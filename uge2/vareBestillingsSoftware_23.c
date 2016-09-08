/*
    Varebestillings software opgave 2.3
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden


Includerer relevante libraries
Og definerer maksBest(maksbestilling) til 10
for optimering af kode, vores arrays skal have defineret en størrelse fra start,
denne definition gør at vi kan ændre denne størrelse nemt, et sted, bliver også brugt
som en begrænsning af bestillingslisten.
*/
#include<stdio.h>
#include<stdlib.h>
#define maksBest 10

/*
Deklarerer de nødvendige variabler:
counter: tæller hvor mange bestillinger kunden har lavet.
flereVarer: en sandhedsværdi, der bruges til at tjekke om kunden vil bestille flere varer
vareNr[maksBest] / pris[maksBest] / antal[maksBest]: vores krævede informationer om bestillingerne.
total bruges til totalprisen*/
int counter = 0;
int flereVarer = 1;
int vareNr[maksBest];
int pris[maksBest];
int antal[maksBest];
int total =0;
int inputError = 0;


/*vores main function*/
int main()
{
  //en operativsystem specifik kommando der rydder op i skærmbilledet i Windows.
  //producerer dog en fejlkode i OSX og Linux
  system("CLS");

  /*så længe at kunden vil tilføje flere bestillinger og at vi ikke har
  opnået vores fastsatte maksimum størrelse af kurven*/
  while (flereVarer == 1 && counter < maksBest) {

    /*Control af at ordren overholder de fastsatte rammer
    fejl bliver fanget af et do while loop, vha af en if statement der
    åbner og lukker loopet alt efter om grænseværdierne er i orden,
    samtidigt bliver brugeren også informeret om fejlen,*/

    //check og indtast varenummer
    do
    {
      printf("Varenummer:\n");
      /*scanf funktionen ændrer dynamisk hvor i diverse arrays, den lagrer informationen.
      dette gør den ved at bruge counter variablen i stedet for et fast tal*/
      scanf("%d", &vareNr[counter]);
      system("CLS");

      if(vareNr[counter]>3 && vareNr[counter]<23)
      {
        inputError = 0;
      }
      else
      {
        inputError = 1;
        printf("fejl i varenummer\n");
      }
    }
    while (inputError);

    //check og indtast pris
    do
    {
      printf("Pris:\n");
      scanf("%d", &pris[counter]);
      system("CLS");
      if(pris[counter]>1 && pris[counter]<100)
      {
        inputError = 0;
      }
      else
      {
        inputError = 1;
        printf("fejl i pris\n");
      }
     }
    while (inputError);

    //check og indtast antal
    do
    {
      printf("Antal:\n");
      scanf("%d", &antal[counter]);
      system("CLS");
      if(antal[counter]<5)
      {
        inputError = 0;
      }
      else
      {
        inputError = 1;
        printf("fejl i antal\n");
      }
     }
     while (inputError);

   //Tæller at nu har kunden tilføjet en bestilling
    counter++;

    /*Kunden beslutter om han/hende vil tilføje mere til bestillingen*/
    printf("Vil du tilføje flere varer? (1/0)\n");

    /* manglerSvar og while loopet sørger for at vi ikke går videre indtil at
    at vores switch case, har godkendt besvarelsen der enten skal være 1
    eller 0*/
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
  } //end of while (flereVarer)

/*En fejl meddelelse til brugeren der kun viser sig hvis kunden ønsker at tilføje
flere bestillinger end der er plads til, dette er sat i stand for at vi ikke overskriver
tidligere værdier i vores arrays*/
  if (counter >= maksBest) {
      printf("Indkøbskurv fyldt! \nFaktura printes!\nTryk en vilkaarlig tast for at fortsaette:\n");
      /*PAUSE bruges windows specifikt til at lade brugeren af programmet
      se at der ikke er mere plads i indkøbskurven*/
      system("PAUSE");
      system("CLS");
  } //end of if (maksBestilling)

  /*Så printer vi vores Faktura til standard output
  vi printer alle forsendelser vha vores for loop, der har
  en variabel "i", der bruges til at hente den passende værdi
  i de diverse arrays*/
  printf("\n\n\tFaktura:\n");


  for (int i = 0; i < counter; i++) {
    /*der bliver pyntet, /t bruges til at gøre outputtet mere læsbart
    sammen med det følgende printf statement*/
    printf("\t=======================\n");
    printf("\t\tVare nummer:%d\n",vareNr[i]);
    printf("\t\tAntal:%d\n",antal[i]);
    printf("\t\tPris/stk:%d kr.\n",pris[i]);

    total += antal[i]*pris[i];
  } //end of for loop (print bestillinger)
  /*printer totalprisen*/
  printf("\n\t\ttotal:%d kr.\n",total);

return 1;
} //end of main
