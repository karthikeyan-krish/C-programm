
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}node;


node* head;
void Insert(int data);
void Print();
void Delete(int n);

//void Insert(int data, int n);
//node* Insert(node *head, int X);
//void Print(node * head);
/* Code for forward inserting linkedList/*
/*
int main(){
    node *head = NULL;
    printf("How many elements you need?\n");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element:\n");
        scanf("%d",&x);
        head = Insert(head, x);
        Print(head);
    }
}

node* Insert(node* head, int x)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;
    if(head != NULL) temp->link = head;
    head = temp;
    return head;
}
void Print(node * head){
    
    printf("The list is:");
    while(head != NULL)
    {
    printf("%d\n",head->data);
    head = head->link;
    }
}
*/
int main(){
    head= NULL;
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    int n;
    printf("Enter a position to delete\n");
    scanf("%d",&n);
    Delete(n);
    Print();
}

/* insert function with n postion argument*/
/*
void Insert(int x, int n){
    int i;
    node* temp1= (node*)malloc(sizeof(node));
    node* temp2= head;

     temp1->data = x;
     temp1->link = NULL;
    if(n==1){
        temp1->link = head;
        head = temp1;
        return;
    }
    for(i=0;i<n-2;i++)
    {
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;
}
*/
void Insert(int x){
    int i;
    node* temp1= (node*)malloc(sizeof(node));
    node* temp2= head;

     temp1->data = x;
     temp1->link = NULL;
    // Checking if it is the first Node
    if(head == NULL){
        temp1->link = head;
        head = temp1;
        return;
    }
    //navigating to (N-1)th Node
    while(temp2->link != NULL)
    {
        temp2 = temp2->link;
    }
    //linking (N-1)th Node and Nth Node
    temp1->link = temp2->link;
    temp2->link = temp1;
}

void Print(){
    node* temp= head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void Delete(int n)
{
    node* temp1 = head;
    if(n == 1)
    {
        head = temp1->link; // head now points to the second node so we can delete first node
        free(temp1);
        return;
    }
    int i;
    for(i=0;i<n-2;i++)
    {
        temp1 = temp1->link;
    }
    //temp1 points to (n-1)th node
    node* temp2 = temp1->link; // nth Node to be deleted
    temp1->link = temp2->link; //linking (N-1)th Node and (n+1)th Node
    free(temp2); //  deleting Nth Node
}