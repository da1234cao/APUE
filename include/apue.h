/**
 * 自定义的头部，包含需要的函数调用
 * dacao : 2020//8/27始 -- 
*/

#ifndef _APUE_H
#define _APUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

#define	MAXLINE	4096			/* max line length */

/**
 * 作用：打印错误信息，并退出；
 * __attribute__((noreturn)): 
 * 的作用告诉编译器这个函数不会返回给调用者，
 * 以便编译器在优化时去掉不必要的函数返回代码
*/
void err_quit(const char *fmt, ...) __attribute__((noreturn)) ;


// 打印和系统调用的错误信息 
void err_ret(const char *fmt, ...);

/**
 * 打印和系统调用的错误信息，并退出
*/
void err_sys(const char *fmt, ...);

#endif