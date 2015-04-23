// Project Driver
#include <iostream>
#include "BookTree.h"
#include <fstream>
#include <string>
using namespace std;

void readfile(BookTree *bt, char *filename);
void showMenu();

int main(int argc, char* argv[])
{
	int command;
	BookTree *btree=new BookTree();
	readfile(btree, argv[1]);
	
	// Menu stuff
	string title;
	bool quit=false;
	while(quit!=true)
	{
		showMenu();
		cin>>command;
		
		cin.clear();
		cin.ignore(10000,'\n');
		
		switch(command)
		{
			
		}
	}
}

void readfile(BookTree *bt, char *filename)
{
	ifstream file;
	file.open(filename);
	if(!file)
		cout<<"Could not open file"<<endl;
	else{
	string title;
	string author;
	string pubyear;
	string genre;
	while(!file.eof())
	{
		getline(file, title, ',');
		getline(file,author,',');
		getline(file,pubyear,',');
		getline(file,genre);
		// How do i get the user to choose how it is ordered?
		bt->addBookbyTitle(title,author,genre,atoi(pubyear.c_str()));
	}
}
}

void showMenu()
{
	cout<<"Options:"<<endl;
	cout<<"------------"<<endl;
	cout<<"1. Find a book"<<endl;
	cout<<"2. Show all books by an author"<<endl;
	cout<<"3. Show all books before a year"<<endl;
	cout<<"4. Show all books after a year"<<endl;
	cout<<"5. Remove a book"<<endl;
	cout<<"6. Display all books"<<endl;
	cout<<"7. Count the books"<<endl;
	cout<<"7.5 Update rank"<<endl;
	cout<<"8. Quit"<<endl; 
}
