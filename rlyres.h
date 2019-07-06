#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int face_fare;
    int sac_fare;
};

struct Passenger
{
    char p_name[20];
    char gender;
    char mob_no[10];
    int age;
    char train_no[20];
    char p_class;
    int ticketno;
    char p_add[40];
};


typedef struct Train Train;
typedef struct Passenger Passenger;


int enterchoice();
void add_trains();
void view_trains();
int book_ticket(Passenger);
int * get_ticket_no(char *);
void view_ticket(int);
void view_all_bookings();
void view_booking(char *);
int accept_ticket_no();
int cancel_ticket(int);
void accept_train_no();
int cancel_train(char *);
int check_train_no(char *);
Passenger *get_passenger_details();
int get_booked_ticket_count(char *,char);
int last_ticket_no();
int check_mob_no(char *);
void search_ticket();
void train_bookings();
int check_name(char *);
#endif // RLYRES_H_INCLUDED
