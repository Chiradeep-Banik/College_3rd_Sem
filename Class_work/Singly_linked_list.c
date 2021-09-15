#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
struct linked_list{
    struct node *head;
    struct node *tail;
    int length;
};

void push(struct linked_list *list,int value){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = value;
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

void shift(struct linked_list *list,int value){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(list->length == 0){
        push(list, value);
    }else{
        new_node->value = value;
        new_node->next = list->head;
        list->head = new_node;
        list->length++;
        printf("Success !!\n");
    }
}
struct node* pop(struct linked_list *list){
    if(list->length == 0){
        printf("list is empty\n");
        return NULL;
    }
    struct node *old_tail = list->tail;
    if(list->length == 1){
        list->head = NULL;
        list->tail = NULL;
    }else{
        struct node *temp = list->head;
        while(temp->next != list->tail){
            temp = temp->next;
        }
        temp->next = NULL;
        list->tail = temp;
    }
    list->length--;
    return old_tail;
}
struct node* unshift(struct linked_list *list){
    if(list->length == 0){
        printf("list is empty\n");
        return NULL;
    }
    struct node *temp = (list->head);
    if(list->length == 1){
        list->head = NULL;
        list->tail = NULL;
    }else{
        list->head = list->head->next;
    }
    list->length--;
    return temp;
}

void print_list(struct linked_list *list){
    struct node *current = list->head;
    for(;current != NULL; current = current->next){
        printf("%d->", current->value);
    }
    printf("NULL Length==%d\n", list->length);
}

void main(){
    struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));

    push(list, 1);
    push(list, 2);
    push(list, 3);
    struct node *a = unshift(list);
    struct node *b = pop(list);
    pop(list);
    unshift (list);
    shift(list, 4);
    printf("%d\n", a->value);
    printf("%d\n", b->value);
    print_list(list);
}