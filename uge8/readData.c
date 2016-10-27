#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
   struct contestant{
      char name[30];
      int accScore; // Accureacy score
      int ausScore; // Aussie-Round score
      int endScore; // Endurance score
   };

   struct contestant Contestant[30];
 
   char r[30];

   // Declare File Position Pointer
   FILE * fp;
   fp = fopen ("data.csv", "r");


   // Parse every line and save in struct array
   while(!feof(fp)){
         // Reads to end of line, max 60 characters
         fgets(r, 60, fp);

         // Remove '\n' from line
         if(iscntrl(r[strlen(r) - 1])){
            r[strlen(r) - 1] = '\0';
         }

         //Tokenize r, at "," and assign to 
         char *tokenPtr = strtok(r, ",");
         strcpy(Contestant[0].name, tokenPtr);
         tokenPtr = strtok(NULL, ",");
         Contestant[0].accScore = atoi(tokenPtr);
         tokenPtr = strtok(NULL, ",");
         Contestant[0].ausScore = atoi(tokenPtr);
         tokenPtr = strtok(NULL, ",");
         Contestant[0].endScore = atoi(tokenPtr);

         printf("%s %d %d %d\n", Contestant[0].name, Contestant[0].accScore, Contestant[0].ausScore, Contestant[0].endScore);

   }

   fclose(fp);
   
   return(0);
}