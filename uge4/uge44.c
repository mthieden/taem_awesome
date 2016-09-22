
/*
    Varebestillings software opgave 2.1
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden


Includerer relevante libraries
*/
#include "uge41.h"

struct forsendelse 
{
    char kat;
    float pris;
};
struct forsendelse a[5] = {{.kat = 'A', .pris = 25},
                           {.kat = 'B', .pris = 35},
                           {.kat = 'C', .pris = 50},
                           {.kat = 'D', .pris = 100},
                           {.kat = 'E', .pris = 200}};


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

      ordreCheck = 1;

      while (ordreCheck == 1) {
        printf("Antal:\n");
        ordreCheckHolder;
        scanf("%d", &ordreCheckHolder);
        if (ordreCheckHolder > 0 && ordreCheckHolder < 6) {
          cur_ordre[counter].antal = ordreCheckHolder;
          ordreCheck = 0;
        } else {
          printf("Prov igen\n");
        }
      }

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
  bobble_sort(cur_ordre,counter);
  print_ordre(cur_ordre,counter);

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


void bobble_sort(struct kundeordre array[], int length)
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
                temp = array[i];
                array[i] = array[i-1];
                array[i-1] = temp;
                swapped = 1;
            }

        }

    length--;
    }

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
    float total = 0;
    float rabat = 0;
    int antalTotal = 0;
    int fors = 0;
    int subTotal;

    int temp;
    printf("\n\n\tBestilling:\n");
    printf("\t\tVarenummer  |  Pris  |  Antal  | subtotal  |    Beskrivelse\n");
    printf("\t\t________________________________________________________________\n");
    for (int i = 0; i < count; i++)
    {
        temp = lager_search(ordre[i].vareNr);
        total += firmaLager[temp].pris * ordre[i].antal;
        subTotal = firmaLager[temp].pris * ordre[i].antal;

        printf("\t\t%2d",ordre[i].vareNr);
        printf("%16dkr",firmaLager[temp].pris);
        printf("%9d",ordre[i].antal);
        printf("%12dkr",subTotal);
        printf("\t%s\n",firmaLager[temp].beskrivelse);
        antalTotal += ordre[i].antal;
    
    }

    //Prisen udskrives før forsendelse og evt. rabatter
     printf("\n\t\tsamlet pris:%.2fkr\n", total);
    //rabat og fragt beregnes efter fastsatte krav
    if(total > 500)
    {
        rabat = total * 0.1;
        total *= 0.9;
    } //end of if
    else if (total < 200 || antalTotal < 3)
    {
        total += 50;
        fors += 50;
    } //end of else if

    //Det fulde resultat, dvs rabat, forsendelse osv skrives
    printf("\n\t\tforsendelse:%d\n", fors);
    printf("\n\t\trabat:%.2f\n", rabat);
    printf("\n\t\ttotal pris:%.2f\n", total);
}

