
/*
    Varebestillings software opgave 5.1
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden


Includerer relevante libraries
*/
#include "uge5.h"




/*vores main function*/
int main()
{
    struct kundeordre cur_ordre[maksBest];
    int counter = 0;
    int flereVarer = 1;
    int ordreCheck;
    int ordreCheckHolder;

    print_lager(firmaLager);

    while (flereVarer == 1 && counter < maksBest)
    {
      ordreCheck = 1;

      while (ordreCheck == 1) {
        printf("Varenummer:\n");
        scanf("%d", &ordreCheckHolder);

        if (ordreCheckHolder > 0 && ordreCheckHolder <= maksBest) {
          cur_ordre[counter].vareNr = ordreCheckHolder;
          ordreCheck = 0;
        } else {
          printf("Prov igen\n");
        }

      }



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

  bobble_sort(cur_ordre, counter);
  print_ordre(cur_ordre, counter);

return 1;
}


void print_lager(struct lagervare lager[])
{
    printf("\n\n\tVarelager:\n");
    printf("\t\tvarenummer  |  Pris  |  Beskrivelse\n");
    printf("\t\t_____________________________________\n");

    for (int i = 0; i < maksBest; i++)
    {

        printf("\t\t%d  ",lager[i].vareNr);
        printf("\t%10d kr",lager[i].pris);
        printf("\t%s\n",lager[i].beskrivelse);

    }
    printf("\n\t\t_____________________________________\n");

}


int lager_search(int varenummer)
{
    for (int i = 0; i < maksBest; i++)
    {
        if(firmaLager[i].vareNr == varenummer)
        {
            return i;
        }
    }
    printf("varen findes ikke på lageret\n");

    return -1; //betyder at den har fejlet
}


void print_ordre(struct kundeordre ordre[], int count)
{
    FILE *filPointer;
    filPointer = fopen("Bestilling.txt", "w");

    int total = 0;
    int temp;
    fprintf(filPointer,"\n\n\tBestilling:\n");
    fprintf(filPointer,"\t\tVarenummer  |  Pris  |  Antal  | subtotal  |    Beskrivelse\n");
    fprintf(filPointer,"\t\t________________________________________________________________\n");
    for (int i = 0; i < count; i++)
    {
        //Vi laver en allround void pointer, vi bruger til at referere til vores struct.
        void *ordreAllRoundPointer;

        temp = lager_search(ordre[i].vareNr);
        int subtotal = firmaLager[temp].pris * ordre[i].antal;
        total += subtotal;
        //referere void pointer til vareNr
        ordreAllRoundPointer = &ordre[i].vareNr;
        //typecaster void pointer til en int pointer
        fprintf(filPointer,"\t\t%2d",*(int*)ordreAllRoundPointer);

        //samme sker næsten efterfølgende bemærk comment ved char**
        ordreAllRoundPointer = &firmaLager[temp].pris;
        fprintf(filPointer,"%16dkr",*(int*)ordreAllRoundPointer);

        ordreAllRoundPointer = &ordre[i].antal;
        fprintf(filPointer,"%9d",*(int*)ordreAllRoundPointer);

        ordreAllRoundPointer = &subtotal;
        fprintf(filPointer,"%12dkr",*(int*)ordreAllRoundPointer);

        //her bliver der typecastet til en ((character array) pointer)
        //dvs en "pointer pointer"
        ordreAllRoundPointer = &firmaLager[temp].beskrivelse;
        fprintf(filPointer,"\t%s\n",*(char**)ordreAllRoundPointer);


    }
    fprintf(filPointer,"\n\n\t\tTotal:%dkr\n", total);
}

void swap(struct kundeordre *a, struct kundeordre *b)
{
    struct kundeordre temp = *a;
    *a = *b;
    *b = temp;
}

void bobble_sort(struct kundeordre *array, int length)
{
    int swapped = 1;
    struct kundeordre temp;
    while (swapped)
    {
        swapped = 0;
        for(int i = 1; i < length; i++)
        {
            if (array[i].vareNr < array[i-1].vareNr)
            {
                swap(&array[i], &array[i-1]);
                swapped = 1;
           }

       }

   length--;
   }

}
