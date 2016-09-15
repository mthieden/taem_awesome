/*
    Varebestillings software opgave 2.1
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
int total = 0;

/*vores main function*/
int main()
{
  //en operativsystem specifik kommando der rydder op i skærmbilledet i Windows.
  //producerer dog en fejlkode i OSX og Linux
  system("CLS");

  /*så længe at kunden vil tilføje flere bestillinger og at vi ikke har
  opnået vores fastsatte maksimum størrelse af kurven*/
  while (flereVarer == 1 && counter < maksBest) {

    /*scanf funktionen ændrer dynamisk hvor i diverse arrays, den lagrer informationen.
    dette gør den ved at bruge counter variablen i stedet for et fast tal*/
    printf("Varenummer:\n");
    scanf("%d", &vareNr[counter]);
    system("CLS");

    printf("Pris:\n");
    scanf("%d", &pris[counter]);
    system("CLS");

    printf("Antal:\n");
    scanf("%d", &antal[counter]);
    system("CLS");

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

  /*Så printer vi vores Vareliste til standard output
  vi printer alle forsendelser vha vores for loop, der har
  en variabel "i", der bruges til at hente den passende værdi
  i de diverse arrays*/
  printf("\n\n\tVareliste:\n");


  for (int i = 0; i < counter; i++) {
    /*der bliver pyntet, /t bruges til at gøre outputtet mere læsbart
    sammen med det følgende printf statement*/
    printf("\t\t=======\n");
    printf("\t\tVare nummer:%d\n",vareNr[i]);
    printf("\t\tAntal:%d\n",antal[i]);
    printf("\t\tPris/stk:%d\n",pris[i]);

    total += antal[i]*pris[i];
  } //end of for loop (print varer)
  /*printer totalprisen*/
  printf("\n\t\ttotal:%d\n",total);

return 1;
} //end of main
