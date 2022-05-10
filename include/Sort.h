#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define Key int
#define Element int
#define ERROR 0
#define OVERFLOW 1
#define MAXSIZE 21
#define LT(a, b) (a) < (b)

typedef enum bool
{
    false,
    true
} bool;

typedef struct
{
    Key key;
    Element data;
} Elemtype;

typedef struct Table
{
    Elemtype T[MAXSIZE];
    int Lengh;
} * p_Table, Table;

p_Table InsertSort(p_Table TablePointer); //插入排序

p_Table BinaryInsertSort(p_Table table); //二分插入排序

p_Table ShellSort(p_Table table, int Skip[], int Lengh); //希尔排序

static p_Table ShellInsertSort(p_Table table, int SkipLengh);

p_Table BubbleSort(p_Table table, int Lengh); //冒泡排序

p_Table QuickSort(p_Table Table, int Low, int High); //快速排序

static int Partition(p_Table Table, int Low, int High);

p_Table ChooseSort(p_Table Table, int Lengh); //选择排序

p_Table HeapSort(p_Table Table, int Lengh); //堆排序

p_Table AdjustHeap(p_Table Table, int pos, int Lengh);

p_Table Swap(p_Table Table, int Top, int End);

void CountingSort(p_Table Table, int Lengh); //计数排序

void MergeSort(p_Table Table, int low, int high); //归并排序

static void Merge(p_Table Table, int low, int mid, int high);

void RadixSort(p_Table Table, int Lengh); //基数排序

static int GetBitSize(int value, int bit);
#endif