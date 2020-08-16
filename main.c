#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node
{
    int p;
    char ans;
    struct node *lptr,*rptr;
}NODE;

NODE *insert(NODE **first,int p,char ans)
{
    NODE *newnode,*temp;
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->p=p;
    newnode->ans=ans;
    newnode->rptr=NULL;
    newnode->lptr=NULL;

    if(*first==NULL)
        *first=newnode;

    else
    {
        temp=*first;
        while(temp->rptr!=NULL)
               temp=temp->rptr;
        temp->rptr=newnode;
        newnode->lptr=temp;
    }

    return (newnode);
}

void display(NODE * first)
{
    printf("\nYour answers are:\n");
    while(first!=NULL)
    {
        printf("%d\t%c\n",first->p+1,first->ans);
        first=first->rptr;
    }
}


void update(char name1[],int data1)
{
    FILE *fp,*fp1;
    char name[20];
    int flag=0,data,res;

    fp=fopen("B.txt","r");
    fp1=fopen("temp.txt","a");

    while((fscanf(fp,"%s %d",name,&data))!=EOF)
    {
        res=strcmp(name,name1);
        if(res==0)
        {
            flag=1;
            fprintf(fp1,"%s %d\n",name,data1);
        }
        else
            fprintf(fp1,"%s %d",name,data);
    }
    if(flag==0)
        printf("\nName not found..");
    fclose(fp);
    fclose(fp1);

    fp=fopen("B.txt","w");
    fclose(fp);

    fp=fopen("B.txt","a");
    fp1=fopen("temp.txt","r");

    while((fscanf(fp1,"%s %d",name,&data))!=EOF)
        fprintf(fp,"%s %d\n",name,data);
    fclose(fp);
    fclose(fp1);

    fp1=fopen("temp.txt","w");
    fclose(fp1);
}


