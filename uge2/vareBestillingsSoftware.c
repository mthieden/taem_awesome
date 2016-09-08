/* Varebestillings software opgave 2.1
*/
#include<stdio.h>
#include<stdlib.h>
//#define maksBest 10

/*
Deklarerer de nødvendige variabler
*/
int counter = 0;
int flereVarer = 1;
int vareNr[10];
int pris[10];
int antal[10];
int maksBest = 2;

int main()
{
  system("CLS");
while (flereVarer == 1 && counter < maksBest) {
    printf("Varenummer:\n");
    scanf("%d", &vareNr[counter]);
    system("CLS");

    printf("Pris:\n");
    scanf("%d", &pris[counter]);
    system("CLS");

    printf("Antal:\n");
    scanf("%d", &antal[counter]);
    system("CLS");
    counter++;

    printf("Vil du tilføje flere varer? (1/0)\n");
    int manglerSvar = 1;

    while (manglerSvar) {
      int svar;
      scanf("%d", &svar);
      system("CLS");
      switch (svar) {
        case 1:
          flereVarer = 1;
          manglerSvar = 0;
          break;
        case 0:
          flereVarer = 0;
          manglerSvar = 0;
          break;
        default:
          printf("Vil du tilføje flere varer? (1/0)\n");
          printf("Dit svar skal enten være 1 eller 0,\nprøv igen\n");
          break;
      } //end of switch(svar)

    } //end of while(manglerSvar)
  } //end of while (flere varer)

  if (counter >= maksBest) {
      printf("Indkøbskurv fyldt! \nFaktura printes!\nTryk en vilkaarlig tast for at fortsaette:\n");
      system("PAUSE");
      system("CLS");
  } //end of if (maksBestilling)

  printf("\n\n\tVareliste:\n");

  for (int i = 0; i < counter; i++) {
    printf("\t\t=======\n");
    printf("\t\tVare nummer:%d\n",vareNr[i]);
    printf("\t\tAntal:%d\n",antal[i]);
    printf("\t\tPris/stk:%d\n",pris[i]);
    printf("\t\tSubtotal:%d\n",pris[i]);

  } //end of for loop (print varer)

return 1;
} //end of main
