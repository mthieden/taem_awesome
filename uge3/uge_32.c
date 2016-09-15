#include<stdio.h>
#include<math.h>

int main (void){

  printf("Velkommen til lommeregneren!\n");

  double tal1;
  double tal2;

  printf("Indtast det første tal: ");
  scanf("%f\n", &tal1);

  printf("Indtast det andet tal: ");
  scanf("%f\n", &tal2);

  printf("%f\n",tal1 );
  printf("%f\n",tal2 );

  gets();

  return(0);

}
