
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
}node;



node* Insert(node *head, int X);
void Print(node * head);

int main(){
    struct Node *head = NULL;
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

struct Node* Insert(struct Node* head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(node));
    temp->data = x;
    temp->link = NULL;
    if(head != NULL) temp->link = head;
    head = temp;
    return head;
}
void Print(struct Node * head){
    
    printf("The list is:");
    while(head != NULL)
    {
    printf("%d\n",head->data);
    head = head->link;
    }
}