
#ifndef _BST_H_
#define _BST_H_

typedef struct bst BST;
typedef struct Node Node;

Node *nodeConstruct(Node *, Node *, int, Node *);
void nodeDestroy(Node *);
BST *btCreate();
Node *btFind(BST *, int);
Node *btMaximum(Node *);
Node *btMinimum(Node *);
void btPush(BST *, int);
void swap(BST *, Node *, Node *);
void btRemove(BST *, int);
void _subtreeDestroy(Node *);
void btDestroy(BST *);

#endif ///HOME-TEMP/ALUNO/CLONES/1/BST_H