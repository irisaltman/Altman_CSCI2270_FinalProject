// Header file for book class
#ifndef BOOKTREE_H
#define BOOKTREE_H

struct BookNode 
{
	std::string title;
	std::string author;
	int pubyr; // year of publication
	int rank; // the user can rank, default set to 0
	std::string genre;
	BookNode *parent;
	BookNode *right;
	BookNode *left;
	
	BookNode(std::string in_title, std::string in_author, int in_pubyr, std::string in_genre)
	{
		title=in_title;
		author=in_author;
		pubyr=in_pubyr;
		genre=in_genre;
		rank=0;
		right=NULL;
		left=NULL;
	}
};

class BookTree
{
	int count;
	public:
		// Constructer
		BookTree();
		// method to order tree by title
		void addBookbyTitle(std::string title, std::string author, std::string genre, /*int rank,*/ int pubyr);
		// method to order tree by year
		void addBookbyYear(std::string title, std::string author, std::string genre, /*int rank,*/ int pubyr);
		// method to add rank
		void updateRank(std::string title, int newrank);
		// method to search for title
		void searchBook(std::string title);
		// method to print all books by same author
		void printBooksbyAuthor(BookNode *node, std::string in_author);
		// method to print all books
		void printAllBooks(BookNode *node);
		// method to print all books made before certain year
		void printBooksBefore(BookNode *node, int year);
		// method to print all books made after a certain year
		void printBooksAfter(BookNode *node, int year);
		// method to print books in order by rank
		// method to delete a book
		void deleteBook(std::string title);
		// method to count books
		int countBooks();
		
	private:
		BookNode *root;
		BookNode* searchTree(BookNode *node, std::string title); // private search method to help the public ones
		// method to count books private helper
		int countBookNodes(BookNode *node);
	
};

#endif
