#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct node {
    int data;
    struct node *next, *curr;
} *first = NULL, *curr;

// 1. Insert at Beginning
void insatbeg(int val) {
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = val;
    new1->next=NULL;

    new1->next = first;
    first = new1;

}

// 2. Insert at End
void insatend(int val) {
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = val;
    new1->next = NULL;

    if (first == NULL) {
        first = new1;
    } else {
        curr = first;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new1;
    }

}

// 3. Delete a node (by value)
void deleteNode(int val) {
    struct node *prev = NULL;
    curr = first;

    if (curr != NULL && curr->data == val) {
        first = curr->next;
        free(curr);

        return;
    }

    while (curr != NULL && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {

        return;
    }

    prev->next = curr->next;
    free(curr);

}

// 4. Display the list
void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    curr = first;
    printf("List: ");
    while (curr != NULL) {
        printf("%d ->-> ", curr->data);
        curr = curr->next;
    }

}
void insbfr(int val)
{
    int value;
    struct node *prev = NULL;
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = val;
    new1->next = NULL;

    if (first == NULL)
    {
        first = new1;
    }
    else
    {
        printf("enter before value :");
        scanf("%d",&value);

        prev=first;
        curr=first;
        while(curr->data !=value)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=new1;
        new1->next=curr;
    }
}
void insaft(int val)
{
    int value;
    struct node *post = NULL;
    struct node *new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = val;
    new1->next = NULL;

    if (first == NULL)
    {
        first = new1;
    }
    else
    {
         printf("enter after value :");
        scanf("%d",&value);

        curr=first;
        post=first;
        while(curr->data!=value)
        {
            curr=curr->next;
            post=curr->next;
        }
        curr->next=new1;
        new1->next=post;
    }


}
void delbfr(int val)
{
    int value;
    struct node *prev = NULL;
    struct node *post = NULL;
    if(first== NULL)
    {
        printf("list is empty !");
    }
    else
    {
        printf("enter value to delete before  :");
        scanf("%d",&value);

        curr=first;
        prev=curr;
        post=curr;

        while(curr->next->data !=value)
        {
            prev=curr;
            curr=curr->next;
            post=curr->next;
        }
        prev->next=post;
        free(curr);
    }
}
void delaft(int val)
{
    int value;
    struct node *post ,*npost=NULL;
    if(first== NULL)
    {
        printf("list is empty !");
    }
    else
    {
        printf("enter value to delete after :");
        scanf("%d",&value);

        curr=first;
        post=first;
        npost=first;

        while(curr->data !=value)
        {
            curr=curr->next;
            post=curr->next;
            npost=post->next;
        }
        curr->next=npost;
        free(post);
    }
}
void delbtw()
{
    int value;
    struct node *post,*prev=NULL;
    if(first== NULL)
    {
        printf("list is empty !");
    }
    else
    {

        printf("enter value to delete after :");
        scanf("%d",&value);

        prev=first;
        curr=first;
        post=first;

        while(curr->data != value)
        {
            prev=curr;
            curr=curr->next;
            post=curr->next;
        }
        prev->next=post;
        free(curr);
    }
}
void sorting()
{
    struct node*i ;
    struct node *j;
    int tmp;

    for(i= first ; i!= NULL ; i=i->next)
    {
        for(j= i ; j->next!= NULL ; j=j->next)
        {
            if(i->data > j->data)
            {
                tmp=i->data;
                i->data=j->data;
                j->data=tmp;
            }

        }

    }
}

void serch()
{
    struct node *i;
    int value ,flag=0;
    printf("enter search element ");
    scanf("%d",&value);
    for(i= first ; i!= NULL ; i=i->next)
    {
        if(value ==i->data)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("Not found");
    }
    else
    {
        printf("found");
    }
}
int main() {
    int val, ch;

    do {
        printf("\n |-----MENU-----|");
        printf("\n 1. INSERT AT BEGINNING");
        printf("\n 2. INSERT AT END");
        printf("\n 3. DISPLAY");
        printf("\n 4. DELETE");
        printf("\n 5. insert before");
        printf("\n 6. insert after");
        printf("\n 7. delete before");
        printf("\n 8. delete after");
        printf("\n 9. delete between");
        printf("\n 10. sorting  ");
        printf("\n 10. search  ");
        printf("\n 12. Exit  ");
        printf("\n |--------------|");
        printf("\n Enter Choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf(" Enter Value to insert: ");
            scanf("%d", &val);
            insatbeg(val);
        }
        else if (ch == 2) {
            printf(" Enter Value to insert: ");
            scanf("%d", &val);
            insatend(val);
        }
        else if (ch == 3) {
            display();
        }
        else if (ch == 4) {
            printf(" Enter Value to Delete: ");
            scanf("%d", &val);
            deleteNode(val);
        }
        else if(ch==5)
        {
            printf(" Enter Value to insert: ");
            scanf("%d", &val);
            insbfr(val);
        }
        else if(ch==6)
        {
             printf(" Enter Value to insert: ");
            scanf("%d", &val);
            insaft(val);
        }
        else if(ch==7)
        {

           delbfr(val);
        }
        else if(ch==8)
        {
        delaft(val);
        }
        else if(ch==9)
        {

           delbtw();
        }

        else if (ch == 10) {
            sorting();
        }
         else if (ch == 11) {
            serch();
        }

        else if (ch == 12) {
            printf("\n Good Bye!\n");
        }
        else {
            printf(" Enter valid Choice.\n");
        }
    } while (ch != 12);

    return 0;
}

