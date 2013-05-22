/*
 * Library.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include <iostream>
#include "Library.h"
#include "Customer.h"
#include "Article.h"
#include "Loan.h"

using namespace std;


Library::Library()
{
	p_articles = new vector<Article *>();
	p_customers = new vector<Customer *>();
	p_loans = new vector<Loan *>();

	cout << "Library created!" << endl;
}

Library::~Library()
{
	delete p_articles;
	delete p_customers;
	delete p_loans;

	cout << "Library deleted!" << endl;
}

// library content handlers
bool Library::addArticle(Article *article)
{
	p_articles->push_back(article);
	return true;
}

/*
 * Deletes article from Library's database
 *
 * @param[in] article pointer to article object
 * @returns true if article was found and deletion succeed, false otherwise
 */
bool Library::deleteArticle(Article *article)
{
	if ( !article )
		return false;

	//cout << "Library: poistetaan teos " << article->getName() << "." << endl;
	for (unsigned int i=0; i < p_articles->size(); i++)
	{
		if ( article == p_articles->at(i) )
		{
			cout << "  " << "teos poistettu!" << endl;
			return true;
		}

	}
	return false;
}

vector<Article *> *Library::getArticles()
{
	return p_articles;
}

// customer handlers
bool Library::addCustomer(Customer *customer)
{
	// should we check if customer already exists?
	p_customers->push_back(customer);

	return 0;
}

bool Library::deleteCustomer(Customer *customer)
{
	if ( !customer )
		return false;

	cout << "Library: poistetaan asiakas " << customer->getName() << " " << customer->getLastname() << "." << endl;
	for (unsigned int i=0; i < p_customers->size(); i++)
	{
		if ( customer == p_customers->at(i) )
		{
			cout << "  " << "asiakas poistettu!" << endl;
			return true;
		}

	}
	return false;
}

// loan operations
bool Library::startLoan(Article *article, Customer *customer)
{
	cout << "*** FUNC: " << __FUNCTION__ << "***" << endl;

	if ( (article == 0 ) || (customer == 0) )
		return false;

	p_loans->push_back(new Loan(article, customer));

	return true;
}

bool Library::returnLoan(Article *article)
{
	return false;
}

bool Library::updateLoan(Article *article)
{
	return false;
}

vector<Article *> *Library::getExpired()
{
	return 0;
}
