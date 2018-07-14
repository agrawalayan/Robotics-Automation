#include<stdio.h>
#include<string.h>
void existing_customer();
void new_customer();
void sign_in();
void myprofile();
void search_book();
void cancel();
void booking_status();
void discount();


int i,id;
char pword[10]={"password"};
struct customer_details
{
	char name[30];
	int age;
	char Address[30];
	char contact_num[10];
	int customer_id;
}customer[5]={{"User1",56,"uyte","12340987",1000},
             	{"User2",46,"hyte","23458765",1001},
             	{"User3",23,"oiuu","98751394",1002}};


void display()
 {
   printf("\n                       :::::::::::::::::::::::::::::::::::::       ");
   printf("\n                       ::                                 ::       ");
   printf("\n                       ::     :::::::::::::::::::::::     ::       ");
   printf("\n                       ::     ::                   ::     ::       ");
   printf("\n                       ::     ::     WELCOME TO    ::     ::       ");
   printf("\n                       ::     ::                   ::     ::       ");
   printf("\n                       ::     ::    HOTEL ORANGE   ::     ::       ");
   printf("\n                       ::     ::                   ::     ::       ");
   printf("\n                       ::     :::::::::::::::::::::::     ::       ");
   printf("\n                       ::                                 ::       ");
   printf("\n                       :::::::::::::::::::::::::::::::::::::   \n\n");
 }



void existing_customer()
{

	for(i=0;i<3;i++)
	{
		printf("\n The details of customer %d :",i+1);
		printf("\n\t\t NAME: %s ",customer[i].name);
		printf("\n\t\t AGE: %d ",customer[i].age);
		printf("\n\t\t ADDRESS: %s ",customer[i].Address);
		printf("\n\t\t CONTACT NUMBER: %s ",customer[i].contact_num);
		printf("\n\t\t CUSTOMER ID:%d ",customer[i].customer_id);
	}
}

void new_customer()
{

	for(i=3;i<=5;i++)
	{
		printf("\n\n\n The details of customer %d",i+1);
		printf("\n\t\t Enter the name:");
		scanf("%s",&customer[i].name);
		printf("\n\t\t Enter the Age:");
		scanf("%d",&customer[i].age);
		printf("\n\t\t Enter the address:");
		scanf("%s",&customer[i].Address);
		printf("\n\t\t Enter the contact number is:");
		scanf("%s",&customer[i].contact_num);
		customer[i].customer_id=(customer[i-1].customer_id)+1;
		printf("\n\t\t Generated Customer_id:%d",customer[i].customer_id );

	}
}

void sign_in()
{
    char pwd[10];
    int choice;
    for(i=0;i<3;i++)
    {
        printf("\n\n\t Enter the customer id : ");
        scanf("%d",&id);
        printf("\n\t\t Enter the password : ");
        scanf("%s",&pwd);
        if((!(strcmp(id,customer[i].customer_id)))&&(!(strcmp(pwd,pword))))
        {
           printf("\n\t\t\t Please enter your choice :");
           scanf("%d",choice);
           switch(choice)
           {
               case 1  : myprofile(int i);
                         break;

               case 2  : search_book();
                         break;

               case 3  : cancel();
                         break;

               case 4  : booking_status();
                         break;

               case 5  : discount();
                         break;

               default : printf("\n You have entered a wrong option : ");
                         break;
            }
        }
        else
        {
           printf("\n\t\t ID or Password is wrong...Please enter the valid details : ");
        }
    }
}


void myprofile(int i)
{

    int choice;
    printf("\n The details of customer %d :",i+1);
    printf("\n\t NAME: %s ",customer[i].name);
    printf("\n\t AGE: %d ",customer[i].age);
    printf("\n\t ADDRESS: %s ",customer[i].Address);
    printf("\n\t CONTACT NUMBER: %s ",customer[i].contact_num);
    printf("\n\t Enter your choice : ");
    scanf("%d",choice);
    switch(choice)
    {
        case 1   : printf("\n\t Edit your profile : ");
                   printf("\n\t\t Enter the name:");
		           scanf("%s",&customer[i].name);
		           printf("\n\t\t Enter the Age:");
		           scanf("%d",&customer[i].age);
		           printf("\n\t\t Enter the address:");
		           scanf("%s",&customer[i].Address);
		           printf("\n\t\t Enter the contact number is:");
                   scanf("%s",&customer[i].contact_num);
                   printf("\n\n\t\t Your profile is edited :");
                   break;

        case 2   : printf("\n\t\t Delete profile : ");
                   customer[i].name=" ";
                   customer[i].age=0;
                   customer[i].Address=" ";
                   customer[i].contact_num=" ";
                   break;

        default  : printf("\n You have entered a wrong option : ");
                   break;
    }
}


void search_book()
{
    int room_no[200],r_choice;
    char choice,room_type[10];
    for(i=0;i<40;i++)
    {
        room_no[i]=i+1;
    }
    for(i=40;i<120;i++)
    {
        room_no[i]=i+1;
    }
    for(i=120;i<200;i++)
    {
        room_no[i]=i+1;
    }
    printf("\n\t Do you want to book a room : ");
    scanf("%c",&choice);
    switch(choice)
    {
     case 'Y' : printf("\n Room Type : \  nPress 1 for Royal \n  Press 2 for Elite \n  Press 3 for Ordinary ");
                scanf("%d"&r_choice);
                switch(r_choice)
                {
                    case 1 :
                }
    }


}


void main()
{
int typ;
printf("Enter your choice:");
printf("\n 1.Existing customer");
printf("\n 2.New customer\n");
printf("\n Enter your choice:");
scanf("%d",&typ);

switch(typ)
{
case 1:existing_customer();
break;
case 2:new_customer();
break;
}
}

