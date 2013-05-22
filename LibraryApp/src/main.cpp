//============================================================================
// Name        : main.cpp
// Authors      : Tomi Lammi / Marko Kaikkonen / Matti Tastula
// Version     : 0.1
// Copyright   : 
// Description : Library Application
//============================================================================

#include <iostream>

#include "Library.h"
#include "Customer.h"
#include "Book.h"

void print_articles(Library *pLib);

using namespace std;

int main() {
	cout << "Hep" << endl;

	Library *pLibrary = new Library();

	Customer *pMarkoKaikkonen = new Customer("Marko", "Kaikkonen");
	pLibrary->addCustomer(pMarkoKaikkonen);

	Article *pBook = new Book("Kirjanen");
	pLibrary->addArticle(pBook);

	if (pLibrary->startLoan(pBook, pMarkoKaikkonen))
	{
		cout << "Kirjan " << pBook->getName() << " lainaaminen onnistui henkilöllä " << pMarkoKaikkonen->getName() << " " << pMarkoKaikkonen->getLastname() << endl;
	}

	print_articles(pLibrary);



	pLibrary->deleteArticle(pBook);


	delete pLibrary;
	delete pBook;
	delete pMarkoKaikkonen;
	return 0;
}

/**
 * Prints all article names found in library
 */
void print_articles(Library *pLib)
{
	cout << "*** FUNC: " << __FUNCTION__ << "***" << endl;

	vector<Article *> *pArticles = pLib->getArticles();

	for (unsigned int i=0; i < pArticles->size(); i++ )
	{
		cout << "  " << (pArticles->at(i))->getName() << endl;
	}

}
