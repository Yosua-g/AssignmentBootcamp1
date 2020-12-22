#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

void nth(struct Node* daeh, int n)
{
    int len = 0, i;
    struct Node* temp = daeh;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    if (len < n)
    {
    	return;
	}
    temp = daeh;
    for (i = 1; i < len - n + 1; i++)
    {
    	temp = temp->next;
	}
	printf("%d",temp->data);
    return;
} 
  
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node; 
} 

int main() 
{
    struct Node* daeh = NULL;
    push(&daeh,52); 
    push(&daeh,12);
    push(&daeh,9);
    push(&daeh,27);
    nth(daeh,4);
    return 0; 
}