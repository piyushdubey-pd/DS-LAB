#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
struct node *link;
char nm[20]; int M,ID,T;
};
typedef struct node *NODE;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
if(x==NULL)
{
printf("mem full\n");
exit(0);
}
return x;
}

NODE cir_insert_front(NODE last,char str[],int id,int mob,int t)
{
NODE temp;
temp=getnode();
int i=0;
while(str[i]!='\0')
temp->nm[i]=str[i];
temp->M=mob;
temp->ID=id;
temp->T=t;

if(last==NULL)
last=temp;
temp->link=last->link;
last->link=temp;
return last;
}
NODE cir_insert_rear(NODE last,char str[],int id,int mob,int t)
{
NODE temp;
temp=getnode();
int i=0;
while(str[i]!='\0')
temp->nm[i]=str[i];
temp->M=mob;
temp->ID=id;
temp->T=t;
if(last==NULL)
last=temp;
else
temp->link=last->link;
last->link=temp;
return temp;
}

void display(NODE last)
{
NODE temp;
if(last==NULL)
{
printf("list empty\n");
return;

}
printf("Name\tID\tMobile Number\n");
for(temp=last->link;temp!=last;temp=temp->link)
{
if(temp->T>8)
printf("%s\t%d\t%d\n",temp->nm,temp->ID,temp->M);
}
}
int main()
{
int choice,ID,M,T;char nm[20];
NODE last=NULL;
for(;;)
{
printf("\n1.Enter employee detail\n2.Enter emplyee detail at rear end \n3. Display who worked more than 8 hours \n4.exit \n");
printf("Enter the choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("Enter NAME, ID, MOBILE num, time in hours : ");
		scanf("%s%d%d%d",nm,&ID,&M,&T);
    nm[strlen(nm)]='\0';
last=cir_insert_front(last,nm,ID,M,T);
break;

case 2:printf("Enter NAME, ID, MOBILE num, time in hours : ");
		scanf("%s%d%d%d",nm,&ID,&M,&T);
    nm[strlen(nm)]='\0';
last=cir_insert_rear(last,nm,ID,M,T);
break;

case 3:display(last);
break;
default:exit(0);
}
}
}