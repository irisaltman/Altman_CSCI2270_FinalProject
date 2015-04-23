// Class creater for the Book Tree
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "BookTree.h"
using namespace std;

BookTree::BookTree()
{
	root=NULL;
	count=1;
}

void BookTree::addBookbyTitle(string title, string author, string genre, /*int rank,*/ int pubyr)
{
	BookNode *newBook = new BookNode(title, author, pubyr, genre);
	BookNode *x=root;
	BookNode *y=NULL;
	
	if(root==NULL)
		root=newBook;
	
	else
	{
		while(x!=NULL)
		{
			y=x;
			if(newBook->title<x->title)
				x=x->left;
			else
				x=x->right;
		}
		newBook->parent=y;
		if(newBook->title<y->title)
			y->left=newBook;
		else
			y->right=newBook;
	}
	return;
}

void BookTree::addBookbyYear(string title, string author, string genre, /*int rank,*/ int pubyr)
{
	BookNode *newBook = new BookNode(title, author, pubyr, genre);
	BookNode *x=root;
	BookNode *y=NULL;
	
	if(root==NULL)
		root=newBook;
	
	else
	{
		while(x!=NULL)
		{
			y=x;
			if(newBook->pubyr<x->pubyr)
				x=x->left;
			else
				x=x->right;
		}
		newBook->parent=y;
		if(newBook->pubyr<y->pubyr)
			y->left=newBook;
		else
			y->right=newBook;
	}
	return;
}

void BookTree::printAllBooks(BookNode *node)
{
	if(node->left!=NULL)
		printAllBooks(node->left);
	cout<<"Title: "<<node->title<<" Author: "<<node->author<<endl;
	if(node->right!=NULL)
		printAllBooks(node->right);
	return;
	
}

void BookTree::printBooksbyAuthor(BookNode *node, string in_author)
{
	cout<<"Searching for author: "<<in_author<<endl;
	if(node->left!=NULL)
		printBooksbyAuthor(node->left, in_author);
	if(node->author==in_author)
		cout<<"Title: "<<node->title<<endl;
	if(node->right!=NULL)
		printBooksbyAuthor(node->right, in_author);
	return;
}

void BookTree::printBooksBefore(BookNode *node, int year)
{
	cout<<"Searching for books before year: "<<year<<endl;
	if(node->left!=NULL)
		printBooksBefore(node->left, year);
	if(node->pubyr<year)
		cout<<"Title: "<<node->title<<" by "<<node->author<<endl;
	if(node->right!=NULL)
		printBooksBefore(node->right, year);
	return;
}

void BookTree::printBooksAfter(BookNode *node, int year)
{
	cout<<"Searching for books after year: "<<year<<endl;
	if(node->left!=NULL)
		printBooksBefore(node->left, year);
	if(node->pubyr>year)
		cout<<"Title: "<<node->title<<" by "<<node->author<<endl;
	if(node->right!=NULL)
		printBooksBefore(node->right, year);
	return;
}

void BookTree::searchBook(string title)
{
	cout<<"Searching for... "<<title<<endl;
	BookNode* bookFound = searchTree(root, title);
	if(bookFound!=NULL)
	{
		cout<<"Info:"<<endl;
		cout<<"====="<<endl;
		cout<<"Title: "<<bookFound->title<<endl;
		cout<<"Author: "<<bookFound->author<<endl;
		cout<<"Year of Publication: "<<bookFound->pubyr<<endl;
		cout<<"Genre: "<<bookFound->genre<<endl;
		// How do I do rank?
	}
	else
		cout<<"Sorry, book not found. Try another title."<<endl;
	return;
}

// Helper function for locating a book for which the user is searching
// Use for printing book info and deleting book
BookNode* BookTree::searchTree(BookNode *node, string title)
{
	if(node==NULL)
		return NULL;
	else if(node->title==title)
		return node;
	else
	{
		if(node->title>title)
			return searchTree(node->left, title);
		else
			return searchTree(node->right, title);
	}
}

int BookTree::countBooks()
{
	int num_books=countBookNodes(root);
	return num_books;
}

int BookTree::countBookNodes(BookNode *node)
{
	if(node==NULL)
		return 0;
	else
		return countBookNodes(node->left)+countBookNodes(node->right)+1;
}

void BookTree::deleteBook(string title)
{
	BookNode *foundBook=searchTree(root, title);
	if(foundBook!=NULL)
	{
		// No children
		if(foundBook->right==NULL&&foundBook->left==NULL)
		{
			// Is it a left child or a right?
			if(foundBook->parent->left==foundBook)
				foundBook->parent->left=NULL;
			else
				foundBook->parent->right=NULL;
			delete foundBook;
		}
		// Only has left child
		else if(foundBook->right==NULL)
		{
			if(foundBook->parent->left==foundBook)
				foundBook->parent->left=foundBook->left;
			else
				foundBook->parent->right=foundBook->left;
			delete foundBook;
		}
		// Only has right child
		else if(foundBook->left==NULL)
		{
			if(foundBook->parent->left==foundBook)
				foundBook->parent->left=foundBook->right;
			else
				foundBook->parent->right=foundBook->right;
			delete foundBook;
		}
		// Has two children
		else
		{
			// right tree - find replacement
			BookNode *replace = foundBook->right;
			// find smallest left
			while(replace->left!=NULL)
				replace=replace->left;
				
			foundBook->title=replace->title;
			foundBook->author=replace->author;
			foundBook->rank=replace->rank;
			foundBook->pubyr=replace->pubyr;
			foundBook->genre=replace->genre;
			
			if(replace->right!=NULL)
				replace->right->parent=replace->parent;
			if(replace->parent->left==replace)
				replace->parent->left=replace->right;
			else
				replace->parent->right=replace->right;
			delete replace;
		}
	}
	else
		cout<<"Book not found."<<endl;
}
