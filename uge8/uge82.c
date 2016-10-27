/*
    Opgave 8.2
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden
*/

#include <stdio.h>
#include <stdlib.h>

struct treeNode{
    struct treeNode *leftNodePtr;
    int data;
    struct treeNode *rightNodePtr;
};

typedef struct treeNode TreeNode;

void insertNode(TreeNode **treePtr, int dataValue);
void inOrder(TreeNode *tree);

int main()
{
    TreeNode *rootPtr = NULL;

    for (int i = 0; i < 90; i++)
    {
        int data = i%45;
        insertNode(&rootPtr, data);

    }
    inOrder(rootPtr);
    return 0;
}

void insertNode(TreeNode **treePtr, int dataValue)
{
    if(*treePtr == NULL) //indholdet af yderste pointer / addressen af inderste pointer er NULL
    {
        *treePtr = malloc(sizeof(TreeNode));
        //printf("her er jeg");
        if (*treePtr != NULL)
        {
            (*treePtr)->data = dataValue;
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
        if(dataValue < (*treePtr)->data)
        {
            insertNode(&((*treePtr)->leftNodePtr), dataValue);
        }
        else if (dataValue > (*treePtr)->data)
        {
            insertNode(&((*treePtr)->rightNodePtr), dataValue);
        }
        else
        {
            printf("Element \"%2d\" slettet pga dublikeret samme værdi\n", dataValue);
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
