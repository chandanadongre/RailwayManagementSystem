#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;

void mainMenu();
void mainMenu2();
void firstPage();

class Date_Time{
    string x;
    string y;
    public:
        Date_Time()
        {
            x = __DATE__;
            y = __TIME__;
        }
        friend void print(Date_Time &x1);
};

void print(Date_Time &x1)
{
    cout << "Date: " << x1.x << "\t";
    cout << "Time: " << x1.y;
}

class Management
{
public:
    Management()
    {
        firstPage();
    }
};

void firstPage()
{
    cout << "\n___________________________________________________________________________________" << endl;
        cout << "____________________________WELCOME TO PESU RAILWAYS______________________________" << endl
             << endl;
    cout << "\t\t|\t 1. Admin Mode    \t|" << endl;
    cout << "\t\t|\t 2. User Mode     \t|" << endl;
    cout << "\t\t|\t 3. Exit          \t|" << endl;
    int choice;
    string id = "admin";
    string password = "admin";
    string eid, pass;

    cout << "Select: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "____________________________________________________________" << endl;
        cout << endl
             << "Enter Admin Username: ";
        cin >> eid;
        if (id == eid)
        {
            cout << "\nEnter Admin Password: ";
            cin >> pass;
            if (pass == password)
            {
                mainMenu();
                firstPage();
            }
            else
            {
                cout << "Password is wrong, Please try again!" << endl;
                firstPage();
            }
        }
        else
        {
            cout << "Entered Admin ID is wrong, Please Try Again!" << endl;
            firstPage();
        }
        break;
    }

    case 2:
    {
        cout << "\n_______________________________________________________________________________" << endl;
        cout << "WELCOME TO USER MODE" << endl;
        cout << "\t1. Create New Account" << endl;
        cout << "\t2. Login using existing account" << endl;
        cout << "\n\tSelect: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string uid, upass;
            cout << "__________________________________________________________________________________" << endl;
            cout << "______________________________CREATING NEW ACCOUNT_________________________________" << endl;
            cout << "\nEnter the New ID: ";
            cin >> uid;
            cout << "\nEnter Password: ";
            cin >> upass;

            fstream f("user.txt", ios::app);
            f << uid << " " << upass << endl;
            f.close();
            cout << "New User ID created!";
            cout << "Your User ID is " << uid << " and password is " << upass << endl;
            cout << "Use this as Login Credentials!" << endl
                 << endl;
            firstPage();

            break;
        }

        case 2:
        {
            cout << "__________________________________________________________________________________" << endl;
            cout << "__________________________________LOGING IN_______________________________________" << endl;

            string uid, upass;
            string cuid, cupass;

            cout << "\nEnter ID: ";
            cin >> uid;

            cout << "\nEnter Password: ";
            cin >> upass;

            fstream f1("user.txt", ios::in);
            while (!f1.eof())
            {
                f1 >> cuid >> cupass;
                cout << endl;
                if (uid == cuid && upass == cupass)
                {
                    cout << "\nLogin Sucessfull!!!" << endl;
                    cout << "\n_____________________________________________________________________________________" << endl;
                    mainMenu2();
                    firstPage();
                    return;
                }
            }

            cout << "Please enter correct details" << endl;
            cout << "\n_____________________________________________________________________________________" << endl;
            firstPage();

            break;
        }
        default:
            break;
        }
        break;
    }
    case 3:
    {

        cout << "___________________Thanks for using PESU Railways_____________________" << endl
             << endl;
        exit(0);
    }
    }
}

class Details
{
public:
    static string name[6], gender[6];
    int phoneNo;
    static int age[6];
    static string bp[6];
    static int cId[6];
    char arr[100];
    static int pnr;
    static int n;

    void information()
    {
        srand(time(NULL));
        pnr = 1000000000 + (rand() % 9000000000);
        cout << "\nYour PNR number is: " << pnr << endl;
        cout << "\nEnter the number of passengers: ";
        cin >> n;
        if (n > 6)
        {
            cout << "You can book tickets for only 6 passengers in a ticket!" << endl
                 << endl;
            mainMenu();
        }
        for (int i = 0; i < n; i++)
        {

            cout << "\n Enter the customer ID :";
            cin >> cId[i];

            cout << "\n Enter the Name :";
            cin >> name[i];
            cout << "\n Enter the age :";
            cin >> age[i];
            cout << "\n Enter Birth Preference :";
            cin >> bp[i];
            cout << "\n Gender:";
            cin >> gender[i];
        }
        cout << "Yours details are saved with us.\n";
        cout << "Your PNR number is: " << pnr << endl;
        cout << "Please use this PNR number to book tickets!" << endl;
    }
};

