**参考资料**：

[Autotools Tutorial](https://www.lrde.epita.fr/~adl/autotools.html)

[Autoconf -- GUN](https://www.gnu.org/software/autoconf/)

[A Practioner's Guide to GNU Autoconf, Automake, and Libtool](https://www.amazon.com/Autotools-Practioners-Autoconf-Automake-Libtool/dp/1593272065)

[coreutils](https://www.gnu.org/software/coreutils/)

---

---


1. Autoconfig手册指出注释行可以以dnl或开头#。

   [Autoconf:dnl 和 #](https://qa.1r1g.com/sf/ask/235986761/#)

   dnl是一个m4宏,它丢弃在同一行(包括换行符)后跟随它的所有输入。#在m4中没有任何意义。
   在configure.ac中,在AC_INIT之后出现的带有"#"的行将出现在生成的配置脚本中.dnl评论不会

   ```shell
   dnl Written by Jim Meyering.
   ```

   

2. *AC_PREREQ* 宏声明本文要求的*autoconf*版本

   ```shell
   AC_PREREQ([2.69])
   ```

   

3. AC_INIT (package, version, [bug-report], [tarname], [url])

   初始化Autoconf，指定软件包的名称，版本号和错误报告地址。

   [autotools: propagating package version into subpackage](https://stackoverflow.com/questions/17008148/autotools-propagating-package-version-into-subpackage)

   ```shell
   AC_INIT([GNU coreutils],
           m4_esyscmd([build-aux/git-version-gen .tarball-version]),
           [bug-coreutils@gnu.org],
        [coreutils],
           [https://www.gnu.org/software/coreutils/])
   ```


   > The arguments of AC_INIT must be static, i.e., there should not be any shell computation, quotes, or newlines, but they can be computed by M4. This is because the
   > package information strings are expanded at M4 time into several contexts, and must
   > give the same text at shell time whether used in single-quoted strings, double-quoted
   > strings, quoted here-documents, or unquoted here-documents. It is permissible to use
   > m4_esyscmd or m4_esyscmd_s for computing a version string that changes with every
   > commit to a version control system (in fact, Autoconf does just that, for all builds of
   > the development tree made between releases).

   > m4_esyscmd_s (command) [Macro]
   > Like m4_esyscmd, this macro expands to the result of **running command in a shell.**
   > The difference is that any trailing newlines are removed, so that the output behaves
   > more like shell command substitution.
   >
   > m4_esyscmd or m4_esyscmd_s for computing a version string that changes with every
   > commit to a version control system (in fact, Autoconf does just that, for all builds of
   > the development tree made between releases).

   > The auxiliary directory is commonly named ‘build-aux’. 

   build-aux目录来存放辅助文件。

   大概意思：GNU coreutils的包，tarname指定完整的tar包名称。版本通过辅助文件git-version-gen生成放在tarball-version中。由于 AC_INIT的参数必须是静态的，不能使用shell计算，但是可以通过M4计算。bug-report是报告错误的邮箱，url是包的主页地址。




4. AC_CONFIG_SRCDIR

   通过检测目录中必定存在的文件来判断目录是否存在。

   ```shell
   AC_CONFIG_SRCDIR([src/ls.c])
   ```


   >AC_CONFIG_SRCDIR (unique-file-in-source-dir) [Macro]
   >unique-file-in-source-dir is some file that is in the package’s source directory;
   >configure checks for this file’s existence to make sure that the directory that it is
   >told contains the source code in fact does. Occasionally people accidentally specify
   >the wrong directory with ‘--srcdir’; this is a safety check. See Section 16.10
   >[configure Invocation], page 299, for more information.

   

5. AC_CONFIG_AUX_DIR

   指定辅助脚本文件的存放目录。

   ```shell
   AC_CONFIG_AUX_DIR([build-aux])
   ```

   

6. AC_CONFIG_HEADERS

   ```shell
   AC_CONFIG_HEADERS([lib/config.h:lib/config.hin])
   ```

   

**待，搞不定，autotools有点难。**

回头得相对系统的看下《A Practioner's Guide to GNU Autoconf, Automake, and Libtool》，直接刚实例刚不下来。

