#include <iostream>
#include "classesheader.h"
#include"libraryheader.h"
#include <string>
#include<Windows.h>
#include <iomanip>


#ifndef queueheader_h
#define queueheader_h


using namespace std;

void queuemenu(){
	// Create data for later use.
	song s1("Kid Cudi", "Scott Mescudi");
	song s2("Kid Cudi", "Enter Galactic");
	song s3("NF", "Running");
	song s4("Kanye West", "Famous");
	song s5("Drake", "Headlines");
	song s6("Kanye", "Flashing Lights");

	playlist myplaylist("playlist1");

	library mainlib;

	q toplay;

	myplaylist.addsong(s1);
	myplaylist.addsong(s2);
	myplaylist.addsong(s3);
	myplaylist.addsong(s4);
	myplaylist.addsong(s5);
	myplaylist.addsong(s6);


	mainlib.addelement(s1);
	mainlib.addelement(s2);
	mainlib.addelement(s3);
	mainlib.addelement(s4);
	mainlib.addelement(s5);
	mainlib.addelement(s6);

	mainlib.addelement(myplaylist);

	int choice;

	// Do while function to setup the queue menu of the spotify application.
	do {
		system("cls");

		cout << "------------------------" << endl
			<< "|  Welcome to Spotify  |" << endl
			<< "------------------------" << endl << endl
			<< "What would you like to do?" << endl << endl
			<< "1- Add song to the queue." << endl
			<< "2- Check if the queue is empty." << endl
			<< "3- Start playing queue." << endl << endl
			<< "Enter your choice (1-3) " << endl
			<< "Or enter 0 to return to main menu:";

		cin >> choice;

		string x, y, t, u;
		song test1, test2;
		playlist xy;
		// Handle user input to perform actions based on the choice.
		switch (choice) {
			//First case program to add song to queue. 
		case 1:
			system("cls");
			
			cout << "What's the name of the song you would like to add to queue? " << endl;
			cin.ignore();
			getline(cin, x);

			cout << "What's the name of the artist? " <<endl;			
			getline(cin, y);

			test1 = song(y, x);
			if (mainlib.findelement(test1)) {
				cout << "The song: " << test1.title << " was found." << endl;
				cout << "The song is being added to queue..." << endl;
				Sleep(1500);
				toplay.addsong(test1);

			}
			else {
				cout << "The song: " << test1.title << " was not found." << "We couldn't add it to the queue." << endl;

			}
			Sleep(2000);
			break;
		// Second case to check if queue is empty.				
		case 2:
			system("cls");

			if (toplay.emptyqueue()) {
				cout << "Your queue is empty, add songs to start playing." << endl;
				Sleep(1500);

			}
			else {
				cout << "Your queue is not empty. Proceed to start playing your songs." << endl;
				Sleep(1500);
			}
			break;

		//Third case to play songs.
		case 3:
			system("cls");
			if (toplay.emptyqueue()) {
				cout << "The queue is empty, nothing to play yet." << endl;
				Sleep(1500);

			}
			else {
				toplay.playqueue();
				
			}			
			break;	

		} 


	} while (choice != 0);

}
#endif

