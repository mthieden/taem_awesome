#include <stdio.h>
#include <string.h>

enum days {mon=1, tue, wed, thu, fri, sat, sun};
enum days scan_input(char* input);

int main(){
    
    char input[8];
    
    printf("input din ønsket dag\n");
    scanf("%s",input);
    printf("\n%s\n",input);
    enum days lol = scan_input(input);
    
    if(!lol)
    {
    printf("fejl :(");
    return 1;
    }
    printf("din dag er nummer %d i ugen\n",lol);

    return 0;
}


enum days scan_input(char* input)
{
    enum days retday;
    if(!(strcmp(input,"mandag")))
    {
        retday = mon;
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
     return 0;
    }
}