int Details::cId[6];
string Details::name[6];
string Details::gender[6];
int Details::pnr;
string Details::bp[6];
int Details::age[6];
int Details::n;

class registration : public Details
{
public:
    static int choice;
    int choice1;
    int back;
    static float charges;

    void trains()
    {
        string trainsN[] = {"DELHI", "KOLKATA", "JAIPUR", "MUMBAI"};

        for (int a = 0; a < 4; a++)
        {
            cout << (a + 1) << ".train to " << trainsN[a] << endl;
        }

        cout << "\nWELCOME TO THE RAIWAYS!" << endl;
        cout << "Press the number of the city you want to book the train:";
        cin >> choice;
        int f;

        switch (choice)
        {
        case 1:
        {
            cout << "_WELCOME TO DELHI_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the Trains \n"
                 << endl;

            cout << " 1.DEL-123 " << endl;
            cout << "\t08-01-2022  8:00AM  10hrs  3A-Rs.2100 2A-Rs.3100 1A-Rs.5200" << endl;
            cout << " 2.DEL-345 " << endl;
            cout << "\t09-01-2022  10:00AM  15hrs  3A-Rs.2300 2A-Rs.3300 1A-Rs.5400" << endl;
            cout << " 3.DEL-456" << endl;
            cout << "\t10-01-2022  11:00AM  20hrs  3A-Rs.2400 2A-Rs.3500 1A-Rs.5100" << endl;

            cout << "\n Select the Trains you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";
            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 2100;
                }
                else if (f == 2)
                {
                    charges = 3100;
                }
                else if (f == 1)
                {
                    charges = 5200;
                }

                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN DEL-123" << endl;

                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }

            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 2300;
                }
                else if (f == 2)
                {
                    charges = 3300;
                }
                else if (f == 1)
                {
                    charges = 5400;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN DEL-345" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 2400;
                }
                else if (f == 2)
                {
                    charges = 3500;
                }
                else if (f == 1)
                {
                    charges = 5100;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN DEL-456" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press 1 to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                exit;
            }

            break;
        }

        case 2:
        {
            cout << "_WELCOME TO KOLKATA_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the Trains \n"
                 << endl;
            cout << " 1.KOL-897 " << endl;
            cout << "\t20-01-2022  8:00PM  10hrs 3A-Rs.1800 2A-Rs.2600 1A-Rs.4400" << endl;
            cout << " 2.KOL-567 " << endl;
            cout << "\t21-01-2022  10:00PM  15hrs 3AC-Rs.1900 2AC-Rs.2200 1AC-Rs.4800" << endl;
            cout << " 3.KOL-789" << endl;
            cout << "\t22-01-2022  11:00PM  20hrs 3A-Rs.1700 2A-Rs.2100 1A-Rs.4500" << endl;

            cout << "\n Select the TRAINS you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";
            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1800;
                }
                else if (f == 2)
                {
                    charges = 2600;
                }
                else if (f == 1)
                {
                    charges = 4400;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN KOL-897" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1900;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 4800;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN KOL-567" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2100;
                }
                else if (f == 1)
                {
                    charges = 4500;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN KOL-789" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press 1 to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }

            break;
        }

        case 3:
        {
            cout << "_WELCOME TO JAIPUR_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the TRAINS \n"
                 << endl;

            cout << " 1.JAI-123 " << endl;
            cout << "\t17-01-2022  12:00AM  10hrs 3A-Rs.2200 2A-Rs.3200 1A-Rs.5300" << endl;
            cout << " 2.JAI-345 " << endl;
            cout << "\t18-01-2022  2:00PM 15hrs 3A-Rs.2300 2A-Rs.3300 1A-Rs.5400" << endl;
            cout << " 3.JAI-456" << endl;
            cout << "\t19-01-2022  4:00PM  20hrs 3A-Rs.2400 2A-Rs.3500 1A-Rs.5500" << endl;

            cout << "\n Select the TRAINS you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";

            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 2200;
                }
                else if (f == 2)
                {
                    charges = 3200;
                }
                else if (f == 1)
                {
                    charges = 5300;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN JAI-123" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 2300;
                }
                else if (f == 2)
                {
                    charges = 3300;
                }
                else if (f == 1)
                {
                    charges = 5400;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN JAI-345" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 2400;
                }
                else if (f == 2)
                {
                    charges = 3500;
                }
                else if (f == 1)
                {
                    charges = 5500;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN JAI-456" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press 1 to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }
            break;
        }

        case 4:
        {

            cout << "_WELCOME TO MUMBAI_\n"
                 << endl;
            cout << " your comfort is our priority , Enjoy the journey!" << endl;
            cout << " Following are the TRAINS \n"
                 << endl;

            cout << " 1.MUM-123 " << endl;
            cout << "\t04-09-2022  12:00AM  10hrs  3A-Rs.1500 2A-Rs.2200 1A-Rs.3700" << endl;
            cout << " 2.MUM-345 " << endl;
            cout << "\t05-09-2022  2:00PM 15hrs  3A-Rs.1600 2A-Rs.2300 1A-Rs.3800" << endl;
            cout << " 3.MUM-456" << endl;
            cout << "\t06-09-2022  4:00PM  20hrs  3A-Rs.1700 2A-Rs.2400 1A-Rs.3900" << endl;

            cout << "\n Select the TRAINS you want to book : ";
            cin >> choice1;
            cout << "\n Enter the AC class in which u want to travel : ";
            cin >> f;

            if (choice1 == 1)
            {
                if (f == 3)
                {
                    charges = 1500;
                }
                else if (f == 2)
                {
                    charges = 2200;
                }
                else if (f == 1)
                {
                    charges = 3700;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN MUM-123" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 2)
            {
                if (f == 3)
                {
                    charges = 1600;
                }
                else if (f == 2)
                {
                    charges = 2300;
                }
                else if (f == 1)
                {
                    charges = 3800;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN MUM-345" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else if (choice1 == 3)
            {
                if (f == 3)
                {
                    charges = 1700;
                }
                else if (f == 2)
                {
                    charges = 2400;
                }
                else if (f == 1)
                {
                    charges = 3900;
                }
                cout << "\n YOU HAVE SUCCESFULLY BOOKED THE TRAIN MUM-456" << endl;
                cout << " YOU CAN GO BACK TO MENU AND TAKE THE TICKET " << endl;
            }
            else
            {
                cout << " Invalid input,shifting to previous menu" << endl;
                trains();
            }

            cout << " press any key to go back to the main menu: " << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                mainMenu();
            }

            break;
        }
        default:
        {
            cout << " INVALID input,Shifting you to the main menu !" << endl;
            mainMenu();
            break;
        }
        }
    }
};
;

