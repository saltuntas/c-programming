#include <stdio.h>
#include <stdlib.h>

 struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
 };
 typedef struct  _retire_info  retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired) {
  int ageMonth = startAge % 12 ;
  int ageYear = (startAge-ageMonth)/12;
  printf("Age %3d month %2d you have $%.2lf\n", ageYear, ageMonth, initial);

  for(int i = 1; i<working.months+1; i++) {

    initial+=(initial*working.rate_of_return)+working.contribution;

    startAge = startAge + 1;
    int ageMonth= startAge % (12);
    int ageYear = (startAge-ageMonth)/12;
    
    printf("Age %3d month %2d you have $%.2lf\n", ageYear, ageMonth, initial);
  }

  for (int j =1; j<retired.months; j++) {

    initial+=(initial*retired.rate_of_return)+retired.contribution;

    startAge=startAge + 1;
    int ageMonth=startAge % (12);
    int ageYear = (startAge-ageMonth)/12;
    printf("Age %3d month %2d you have $%.2lf\n", ageYear, ageMonth, initial);
  }

}
int main(void) {

  retire_info working;
  working.months=489;
  working.contribution =1000;
  working.rate_of_return=(0.045/12);

  retire_info retired;
  
  retired.months=384;
  retired.contribution = -4000;
  retired.rate_of_return= (0.01/12);

  // Starting informations

  int  startAge=327;
  double  initial=21345;

  // Calling retirement computation

  retirement(startAge, initial, working, retired);

  return EXIT_SUCCESS;
}





