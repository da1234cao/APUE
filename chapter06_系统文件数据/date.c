/**
 * 显示当前时间
*/

#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void date(void){
    time_t t;
    struct tm *tmp;
    const int buf_size = 256;
    char buf[256];

    //获取当前时间，并分解，格式化输出
    time(&t);
    // tmp = gmtime(&t);
    tmp = localtime(&t);
    if(strftime(buf,buf_size,"time and date : %Y  %b %d || %a || %X ",tmp) == 0)
        printf("buffer length  is too small\n");
    else
        printf("%s\n",buf);
}

int main(void){
    date();
    return 0;
}