#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#define MaxLengh 99999
#define ElemType int
#define ERROR -1
#define OVERFLOW -1
#define DEBUG_LOG(a) printf(a)

#pragma region 数据结构

typedef struct Node *p_Node, Node, BinaryTree, *P_Tree;
struct Node
{
    short m_Weight;            // weight
    ElemType m_Data;           // data
    p_Node m_Lchild, m_Rchild; // pointer->child
};

int OutPutTree(P_Tree Tree); //输出树

#pragma endregion

// Search Functions
#pragma region 排序函数

// bianarySearch
int BinarySearch(ElemType EleArray[], ElemType Key);

// scondOptimal:Create BInaryTree
P_Tree ScondOptimal(P_Tree Tree, ElemType Data[], float Sw[], int Low, int High);

#pragma endregion

#pragma region 工具类函数

int GetArrayLengh(ElemType Array[]);

#pragma endregion

#pragma region 平衡二叉树

typedef enum bool
{
    true,
    false
} bool;

typedef struct Node_ *p_Node_,
    Node_;
struct Node_
{
    ElemType data;
    short bf;
    p_Node_ lchild, rchild;
};

//单向右旋操作
p_Node_ R_Rotate(p_Node_ p);

//单向左旋操作
p_Node_ L_Rotate(p_Node_ p);

p_Node_ InsertAVLT(p_Node_ p, ElemType key, bool *IsInsert);

p_Node_ LeftBalance(p_Node_ p); //左平衡处理

p_Node_ RightBalance(p_Node_ p); //右平衡处理

void OutPutTree_(p_Node_ p);

#pragma endregion
#endif