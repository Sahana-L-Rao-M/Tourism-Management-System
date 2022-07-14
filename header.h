typedef struct userprofile
{
    char user_fname[100];
    char user_password[30];
    char user_place[100];
    int ticket_price;
    int user_numtick;
    int total;
    struct userprofile *next;
}userprofile;

//Function definitions

userprofile* Adding_Client(userprofile*);

userprofile* InitializeListing(userprofile*);

void WriteToFile(userprofile*);

void login_client(userprofile*);

void ShowBrochure(userprofile*);
void booking_ticket(userprofile*);
void book_tick_continue(userprofile *hello);

void printing_ticket(userprofile*);

void cancelling_ticket(userprofile*);

void logout_client(userprofile*);

void exit_system();

//Definition of tours

void package1();
void package2();
void package3();
void package4();
void package5();
void package6();
void package7();
void package8();
void package9();
void package10();