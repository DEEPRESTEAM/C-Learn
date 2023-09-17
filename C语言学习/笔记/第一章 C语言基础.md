# 第一章C语言基础

## ⼀、C语⾔程序的基本结构

### 1.1 基本结构

>C语⾔程序的基本结构包括以下⼏个部分： 
>
>1.预处理指令：这些编译器指令，通常放在程序的开头，#include  。预处理器指令以# 字符开始，最常⻅的#include,⽤于包含其他的头⽂件。
>
>2.函数：C程序中⾄少包含⼀个函数，即 main()函数。main()函数是程序执⾏的起点。此外，⼀个C程序中可以包含其他的函数，这些函数 可以⾃⼰定义也可以是从库中调⽤。 
>
>3.变量：变量⽤于存储数据。在C语⾔中，每个变量都有特有类型。
>
>4.语句&表达式：语句是执⾏特定任务的语句，如赋值语句、调⽤函数等，表达式则是计算产⽣值 的计算公式。 
>
>5.注释：注释⽤于解释程序的功能，对代码进⾏解释和描述。在C语⾔中，注释可以⽤/* 注释内 容 */或者//注释内容来书写。

![](https://typora0-0-1.oss-cn-shenzhen.aliyuncs.com/C/%E5%9B%BE%E7%89%87/C%E7%A8%8B%E5%BA%8F%E7%BB%93%E6%9E%84%E5%9B%BE.png)

```c
1、预处理
#include
2、main
主函数 不管在外⾯写了多少个函数 只能运⾏main
要运⾏外部函数，则需要通过main直接或间接的调⽤
3、语句
需要执⾏的程序
```

实例程序

```c
#include <stdio.h> //预处理指令
/* 这是⼀个简单的C程序 */
int main() //函数开始
{
    int a = 10; //定义变量和赋值语句
    printf("Hello World"); //语句：调⽤printf函数
    return 0; //语句：返回，结束main函数
} //函数结束
```

>在这个程序中： #include 是预处理指令，⽤于包含stdio.h头⽂件。 
>
>main()是函数，程序的⼊⼝。 
>
>int a = 10为变量赋值语句。 
>
>printf是⼀个函数调⽤该语句，⽤于输出字符以及字符串和变量a的值。

### 1.2 gcc编译流程

>gcc的编译流程分为4个步骤： 
>
>①预处理 -E .i 展开头⽂件 替换宏定义 删除注释 
>
>②编译 -S .s 纠错 
>
>③汇编 -c .o 
>
>④链接 a.out 
>
>⽀持以下后缀： 
>
>​	.c C语⾔源代码 
>
>​	.h 程序中所包含的头⽂件 
>
>​	.i 已经预处理过的C源代码⽂件 
>
>​	.s 汇编语⾔源代码⽂件 
>
>​	.o 汇编后的⽬标⽂件

![](https://typora0-0-1.oss-cn-shenzhen.aliyuncs.com/C/%E5%9B%BE%E7%89%87/%E7%BC%96%E8%AF%91%E6%B5%81%E7%A8%8B%E5%9B%BE.png)

接下通过⼀个实例程序来对gcc进⾏讲解，实例程序如下，分为两个⽂件⼀个hello.c和hello.h：

```c
//hello.c//
#include <stdio.h>
#include "hello.h"
int main()
{
    u8 i;
    printf("%ld\n",sizeof(i));
    return 0;
}
```

```c
#ifndef __HELLO_H_
#define __HELLO_H_
typedef unsigned int u8;
#endif
```

>预处理阶段： gcc的选项"-E"可以使⽤编译器在预处理结束时就停⽌编译，选项-o是指定gcc输出结果， gcc -E -o [⽬标⽂件] [编译⽂件] gcc -E -o hello.i hello.c 
>
>编译阶段： 编译器在预处理结束后开始使⽤，gcc⾸先要检查代码的规范性、是否还有语法错误等，在检查⽆ 误后，就开始把代码翻译成汇编语⾔。 gcc -S -o [⽬标⽂件] [编译⽂件] gcc -S -o hello.s hello.i 
>
>汇编阶段: 汇编的过程就是将.s⽂件⽣成⽣产⽬标⽂件，我们在使⽤-c就可以看到汇编的代码转换成为.o的⼆ 进制⽬标代码了。 gcc -c -o [⽬标⽂件] [编译⽂件]gcc -c -o hello.o hello.s 链接阶段： //hello.c// #include  #include "hello.h" int main() { u8 i; printf("%ld\n",sizeof(i)); return 0; } 1 2 3 4 5 6 7 8 9 Plain Text #ifndef __HELLO_H_ #define __HELLO_H_ typedef unsigned int u8; #endif 1 2 3 4 5 6 7 Plain Text 8 
>
>成功编译后，就进⼊到了链接阶段，在这⾥涉及到⼀个很重要的概念：函数库。 

## 二、C语言关键字和标识符

### 2.1 关键字

>关键字：关键字是C语⾔中预先定义并保留的特殊单词，每个关键字在C语⾔中都有特定的含义 和⽤途。我们在编写C程序时不能将关键字作为变量名或者其他标识名。以下是C语⾔的关键字：

```c
auto double int struct
 break else long switch
 case enum register typedef
 char extern return union
 const float short unsigned
continue for signed void
default goto sizeof volatile
 do if static while
```

### 2.2 标识符

> 标识符：是程序编写过程中的变量名、函数名、数组名等元素定义的名称。标识符的命名需要遵循 以下规则： 
>
> 1.标识符的第⼀个字符必须是字⺟（⼤写或⼩写）或者下划线"_"。 
>
> 2.后续的字符可以是字⺟、数字或下划线。 
>
> 3.关键字不能作为标识符。 
>
> 4.标识符在C语⾔中是区分⼤⼩写的。

```c
//正确
int myVar;
double _myVar;
unsigned long int var123;
void myFunction();
//错误
int 123var; // 以数字开头
double double; // 使⽤了关键字
```

```c
int score; // 正确
double _maxValue; // 正确
char response1; // 正确
int 7score; // 错误，名称不能以数字开头
void print_score(); // 正确
double double; // 错误，不能使⽤关键字作为名称
char a b; // 错误，名称中不能有空格
int number of students; // 错误，名称中不能有空格
void PrintScore(); // 正确，但不符合C语⾔的常⻅命名习惯，函数名通常全部⼩写，
如print_score
int NumberOfStudents; // 正确，但不符合C语⾔的常⻅命名习惯，更常⻅的是使⽤下划线，如number_of_students
```

## 三、C语⾔的数据类型和变量的以及存储类型

### 3.1 计算机的数据表示

#### 3.1.1进制

计算机中数据通常以⼆进制形式表示，但根据需要，它们可以进⼀步划分为不同的类型。以下是常 ⻅的计算机中数据表示的⽅式：

##### 3.1.1.1 数据进制

1. ⼆进制：这是计算机最基础的数据表示⽅式，所有的信息都可以转换为0和1。这是因为计算机 的硬件电路（例如，开关和逻辑⻔）最适合处理⼆进制系统。 
2. ⼗进制：尽管计算机内部使⽤⼆进制，但在显示和输⼊数据时，通常使⽤我们更熟悉的⼗进制 系统。计算机内部会将⼗进制数字转换为⼆进制，进⾏计算后再转回⼗进制。 
3. ⼗六进制：⼗六进制被⼴泛⽤于计算机科学和编程，因为它可以更简洁地表示⼆进制数。每个 ⼗六进制数字可以精确地表示四个⼆进制位，这使得⼆进制数和⼗六进制数之间的转换⾮常直接。

##### 3.1.1.2 ⾮数值数据

1. ASCII：ASCII是⼀种将字符（如字⺟、数字和特殊符号）映射到⼆进制数的标准。例如，在 ASCII中，⼤写字⺟A的编码是65，对应的⼆进制是1000001。

![](https://typora0-0-1.oss-cn-shenzhen.aliyuncs.com/C/%E5%9B%BE%E7%89%87/ASCII%E7%A0%81%E8%A1%A8%E5%9B%BE.png)

2. 浮点数：计算机使⽤浮点数表示法来存储和操作实数。IEEE 754标准定义了浮点数的表示⽅ 式和操作，这是现代计算机最⼴泛使⽤的浮点数标准。

   

#### 3.1.2 源码反码补码

>原码、反码和补码是⽤于表示和存储⼆进制有符号整数的⽅式。它们都⽤最⾼位（通常是左边的 位）表示符号，0表示正，1表示负。 
>
>原码：原码就是符号位加上真值的绝对值，即⽤第⼀位表示符号，其余位表示值。⽐如如果是8位 ⼆进制： 
>
>- [+1]原 = 0000 0001 
>- [-1]原 = 1000 0001 
>
>有符号数的第⼀位为符号位 反码：正数的反码是其本身，负数的反码是在其原码的基础上, 符号位不变，其余各位取反。 
>
>- [+1]反 = 0000 0001 
>- [-1]反 = 1111 1110 
>
>补码：正数的补码就是其本身，负数的补码是在其原码的基础上，符号位不变，其余各个位取反， 然后最后⼀位加1。 
>
>- [+1]补 = 0000 0001 
>- [-1]补 = 1111 1111 
>
>原码 本身 
>
>反码 原码取反 
>
>补码 反码 + 1

![](https://typora0-0-1.oss-cn-shenzhen.aliyuncs.com/C/%E5%9B%BE%E7%89%87/%E5%8E%9F%E7%A0%81%E5%8F%8D%E7%A0%81%E8%A1%A5%E7%A0%81%E8%BD%AC%E6%8D%A2%E5%9B%BE.png))

### 3.2 数据类型

>数据类型的作⽤
>
>在计算机最开始的时候，没有这么⼤的存储空间，需要⼀个东⻄规范存储空间的⼤⼩

![](https://typora0-0-1.oss-cn-shenzhen.aliyuncs.com/C/%E5%9B%BE%E7%89%87/%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B%E5%9B%BE.png)

>在C语⾔中，数据类型指的是⽤于声明不同类型的变量或函数的⼀个⼴泛的系统。变量的类型决定 了变量存储的⼤⼩和布局，该范围内的值都可以存储在内存中，以及该位置可以参与的运算。 

C语⾔中的数据类型主要可以分为以下⼏类：

#### 3.2.1 基本类型：它们是算术类型，包括两种类型：整数类型和浮点类型。

- 整数类型包括：char、short int、int、long int、long long int。 
- 浮点类型包括：float、double、long double。

```c
#include <stdio.h>
//● 整数类型包括：char、short int、int、long int、long long int。
//● 浮点类型包括：float、double、long double。
//● ascll
int main(int argc, char const *argv[])
{
    //int 整型
    int num = 0;
    printf("%ld\n",sizeof(num));
    //char 字符型
    char ch = 'A';
    printf("%d\n",ch);
    printf("%ld\n",sizeof(ch));
    //short int 短整型
    short int sh_in = 0;
    printf("%ld\n" , sizeof(sh_in));
    //long int ⻓整型
    //long long int ⻓⻓整型
    long long lo_in = 0;
    printf("%ld\n" , sizeof(lo_in));
    //⽆符号 整型
    unsigned int un_in = 0;
    printf("%ld\n" , sizeof(un_in));
    return 0;
}
```

浮点型：

```c
#include <stdio.h>
//● 浮点类型包括：float、double、long double。
int main(int argc, char const *argv[])
{
    //单精度浮点型 4
    float fl = 3.14;
    printf("%ld\n" , sizeof(fl));
    //双精度浮点型 8
    double dou = 3.14;
    printf("%ld\n" , sizeof(dou));
    //⻓双精度浮点型 16
    long double dou_1 = 3.14;
    printf("%ld\n" , sizeof(dou_1));
    return 0;
}
```

