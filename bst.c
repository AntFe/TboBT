#include "/home-temp/aluno/clones/1/bst.h"
#include "bst.h"
#include <stdlib.h>


struct Node
{
    int key;
    Node *pai, *esq, *dir;
};

struct bst
{
    Node *root;
    int size;
};

Node *nodeConstruct(Node *Pai, Node *esq, int value, Node *dir)
{
    Node *new_node = calloc(1, sizeof(Node));
    new_node->pai = Pai;
    new_node->key = value;
    new_node->esq = esq;
    new_node->dir = dir;
    return new_node;
}

void nodeDestroy(Node *n)
{
    free(n);
}

BST *btCreate()
{
    return calloc(1, sizeof(BST));
}

/// @brief BT FIND - busca a posição do valor na árvore
/// @param bt
/// @param key
/// @return
Node *btFind(BST *bt, int key)
{
    Node *x = bt->root;
    while (x != NULL && x->key != key)
    {
        if (key < x->key)
            x = x->esq;
        else
            x = x->dir;
    }
    return x;
}

Node *btMaximum(Node *x)
{
    while (x->dir != NULL)
        x = x->dir;
    return x;
}

Node *btMinimum(Node *x)
{
    while (x->esq != NULL)
        x = x->esq;
    return x;
}

void btPush(BST *bt, int key)
{
    Node *y = NULL, *x = bt->root;
    while (x != NULL)
    {
        y = x;
        if (x->key > key)
            x = x->esq;
        else
            x = x->dir;
    }   
    if (y == NULL)
        bt->root = nodeConstruct(NULL, NULL, key, NULL);
    else if (key < y->key)
        y->esq = nodeConstruct(y, NULL, key, NULL);
    else
        y->dir = nodeConstruct(y, NULL, key, NULL);
    bt->size++;
}

void swap(BST *bt, Node *u, Node *v)
{
    if (u->pai == NULL)
        bt->root = v;
    else if (u == u->pai->esq)
        u->pai->esq = v;
    else
        u->pai->dir = v;
    if (v != NULL)
        v->pai = u->pai;
}

void btRemove(BST *bt, int key)
{
    Node *z = btFind(bt, key), *y = NULL, *to_remove = z;
    if (z->esq == NULL)
    {
        swap(bt, z, z->dir);
        nodeDestroy(to_remove);
        bt->size--;
        return;
    }
    else if (z->dir == NULL)
    {
        swap(bt, z, z->esq);
        nodeDestroy(to_remove);
        bt->size--;
        return;
    }
    else
    {
        y = btMinimum(z->dir);
        if (y->pai != z)
        {
            swap(bt, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        swap(bt, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        nodeDestroy(to_remove);
        bt->size--;
    }
}


void _subtreeDestroy(Node *n){
    if(n == NULL) return;
    _subtreeDestroy(n->esq);
    _subtreeDestroy(n->dir);
    nodeDestroy(n);
}

void btDestroy(BST *bt){
    _subtreeDestroy(bt->root);
    free(bt);
}