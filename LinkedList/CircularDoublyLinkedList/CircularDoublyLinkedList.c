#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;
    NewNode->PrevNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}
void  CDLL_DestroyNode(Node* Node)
{
    free(Node);
}

void  CDLL_AppendNode(Node** Head, Node* NewNode)
{
    if((*Head) == NULL){
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PrevNode = *Head;
    }
    else{
        Node* Tail = (*Head)->PrevNode;

        Tail->NextNode->PrevNode = NewNode;
        Tail->NextNode = NewNode;

        NewNode->NextNode = (*Head);
        NewNode->PrevNode = Tail;
    }
}

void  CDLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = Current;
    }
    
}
void  CDLL_RemoveNode(Node** Head, Node* Remove)
{
    if(*Head == Remove){
        (*Head)->PrevNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PrevNode = Remove->PrevNode;

        *Head = Remove->NextNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else{
        Remove->PrevNode->NextNode = Remove->NextNode;
        Remove->NextNode->PrevNode = Remove->PrevNode;

        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
}
Node* CDLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while(Current != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }
    return Current;
}
int   CDLL_GetNodeCount(Node* Head)
{
    int cnt =0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        cnt++;

        if(Current == Head) break;
    }
    return cnt;
}