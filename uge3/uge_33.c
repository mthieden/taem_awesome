#include<stdio.h>
#include<math.h>

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

  //for at træne brugen af enums gør jeg brug af dem her
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

  switch (currentValg) {
    case added:
      res = addition(tal1,tal2);
      break;
    case multiplied:
      res = multiplication(tal1,tal2);
      break;
  }

  printf("%.2lf\n",res);

  return(0);

}

//her er de 2 funktioner der erstatter funktionaliteten der før var i main
double addition(double a, double b){
  return a + b;
}

double multiplication(double a, double b){
  return a * b;
}
