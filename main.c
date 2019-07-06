#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"rlyres.h"

int main()
{
    add_trains();
    int choice;
    Passenger *ptr;
    int n,result;
    int ticket_no;
    char *train;
    while(1)
    {
         choice=enterchoice();
         if(choice==9)
         {
             exit(0);
         }
             switch(choice)
             {
                 case 1:clrscr();
                        view_trains();
                        break;
                 case 2:clrscr();
                        printf("Please Wait...");
                        delay(2000);
                        //printf("\nPress any key to continue..");
                        //getch();
                        clrscr();
                        ptr=get_passenger_details();
                        clrscr();
                        if(ptr!=NULL)
                        {
                            int x;
                            x=book_ticket(*ptr);
                            clrscr();
                            textcolor(LIGHTCYAN);
                            if(x==0)
                            {
                                printf("Sorry! TIcket can not be booked....");
                            }
                            else
                            {
                                printf("Please Wait....");
                                delay(500);
                                printf("\n\nYour Ticket No. is %d",x);
                                printf("\nPress any key to continue..");
                                getch();

                            }
                            clrscr();

                        }

                        //clrscr();

                        break;
                 case 3:clrscr();
                        printf("Enter your ticket no.");
                        scanf("%d",&n);
                        view_ticket(n);
                        clrscr();
                        break;
                 case 4:clrscr();
                        search_ticket();
                        clrscr();
                        break;
                 case 5:clrscr();
                        view_all_bookings();
                        clrscr();
                        break;
                 case 6:clrscr();
                        train_bookings();
                        clrscr();
                        break;
                 case 7:clrscr();
                        ticket_no=accept_ticket_no();
                        if(ticket_no!=0)
                        {
                            result=cancel_ticket(ticket_no);
                            if(result==0)
                            {
                                textcolor(LIGHTRED);
                                printf("Sorry!No tickets booked against ticket no %d",ticket_no);
                            }
                            else if(result==1)
                            {
                                textcolor(LIGHTGREEN);
                                printf("Ticket no %d successfully cancelled!",ticket_no);
                            }
                            else
                            {
                                textcolor(WHITE);
                                printf("\nPress any key to go back to the main screen");
                            }
                        }
                        getch();
                        clrscr();

                        break;
                 case 8:clrscr();
                        accept_train_no();

                        getch();
                        clrscr();
                        break;
                 default:textcolor(LIGHTRED);
                        printf("Wrong Choice!Try Again");
                        getch();
                        clrscr();


         }

    }

    //switch(x)
    return 0;
}
