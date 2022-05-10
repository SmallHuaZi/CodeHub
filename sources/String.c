#include "String.h"
#include <stdlib.h>
#include <malloc.h>

// KMP算法只针对于模式串，与主串无关
// next数组是相对于模式串中重复的子串而言的，
// 当出现主串和模式串的不匹配，只需要按照next数组，移动模式串的指针的位置就好了.
// 而next数组本质就是一个求当指针为i时的  i指向的字符之前的子串中的最长公共前后缀长度
// 所以不匹配时，就可以移动到最长公共后前后缀中前缀的后一位

// bababbc    main主串
// abababbc   pattern模式串
int *KMP(char *string, int lengh)
{
    int *next = (int *)malloc(sizeof(int) * lengh - 1);
    int main = 0, pattern = -1; // main指向主串，pattern指向模式串

    next[0] = -1; //这里的值设置最好设置成不能为索引的数

    while (main < lengh - 1) //主串已经遍历完了
    {
        if (-1 == pattern || string[main] == string[pattern])
        {
            //两种情况：1.相等时同步后移
            //        2.不等时：1.第一个字符就不匹配，这时候的应该移动main指针而不动pattern指针，
            //                   所以pattern指针初值设置为-1，而next[0]=-1;
            //                 2.后面的字符不匹配，这时候就利用之前已经存在的next数组帮助回溯，引文
            //                   main始终大于pattern，所以不用担心指针越界
            next[++main] = ++pattern;
        }
        else
        {
            //不匹配则让模式串回溯到最大相同前缀的最后一个字符
            pattern = next[pattern];
        }
    }
    return next;
}