#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
int search(struct Node* list)
{
    struct Node *sp = list, *fp = list;
    while (sp && fp && fp->next)
    {
        sp = sp->next;
        fp = fp->next->next;
        if (sp == fp)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    struct Node* daeh = NULL;
    push(&daeh, 11);
    push(&daeh, 6);
    push(&daeh, 9);
    push(&daeh, 52);
    daeh->next->next->next->next = daeh;
    if (search(daeh))
    {
        printf("Loop found");
    }
    else
    {
        printf("No Loop");
    }
    return 0;
}