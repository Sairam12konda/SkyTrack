//This code just shows How to read Csv in c++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

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

void main_display() {
    string fileName = "airline_data.csv"; // Replace with your CSV file's name
    displayCSVData(fileName);
    
}
