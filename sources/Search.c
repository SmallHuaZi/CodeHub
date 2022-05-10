#include "Search.h"

// ASL = 所有 (找到关键字比较的次数 * 关键字的概率) 相加之和
//平均查找长度：带权路径之和
//判定树的 带权路径之和 = (节点所在层次 * 节点的概率) 相加之和
//层次即比较的次数

int BinarySearch(ElemType EleArray[], ElemType Key)
{
    int Low, High, Mid, ArrLengh;
    if (EleArray == NULL)
    {
        DEBUG_LOG("This Array is NULL");
        return ERROR;
    }

    Low = -1;
    High = GetArrayLengh(EleArray);

    while (Low <= High)
    {
        Mid = (Low + High) / 2;
        if (EleArray[Mid] == Key)
            return Mid;
        else if (EleArray[Mid] <= Key)
            Low = Mid + 1;
        else if (EleArray[Mid] >= Key)
            High = Mid - 1;
    }
}

// SW [Now - 1] -SW[Low-1] = 左边的权值和
// SW [High] -SW[Now] = 右边的权值和
// PH = SW[High] -SW[Now] - (SW[Now-1] -SW[Low-1])
// 次优查找树类似最优二叉树，它的权值是左右权值之差Pi,选择Pi是为了降低判定树的深度，减少判定树的深度
// 就大大减少了比较的次数，和二分查找法不同，它将权值中等的节点放在根部，防止访问高概率的节点时，也要二分很多次;
P_Tree ScondOptimal(P_Tree Tree, ElemType Data[], float Sw[], int Low, int High)
{
    int Pos = Low;
    float PH, PHForward;
    //存储节点
    if (Data == NULL)
        exit(ERROR);

    // PH = Sw[High] + Sw[Low-1] -Sw[Now] - Sw[Now-1]
    PHForward = Sw[High] + Sw[Low - 1]; //代表的是PH前两项
    PH = abs(Sw[High] - Sw[Low]);       //初始化为Low->High之间权值之和,用于记录最小的PH值

    for (int Index = Low + 1; Index <= High; Index++) //取得最小的PH值
    {
        if (abs(PHForward - Sw[Index] - Sw[Index - 1]) < PH)
        {
            Pos = Index;
            PH = abs(PHForward - Sw[Index] - Sw[Index - 1]);
        }
    }

    Tree = (P_Tree)malloc(sizeof(BinaryTree));

    if (Tree)
        Tree->m_Data = Data[Pos - 1];

    if (Pos == Low)
        Tree->m_Lchild = NULL;
    else
        Tree->m_Lchild = ScondOptimal(Tree->m_Lchild, Data, Sw, Low, Pos - 1);

    if (Pos == High)
        Tree->m_Rchild = NULL;
    else
        Tree->m_Rchild = ScondOptimal(Tree->m_Rchild, Data, Sw, Pos + 1, High);

    return Tree;
}

int GetArrayLengh(ElemType Array[])
{
    int Index = 0;

    // initialize Index=0, if this array is null return 0
    if (Array == NULL)
        return Index;

    // if this array is not null,output this array until some value belong to this array if NULL
    for (Index = 0; Index < MaxLengh; Index++)
    {
        if (Array[Index] == NULL)
            return --Index;
    }
}


