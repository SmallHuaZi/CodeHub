#include "B_Tree.h"

// 多路平衡查找树：允许一个节点有更多子结点
// B类树：为了辅存IO而定义的一种数据结构,键值分布在整颗树中
// 注：结点的插入只会在叶子结点上，分裂是一种递归的性质的操作
Result SearchBTree(BTree T, Key key)
{
    BTree p = T;
    Result result;
    result.IsFound = false;
    result.Parent = NULL;

    while (p && !result.IsFound)
    {
        result.Index = SearchBTNode(p, key);

        if (key == p->KeyAry[result.Index])
            result.IsFound = true;
        else
        {
            result.Parent = p;
            p = p->PointArry[result.Index];
        }
    }
    return result;
}

//返回键值插入的位置
static int SearchBTNode(p_Node p, Key key)
{
    int Index = 0;
    for (; Index < p->Count; Index++)
        if (key <= p->KeyAry[Index])
            return Index;
    return Index;
}

// 1.先插入一个顶点的子结点中去
// 2.判断子结点是否满足键数小于（Order-1）
// 3.1满足，跳出循环,完成任务
// 3.2不满足，分裂结点，挑选中间键值[Order/2]，创造一个新结点存储分裂后的[Order/2---Order]，将中间键值和新结点的指针插入双亲结点
BTree InsertBTree(BTree T, p_Node p, Key key, int Index)
{
    int Pos = Index;
    Key buffer = key;
    bool IsFinish = false;
    p_Node NewNode = NULL;

    while (p && !IsFinish)
    {
        InsertNode(p, buffer, NewNode, Pos);
        if (p->Count < Order)
            IsFinish = true;
        else //分裂操作
        {
            Pos = Order / 2;
            NewNode = Initstate(NewNode); //申请新结点，并将其初始化;

            buffer = p->KeyAry[Pos];
            //
            SplitNode(p, NewNode, Pos); //分裂结点，并将新结点返回给NewNode;
            //存储待插入父结点的键值
            p = p->Parent; //插入结点的父结点
            //
            if (p)
                Pos = SearchBTNode(p, buffer); //获取待插入结点在赋值中的位置
        }
    }
    if (!IsFinish) // 1.参数为空； 2.在分裂的过程中根结点分裂了,即p指向了根结点的父结点
    {
        T = CreateRoot(T, NewNode, buffer);
    }
    return T;
}

// greater指针明显是大于key键值的另一部分的指针域
// p指向待插入结点
static BTree InsertNode(p_Node p, Key key, p_Node greater, int Index)
{
    //注：插入操作：移位时，待插入位置的键值要移动，但是指针域不移动
    for (int pos = Order - 1; pos > Index; pos--)
    {
        p->KeyAry[pos] = p->KeyAry[pos - 1];       //键值域后移
        p->PointArry[pos + 1] = p->PointArry[pos]; //指针域后移
    }
    if (greater)
        greater->Parent = p;
    p->PointArry[Index + 1] = greater; //子结点插入操作
    p->KeyAry[Index] = key;
    p->Count++;
    return p;
}

//分裂结点操作
static BTree SplitNode(p_Node Aim, p_Node Return, int Pos)
{
    int Aim_Index, Return_Index;
    for (Return_Index = 0, Aim_Index = Pos + 1; Aim_Index <= Order; Aim_Index++, Return_Index++)
    {
        Return->PointArry[Return_Index] = Aim->PointArry[Aim_Index];
        //这一步操作很重要
        if (Return->PointArry[Return_Index])
        {
            Return->PointArry[Return_Index]->Parent = Return;
        }
        Aim->PointArry[Aim_Index] = NULL;
        Return->KeyAry[Return_Index] = Aim->KeyAry[Aim_Index];
        Aim->KeyAry[Aim_Index] = MAXNumber;
        --Aim->Count;
    }
    Return->Parent = Aim->Parent;
    Aim->KeyAry[Pos] = MAXNumber;
    Return->Count = 1;
    return Return;
}

//生成根结点:1.传入空树   2.分裂过程中，根节点分裂
static p_Node CreateRoot(p_Node left, p_Node right, Key key)
{
    p_Node T = Initstate(T);
    if (right && left) //当根节点分裂时
        right->Parent = left->Parent = T;
    T->Count++;
    T->KeyAry[0] = key;
    T->PointArry[0] = left;
    T->PointArry[1] = right;
    return T;
}

//初始化结点
static p_Node Initstate(p_Node node)
{
    node = (p_Node)malloc(sizeof(Node));
    node->PointArry = (p_Node *)malloc(sizeof(p_Node) * (Order + 1));
    node->KeyAry = (Key *)malloc(sizeof(Key) * Order);
    for (int i = 0; i <= Order; i++)
    {
        node->KeyAry[i] = MAXNumber;
        node->PointArry[i] = NULL;
    }
    node->Parent = NULL;
    node->Count = 0;
    return node;
}

void OutPut(BTree Tree)
{
    if (!Tree)
        return;
    for (int i = 0; i < Tree->Count; i++)
    {
        printf("%d  ", Tree->KeyAry[i]);
    }
    printf("\n");
    for (int i = 0; i <= Tree->Count; i++)
    {
        OutPut(Tree->PointArry[i]);
    }
}
