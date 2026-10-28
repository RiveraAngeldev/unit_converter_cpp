#include <iostream>
#include <limits>
#include "length.h"
using namespace std;
/***************************************************************
                            MENU
***************************************************************/

void displayMenu()
{
    cout << "\n======================================\n";
    cout << "       UNIT CONVERSION CALCULATOR\n";
    cout << "======================================\n";
    cout << "1. Length\n";
    cout << "2. Mass and Weight\n";
    cout << "3. Temperature\n";
    cout << "4. Time\n";
    cout << "5. Speed\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}


int main()
{
    int choice;

    cout << "\tWelcome to the Unit Conversion Calculator\n";

    do {
        displayMenu();

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                lengthMenu();
                break;

            case 2:
                cout << "Mass and Weight: Coming soon!\n";
                break;

            case 3:
                cout << "Temperature: Coming soon!\n";
                break;

            case 4:
                cout << "Time: Coming soon!\n";
                break;

            case 5:
                cout << "Speed: Coming soon!\n";
                break;

            case 6:
                cout << "Exiting the application. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Select a number from 1 to 6.\n";
                break;
        }

    } while (choice != 6);

    return 0;
}