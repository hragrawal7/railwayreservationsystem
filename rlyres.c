#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<ctype.h>
int enterchoice()
{
    int choice,i;
    textcolor(YELLOW);
    gotoxy(48,1);
    printf("RAILWAY RESERVATION SYSTEM\n");

    for(i=1;i<=119;i++)
    {
        printf("-");

    }
    printf("\nSelect an option");
    printf("\n1-View Trains");
    printf("\n2-Book Tickets");
    printf("\n3-View Tickets");
    printf("\n4-Search Ticket No.");
    printf("\n5-View All Bookings");
    printf("\n6-View Train Bookings");
    printf("\n7-Cancel Ticket");
    printf("\n8-Cancel Train");
    printf("\n9-Quit");
    textcolor(LIGHTBLUE);
    printf("\n\nEnter choice:");
    scanf("%d",&choice);
    return choice;

}

void add_trains()
{
    FILE *fp;
    fp=fopen("D:\\myproject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={
            {"123","BPL","GWA",2100,1500},
            {"546","BPL","DEL",3500,2240},
            {"345","HBJ","AGR",1560,1135},
            {"896","HBJ","MUM",4500,3360},
        };
        fp=fopen("D:\\myproject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        //printf("File Saved Successfully!!!");
        fclose(fp);
    }
    else
    {
        //printf("File Already present\n");
        fclose(fp);
    }
}
void view_trains()
{
    Train tr;
    int i;
    textcolor(WHITE);
    printf("\t\tTRAIN NO.\t\tFROM\tTO\t\tFIRST AC FAIR\tSECOND AC FAIR\n");
    printf("\t    ");
    for(i=1;i<=84;i++)
    {
        printf("-");

    }

    //clrscr();
     FILE *fp;
     fp=fopen("D:\\myproject\\alltrains.dat","rb");

   /* for(i=1;i<=80;i++)
    {
        printf("-");

    }
    */
    textcolor(LIGHTBLUE);
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {

        printf("\n\t\t  %s\t\t\t%s\t%s\t\t  %d\t\t  %d",tr.train_no,tr.from,tr.to,tr.face_fare,tr.sac_fare);
    }
    fclose(fp);

    printf("\n\t    ");
    textcolor(WHITE);
    for(i=1;i<=84;i++)
    {
        printf("-");

    }
    textcolor(WHITE);
    printf("\n\n\n\nPress any Key to go back to return.......");
getch();
clrscr();
}
int check_train_no(char *trainno)
{
     FILE *fp;
     fp=fopen("D:\\myproject\\alltrains.dat","rb");

     Train tr;
     while(fread(&tr,sizeof(tr),1,fp)==1)
     {
         if(strcmp(trainno,tr.train_no)==0)
         {
             fclose(fp);
             return 1;
         }
     }
     fclose(fp);
     return 0;
}

