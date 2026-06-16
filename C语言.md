1. strcpy(char* s1, char* s2)和直接s1 =  s2赋值的区别是：strcpy 是复制字符串内容，而 = 对指针来说是复制地址
```c
char buf[20] = "abc";
char *s1 = buf;
char *s2 = "hello";

strcpy(s1, s2); //s1和buf都变成"hello"


char buf[20] = "abc";
char *s1 = buf;
char *s2 = "hello";

s1 = s2;  //buf仍然是"abc"，而s1和s2都指向了"hello"
```
2.数组名不是普通指针变量，代表数组首地址，无法被重新赋值，只能strcpy
```c
char s1[20] = "hello";
s1 = "world";   // 错
```