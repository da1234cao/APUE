#include "apue.h" //加上这个头文件，便于编译器检查apue.h中的原型和这里相匹配，

static void err_doit(int errorflag,int error, const char *fmt, va_list ap);

/**
 * 打印错误信息，并退出
*/
void err_quit(const char *fmt, ...){
    va_list ap;
    va_start(ap,fmt);
    err_doit(0,0,fmt,ap);
    va_end(ap);
    exit(1);
}


/**
 * 打印和系统调用的错误信息，不退出
*/
void err_ret(const char *fmt, ...){
	va_list		ap;

	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

/**
 * 打印和系统调用的错误信息，并退出
*/
void err_sys(const char *fmt, ...){
	va_list		ap;

	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

/**
 * static 函数，仅在该文件中可见
 * 打印错误信息
*/
static void err_doit(int errorflag,int error, const char *fmt, va_list ap){
    char buf[MAXLINE];

    vsnprintf(buf,MAXLINE-1,fmt,ap);
    if(errorflag){
        snprintf(buf+strlen(buf),MAXLINE-strlen(buf)-1,":%s",strerror(error));
    }
    strcat(buf,"\n");
    fflush(stdout);
    fputs(buf,stderr);
    fflush(NULL);
}