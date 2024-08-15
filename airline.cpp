#include <iostream>
#include <queue>
#include <array>
#include <typeinfo>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cctype>
using namespace std;

// Function to split a string into tokens based on a delimiter
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to display CSV data with left-aligned columns
void displayCSVData(const string& fileName) {
    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Error: Unable to open the CSV file." << endl;
        return;
    }

    string line;
    int lineCount = 0;

    while (getline(file, line)) {
        if (lineCount == 0) {
            // Print the header row with left-aligned columns
            cout << left << setw(10) << "FLIGHT" << setw(15) << "FROM" << setw(15) << "TO" << setw(10) << "LEAVE" << setw(10) << "ARRIVE"
                 << setw(10) << "COST" << setw(10) << "SEATS" << setw(10) << "BOOKED" << endl;
        } else {
            // Split the line into tokens
            vector<string> tokens = split(line, ',');

            // Display the data with left-aligned columns
            cout << left << setw(10) << tokens[0] << setw(15) << tokens[1] << setw(15) << tokens[2] << setw(10) << tokens[3] << setw(10) << tokens[4]
                 << setw(10) << tokens[5] << setw(10) << tokens[6] << setw(10) << tokens[7] << endl;
        }

        lineCount++;
    }

    file.close();
}


struct Passenger_Details
{
    string name;
    int age;
    string Contact;
    char Gender;
    int flight_number;
    int cost;
};

queue<struct Passenger_Details> myQueue;


    

