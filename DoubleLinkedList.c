#include "DoubleLinkedList.h"

void Add_To_Head(int data)
{
    Node *Current = (Node*)malloc(sizeof(Node));
    Current->data = data;

    //Check if list is empty
    if(Head == NULL)
    {
        Head = Current;
        Head->next = NULL;
        Head->Previous = NULL;

        Tail = Current;
        Tail->next = NULL;
        Tail->Previous = NULL;
    }
    else
    {
        Head->Previous = Current;
        Current->next = Head;
        Head = Current;
        Head->Previous = NULL;
    }
}

void Add_To_Tail(int data)
{
    Node *Current = (Node*)malloc(sizeof(Node));
    Current->data = data;

    //Check if list is empty
    if(Head == NULL)
    {
        Head = Current;
        Head->next = NULL;
        Head->Previous = NULL;

        Tail = Current;
        Tail->next = NULL;
        Tail->Previous = NULL;
    }
    else
    {
        Tail->next = Current;
        Current->Previous = Tail;
        Tail = Current;
        Tail->next = NULL;
    }
}

void Remove_From_Head(void)
{
    if(Head->next == NULL)
    {
        free(Head);
    }
    else
    {
        Node *myHead = Head;
        Head = Head->next;
        free(myHead);
        Head->Previous = NULL;
    }
}

void Remove_From_Tail(void)
{
    if(Head == Tail)
    {
        free(Tail);
    }
    else
    {
        Node *myTail = Tail;
        Tail = Tail->Previous;
        free(myTail);
        Tail->next = NULL;
    }
}

void Remove_From_Middle(int data)
{
    Node *temp = Head;
    while(temp != NULL)
    {
        if(temp->data == data)
        {
            temp->Previous->next = temp->next;
            temp->next->Previous = temp->Previous;
            free(temp);
            break;
        }
        temp = temp->next;
    }
}

void Print_DoubleLinkedList(void)
{
    Node *temp;
    temp = Head;
    int i = 1;
    while(temp != NULL)
    {
        printf("Node%d: %d\n",i,temp->data);
        temp = temp->next;
        i++;
    }
}

int main()
{
    Add_To_Head(1);
    Add_To_Tail(2);
    Add_To_Head(0);
    Remove_From_Middle(1);
    Remove_From_Tail();
    Print_DoubleLinkedList();
    return 0;
}