//strstr���ܵ�ʵ�֣������档ʵ�ִ�ѭ����λ�Ĳ���
//string����ֻ��C++�в���
/*���õ�string������
char *strtok(char *s1,const char *s2)
��һ�ε��õ�ʱ��Ҫ��s1һ����ʼֵ��������s1����ʼλ�ÿ�ʼѰ�ҡ�
�Ժ�ÿ�ε��õ�ʱ��s1����һ��NULL�ˣ����ϴηָ���λ�ÿ�ʼ�������С�
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
