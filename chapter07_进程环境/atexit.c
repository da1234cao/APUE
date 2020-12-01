// 使用atexit 函数:int atexit(void (*func)(void));
// 返回值： 若成功， 返回0； 若出错， 返回非0

#include <stdio.h>
#include "apue.h"

void exit_func1(void){
    printf("This is the first exit_func\n");
}

void exit_func2(void){
    printf("This is the second exit_func\n");
}

int main(void){
    // 登记终止处理程序
    if(atexit(exit_func2)!=0)
        err_sys("canot register the exit_func2\n");
    if(atexit(exit_func1)!=0)
        err_sys("canot register the exit_func1\n");
    if(atexit(exit_func1)!=0)
        err_sys("canot register the exit_func1\n");
    
    printf("main func is down\n");
    return 0;
}