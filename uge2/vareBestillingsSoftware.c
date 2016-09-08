/* Varebestillings software opgave 2.1
*/
#include<stdio.h>
//#define maksBest 10

/*
Deklarerer de nødvendige variabler
*/
int counter = 0;
int flereVarer = 1;
int vareNr[10];
int pris[10];
int antal[10];
int maksBest = 10;

int main()
{
while (flereVarer == 1 && counter < maksBest) {
    printf("Varenummer:\n");
    scanf("%d", &vareNr[counter]);
    printf("Pris:\n");
    scanf("%d", &pris[counter]);
    printf("Antal:\n");
    scanf("%d", &antal[counter]);
    counter++;

    printf("Flere varer? (1/0)\n");
    int manglerSvar = 1;

    while (manglerSvar) {
      int svar;
      scanf("%d", &svar);
      switch (svar) {
        case 1:
          flereVarer = 1;
          manglerSvar = 0;
          printf("hej Y y\n");
          break;
        case 0:
          flereVarer = 0;
          manglerSvar = 0;
          printf("hej N n\n");
          break;
        default:
          printf("Yo slem stil der! \n Brug nu bare 1 for flere varer eller 0 for at afslutte indtastningen \n");
          break;
      } //end of switch(svar)
        //goto #YOLO
    } //end of while(manglerSvar)

  } //end of while

return 1;
} //end of main
