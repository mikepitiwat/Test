#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
    int info;
    struct Node *llink;
    struct Node *rlink;
};
struct Node *H, *H1, *p, *q;
int i,j,k,n,data;
char ch;
int del,data1,data2; //edit
struct Node *s1, *s2, *p1f, *p1r,*p2f, *p2r; //edit
struct Node *Allocate()
{
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    return(temp);
}
void CreateNNode(int n)
{
    int i,temp;
    H1 = H;
    for( i = 1 ; i <= n ; i++ ) {
        p = Allocate();
        temp = 1 + rand() % 99;
        p->info = temp;//edit
        H1->rlink = p;//edit
        p->llink = H1;//edit
        H1 = p;//edit
        H1->rlink = H;//edit
        H->llink = H1;//edit
    }
}
void ShowAllNode()
{
    printf("H = %x\n",H);
    p = H;
    i = 1;
    while (i <= n)//edit
    {
        printf("%d = %x\t", i, p);
        printf("LLINK : %x\t", p->llink);
        printf("INFO : %d\t", p->info);
        printf("RLINK : %x\n", p->rlink);
        p = p->rlink;
        i++;
    }
}
void InsertAfter(int data1){
    int temp;
    i = 1; //edit
    if( H == NULL )
        printf("Linked List have no node!!..\n");
    else
    {
        H1 = H;
        printf("\nInsert data : ");//edit
        scanf("%d",&temp);//edit
        while( i <= n )//edit
        {
            if( H1->info == data1 )
            {
                p = Allocate();
                p->info = temp;
                if( (H1->rlink->info == H->info) && (i==n) ) //edit
                {
                    H1->rlink->llink = p; //edit
                    p->rlink = H1->rlink; //edit
                }
                else
                {
                    p->rlink = H1->rlink;
                    H1->rlink->llink = p;
                }
                p->llink = H1;
                H1->rlink = p;
                n++;//edit
                i++;//edit
                H1 = H1->rlink;//edit
            }
            H1 = H1->rlink;
            i++; //edit
        }
    }
}
void InsertBefore(int data1)
{
    int temp;
    i = 1;
    if( H == NULL )
        printf("Linked List have no node!!..\n");
    else
    {
        H1 = H;
        printf("\nInsert data : ");  //edit
        scanf("%d",&temp);  //edit
        while( i <= n)//edit
        {
            if( H1->info == data1 )
            {
                p = Allocate();
                p->info = temp;
                if( (H1->info == H->info) && (i == 1))//edit
                {
                    H1->llink->rlink = p;//edit
                    p->llink = H1->llink;//edit
                    H = p;//edit
                }
                else
                {
                    H1->llink->rlink = p;
                    p->llink = H1->llink;
                }
                H1->llink = p;
                p->rlink = H1;
                n++;//edit
                i++;//edit
            }
            H1 = H1->rlink;
            i++;//edit
        }
    }
}
void DeleteBefore(int data1)
{
    i =1; //edit
    if( H == NULL )
        printf("Linked List have no node!!..\n");
    else
    {
        H1 = H;
        while( i <= n ) //edit
        {
            if( H1->info == data1 )
            {
                if( H1->llink == NULL )
                    printf("No more node from here,Can't delete it!!\n");
                else
                {
                    p=H1->llink;
                    if( (p->info == H->info) && (i == 2))//edit
                    {
                        H1->llink = p->llink;//edit
                        p->llink->rlink = H1;//edit
                        H = H1;//edit
                    }
                    else
                    {
                        H1->llink = p->llink;
                        p->llink->rlink = H1;
                    }
                    free(p);
                    n--; //edit
                }
            }
            H1 = H1->rlink;
            i++;//edit
        }
    }
}
void DeleteSelf(int data1)
{
    int temp;
    i = 1; //edit
    del = 0;//edit
    if( H == NULL )
        printf("Linked List have no node!!..\n");
    else
    {
        H1 = H;
        while( i <= n ) //edit
        {
            if( H1->info == data1 )
            {
                p = H1;
                if( p->llink == NULL && p->rlink == NULL )
                    H = NULL;
                else
                {
                    if( p->info == H->info) //edit
                    {
                        H = p->rlink; //edit
                        H->llink = p->llink; //edit
                        p->llink->rlink = H; //edit
                    }
                    else
                        if(p->rlink->info == H->info) //edit
                        {
                            H1 = p->llink;//edit
                            H1->rlink = p->rlink;//edit
                            p->rlink->llink = H1;//edit
                        }
                        else
                        {
                            p->llink->rlink = p->rlink;
                            p->rlink->llink = p->llink;
                        }
                }
                free(p);
                del++; //edit
            }
            H1 = H1->rlink;
            i++; //edit
        }
        n = n - del;//edit
    }
}
void DeleteAfter(int data1)
{
    int temp;
    i = 1;//edit
    if( H == NULL )
        printf("Linked List have no node!!\n");
    else
    {
        H1 = H;
        while( i <= n )
        {
            if( H1->info == data1 )
            {
                if( H1->rlink == NULL )
                    printf("No more node from here,Can't delete it!!\n");
                else
                {
                    p = H1->rlink;
                    if( (p->rlink->info == H1->info) && (i == (n-1))) {//edit
                        H1->rlink = p->rlink;//edit
                        p->rlink->llink = H1;//edit
                    }else{
                        if ((p->info == H->info) && (i == n)) {//edit
                            H = p->rlink;//edit
                            H1->rlink = H;//edit
                            H->llink = H1;//edit
                        }else{
                            H1->rlink = p->rlink;
                            p->rlink->llink = H1;
                        }
                    }
                    free(p);
                    n--;//edit
                }
            }
            H1 = H1->rlink;
            i++;//edit
        }
    }
}

