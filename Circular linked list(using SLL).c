#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next; 
}*head,*p,*n,*old;
struct node* insert_front(struct node *head){
    int e;
    p=head;
    old=head;
    printf("Enter the element : ");
    scanf("%d",&e);
    n=(struct node *)malloc(sizeof(struct node));
    n->data=e;
    n->next=NULL;
    if(head->next==NULL){
           head->next=n;
           n->next=head;
           return head;
        }
    while(old->next!=head){
        old=old->next;
    }
    old->next=n;
    n->next=p;
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
    if(head->next==NULL){
           head->next=n;
           n->next=head;
           printf("Insertion success");
           return head;
        }
    printf("Enter the position : ");
    scanf("%d",&pos);
    while(pos!=1){
        old=p;
        p=p->next;
        pos--;
    }
    old->next=n;
    n->next=p;
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
    if(head->next==NULL){
           head->next=n;
           n->next=head;
           printf("Insertion success");
           return head;
        }
    while(p->next!=head){
        old=p;
        p=p->next;
    }
    printf("Insertion success");
    p->next=n;
    n->next=head;
    return head;
}
void traverse(struct node *head){
    p=head;
    printf("The elemments are : ");
    do{
        printf("%d\t",p->data);
        p=p->next;
    }while(p!=head);
    //printf("\n");
}
struct node* delete_front(struct node *head){
    p=head;
    old=p;
    if(head->next==NULL){
        printf("Deletion of %d successfull",old->data);
        return NULL;
    }
    while(old->next!=head){
        old=old->next;
    }
    head=head->next;
    old->next=head;
    printf("Deletion of %d successfull",old->data);
    return head;
}
struct node* delete_middle(struct node *head){
    p=head;
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(head->next==NULL){
        printf("Deletion of %d successfull",head->data);
        return NULL;
    }
    while(pos!=1){
        old=p;
        p=p->next;
        pos--;
    }
    old->next=p->next;
    printf("Deletion of %d successfull",p->data);
    return head;
}
struct node* delete_end(struct node *head){
    p=head;
    if(p->next==NULL){
        printf("Deletion of %d successfull",p->data);
        return NULL;
    }
    while(p->next!=head){
        old=p;
        p=p->next;
    }
    printf("Deletion of %d successfull",p->data);
    old->next=head;
    return head;
}

void main()
{
    head=NULL;
    int f,r;
    printf("Enter the number of node : ");
    scanf("%d",&f);
    for(int l=0;l<f;l++){
        old=head;
        p=head;
        n=(struct node *)malloc(sizeof(struct node));
        printf("Enter %dth element : ",l+1);
        scanf("%d",&r);
        n->data=r;
        n->next=NULL;
        if(head==NULL){
            head=n;
        }
        else if(head->next==NULL){
           head->next=n;
           n->next=head;
        }
        else{
            while(p->next!=head){
                old=p;
                p=p->next;
            }
            p->next=n;
            n->next=head;
        }
    }
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