int proper_age() {
    int age;

    while (true) {
        cout << "Enter the age of the Passenger: ";

        if (cin >> age) {
            if (age >= 0 && age <= 100) {
                break; 
            } else {
                cout << "Age must be between 0 and 100. Try again." << endl;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a valid age." << endl;
        }
    }

    return age;
}

bool isNumeric(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

string contact_validator() {
    string num;

    while (true) {
        cout << "Enter the contact number which has only 10 digits: ";
        cin >> num;

        if (num.length() == 10 && isNumeric(num)) {
            break;
        } else {
            cout << "Invalid input. Please enter a 10-digit numeric contact number." << endl;
        }
    }

    return num;

}

int fli_num_validation() {
    int num;
    array<int, 11> flightNumbers = {123445, 234567, 345678, 456789, 567890, 678901, 789012, 890123, 901234, 123456, 234567};
    
    while (true) {
        // Prompt the user to enter the flight number
        cout << "Enter the flight number: ";

        // Check if the input operation was successful
        if (cin >> num) {
            // Check if the flight number is valid
            for (int i = 0; i < 10; i++) {
                if (num == flightNumbers[i]) {
                    return num; // Valid flight number, exit the function
                }
            }
            cout << "Invalid flight number. Try again." << endl;
        } else {
            cout << "Invalid input. Please enter a valid flight number." << endl;
            // Clear the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


char gender_validation() {
    char gender;

    
    while (true) {
        cout << "Enter the gender (M/F): ";

        
        if (cin >> gender) {
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (gender == 'M' || gender == 'm' || gender == 'F' || gender == 'f') {
                break; 
            } else {
                cout << "Invalid gender. Please enter 'M' or 'F'. Try again." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a single character. Try again." << endl;
            
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return gender;
}

array<int, 11> flightNumbers = {123445, 234567, 345678, 456789, 567890, 678901, 789012, 890123, 901234, 123456, 234567};
array<int,11> array_cost={5000, 7500, 6000, 4500, 5500, 6500, 4800, 7100, 5900, 4200, 5300};

int bill(int num)
{
    for(int i=0;i<11;i++)
    {
        if(flightNumbers[i]==num)
        {
            return array_cost[i];
        }

    }
}

int cost = 0;


void Book_reservation()
{
    cost = 0;
    int index = 100;
    int pas_num;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"\n";
    cout<<"\n";
    cout<<"     Here is the details of all the flights present in our airlines    "<<endl;
    cout<<"\n";
    string fileName = "airline_data.csv"; // Replace with your CSV file's name
    displayCSVData(fileName);
    cout<<"\n";
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"\n\n";

    cout << "Enter the number of passengers:";
    cin >> pas_num;
    struct Passenger_Details passenger[pas_num];
    for (int i = 0; i < pas_num; i++)
    {
        cout << "Enter passenger details for passenger " << i + 1 << ":" << endl;
        cout << "Name of the passenger: ";
        cin.ignore();
        getline(cin,passenger[i].name);

        
        passenger[i].age = proper_age();

        passenger[i].Gender = gender_validation();

        
        passenger[i].Contact = contact_validator();

        
        
        passenger[i].flight_number = fli_num_validation();
        
        
        cost+=bill(passenger[i].flight_number);
        passenger[i].cost=bill(passenger[i].flight_number);
        myQueue.push(passenger[i]);
        cout<<"\n\n";
    }
   
}
// cout<<"Booking Your Flight"<<endl;

int comparison(string Name , int flight_num){
     queue<Passenger_Details> tempQueue = myQueue;
     int res = 0;
     int i=0;
     while(!tempQueue.empty()){
            struct Passenger_Details pass = tempQueue.front();
            if(!(Name.compare(pass.name)) && pass.flight_number==flight_num){
                i=1;
                cost = cost-pass.cost;
                myQueue.pop();
            }
            tempQueue.pop();
            
     }
     return i;
}

void Cancel_reservation()
{
    if(myQueue.empty()){
        cout<<"There are no booked Flights\n\n";
        return;
    }
    string name;
    cout<<"Enter Your name as in Ticket: ";
    cin.ignore();
    getline(cin , name);
    int num;
   
    num = fli_num_validation();
    int x = comparison(name , num);
    if(x==1){
        cout<<"Reservation Cancellled successfully\n\n";
    }else{
        cout<<"incorrect input Details\n\n";
    }


    
    

}

void Display_flight_details()
{
    queue<Passenger_Details> tempQueue = myQueue; // Create a copy of the original queue
    if(myQueue.empty()){
        cout<<"There are no tickets Booked to display\n\n";
        return;
    }

    int i = 0;
    while (!tempQueue.empty())
    {
        Passenger_Details frontElement = tempQueue.front(); // Access the front element
        cout << "Passenger " << i + 1 << ":" << endl;
        cout << "Name: " << frontElement.name << endl;
        cout << "Age: " << frontElement.age << endl;
        cout << "Gender:" << frontElement.Gender << endl;
        cout << "Contact: " << frontElement.Contact << endl;
        cout << "Flight Number: " << frontElement.flight_number << endl;
        cout<<"Cost: "<<frontElement.cost<<endl;
        cout << "-------------------------------------" << endl;

        // Process the front element here

        tempQueue.pop(); // Remove the front element in the temporary queue to move to the next one
        i++;
    }
    cout<<"\n---------------------The Total Bill is "<<cost<<"----------------------\n\n";

}

void Exit(int &a)
{
    cout << "Thanks For Using Our Booking System" << endl;
    a = 0;
}




void operation_of_menu() {
    int option = 1;

    while (option) {
        cout << "Enter the number of a menu option: ";

        if (cin >> option) {
            switch (option) {
                case 1:
                    Book_reservation();
                    break;
                case 2:
                    Cancel_reservation();
                    break;
                case 3:
                    Display_flight_details();
                    break;
                case 4:
                case 0:
                    Exit(option);
                    break;
                default:
                    cout << "Invalid option. Please enter a valid option from the menu." << endl;
                    break;
            }
        } else {
            cout << "Invalid input. Please enter a valid option from the menu." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void display_menu()
{

    cout << "-----------------------------------------------" << endl;
    cout << "         Airplane Ticket Booking SYSTEM            " << endl;
    cout << "\n";

    cout << "Please pick an option from the menu below." << endl;
    cout << "1. Book reservation" << endl;
    cout << "2. Cancel reservation" << endl;
    cout << "3. Display flight details" << endl;
    cout << "4. Exit(4 or 0) " << endl;
    cout << "\n";
    cout << "-----------------------------------------------" << endl;
    operation_of_menu();
}

int main()
{
    display_menu();
}