void swap(int data1, int data2){
    i = 1;
    s1 = NULL; s2 = NULL;
    H1 = H;
    while (i <= n) {
        if(H1->info == data1){
            s1 = H1;
            p1f = H1->llink;
            p1r = H1->rlink;
        }
        if(H1->info == data2){
            s2 = H1;
            p2f = H1->llink;
            p2r = H1->rlink;
        }
        H1 = H1->rlink;
        i++;
    }// serch
    if((s1->llink->info == s2->info) || (s2->llink->info == s1->info)){
        if(s1->rlink->info == s2->info) {
            p1f->rlink = s2;
            s2->llink = p1f;
            s1->rlink = p2r;
            p2r->llink = s1;
            s2->rlink = s1;
            s1->llink = s2;
            if((s1->info == H->info) || (s2->info == H->info)){
                if(s1->info == H->info) H = s2; else H = s1;
            }
        }else if(s2->rlink->info == s1->info) {
            p2f->rlink = s1;
            s1->llink  = p2f;
            s2->rlink  = p1r;
            p1r->llink = s2;
            s1->rlink  = s2;
            s2->llink  = s1;
            if((s1->info == H->info) || (s2->info == H->info)){
                if(s1->info == H->info) H = s2; else H = s1;
            }
        }
    }else{
        p1f->rlink = s2;
        s2->llink  = p1f;
        s2->rlink  = p1r;
        p1r->llink = s2;
        p2f->rlink = s1;
        s1->llink  = p2f;
        s1->rlink  = p2r;
        p2r->llink = s1;
        if((s1->info == H->info) || (s2->info == H->info)){
            if(s1->info == H->info) H = s2; else H = s1;
        }
    }
}

int main()
{
    n = 10;
    p = Allocate();//edit
    p->info = 1+rand()%99;//edit
    H = p;//edit
    H->rlink = H;//edit
    H->llink = H;//edit
    CreateNNode(n-1);//edit
    printf("PROGRAM DOUBLY LINKED LIST...\n");
    printf("=============================\n");
    printf("All Data in Linked List...\n");
    ShowAllNode();
    ch = ' ';
    while( ch != 'E' )
    {
        printf("MENU >> [B : INSERTBEFTER | A : INSERTAFTER]\n");
        printf("        [O : DELETEBEFORE | X : DELETESELF ]\n");
        printf("        [D : DELETEAFTER  | S : SWAP   ]\n");
        printf("        [E : EXIT\n");
        ch = getch();
        switch(ch){
            case'B':	printf("\nInsert Before data : ");
                scanf("%d",&data);
                InsertBefore(data);
                printf("\nAll Data in Linked List After Inserted\n");
                ShowAllNode();
                break;
            case'A':	printf("\nInsert After data : ");
                scanf("%d",&data);
                InsertAfter(data);
                printf("\nAll Data in Linked List After Inserted\n");
                ShowAllNode();
                break;
            case'O':	printf("\nDelete Before data : ");
                scanf("%d",&data);
                DeleteBefore(data);
                printf("\nAll Data in Linked List After Delete\n");
                ShowAllNode();
                break;
            case'X':	printf("\nDelete Self data : ");
                scanf("%d",&data);
                DeleteSelf(data);
                printf("\nAll Data in Linked List Itself Delete\n");
                ShowAllNode();
                break;
            case'D':	printf("\nDelete After data : ");
                scanf("%d",&data);
                DeleteAfter(data);
                printf("\nAll Data in Linked List After Deleted\n");
                ShowAllNode();
                break;
            case'S':	printf("\nSWAP Linked List : ");//edit
                printf("\ndata1 : ");
                scanf("%d",&data1);
                printf("\ndata2 : ");
                scanf("%d",&data2);
                swap(data1,data2);
                printf("\nAll Data in Linked List After SWAP\n");
                ShowAllNode();
                break;
        }
    }
}
