# Altman_CSCI2270_FinalProject
Final project for Data Structures

This project will read in a file of a list of books and create a binary search tree. It is similar to the movie assignment that we did in class. I want to create several functions to order and search the tree. The tree can be ordered according to title or publication year. (this will be specified as a command line argument). One method will print all books by the same author. I can print the entire list of books, or all books written before (or after) a user-input's year. I can print all books of a certain genre or delete a book from the tree. I could also provide the user an option to rate the books, and to count the number of books in the tree. When the program runs, an options menu will appear so that the user can choose what method will be used. The book files I will use will be created by me and will include title, author, year of publication, genre, and previous user ranks.

How to Run:
To run my program you must include 2 command line arguments. The first will be the name of the book file to be read, and the second will be either a (1), which indicates that the tree should be sorted by title; or a (2), which indicates that the tree should be sorted by year. To navigate the menu, enter the number of the option you wish to execute. 

Dependencies:
The program requires a file of books with specific information in order- one has been provided that I made and it is called book.txt

System Requirements:
Linux

Group Members:
N/A

Contributors:
None so far

Open issues/bugs:
Some of the menu options print unexpected things and I am not sure if this is a problem with the example file I made, the way I am reading in my file, or something else entirely. However the program compiles and runs well. I wanted to add a function to print the books in order by their rankings by implementing an array but I didn't have time, so maybe that could be a good enhancement. 



