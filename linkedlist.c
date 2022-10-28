#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head=NULL;
void create()
{
    struct Node *temp,*p=head;
    temp=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}
void insert(int index)
{
    struct Node *temp,*p=head;
    temp=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&temp->data);
    if(index==0)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        while(p->next!=NULL && index>0)
        {
            p=p->next;
            index--;
        }
        temp->next=p->next;
        p->next=temp;
    }
}
void delete(int index)
{
    struct Node *temp,*p=head,*q;
    if(index==0)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    else
    {
        while(p->next!=NULL && index>0)
        {
            q=p;
            p=p->next;
            index--;
        }
        q->next=p->next;
        temp=p;
        free(p);
    }
}
void display()
{
    struct Node *p=head;
    while(p!=NULL)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
}
int main()
{
    int n;
label:
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        {
            create();
            break;
        }
        case 2:
        {
            int num;
            scanf("%d",&num);
            insert(num);
            break;
        }
        case 3:
        {
            int num;
            scanf("%d",&num);
            delete(num);
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
            exit(0);
    }
    if(n==5)
        return 0;
    else{goto label;}
}