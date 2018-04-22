#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char  dish[100];
int sum=0;
int gst=0;
int total=0;
FILE *fp;
	int c=0;
	char *i;
	char *d;
	char *p;
	char *cu;
	struct prop *temp;
   char str[1000];
struct node
{
 char data[20];
 char price[3];
 struct node* next;
};
struct node *first=NULL;
void insert_t(int);
void remove_order(int);
void display();
//int i;
int cs;
void insert_ll(struct node **,char *,char*);
void remove_ll(struct node**, char*);
void bill();
char*disp[20];
int quantity;
int main()
{
 char indian[50];
 char italian[50];
 char chinese[50];
 printf("1.Indian Cuisine\n");
 printf("2.Chinese Cuisine\n");
 printf("3.Italian Cuisine\n");
 printf("4.American Cuisine\n");
 printf("5.Mexican Cuisine\n");
 scanf("%d", &cs);
 switch(cs)
 {
 case 1:


   fp = fopen("dat123.csv" , "r");

  if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   fgets (str, 1000, fp);
   while( fgets (str, 1000, fp)!=NULL ) {
    i=strtok(str,",");
    d=strtok(NULL, ",");
    p=strtok(NULL, ",");
    cu=strtok(NULL, ",");
    if(strcmp(cu, "Indian")==0)
    {
   	printf("%s %s %s\n",i, d, p);}
   }
   fclose(fp);

    break;
 case 2:
   fp = fopen("dat123.csv" , "r");

  if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   fgets (str, 1000, fp);
   while( fgets (str, 1000, fp)!=NULL ) {
    i=strtok(str,",");
    d=strtok(NULL, ",");
    p=strtok(NULL, ",");
    cu=strtok(NULL, ",");
    if(strcmp(cu, "Chineese")==0)
    {
   	printf("%s %s %s\n",i, d, p);}
   }
   fclose(fp);
   break;

 case 3:

  fp = fopen("dat123.csv" , "r");

  if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   fgets (str, 1000, fp);
   while( fgets (str, 1000, fp)!=NULL ) {
    i=strtok(str,",");
    d=strtok(NULL, ",");
    p=strtok(NULL, ",");
    cu=strtok(NULL, ",");
    if(strcmp(cu, "Italian")==0)
    {
   	printf("%s %s %s\n",i, d, p);}
   }
   fclose(fp);
   break;

 case 4:

  fp = fopen("dat123.csv" , "r");

  if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   fgets (str, 1000, fp);
   while( fgets (str, 1000, fp)!=NULL ) {
    i=strtok(str,",");
    d=strtok(NULL, ",");
    p=strtok(NULL, ",");
    cu=strtok(NULL, ",");
    if(strcmp(cu, "American")==0)
    {
   	printf("%s %s %s\n",i, d, p);}
   }
   fclose(fp);
   break;
 case 5:

  fp = fopen("dat123.csv" , "r");

  if(fp == NULL) {
      perror("Error opening file");
      return(-1);
   }
   fgets (str, 1000, fp);
   while( fgets (str, 1000, fp)!=NULL ) {
    i=strtok(str,",");
    d=strtok(NULL, ",");
    p=strtok(NULL, ",");
    cu=strtok(NULL, ",");
    if(strcmp(cu, "Mexican")==0)
    {
   	printf("%s %s %s\n",i, d, p);}
   }
   fclose(fp);
   break;
 }
 int ch;
 int x;
 while(1)
 {
printf("1.Order\n");
printf("2.Delete an order\n");
printf("3.Display Order\n");
printf("4.Bill\n");
printf("5.Choose another cuisine\n");
printf("6.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter the number of the dish you would like to order\n");
        scanf("%d",&x);
        insert_t(x);
        break;
case 2: printf("Enter the number of the dish that you want to remove\n");
        scanf("%d",&x);
        remove_order(x);
        break;
case 3: display();
        break;
case 4: bill();
        break;

case 5: main();
        break;
case 6: exit(0);
        break;
}
}
}

void insert_t(int x)
{
int a;
char *u,*j;
char strs[1000];
FILE *f;
f=fopen("dat123.csv","r");
fgets(strs, 1000, f);
for(a=0;a<x;a++)
    fgets(strs, 1000, f);
strtok(strs,",");
u=strtok(NULL,",");
j=strtok(NULL,",");
insert_ll(&first,u,j);
}

void insert_ll(struct node**p ,char *i,char *x)
{
struct node*temp;
struct node*q;
temp=(struct node*)malloc(sizeof(struct node));
strcpy(temp->data,i);
temp->next=NULL;
strcpy(temp->price,x);
if(*p==NULL)
    *p=temp;
else{
    q=*p;
    while(q->next!=NULL)
        q=q->next;
    q->next=temp;
}
}
void remove_order(int x)
{
int a;
char *u,*j;
char strs[1000];
FILE *f;
f=fopen("dat123.csv","r");
fgets(strs, 1000, f);
for(a=0;a<x;a++)
    fgets(strs, 1000, f);
strtok(strs,",");
u=strtok(NULL,",");
j=strtok(NULL,",");
remove_ll(&first,u);
}
void remove_ll(struct node**p ,char *i)
{
  struct node *q,*prev;

  if(first==NULL)
     printf("\nEmpty\n");
 else
 { prev=NULL;//keep track of the previous node
  q=first;//copy the address of the first node
  strcpy(q->data,i);
  //q=q->next;
  //move forward until you find the node to be deleted
  //or you go beyond the end of the list

   while((q!=NULL)&&(strcmp(q->data,i)!=0))
   {
     prev=q;
     q=q->next;
   }
   if(q==NULL)
    printf("Node not found\n");
   else if(prev==NULL)//data found and it is first node
    first=q->next;//make first point to second node
   else
     prev->next=q->next;//data found and it is somewhere in between
                     // second and the last node
   free(q);
  }
 }
// struct node* head = NULL;

void display()
{
   struct node *l=first;
   if(first==NULL)
        printf("\nYou have nor ordered anything");
   else
 {
   while(l!=NULL)
   {
   printf("%s %s\n",l->data, l->price);

   l=l->next;
   }
 }
}


void bill()
{
int bp;
int i;
struct node *b=first;
   if(first==NULL)
        printf("\nEmpty");
   else
 {
   printf("YOUR ORDER:\n");
   while(b!=NULL)
   {
   printf("%s %s\n",b->data, b->price);
   i=atoi(b->price);
   sum=sum+(i*0.18)+i;
   b=b->next;
   }
 }
 printf("Your total(inclusive of GST) amounts to %d\n", sum);
 printf("Thank you, Visit Again\n");
 printf("\n");
}

