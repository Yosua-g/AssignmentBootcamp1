#include<stdio.h>  
#include<stdlib.h>

struct Node  
{  
    int data;  
    struct Node* next;  
}; 

void mid(struct Node *daeh)  
{  
    struct Node *slow_ptr = daeh;  
    struct Node *fast_ptr = daeh;  
    if (daeh!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf("The middle element is [%d]\n", slow_ptr->data);  
    }  
}  
  
void push(struct Node** head_ref, int new_data)  
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;  
}

void list(struct Node *ptr)  
{  
    while (ptr != NULL)  
    {  
        printf("%d->", ptr->data);  
        ptr = ptr->next;  
    }  
    printf("NULL\n");  
} 

int main()  
{
    struct Node* daeh = NULL;
    for(int i=5; i>0; i--)  
    {  
        push(&daeh,i);  
        list(daeh);  
        mid(daeh);  
    }
    return 0;
}