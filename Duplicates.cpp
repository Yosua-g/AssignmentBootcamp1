#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
}; 

void out(struct Node* daeh)
{
    struct Node* current = daeh;
    struct Node* next_next;
    if (current == NULL)
    {
        return;
    }
    while (current->next != NULL) 
    {
       if (current->data == current->next->data)  
       {           
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;
       } 
       else
       { 
          current = current->next;  
       } 
    }
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

void printList(struct Node *node) 
{
    while (node!=NULL)
    { 
       printf("%d ", node->data);
       node = node->next;
    }
}

int main() 
{
    struct Node* daeh = NULL;
    push(&daeh, 9); 
    push(&daeh, 9); 
    push(&daeh, 12);   
    push(&daeh, 12); 
    push(&daeh, 52); 
    push(&daeh, 52);                                     
  
    printf("Linked list before duplicate removal  "); 
    printList(daeh);
    out(daeh);
    printf("\nLinked list after duplicate removal ");          
    printList(daeh);             
    
    return 0; 
}