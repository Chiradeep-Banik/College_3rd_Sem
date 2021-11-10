//Q4 How to remove loop in linked list?

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct linked_list
{
    struct node *head;
    struct node *tail;
    int length;
};

void push(struct linked_list *list, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->length == 0)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->length++;
    printf("Success !!\n");
}

void print_list(struct node *first)
{
    struct node *current = first;
    for (; current != NULL; current = current->next)
    {
        printf("%d->", current->data);
    }
    printf("NULL\n");
}

void detect_and_delete_loop(struct linked_list *list)
{
    struct node *slow_ptr = list->head;
    struct node *fast_ptr = list->head;
    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
        {
            printf("Loop detected !!\n");
            break;
        }
    }
    struct node *ptr1 = list->head;
    struct node *ptr2 = slow_ptr;
    struct node *prev;
    while (ptr1 != ptr2)
    {
        prev = ptr2;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    prev->next = NULL;
    printf("Loop removed !!\n");
}
void main()
{
    struct linked_list list = {NULL, NULL, 0};
    push(&list, 1);
    push(&list, 2);
    push(&list, 3);
    push(&list, 4);
    push(&list, 5);
    push(&list, 6);
    list.tail->next = list.head;
    detect_and_delete_loop(&list);
    print_list(list.head);
}
