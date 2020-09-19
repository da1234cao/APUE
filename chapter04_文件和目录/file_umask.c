/**
 * 屏蔽权限
*/
#include "apue.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RWRWR (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH) //664

int main(void){
    char *file_name = "./data.txt";

    if(creat(file_name,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)<0){
        err_sys("creat file error");
    }
    umask(S_IRGRP|S_IWGRP|S_IROTH);

    if(creat("./tmp.txt",RWRWR)<0){
        err_sys("creat file error");
    }

    return 0;
}