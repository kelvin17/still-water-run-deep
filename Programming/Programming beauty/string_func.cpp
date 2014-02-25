//strstr功能的实现，升级版。实现带循环移位的查找
//string类型只有C++中才有
/*常用的string函数：
char *strtok(char *s1,const char *s2)
第一次调用的时候，要给s1一个初始值，这样从s1的起始位置开始寻找。
以后每次调用的时候，s1就是一个NULL了，从上次分割后的位置开始继续进行。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const char *my_strstr(const char *source,const char *dest)
{
    const char *p1 = source;
    const char *p2 = dest;
    const char *p11 = NULL,*p22=NULL;
    for(;(*p1)!='\0';p1++)
    {
        p11 = p1;
        p22 = p2;
        for(;*p22!='\0';)
        {
            if(*p11 != '\0')
            {
                if(*p11 == *p22)
                {
                    p11++;
                    printf("string:%c\n",*p22);
                    p22++;
                }else
                {
                    break;
                }
            }else
            {
                p11 = source;
            }
        }
        if(*p22 == '\0')
        {
            break;
        }
    }

    if(*p22 == '\0')
    {
        printf("True\n");
        return p1;
    }else printf("False\n");

    return NULL;
}

int main()
{
 /*   char s1[] = "AABCD";
    char s2[] = "ABCD";
    if(my_strstr(s1,s2)!=NULL)
    {
        printf("Find\n");
    }*/
    char str[] = "- This,a sample string.";
    char *pch;
    pch = strtok(str,", . -");
    while(pch!=NULL)
    {
        printf("%s\n",pch);
        pch = strtok(NULL,", . -");
    }
    return 0;
}
