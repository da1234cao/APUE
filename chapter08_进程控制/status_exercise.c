/**
 * 获取子进程返回的信息：wait、waitpid
 * 这两个函数的返回信息，存储在一个整形的状态字中。
 * 其中某些位表示退出状态(正常返回)，其他位则指示信号编号(异常返回)，有一位指示是否产生core文件等
 * POSIX.1规定， 终止状态用定义在<sys/wait.h>中的各个宏来查看
 * 有4个互斥的宏可用来取得进程终止的原因， 它们的名字都以WIF开始
 * 
 * 代码中的宏定义是这么写的，没见过
 * 
*/

#include "apue.h"
#include <sys/wait.h>

void pr_exit(int status){
    if(WIFEXITED(status))
        printf("normal termination, eexit status = %d\n",WEXITSTATUS(status));
    else if(WIFSIGNALED(status))
        printf("abnormal termination,signal number = %d%s\n",
            WTERMSIG(status),
#ifdef __WCOREDUMP
            __WCOREDUMP(status) ? "(core file genetated)":"");
#else 
            "");
#endif
    else if(WIFSTOPPED(status))
        printf("child stopped,signal num = %d\n", WIFSTOPPED(status));
}

