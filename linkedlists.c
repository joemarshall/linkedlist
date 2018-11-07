#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data; /* the data point*/
	struct Node *next; /* pointer to the next node */
};

/* Make an unconnected list node with a given data value */
struct Node* makeNode(int data){
    /* allocate node structure*/
    struct Node*theNode=(struct Node*)malloc(sizeof(struct Node));
    theNode->data=data; /* set the data value */
    theNode->next=NULL; /* node isn't linked to anything yet */
    return theNode;
}

/* insert a node after this node */
struct Node* insertNodeAfter(int data,struct Node* prev){
    struct Node*theNode=makeNode(data);
    theNode->next=prev->next;/* link to next node */ 
    prev->next=theNode; /*link previous node to new node*/
    return theNode; /* return new node */
}

/* Delete the node after this one. You need to know the
   previous node to delete a node, so you can make the pointers 
   go around the deleted node */
struct Node* deleteNodeAfter(struct Node* prev){
    struct Node *del;
    del=prev->next;
    prev->next=del->next;
    free(del);
    return prev;
}

/* print out a list - this is an example of how to iterate over a list and do something */
void printList(struct Node * head)
{
    struct Node *cursor = head; /* cursor points to the current node */
    while(cursor!=NULL) {
        printf("%d ",cursor->data); /* do something */
        cursor=cursor->next; /* move the cursor to the next node*/
    }
    printf("\n") ;   
}

/* Free all items in the list - another example of how to iterate over a list */
void freeList(struct Node* head)
{
    struct Node *cursor = head;
    struct Node*next=NULL;
    while(cursor!=NULL) {
        /* copy the next pointer here, because we are about 
           to free the current node */        
        next=cursor->next;
        free(cursor);
        cursor=next;
    }    
}

int main()
{
    struct Node *head,*tail;

    /* make a head node */
    head = makeNode(3);
    /* initially the tail and head are the same */
    tail = head; 

    printf("Initial node:        ");
    printList(head);
    
    /* add node to end and move the tail pointer */
    tail=insertNodeAfter(4,tail);

    printf("Inserted at end:     ");
    printList(head);

    /* add a node after the head */
    insertNodeAfter(1,head);

    printf("Inserted after head: ");
    printList(head);

    /* delete the first node after the head */
    deleteNodeAfter(head);    
    
    printf("Deleted after head:  ");
    printList(head);
    
    /* this function traverses the list to free each node */
    freeList(head);
    
    return 0;
}
