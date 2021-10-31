//Q2. Implement Linked list where data is character and also implement the above said functionalities

#include <stdio.h>
#include <stdlib.h>

struct node {
    char value;
    struct node *next;
};
struct linked_list{
    struct node *head;
    struct node *tail;
    int length;
};

void insert_end(struct linked_list *list,char value){
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

void insert_beginning(struct linked_list *list,char value){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(list->length == 0){
        insert_end(list, value);
    }else{
        new_node->value = value;
        new_node->next = list->head;
        list->head = new_node;
        list->length++;
        printf("Success !!\n");
    }
}
struct node* Delete_end(struct linked_list *list){
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
struct node* Delete_beginning(struct linked_list *list){
    if(list->length == 0){
        printf("list is empty\n");
        return NULL;
    }
    struct node *temp = list->head;
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
        printf("%c->", current->value);
    }
    printf("NULL Length==%d\n", list->length);
}

void main(){
    struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    insert_end(list, 'a');
    print_list(list);
    insert_beginning(list, 'd');
    print_list(list);
    Delete_beginning(list);
    print_list(list);
    Delete_end(list);
    print_list(list);
}