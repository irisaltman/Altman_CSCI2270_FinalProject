// Project Driver

#include <iostream>

#include "BookTree.cpp"

#include <fstream>

#include <string>

#include <cstdlib>
using namespace std;



void readfile(BookTree *bt, char *filename, char *option);

void showMenu();



int main(int argc, char* argv[])

{

	int command;

	BookTree *btree = new BookTree();

	readfile(btree, argv[1], argv[2]);



	// Menu stuff

	string title;

	string author;

	string year;

	string rank;

	string genre;

	int num_books;

	bool quit = false;

	while (quit != true)

	{

		showMenu();

		cin >> command;



		cin.clear();

		cin.ignore(10000, '\n');



		switch (command)

		{

			// Find and print a movie's info

		case 1:

			cout << "Enter movie title: " << endl;

			getline(cin, title);

			btree->searchBook(title);

			break;



			// Print all books by an author

		case 2:

			cout << "Enter author: " << endl;

			getline(cin, author);

			btree->printBooksbyAuthor(author);

			break;



			// Print all books before a year

		case 3:

			cout << "Enter year: " << endl;

			getline(cin, year);

			btree->printBooksBefore(atoi(year.c_str()));

			break;



			// Print all books after a year

		case 4:

			cout << "Enter year: " << endl;

			getline(cin, year);

			btree->printBooksAfter(atoi(year.c_str()));

			break;



			// Print all books of a genre

		case 5:

			cout << "Enter genre: " << endl;

			getline(cin, genre);

			btree->printGenre(genre);

			break;



			// Delete book

		case 6:

			cout << "Enter title to delete: " << endl;

			getline(cin, title);

			btree->deleteBook(title);

			break;



			// Print all books

		case 7:

			btree->printAllBooks();

			break;



			// Count books

		case 8:

			cout << "Number of books: " << endl;

			num_books = btree->countBooks();

			cout << num_books << " books in inventory." << endl;

			break;



			// Update rank

		case 9:

			cout << "Enter title to rank: " << endl;

			getline(cin, title);

			cin.clear();

			cin.ignore(10000, '\n');

			cout << "Enter new rank (0-5): " << endl;

			getline(cin, rank);

			btree->updateRank(title, atoi(rank.c_str()));

			break;

			// print the books in order by their rankings

		case 10:

			btree->printBooksOrderedByRank();

			break;

			// Quit

		case 11:

			cout << "Goodbye" << endl;

			quit = true;

			break;

			// Default

		default:

			cout << "Command not recognized" << endl;

			cin.clear();

			cin.ignore(10000, '\n');

			break;

		}

	}

}



void readfile(BookTree *bt, char *filename, char *option)

{

	int order = atoi(option);

	ifstream file;

	file.open(filename);

	if (!file)

		cout << "Could not open file" << endl;

	else

	{

		string title;

		string author;

		string pubyear;

		string genre;

		string ranking;

		while (!file.eof())

		{

			getline(file, title, ',');

			getline(file, author, ',');

			getline(file, pubyear, ',');

			getline(file, genre, ',');

			getline(file, ranking, '\n');

			if (order == 2)

				bt->addBookbyYear(title, author, genre, atoi(ranking.c_str()), atoi(pubyear.c_str()));

			else

				bt->addBookbyTitle(title, author, genre, atoi(ranking.c_str()), atoi(pubyear.c_str()));

		}

	}

}



void showMenu()

{

	cout << "Options:" << endl;

	cout << "------------" << endl;

	cout << "1. Find a book" << endl;

	cout << "2. Show all books by an author" << endl;

	cout << "3. Show all books before a year" << endl;

	cout << "4. Show all books after a year" << endl;

	cout << "5. Show all books of one genre" << endl;

	cout << "6. Remove a book" << endl;

	cout << "7. Display all books" << endl;

	cout << "8. Count the books" << endl;

	cout << "9. Update rank (Enter rank from 0-5" << endl;

	cout << "10. print the books in order by their rankings" << endl;

	cout << "11. Quit" << endl;

}
