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

int main (void){

  //Declare variables
  printf("Welcome to the calculator!\n");

  double tal1;
  double tal2;
  double res;


  // User input
  printf("Input first number: ");
  scanf(" %lf", &tal1);

  printf("Input second number: ");
  scanf(" %lf", &tal2);

  printf("%.2lf\n", tal1);
  printf("%.2lf\n", tal2);

  printf("Should they be:\n1: Added together? \n2: Or multiplied?\n");

  // To excercise in the functionality of enums...
  enum brugerValg {intet, multiplied, added};
  enum brugerValg currentValg = intet;

  while (currentValg != multiplied && currentValg != added){
    int valg;
    scanf(" %d", &valg);

    // Training the use of enums...
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
      res = tal1 + tal2;
      break;
    case multiplied:
      res = tal1 * tal2;
      break;
    case intet:
      break;
  }

  // Print result
  printf("%.2lf\n",res);

  return(0);

}
