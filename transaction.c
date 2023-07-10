#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#define MAX 100
struct list
{ 
char Name[MAX];
char Phno[MAX];
char Acc[MAX];
char upi[MAX];
char Password[MAX];
float Balance;
char dob[MAX];
struct list *link;
};
typedef struct list* NODE;
//function declarations
NODE create(NODE);
NODE Phone(NODE,char*,char*);
NODE Acount(NODE,char*,char*);
float Balance(NODE,char*);
void personal(NODE);
NODE Reset(NODE,char*);
NODE sys1(NODE,char*);
//global variables
void readdata();
char name[MAX];
char phno[MAX];
char acc[MAX];
char pass[MAX];
char upipin[MAX];
float bal;
char Dob[MAX];
NODE primary;
int main()
{ 
 int choice1,done1=0;
 char phno1[MAX],pass1[MAX];
 
 NODE fi,p1,p2,p3,cur;
 p1=(NODE)malloc(sizeof(struct list));
 p2=(NODE)malloc(sizeof(struct list));
 p3=(NODE)malloc(sizeof(struct list));
 fi=(NODE)malloc(sizeof(struct list));
 strcpy((p1->Name),"Ram");
 strcpy((p1->Phno),"9876543210");
 strcpy((p1->Acc),"9087654321");
 strcpy((p1->upi),"7654");
 strcpy((p1->Password),"Rhul");
 p1->Balance=10000;
 strcpy((p1->dob),"22/10/2002");
 strcpy((p2->Name),"RahulR");
 strcpy((p2->Phno),"9876543211");
 strcpy((p2->Acc),"9087654311");
 strcpy((p2->upi),"7655");
 strcpy((p2->Password),"R1hu1/");
 p2->Balance=10000;
 strcpy((p2->dob),"23/10/2002");
 strcpy((p3->Name),"RahulRS");
 strcpy((p3->Phno),"9876543212");
 strcpy((p3->Acc),"9087654322");
 strcpy((p3->upi),"7656");
 strcpy((p3->Password),"R2hul");
 p3->Balance=10000;
 strcpy((p3->dob),"24/10/2002");
fi->link=p1;
p1->link=p2;
p2->link=p3;
p3->link=NULL;
 printf("\t\t------welcome to upi payment system------\n\n\n");
 while(!done1)
 { printf("-----------------------------------------------\n");
 printf("1.new customer\t2.existing customer\t3.exit\n");
 printf("-----------------------------------------------\n");
 printf("enter your choice\n");
 scanf("%d",&choice1);
 switch(choice1)
 { 

 case 1:readdata();
 fi=create(fi);
 break;
 case 2:printf("enter Phno:");
 scanf("%s",phno1);
 printf("\nenter password:");
 scanf("%s",pass1);
 cur=fi->link;
 while(((strcmp(cur->Phno,phno1))!=0))
 {cur=cur->link;
 if(cur==NULL)
 break;}
 if(cur==NULL)
 { printf("incorrect phone number!!!\n");
 break;
 }
 else
 { if(strcmp(cur->Password,pass1)==0)
 {primary=cur;
 printf("login successfull----\n");
 fi=sys1(fi,phno1);
 break;}
 else
 {printf("incorrect login credentials!!!!! \n");
 break;}
 }
 case 3:done1=1;
 break;
 default:printf("invalid choice\n");
 break;
 } 
 }
return 0;
}
NODE sys1(NODE fi,char* phno1)
{
int choice,done=0;
char acc2[MAX],phno2[MAX];
float bal1;
while(!done)
{printf("-------------------------------------------------------------------------
-----------\n");

 printf("1.PHONE NUMBER\t2.ACCOUNT 
NO\t3.BALANCE\t4.PERSONAL DETAILS\t5..RESET 
UPI\t6.ELECTRICITYBILL7.EXIT\n");
 printf("--------------------------------------------------------------------------
-----------\n");
 printf("enter choice");
 scanf("%d",&choice);
 switch(choice)
 { 
 case 1:printf("enter the phone number to send money\n");
 scanf("%s",phno2);
 fi=Phone(fi,phno1,phno2);
 break;
 case 2:printf("enter the account no to sendmoney\n");
 scanf("%s",acc2);
 fi=Acount(fi,phno1,acc2);
 break;
 case 3:bal1=Balance(fi,phno1);
 printf("%f\n",bal1);
 break;
 case 4:personal(fi);
 break;
 case 5:fi=Reset(fi,phno1);
 break;
 case 6:fi=NODE(primary,fi)
 break;
 case 7:done=1;
 break;
 default:printf("invalid choice\n");
 break;
 }
}
return fi;
}
void readdata()
{ printf("enter name:");
 scanf("%s",name);
 printf("\n enter phno:");
 scanf("%s",phno);
 printf("\n enter acc no:");
 scanf("%s",acc);
 printf("\n enter password:");
 scanf("%s",pass);
 printf("\n enter 4 digit upi pin:");

 scanf("%s",upipin);
 printf("enter dob(dd/mm/yy):");
 scanf("%s",Dob);
 bal=1000.00;//minimum balance is set to 1000
} 
NODE create(NODE fi)
{ NODE cur,temp;
 cur=fi;
 temp=(NODE)malloc(sizeof(struct list));
 strcpy(temp->Name,name);
 strcpy(temp->Phno,phno);
 strcpy(temp->Acc,acc);
 strcpy(temp->upi,upipin);
 strcpy(temp->Password,pass);
 temp->Balance=bal;
 strcpy(temp->dob,Dob);
 while(cur->link!=NULL)
 cur=cur->link;
 cur->link=temp;
 temp->link=NULL;
 return fi;
}

NODE Phone(NODE fi,char* phno1,char* phno2)
{
 NODE cur,cur1;int i=1,j=3;
 char upipin1[MAX];
 float amount;
 cur=fi;
 cur1=fi;
 while((strcmp(cur1->Phno,phno2)!=0))
 {cur1=cur1->link;
 if(cur1==NULL)
 break;
 }
if(cur1==NULL)
{printf("NO acount linked to this number\n");
 return fi;}
else{
 printf("enter amount of money to send:");
 scanf("%f",&amount);
 while(strcmp(cur->Phno,phno1)!=0)
 cur=cur->link;}
if(amount>(cur->Balance))
 {printf("insufficient acount balance!!!\n");

 return fi;}
else
 { read:
 printf("\nenter your upipin:");
 scanf("%s",upipin);
 if(strcmp(cur->upi,upipin)==0)
 {
 cur->Balance=cur->Balance-amount;
 cur1->Balance=cur1->Balance+amount;
 printf("amount transfer of %f successfull\n",amount);
 return fi;
 }
 else 
 {
 i++;j--;
 printf("wrong pin!!\n");
 printf("you have %d chances!!",j);
 if(i>3)
 return fi;
 else
 goto read;
 }
 } 
return fi;
}
NODE Acount(NODE fi,char* phno1,char* acc2)
{
 NODE cur,cur1;int i=1,j=3;
 char upipin1[MAX];
 float amount;
 cur=fi;
 cur1=fi;
 while((strcmp(cur1->Acc,acc2)!=0))
 {cur1=cur1->link;
 if(cur1==NULL)
 break;
 }
 if(cur1==NULL)
 {printf("there is no acount with this acountnumber!!!\n");
 return fi;}
 else
 {
 printf("enter amount of money to send:");
 scanf("%f",&amount);
 while(strcmp(cur->Phno,phno1))
 {cur=cur->link;}
 if(amount>cur->Balance)
 {printf("insufficient acount balance!!!!\n");
 return fi;
 }
 else
 { read:
 printf("\nenter your upipin:");
 scanf("%s",upipin);
 if(strcmp(cur->upi,upipin)==0)
 {
 cur->Balance=cur->Balance-amount;
 cur1->Balance=cur1->Balance+amount;
 printf("amount transfer of %f successfull\n",amount);
 return fi;
 }
 else 
 {
 i++;j--;
 printf("wrong pin!!\n");
 printf("you have %d chances!!",j);
 if(i>3)
 return fi;
 else
 goto read;
 }
 } 
 }
}
float Balance(NODE fi,char* phno1)
{ int i=1,j=3;
 char upipin1[MAX];
 NODE cur;
 float balan;
 cur=fi;
 while((strcmp(cur->Phno,phno1)!=0))
 cur=cur->link;
 read:
 printf("\nenter your upipin:");
 scanf("%s",upipin1);
 if(strcmp(cur->upi,upipin1)==0)
 {
 balan=cur->Balance;
 return balan;
 }
 else 
 {
 i++;j--;
 printf("wrong pin\n");
 printf("you have %d chances",j);
 if(i>3)
 return 0;
 else
 goto read;
 } 
}
NODE Reset(NODE fi,char* phno1)
{
 NODE cur;
 char upi2[MAX],dob2[MAX],upinew[MAX];
 printf("enter old upi:");
 scanf("%s",upi2);
 printf("answer security question\n");
 printf("\nenter you dob(dd/mm/yy):");
 scanf("%s",dob2);

 cur=fi;
 while(strcmp(( cur->Phno),phno1)!=0)
 cur=cur->link;
 if(strcmp(cur->upi,upi2)==0&&strcmp(cur->dob,dob2)==0)
 {
 printf("enter new upi pin:");
 scanf("%s",upinew);
 strcpy(cur->upi,upinew);
 printf("upi pin reset successfull");
 return fi;}
else
 {printf("wrong details\ntry again\n");
 return fi;}
}
void personal(NODE fi)
{ NODE cur;
 cur=primary;
 printf("Name :%s\n",cur->Name);
 printf("Phno :%s\n",cur->Phno);
 printf("Acno :%s\n",cur->Acc);
 printf("Balance:%f\n",cur->Balance);
 printf("UPI :%s\n","****");

 printf("Password:%s\n","*****");
}
NODE currentbill(NODE Primary,NODE fi)
{ char customerid[MAX],upipin1[MAX];
 int n,i=1,j=3;
 printf("enter the customer id:");
 scanf("%s",customerid);
 printf("enter the no of months:");
 scanf("%d",&n);
 read:
 printf("\nenter your upipin:");
 scanf("%s",upipin1);
 if(strcmp(primary->upi,upipin1)==0)
 {
 primary->Balance=(primary->Balance)-(n*100);
 printf("bill payment successfull\n");
 return fi;
 }
 else 
 {
 i++;j--;
 printf("wrong pin\n");
 printf("you have %d chances",j);
 if(i>3)
 return 0;
 else
 goto read;
 }
}
