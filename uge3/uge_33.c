/* 

Uge 3 opgave 2
This is a simple calculator taking two numbers and multiply or add them together.
Gruppe "taem awesome" (ja det er stavet forkert med vilje)
    s153460 Jonas Ladefoged Holm
    s113070 David Bjerre Bjørklund
    s164920 Markus Visvaldis Ingemann Thieden
*/

#include <stdio.h>
#include <math.h>

//Function prototypes
double addition(double a, double b);
double multiplication(double a, double b);


int main (void){

  printf("Velkommen til lommeregneren!\n");

  double tal1;
  double tal2;
  double res;

  printf("Indtast det første tal: ");
  scanf(" %lf", &tal1);

  printf("Indtast det andet tal: ");
  scanf(" %lf", &tal2);

  printf("%.2lf\n", tal1);
  printf("%.2lf\n", tal2);

  printf("Should they be:\n1: Added together? \n2: Or multiplied?\n");

  // Training the use of enums...
  enum brugerValg {intet, multiplied, added};
  enum brugerValg currentValg = intet;

  while (currentValg != multiplied && currentValg != added){
    int valg;
    scanf(" %d", &valg);
    if (valg == 1){
      currentValg = added;
    } else if (valg == 2) {
      currentValg = multiplied;
    } else {
      printf("Wrong answer try again!\n");
    }
  }

  // Doing the calculations
  switch (currentValg) {
    case added:
      res = addition(tal1,tal2);
      break;
    case multiplied:
      res = multiplication(tal1,tal2);
      break;
  }

  // Print result
  printf("%.2lf\n",res);

  return(0);

}

// Takes two arguments and returns sum
double addition(double a, double b){
  return a + b;
}

// Takes two arguments and returns product.
double multiplication(double a, double b){
  return a * b;
}
