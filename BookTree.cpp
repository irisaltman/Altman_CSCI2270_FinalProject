// Class creater for the Book Tree

#include <iostream>

#include <string>

#include <vector>

#include <stdio.h>

#include <stdlib.h>

#include "BookTree.h"

using namespace std;



// Constructor 

BookTree::BookTree()

{

	root = NULL;

	count = 0;

}



/* Function prototype:

void BookTree::addBookbyTitle(string,string,string,int,int)



Function description:

This function adds a new node to the binary search tree. The node is sorted by its title alphabetically.



Example:

BookTree bt;

bt->addBookbyTitle("Inkheart","Cornelia Funke","fiction",3,2003);



Precondition: unused nodes are NULL, a tree has been established, the parameters are in order: title, author, genre, rank, and pubication year

Postcondition: the new node has been added to the tree according to title

*/

void BookTree::addBookbyTitle(string title, string author, string genre, int rank, int pubyr)

{

	BookNode *newBook = new BookNode(title, author, pubyr, genre);

	newBook->rank = rank;

	BookNode *x = root;

	BookNode *y = NULL;



	if (root == NULL){

		root = newBook;

		root->parent = NULL;

	}

	else

	{

		while (x != NULL)

		{

			y = x;

			if (newBook->title<x->title)

				x = x->left;

			else

				x = x->right;

		}

		newBook->parent = y;

		if (newBook->title<y->title)

			y->left = newBook;

		else

			y->right = newBook;

	}

	return;

}

/*Function prototype:

void BookTree::addBookbyYearstring,string,string,int,int)



Function description:

This function adds a new node to the binary search tree. The node is sorted by its publication year.



Example:

BookTree bt;

bt->addBookbyYear("Inkheart","Cornelia Funke","fiction",3,2003);



Precondition: unused nodes are NULL, a tree has been established, the parameters are in order: title, author, genre, rank, and pubication year

Postcondition: the new node has been added to the tree according to year

*/

void BookTree::addBookbyYear(string title, string author, string genre, int rank, int pubyr)

{

	BookNode *newBook = new BookNode(title, author, pubyr, genre);

	newBook->rank = rank;

	BookNode *x = root;

	BookNode *y = NULL;



	if (root == NULL){

		root = newBook;

		root->parent = NULL;

	}

	else

	{

		while (x != NULL)

		{

			y = x;

			if (newBook->pubyr<x->pubyr)

				x = x->left;

			else

				x = x->right;

		}

		newBook->parent = y;

		if (newBook->pubyr<y->pubyr)

			y->left = newBook;

		else

			y->right = newBook;

	}

	return;

}



/*Function prototype:

void BookTree::printAllBooks(BookNode*)



Function description:

This function displays all of the books in the tree. It uses recursion to implement in-order traversal.



Example:

BookTree bt;

bt->printAllBooks(root);



Precondition: unused nodes are NULL, a tree has been established

Postcondition: nothing is returned, a list of the books and their authors should be displayed

*/

void BookTree::printAllBooks(BookNode *node)

{

	if (node->left != NULL)

		printAllBooks(node->left);

	cout << "Title: " << node->title << " Author: " << node->author << endl;

	if (node->right != NULL)

		printAllBooks(node->right);

	return;



}



// This is the public method to help the previous method in the driver

void BookTree::printAllBooks()

{

	if (root == NULL){

		cout << "No movies found" << endl;

	}

	else 

		printAllBooks(root);

	return;

}



// Print all books by one author (private helper method)

void BookTree::printBooksbyAuthor(BookNode *node, string in_author)

{

	cout << "Searching for author: " << in_author << endl;

	if (node->left != NULL)

		printBooksbyAuthor(node->left, in_author);

	if (node->author == in_author)

		cout << "Title: " << node->title << endl;

	if (node->right != NULL)

		printBooksbyAuthor(node->right, in_author);

	return;

}



/*Function prototype:

void BookTree::printBooksbyAuthor(string)



Function description:

This function displayes all books by a given author. If the author is not found, it will not print.



Example:

BookTree bt;

bt->printBooksbyAuthor("Cornelia Funke");



Precondition: unused nodes are NULL, a tree has been established

Postcondition: nothing is returned, a list of the books and their authors should be displayed

*/

