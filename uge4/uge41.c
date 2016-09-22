
/*
    Varebestillings software opgave 2.1
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden


Includerer relevante libraries
*/
#include "uge41.h"




/*vores main function*/
int main()
{
    struct kundeordre cur_ordre[maksBest];
    int counter = 0;
    int flereVarer = 1;

    while (flereVarer == 1 && counter < maksBest) 
    {

        printf("Varenummer:\n");
        scanf("%d", &cur_ordre[counter].vareNr);


        printf("Antal:\n");
        scanf("%d", &cur_ordre[counter].antal);

        counter++;

        printf("Vil du tilføje flere varer? (1/0)\n");

        int manglerSvar = 1;

        while (manglerSvar) 
        {
             int svar;
             scanf("%d", &svar);
             switch (svar)
             {
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
              }
         }
    }

  if (counter >= maksBest) {
      printf("Indkøbskurv fyldt! \nFaktura printes!\nTryk en vilkaarlig tast for at fortsaette:\n");
  }
  print_ordre(cur_ordre,counter);


return 1;
}


void print_lager(struct lagervare lager[])
{
    printf("\n\n\tVarelager:\n");


    for (int i = 0; i < maksBest; i++) 
    {
        printf("\t\tvarenummer  |  Pris  |  Beskrivelse\n");
        printf("\t\t_____________________________________\n");
        printf("\t\t%d  ",lager[i].vareNr);
        printf("\t\t%d  ",lager[i].pris);
        printf("\t\t%s\n",lager[i].beskrivelse);

    }
    printf("\n\t\t_____________________________________\n");


lager[0].pris =0;
}

struct lagervare lager_search(struct lagervare lager[], int varenummer)
{
    struct lagervare fejlet = {.vareNr = 999, .pris = -1, .beskrivelse = "varen blev ikke fundet"};
    for (int i = 0; i < maksBest; i++) 
    {
        if(lager[i].vareNr == varenummer)
        {
            return lager[i];
        } 
    }
    printf("varen findes ikke på lageret");
    return fejlet;
}

void print_ordre(struct kundeordre ordre[], int count)
{
    int total = 0;
    struct lagervare temp;
    for (int i = 0; i < count; i++) 
    {
        temp = lager_search(firmaLager, ordre[i].vareNr);


    }
    
    

}


