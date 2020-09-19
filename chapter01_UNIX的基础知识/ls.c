/**
 * 查看指定目录中，有哪些文件
*/

#include "apue.h"
#include <sys/types.h>
#include <dirent.h>

int main(int argc , char* argv[]){
    DIR *dp;
    struct dirent *dirp;

    if(argc!=2){
        err_quit("usage: ls directory_name");
    }
    if((dp = opendir(argv[1])) == NULL){
        err_sys("fail open %s",argv[1]);
    }

    while ( (dirp = readdir(dp)) != NULL){
        printf("%s\n",dirp->d_name);
    }
    
    closedir(dp);
    return 0;
}
