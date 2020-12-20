/**
 * 一个简单的信号处理程序， 它捕捉两个用户定义的信号并打印信号编号。
 * 函数原型：void (*signal(int signo, void (*func)(int)))(int);
 * 
 * typedef void Sigfunc(int);
 * Sigfunc *signal(int, Sigfunc *);
 * 
 * SIGUSR1 这是一个用户定义的信号， 可用于应用程序。
 * SIGUSR2 这是另一个用户定义的信号， 与SIGUSR1相似， 可用于应用程序
 * 
 * 让程序后台运行，使用kill对该后台发送信号，查看效果
*/

#include "apue.h"
#include <signal.h>
#include <unistd.h>

//这个信号处理函数啥也没干啊，比如waitpid
static void self_use(int signo){
    if(signo == SIGUSR1)
        printf("capture SIGUSR1 signal\n");
    else if(signo == SIGUSR2)
        printf("capture SIGUSR2 signal\n");
    else
        printf("unrecogenize signal\n");
    return;
}

int main(void){
    if(signal(SIGUSR1,self_use) == SIG_ERR)
        err_sys("signal fail");
    if(signal(SIGUSR2,self_use) == SIG_ERR)
        err_sys("signal fail");
    // pause(); // pause（）函数是将进程挂起等待任意一个信号，若接收到信号则当信号处理完毕之后pause会返回
    while(1)
        pause();
}