int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
        return 0;

    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;

}
Passenger * get_passenger_details()
{

    int valid;
    int i;
    gotoxy(45,1);
    textcolor(WHITE);
    printf("Please Give us Passenger Details");
    gotoxy(100,3);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(10,7);
    textcolor(YELLOW);

    static Passenger psn;
    printf("Passenger Name:");
//    int valid;
    gotoxy(10,10);
    printf("Gender(M/F):");
    gotoxy(10,13);
    printf("Class(F-First Ac)(s-Second Ac):");
    gotoxy(10,16);
    printf("Age(1-110):");
    gotoxy(10,19);
    printf("Train No.:");
        gotoxy(10,22);
        printf("Mobile No.(10 Digits):");
        gotoxy(10,25);
        printf("Address:");
        //int valid=1;
    do
    {
        gotoxy(25,7);
        textcolor(LIGHTBLUE);
        fflush(stdin);
        fgets(psn.p_name,20,stdin);
        char *pos;
        pos=strchr(psn.p_name,'\n');
        *pos='\0';
        if(strcmp(psn.p_name,"0")==0)
        {

        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }


    }while(psn.p_name[0]=='\0');

    fflush(stdin);
    gotoxy(22,10);
    scanf("%c",&psn.gender);
    while((psn.gender!='M')&&(psn.gender!='F')&&(psn.gender!='f')&&(psn.gender!='m')||(psn.gender=='0'))
    {

        if(psn.gender=='0')
        {
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
        else
        {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please enter (M/F)");
        textcolor(LIGHTBLUE);
        getch();
        gotoxy(1,30);
        for(i=1;i<=18;i++)
        printf(" ");
        gotoxy(22,10);
        printf(" ");
        fflush(stdin);
        scanf("%c",&psn.gender);
        //gotoxy(22,10);
        }


    }
    fflush(stdin);
    gotoxy(41,13);
    scanf("%c",&psn.p_class);
    while((psn.p_class!='F')&&(psn.p_class!='S')&&(psn.p_class!='f')&&(psn.p_class!='s')||(psn.p_class=='0'))
    {

        if(psn.p_class=='0')
        {
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
        else
        {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please enter (F/S)");
        textcolor(LIGHTBLUE);
        getch();
        gotoxy(1,30);
        for(i=1;i<=18;i++)
        printf(" ");
        gotoxy(41,13);
        printf(" ");
        fflush(stdin);
        scanf("%c",&psn.p_class);
        //gotoxy(22,10);
        }
    }

    fflush(stdin);
    gotoxy(21,16);
    scanf("%d",&psn.age);
    while((psn.age<=1)||(psn.age>=111)||(psn.age==0))
    {

        if(psn.age==0)
        {
        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        return NULL;
        }
        else
        {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Please enter a Valid Age");
        textcolor(LIGHTBLUE);
        getch();
        gotoxy(1,30);
        for(i=1;i<=25;i++)
        printf(" ");
        gotoxy(21,16);
        printf("   ");
        gotoxy(21,16);
        fflush(stdin);
        scanf("%d",&psn.age);
        }
    }
    do
    {
         gotoxy(20,19);
        fflush(stdin);
        fgets(psn.train_no,20,stdin);
        char *pos1;
        pos1=strchr(psn.train_no,'\n');
        *pos1='\0';
    if(strcmp(psn.train_no,"0")==0)
    {

        textcolor(LIGHTRED);
        printf("Reservation Cancelled!!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    valid=check_train_no(psn.train_no);
    if(valid==0)
    {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Invalid Train  no.");
        textcolor(LIGHTBLUE);
        getch();
        gotoxy(1,30);
        for(i=1;i<=25;i++)
        printf(" ");
        gotoxy(20,19);
        printf("      ");
        gotoxy(20,19);
        valid=0;

    }
    }while(valid==0);
    fflush(stdin);
    gotoxy(32,22);
    do
    {
            fflush(stdin);
           scanf("%s",psn.mob_no);

            if(strcmp(psn.mob_no,"0")==0)
            {
                textcolor(LIGHTRED);
                printf("Reservation Cancelled!!");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            valid=check_mob_no(psn.mob_no);
            if(valid==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,30);
                printf("Error!Invaid Mobile No");
                textcolor(LIGHTBLUE);
                getch();
                gotoxy(1,30);
                for(i=1;i<=25;i++)
                printf(" ");
                gotoxy(32,22);
                printf("\t\t\t\t");
                gotoxy(32,22);
                valid=0;
            }
        }while(valid==0);
        fflush(stdin);
        gotoxy(19,25);
        gets(psn.p_add);
        return &psn;
    }

int get_booked_ticket_count(char *train_no,char tc)
{
        FILE *fp;
        fp=fopen("D:\\myproject\\allbookings.dat","rb");
        if(fp==NULL)
            return 0;

        Passenger pr;
        int count=0;
        while(fread(&pr,sizeof(pr),1,fp)==1)
        {
                if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
                    ++count;
        }
        fclose(fp);
        return count;
}
int last_ticket_no()
{
    FILE *fp;
    fp=fopen("D:\\myproject\\allbookings.dat","rb");
    Passenger pr;
    if(fp==NULL)
        return 0;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}
int book_ticket(Passenger psn)
{
    int x=0;
    x=get_booked_ticket_count(psn.train_no,psn.p_class);
    if(x==2)
    {
        clrscr();
        textcolor(LIGHTMAGENTA);
        gotoxy(4,8);
        printf("Sorry!! No rooms are available yet....");
        printf("\nPress any key to continue...");
        getch();
        return 0;
    }
    else
    {
        int last;
        last=last_ticket_no()+1;
        psn.ticketno=last;
        FILE *fp;
        fp=fopen("d:\\myproject\\allbookings.dat","ab");
        fwrite(&psn,sizeof(psn),1,fp);
        fclose(fp);
        //clrscr()
        return psn.ticketno;

    }
}
void view_all_bookings()
{
    int i,x=7,y=1;
    Passenger pr;
    textcolor(LIGHTGREEN);
    gotoxy(x,y);
    printf("TRAIN NO.");
    gotoxy(x+15,y);
    printf("PASSENGER NAME");
    gotoxy(x+35,y);
    printf("GENDER");
    gotoxy(x+45,y);
    printf("CLASS");
    gotoxy(x+55,y);
    printf("AGE");
    gotoxy(x+61,y);
    printf("MOBILE NO.");
    gotoxy(x+75,y);
    printf("ADDRESS");
    gotoxy(x+85,y);
    printf("TICKET NO.");
    gotoxy(4,2);
    for(i=5;i<=115;i++)
    {
        printf("-");

    }
    FILE *fp;
    fp=fopen("D:\\myproject\\allbookings.dat","rb");
    textcolor(LIGHTCYAN);
    y++;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
            y++;
            gotoxy(x+2,y);
            printf("%s",pr.train_no);
            gotoxy(x+17,y);
            printf("%s",pr.p_name);
            gotoxy(x+37,y);
            printf("%c",pr.gender);
            gotoxy(x+47,y);
            printf("%c",pr.p_class);
            gotoxy(x+55,y);
            printf("%d",pr.age);
            gotoxy(x+60,y);
            printf("%s",pr.mob_no);
            gotoxy(x+75,y);
            printf("%s",pr.p_add);
            gotoxy(x+90,y);
            printf("%d",pr.ticketno);

    }
    fclose(fp);
    textcolor(LIGHTBLUE);
    printf("\n\nPress any key to continue...");
    getch();

}
void view_ticket(int n)
{
    Passenger psn;
    Train tr;
    char str[20];
    char ch;
    FILE *fp;
    int flag=0;
    fp=fopen("D:\\myproject\\allbookings.dat","rb");
    clrscr();
    textcolor(WHITE);
    printf("DETAILS ARE::");
    while(fread(&psn,sizeof(psn),1,fp)==1)
    {
        if(n==psn.ticketno)
        {
            textcolor(LIGHTMAGENTA);
            printf("\n\n\nNAME: ");
            textcolor(WHITE);
            printf("%s",psn.p_name);
            textcolor(LIGHTMAGENTA);
            printf("\nGENDER:");
            textcolor(WHITE);
            printf("%c",psn.gender);
            textcolor(LIGHTMAGENTA);
            printf("\nTRAIN NO.:");
            textcolor(WHITE);
            printf("%s",psn.train_no);
            textcolor(LIGHTMAGENTA);
            printf("\nCLASS:");
            textcolor(WHITE);
            printf("%c",psn.p_class);
            textcolor(LIGHTMAGENTA);
            printf("\nADDRESS:");
            textcolor(WHITE);
            printf("%s",psn.p_add);
            textcolor(LIGHTMAGENTA);
            printf("\nAGE:");
            textcolor(WHITE);
            printf("%d",psn.age);
            textcolor(LIGHTMAGENTA);
            printf("\nMo.No.:");
            textcolor(WHITE);
            printf("%d",psn.mob_no);
            textcolor(LIGHTMAGENTA);
            printf("\nTICKET No.:");
            textcolor(WHITE);
            printf("%d",psn.ticketno);
            textcolor(LIGHTMAGENTA);
            strcpy(str,psn.train_no);
            ch=psn.p_class;
            flag=1;
        }
    }
    fclose(fp);
    fp=fopen("D:\\myproject\\alltrains.dat","rb");
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(str,tr.train_no)==0)
        {
            printf("\nFrom:%s",tr.from);
            printf("\nTo:%s",tr.to);
            if(ch=='F'||ch=='f')
            {
                textcolor(LIGHTMAGENTA);
                printf("\nFair:");
                textcolor(WHITE);
                printf("%d",tr.face_fare);
            }
            else
            {
                textcolor(LIGHTMAGENTA);
                printf("\nFair:");
                textcolor(WHITE);
                printf("%d",tr.sac_fare);
            }

        }
    }
    fclose(fp);
    textcolor(LIGHTCYAN);
    if(flag==0)
    {
        printf("\n\tSorry!!! No ticket available in this ticket no.");
       // exit(0);
    }
    printf("\n\n\n\n\n\tPress any key to continue");
    getch();
}
void search_ticket()
{
    char mono[11];
    int valid=0;
    Passenger psn;
    fflush(stdin);
    textcolor(LIGHTCYAN);
    printf("Enter mobile no.");
    gets(mono);
    FILE *fp;
    fp=fopen("D:\\myproject\\allbookings.dat","rb");
    while(fread(&psn,sizeof(psn),1,fp)==1)
    {
        if(strcmp(psn.mob_no,mono)==0)
        {
                textcolor(LIGHTGREEN);
                printf("\n Train no. is %s",psn.train_no);
                //textcolor(LIGHTMAGENTA);
                printf("\n Ticket no. is %d\n\n",psn.ticketno);
                valid=1;
        }
    }
    textcolor(LIGHTCYAN);
    if(valid==0)
    {
        printf("Ticket not  Booked from this mo.no.");
    }
    printf("\n\n\n\nPress any key to continue....");
    getch();
}
void train_bookings()
{
   //fflush(stdin);
   char trainno[10];
   printf("\nEnter train no.");
   fflush(stdin);
   fgets(trainno,20,stdin);
   char *pos;
   pos=strchr(trainno,'\n');
    *pos='\0';
   //fflush(stdin);
   //gets(trainno);
   clrscr();
   view_booking(trainno);
}
void view_booking(char *train_no)
{

    Passenger psn;
    int flag=0;
    FILE *fp;
    int x=7,y=1;
    fp=fopen("D:\\myproject\\allbookings.dat","rb");
    textcolor(LIGHTGREEN);
    gotoxy(x,y);
    printf("TICKET NO.");
    gotoxy(x+15,y);
    printf("PASSENGER NAME");
    gotoxy(x+35,y);
    printf("GENDER");
    gotoxy(x+45,y);
    printf("CLASS");
    gotoxy(x+55,y);
    printf("AGE");
    gotoxy(x+65,y);
    printf("MOBILE NO.");
    textcolor(LIGHTMAGENTA);
    while(fread(&psn,sizeof(psn),1,fp)==1)
    {
        if(strcmp(psn.train_no,train_no)==0)
        {
            y++;
            flag=1;
            gotoxy(x+2,y);
            printf("%d",psn.ticketno);
            gotoxy(x+17,y);
            printf("%s",psn.p_name);
            gotoxy(x+37,y);
            printf("%c",psn.gender);
            gotoxy(x+47,y);
            printf("%c",psn.p_class);
            gotoxy(x+55,y);
            printf("%d",psn.age);
            gotoxy(x+65,y);
            printf("%d",psn.mob_no);
        }
    }
    if(flag==0)
    {
        printf("\nNo Tickets in this room");
    }
    textcolor(LIGHTGREEN);
    printf("\n\nPress any key goto continue....");
    getch();
}
int accept_ticket_no()
{
    int ticket_no;
    gotoxy(80,1);
    printf("Press 0 for Cancel the process");
    gotoxy(1,1);
    printf("Enter ticket no.");

    scanf("%d",&ticket_no);
    //gotoxy(1,40);
    //printf("Press 0 for Cancel the process");
    while(ticket_no<0)
    {
        printf("Ticket no. should be Positive");
        gotoxy(10,30);
        printf("\t\t");
        printf("Enter ticket no.");
        scanf("%d",&ticket_no);
    }
    if(ticket_no==0)
    {

        textcolor(LIGHTRED);
        gotoxy(60,1);
         printf("Process has been cancelled!!!");
        printf("Press any key to continue...");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    return ticket_no;
}
void accept_train_no()
{
    int valid,result;
    char train_no[20];
    gotoxy(80,1);
    printf("Press 0 for Cancel the process");
    gotoxy(1,1);

    printf("Enter train no.");
    do
    {


    fflush(stdin);
    gets(train_no);

    //char *pos1;
    //pos1=strchr(train_no,'\n');
    //*pos1='\0';
    if(strcmp(train_no,"0")==0)
    {

        textcolor(LIGHTRED);
        printf("Process has been Cancelled!!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    valid=check_train_no(train_no);
    if(valid==0)
    {
        gotoxy(1,30);
        textcolor(LIGHTRED);
        printf("Invalid Train  no.");
        getch();
        gotoxy(1,30);
        //for(i=1;i<=25;i++)
        //printf(" ");
        gotoxy(16,1);
        printf("      ");
        gotoxy(16,1);
        valid=0;

    }
    }while(valid==0);
   result=cancel_train(train_no);
                        if(result==0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry!No tickets booked against train no %s",train_no);
                        }
                        else if(result==1)
                        {
                            textcolor(LIGHTGREEN);
                            printf("Train no %s successfully cancelled!",train_no);
                        }
                        else
                        {
                            textcolor(WHITE);
                            printf("\nPress any key to go back to the main screen");
                        }
}
int cancel_ticket(int ticket_no)
{
    FILE *fp1=fopen("d://myproject//allbookings.dat","rb+");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("d:\\myproject\\temp.dat","wb+");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno!=ticket_no)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\myproject\\temp.dat");
    }
    else
    {
        remove("d:\\myproject\\allbookings.dat");
        rename("d:\\myproject\\temp.dat","d:\\myproject\\allbookings.dat");
    }
    return found;
}

int cancel_train(char *trainno)
{
     FILE *fp1=fopen("d://myproject//allbookings.dat","rb+");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("d:\\myproject\\temp.dat","wb+");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,trainno)!=0)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else
        {
            found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\myproject\\temp.dat");
    }
    else
    {
        remove("d:\\myproject\\allbookings.dat");
        rename("d:\\myproject\\temp.dat","d:\\myproject\\allbookings.dat");
    }
    return found;
}
