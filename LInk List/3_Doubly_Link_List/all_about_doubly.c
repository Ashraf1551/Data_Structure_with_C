#include<stdio.h>
#include<stdlib.h>

struct node
{
    int x;
    struct node *next;
    struct node *prev;
}*head = NULL, *tail=NULL;

void create()
{
    int nodeNum, i;
    struct node *newNode, *current;

    printf("Enter the number of Node: ");
    scanf("%d", &nodeNum);

    for(i=0; i<nodeNum; i++)
    {
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value of X: ");
        scanf("%d", &newNode->x);

        newNode->next = NULL;
        newNode->prev = NULL;

        if(head==NULL)
        {
            head = newNode;
            current = newNode;
            tail = newNode;
        }
        else
        {
            current->next = newNode;
            newNode->prev=current;
            current = newNode;
            tail = newNode;
        }
        printf("%d no node created!\n", i+1);
    }
}

void f_insert()
{
    struct node *newNode, *current;

    newNode = (struct node*)malloc(sizeof(struct node));

    printf("\n\nEnter the value of first node: ");
    scanf("%d", &newNode->x);
    newNode->next = NULL;
    newNode->prev = NULL;

    current = head;
    newNode->next = current;
    current->prev = newNode;
    head = newNode;
    printf("The first node added successfully!\n");

}

void l_insert()
{
    struct node *newNode, *current;

    newNode = (struct node*)malloc(sizeof(struct node));

    printf("\n\nEnter the value of last node: ");
    scanf("%d", &newNode->x);
    newNode->next = NULL;
    newNode->prev = NULL;

    current = tail;
    current->next = newNode;
    newNode->prev = current;
    tail = newNode;

    printf("The last node added successfully!\n");

}

void f_display()
{
    struct node *current;

    printf("\nThe Created Doubly Linked List - Forward Display: \n");
    current = head;

    while(current!=NULL)
    {
        printf("%d->", current->x);
        current = current->next;
    }
    printf("NULL");
}

void b_display()
{
    struct node *current;

    printf("\nThe Created Doubly Linked List - Backward Display: \n");
    current = tail;

    while(current!=NULL)
    {
        printf("%d->", current->x);
        current = current->prev;
    }
    printf("NULL");
}

void mb_insert()
{
    int key,pos,i;

    struct node *newNode, *current, *temp,*temp1;

    newNode=(struct node*)malloc(sizeof(struct node));

    printf("\nEnter the value for middle data:");
    scanf("%d",&newNode->x);

    newNode->next=NULL;
    newNode->prev=NULL;

    current=head;

    printf("\nEnter the data for insert before:");
    scanf("%d",&key);
    pos=search(key);
    //printf("\nin POS=%d",pos);

    for(i=1; i<=(pos-1); i++)
    {
        current=current->next;
    }

    temp=current->prev;
    temp->next=newNode;
    newNode->prev=temp;
    newNode->next=current;
    current->prev=newNode;
}

void node_delete()
{
    if(head==NULL)
    {
        printf("\nThere is no data to delete \n");
        exit(0);
    }

    struct node *current,*temp,*temp1;

    int i,key,pos;
    printf("\nEnter your data to delete\n");
    scanf("%d",&key);

    pos=search(key);

    current=head;
    for(i=1; i<=(pos-1); i++)
    {
        current=current->next;
    }

    if(head==current)
    {
        head=current->next;
        head->prev=NULL;
    }
    else if(current->next==NULL)
    {
        tail = current->prev;
        current=head;
        for(i=1; i<=(pos-2); i++)
        {
            current=current->next;
        }
        current->next=NULL;
    }
    else
    {
        temp=current;
        temp1=current->next;
        current=head;
        for(i=1; i<=(pos-2); i++)
        {
            current=current->next;
        }
        current->next=temp->next;
        temp1->prev=current;

    }
    printf("\nDelete Successfully\n");
}

int search(int key)
{
    int pos=0;
    struct node *current;
    current = head;

    while(current!=NULL)
    {
        pos++;
        if(current->x == key)
        {
            return pos;
        }
        current = current->next;
    }
    return -1;

}

int main()
{
    create();
    f_display();
    b_display();

    f_insert();
    f_display();
    b_display();

    l_insert();
    f_display();
    b_display();

    mb_insert();
    f_display();
    b_display();

    node_delete();
    f_display();
    b_display();

    /*int key, pos = 0;
    printf("\nEnter the search value of X: ");
    scanf("%d", &key);

    pos = search(key);

    if(pos==-1)
    {
        printf("\mNot Found!");
    }
    else
    {
        printf("\Found at : %d node node", pos);
    }*/

}