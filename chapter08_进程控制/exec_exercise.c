/**
 * exec家庭成员有7个
 * 当进程调用一种exec函数时， 该进程执行的程序完全替换为新程序， 而新程序则从其main函数开始执行。 
 * 因为调用exec并不创建新进程， 所以前后的进程ID并未改变。 
 * exec只是用磁盘上的一个新程序替换了当前进程的正文段、 数据段、 堆段和栈段。
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "apue.h"

int main(void){
    __pid_t pid;

    if((pid=fork())<0)
        err_sys("fork error");
    else if(pid == 0){
        char *argv[] = {"ls -alh",NULL};
        if(execve("/bin/ls",argv,__environ)<0)
            err_sys("ececve error");
    }

    if(waitpid(pid,NULL,0)<0)
        err_sys("wait err");
    
    return 0;
}