float registration::charges;
int registration::choice;

class ticket : public registration
{
public:
    void Bill()
    {
        string destination[4] = "";
        for (int i = 0; i < n; i++)
        {
            ofstream outf("tickets.txt", ios::app);
            {
                outf << pnr << "\t\t|";
                outf << cId[i] << "\t\t|";
                outf << name[i] << "\t|";
                outf << gender[i] << "\t|";

                if (registration::choice == 1)
                {
                    destination[i] = "Delhi";
                }

                else if (registration::choice == 2)
                {
                    destination[i] = "Chennai";
                }

                else if (registration::choice == 3)
                {
                    destination[i] = "Jaipur";
                }

                else if (registration::choice == 4)
                {
                    destination[i] = "Mumbai";
                }

                outf << "CHN"
                     << "\t\t|";
                outf << destination[i] << "\t\t|";
                outf << registration::charges << "\t|";
                outf << endl;
            }
            outf.close();
        }
        cout << "Total Cost: " << charges * n;
    }

    void database()
    {
        string destination[4] = "";

        for (int i = 0; i < n; i++)
        {
            ofstream outf("records.txt", ios::app);
            {
                outf << pnr << " ";
                outf << cId[i] << " ";
                outf << name[i] << " ";
                outf << gender[i] << " ";

                if (registration::choice == 1)
                {
                    destination[i] = "Delhi";
                }

                else if (registration::choice == 2)
                {
                    destination[i] = "Chennai";
                }

                else if (registration::choice == 3)
                {
                    destination[i] = "Jaipur";
                }

                else if (registration::choice == 4)
                {
                    destination[i] = "Mumbai";
                }

                outf << destination[i] << " ";
                outf << registration::charges;
                outf << endl;
            }
            outf.close();
        }
    }

void dispBill()
    {

        cout << "____XYZ Railways_____" << endl;
        cout << "____Tickets______" << endl;
        cout << "___________" << endl
             << endl;
        ;

        cout << "PNR Num" << endl;
        cout << "Customer ID" << endl;
        cout << "Name" << endl; 
        cout << "Gender" << endl;
        cout << "Boarding" << endl;
        cout << "Destination" << endl;
        cout << "Charge" << endl;

        ifstream ifs("tickets.txt", ios::in);
        {
            if (!ifs)
            {
                cout << "File error!" << endl;
            }

            while (!ifs.eof())
            {

                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }

        ifs.close();
    }

    void deletedata()
    {
        ticket obj;
        int w;
        cout << "Enter PNR no.:" << endl;
        cin >> w;
        string line;
        int cpnr, ccharges, ccid;
        string cname, cgen, cdest;

        ifstream myfile;
        ofstream temp;
        myfile.open("records.txt");
        temp.open("temp.txt");
        while (myfile >> cpnr >> ccid >> cname >> cgen >> cdest >> ccharges)
        {
            if (cpnr != w)
                temp << cpnr << " " << ccid << " " << cname << " " << cgen << " " << cdest << " " << ccharges << endl
                     << flush;
        }
        cout << "The record with the name " << w << " has been deleted if it exsisted" << endl;
        myfile.close();
        temp.close();
        remove("records.txt");
        getchar();
        rename("temp.txt", "records.txt");
    }
};

void mainMenu()
{
    int lchoice;
    int schoice, back;

    cout << "\t               XYZ Railways " << endl
         << endl;
    cout << "\t_________________________Main Menu_______________________" << endl;

    cout << "\t___________________________________________________________" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;

    cout << "\t|\t Press 1 To add the Customer Details    \t|" << endl;
    cout << "\t|\t Press 2 For Booking Train              \t|" << endl;
    cout << "\t|\t Press 3 For Ticket and Charges         \t|" << endl;
    cout << "\t|\t Press 4 To Cancel the Train            \t|" << endl;
    cout << "\t|\t Press 5 Exit!                           \t|" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t___________________________________________________________" << endl;

    cout << "Enter the Choice: ";
    cin >> lchoice;

    Details d;
    registration r;
    ticket t;
    switch (lchoice)
    {
    case 1:
    {
        char filename[] = "tickets.txt";
        remove(filename);

        cout << "____Customers___" << endl
             << endl;
        d.information();
        cout << "Press 1 to go back to the Main Menu" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }
        else
            exit;
        break;
    }

    case 2:
    {
        cout << "___Book a ticket in this section__" << endl
             << endl;
        r.trains();
        break;
    }

    case 3:
    {
        cout << "____Getting your Ticket___" << endl
             << endl;
        t.Bill();

        cout << "Your Ticket is printed, you can collect it" << endl
             << endl;

        cout << "Press 1 to display your ticket ";
        cin >> back;

        if (back == 1)
        {
            t.dispBill();
            cout << "Press 1 key to go back" << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }

            else
                exit;
        }

        break;
    }