void BookTree::printBooksbyAuthor(string in_author)

{

	printBooksbyAuthor(root, in_author);

	return;

}



// Print books pulished before a given year (private helper method)

void BookTree::printBooksBefore(BookNode *node, int year)

{

	cout << "Searching for books before year: " << year << endl;

	if (node->left != NULL)

		printBooksBefore(node->left, year);

	if (node->pubyr<year)

		cout << "Title: " << node->title << " by " << node->author << endl;

	if (node->right != NULL)

		printBooksBefore(node->right, year);

	return;

}



/*Function prototype:

void BookTree::printBooksBefore(int)



Function description:

This function displays all of the books in the tree that were published before a given year. The year is the parameter given by the user.



Example:

BookTree bt;

bt->printBooksBefore(2003);



Precondition: unused nodes are NULL, a tree has been established

Postcondition: nothing is returned, a list of the books and their authors should be displayed

*/

void BookTree::printBooksBefore(int year)

{

	printBooksBefore(root, year);

	return;

}



// Print books published after a given year (private helper method)

void BookTree::printBooksAfter(BookNode *node, int year)

{

	cout << "Searching for books after year: " << year << endl;

	if (node->left != NULL)

		printBooksBefore(node->left, year);

	if (node->pubyr>year)

		cout << "Title: " << node->title << " by " << node->author << endl;

	if (node->right != NULL)

		printBooksBefore(node->right, year);

	return;

}



/*Function prototype:

void BookTree::printBooksAfter(int)



Function description:

This function displays all of the books in the tree that were published after a given year. The year is the parameter given by the user.



Example:

BookTree bt;

bt->printBooksAfter(2003);



Precondition: unused nodes are NULL, a tree has been established

Postcondition: nothing is returned, a list of the books and their authors should be displayed

*/

void BookTree::printBooksAfter(int year)

{

	printBooksAfter(root, year);

	return;

}



// Method to print all books of one genre (private helper method)

void BookTree::printGenre(BookNode *node, string genre)

{

	cout << "Searching for all " << genre << " books." << endl;

	if (node->left != NULL)

		printGenre(node->left, genre);

	if (node->genre == genre)

		cout << "Title: " << node->title << " by " << node->author << endl;

	if (node->right != NULL)

		printGenre(node->right, genre);

	return;



}



/*Function prototype:

void BookTree::printGenre(string)



Function description:

This function displays all of the books in the tree of a certain genre. The genre is the parameter given by the user.



Example:

BookTree bt;

bt->printGenre("fiction");



Precondition: unused nodes are NULL, a tree has been established

Postcondition: nothing is returned, a list of the books and their authors should be displayed

*/

void BookTree::printGenre(string genre)

{

	printGenre(root, genre);

	return;

}



/*Function prototype:

void BookTree::searchBook(string)



Function description:

This function searches the tree for a title and prints that book's information. The title is the parameter given by the user.



Example:

BookTree bt;

bt->searchBook("Inkheart");



Precondition: unused nodes are NULL, a tree has been established

Postcondition: nothing is returned, the book's information should be displayed

*/

void BookTree::searchBook(string title)

{

	cout << "Searching for... " << title << endl;

	BookNode* bookFound = searchTree(root, title);

	if (bookFound != NULL)

	{

		cout << "Info:" << endl;

		cout << "=====" << endl;

		cout << "Title: " << bookFound->title << endl;

		cout << "Author: " << bookFound->author << endl;

		cout << "Year of Publication: " << bookFound->pubyr << endl;

		cout << "Genre: " << bookFound->genre << endl;

		cout << "Rank: " << bookFound->rank << endl;

	}

	else

		cout << "Sorry, book not found. Try another title." << endl;

	return;

}



// Helper function for locating a book for which the user is searching

// Use for printing book info and deleting book

BookNode* BookTree::searchTree(BookNode *node, string title)

{

	if (node == NULL)

		return NULL;

	else if (node->title == title)

		return node;

	else

	{

		if (node->title>title)

			return searchTree(node->left, title);

		else

			return searchTree(node->right, title);

	}

}





