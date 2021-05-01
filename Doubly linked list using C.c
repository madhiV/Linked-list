#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next; 
    struct node *prev;
}*head,*p,*n,*old;
//insert front
struct node* insert_front(struct node *head){
    int e;
    p=head;
    
    printf("Enter the element : ");
    scanf("%d",&e);
    n=(struct node *)malloc(sizeof(struct node));
    n->data=e;
    n->prev=NULL;
    n->next=NULL;
    if(head==NULL){
        head=n;
        return head;
    }
    n->next=p;
    p->prev=n;
    head=n;
    printf("Insertion success");
    return head;
}
struct node* insert_middle(struct node *head){
    p=head;
    int e,pos;
    printf("Enter the element : ");
    scanf("%d",&e);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=e;
    n->next=NULL;
    n->prev=NULL;
    printf("Enter the position : ");
    scanf("%d",&pos);
    while(pos!=1){
        old=p;
        p=p->next;
        pos--;
    }
    old->next=n;
    n->next=p;
    n->prev=old;
    if(p!=NULL){
    p->prev=n;
    }
    printf("Insertion success");
    return head;
}
struct node* insert_end(struct node *head){
    p=head;
    int e;
    printf("Enter the element : ");
    scanf("%d",&e);
    n=(struct node*)malloc(sizeof(struct node));
    n->data=e;
    n->next=NULL;
    n->prev=NULL;
    while(p->next!=NULL){
        old=p;
        p=p->next;
    }
    printf("Insertion success");
    p->next=n;
    n->prev=p;
    return head;
}
void traverse(struct node *head){
    p=head;
    if(head==NULL){
        printf("There are no element in the list");
    }
    else{
    printf("The elemments are : ");
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    }
    //printf("\n");
}
struct node* delete_front(struct node *head){
    p=head;
    old=p;
    head=head->next;
    head->prev=NULL;
    printf("Deletion of %d successfull",old->data);
    return head;
}
struct node* delete_middle(struct node *head){
    p=head;
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    while(pos!=1){
        old=p;
        p=p->next;
        pos--;
    }
    old->next=p->next;
    if(p->next!=NULL){
    p->next->prev=old;}
    printf("Deletion of %d successfull",p->data);
    return head;
}
struct node* delete_end(struct node *head){
    p=head;
    if(p->next==NULL){
        printf("Deletion of %d successfull",p->data);
        return NULL;
    }
    while(p->next!=NULL){
        old=p;
        p=p->next;
    }
    printf("Deletion of %d successfull",p->data);
    old->next=NULL;
    return head;
}

void main()
{
    head=NULL;
    int n,e,flag=1;
    while(flag==1){
    printf("-----Menu-----\n");
    printf("1.Insert a node\t2.Delete a node\t3.Traverse\t4.Exit");
    printf("\nEnter an option : ");
    scanf("%d",&n);
    switch(n){
        case 1:
            printf("1.Insert at front\t2.Insert at middle\t3.Insert at end\nEnter a choice : ");
            scanf("%d",&e);
            switch(e){
                case 1:
                    head=insert_front(head);
                    break;
                case 2:
                    head=insert_middle(head);
                    break;
                case 3:
                    head=insert_end(head);
                    break;
                default:
                    printf("Invalid choice");
            }
            break;
        case 2:
            printf("1.Delete at front\t2.Delete at middle\t3.Delete at end\nEnter a choice : ");
            scanf("%d",&e);
            switch(e){
                case 1:
                    head=delete_front(head);
                    break;
                case 2:
                    head=delete_middle(head);
                    break;
                case 3:
                    head=delete_end(head);
                    break;
                default:
                    printf("Invalid choice");
            }
            break;
        case 3:
            traverse(head);
            break;
        case 4:
            flag=0;
            break;
        default:
            printf("Invalid choice");
        }
        printf("\n");
    }
}

