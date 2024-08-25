// ItemTracker Class

#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// creates a class named Item Tracker
class ItemTracker{

// private access modifer
private:
    map<string, int> frequencyMap; // initialize frequencyMap

// public access modifer
public:

  	// method to add items
    void addItem(const string &item) {
        frequencyMap[item]++; // incrementing item into the map
    }

  	// method to get item frequency
    int getItemFrequency(const string &item) {

      	// finds the amount of times item appears
        if (frequencyMap.find(item) != frequencyMap.end()) {
            return frequencyMap[item]; // returns the amount
        } else {
            return 0;
        }
    }

  	// method to display item frequennt appearance
    void displayFrequencies() {

        for (auto& pair : frequencyMap) {
            cout << pair.first << " " << pair.second << endl; // prints item and number of times it appear
        }
    }

    void displayHistogram() {

        for (auto& pair : frequencyMap) {
            cout << pair.first << " " << string(pair.second, '*') << endl; // prints item and number of times it appear using " * "
        }
    }

  	// method to save frequency data into a new file
    void saveFrequenciesToFile() {
        ofstream outFile("frequency.dat");
        if (outFile.is_open()) {
            for (auto& pair : frequencyMap) {
                outFile << pair.first << " " << pair.second << endl; // formats the data it will appear as
            }
            outFile.close();
        } else {
            cout << "Unable to create file." << endl; // prompts incase new file cant be create
        }
    }

  	// method to load and read the file
    void loadFrequenciesFromFile() {
        ifstream inFile("CS210_Project_Three_Input_File.txt");
        string item;
        if (inFile.is_open()) {
            while (inFile >> item) {
                addItem(item); // read items from file
            }
            inFile.close();
        } else {
            cout << "Unable to open file." << endl; // prompts incase file cant be opened
        }
    }

};

// method to Display Menus
inline void displayMenu() {
    cout << "Menu Options:" << endl; // prompts the list of options
    cout << "1. Search for an item" << endl; // prompts option to search for an item
    cout << "2. Display frequency of all items" << endl; // prompts option to display frequency of all items
    cout << "3. Display histogram of items" << endl; // prompts option to display histograms of items
    cout << "4. Exit" << endl; // prompts option to exit the program
    cout << "Choose an option: " << endl; // prompts user to choose an option
}



#endif //ITEMTRACKER_H