/*Function prototype:

void BookTree::countBooks()



Function description:

This function counts how many nodes are in the binary search tree.



Example:

BookTree bt;

bt->countBooks();



Precondition: unused nodes are NULL, a tree has been established

Postcondition: nothing is returned, a number should be displayed, being the number of nodes found in the tree

*/

int BookTree::countBooks()

{

	int num_books = countBookNodes(root);

	return num_books;

}



// Helper to count the books (private)

int BookTree::countBookNodes(BookNode *node)

{

	if (node == NULL)

		return 0;

	else

		return countBookNodes(node->left) + countBookNodes(node->right) + 1;

}



/*Function prototype:

void BookTree::deleteBook(string)



Function description:

This function deletes a specific book from the tree. The title to be deleted is the parameter given by the user.



Example:

BookTree bt;

bt->deleteBook("Inkheart");



Precondition: unused nodes are NULL, a tree has been established

Postcondition: Nothing is printed, the tree should now contain one less node (check with count method)

*/

void BookTree::deleteBook(string title)

{

	BookNode *foundBook = searchTree(root, title);

	if (foundBook != NULL)

	{

		// No children

		if (foundBook->right == NULL&&foundBook->left == NULL)

		{

			// Is it a left child or a right?

			if (foundBook->parent->left == foundBook)

				foundBook->parent->left = NULL;

			else

				foundBook->parent->right = NULL;

			delete foundBook;

		}

		// Only has left child

		else if (foundBook->right == NULL)

		{

			if (foundBook->parent->left == foundBook)

				foundBook->parent->left = foundBook->left;

			else

				foundBook->parent->right = foundBook->left;

			delete foundBook;

		}

		// Only has right child

		else if (foundBook->left == NULL)

		{

			if (foundBook->parent->left == foundBook)

				foundBook->parent->left = foundBook->right;

			else

				foundBook->parent->right = foundBook->right;

			delete foundBook;

		}

		// Has two children

		else

		{

			// right tree - find replacement

			BookNode *replace = foundBook->right;

			// find smallest left

			while (replace->left != NULL)

				replace = replace->left;



			foundBook->title = replace->title;

			foundBook->author = replace->author;

			foundBook->rank = replace->rank;

			foundBook->pubyr = replace->pubyr;

			foundBook->genre = replace->genre;



			if (replace->right != NULL)

				replace->right->parent = replace->parent;

			if (replace->parent->left == replace)

				replace->parent->left = replace->right;

			else

				replace->parent->right = replace->right;

			delete replace;

		}

	}

	else

		cout << "Book not found." << endl;

}





/*Function prototype:

void BookTree::updateRank(string,int)



Function description:

This function changes the rank of a specific book in the tree. The title and new ranking are the parameters given by the user.



Example:

BookTree bt;

bt->updateRank("Inkheart",5);



Precondition: unused nodes are NULL, a tree has been established

Postcondition: nothing is returned, the rank of the book should now be changed (check with the searchBook method)

*/

void BookTree::updateRank(string title, int newrank)

{

	BookNode *updateBook = searchTree(root, title);

	updateBook->rank = newrank;

	return;

}



void BookTree::printBooksOrderedByRank(){

	if (root == NULL){

		cout << "No movies in the list" << endl;

	}

	else{

		vector<BookNode *> v;

		printBooksOrderedByRank(root, v);

		sortList(v);

		printList(v);

	}

}



void BookTree::printBooksOrderedByRank(BookNode *node, vector<BookNode *> &v){

	if (node == NULL){

		return;

	}

	else{

		printBooksOrderedByRank(node->left, v);

		v.push_back(node);

		printBooksOrderedByRank(node->right, v);

	}

}



void BookTree::sortList(vector<BookNode *> &v){

	for (int i = 0; i < v.size(); ++i){

		for (int j = i - 1; j >= 0; --j){

			if (v[j]->rank > v[j + 1]->rank){

				BookNode *temp = v[j];

				v[j] = v[j + 1];

				v[j + 1] = temp;

			}

			else{

				break;

			}

		}

	}

}



void BookTree::printList(vector<BookNode *> &v){

	for (int i = 0; i < v.size(); ++i){

		cout << "Title: " << v[i]->title << ", Author: " << v[i]->author << ", Rank: " << v[i]->rank << endl;

	}

}
