# 第二天计算器作业

## 	1、需求分析

​			此计算要求先登录，如果账号或密码错误则要求重新登录

​			![image-20230912205647801](C:\Users\33187\AppData\Roaming\Typora\typora-user-images\image-20230912205647801.png)

​			登录成功后进入计算机系统中：

​			![image-20230912205730627](C:\Users\33187\AppData\Roaming\Typora\typora-user-images\image-20230912205730627.png)

​			然后输入所需计算的公式，输入完成后即可计算，当计算完成后询问是否再次计算，输入提示符即可			

​			![image-20230912210006749](C:\Users\33187\AppData\Roaming\Typora\typora-user-images\image-20230912210006749.png)

​			最后输入n退出程序

​			![image-20230912210041224](C:\Users\33187\AppData\Roaming\Typora\typora-user-images\image-20230912210041224.png)

	## 2、逻辑分析

​	在第一次登录时用while语句控制用户是否重新输入

​	考虑是否重新计算时，在大循环中嵌套小循环，在小循环中如果输入的是y则跳出小循环，不跳出大循环，如果输入的是n

​	则大小循环都跳出，结束程序执行

​	第一次写Mrakdown，写的不好



