#include "bst.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    BST *bt = btCreate();
    srand(time(NULL));
    int N = 1000000;
    printf("Generate %d Nodes\n", N);
    for (int i = 0; i < N; i++){
        printf("Insert node %d\n",i);
        btPush(bt,rand());
    }
    btDestroy(bt);
    return 0;
}
