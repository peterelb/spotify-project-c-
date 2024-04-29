#ifndef classesheader_h
#define classesheader_h
#include<string>
#include <set>
#include <queue>
#include<list>
#include <iomanip>
#include <Windows.h>

using namespace std;

// Header file to implement classes and their functions.
struct song {
	//Data variables for this class.
	string artist;
	string title;

	//Constructor and its overload.
	song() :title(""), artist("") {}

	song(string y, string x) {
		artist = y;
		title = x;

	}
	//Operator overload functions for this class.
	friend ostream& operator << (ostream& os, song r) {

		os << setw(7) << left << "Title:" << setw(20) << left << r.title
			<< setw(8) << left << "Artist:" << r.artist;
		return os;
	}

	bool operator ==(song other) {
		return(artist == other.artist) && (title == other.title);
	}
	bool operator < (const song other) const {
		return title < other.title;

	}


};

struct playlist {
	//Data variables for this class.
	string playlistname;
	list <song> pname;
	//Iterator for the list.
	list<song>::const_iterator it;

	//Constructor and its overload.
	playlist() :playlistname("") {}

	playlist(string x) {
		playlistname = x;
	}

	
	// Function to add song to the class' data structure list.
	void addsong(song t) {
		//For loop to check if song already in playlist. 
		for (song b : pname)
		{
			if (b == t)
			{
				cout << "The song is already found in the library." << endl;
				return;
			}
		}

		//Add the song to the library.
		pname.push_back(t);


	}

	//Function to remove song from list data structure of the class.
	void removesong(song s) {
		bool isFound = false;
		for (it = pname.begin(); it != pname.end(); it++) 
		{
			song currentsong = *it;
			if (currentsong.title == s.title && currentsong.artist == s.artist) 
			{

				//Pass the iterator as a parameter to the erase function to remove the song from the library.
				pname.erase(it);
				cout << "The song was succussfully removed." << endl;
				isFound = true;
				break;
				
			}
		}
		if (isFound == false) 
		{
			cout << "Song " << s.title << " is not found in the playlist." << endl;
		}	

	
	}

	//Function to display playlist using an iterator.
	void displayplaylist() {

		cout << "The songs in the playlist " << playlistname << " are :" << endl << endl;
		for (it = pname.begin(); it != pname.end(); it++) {
			cout << *it << endl;
		}
	}
	//Function to check if playlist empty.
	bool checkempty() {
		return pname.empty();
	}
	//Operator overload functions for this class.
	bool operator < (const playlist other) const {
		return playlistname < other.playlistname;

	}


};

struct library {
	//Data variables for this class.
	set <song> librarysong;
	set <playlist> libraryplaylist;

	// Function name overload to add a song or a playlist to library.
	void addelement(const song song) {
		librarysong.insert(song);
	}

	void addelement(const playlist playlist) {
		libraryplaylist.insert(playlist);
	}

	// Function to check if library is empty.
	bool checkempty() {
		return librarysong.empty() && libraryplaylist.empty();
	}
	// Function to return size of library.
	int returnsize() {
		int size1=0, size2=0;
		size1 = librarysong.size();
		size2 = libraryplaylist.size();

		
		return size1 + size2;

	}
	// Function name overload to find a song or a playlist to library.
	bool findelement(song s) {
		if (librarysong.find(s) != librarysong.end())	
			return true;
		else
			return false;
	}
	bool findelement(playlist p) {
		if (libraryplaylist.find(p) != libraryplaylist.end())
			return true;
		else
			return false;
	}

};


struct q {
	//Data structure for this class.
	queue <song> queuemanager;

	//Function to add song to queue.
	void addsong(song r) {
		queuemanager.push(r);
	}
	//Function to check if queue is empty.
	bool emptyqueue() {
		return queuemanager.empty();
	}
	//Function to simulate a spotify player.
	void playqueue() {
		
		while (!queuemanager.empty()) {
			cout << "Now playing: " << endl
				 << "             " <<queuemanager.front().title << endl << endl ;
			cout << "            ---------------- 2:23  " << endl <<endl;
			cout << "               <-  ||  ->       " << endl <<endl;
			cout << "              " << queuemanager.front().artist << endl;
			queuemanager.pop();
			Sleep(3000);
			system("cls");

		}		
	}
};


#endif
