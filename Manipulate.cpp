void pushHead(const char *name, int score)
{
    Node *temp = createNode(name, score);
    if(head == NULL)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}