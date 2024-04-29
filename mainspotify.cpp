#include <iostream>
#include <string>
#include "classesheader.h"
#include"playlistheader.h"
#include"libraryheader.h"
#include "queueheader.h"
#include <iomanip>


using namespace std;




int main() {
    int choice;

// Do while function to setup the main menu of the spotify application.
    do {
        system("cls");
        cout << "------------------------" << endl
            << "|  Welcome to Spotify  |" << endl
            << "------------------------" << endl << endl
            << "What would you like to do?" << endl << endl
            << "1- Browse playlist menu..." << endl
            << "2- Browse library menu..." << endl
            << "3- Browse queue menu..." << endl
            << "Enter your choice (1-3): ";
        cin >> choice;

        // Handle user input to perform actions based on the choice.
        switch (choice) {
        case 1:
            //Clear page for neat menu and go to playlist menu using funciton call.
            system("cls");
            cout << "You selected Browse playlist menu." << endl << "Loading...";
            Sleep(1000);
            playlistmenu();
            break;
        case 2:
            //Clear page for neat menu and go to library menu using funciton call.
            system("cls");
            cout << "You selected Browse library menu." << endl << "Loading...";
            Sleep(1000);
            librarymenu();
            break;
        case 3:
            //Clear page for neat menu and go queue menu using funciton call.
            system("cls");
            cout << "You selected Browse queue menu." << endl << "Loading...";
            Sleep(1000);
            queuemenu();
            break;
        default:
            // Handle invalid input.
            cout << "You entered a wrong command exiting application..." << endl;
            break;
        }
    } while (choice != 0);


    return 0;
}