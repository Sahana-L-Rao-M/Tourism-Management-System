#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include <conio.h>
#include "header.h"

enum state{main_menu,login_system};
enum state currentwindow=main_menu;
char current_client[100];


int main()
{
    system("CLS");
    printf("\n\n\t\t\t\t\t MTS TOURISM \n");
    userprofile *hello=NULL;
    char choice1,choice2;
    hello=InitializeListing(hello);
    while (1)
    {

        if(currentwindow==main_menu)
        {

            printf("\n\t\t\t\tAdd User - 1\n\t\t\t\tLogin User - 2\n\t\t\t\tExit - 3\n\n\t\t\t\tEnter:");
	    fflush(stdin);
            scanf("%c",&choice1);
	    fflush(stdin);
            switch(choice1)
            {
                case '1':
                    hello=Adding_Client(hello);
                    break;
                case '2':
                    login_client(hello);
                    break;
                case '3':
                    exit(0);
                    break;
                default:
		
                    printf("Oops!Please enter a valid input at this stage\n");
		    break;
            }
	    if(choice1!='2')
	    {
	    	printf("\n\n\t\t\t\tRedirecting to Home page...");
	    	sleep(1);
	    	system("CLS");
            	printf("\n\t\t\t\t || MTS TOURISM ||\n");
	    }

        }
        else if(currentwindow==login_system)
        {
        	system("CLS");
		printf("\n\t\t\t\t || MTS TOURISM ||\n");
           	printf("\n\t\t\t\tBook Package - 1\n\t\t\t\tPrint Ticket - 2\n\t\t\t\tCancel Ticket - 3\n\t\t\t\tLogout User - 4\n\t\t\t\t\n");
	        fflush(stdin);
            	scanf("%c",&choice2);
	    	fflush(stdin);
           	switch(choice2)
            	{
               		case '1':
                   		booking_ticket(hello);
                    		system("PAUSE");
                    		system("CLS");
                    		break;
                	case '2':
                    		printing_ticket(hello);
                    		system("PAUSE");
                    		system("CLS");
                    		break;
                	case '3':
                    		cancelling_ticket(hello);
                    		system("PAUSE");
                    		system("CLS");
                    		break;
                	case '4':
                    		logout_client(hello);
                    		system("PAUSE");
                    		system("CLS");
                    		break;
                	default:
                    		printf("Not a valid input at this stage\n");
            }
        }
    }
	return 0;

}

                                                       /*     ---------- To Initialise List ----------     */

userprofile* InitializeListing(userprofile *hello)
{
    	userprofile* text,*petrol,temporary;
    	FILE *fileopen;
    	int counting_cooridantes=0,z;
    	float following;
    	fileopen=fopen("users.txt","r");

    	if(fileopen==NULL)
        	return NULL;

	if(fgetc(fileopen)==EOF)
       		return NULL;

    	rewind(fileopen);
	while(fscanf(fileopen,"%s %s %s %d %d",temporary.user_fname,temporary.user_password,temporary.user_place,&temporary.ticket_price,&temporary.user_numtick)!=EOF)
	{
		petrol=(userprofile*)malloc(sizeof(userprofile));
		strcpy(petrol->user_fname,temporary.user_fname);
		strcpy(petrol->user_password,temporary.user_password);
		strcpy(petrol->user_place,temporary.user_place);
		petrol->ticket_price=temporary.ticket_price;
		petrol->user_numtick=temporary.user_numtick;
		petrol->next=NULL;

		if(hello==NULL)
            		hello=text=petrol;
		else
		{
			hello->next=petrol;
			hello=petrol;
		}
	}
	fclose(fileopen);
    	return text;
}

                                                       /*     ---------- To Write the obtained info to FILE ----------     */

void WriteToFile(userprofile *hello)
{
    FILE *fileopen;
    fileopen=fopen("users.txt","w");
    while(hello!=NULL)
    {
        fprintf(fileopen,"%s %s %s %d %d\n",hello->user_fname,hello->user_password,hello->user_place,hello->ticket_price,hello->user_numtick);
        hello=hello->next;
    }
    fclose(fileopen);
}

                                                       /*     ---------- Adding New Client ----------     */

