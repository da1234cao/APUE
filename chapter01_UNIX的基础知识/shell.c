/**
 * 执行不包含参数的命令
*/
#include "apue.h"
#include <sys/types.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void){
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    // 返回值是一个指针，指向字符串中第一个字符的地址；输入EOF的时候截止
    while(fgets(buf,MAXLINE,stdin)!=NULL){
        if(buf[strlen(buf)-1] == '\n')
            buf[strlen(buf)-1] = 0;

        if( (pid = fork()) < 0)
            err_sys("fork failed");
        else if( pid  == 0){
            // execle成功則函數不會返回，直接退出；執行失敗則直接返回-1，失敗原因存於errno 中
            execlp(buf,buf,NULL);
            err_ret("%s execute failed",buf);
            exit(127);
        }

       if( (pid = waitpid(pid,&status,0)) < 0){
           err_sys("waitpid error");
       }

       printf("%% "); 
    }

    return 0;
}