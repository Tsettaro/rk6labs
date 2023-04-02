#include <stdio.h>
#include <time.h>

int main(){
    int hour, minute, second;
    hour = ((time(NULL)+10800)/3600)%24; // 10800 секунд – 3 часа
    minute = (time(NULL)/60)%60;
    second = time(NULL)%60;
    printf("%.2d:%.2d:%.2d \n",hour, minute, second);
    return 0;
}
