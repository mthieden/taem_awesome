/* 
Uge 3 opgave 4 
This is short showcase of typecasting, with examples.
Gruppe "taem awesome" (ja det er stavet forkert med vilje)
    s153460 Jonas Ladefoged Holm
    s113070 David Bjerre Bjørklund
    s164920 Markus Visvaldis Ingemann Thieden
*/

#include <stdio.h>
#include <stdlib.h>


// We initialise our variables
void* typeless;
int x, y = 0;
float a, b = 0;
char ch = 'A';

int main()
{
    // we start with som simple calculations
    printf("We start our typcasting with som simple integers\n");
    printf("x = y + 6;\ny = (int)x/4;\n");
    x = y + 6;
    // we use float to redefine a int, this is only possible using typcasting 
    y = (int)x/4;

    // it's not nessesary to typecast a simple type to a more advanced type a.i. int to float 
    printf("then we show that typcasting is not nessary, when going from a simple to a advanced type\n");
    printf("a = x / 3.2;\nb = x + y;\n");
    a = x / 3.2;
    b = x + y;
    
    // we use chars and typecast it as unsinged int
    printf("\n Now we try with char and unsinged\n");
    printf("This is our char:  %c\n",ch);
    printf("now we print it as unsigned: 0x%08x\n",(unsigned int)ch);
    
    // Here we use null pointer which can be typecasted as all types
    printf("Here we use null pointers, which is an amazing type who can be typecasted to all types\n");
    typeless = &a;
    printf("Now our void pointer points to the float:  %f\n", *(float*)typeless);
    typeless = &ch;
    printf("Now our void pointer points to the char:  %c\n", *(char*)typeless);
    typeless = &x;
    printf("Now our void pointer points to the int:  %d\n", *(int*)typeless);

    return 0;
}
