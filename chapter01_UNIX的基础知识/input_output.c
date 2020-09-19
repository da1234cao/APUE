/**
 * 从标准输入读取，从标准输出输出。
 * 在shell中执行该程序，该程序是shell的子进程，
 * 也有标准输入，标准输出，标准错误输出的文件描述符。
 * 该进程和shell进程中，文件描述符表中，都有这三个文件描述符。
 * 
 * 如果这个程序在两个窗口运行，会互相干扰吗？
 * 先来预测一波，不会；因为在两个伪终端，pts0和pts1
 * 
 * 如果在窗口运行./input_output 或者 ./input_output &
 * 这关于多个进程，公用相同的文件描述符，如何处理？
 * 我还不知道，但操作来看，并没有干扰。。
*/

#include "apue.h"
#include <unistd.h>

#define MAX 4096

int main(void){
    int n;
    char buf[MAX];

    while( (n=read(STDIN_FILENO,buf,MAX-1)) > 0){
        if( write(STDOUT_FILENO,buf,n) !=n )
            err_sys("write error");
    }

    if(n<0)
        err_sys("read error");
    
    return 0;
}