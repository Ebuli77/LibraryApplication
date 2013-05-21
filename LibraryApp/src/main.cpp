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

using namespace std;

int main() {
	cout << "Hep" << endl;

	Library *pLibrary = new Library();

	Customer *pMarkoKaikkonen = new Customer("Marko", "Kaikkonen");
	pLibrary->addCustomer(pMarkoKaikkonen);

	Article *pBook = new Book("Kirjanen");
	pLibrary->addArticle(pBook);

	pLibrary->deleteArticle(pBook);


	delete pLibrary;
	delete pBook;
	delete pMarkoKaikkonen;
	return 0;
}
