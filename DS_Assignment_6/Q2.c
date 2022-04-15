//Q2 Insert an element before a particular element in linked list.

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

void insert_before_particular(struct linked_list *list,int data,int val){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    struct node *temp = list->head;
    if(list->head->data == val){
        new_node->next = list->head;
        list->head = new_node;
        list->length++;
        printf("Success !!\n");
        return;
    }
    while(temp->next != NULL && temp->next->data != val){
        temp = temp->next;
    }
    if(temp->next == NULL){
        printf("The element is not present in the list\n");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
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

void main(){
    struct linked_list list = {NULL,NULL,0};
    push(&list,1);
    push(&list,2);
    push(&list,3);
    push(&list,4);
    insert_before_particular(&list,5,2);
    insert_before_particular(&list,5,7);
    insert_before_particular(&list,5,1);
    print_list(list.head);
}