//Q1. Implement Circular Linked list with functions insert_beginning, insert_end , Delete_beginning, Delete_end

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct circular_linked_list{
    struct node *head;
    struct node *tail;
    int length;
};

void insert_beginning(struct circular_linked_list* list, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    if(list->length == 0){
        list->head = new_node;
        list->tail = new_node;
        list->tail->next = list->head;
    }else{
        list->head = new_node;
        list->tail->next = new_node;
    }
    list->length++;
    printf("Success !!\n");
}
void insert_end(struct circular_linked_list* list, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    if(list->length == 0){
        list->head = new_node;
        list->tail = new_node;
        list->tail->next = list->head;
    }else{
        list->tail->next = new_node;
        list->tail = new_node;
        list->tail->next = list->head;
    }
    list->length++;
    printf("Success !!\n");
}
void Delete_beginning(struct circular_linked_list* list){
    if(list->head == NULL){
        printf("List is empty !!\n");
        return;
    }else if(list->length == 1){
        list->head = NULL;
        list->tail = NULL;
    }else{
        list->head = list->head->next;
        list->tail->next = list->head;
    }
    list->length--;
    printf("Success !!\n");
}
void Delete_end(struct circular_linked_list *list){
    if(list->head == NULL){
        printf("List is empty !!\n");
        return;
    }else if(list->length == 1){
        list->head = NULL;
        list->tail = NULL;
    }else{
        struct node *temp = list->head;
        while(temp->next != list->tail){
            temp = temp->next;
        }
        temp->next = list->head;
        list->tail = temp;
        list->tail->next = list->head;
    }
    list->length--;
    printf("Success !!\n");
}

void print_list(struct circular_linked_list* list){
    if(list->length == 0){
        printf("List is empty !!\n");
        return;
    }
    struct node *temp = list->head;
    while(temp != list->tail){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d->Head\n", temp->data);
}

void main(){
    struct circular_linked_list *list = (struct circular_linked_list *)malloc(sizeof(struct circular_linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    print_list(list);
    insert_beginning(list, 1);
    print_list(list);
    insert_end(list, 4);
    print_list(list);
    Delete_beginning(list);
    print_list(list);
    Delete_end(list);
    print_list(list);
} 