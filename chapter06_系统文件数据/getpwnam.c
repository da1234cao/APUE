/**
 * 自行实现getpsnam函数
 * 函数说明：getpwnam()用来逐一搜索参数name 指定的账号名称,
 *  找到时便将该用户的数据以passwd 结构返回。passwd 结构请参考getpwent()。
*/

#include "apue.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd* getpwnam(const char * name){
    static struct passwd* ptr;

    setpwent();
    //  这似乎是一种很常见的查找函数的写法。
    // 不断指向下一个。
    while((ptr=getpwent()) != NULL)
        if( strcmp(ptr->pw_name,name)==0 )
            break;
    endpwent();
    return ptr;
}


int main(void){
    char *name = "dacao";
    struct passwd* ptr = getpwnam(name);

    if(ptr != NULL){
        printf("uid:%ud\n",ptr->pw_uid);
        printf("name:%s\n",ptr->pw_name);
        printf("shell:%s\n",ptr->pw_shell);
    }else{
        printf("No user:%s",name);
    }

    return 0;
}
