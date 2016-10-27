/*
    Opgave 8.3
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    struct contestant{
        char name[64];
        int accScore; // Accuracy score
        int ausScore; // Aussie-Round score
        int endScore; // Endurance score
    } Contestant;
    
    char fileInput[64];
    
    // Declare File Position Pointer
    FILE *fOutAcPtr;
    FILE *fOutAuPtr;
    FILE *fOutEnPtr;
    FILE *fInPtr;
    
    if((fInPtr = fopen ("data.csv", "r")) == NULL)
    {
        printf("Cannot read file!");
    }
    else
    {
        // Open files for write seperate values
        fOutAcPtr = fopen("Accuracy.csv", "w");
        fOutAuPtr = fopen("Aussie.csv", "w");
        fOutEnPtr = fopen("Endurance.csv", "w");
        
        // Parse every line and save in struct array
        while(!feof(fInPtr)){
            // Reads to end of line, max 60 characters
            fgets(fileInput, 64, fInPtr);
            
            // Remove '\n' from line
            if(iscntrl(fileInput[strlen(fileInput) - 1])){
                fileInput[strlen(fileInput) - 1] = '\0';
            }
            
            //Tokenize r, at "," and assign to
            char *tokenPtr = strtok(fileInput, ",");
            strcpy(Contestant.name, tokenPtr);
            
            tokenPtr = strtok(NULL, ",");
            Contestant.accScore = atoi(tokenPtr);
            
            tokenPtr = strtok(NULL, ",");
            Contestant.ausScore = atoi(tokenPtr);
            
            tokenPtr = strtok(NULL, ",");
            Contestant.endScore = atoi(tokenPtr);
            
            fprintf(fOutAcPtr, "%s, %d\n", Contestant.name, Contestant.accScore);
            fprintf(fOutAuPtr, "%s, %d\n", Contestant.name, Contestant.accScore);
            fprintf(fOutEnPtr, "%s, %d\n", Contestant.name, Contestant.endScore);
        }
        
        fclose(fOutAcPtr);
        fclose(fOutAuPtr);
        fclose(fOutEnPtr);
    }
    
    
    fclose(fInPtr);
    
    return(0);
}
