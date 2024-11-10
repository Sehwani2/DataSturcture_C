#include "DoublyLinkedList.h"


Node* DLL_CreateNode( ElementType NewData )
{
    Node* NewNode = (Node*)malloc(sizeof(NewNode));

    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;
}

void  DLL_DestroyNode( Node* Node)
{
    free(Node);
}

void  DLL_AppendNode( Node** Head, Node* NewNode )
{
    if((*Head) == NULL){
        *Head = NewNode;
    }
    else{
        Node* Tail = *Head;
        while(Tail->NextNode == NULL){
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
        NewNode->NextNode = Tail;
    }
}

void  DLL_InsertAfter( Node* Current, Node* NewNode )
{
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
        Current->PrevNode = NewNode;
    }
}
void  DLL_RemoveNode( Node** Head, Node* Remove )
{
    if((*Head) == Remove){
        *Head = Remove->NextNode;
        if(*Head != NULL){
            (*Head)->PrevNode = NULL;
        }
        Remove->PrevNode = NULL;
        Remove->NextNode = NULL;
    }
    else{
        Node* Temp = Remove;
        
        if(Remove->PrevNode != NULL){
            Remove->PrevNode->NextNode = Temp->NextNode;
        }
        if(Remove->NextNode != NULL){
            Remove->NextNode->PrevNode = Temp->PrevNode;
        }
        Remove->NextNode = NULL;
        Remove->PrevNode = NULL;
    }
    
}

Node* DLL_GetNodeAt( Node* Head, int Location )
{
    Node* Current = Head;

    while(Current != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }
    return Current;
}

int   DLL_GetNodeCount( Node* Head )
{
    int cnt =0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        cnt++;
    }
    return cnt;
}