userprofile* Adding_Client(userprofile* hello)
{
    userprofile *trans;
    trans=hello;
    userprofile *newwonderers;
    newwonderers=(userprofile*)malloc(sizeof(userprofile));
    fflush(stdin);
    printf("Enter Username or Email\n");
    scanf("%s",newwonderers->user_fname);
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,newwonderers->user_fname))
        {
            printf("That email already exists\n");
            return trans;
        }
        hello=hello->next;
    }
    hello=trans;
    fflush(stdin);
    printf("Enter password(NOTE: backspace , delete , and all other keys are counted as passwords except ENTER):\n");
    int i=0;
    char ch;
    char pwd[30];
    while((ch=getch())!='\r')
    {
	pwd[i]=ch;
	i++;
	printf("*");
	fflush(stdin);
    }
    pwd[i]='\0';
    //scanf(" %[^\n]s",&newwonderers->user_password);
    strcpy(newwonderers->user_password,pwd);

    printf("\nRe-enter password(NOTE: backspace , delete , and all other keys are counted as passwords except ENTER):\n");
    fflush(stdin);
    int i1=0;
    char ch1;
    char pwd1[30];
    while((ch1=getch())!='\r')
    {
	pwd1[i1]=ch1;
	i1++;
	printf("*");
	fflush(stdin);
    }
    pwd1[i1]='\0';

    if(strcmp(pwd,pwd1)==0)
    {
    	newwonderers->next=NULL;
    	strcpy(newwonderers->user_place,"N/A");
    	newwonderers->ticket_price=0;
    	newwonderers->user_numtick=0;

    	if(hello==NULL)
    	{
        	hello=trans=newwonderers;
    	}
    		else
    	{
        	while(hello->next!=NULL)
        	{
        	    hello=hello->next;
        	}
        	hello->next=newwonderers;
    	}
    	WriteToFile(trans);
    	printf("\nAccount created!!");
   }
   else
   {
	printf("\nPassword miss-match!");
   }
    return trans;
}


                                                       /*     ---------- Login Existing User ----------     */

void login_client(userprofile* hello)
{
    char client_username[100];
    char client_password[100];
    fflush(stdin);
    printf("\n\n");
    printf("\t\tEnter Email/Username:\n\t\t");
    scanf("%s",client_username);
    fflush(stdin);
    printf("\n\t\tEnter Password(NOTE: backspace , delete , and all other keys are counted as passwords except ENTER):\n\t\t");
    //scanf(" %[^\n]s",client_password);
    int i=0;
    char ch;
    while((ch=getch())!='\r')
    {
	client_password[i]=ch;
	i++;
	printf("*");
	fflush(stdin);
    }
    client_password[i]='\0';
    while(hello!=NULL)
    {
        if((!strcmp(hello->user_fname,client_username)) && (!strcmp(hello->user_password,client_password)))
        {
            currentwindow=login_system;
            strcpy(current_client,client_username);

            printf("\n\t\tLogin successful!\n");
            system("PAUSE");
            return;
        }
        else if((!strcmp(hello->user_fname,client_username)) && (strcmp(hello->user_password,client_password)))
        {
            printf("\nPassword mismatch");
	    sleep(1);
	    system("CLS");
            return;
        }
        hello=hello->next;
    }
    printf("\nSorry, no such user record was found");
    sleep(1);
    system("CLS");
}

                                                       /*     ---------- SHOW BROCHURE : Includes function calls for description of Places ----------     */

void ShowBrochure(userprofile *hello)
{
	system("CLS");
    printf("\n\n\tPRICE LIST\n=============================\nA. Exotic Kashmir - P 15000\nB. Andaman Highlights - P 9000\nC. Kerala Special - P 6000\nD. Goa-Basic Break  - P 3000\n"
           "E. Temples of the South - P 22000\nF. Valleys of the North - P 22000\nG. Gujurat Lions v/s Rajasthan Royals  - P 10000\nH. Dubai to Europe - P 180000\nI. Thailand & Singapore- P 30000\nJ. Mauritius - P 28000\n");
	printf("\nChoose the package you would like to explore! (Ex: A  for Exotic Kashmir ,etc..)  -  ");
	char choice1;
	fflush(stdin);
	scanf("%c",&choice1);
	printf("\n");
	switch(choice1)
	{
		case 'A':package1();
			book_tick_continue(hello);
			break;
		case 'B':package2();
			book_tick_continue(hello);
			break;
		case 'C':package3();
			book_tick_continue(hello);
			break;
		case 'D':package4();
			book_tick_continue(hello);
			break;
		case 'E':package5();
			book_tick_continue(hello);
			break;
		case 'F':package6();
			book_tick_continue(hello);
			break;
		case 'G':package7();
			book_tick_continue(hello);
			break;
		case 'H':package8();
			book_tick_continue(hello);
			break;
		case 'I':package9(); 
			book_tick_continue(hello);
			break;
		case 'J':package10();
			book_tick_continue(hello);
			break;
		default:printf("Invalid choice!\n\t\t\t\t");
			system("PAUSE");
			ShowBrochure(hello);
			break;
	}
}

                                                       /*     ---------- BOOK TICKETS-Part 1-Function call to show brochure ----------     */



void booking_ticket(userprofile *hello)
{
    userprofile *trans=hello;
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }
    if(hello==NULL)
        return;
    if(hello->ticket_price!=0)
    {
        printf("You must cancel your previous ticket before buying a new one\n");
        return;
    }
    ShowBrochure(hello);
    
    return;
}


                                                       /*     ---------- BOOK TICKETS-Part 2-To continue booking/return to brochure/exit ----------     */

