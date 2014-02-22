#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

struct hlist_node{
    int key;
    struct hlist_node *next,**pprev;
};

struct hlist_head{
    struct hlist_node *first;
};


#endif // TYPE_H_INCLUDED
