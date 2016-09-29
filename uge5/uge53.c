#include <stdio.h>

//definere 3 funktioner
void function1(int a);
void function2(int b);
void function3(int c);

int main() {

  //laver et funktionspointer array, der peger til de 3 funktioner
  void (*f[3])(int) = { function1, function2, function3};


  int valg;

  //spørger første gang om hvilken funktion man vil køre.
  //resten af gangene bliver håndteret af while loopet.
  printf("Hvilken funktion vil du ha?(1-3)\n");
  scanf(" %d",&valg);

//koden lavet om så at et mere logisk 0 eller tal over 3 afslutter programmet.
  while (0 < valg && valg < 4) {
    int arrayValg = valg - 1; //valg bliver ordentligt oversat til arrayet.
    (*f[arrayValg])(valg); //kalder en funktion alt efter valg.

    printf("Hvilken funktion vil du ha?(1-3)\n");
    scanf(" %d",&valg);
  }

  puts("Program sluttet");

  return 0;
}


//de tre funktioner
void function1(int a){
  printf("Du har valgt %d, saa funktion1 er blevet kaldt\n", a);
}
void function2(int b){
  printf("Du har valgt %d, saa funktion2 er blevet kaldt\n", b);
}
void function3(int c){
  printf("Du har valgt %d, saa funktion3 er blevet kaldt\n", c);
}
