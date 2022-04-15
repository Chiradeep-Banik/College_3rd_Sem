//Q5 Delete N nodes after M nodes of a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct linked_list{
    struct node *head;
    struct node *tail;
    int length;
};

void push(struct linked_list *list,int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if(list->length == 0){
        list->head = new_node;
        list->tail = new_node;
    }else{
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->length++;
    printf("Success !!\n");
}

void print_list(struct node *first){
    struct node *current = first;
    for(;current != NULL; current = current->next){
        printf("%d->", current->data);
    }
    printf("NULL\n");
}

void delete_n_after_m(struct linked_list *list,int n,int m){
    struct node *current = list->head;
    struct node *prev = NULL;
    int count = 0;
    while (count < m && m != 0){
        prev = current;
        current = current->next;
        count++;
    }
    while (count < m + n){
        current = current->next;
        count++;
    }
    prev->next = current;
    list->length -= n;
    printf("Success !!\n");
}

void main(){
    struct linked_list list = {NULL,NULL,0};
    push(&list,1);
    push(&list,2);
    push(&list,3);
    push(&list,4);
    push(&list,5);
    delete_n_after_m(&list,2,1);
    print_list(list.head);
}