int advanced(int progress)
{
    printf("\nWelcome to Advanced level, to complete this level your score must be greater than 85%%.\n");
    progress=5;

    char enter;
    fflush(stdin);
    printf("\nPress Enter to continue...");
    scanf("%c",&enter);

    int count=0,i,j,p,m[6];
    char ans[6]="abcda";
    char answer,ch,change,cans,cl;
    NODE *l1=NULL,*cur,*temp;
    int flg[5]={0};
    long t;
    t=time(NULL);
    srand(t);

    for(i=0;i<5;i++)
    {
        fflush(stdin);
        label: p=(rand()%5);
        m[i]=p;

        for(j=0;j<i;j++)
        {
            if(m[j]==p)
                goto label;
        }
        fflush(stdin);

        label1:switch(p)
        {
            case 0:printf("\nQuestion: this is question 1:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                        if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                        }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 1:printf("\nQuestion: this is question 2:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                    if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                                }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 2:printf("\nQuestion: this is question 3:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                        if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                         }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                        {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }

                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                   else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 3:printf("\nQuestion: this is question 4:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                            if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                         }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                 else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 4:printf("\nQuestion: this is question 5:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                            if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                        }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;
        }
    }

    display(l1);
    temp=l1;
    while(temp!=NULL)
    {
        if(temp->ans==ans[temp->p])
            count++;
        temp=temp->rptr;
    }

    float res;
    res=count/5.0;
    printf("\nyour result is %f percent.",res*100);

    if(count>=4)
        printf("\nCongrats you have completed our Smart Quiz..you will soon get a certificate from us.");

     else
    {
       printf("\nYour result is poor,please try again...");
       printf("\n Do you want to continue to this level or exit: c-continue e-exit:");
       scanf("%c",&cl);
       fflush(stdin);
       if(cl=='c')
            progress=advanced(progress);
    }

    return progress;
}

int intermediate(int progress)
{
    printf("\nWelcome to Intermediate level, to complete this level your score must be greater than 85%%.\n");
    progress=4;

    char enter;
    fflush(stdin);
    printf("\nPress Enter to continue....");
    scanf("%c",&enter);

    int count=0,i,j,p,m[6];
    char ans[6]="abcda";
    char answer,ch,change,cans,nl,cl;
    NODE *l1=NULL,*cur,*temp;
    int flg[5]={0};
    long t;
    t=time(NULL);
    srand(t);

    for(i=0;i<5;i++)
    {
        fflush(stdin);
        label: p=(rand()%5);
        m[i]=p;

        for(j=0;j<i;j++)
        {
            if(m[j]==p)
                goto label;
        }
        fflush(stdin);

        label1:switch(p)
        {
            case 0:printf("\nQuestion: this is question 1:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                        if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                        }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 1:printf("\nQuestion: this is question 2:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                    if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                                }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 2:printf("\nQuestion: this is question 3:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                        if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                         }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                        {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }

                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                   else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 3:printf("\nQuestion: this is question 4:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                            if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                         }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                 else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 4:printf("\nQuestion: this is question 5:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                            if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                        }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;
        }
    }

    display(l1);
    temp=l1;
    while(temp!=NULL)
    {
        if(temp->ans==ans[temp->p])
            count++;
        temp=temp->rptr;
    }

    float res;
    res=count/5.0;
    printf("\nyour result is %f percent.",res*100);

    if(count>=4)
    {
        printf("\n\nYou are promoted to advanced level.");
        progress=5;
        printf("\n Do you want to continue to next level or exit: c-continue e-exit :");
        scanf("%c",&nl);
        fflush(stdin);
        if(nl=='c')
             progress=advanced(progress);
    }
    else
    {
       printf("\nYour result is poor,please try again...");
       printf("\n Do you want to continue to this level or exit: c-continue e-exit:");
       scanf("%c",&cl);
       fflush(stdin);
       if(cl=='c')
            progress=intermediate(progress);
    }
    return progress;
}

int basic(int progress)
{
    printf("\nWelcome to Basic level, to complete this level your score must be greater than 85%%.\n");
    progress=2;

    char enter;
    fflush(stdin);
    printf("\nPress Enter to continue...");
    scanf("%c",&enter);

    int count=0,i,j,p,m[6];
    char ans[6]="abcda";
    char answer,ch,change,cans,nl,cl;
    NODE *l1=NULL,*cur,*temp;
    int flg[5]={0};
    long t;
    t=time(NULL);
    srand(t);

    for(i=0;i<5;i++)
    {
        fflush(stdin);
        label: p=(rand()%5);
        m[i]=p;

        for(j=0;j<i;j++)
        {
            if(m[j]==p)
                goto label;
        }
        fflush(stdin);

        label1:switch(p)
        {
            case 0:printf("\nQuestion: this is question 1:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                        if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                        }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 1:printf("\nQuestion: this is question 2:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                    if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                                }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 2:printf("\nQuestion: this is question 3:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                        if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                         }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                        {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }

                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                   else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 3:printf("\nQuestion: this is question 4:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                            if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                         }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                 else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 4:printf("\nQuestion: this is question 5:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                            if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                        }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;
        }
    }

    display(l1);
    temp=l1;
    while(temp!=NULL)
    {
        if(temp->ans==ans[temp->p])
            count++;
        temp=temp->rptr;
    }

    float res;
    res=count/5.0;
    printf("\nyour result is %f percent.",res*100);

    if(count>=4)
    {
        printf("\n\nYou are promoted to intermediate.");
        progress=4;
        printf("\n Do you want to continue to next level or exit: c-continue e-exit :");
        scanf("%c",&nl);
        fflush(stdin);
        if(nl=='c')
             progress=intermediate(progress);
    }
    else
    {
       printf("\nYour result is poor,please try again...");
       printf("\n Do you want to continue to this level or exit: c-continue e-exit:");
       scanf("%c",&cl);
       fflush(stdin);
       if(cl=='c')
            progress=basic(progress);
    }
    return progress;
}

int initial(char name[])
{
    printf("\nwelcome %s, First of all We will check your previous knowledge here and accordingly assign you a level,",name);
    printf("\nso that you get the deserving questions.Here,it goes..\n");
    int count=0,i,j,p,m[6];
    char ans[6]="abcda";
    char answer,ch,change,cans;
    NODE *l1=NULL,*cur,*temp;
    int flg[5]={0};
    long t;
    t=time(NULL);
    srand(t);

    for(i=0;i<5;i++)
    {
        fflush(stdin);
        label: p=(rand()%5);
        m[i]=p;

        for(j=0;j<i;j++)
        {
            if(m[j]==p)
                goto label;
        }
        fflush(stdin);

        label1:switch(p)
        {
            case 0:printf("\nQuestion: this is question 1:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                        if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                        }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 1:printf("\nQuestion: this is question 2:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                    if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                                }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 2:printf("\nQuestion: this is question 3:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                        if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                         }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                        {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }

                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                   else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 3:printf("\nQuestion: this is question 4:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                            if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                         }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                 else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;

            case 4:printf("\nQuestion: this is question 5:\n");
                    printf("a. option1\tb. option2\t c. option3\t d. option3");
                            if(flg[p]==0){
                            printf("\nYour answer is:");
                            scanf("%c",&answer);
                            fflush(stdin);
                            cur=insert(&l1,p,answer);
                        }
                        else
                        {
                            printf("\nYour answer was: %c",cur->ans);
                            printf("\nDo you want to change your answer:");
                            scanf("%c",&change);
                            fflush(stdin);
                            if(change=='y')
                            {
                                printf("\nEnter your new answer:");
                                scanf("%c",&cans);
                                fflush(stdin);
                                cur->ans=cans;
                            }
                        }
                    flg[p]=1;
                    printf("\np:previous n:next");
                    scanf("%c",&ch);
                    fflush(stdin);
                    if(ch=='p')
                    {
                        if(cur->lptr==NULL)
                            {
                            printf("\nNo previous Questions.");
                            goto label1;
                        }
                        else
                        {
                            cur=cur->lptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    else if(ch=='n')
                    {
                        if(cur->rptr!=NULL)
                        {
                            cur=cur->rptr;
                            p=cur->p;
                            goto label1;
                        }
                    }
                    break;
        }
    }

    display(l1);
    temp=l1;
    while(temp!=NULL)
    {
        if(temp->ans==ans[temp->p])
            count++;
        temp=temp->rptr;
    }

    float res;
    res=count/5.0;
    printf("\nyour result is %f percent.\n",res*100);
    return count;
}

int main()
{
    int count;
    printf("\n\t\t\t\t\tWelcome to SmartQuiz!!\n");
    printf("\n SmartQuiz consits of 3 levels:\n \t BASIC \t INTERMEDIATE \t ADVANCED \n");
    printf("\n Each level consists of 10 Questions. At least 80 of the questions must me answered correctly to complete each level.\n");
    printf(" After each level you can save your progress.\n");

    char name[20],name2[20],expn;
    int data2,flg=0,me=0;
    printf("\n\nEnter your name to continue:");
    gets(name);
    fflush(stdin);

    int progress=0;
    FILE *fp;
    fp=fopen("B.txt","r");
    while((fscanf(fp,"%s %d",name2,&data2))!=EOF)
    {
        if(strcmp(name,name2)==0)
            {
                flg=1;
            }
    }
    fclose(fp);

    if(flg==0)
    {
        fp=fopen("B.txt","a");
        fprintf(fp,"%s %d\n",name,progress);
        fclose(fp);
        count=initial(name);
    }

    else if(flg==1)
    {
        printf("Do you want to continue your progress:y for yes n for no:");
        scanf("%c",&expn);

        if(expn=='y')
        {
            fp=fopen("B.txt","r");
            while((fscanf(fp,"%s %d",name2,&data2))!=EOF)
            {
                if(strcmp(name,name2)==0)
                {
                    count=data2;
                    me=1;
                    break;
                }
            }
            fclose(fp);
        }
        else
            count=initial(name);

    }

    if(count==0)
    {
       count=initial(name);
    }

    if(count==5)
    {
        if(me==0)
            printf("\nCongratulations, You are upgraded to Advanced level.");
        progress=advanced(progress);
    }

    else if(count==4)
    {
        if(me==0)
            printf("\nCongratulations, You are upgraded to Intermediate level.");
        progress=intermediate(progress);
    }
    else
    {
        if(me==0)
            printf("\nCongratulations, You are upgraded to basic level.");
        progress=basic(progress);
    }

    char want;
    printf("\n\nDo you want to save your progress:y for yes n for no:");
    scanf("%c",&want);

    if(want=='y')
    {
         update(name,progress);
         printf("\nYour progess is saved successfully.\n");
    }


    return 0;
}
