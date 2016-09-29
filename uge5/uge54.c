#include<stdio.h>
#include<time.h>

// time_t er en type fra time.h, der indeholder tiden
time_t rawtime;

// tm er en datastruktur, der også indholder tiden
// // til forskel fra time_t kan vi hente ønsket variable ud af tm.
// // siden timeinfo er en pointer henter vi data ud fra den med timeinfo->tm_min 
// // i stedet for timeinfo.tm_min
struct tm *timeinfo;

// {tændt_alarm_signal, timer, minutter }
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
    // time henter nuværende tidspunkt fra computer
    time ( &rawtime);

    // localtime parser rawtime ind i timeinfo
    timeinfo = localtime ( &rawtime );

    if(alarm[0] == 1 && alarm[1] == timeinfo->tm_hour && alarm[2] == timeinfo->tm_min )
    {
        printf("ALARM!!!!!!!!!!!!!\n");
    }
    printf("%d:%d\n",timeinfo->tm_hour, timeinfo->tm_min);
}


void set_time(void)
{
    // time funktionerne bestemmer tiden udfra indstillingerne på brugerens computer 
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

// snooze ligger fem minutter ekstra til alarmen, og tager 
// // højde for at der kun er 60 min på en time
void snooze(void)
{
    if(alarm[2]+5>=60)
    {
        alarm[2] = (alarm[2]+5)%60;
        alarm[1]++;
    }
        else
    {
        alarm[2] += 5;   

    }
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
