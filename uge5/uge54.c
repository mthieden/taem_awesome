#include<stdio.h>
#include<time.h>

time_t rawtime;
struct tm *timeinfo;
int alarm[] = {0,0,0};

void show_time(void);

void set_time(void);

void set_alarm(void);

void snooze(void);

void stop_alarm(void);

void power_off(void);

int menuRunner = 1;
int choice;

int main()
{

void (*menu[6])(void) = { show_time,
                          set_time,
                          set_alarm,
                          snooze,
                          stop_alarm,
                          power_off};

  while (menuRunner != 0)
  {

    printf("==== Menu ====\n");
    printf("TidsModus:\t1\n");
    printf("Indstil tid:\t2\n");
    printf("Indstil alarm:\t3\n");
    printf("Snooze alarm:\t4\n");
    printf("Stop alarm:\t5\n");
    printf("Hiv stik ud:\t6\n");

    int choiceChecker = 1;

    while (choiceChecker)
    {
      scanf(" %d",&choice);

      if (0 < choice && choice < 7)
      {
        choiceChecker = 0;
      } else {
        printf("Prov igen\n");
      }//end if else

     } //end choiceChecker loop

    choice--;
    (*menu[choice])();

  }//end of menuRunner
  sluk:
  return 0;
}//end of main

void show_time()
{
    time ( &rawtime);
    timeinfo = localtime ( &rawtime );

    if(alarm[0] == 1 && alarm[1] == timeinfo->tm_hour && alarm[2] == timeinfo->tm_min )
    {
        printf("ALARM!!!!!!!!!!!!!\n");
    }
    printf("%d:%d\n",timeinfo->tm_hour, timeinfo->tm_min);
}


void set_time(void)
{
    printf("go to your system setting and change the time\n");
}

void set_alarm(void)
{
    alarm[0] = 1;
    printf("input hour\n");
    scanf("%d",&alarm[1]);

    printf("input minutes\n");
    scanf("%d",&alarm[2]);
}

void snooze(void)
{
    alarm[2] = (alarm[2]+5)%60;
    printf("Alarmen er blevet udskudt! med 5 min\n");
}

void stop_alarm(void)
{
    alarm[0] = 0;
    printf("Alarmen er blevet slukket\n");

}

void power_off(void)
{
    menuRunner = 0;
    printf("slukker program\n");

}
