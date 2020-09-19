/**
 * 文件名：file_access.c
 * 功能：检测是否具有对该文件的写权限，有的话，则打开，在后面追加内容
 * 注1：access检测文件的有效ID，非实际ID
 * 注2：检测和执行分开，非特权程序
 * 注3：access不成功，open也可能成功，对于特权程序
*/

#include "apue.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
    int fd;
    char *file_name = argv[1];
    char *buf = "append!\n";

    if(argc<2){
        err_quit("usage:file_access <pathname>");
    }

    if(access(file_name,R_OK|W_OK) < 0){
        err_ret("access error : %s\n",file_name);
    }else{
        printf("access for : %s\n",file_name);
    }

    if((fd=open(file_name,O_RDWR|O_APPEND)) < 0){
        err_ret("open error : %s\n",file_name);
    }else{
        printf("open for : %s\n",file_name);
        write(fd,buf,strlen(buf));
    }
    close(fd);

    return 0;
}