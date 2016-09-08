/*
    Varebestillings software opgave 2.4
    Gruppe "taem awesome" (ja det er stavet forkert med vilje)
        s153460 Jonas Ladefoged Holm
        s113070 David Bjerre Bjørklund
        s164920 Markus Visvaldis Ingemann Thieden


Inkluderer relevante libraries
Og definerer maksBest(maksbestilling) til 10
for optimering af kode. Vores arrays skal have defineret en størrelse fra start.
Denne definition gør at vi kan ændre denne størrelse nemt, et sted. Bliver også brugt
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
total bruges til totalprisen
rabat bruges til at opbevare den beregnede rabat,*/

int counter = 0;
int flereVarer = 1;
int vareNr[maksBest];
int pris[maksBest];
int antal[maksBest];
int inputError = 0;
float total = 0;
int forsendelse = 0;
float rabat;
int antalTotal = 0;


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
      /* counter variablen bruges som index i divere arrays og ændrer dynamisk hvor informationen lagres.*/
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
      if(antal[counter]=<5 && antal[counter]>0)
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

   //Tæller at kunden har tilføjet en bestilling
    counter++;

    /*Kunden beslutter om han/hun vil tilføje flere bestillinger*/
    printf("Vil du tilføje flere varer? (1/0)\n");

    /* manglerSvar og while loopet sørger for at spørge om input indtil dette godkendes i switch case (enten 0 eller 1.*/
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
flere bestillinger end der er plads til, dette er sat i stand for ikke at overskriver
tidligere værdier i vores arrays eller risikere overflow*/
    
  if (counter >= maksBest) {
      printf("Indkøbskurv fyldt! \nFaktura printes!\nTryk en vilkaarlig tast for at fortsaette:\n");
      /*PAUSE bruges windows specifikt til at lade brugeren af programmet
      se at der ikke er mere plads i indkøbskurven*/
      system("PAUSE");
      system("CLS");
  } //end of if (maksBestilling)

  /*Faktura printes til standard output.
  alle bestillinger vha vores for-loop, der har
  en variabel "i", der bruges som index, til at hente den passende værdi
  i arrays*/
  printf("\n\n\tFaktura:\n");


  for (int i = 0; i < counter; i++) {
    /*Outout formateres. '/t' (tab) bruges til at gøre outputtet mere læsbart
    sammen med det følgende printf statement*/
    printf("\t=======================\n");
    printf("\t\tVare nummer:%d\n", vareNr[i]);
    printf("\t\tAntal:%d\n", antal[i]);
    printf("\t\tPris/stk:%d\n", pris[i]);

    total += antal[i]*pris[i];
    //vi har brug for at beregne hvor mange ting der er bestilt
    antalTotal += antal[i];
  } //end of for loop (print varer)

  //Prisen udskrives før forsendelse og evt. rabatter
  printf("\n\t\tsamlet pris:%f\n", total);
  //rabat og fragt beregnes efter fastsatte krav
  if(total > 500)
  {
    rabat = total * 0.1;
    total *= 0.9;
  } //end of if
  else if (total < 200 || antalTotal < 3)
  {
    total += 50;
    forsendelse += 50;
  } //end of else if

  //Det fulde resultat, dvs rabat, forsendelse osv skrives
  printf("\n\t\tforsendelse:%d\n", forsendelse);
  printf("\n\t\trabat:%f\n", rabat);
  printf("\n\t\ttotal pris:%f\n", total);


return 1;
} //end of main
