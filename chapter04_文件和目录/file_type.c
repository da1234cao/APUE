/**
 * 作用：查看文件类型
 * 测试：./file_type /etc/passwd /etc /dev/tty
 * 待：有的类型我没见过，不测试
*/
#include "apue.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <bits/stat.h> //S_ISSOCK
#include <unistd.h>

int main(int argc, char *argv[]){
    int i;
    struct stat st;
    char *ptr;

    for(i=1;i<argc;i++){
        printf("%s: ",argv[i]);

        if( lstat(argv[i],&st) == -1){
            err_ret("lstat error");
            continue;
        }

        if (S_ISREG(st.st_mode))
            ptr = "regular";
        else if(S_ISDIR(st.st_mode))
            ptr = "director";
        else if(S_ISCHR(st.st_mode))
            ptr = "charter special";
        else if(S_ISBLK(st.st_mode))
            ptr = "block special";
        else if(S_ISFIFO(st.st_mode))
            ptr = "fifo";
        else if (S_ISLNK(st.st_mode))
            ptr = "symbolic link";
        else if(S_ISSOCK(st.st_mode))
            ptr = "socket";
        else 
            ptr = "** unknown mode **";
        printf("%s\n",ptr);
    }

    return 0;
}
