#include "Sort.h"

//查找排序：左右值比较，如果右<左，则进行换位操作
//换位操作：用哨岗记录右值（更小的那个值），在右值所在的地址记录更大的值
//继续向前比较，直到遇到比左值更小的，或者遇到哨岗才停止
p_Table InsertSort(p_Table TablePointer)
{
    int Index, smaller;
    for (Index = 2; Index <= TablePointer->Lengh; ++Index)
    {
        if (LT(TablePointer->T[Index].key, TablePointer->T[Index - 1].key))
        {
            TablePointer->T[0].key = TablePointer->T[Index].key;
            TablePointer->T[Index] = TablePointer->T[Index - 1];

            //这里的Index-2是因为Index-1已经和Index(更小值)比较了
            for (smaller = Index - 2; LT(TablePointer->T[0].key, TablePointer->T[smaller].key); smaller--)
            {
                //更小值比前面的其他值还小，所以其他值向前移给更小值让位;
                TablePointer->T[smaller + 1] = TablePointer->T[smaller];
            }
            //这里的smaller加1  1.是因为在循环执行时，结束时减去了1
            //                 2.是因为没有执行循环时，该插入更小值的地方是Index-1
            TablePointer->T[smaller + 1] = TablePointer->T[0];
        }
    }
    return TablePointer;
}

//二分插入记录排序：利用了在查找排序中已经形成了正序的序列；
p_Table BinaryInsertSort(p_Table table)
{
#define Listener (table->T[0])

    int Index, InsertPos;
    int Low, High, Mid;
    for (Index = 2; Index <= table->Lengh; Index++)
    {
        if (LT(table->T[Index].key, table->T[Index - 1].key))
        {
            Listener = table->T[Index];
            Low = 1;
            High = Index - 1;

            //判断表中已经有序的部分的中间部分和哨岗中的值进行比较
            //这里使用等于是为了计算Mid的值;
            while (Low <= High)
            {
                Mid = ((Low + High) >> 1);

                if (LT(Listener.key, table->T[Mid].key))
                    High = Mid - 1;
                else
                    Low = Mid + 1;
            }
            for (InsertPos = Index; InsertPos > Mid; InsertPos--)
            {
                table->T[InsertPos] = table->T[InsertPos - 1];
            }
            table->T[Mid] = Listener;
        }
    }
    return table;
}

//希尔排序：用大幅度的插入排序来降低值的不均匀分布，以至于减少最后一次插入排序的比较次数
p_Table ShellSort(p_Table table, int Skip[], int Lengh)
{
    int Index;
    for (Index = 0; Index < Lengh; Index++)
    {
        ShellInsertSort(table, Skip[Index]);
    }
    return table;
}
//希尔插入排序
static p_Table ShellInsertSort(p_Table table, int SkipLengh)
{
#define Listener (table->T[0])
    int Index, InsertPos;
    for (Index = SkipLengh + 1; Index <= table->Lengh; Index++)
    {
        if (LT(table->T[Index].key, table->T[Index - SkipLengh].key))
        {
            Listener = table->T[Index];

            //这里不减去2倍的步长是为了后面的给Index进行赋值操作
            //很关键的一部操作
            InsertPos = Index - SkipLengh;
            while (InsertPos > 0 && LT(Listener.key, table->T[InsertPos].key))
            {
                table->T[InsertPos + SkipLengh] = table->T[InsertPos];
                InsertPos -= SkipLengh;
            }

            table->T[InsertPos + SkipLengh] = Listener;
        }
    }
}

//冒泡排序:每次都比较相邻的两个值，但是已经比较了的值就不需要比较了
p_Table BubbleSort(p_Table table, int Lengh)
{
#define Data(a) (table->T[a].key)
    int Count, Index;
    bool IsEnd = false;
    for (Count = 0; Count < Lengh - 1 && !IsEnd; Count++)
    {
        //已经比较了的元素就不需要再比较了，所以Index<Lengh-COunt;
        for (Index = 0; Index < Lengh - Count; Index++)
        {
            if (LT(Data(Index + 1), Data(Index)))
            {
                IsEnd = false;
                Data(Index + 1) ^= Data(Index);
                Data(Index) ^= Data(Index + 1);
                Data(Index + 1) ^= Data(Index);
            }
            else //没有发生交换的情况下
                IsEnd = true;
        }
    }
}

//快速排序：空间占用比较大;
//按区间进行排序
p_Table QuickSort(p_Table Table, int Low, int High)
{
    if (Low >= High)
        return NULL;
    int Mid = Partition(Table, Low, High);
    QuickSort(Table, Low, Mid - 1);
    QuickSort(Table, Mid + 1, High);
    return Table;
}

static int Partition(p_Table Table, int Low, int High)
{
#define Listener (Table->T[0])
    Listener = Table->T[Low];
    while (Low < High)
    {
        //先从右边查找有没有小于哨兵的值
        while (LT(Listener.key, Table->T[High].key) && Low < High) //
            High--;
        Table->T[Low] = Table->T[High];

        //再从左边查找有没有大于哨兵值的
        while ((LT(Table->T[Low].key, Listener.key)) && Low < High) //
            Low++;
        Table->T[High] = Table->T[Low];
    }
    Table->T[Low] = Listener;
    return Low;
}

