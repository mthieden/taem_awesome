/*
    Opgave 8.2
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden
*/

#include <stdio.h>
#include <stdlib.h>
#include "uge8.h"

struct treeNode{
    struct treeNode *leftNodePtr;
    const_t data;
    struct treeNode *rightNodePtr;
};

typedef struct treeNode TreeNode;

void insertNode(TreeNode **treePtr, int dataValue1, int );
void inOrder(TreeNode *tree);

int main()
{

    //tree initializes
    TreeNode *rootPtr = NULL;


    for (int i = 0; i < 90; i++)
    {
        const_t ///////////////////////////////////////////////
        insertNode(&rootPtr, data);
    }


    inOrder(rootPtr);

    return 0;
}

void insertNode(TreeNode **treePtr, int dataValue1)
{
    if(*treePtr == NULL) //indholdet af yderste pointer / addressen af inderste pointer er NULL
    {
        *treePtr = malloc(sizeof(TreeNode));
        //printf("her er jeg");
        if (*treePtr != NULL)
        {
            (*treePtr)->data = dataValue1;
            (*treePtr)->rightNodePtr = NULL;
            (*treePtr)->leftNodePtr = NULL;
        }
        else
        {
            printf("memory was not available");
        }
    }
    else
    {
        if(dataValue1 < (*treePtr)->data)
        {
            insertNode(&((*treePtr)->leftNodePtr), dataValue1);
        }
        else if (dataValue1 > (*treePtr)->data)
        {
            insertNode(&((*treePtr)->rightNodePtr), dataValue1);
        }
        else
        {
            printf("Element \"%2d\" slettet pga dublikeret samme værdi\n", dataValue1);
        }
    }
}

void inOrder(TreeNode *tree)
{
    if (tree != NULL)
    {
        inOrder(tree->leftNodePtr);
        printf("%2d ",tree->data);
        inOrder(tree->rightNodePtr);
    }
    else if (tree == NULL)
    {

    }
}
