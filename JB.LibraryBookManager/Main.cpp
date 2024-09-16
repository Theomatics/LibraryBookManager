
// Assignment 3 - Library Book Manager
// Jonathan Bloedorn

#include <iostream>
#include <conio.h>

using namespace std;

// struct holding the data each book has
struct Book {
	string title;
	string author;
	int yearPublished;
	int numPages;
};

int main()
{
	// create book array
	const int NUM_BOOKS = 4;
	Book books[NUM_BOOKS];

	// fill book array with books
	//book 1
	books[0].title = "The Great Gatsby";
	books[0].author = "F. Scott Fitzgerald";
	books[0].yearPublished = 1925;
	books[0].numPages = 180;

	//book 2
	books[1].title = "To Kill a Mockingbird";
	books[1].author = "Unknown";
	books[1].yearPublished = 2021;
	books[1].numPages = 1;

	//book 3
	books[2].title = "1984";
	books[2].author = "George Orwell";
	books[2].yearPublished = 1949;
	books[2].numPages = 328;

	//book 4
	books[3].title = "The Catcher in the Rye";
	books[3].author = "J.D. Salinger";
	books[3].yearPublished = 1951;
	books[3].numPages = 277;

	// display the books
	for (int i = 0; i < NUM_BOOKS; i++) {
		cout << i + 1 << ". " << books[i].title << "\n";
		cout << "Author: " << books[i].author << "\n";
		cout << "Year Published: " << books[i].yearPublished << "\n";
		cout << "Number of Pages: " << books[i].numPages << "\n";
		cout << "\n";
	}

	// update book information
	int bookNumber;
	string newAuthor;
	int newYearPublished;
	int newNumPages;
	string userSaveDecision;

	cout << "Enter the ID of the book you would like to update (1-4): ";
	cin >> bookNumber;
	bookNumber--; // decrement so that the first book selected is 0 and we can use it to index our array

	if (bookNumber >= 0 && bookNumber < NUM_BOOKS) { // book is in the library and can be modified
		cout << bookNumber + 1 << ". " << books[bookNumber].title << "\n";
		// modify the author
		cout << "Enter the Author (" << books[bookNumber].author << "): ";
		cin >> newAuthor;
		// modify the published date
		cout << "Enter the Year Published (" << books[bookNumber].yearPublished << "): ";
		cin >> newYearPublished;
		// modify the number of pages
		cout << "Enter the Number of Pages (" << books[bookNumber].numPages << "): ";
		cin >> newNumPages;
		// verify changes. if yes, then update the "database"
		cout << "Save these changes? (Y/N): ";
		cin >> userSaveDecision;

		// if the user decided to save the changes, update the "database" and display changes
		if (userSaveDecision == "Y" || userSaveDecision == "y") {
			// update
			books[bookNumber].author = newAuthor;
			books[bookNumber].yearPublished = newYearPublished;
			books[bookNumber].numPages = newNumPages;

			// display
			cout << "\n";
			cout << bookNumber + 1 << ". " << books[bookNumber].title << "\n";
			cout << "Author: " << books[bookNumber].author << "\n";
			cout << "Year Published: " << books[bookNumber].yearPublished << "\n";
			cout << "Number of Pages: " << books[bookNumber].numPages << "\n";
		}
		else {
			cout << "\n";
			cout << "CHANGES WERE NOT SAVED.";
		}
	}
	else {
		cout << "\n";
		cout << "Sorry! Book is not in the library.";
	}

	(void)_getch();
	return 0;
}
