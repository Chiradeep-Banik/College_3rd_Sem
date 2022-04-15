//Q3. Implement LinkedLIst with array

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;

struct linked_list{
    Node list[MAX];
};
typedef struct linked_list Linked_list;

void main(){
    Linked_list *ll = (Linked_list *)malloc(sizeof(Linked_list));
    ll->list[0].data = 1;
    ll->list[0].next = &ll->list[1];
    ll->list[1].data = 2;
    ll->list[1].next = NULL;
    int i =0;
    while(ll->list[i].data){
        printf("%d->",ll->list[i].data);
        i++;
    }
    printf("NULL\n");
}