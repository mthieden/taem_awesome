#include <stdio.h>
#include <string.h>

// Enum is declared
enum days {mon=1, tue, wed, thu, fri, sat, sun};

// Prototype for function scan_input
enum days scan_input(char* input);

int main(){
    
    // Declare char array (string)
    char input[8];
    
    // Ask for input
    printf("Indtast dag\n");
    scanf("%s",input);

    // Translate string input to enum reference
    enum days scanDays = scan_input(input);
    
    // If an error has occured, returns an error, and closes the program.
    // That is if scan_input returns 0;
    if(!scanDays)
    {
        printf("Inkorrekt indtastning\n");
        return 1;
    }

    // Udskriv brugerens input samt denne dag nr.
    printf("%s er nummer %d i ugen\n",input,scanDays);

    return 0;
}

/*  Function enum days scan_input(char* input)
    Arguments: takes a string
    Returns enum reference coresponding to string.
*/
enum days scan_input(char* input)
{   
    // Declare enum
    enum days retday;
    //uses strcmp from string.h to compare input to predefined strings.
    if(!(strcmp(input,"mandag")))
    {
        retday = mon;
        //Return enum with coresponding value
        return retday;
    } 
    else if(!(strcmp(input,"tirsdag")))
    {
        retday = tue;
        return retday;
    } 
    else if(!(strcmp(input,"onsdag")))
    {
        retday = wed;
        return retday;
    }
    else if(!(strcmp(input,"torsdag")))
    {
        retday = thu;
        return retday;
    }
    else if(!(strcmp(input,"fredag")))
    {
        retday = fri;
        return retday;
    }
    else if(!(strcmp(input,"lørdag")))
    {
        retday = sat;
        return retday;
    }
    else if(!(strcmp(input,"søndag")))
    {
        retday = sun;
        return retday;
    }
    else
    {
     // Return an 'error'
     return 0;
    }
}