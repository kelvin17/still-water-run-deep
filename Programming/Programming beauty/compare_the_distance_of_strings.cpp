#include <iostream>
#include <string.h>
//���֮����3.3�����ַ��������ƶȡ��ݹ�ķ�ʽ���ҵ�����
using namespace std;

int calculate(char * A,int pABegin,int pAend,char *B,int pBBegin,int pBend);
int main()
{
    char *A = "abdd";
    char *B = "aebd";
    cout << "The distance between of A and B is:" <<calculate(A,0,strlen(A)-1,B,0,strlen(B)-1) << endl;
    cout << "Hello world!" << endl;
    return 0;
}

int calculate(char * A,int pABegin,int pAend,char *B,int pBBegin,int pBend)
{
    if(pABegin > pAend)
    {
        if(pBBegin > pBend)return 0;
        else
            return pBend - pBBegin + 1;
    }

    if(pBBegin > pBend)
    {
        if(pABegin > pAend)return 0;
        else
            return pAend - pABegin + 1;
    }

    int t1=0,t2=0,t3=0;

    if(A[pABegin] == B[pBBegin])
    {
        return calculate(A,pABegin+1,pAend,B,pBBegin+1,pBend);
    }else
    {
        t1 = calculate(A,pABegin+1,pAend,B,pBBegin+1,pBend);
        t2 = calculate(A,pABegin,pAend,B,pBBegin+1,pBend);
        t3 = calculate(A,pABegin+1,pAend,B,pBBegin+1,pBend);
    }

    if(t1 > t2)
    {//����ֵ��1����Ϊ����Ĳ�������һ�Ρ���
        return t2 < t3 ? t2+1 : t3+1;
    }else return t1 < t3 ? t1+1 : t3+1;

}
