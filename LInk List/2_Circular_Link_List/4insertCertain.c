#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} block;
block *head = NULL;
int node = 0;
void create()
{
    int i, n;
    printf("Enter node number: ");
    scanf("%d", &n);
    block *temp, *tail;
    printf("Enter data: ");
    for (i = 0; i < n; i++)
    {
        temp = malloc(sizeof(block));
        scanf("%d", &temp->data);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            node++;
        }
        else
        {
            tail->link = temp;
            tail = temp;
            node++;
        }
        tail->link = NULL;
    }
    tail->link = head;
}
void display()
{
    block *temp = head;
    printf("Display data: ");
    
    for(int i=0; i<((2*node)); i++)
    {
        printf("%d-->", temp->data);
        temp=temp->link;
    }
    printf("head\n");
}
void mb_i()
{
    int pos;
    printf("Enter position to insert(Middle Before): ");
    scanf("%d", &pos);
    block *temp=head, *newNode;
    newNode=malloc(sizeof(block));
    printf("Enter data for newNode:");
    scanf("%d", &newNode->data);
    newNode->link=NULL;
    pos--;
    while(pos!=1)
    {
        temp=temp->link;
        pos--;
    }
    newNode->link=temp->link;
    temp->link=newNode;
    node++;
}
void ma_i()
{
    int pos;
    printf("Enter position to insert(Middle After): ");
    scanf("%d", &pos);
    block *temp=head, *newNode;
    newNode=malloc(sizeof(block));
    printf("Enter data for newNode:");
    scanf("%d", &newNode->data);
    newNode->link=NULL;
    pos--;
    while(pos!=0)
    {
        temp=temp->link;
        pos--;
    }
    newNode->link=temp->link;
    temp->link=newNode;
    node++;
}
int main()
{
    create();
    display();

    mb_i();
    display();

    ma_i();
    display();
    return 0;
}