void book_tick_continue(userprofile *hello)
{
    userprofile *trans=hello;
    printf("\nEnter your choice:\n1.Book Ticket\n2.Get back to Brochure\n3.Exit\n");
    int price=0;
    fflush(stdin);
    int choice123;
    scanf("%d",&choice123);
    if(choice123==1)
    {
	int pricelist[]={15000,9000,6000,3000,22000,22000,10000,180000,30000,28000};
	fflush(stdin);
	char place[2];
	printf("Enter place (Example A for Exotic Kashmir etc..):");
	scanf("%s",place);
	//if(place>64 && place<75)
	if(strcmp(place,"A")==0 ||strcmp(place,"B")==0 ||strcmp(place,"C")==0 ||strcmp(place,"D")==0 ||strcmp(place,"E")==0 ||strcmp(place,"F")==0 ||strcmp(place,"G")==0 ||strcmp(place,"H")==0 ||strcmp(place,"I")==0 ||strcmp(place,"J")==0)
	{
		fflush(stdin);
		int choice;
		fflush(stdin);
		printf("\nWould You Like to Confirm Booking?\n[1] - Yes\n[2] - No\n");
		scanf("%d",&choice);
		if(choice!=1)	
			return;	
		char place1=place[0];
		price=pricelist[place1-65];

	
    		int num_tickets;
    		printf("Enter the number of tickets you want to book?\n");
    		scanf("%d",&num_tickets);
    		if(num_tickets==0)
        		return;
    		hello->user_numtick=num_tickets;
    		strcpy(hello->user_place,place);
    		hello->ticket_price=price;
    		hello->total=price*num_tickets;
    		WriteToFile(trans);
    		printf("Bookings Done!!\n");
    		system("PAUSE");
	}
	else
    	{
        	printf("That tour code doesn't exist\n");
		sleep(1);
   		ShowBrochure(hello);
    	}
    }
    else if(choice123==2)
    {
	ShowBrochure(hello);
	book_tick_continue(hello);
    }
    else if(choice123==3)
    	return;
    else
    {
	printf("Invalid choice!");
	booking_ticket(hello);
    }
}

                                                       /*     ---------- Printing Ticket ----------     */


void printing_ticket(userprofile *hello)
{
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }
    if(!strcmp(hello->user_place,"\0") || hello->ticket_price==0.0 || hello->user_numtick==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    FILE *fileopen;
    char filename[50];
    strcpy(filename,hello->user_fname);
    strcat(filename,"_ticket.txt");
    fileopen=fopen(filename,"w");
    if(fileopen==NULL)
    {
        printf("Problem opening the file\n");
        return;
    }
    if(fgetc(fileopen)==EOF)
    {
        fprintf(fileopen,"TOURISM TICKET\n===============\n\n");
    }
    fprintf(fileopen,"Email ID: %s\nTour Code: %s\nTicket Cost: P %d\nNumber of tickets: %d\nTotal Cost: P %d\n",hello->user_fname,hello->user_place,hello->ticket_price,hello->user_numtick,(hello->ticket_price)*(hello->user_numtick));
    printf("Your tickets have been booked.Details are as follows\n");
    fprintf(stdout,"Email ID: %s\nTour Code: %s\nTicket Cost: P %d\nNumber of tickets: %d\nTotal Cost: P %d\n",hello->user_fname,hello->user_place,hello->ticket_price,hello->user_numtick,(hello->ticket_price)*(hello->user_numtick));
    fclose(fileopen);
}

                                                       /*     ---------- Cancelling Ticket ----------     */


void cancelling_ticket(userprofile *hello)
{
    userprofile *trans=hello;
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }

    int flag=-1;

    if(hello==NULL)
        printf("No such user\n");

    if(strcmp(hello->user_place,"A")==0)
        flag++;
    else if(strcmp(hello->user_place,"B")==0)
        flag++;
    else if(strcmp(hello->user_place,"C")==0)
        flag++;
    else if(strcmp(hello->user_place,"D")==0)
        flag++;
    else if(strcmp(hello->user_place,"E")==0)
        flag++;
    else if(strcmp(hello->user_place,"F")==0)
        flag++;
    else if(strcmp(hello->user_place,"G")==0)
        flag++;
    else if(strcmp(hello->user_place,"H")==0)
        flag++;
    else if(strcmp(hello->user_place,"I")==0)
        flag++;
    else if(strcmp(hello->user_place,"J")==0)
        flag++;
    else
    {
        printf("You haven't booked a tour yet\n");
        return;
    }
    if(flag==0)
    {
        printf("Your ticket has been successfully cancelled\nA refund of P %d for Tour Code %s for %d tickets will soon be made to your original source of purchase\n",hello->total,hello->user_place,hello->user_numtick);
        strcpy(hello->user_place,"N/A");
        hello->ticket_price=0;
        hello->user_numtick=0;
        WriteToFile(trans);
    }
}


                                                       /*     ---------- Logout ----------     */


void logout_client(userprofile* hello)
{
    if(currentwindow==main_menu || strcmp(current_client,"\0")==0)
    {
        printf("You must be logged in to logout\n");
        return;
    }
    strcpy(current_client,"\0");
    currentwindow=main_menu;
    printf("You have been successfully logged out\n");
}






