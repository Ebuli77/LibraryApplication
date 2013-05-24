//============================================================================
// Name        : main.cpp
// Authors      : Tomi Lammi / Marko Kaikkonen / Matti Tastula
// Version     : 0.1
// Copyright   : 
// Description : Library Application
//============================================================================

#include <iostream>
#include <vector>

#include "Library.h"
#include "Customer.h"
#include "Book.h"
#include "Movie.h"
#include "CD.h"
#include "Article.h"


void print_articles(Library *pLib);
void initLibrary(Library *pLib);
int showMenu();

using namespace std;

int main()
{
	cout << "Library doors are now open!" << endl;

	Library *pLibrary = new Library();

	initLibrary(pLibrary);

	string firstname;
	string lastname;

	vector<Article *> *av;
	vector<Article *>::iterator ar_it;

	vector<Customer *> *cv;
	vector<Customer *>::iterator cu_it;

	bool running = true;


	while (running)
	{
		int selection = showMenu();

		switch(selection)
		{
		case 1:
			av = pLibrary->getArticles();
			cout << "\nArticles: \n";

			for (ar_it = av->begin(); ar_it < av->end(); ar_it++)
			{
				cout << " - " ;

				if ((*ar_it)->getType() == 1)
					cout << "Book";
				else if ((*ar_it)->getType() == 0)
					cout << "Movie";
				else if ((*ar_it)->getType() == 2)
					cout << "CD";
				else cout << "Other";

				cout << " : " << (*ar_it)->getName() << " - \n";
			}
			cout << "\n\n";
			break;

		case 2:
			int selection;
			cout<<"\n\n Select the article type\n\n";
			cout<<"1: Book\n";
			cout<<"2: Movie\n";
			cout<<"3: CD\n";
			cout<<"4: Other\n";
			cout<<"5: Cancel\n";
			cout<<":";
			cin >> selection;

			if (selection == 1)
			{

				string name, auth;
				cout << "Give the name of the book: ";
				cin >> name;

				cout << "\n And give the author: ";
				cin >> auth;

				Book book(name);
				book.setAuthor(auth);
				pLibrary->addArticle(&book);

			}

			else if (selection == 2)
			{
				string name;
				cout << "Give the name of the movie: ";
				cin >> name;

				Movie movie(name);

				pLibrary->addArticle(&movie);
			}

			else if (selection == 3)
			{
				string name, artist;
				cout << "Give the name of the album: ";
				cin >> name;

				cout << "\n And give the artist: ";
				cin >> artist;

				CD cd(name);
				cd.setAuthor(artist);
				pLibrary->addArticle(&cd);

			}

			else if (selection == 4)
			{
				string name;
				cout << "Give the name of the article: ";
				cin >> name;

				Article article(name);
				// TODO: set type to NONE when article type setter is implemented
				pLibrary->addArticle(&article);

			}

			else
			{
				cout << "\n\n Cancelled";
				break;
			}

			break;

		case 3:
			// Remove an article
			break;

		case 4:
			// Borrow an article
			break;

		case 5:
			cv = pLibrary->getCustomers();
			cout << "\nCustomers: \n";

			for (cu_it = cv->begin(); cu_it < cv->end(); cu_it++)
			{
				cout << " - " << (*cu_it)->getFirstName() << " "//
						<< (*cu_it)->getLastName() << " - \n";

			}
			cout << "\n\n";
			break;

		case 6:
			cout << "\nPlease give the firstname of a new customer: ";
			cin >> firstname;
			cout << "\nAnd give the lastname: ";
			cin >> lastname;
			pLibrary->addCustomer(new Customer(firstname, lastname));
			break;

		case 7:
			//Remove customer
			break;

		case 8:
			cout << "Bye!";
			running = false;
			break;

		default: cout<<"\n This is a library, not a super market.\n Please try again.\n";
		}

	}
	delete pLibrary;
}

/**
 * Prints all article names found in library
 */
void print_articles(Library *pLib)
{
	//cout << "*** FUNC: " << __FUNCTION__ << "***" << endl;

	vector<Article *> *pArticles = pLib->getArticles();

	for (unsigned int i=0; i < pArticles->size(); i++ )
	{
		cout << "  " << (pArticles->at(i))->getName() << endl;
	}

}

void initLibrary(Library *pLib)
{
	pLib->addCustomer(new Customer("Marko", "Kaikkonen"));
	pLib->addCustomer(new Customer("Teppo", "Testaaja"));
	pLib->addCustomer(new Customer("Kaisa", "Varis"));
	pLib->addCustomer(new Customer("Juha", "Kankkunen"));

	//Article *pBook = new Book("Teach yourself C++ in 3 days");

	pLib->addArticle(new Book("Teach yourself C++ in 3 days"));
	pLib->addArticle(new Book("Teach yourself C++ in 30 days, 2nd edition"));
	pLib->addArticle(new Book("Java for C++ developers"));
	pLib->addArticle(new Book("Nightwatch"));

	pLib->addArticle(new Movie("A bridge too far"));
	pLib->addArticle(new Movie("Mismata"));
	pLib->addArticle(new CD("Jay Karelian and the black glasses"));
	pLib->addArticle(new CD("C.C.R"));
}

int showMenu()
{
	int selection;

	//cout<<" Welcome to Library\n";
	cout<<"\n\n Select an action\n\n";
	cout<<"1: Show articles\n";
	cout<<"2: Add an article\n";
	cout<<"3: Remove article\n";
	cout<<"4: Borrow an article\n";
	cout<<"5: Show customers\n";
	cout<<"6: Add a customer\n";
	cout<<"7: Remove customer\n";
	cout<<"8: Exit\n";
	cout<<":";
	cin>>selection;

	return selection;
}
