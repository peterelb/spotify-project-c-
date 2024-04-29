#include <iostream>
#include "classesheader.h"
#include <string>
#include<Windows.h>
#include <iomanip>


#ifndef playlistheader_h
#define playlistheader_h



using namespace std;

//Create playlist function to call in main page.
void playlistmenu() {
		// Create songs and a playlist to use.
	song s1("Kid Cudi", "Scott Mescudi");
	song s2("Kid Cudi", "Enter Galactic");
	song s3("NF", "Running");
	song s4("Kanye West", "Famous");
	song s5("Drake", "Headlines");
	song s6("Kanye", "Flashing Lights");

	playlist myplaylist("playlist1");

	myplaylist.addsong(s1);
	myplaylist.addsong(s2);
	myplaylist.addsong(s3);
	myplaylist.addsong(s4);
	myplaylist.addsong(s5);
	myplaylist.addsong(s6);


	int choice;

	do {
		// Do while function to setup the playlist menu of the spotify application.
		system("cls");
		cout << "------------------------" << endl
			<< "|  Welcome to Spotify  |" << endl
			<< "------------------------" << endl << endl
			<< "What would you like to do?" << endl << endl				
		    << "1- Display songs in playlist." << endl
			<< "2- Add song to playlist." << endl
			<< "3- Remove song from playlist." << endl
			<< "4- Check if playist is empty." << endl<< endl			
			<< "Enter your choice (1-3) " << endl
			<< "Or enter 0 to return to main menu:";

		cin >> choice;

		string x, y, t, u;
		song test1, test2;
	// Switch case for user to select function needed
		switch (choice) {
		

		case 1:
			//First case call of function.
			system("cls");
			myplaylist.displayplaylist();
			Sleep(2000);
			break;

		case 2:
			//Second case user inputs song name and artist to add song.
			system("cls");
			cout << "What's the name of the song you would like to add? " << endl;
			cin.ignore();
			getline(cin, x);
			cout << "What's the name of the artist? " << endl;
			getline(cin, y);
			test1 = song(y, x);
			myplaylist.addsong(test1);
			cout << "The song was succucsuflly added." << endl;
			Sleep(2000);
			break;

		case 3:
			//Third case user input name of song to be removed.
			system("cls");
			cout << "What song do you want to remove? " << endl;
			cin.ignore();
			getline(cin,u);			

			cout << "What's the artists name?" << endl;			
			getline(cin, t);

			test2 = song(t, u);
			myplaylist.removesong(test2);
			Sleep(2000);
			break;

		case 4:
			//Fourth case, if statements to check if plyalist empty.
			system("cls");
			if (myplaylist.checkempty()) {
				cout << "Your playlist " << myplaylist.playlistname << " is empty." << endl;
			}
			else {
				cout << "Playlist " << myplaylist.playlistname << " is not empty." << endl;
			}
			Sleep(2000);
			break;
		}


	} while (choice != 0);

}
#endif