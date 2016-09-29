#include<stdio.h>
#include<time.h>

time_t rawtime;
struct tm * timeinfo;
int alarm[] = {0,0,0};

void show_time(void);

void set_time(void);

void set_alarm(void);

void snooze(void);

void stop_alarm(void);

int main()
{
    
    while(1)
    {
        show_time();
        set_time();
        set_alarm();
        show_time();
        snooze();
        show_time();
        stop_alarm();
        show_time();
    }
    return 0;
}

void show_time()
{
    time ( &rawtime);
    timeinfo = localtime ( &rawtime );
    
    if(alarm[0] == 1 && alarm[1] == timeinfo->tm_hour, alarm[2] == timeinfo->tm_min )
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
}

void stop_alarm(void)
{
    alarm[0] = 0;
}

