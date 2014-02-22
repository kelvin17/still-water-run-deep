#include <stdio.h>
#include <stdlib.h>
#include "type.h"

#define N 13

//ʹ������ַ�������ͻ����ϣ������H(key) = key mod 13 �Ĺ�ϣ��
//��ϣ�������Linux�� ��ϣ��ͷ�ڵ�ͽڵ㡣
//ÿ����ͻ�ڵ㣬���սڵ㵽��˳������

void INIT_HNODE(struct hlist_node *node,int key)
{
    node->key = key;
    node->next = NULL;
    node->pprev = NULL;
}

int main()
{
    struct hlist_head Hash_my[N];

    int array[12] = {19,14,23,01,68,20,84,27,55,11,10,79};
    //Init the Hash list
    int i = 0;
    int num = 12;
    int key;
    int pos;
    for(;i<N;i++)
    {
        Hash_my[i].first = NULL;
    }

    i = 0;

    struct hlist_node *n;
    INIT_HNODE(n,0);

    while(i<num)
    {
        i++;
        key = array[i-1];
        pos = key % 13;

        struct hlist_node *node = (struct hlist_node *)malloc(sizeof(struct hlist_node));
        INIT_HNODE(node,key);

        //��ͻ̽��
        if(Hash_my[pos].first == NULL)
        {
            Hash_my[pos].first = node;
            node->pprev = &(Hash_my[pos].first);
        }else//conflicts
        {
            n = Hash_my[pos].first;
            for(;n->next;n = n->next);

            n->next = node;
            node->pprev = &(n->next);
        }
    }

    for(i=0;i<N;i++)
    {
        if(Hash_my[i].first!=NULL)
        {
            printf("key = %d\n",i);
            n = Hash_my[i].first;
            for(;n;n=n->next)
            {
                printf("The origial key is %d\n",n->key);
            }
            printf("\n");
        }

    }

    printf("Hello world!\n");
    return 0;
}