    case 4:
    {
        t.deletedata();
        cout << "Press any key to go back" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }

        else
        {
            exit;
        }

        break;
    }

    case 5:
    {
        cout << endl
             << endl;

        return;
        break;
    }

    default:
    {
        cout << "Invalid Input, Please try again!" << endl
             << endl;
        mainMenu();
        break;
    }
    }
}

void mainMenu2()
{
    int lchoice;
    int schoice, back;

    cout << "\t               PESU Railways " << endl
         << endl;
    cout << "\t_________________________Main Menu_______________________" << endl;

    cout << "\t___________________________________________________________" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;

    cout << "\t|\t Press 1 To add the Customer Details    \t|" << endl;
    cout << "\t|\t Press 2 For Train Booking              \t|" << endl;
    cout << "\t|\t Press 3 For Ticket and Charges         \t|" << endl;
    cout << "\t|\t Press 4 To Cancel the Train            \t|" << endl;
    cout << "\t|\t Press 5 Exit                           \t|" << endl;
    cout << "\t|\t\t\t\t\t\t\t|" << endl;
    cout << "\t____________________________________________________________" << endl;

    cout << "Enter the Choice: ";
    cin >> lchoice;

    Details d;
    registration r;
    ticket t;

    switch (lchoice)
    {
    case 1:
    {
        char filename[] = "tickets.txt";
        remove(filename);

        cout << "____Customers___" << endl
             << endl;
        d.information();
        cout << "Press any key to go back to the Main Menu" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }
        else
        {
            exit;
        }
        break;
    }

    case 2:
    {
        cout << "___Book a ticket in this section__" << endl
             << endl;
        r.trains();
        break;
    }

    case 3:
    {
        cout << "____Getting your Ticket___" << endl
             << endl;
        t.Bill();

        cout << "Your Ticket is printed, you can collect it" << endl
             << endl;

        cout << "Press 1 to display your ticket ";
        cin >> back;

        if (back == 1)
        {
            t.dispBill();
            cout << "Press any key to go back" << endl;
            cin >> back;

            if (back == 1)
            {
                mainMenu();
            }
            else
            {
                exit;
            }
        }
        break;
    }

    case 4:
    {
        t.deletedata();
        cout << "Press any key to go back" << endl;
        cin >> back;

        if (back == 1)
        {
            mainMenu();
        }

        else
        {
            exit;
        }

        break;
    }
    case 5:
    {
        cout << endl
             << endl;

        firstPage();
        break;
    }
    default:
    {
        cout << "Invalid Input, Please try again!" << endl
             << endl;
        mainMenu();
        break;
    }
    }
};

int main()
{
    Date_Time dt;
    print(dt);
    Management mobj;
    return 0;
}