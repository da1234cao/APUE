/**
 * 组合alarm和pause，实现sleep
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "apue.h"

static void sig_alrm(int signo){
    //do nothing,just for wake wu pause
}

// 这个程序有三个问题
// 1. 程序如果之前已经设置了alram，那么sleep宗alarm会被擦除。应当和原来的剩余时间比较。如果原来的时间大，仍然用原来的时间；如果原来的时间小，使用新定时时间
// 2. 这里修改了SIGALRM信号默认的处理方式，应当报错原来的处理方式。sleep结束后，使用原来的处理方式。good
// 3. 调用alarm和sleep之前存在竞争条件。由于进程调度的原因，可能alarm结束后，才调用sleep，导致进程被挂起，出不去了。
// 第3个问题。 第一种方法是使用setjmp， 下一个实例将说明这种方法。 另一种方法是使用sigprocmask和sigsuspend
int sleep(int seconds){
    if(signal(SIGALRM,sig_alrm) == SIG_ERR)
        err_sys("signal failed");
    alarm(10);
    pause();
    return(alarm(0));// turen of timer,return the unsleep time
}