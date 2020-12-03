/**
 * 获取子进程返回的信息：wait、waitpid
 * 这两个函数的返回信息，存储在一个整形的状态字中。
 * 其中某些位表示退出状态(正常返回)，其他位则指示信号编号(异常返回)，有一位指示是否产生core文件等
 * POSIX.1规定， 终止状态用定义在<sys/wait.h>中的各个宏来查看
 * 有4个互斥的宏可用来取得进程终止的原因， 它们的名字都以WIF开始
 * 
 * 演示终止状态的各种值
 * 正常终止|about退出SIGABRT|除0退出SIGFPE
 * 
 * 若要查看特定进程的退出状态，可以循环调用wait；或者调用waitpid
 * 
 * core dump文件生成：https://www.codenong.com/cs106672319/
 * ulimit -c unlimited ---》允许core dump
 * sysctl -w kernel.core_pattern=./core-%e.%p.%h.%t
 * 
 * 代码中的宏定义是这么写的，没见过
 * 
*/

#include "apue.h"
#include <sys/wait.h>
#include <unistd.h>

void pr_exit(int status){
    if(WIFEXITED(status)) // 正常终止子进程返回状态
        printf("normal termination, eexit status = %d\n",WEXITSTATUS(status));
    else if(WIFSIGNALED(status)) // 异常终止的子进程返回状态
        printf("abnormal termination,signal number = %d%s\n",
            WTERMSIG(status),
#ifdef __WCOREDUMP
            __WCOREDUMP(status) ? "(core file generated)":"");
#else 
            "");
#endif
    else if(WIFSTOPPED(status)) // 当前暂停子进程的返回状态
        printf("child stopped,signal num = %d\n", WIFSTOPPED(status));
    else
        printf("not detected");
}

int main(void){
    pid_t pid;
    int status;

    if((pid = fork())<0)
        err_sys("fork error");
    else if(pid == 0)
        exit(7); // 正常退出
    if(wait(&status) != pid)
        err_sys("wait error");
    pr_exit(status);

    
    if((pid = fork())<0)
        err_sys("fork error");
    else if(pid == 0)
        abort(); // 异常退出
    if(wait(&status) != pid)
        err_sys("wait error");
    pr_exit(status);


    if((pid = fork())<0)
        err_sys("fork error");
    else if(pid == 0)
        status /= 0; // 异常退出
    if(wait(&status) != pid)
        err_sys("wait error");
    pr_exit(status);

    return 0;
}