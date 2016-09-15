#include<stdio.h>
#include<math.h>

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
      res = tal1 + tal2;
      break;
    case multiplied:
      res = tal1 * tal2;
      break;
  }

  printf("%.2lf\n",res);

  return(0);

}
