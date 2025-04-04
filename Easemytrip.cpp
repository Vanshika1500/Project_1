#include <iostream>
#include <vector>
#include <string>
using namespace std;
//user panel forward declaration
class User;

//Destination classes forward declaration
class Delhi;
class Mumbai;

//Delhi hotels
class skyview;
class parktown;
class greendale;
//Mumbai hotels
class stemfield;
class pridestar;
class galaxyinn;

//userpanel
class User 
{
public:
    string username;
    string phoneNo;
    int numGuests;
    string paymentMode;
    static int nextUserID;
    int userID;

    User() {}

    void enterDetails() {
        cout << "Name: ";
        cin.ignore();
        getline(cin, username);

        cout << "Phone Number: ";
        getline(cin, phoneNo);

        cout << "Number of Guests: ";
        cin >> numGuests;
        cin.ignore();

       
    }

    void selectPaymentMode() {
        int choice;
        cout << "Select Payment Mode:" << endl;
        cout << "1. Credit Card" << endl;
        cout << "2. Debit Card" << endl;
        cout << "3. Cash" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                paymentMode = "Credit Card";
                break;
            case 2:
                paymentMode = "Debit Card";
                break;
            case 3:
                paymentMode = "Cash";
                break;
            default:
                cout << "Invalid choice. Defaulting to Cash." << endl;
                paymentMode = "Cash";
                break;
        }

        cin.ignore();
    }

    int getNextUserID() 
    {
        return nextUserID++;
    }

};

int User::nextUserID=1;

// Delhi hotel 1 class
class skyview:public User
{
    int rating = 3;
    double hotel_id = 1003;
    int room_no;
    vector<int> room_1;
    vector<int> room_2;
    vector<int> room_3;
    int room_fare1 = 2000;
    int room_fare2 = 4000;
    int room_fare3 = 7000;
    int totalrooms1 = 20;
    int totalrooms2 = 10;
    int totalrooms3 = 5;
    int n;//for room category preference
    int numDaysTrip=0;

public:
    void smenu()
    {
        cout << "\t**********WELCOME TO SKYVIEW HOTEL**********\t" << endl;
        cout<<"\t**********MAIN MENU**********\t"<<endl;
        cout << "*****category 1------------category 2---------------category 3*****" << endl;
        cout << " room-price:2000    |   room-price:3000       |   room-price:4000   " << endl;
        cout << "                    |       food&drink        |     food&drinks     " << endl;
        cout << "                    |                         | Access to spa & gym " << endl;
    }

    void sbook_room()
    {
       
        // press 1 for category 1,2 for category 2 and 3 for category 3
        cout<<"\t**********ROOM BOOKING PANEL**********\t"<<endl;
        cout << "Enter your preference of room category for room booking" << endl;
        cin >> n;
        cout << "Number of Days of Trip: ";
        cin >> numDaysTrip;
        switch (n)
        {
        case 1:
        {
            cout << "*****Category 1 selected*****"<<endl;
            User ob1;
            ob1.enterDetails();
            ob1.selectPaymentMode();
            userID=ob1.getNextUserID();
            cout << "*****Enter no. of rooms to be booked*****"<<endl;
            cin >> room_no;
            int count = room_1.size();
            if (count + room_no < totalrooms1)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_1.push_back(userID+i); // pushing room id
                }
                cout<<"Room booked sucessfully"<<endl;
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****"<< endl;
            }
            break;
        }

        case 2:
        {
            cout << "*****Category 2 selected*****" << endl;
            User ob2;
            ob2.enterDetails();
            ob2.selectPaymentMode();
            userID=ob2.getNextUserID();
            cout << "*****Enter no. of rooms to be booked*****" << endl;
            cin >> room_no;
            int count = room_2.size();
            if (count + room_no < totalrooms2)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_2.push_back(userID+i); // pushing room id
                }
                cout<<"Room booked sucessfully"<<endl;
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 3:
        {
            cout << "*****Category 3 selected*****" << endl;
            User ob3;
            ob3.enterDetails();
            ob3.selectPaymentMode();
            userID=ob3.getNextUserID();
            cout << "*****Enter no. of rooms to be booked*****" << endl;
            cin >> room_no;
            int count = room_3.size();
            if (count + room_no < totalrooms3)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_3.push_back(userID+i); 
                }
                cout<<"Room booked sucessfully"<<endl;
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }
        }
    }
    void sfinal_bill(int n, int numDaysTrip, int room_no)
{
    cout<<"\t*****FINAL BILL\t*****"<<endl;
    
    if(n==1)
    {   cout<<"userid: "<<userID<<endl;
        double final_bill = numDaysTrip * room_fare1 * room_no; // when using category 1 room fare for final bill
        cout << "The total bill of customer is:" << final_bill << endl;
    }
    else if(n==2)
    {
        double final_bill = numDaysTrip * room_fare2 * room_no; // when using category 2 room fare for final bill
        cout << "The total bill of customer is:" << final_bill << endl;
    }
    else if(n==3)
    {
        double final_bill = numDaysTrip * room_fare3 * room_no; // when using category 2 room fare for final bill
        cout << "The total bill of customer is:" << final_bill << endl;
    }
}

   
     skyview()
    {
        cout << "\t*****Your budget lies in the range of " << rating << " star hotel*****\t" << endl;
        smenu();
        sbook_room();
        sfinal_bill(n, numDaysTrip, room_no);

       
    }
};

