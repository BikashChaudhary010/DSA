#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
 
void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}
 
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
 
int main(){
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    head->prev=NULL;
    head->data = 4;
    head->next = second;
 
    second->prev=head;
    second->data = 3;
    second->next = third;
 
    third->prev=second;
    third->data = 6;
    third->next = fourth;
 
    fourth->prev=third;
    fourth->data = 1;
    fourth->next = head;
   printf("Circular Linked list before insertion\n");
   linkedListTraversal(head);
   head = insertAtFirst(head, 54);
   head = insertAtFirst(head, 58);
   head = insertAtFirst(head, 59);
   printf("Circular Linked list after insertion\n");
   linkedListTraversal(head);
    return 0;
}
