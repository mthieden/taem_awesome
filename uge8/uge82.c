/*
    Opgave 8.2
    Gruppe "taem ducksome"
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden
                 _      _      _                _      _      _
              __(.)< __(.)> __(.)=   Rubber   >(.)__ <(.)__ =(.)__
              \___)  \___)  \___)    Ducky!    (___/  (___/  (___/
*/

#include "uge8.h"

typedef struct treeNode
{
    struct treeNode *leftNodePtr;
    const_t data;
    struct treeNode *rightNodePtr;
} TreeNode;

void insertNode(TreeNode **treePtr, const_t dataValue);
void inOrder(TreeNode *tree);
void readDataToTree(const char *file, TreeNode **rootPtr);

int main()
{

    //tree initializes
    TreeNode *rootPtr = NULL;

    const char *file = "data.csv";

    readDataToTree(file, &rootPtr);

    inOrder(rootPtr);

    return 0;
}

void insertNode(TreeNode **treePtr, const_t dataValue)
{
    if(*treePtr == NULL) //indholdet af yderste pointer / addressen af inderste pointer er NULL
    {
        *treePtr = (TreeNode*) malloc(sizeof(TreeNode));
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
        if (dataValue.accScore < (*treePtr)->data.accScore)
        {
            insertNode(&((*treePtr)->leftNodePtr), dataValue);
        }
        else
        {
            insertNode(&((*treePtr)->rightNodePtr), dataValue);
        }
    }
}

void inOrder(TreeNode *tree)
{
    if (tree != NULL)
    {
        inOrder(tree->leftNodePtr);
        printf("%2d ",tree->data.accScore);
        inOrder(tree->rightNodePtr);
    }
}

void readDataToTree(const char *file, TreeNode **rootPtr)
{

   // Declare File Position Pointer
   FILE *fp; //file pointer
   fp = fopen (file, "r"); //open file in readmode
   const_t contestant; //contestant holder
   char file_input[64]; //input array

   // Parse every line and save in struct array
   while(!feof(fp)) //while not end of file
   {
         // Reads to end of line, max 60 characters
         fgets(file_input, 60, fp);

         // Remove '\n' from line
         if( iscntrl( file_input[ strlen(file_input) - 1])) //iscntrl: check for control characters
         {                                                  // (fx \n)
            file_input[strlen(file_input) - 1] = '\0';      // \n -> \0
         }


         //Tokenize r, at "," and assign to
         char *tokenPtr = strtok(file_input, ","); //strtok: "," er delimiter
         strcpy(contestant.name, tokenPtr); //copy first token to name

         tokenPtr = strtok(NULL, ",");
         contestant.accScore = atoi(tokenPtr); //copy second token to accScore

         tokenPtr = strtok(NULL, ",");
         contestant.ausScore = atoi(tokenPtr); //copy third token to ausScore

         tokenPtr = strtok(NULL, ",");
         contestant.endScore = atoi(tokenPtr); //copy fourth token to endScore

         insertNode(rootPtr, contestant);


   }

   fclose(fp);
}
