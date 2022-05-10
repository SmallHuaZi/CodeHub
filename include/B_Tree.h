#ifndef _BTREE_H_
#define _BTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define Key int
#define Order 3
#define MAXNumber 10000

typedef enum bool
{
    false,
    true
} bool;

typedef struct BTree_Node *p_Node,
    Node, *BTree;
struct BTree_Node
{
    int Count;
    Key *KeyAry;       //键值域指针，使用时用malloc函数进行生成
    p_Node Parent;     //指向双亲结点，便于后续的分裂，合并
    p_Node *PointArry; //指向子树的指针，使用时用malloc函数在堆上申请Order个空间
};
typedef struct Result
{
    p_Node Parent;
    int Index;
    bool IsFound;
} Result, *p_Result;
static int SearchBTNode(p_Node p, Key key);

Result SearchBTree(BTree T, Key key);

BTree InsertBTree(BTree T, p_Node p, Key key, int Index);

static BTree InsertNode(p_Node p, Key key, p_Node child, int Index);

static p_Node Initstate(p_Node node);

static p_Node CreateRoot(p_Node left, p_Node right, Key key);

static BTree SplitNode(p_Node Aim, p_Node Return, int Pos);

void OutPut(BTree Tree);
#endif