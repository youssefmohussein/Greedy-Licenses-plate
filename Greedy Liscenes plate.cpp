#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isForbiddenChar(char c) {
    c = toupper(c);
    return c == 'I' || c == 'O' || c == 'Q';
}

string completePlate(const string& input) {// greedy 
    string plate = "";
    int letterCount = 0, digitCount = 0;


    for (char c : input) {
        if (isalpha(c) && letterCount < 3) {
            char upper = toupper(c);
            if (!isForbiddenChar(upper)) {
                plate += upper;
                letterCount++;

            }
        }
    }

    while (letterCount < 3) {
        plate += 'A';
        letterCount++;
    }


    plate += '-';


    for (char c : input) {
        if (isdigit(c) && digitCount < 4) {
            plate += c;
            digitCount++;

        }
    }

    while (digitCount < 4) {
        plate += '0';
        digitCount++;
    }


    return plate;
}


bool isValidPlate(const string& plate) {

    if (plate.size() != 8 || plate[3] != '-') return false;


    for (int i = 0; i < 3; ++i) {
        if (!isalpha(plate[i]) || isForbiddenChar(plate[i])) {
            return false;
        }
    }

    for (int i = 4; i < 8; ++i) {
        if (!isdigit(plate[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << "Format: ABC-1234 (No I, O, Q)" << endl;
    cout << "Type 'exit' to stop" << endl;

    string input;
    while (true) {
        cout << "Enter license plate: ";
        getline(cin, input);

        if (input == "exit") break;

        if (isValidPlate(input)) {
            cout << "Valid American Plate" << endl;
            continue;
        }
        else {
            cout << "Invalid Plate" << endl;
        }

        string plate = completePlate(input);
        cout << "Completed Plate: " << plate << endl;

        if (isValidPlate(plate)) {
            cout << "Valid American Plate (after correction)" << endl;
        }
        else {
            cout << "Invalid Plate (even after correction)" << endl;
        }
    }
    return 0;
}