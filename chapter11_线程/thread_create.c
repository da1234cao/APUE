/**
 * 创建一个线程
 * int pthread_create(pthread_t *restrict tidp,
 * const pthread_attr_t *restrict attr,
 * void *(*start_rtn)(void *), void *restrict arg);
 * 
 * 书上说，这个代码两个地方值得关注；
 * 1. 可能会有竞争条件
 * 2. 新线程没有选择去读取进程中的自身线程id，而是自己获取。
*/
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include "apue.h"

// pthread_t ntid;

void printid(char *s){
    pid_t pid = getpid();
    pthread_t tid = pthread_self();
    printf("%s pid %d tip %lu (0x%lx)\n", s,pid,tid,tid);
}

void *thr_fun(void *arg){
    printid("new thread :");
    return (void *)0;
}

int main(void){
    pthread_t ntid;
    int err = pthread_create(&ntid,NULL,thr_fun,NULL);
    if(err !=0 )
        err_sys("create thread error : %d\n",err);
    printid("main thread: ");
    sleep(1);
    return 0;
}