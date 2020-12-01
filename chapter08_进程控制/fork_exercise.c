/**
 * 描述：子进程对变量的修改，不影响父线程
*/

#include "apue.h"
#include <unistd.h>

int gloabalvar = 1;
char *str = "write to stdout\n";

int main(void){
    int localvar = 2;
    __pid_t pid;

    if(write(STDOUT_FILENO,str,strlen(str)) != strlen(str))
        err_sys("write to stdout error.");
    
    printf("befor fork\n");
    /**如果没有 fflush(stdout)，
     * ./fork_exercise 与 ./fork_exercise > data.txt 输出不同；
     * write函数不带缓冲区，不用管它；
     * printf标准I/O带有缓冲区;
     * 当交互输出的时候，标准输出缓冲区以换行符冲洗；
     * 当输出的文件的时候，是全缓冲的；
     * 如果不冲洗缓冲区，缓冲区中的内容，会被赋值到子进程中。
     * 当每个进程终止时， 其缓冲区中的内容都被写到相应文件中。
    */
    fflush(stdout);

    if((pid = fork()) < 0)
        err_sys("fork error : %d",pid);
    else if( pid ==0 ){
        gloabalvar++;
        localvar++;
    }else{
        sleep(2);
    }

    printf("pid is %d; globalvar is %d; localvar is %d;\n",getpid(),gloabalvar,localvar);
    return 0;
}