// Delhi hotel 2 class
class parktown:public User
{
    int rating = 5;
    double hotel_id = 1005;
    int room_no;
    vector<int> room_1;
    vector<int> room_2;
    vector<int> room_3;
    int room_fare1 = 4000;
    int room_fare2 = 5000;
    int room_fare3 = 7000;
    int totalrooms1 = 20;
    int totalrooms2 = 10;
    int totalrooms3 = 10;
    int n;//for room category preference
    int numDaysTrip;

public:
   
    void pmenu()
    {
        cout << "\t**********WELCOME TO PARKTOWN HOTEL**********\t" << endl;
        cout<<"\t**********MAIN MENU FOR ROOM BOOKING**********\t"<<endl;
        cout << "category 1---------category 2---------category 3" << endl;
        cout << " room-price:4000    |     room-price:5000     |   room-price:7000   " << endl;
        cout << "  food&drink        |      Gamezone acces     |     food&drinks     " << endl;
        cout << "                    |        food&drink       |     Gamezone access " << endl;
        cout << "                    |                         | Access to spa & gym " << endl;
    }

    void pbook_room()
    {
        // press 1 for category 1,2 for category 2 and 3 for category 3
        cout << "Enter your preference of room category for room booking" << endl;
        cin >> n;
        cout << "Number of Days of Trip: ";
        cin >> numDaysTrip;
        switch (n)
        {
        case 1:
        {
            cout << "*****Category 1 selected*****" << endl;
            User ob1;
            ob1.enterDetails();
            ob1.selectPaymentMode();
            userID=ob1.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_1.size();
            if (count + room_no < totalrooms1)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_1.push_back(userID+i); // Assuming you're pushing room numbers
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 2:
        {
            cout << "*****Category 2 selected*****" << endl;
            User ob2;
            ob2.enterDetails();
            ob2.selectPaymentMode();
            userID=ob2.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_2.size();
            if (count + room_no < totalrooms2)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_2.push_back(userID+i); //  pushing id
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 3:
        {
            cout << "*****Category 3 selected*****" << endl;
            User ob3;
            ob3.enterDetails();
            ob3.selectPaymentMode();
            userID=ob3.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_3.size();
            if (count + room_no < totalrooms3)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_3.push_back(userID+i); //  pushing id
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }
        }
    }

    void pfinal_bill(int n, int numDaysTrip, int room_no)
    {
         if(n==1)
         {
            double final_bill = numDaysTrip* room_fare1*room_no; // when using category 1 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;}
        else if(n==2)
        {
            double final_bill = numDaysTrip* room_fare2*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
        else if(n==3)
        {
            double final_bill = numDaysTrip* room_fare3*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
    }
    parktown()
    {
        cout << "\t**********Your budget lies in the range of " << rating << " star hotel**********\t" << endl;
        pmenu();
        pbook_room();
       pfinal_bill( n, numDaysTrip, room_no);
    }

};

//Delhi hotel 3 class
class greendale:public User
{
    int rating = 7;
    double hotel_id = 1007;
    int room_no;
    vector<int> room_1;
    vector<int> room_2;
    vector<int> room_3;
    int room_fare1 = 4000;
    int room_fare2 = 5000;
    int room_fare3 = 7000;
    int totalrooms1 = 20;
    int totalrooms2 = 30;
    int totalrooms3 = 30;
    int n;
    int numDaysTrip;

public:
    
    void gmenu()
    {
        cout << "\t**********WELCOME TO GREENDALE HOTEL**********\t" << endl;
        cout << "*****category 1--------------category 2---------------category 3*****" << endl;
        cout << " room-price:4000    |     room-price:5000     |   room-price:7000   " << endl;
        cout << "  Food&Drinks       |       food&drink        |     food&drinks     " << endl;
        cout << "  Gamezone access   |    Gamezone access      |     Gamezone access " << endl;
        cout << "                    |     Spa & Gym access    |  Spa & Gym access   " << endl;
        cout << "                    |                         |      zoom car       " << endl;
        cout << "                    |                         |      Home theatre   " << endl;
    }

    void gbook_room()
    {
        // press 1 for category 1,2 for category 2 and 3 for category 3
        cout << "Enter your preference of room category for room booking" << endl;
        cin >> n;
        cout << "Number of Days of Trip: ";
        cin >> numDaysTrip;
        switch (n)
        {
        case 1:
        {
            cout << "*****Category 1 selected*****" << endl;
            User ob1;
            ob1.enterDetails();
            ob1.selectPaymentMode();
            userID=ob1.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_1.size();
            if (count + room_no < totalrooms1)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_1.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 2:
        {
            cout << "*****Category 2 selected*****" << endl;
            User ob2;
            ob2.enterDetails();
            ob2.selectPaymentMode();
            userID=ob2.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_2.size();
            if (count + room_no < totalrooms2)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_2.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 3:
        {
            cout << "*****Category 3 selected*****"<<endl;
            User ob3;
            ob3.enterDetails();
            ob3.selectPaymentMode();
            userID=ob3.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_3.size();
            if (count + room_no < totalrooms3)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_3.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }
        }
    }

    void gfinal_bill(int n, int numDaysTrip, int room_no)
    {
        if(n==1)
        {
            double final_bill = numDaysTrip* room_fare1*room_no; // when using category 1 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;}
        else if(n==2)
        {
            double final_bill = numDaysTrip* room_fare2*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
        else if(n==3)
        {
            double final_bill = numDaysTrip* room_fare3*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
     }
    greendale()
    {
        cout << "Your budget lies in the range of " << rating << " star hotel" << endl;
        gmenu();
        gbook_room();
        gfinal_bill( n,  numDaysTrip, room_no);
    }

};

// Mumbai hotel 1 class
class stemfield:public User
{
    int rating = 3;
    double hotel_id = 1103;
    int room_no;
    vector<int> room_1;
    vector<int> room_2;
    vector<int> room_3;
    int room_fare1 = 2000;
    int room_fare2 = 4000;
    int room_fare3 = 7000;
    int totalrooms1 = 20;
    int totalrooms2 = 10;
    int totalrooms3 = 5;
    int n;//for room category preference
    int numDaysTrip;

public:
    void smenu()
    {
        cout << "\t**********WELCOME TO STEMFIELD HOTEL**********\t" << endl;
        cout<<"\t**********MAIN MENU**********\t"<<endl;
        cout << "*****category 1------------category 2---------------category 3*****" << endl;
        cout << " room-price:2000    |   room-price:3000       |   room-price:4000   " << endl;
        cout << "                    |       food&drink        |     food&drinks     " << endl;
        cout << "                    |                         | Access to spa & gym " << endl;
    }

    void sbook_room()
    {
        // press 1 for category 1,2 for category 2 and 3 for category 3
        cout<<"\t**********ROOM BOOKING PANEL**********\t"<<endl;
        cout << "Enter your preference of room category for room booking" << endl;
        cin >> n;
        cout << "Number of Days of Trip: ";
        cin >> numDaysTrip;
        switch (n)
        {
        case 1:
        {
            cout << "*****Category 1 selected*****"<<endl;
            User ob1;
            ob1.enterDetails();
            ob1.selectPaymentMode();
            userID=ob1.getNextUserID();
            cout << "*****Enter no. of rooms to be booked*****"<<endl;
            cin >> room_no;
            int count = room_1.size();
            if (count + room_no < totalrooms1)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_1.push_back(userID+i);
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****"<< endl;
            }
            break;
        }

        case 2:
        {
            cout << "*****Category 2 selected*****" << endl;
            User ob2;
            ob2.enterDetails();
            ob2.selectPaymentMode();
            userID=ob2.getNextUserID();
            cout << "*****Enter no. of rooms to be booked*****" << endl;
            cin >> room_no;
            int count = room_2.size();
            if (count + room_no < totalrooms2)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_2.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 3:
        {
            cout << "*****Category 3 selected*****" << endl;
            User ob3;
            ob3.enterDetails();
            ob3.selectPaymentMode();
            userID=ob3.getNextUserID();
            cout << "*****Enter no. of rooms to be booked*****" << endl;
            cin >> room_no;
            int count = room_3.size();
            if (count + room_no < totalrooms3)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_3.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }
        }
    }

    void sfinal_bill(int n, int numDaysTrip, int room_no)
    {
        if(n==1)
        {
            double final_bill = numDaysTrip* room_fare1*room_no; // when using category 1 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;}
        else if(n==2)
        {
            double final_bill = numDaysTrip* room_fare2*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
        else if(n==3)
        {
            double final_bill = numDaysTrip* room_fare3*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
    }
     stemfield()
    {
        cout << "\t*****Your budget lies in the range of " << rating << " star hotel*****\t" << endl;
        smenu();
        sbook_room();
       sfinal_bill(n, numDaysTrip,  room_no);
    }
};

// Mumbai hotel 2 class
class pridestar:public User
{
    int rating = 5;
    double hotel_id = 1105;
    int room_no;
    vector<int> room_1;
    vector<int> room_2;
    vector<int> room_3;
    int room_fare1 = 4000;
    int room_fare2 = 5000;
    int room_fare3 = 7000;
    int totalrooms1 = 20;
    int totalrooms2 = 10;
    int totalrooms3 = 10;
    int n;//for room category preference
    int numDaysTrip;

public:
   
    void pmenu()
    {
        cout << "\t**********WELCOME TO PRIDESTAR HOTEL**********\t" << endl;
        cout<<"\t**********MAIN MENU FOR ROOM BOOKING**********\t"<<endl;
        cout << "category 1---------category 2---------category 3" << endl;
        cout << " room-price:4000    |     room-price:5000     |   room-price:7000   " << endl;
        cout << "  food&drink        |      Gamezone acces     |     food&drinks     " << endl;
        cout << "                    |        food&drink       |     Gamezone access " << endl;
        cout << "                    |                         | Access to spa & gym " << endl;
    }

    void pbook_room()
    {
        // press 1 for category 1,2 for category 2 and 3 for category 3
        cout << "Enter your preference of room category for room booking" << endl;
        cin >> n;
        cout << "Number of Days of Trip: ";
        cin >> numDaysTrip;
        switch (n)
        {
        case 1:
        {
            cout << "*****Category 1 selected*****" << endl;
            User ob1;
            ob1.enterDetails();
            ob1.selectPaymentMode();
            userID=ob1.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_1.size();
            if (count + room_no < totalrooms1)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_1.push_back(userID+i);
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 2:
        {
            cout << "*****Category 2 selected*****" << endl;
            User ob2;
            ob2.enterDetails();
            ob2.selectPaymentMode();
            userID=ob2.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_2.size();
            if (count + room_no < totalrooms2)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_2.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 3:
        {
            cout << "*****Category 3 selected*****" << endl;
            User ob3;
            ob3.enterDetails();
            ob3.selectPaymentMode();
            userID=ob3.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_3.size();
            if (count + room_no < totalrooms3)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_3.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }
        }
    }

     void pfinal_bill(int n, int numDaysTrip, int room_no)
    {
         if(n==1)
         {
            double final_bill = numDaysTrip* room_fare1*room_no; // when using category 1 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;}
        else if(n==2)
        {
            double final_bill = numDaysTrip* room_fare2*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
        else if(n==3)
        {
            double final_bill = numDaysTrip* room_fare3*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
    }
    pridestar()
    {
        cout << "\t**********Your budget lies in the range of " << rating << " star hotel**********\t" << endl;
        pmenu();
        pbook_room();
        pfinal_bill(n, numDaysTrip,room_no);
    }

};

//Mumbai hotel 3 class
class galaxyinn:public User
{
    int rating = 7;
    double hotel_id = 1107;
    int room_no;
    vector<int> room_1;
    vector<int> room_2;
    vector<int> room_3;
    int room_fare1 = 4000;
    int room_fare2 = 5000;
    int room_fare3 = 7000;
    int totalrooms1 = 20;
    int totalrooms2 = 30;
    int totalrooms3 = 30;
    int n;
    int numDaysTrip;

public:
    
    void gmenu()
    {
        cout << "\t**********WELCOME TO Galaxyinn HOTEL**********\t" << endl;
        cout << "*****category 1--------------category 2---------------category 3*****" << endl;
        cout << " room-price:4000    |     room-price:5000     |   room-price:7000   " << endl;
        cout << "  Food&Drinks       |       food&drink        |     food&drinks     " << endl;
        cout << "  Gamezone access   |    Gamezone access      |     Gamezone access " << endl;
        cout << "                    |     Spa & Gym access    |  Spa & Gym access   " << endl;
        cout << "                    |                         |      zoom car       " << endl;
        cout << "                    |                         |      Home theatre   " << endl;
    }

    void gbook_room()
    {
        // press 1 for category 1,2 for category 2 and 3 for category 3
        cout << "Enter your preference of room category for room booking" << endl;
        cin >> n;
        cout << "Number of Days of Trip: ";
        cin >> numDaysTrip;
        switch (n)
        {
        case 1:
        {
            cout << "*****Category 1 selected*****" << endl;
            User ob1;
            ob1.enterDetails();
            ob1.selectPaymentMode();
            userID=ob1.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_1.size();
            if (count + room_no < totalrooms1)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_1.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 2:
        {
            cout << "*****Category 2 selected*****" << endl;
            User ob2;
            ob2.enterDetails();
            ob2.selectPaymentMode();
            userID=ob2.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_2.size();
            if (count + room_no < totalrooms2)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_2.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }

        case 3:
        {
            cout << "*****Category 3 selected*****"<<endl;
            User ob3;
            ob3.enterDetails();
            ob3.selectPaymentMode();
            userID=ob3.getNextUserID();
            cout << "Enter no. of rooms to be booked" << endl;
            cin >> room_no;
            int count = room_3.size();
            if (count + room_no < totalrooms3)
            {
                for (int i = 0; i < room_no; i++)
                {
                    room_3.push_back(userID+i); 
                }
            }
            else
            {
                cout << "*****Sorry! Rooms not available*****" << endl;
            }
            break;
        }
        }
    }

    void gfinal_bill(int n, int numDaysTrip, int room_no)
    {
        if(n==1)
        {
            double final_bill = numDaysTrip* room_fare1*room_no; // when using category 1 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;}
        else if(n==2)
        {
            double final_bill = numDaysTrip* room_fare2*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
        else if(n==3)
        {
            double final_bill = numDaysTrip* room_fare3*room_no; // when using category 2 room fare for final bill
            cout << "The total bill of customer is:" << final_bill << endl;
        }
     }
        galaxyinn()
    {
        cout << "Your budget lies in the range of " << rating << " star hotel" << endl;
        gmenu();
        gbook_room();
       gfinal_bill( n,numDaysTrip, room_no);
    }
};
//place class
class Delhi
{
    int days;
    double price;
    public:
    Delhi()
    {
        cout << "\t**********THANK YOU FOR CHOOSING DELHI AS DESTINATION**********\t" << endl;
        budget();
    }
    
    void budget()
    {
        cout << "\tEnter no of days for your trip\t" << endl;
        cin >> days;
        cout << "\tKindly enter budget for your hotel stay\t" << endl;
        cin >> price;
        try {
        if (price < days * 5000) {
            throw runtime_error("Budget too low");
        }

        if (price >= days * 5000 && price < days * 10000)
        {
             skyview obj1;
        }
        else if (price >= days * 10000 && price < days * 15000)
        {
             parktown obj2;
        }
        else if (price >= days * 15000)
        {
             greendale obj3;
        }
    }
    catch (const runtime_error& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }}
};
//place class
class Mumbai
{
    int days;
    double price;
    public:
    Mumbai()
    {
        cout << "\t**********THANK YOU FOR CHOOSING MUMBAI AS DESTINATION**********\t" << endl;
        budget();
    }
    
    void budget()
    {
        cout << "\tEnter no of days for your trip\t" << endl;
        cin >> days;
        cout << "\tKindly enter budget for your hotel stay\t" << endl;
        cin >> price;
        try {
        if (price < days * 5000) {
            throw runtime_error("Budget too low");
        }
        if (price >= days * 5000 && price < days * 10000)
        {
             stemfield obj1;
        }
        else if (price >= days * 10000 && price < days * 15000)
        {
             pridestar obj2;
        }
        else if (price >= days * 15000)
        {
             galaxyinn obj3;
        }
    }
    catch (const runtime_error& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }}
};

int main()
{
    cout<<"\t\tWELCOME TO EASE MY TRIP\t\t"<<endl;
    Delhi d1;
    cout<<"----------THANK YOU FOR CHOOSING OUR SERVICES WE HOPE YOU ENJOYED YOUR TRIP----------"<<endl;
    Mumbai m1;
    cout<<"----------THANK YOU FOR CHOOSING OUR SERVICES WE HOPE YOU ENJOYED YOUR TRIP----------"<<endl;
    return 0;
}



