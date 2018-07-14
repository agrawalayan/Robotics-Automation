#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//function declaration
void existing_customer();
void new_customer();
void sign_in();
void myprofile(int);
void booking();
void cancel();
void booking_status();
void room_status(int);
void check_avail(int);
void staff();



//global variable declaration
char pword[10]={"password"};
int i,id,r_status=0,room_no,tot_room[3]={40,80,80},exist_cust_r=0,exist_cust_e=0,exist_cust_o=0,count=0,room_alot=0;



//structure declaration
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

struct room_alotted
{
    int room_number,cust_id;
}room[5]={};





//main function
void main()
{
    int choice;
    display();
    printf("Enter your choice:");
    printf("\n 1.Login");
    printf("\n 2.New customer");
    printf("\n 3.Login as Staff");
    printf("\n 4.Login as Admin");
    printf("\n 5.Exit\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:sign_in();
                break;
        case 2://new_customer();
                break;
        case 3://staff();
                break;
        case 4://admin();
                break;
        case 5:exit(0);
                break;
    }
}


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
		room
		break;
	}
}



void sign_in()
{
    int found=0,m;
    char pwd[10];
    int choice;
    printf("\n\n\t Enter the customer id : ");
    scanf("%d",&id);
    printf("\n\t\t Enter the password : ");
    scanf("%s",&pwd);
    for(i=0;i<3;i++)
    {

        if((id==customer[i].customer_id)&&(strcmp(pwd,pword)==0))
        {
            m=i;

            found=1;
           printf("\n\t\t\t Please enter your choice \n 1. Myprofile \n 2. Booking & Availability \n 3. Cancellation \n 4. Discount: \n");
           scanf("%d",&choice);
           switch(choice)
           {
               case 1  : //myprofile(m);
                         break;

               case 2  : booking();
                         break;

               case 3  : //cancel();
                         break;

               case 4  : //discount();
                         break;

               default : printf("\n You have entered a wrong option : ");
                         break;
            }
        }
    }
        if(found==0)
        {
           printf("\n\t\t ID or Password is wrong...Please enter the valid details : ");
           sign_in();
        }

}

void myprofile(int i)
{

    int choice,j=0;
    printf("\n The details of customer %d :",customer[i].customer_id);
    printf("\n\t NAME: %s ",customer[i].name);
    printf("\n\t AGE: %d ",customer[i].age);
    printf("\n\t ADDRESS: %s ",customer[i].Address);
    printf("\n\t CONTACT NUMBER: %s ",customer[i].contact_num);
    printf("\n\t Enter your choice : ");
    scanf("%d",&choice);
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
                       while(((customer[i].name[j])!="\0")&&(j<30))
                       {
                           customer[i].name[j]=65;
                           j++;
                       }


                   customer[i].age=0;
                   printf("Hello1");
                   j=0;
                   while(((customer[i].Address[j])!="\0")&&(j<30))
                       {
                           customer[i].Address[j]=65;
                           j++;
                       }
                       j=0;

                    while(((customer[i].contact_num[j])!="\0")&&(j<10))
                       {
                           customer[i].contact_num[j]=65;
                           j++;
                       }


                   myprofile(i);
                   printf("Hello");
                   break;

        default  : printf("\n You have entered a wrong option : ");
                   break;
    }

}





void booking()
{
    int r_choice,choice;
    char room_type[10];
    printf("\n\t Do you want to book a room or check availability of room : ");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1 : printf("\n Room Type : \n  Press 1 for Royal \n  Press 2 for Elite \n  Press 3 for Ordinary\n ");
                scanf("%d",&r_choice);
                switch(r_choice)
                {
                    case 1  : room_status(r_choice);
                              break;

                    case 2  : room_status(r_choice);
                              break;

                    case 3  : room_status(r_choice);
                              break;

                    default : printf("\n Please enter a valid choice ");
                              break;
                }
                break;

      case 2 : printf("\n Room Type : \n  1. Royal \n  2. Elite \n  3. Ordinary ");
                 printf("\n Enter the room type : ");
                 scanf("%d",&r_choice);
                 switch(r_choice)
                 {
                    case 1  : check_avail(r_choice);
                              break;

                    case 2  : check_avail(r_choice);
                              break;

                    case 3  : check_avail(r_choice);
                              break;

                    default : printf("\n Please enter a valid choice ");
                              break;
                 }
                 break;

       default : printf("\n You have entered a wrong option : ");
                 break;
    }


}


void room_status(int j)
{
    if(j==1)
    {
     tot_room[j-1]=(tot_room[j-1]-exist_cust_r);
     printf("\n %d",tot_room[j-1]);
     if(((tot_room[j-1])>0)&&(tot_room[j-1])<=40)
     {
     printf("\n Room is available ");
     }
     new_customer();
     exist_cust_r=exist_cust_r+1;
     room_no=exist_cust_r;
     printf("\n Your room is booked & alloted room number is %d : ",room_no);
     room[room_alot].room_number=room_no;
     room_alot++;
    }
    else if(j==2)
    {
     tot_room[j-1]=(tot_room[j-1]-exist_cust_e);
     if(((tot_room[j-1])>0)&&(tot_room[j-1])<=80)
     {
     printf("\n Room is available ");
     }
     exist_cust_e=exist_cust_e+1;
     room_no=exist_cust_e+40;
     new_customer();
     printf("\n Your room is booked & alloted room number is : %d ",room_no);
     room[room_alot].room_number=room_no;
     room_alot++;
    }
     else if(j==3)
     {
     tot_room[j-1]=(tot_room[j-1]-exist_cust_o);
     if(((tot_room[j-1])>0)&&(tot_room[j-1])<=80)
     {
     printf("\n Room is available ");
     }
     exist_cust_o=exist_cust_o+1;
     room_no=exist_cust_o+120;
     new_customer();
     printf("\n Your room is booked & alloted room number is %d : ",room_no);
     room[room_alot].room_number=room_no;
     room_alot++;
    }
}



void check_avail(int j)
{
    if(j==1)
    {
     tot_room[j-1]=(tot_room[j-1]-exist_cust_r);
     if(((tot_room[j-1])>0)&&(tot_room[j-1])<=40)
    {
         printf("\n Room is available ");
    }
    }
    else if(j==2)
    {
     tot_room[j-1]=(tot_room[j-1]-exist_cust_e);
     if(((tot_room[j-1])>0)&&(tot_room[j-1])<=80)
    {
         printf("\n Room is available ");
    }
    }
    else if(j==3)
    {
     tot_room[j-1]=(tot_room[j-1]-exist_cust_o);
     if(((tot_room[j-1])>0)&&(tot_room[j-1])<=80)
    {
         printf("\n Room is available ");
    }
    }
}


void cancel()
{
    int room_num,found=0,match=0;
    prrintf("Enter the room no to cancel");
    scanf("%d",&room_num);
    if(id<=1002)
    {
        for(i=0;i<3;i++)
        {
            if(room[i].room_number==room_num)
            {
                if(id==customer[i].customer_id)
                {
                    found=1;
                    printf("Your booking has been successfully canceled");
                }
            }
        }
    }
    else
    {
        for(i=0;i<2;i++)
        {
            if(room[i].room_number==room_num)
            {
                if(id==customer[i+3].customer_id)
                {
                    found=1;
                    printf("Your booking has been successfully canceled");
                }
            }
        }
    }
    if(found==0)
    {
        printf("Please enter the room number you have booked correctly")
    }

}




void staff()
{
    char user_name[10],password[10];
    printf("Enter your user name:");
    scanf("%s",&user_name);
    printf("Enter your password:");
    scanf("%s",&password);

}


