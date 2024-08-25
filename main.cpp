/*
Samit Datta
Project 3

This program checks the file and outputs the amount of time an item appear in the file in different ways, and save the data into a new file
*/
#include <iostream>
#include "ItemTracker.h"

// main function
int main(){

    ItemTracker tracker;

    tracker.loadFrequenciesFromFile(); // load and read the file

    int choice; // gets user input
    do {
        cout << endl; // white space
        displayMenu();  // displays the menu
        cin >> choice; // get the user input
        cin.ignore();
        switch (choice) {

            // option 1
            case 1: {
                string item; // declares item as a string
                cout << "Enter item name: " << endl; // prompts user to enter an item name
                getline(cin, item); // get input from user
                cout << item << " appears " << tracker.getItemFrequency(item) << " times." << endl; // prints item names and the amount of time it appear in the file
                break;
            }
            case 2:
                tracker.displayFrequencies(); // displays prompts and outputs item and number of times it appear
                break;
            case 3:
                tracker.displayHistogram(); // displays prompts and outputs item and number of times it appear using " * "
                break;
            case 4:
                tracker.saveFrequenciesToFile(); // save frequency data into a new file
                cout << "Exiting program." << endl; // exits the program
                break;
            default:
                cout << "Invalid option. Try again." << endl; // prompts if input is invalid
                break;
        }
    } while (choice != 4); // checks if user inputs to exit the program

    return 0;
}
