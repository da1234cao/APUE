《UNIX高级环境编程》读书笔记

## 编译过程

我修改使用了“参考代码”中的makefile；

主要区别是，“参考代码”使用文件传递makefile中的变量；

我使用export传递变量，这使得我每次编译任何一个文件，都只能从根makefile出发；

所以，我认为“参考代码”中的makefile更好些，但是我也懒得改，区别不大。

## 文件目录

1. 参考代码：官网下载的书中的代码
2. lib：自定义的静态库
3. include: 自定义的头文件，头文件内容的实现在lib中。
