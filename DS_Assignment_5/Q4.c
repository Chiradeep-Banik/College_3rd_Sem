/**
 * Q4. Create a user friendly and menu driven singly linked list program to perform the following operations:
                Insert at rear position
                Insert at front position
                Insert at any position
                Display the elements
 * 
 * **/
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

void insert(struct linked_list *list,int value,int position){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if(position > list->length){
        printf("Invalid position !!\n");
    }else if(position == 0){
        shift(list, value);
    }else if(position == list->length){
        push(list, value);
    }else{
        new_node->value = value;
        struct node *temp = list->head;
        for (int i = 0; i < position-1; i++){
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        list->length++;
        printf("Success !!\n");
    }
}
void print_list(struct linked_list *list){
    struct node *current = list->head;
    for(;current != NULL; current = current->next){
        printf("%d->", current->value);
    }
    printf("NULL\n");
}

void main(){
    struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    int choice;
    int value;
    int position;
    while(1){
        printf("1.Insert at rear position\n");
        printf("2.Insert at front position\n");
        printf("3.Insert at any position\n");
        printf("4.Display the elements\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted : ");
                scanf("%d", &value);
                printf("\n");
                push(list, value);
                printf("\n");
                break;
            case 2:
                printf("Enter the value to be inserted : ");
                scanf("%d", &value);
                printf("\n");
                shift(list, value);
                printf("\n");
                break;
            case 3:
                printf("Enter the value to be inserted : ");
                scanf("%d", &value);
                printf("Enter the position : ");
                scanf("%d", &position);
                printf("\n");
                insert(list, value, position);
                printf("\n");
                break;
            case 4:
                printf("\n");
                print_list(list);
                printf("\n");
                break;
            case 5:
                printf("\nExiting ...\n");
                free(list);
                exit(0);
            default:
                printf("\nInvalid choice !!\n");
                break;
        }
    }
}