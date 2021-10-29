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

int find(struct linked_list *list,int value){
    if(list->length == 0){
        printf("list is empty\n");
        return -1;
    }else{
        struct node* temp = list->head;
        while(temp != NULL){
            if(temp->value == value){
                printf("Found!!\n");
                return 1;
            }
            temp = temp->next;
        }
    }
    return -1;
}

struct linked_list* concat (struct linked_list *list1,struct linked_list *list2){
    int total_length = list1->length + list2->length;
    struct linked_list *new_list = (struct linked_list *)malloc(sizeof(struct linked_list));
    new_list->length = total_length;
    if(list1->length == 0){
        new_list->head = list2->head;
        new_list->tail = list2->tail;
    }else if(list2->length == 0){
        new_list->head = list1->head;
        new_list->tail = list1->tail;
    }else if(list1->length == 0 && list2->length == 0){
        new_list->head = NULL;
        new_list->tail = NULL;
    }else{
        new_list->head = list1->head;
        list1->tail->next = list2->head;
        new_list->tail = list2->tail;
    }
    return new_list;
}

struct linked_list* create_list(){
    struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void print_list(struct linked_list *list){
    struct node *current = list->head;
    for(;current != NULL; current = current->next){
        printf("%d->", current->value);
    }
    printf("NULL Length==%d\n", list->length);
}

void main(){
    struct linked_list *list = create_list();
    struct linked_list *list2 = create_list();
    push(list, 1);
    push(list, 2);
    push(list, 3);
    pop(list);
    unshift (list);
    shift(list, 4);
    push(list, 5);
    push(list, 6);
    push(list2, 7);
    push(list2, 8);
    print_list(list);
    print_list(list2);
    print_list(concat(list, list2));
}