/**
 * 在不同栈帧之间跳转：setjmp,longjmp
 * 说明在调用longjmp后， 自动变量、 全局变量、 寄存器变量、 静态变量和易失变量的不同情况
 * C语言volatile关键字—最易变的关键字:http://c.biancheng.net/cpp/html/447.html
 * C语言register关键字—最快的关键字:http://c.biancheng.net/cpp/html/435.html
 * 
 * 存放在存储器中的内容得到了恢复|在寄存器中的内容没有恢复|如果使用非局部跳转的程序，必须使用volatole属性
 * 
 * gcc -o longjmp longjmp.c
 * gcc -O3 -o longjmp longjmp.c
*/

#include <stdio.h>
#include <setjmp.h>

static void func(int autovar,int registervar,int staticvar, int volavar);

static jmp_buf jmpbuff;
static int globalvar=2;

int main(void){
    auto int autovar=1;
    register int registervar=3;
    static int staticvar=4;
    volatile int volavar=5;

    if( setjmp(jmpbuff)!=0 ){
        printf("after call longjmp:\n");
        printf("auto var:%d, global var:%d, register var :%d, static var:%d, volatile var:%d\n",
                autovar,globalvar,registervar,staticvar,volavar);
    }else{
        // 修改变量的值，在设置setjmp之后，longjmp之前
        autovar=11;globalvar=12;registervar=13;staticvar=14;volavar=15;
        func(autovar,registervar,staticvar,volavar);
    }
}

static void func(int autovar,int registervar,int staticvar, int volavar){
        printf("before call longjmp:\n");
        printf("auto var:%d, global var:%d, register var :%d, static var:%d, volatile var:%d\n",
                autovar,globalvar,registervar,staticvar,volavar);
    longjmp(jmpbuff,1);
}