//选择排序:选择一个值，在剩余的的序列中找到最小的值，和它位置互换
p_Table ChooseSort(p_Table Table, int Lengh)
{
#define KEY(a) (Table->T[a])
    int Index, Pos;
    int AimPos;
    for (Index = 0; Index < Lengh - 1; Index++)
    {
        AimPos = Index;
        for (Pos = Index + 1; Pos < Lengh; Pos++)
        {
            if (KEY(AimPos).key > KEY(Pos).key)
            {
                AimPos = Pos;
            }
        }
        if (AimPos != Index)
        {
            KEY(AimPos).key ^= KEY(Index).key;
            KEY(AimPos).data ^= KEY(Index).key;
            KEY(Index).key ^= KEY(AimPos).key;
            KEY(Index).data ^= KEY(AimPos).data;
            KEY(AimPos).key ^= KEY(Index).key;
            KEY(AimPos).data ^= KEY(Index).key;
        }
    }
    return Table;
}

//堆排序，本质上是对数组的抽象表达，将数组元素依靠索引的特殊关系，看成二叉树
//简化操作：1.堆的调整操作    2.堆顶元素和末尾元素的交换
p_Table HeapSort(p_Table Table, int Lengh)
{
    if (!Table)
        return NULL;
    int Index;
    for (Index = Lengh / 2 - 1; Index >= 0; Index--)
    {
        AdjustHeap(Table, Index, Lengh);
    }
    for (Index = Lengh - 1; Index > 0; Index--)
    {
        Swap(Table, 0, Index);       // 这里的index一定不能为0，因为为0会使第一个元素自己和异或运算，会造成输出第一个数组元素为0
        AdjustHeap(Table, 0, Index); //这里带如数组的长度为什么是Index，是因为在进行交换操作后，最后一位的元素已经达到了预期的效果
    }
    return Table;
}
//调整大堆:获得升序的数组
//输入结点的位序，然后调整结点的和其子孙结点的关系;
p_Table AdjustHeap(p_Table Table, int pos, int Lengh)
{
#define KEY(a) (Table->T[a])
    int buffer = KEY(pos).key;
    for (int p = pos * 2 + 1; p < Lengh; p = 2 * p + 1)
    {
        if (p + 1 < Lengh && KEY(p).key < KEY(p + 1).key)
            p++;
        if (KEY(pos).key > KEY(p).key)
            break;
        Swap(Table, pos, p);
        pos = p;
    }
    return Table;
}

p_Table Swap(p_Table Table, int Top, int End)
{
#define KEY(a) (Table->T[a])
    KEY(Top).key ^= KEY(End).key;
    KEY(End).key ^= KEY(Top).key;
    KEY(Top).key ^= KEY(End).key;
    return Table;
}

//计数排序
void CountingSort(p_Table Table, int Lengh)
{
#define Min -200
#define KEY(A) (Table->T[A].key)

    int Max = Min, Index, Pos;

    for (Index = 0; Index < Lengh; Index++)
    {
        if (KEY(Index) > Max)
            Max = KEY(Index);
    }

    int Array[Max + 1];

    for (Index = 0; Index < Max + 1; Index++)
        Array[Index] = 0;

    for (Index = 0; Index < Lengh; Index++)
        Array[KEY(Index)]++;

    Pos = 0;
    for (Index = 0; Index < Max + 1; Index++)
    {
        if (Array[Index] != 0)
        {
            int count = Pos;
            for (; Pos < count + Array[Index]; Pos++)
                KEY(Pos) = Index;
        }
    }
}

//归并排序
void MergeSort(p_Table Table, int low, int high)
{
    if (low >= high)
        return;
    int Mid = (high + low) / 2;
    MergeSort(Table, low, Mid); //这里不用Mid-1，是为了让mid也参与排序中
    MergeSort(Table, Mid + 1, high);
    Merge(Table, low, Mid, high);
}

static void Merge(p_Table Table, int low, int mid, int high)
{
#define KEY(a) (Table->T[a].key)
    int temp[high - low + 1];
    int L = low, R = mid + 1, Index = 0;

    while (L <= mid && R <= high)
    {
        if (KEY(L) < KEY(R))
        {
            temp[Index++] = KEY(L++);
        }
        else
            temp[Index++] = KEY(R++);
    }

    while (L <= mid)
        temp[Index++] = KEY(L++);
    while (R <= high)
        temp[Index++] = KEY(R++);

    for (Index = 0; low <= high; low++, Index++)
    {
        KEY(low) = temp[Index];
    }
}

//基数排序
void RadixSort(p_Table Table, int Lengh)
{
#define MaxE 10
#define MAXBIT 2
#define KEY(a) (Table->T[a].key)

    int bitAry[10][MaxE];
    int buffer, Bit, Index, aryPos, TableIndex;

    //初始化数组
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < MaxE; j++)
        {
            bitAry[i][j] = 0;
        }
    }

    for (Bit = 0; Bit < MAXBIT; Bit++)
    {

        //插入数组
        for (Index = 0; Index < Lengh; Index++)
        {
            //获取行数
            buffer = GetBitSize(KEY(Index), Bit);
            //插入基数数组
            aryPos = 0;
            //找到插入的位置
            while (bitAry[buffer][aryPos])
                aryPos++;
            bitAry[buffer][aryPos] = KEY(Index);
        }

        //重新赋值
        TableIndex = 0;
        for (Index = 0; Index < 10; Index++)
        {
            for (aryPos = 0; bitAry[Index][aryPos]; aryPos++)
            {
                KEY(TableIndex++) = bitAry[Index][aryPos];
                bitAry[Index][aryPos] = 0; //还原数组初始状态
            }
        }
    }
}

static int GetBitSize(int value, int bit)
{
    while (bit)
    {
        value /= 10;
        bit--;
    }
    return value % 10;
}