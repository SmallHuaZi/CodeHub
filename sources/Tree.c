#include "Search.h"

int OutPutTree(P_Tree Tree)
{
	if (!Tree)
		exit(ERROR);
	if (Tree->m_Lchild)
		OutPutTree(Tree->m_Lchild);

	printf("%d\n", Tree->m_Data);

	if (Tree->m_Rchild)
		OutPutTree(Tree->m_Rchild);
}

#pragma region 平衡二叉树

#define LH 1  //左子树高
#define EH 0  //等高
#define RH -1 //右子树高
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))
#define SertYES 2
#define SertNO 0

//单向右旋操作
p_Node_ R_Rotate(p_Node_ p)
{
	if (!p)
		return NULL;
	p_Node_ lc = p->lchild;
	p->lchild = lc->rchild;
	lc->rchild = p;
	p = lc;
	return p;
}

//单向左旋操作
p_Node_ L_Rotate(p_Node_ p)
{
	if (!p)
		return NULL;
	p_Node_ rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
	return p;
}

//先分析插入类型：LL，RR，LR，RL；
//在找到最小不平衡子树:
// 1.判断是否插入，如果插入回溯到插入结点的祖宗结点，根据祖宗结点的BF进行相应的处理;
//   插入左子树的情况下：
//      1.插入左子树的右子树，双亲BF=RH，返回上一层：
//            注：以下进行在祖宗结点存在的情况下，不存在的情况下不需要回溯
//                1.双亲的双亲BF=LH：则作LR处理，双亲^2B的F=EH，停止回溯；
//                2.双亲的双亲BF=EH：双亲^2的BF=LH，回溯->上一层;
//                2.双亲的双亲BF=RH：双亲^2的BF=EH,停止回溯;

//      2.插入左子树的左子树：双亲BF=LH：返回上一层:
//            注：以下进行在祖宗结点存在的情况下，不存在的情况下不需要回溯
//                1.双亲的双亲BF=LH：则作LL处理，双亲^2的BF=EH，停止回溯；
//                2.双亲的双亲BF=EH：双亲^2的BF=LH，回溯->上一层;
//                2.双亲的双亲BF=RH：双亲^2的BF=EH,停止回溯;
//
//   插入右子树的情况下：
//      1.插入右子树的左子树，双亲结点的BF=LH，返回上一层：
//            注：以下进行在祖宗结点存在的情况下，不存在的情况下不需要回溯
//                1.双亲的双亲BF=LH：双亲^2的BF=EH，停止回溯;
//                2.双亲的双亲BF=EH：双亲^2的BF=RH，回溯->上一层;
//                2.双亲的双亲BF=RH：则作RL处理，双亲^2的BF=EH，停止回溯;
//
//      2.插入右子树的右子树，双亲结点的BF=RH，返回上一层：
//            注：以下进行在祖宗结点存在的情况下，不存在的情况下不需要回溯
//                1.双亲的双亲BF=LH：双亲^2的BF=EH，停止回溯;
//                2.双亲的双亲BF=EH：双亲^2的BF=RH，回溯->上一层;
//                2.双亲的双亲BF=RH：则作RR处理，双亲^2的结点BF=EH，停止回溯;
//
//

//左旋就是把插入结点的双亲结点的左子树赋给根节点的右子树
//右旋就是把插入结点的双亲结点的右子树赋给根节点的左子树
// LL：插入左子树的左子树的情况，对最小不平衡子树进行单向右旋；
// RR：插入右子树的右子树的情况，对最小不平衡子树进行单向左旋；
// LR：插入左子树的右子树的情况，先对最小不平衡的左子树进行单向左旋，再对最小不平衡子树进行单向右旋;
// RL：插入右子树的左子树的情况，先对最小不平衡的右子树进行单向右旋，再对最小不平衡子树进行单向左旋;

p_Node_ InsertAVLT(p_Node_ p, ElemType key, bool *IsInsert)
{
	if (!p)
	{
		p = (p_Node_)malloc(sizeof(Node_));
		p->data = key;
		p->lchild = p->rchild = NULL;
		p->bf = EH;
		*IsInsert = true;
	}
	else
	{
		if (EQ(p->data, key))
			return NULL;
		if (LT(key, p->data)) //插入左子树
		{
			if (!(p->lchild = InsertAVLT(p->lchild, key, IsInsert)))
				return NULL;
			if (*IsInsert)
			{
				switch (p->bf)
				{
				case LH:
					LeftBalance(p);
					*IsInsert = false;
					break;
				case EH:
					p->bf = LH;
					break;
				case RH:
					p->bf = EH;
					*IsInsert = false;
					break;
				}
			}
		}
		else //插入右子树
		{
			if (!(p->rchild = InsertAVLT(p->rchild, key, IsInsert)))
				return NULL;
			if (*IsInsert)
			{
				switch (p->bf)
				{
				case LH:
					p->bf = EH;
					*IsInsert = false;
					break;
				case EH:
					p->bf = RH;
					break;
				case RH:
					RightBalance(p);
					*IsInsert = true;
					break;
				}
			}
		}
	}
	return p;
}

p_Node_ LeftBalance(p_Node_ p)
{
	if (!p)
		return NULL;
	p_Node_ lc = p->lchild;
	if (!lc)
		return NULL;
	p_Node_ rc = lc->rchild;
	switch (lc->bf)
	{
	case LH: //插入左孩子的左孩子LL
		p->bf = lc->bf = EH;
		return R_Rotate(p);
	case RH:			//插入到了左孩子的右孩子LR
		switch (rc->bf) //这一步判断的是插入的叶子结点的左子树和右子树
		{				//插入位置不同，左旋和右旋后插入结点的位置不同，可能是插入根节点，也可能是左孩子的右孩子
		case LH:		//对应的BF值也会相应的转变
			p->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			p->bf = EH;
			break;
		case RH:
			p->bf = EH;
			lc->bf = LH;
			break;
		}
		rc->bf = EH;
		p->lchild = L_Rotate(p->lchild);
		p = R_Rotate(p);
		break;
	}
	return p;
}

p_Node_ RightBalance(p_Node_ p)
{
	if (!p)
		return NULL;
	p_Node_ rc = p->rchild;
	if (!rc)
		return NULL;
	p_Node_ lc = rc->lchild;
	switch (rc->bf)
	{
	case RH: // RR
		p->bf = EH;
		return L_Rotate(p);
	case LH: // RL
		switch (lc->bf)
		{
		case LH:
			p->bf = EH;
			lc->bf = RH;
			break;
		case EH:

			p->bf = EH;
			break;
		case RH:
			lc->bf = EH;
			p->bf = LH;
			break;
		}
		break;
	}
	lc->bf = EH;
	p->rchild = R_Rotate(rc);
	p = L_Rotate(p);
	return p;
}

void OutPutTree_(p_Node_ p)
{
	if (!p)
		return;
	OutPutTree_(p->lchild);
	printf("%d\n", p->data);
	OutPutTree_(p->rchild);
}

#pragma endregion
