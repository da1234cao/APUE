/**
 * fork之后，父进程和子进程都要执行一些任务
 * 当最后的结果和进程的运行顺序有关的时候，我们认为发生了竞争条件
 * 
 * 如果一个进程希望等待一个子进程终止， 则它必须调用wait函数中的一个。 
 * 如果一个进程要等待其父进程终止， 则可使用循环：while(getppid() != 1)
 * 
 * 为了避免竞争条件和轮询， 在多个进程之间需要有某种形式的信号发送和接收的方法。 在UNIX 中可以使用信号机制。 
 * 各种形式的进程间通信（IPC） 也可使用。
 * 
 * 这里演示下竞争条件
*/

#include <stdio.h>
#include <unistd.h>
#include "apue.h"

static void charattime(char *str);

int main(void){
    __pid_t pid;
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
        charattime("child process out\n");
        // printf("child process out\n");
    else
        charattime("parent process out\n");
        // printf("parent process out\n");
    return 0;
}

static void charattime(char *str){
    char *ptr;
    char c;
    // 将标准输出的缓冲区设置为空，打印字符串的时候，每次只能输出一个字符；使得进程之间的切换，容易出现竞争现象
    setbuf(stdout,NULL); 

    for(ptr=str; (c=*ptr++)!=0;){
        putc(c,stdout);
    }
}