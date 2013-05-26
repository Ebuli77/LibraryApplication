//============================================================================
// Name        : main.cpp
// Authors      : Tomi Lammi / Marko Kaikkonen / Matti Tastula
// Version     : 0.1
// Copyright   : 
// Description : Library Application
//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>

#include "Library.h"
#include "Customer.h"
#include "Book.h"
#include "Movie.h"
#include "CD.h"
#include "Article.h"


void print_articles(Library *pLib);
void initLibrary(Library *pLib);
int showMenu();

void showArticles(vector<Article *> *pArticles);
void showCustomers(vector<Customer *> *pCustomers);

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

	vector<Loan *> *lo;
	vector<Loan *>::iterator lo_it;

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

				if ((*ar_it)->getType() == Article::BOOK)
					cout << "Book";
				else if ((*ar_it)->getType() == Article::MOVIE)
					cout << "Movie";
				else if ((*ar_it)->getType() == Article::CD)
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
				fflush(stdin);
				getline(cin, name);

				cout << "\nAnd give the author: ";
				fflush(stdin);
				getline(cin, auth);

				Book book(name);
				book.setAuthor(auth);
				pLibrary->addArticle(&book);

			}

			else if (selection == 2)
			{
				string name;
				cout << "Give the name of the movie: ";
				fflush(stdin);
				getline(cin, name);

				Movie movie(name);

				pLibrary->addArticle(&movie);
			}

			else if (selection == 3)
			{
				string name, artist;
				cout << "Give the name of the album: ";
				fflush(stdin);
				getline(cin, name);

				cout << "\n And give the artist: ";
				fflush(stdin);
				getline(cin, artist);

				CD cd(name);
				cd.setAuthor(artist);
				pLibrary->addArticle(&cd);

			}

			else if (selection == 4)
			{
				string name;
				cout << "Give the name of the article: ";
				fflush(stdin);
				getline(cin, name);

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
			unsigned int article_idx;

			cout << "\nWhich article do you want to remove";
			showArticles(pLibrary->getArticles());
			cout << " :";
			cin >> article_idx;

			if ( (article_idx > 0) && (article_idx < pLibrary->getArticles()->size()) )
			{
				Article *pRemovedArticle = pLibrary->getArticles()->at(article_idx);
				pLibrary->getArticles()->erase(pLibrary->getArticles()->begin() + article_idx);
				delete pRemovedArticle; ///< remember also to free memory reserved for the article

			}
			else
			{
				cout << "No such article found!\n";
			}
			// Remove an article
			break;

		case 4:
			// Borrow an article

			unsigned int cstmr_idx; //index of the loaning customer
			unsigned int art_idx; //index of the loaned article

			cout<< "\nEnter the index of customer loaning the article" <<endl;
			showCustomers(pLibrary->getCustomers());
			cin>>cstmr_idx;

			cout << "\nWhich article do you want to remove";
			showArticles(pLibrary->getArticles());
			cout << " :";
			cin >> art_idx;
			if((art_idx>=0) && (art_idx < pLibrary->getArticles()->size()))
			{
				if((cstmr_idx>=0)&&(cstmr_idx<pLibrary->getCustomers()->size()))
				{
					pLibrary->startLoan(pLibrary->getArticles()->at(art_idx),pLibrary->getCustomers()->at(cstmr_idx));
					string tmparticle;
					tmparticle=pLibrary->getArticles()->at(art_idx)->getName();
					string tmpcustomer=pLibrary->getCustomers()->at(cstmr_idx)->getFirstName()+" "+pLibrary->getCustomers()->at(cstmr_idx)->getLastName();
					cout << "Loaned article "<<tmparticle<<" to "<<tmpcustomer;
				}
				else
				{
					cout<<"Loan failed, customer not selected properly "<<endl;;
				}
			}
			else
			{
				cout<<"Loan failed. Article not selected properly "<<endl;
			}

			break;
		case 5:
			int loan_index;

			break;
		case 6:
			cv = pLibrary->getCustomers();
			cout << "\nCustomers: \n";

			for (cu_it = cv->begin(); cu_it < cv->end(); cu_it++)
			{
				cout << " - " << (*cu_it)->getFirstName() << " "//
						<< (*cu_it)->getLastName() << " - \n";

			}
			cout << "\n\n";
			break;

		case 7:
			cout << "\nPlease give the firstname of a new customer: ";
			fflush(stdin);
							getline(cin, firstname);
			cout << "\nAnd give the lastname: ";
			fflush(stdin);
							getline(cin, lastname);
			pLibrary->addCustomer(new Customer(firstname, lastname));
			break;

		case 8:
			// remove customer
			unsigned int customer_idx;

			cout << "\nWhich customer do you want to remove";
			showCustomers(pLibrary->getCustomers());
			cout << " :";
			cin >> customer_idx;

			if ( (customer_idx > 0) && (customer_idx < pLibrary->getCustomers()->size()) )
			{
				Customer *pRemovedCustomer = pLibrary->getCustomers()->at(customer_idx);
				pLibrary->getCustomers()->erase(pLibrary->getCustomers()->begin() + customer_idx);
				delete pRemovedCustomer; ///< remember also to free memory reserved for the article

			}
			else
			{
				cout << "No such article found!\n";
			}
			break;

		case 9:
			cout << "Bye!\n\n";
			running = false;
			break;

		default: cout<<"\n This is a library, not a super market.\n Please try again.\n";
		}

	}
	//Delete dynamic objects

	for (unsigned int i=0; i < pLibrary->getArticles()->size(); i++ )
	{
		//cout << " deleting article: " << i << endl;
		delete pLibrary->getArticles()->at(i);
	}

	for (unsigned int i=0; i < pLibrary->getCustomers()->size(); i++ )
	{
		//cout << " deleting customer: " << i << endl;
		delete pLibrary->getCustomers()->at(i);
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
	cout<<"5: List loaned articles\n";
	cout<<"6: Show customers\n";
	cout<<"7: Add a customer\n";
	cout<<"8: Remove customer\n";
	cout<<"9: Exit\n";
	cout<<":";
	cin>>selection;

	return selection;
}


void showArticles(vector<Article *> *pArticles)
{
	vector<Article *>::iterator ar_it;
	cout << "\n";

	int i = 0;
	for (ar_it = pArticles->begin(); ar_it < pArticles->end(); ar_it++)
	{
		cout << " " << i++ << ": " ;

		if ((*ar_it)->getType() == Article::BOOK)
			cout << "Book";
		else if ((*ar_it)->getType() == Article::MOVIE)
			cout << "Movie";
		else if ((*ar_it)->getType() == Article::CD)
			cout << "CD";
		else cout << "Other";

		cout << " : " << (*ar_it)->getName() << " - \n";
	}

}

void showCustomers(vector<Customer *> *pCustomers)
{
	vector<Customer *>::iterator cu_it;
	cout << "\n";

	int i = 0;

	for (cu_it = pCustomers->begin(); cu_it < pCustomers->end(); cu_it++)
	{
		cout << " " << i++ << ": " << (*cu_it)->getFirstName() << " "//
				<< (*cu_it)->getLastName() << " - \n";

	}
}

void showLoans(vector<Loan *> *pLoans)
{
	vector<Loan *>::iterator lo_it;
	cout<<"\n";

	for(lo_it=pLoans->begin();lo_it<pLoans->end();lo_it++)
	{
		//cout <<(*lo_it)->getArticle()->getName() <<" is loaned to Customer: "<<(*lo_it)->getCustomer()->getFirstName()<<" "<<(*lo_it)->getCustomer()->getLastName();
	}
}
