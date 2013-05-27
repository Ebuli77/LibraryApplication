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
	articles = new vector<Article *>();
	customers = new vector<Customer *>();
	loans = new vector<Loan *>();

	//cout << "Library created!" << endl;
}

Library::~Library()
{
	delete articles;
	delete customers;
	delete loans;

	//cout << "Library deleted!" << endl;
}

// library content handlers
bool Library::addArticle(Article *article)
{
	cout << "Adding article " << article->getName();
	articles->push_back(article);
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

	//cout << "*** FUNC: " << __FUNCTION__ << "***" << endl;

	vector<Article *>::iterator arti_itr;
	for (arti_itr = articles->begin(); arti_itr < articles->end(); arti_itr++)
	{
		if ( (*arti_itr) == article)
		{
			cout << "  Article " << (*arti_itr)->getName() << " found and deleted!" << endl;
			return true;
		}
	}

	return false;
}

vector<Article *> *Library::getArticles()
{
	return articles;
}

// customer handlers
bool Library::addCustomer(Customer *customer)
{
	// should we check if customer already exists?
	customers->push_back(customer);

	return 0;
}

/**
 * Removes customer from customer container.
 *
 * Iterates through customers pointer stack and removes it when matching pointer is found.
 *
 * @param[in] customer	customer pointer
 * @return true when successful
 */
bool Library::deleteCustomer(Customer *customer)
{
	if ( !customer )
		return false;

	//cout << "*** FUNC: " << __FUNCTION__ << "***" << endl;

	vector<Customer *>::iterator cust_itr;
	for (cust_itr = customers->begin(); cust_itr < customers->end(); cust_itr++)
	{
		if ( (*cust_itr) == customer)
		{
			cout << "  Customer " << (*cust_itr)->getLastName() << " found and deleted!" << endl;
			return true;
		}
	}

	return false;
}

vector<Customer *> *Library::getCustomers()
{
	return customers;
}

vector<Loan *> *Library::getLoans()
{
	return loans;
}

/**
 * Starting loan operation.
 *
 * Pushes new Loan object containing article and customer object pointers
 * to p_loans pointer stack. Article and customer must exist in Librarys
 * database.
 *
 * @param[in] article	article pointer
 * @param[in] customer	customer pointer
 * @return true when successful
 */
bool Library::startLoan(Article *article, Customer *customer)
{
	//cout << "*** FUNC: " << __FUNCTION__ << "***" << endl;

	if ( (article == 0 ) || (customer == 0) )
		return false;

	loans->push_back(new Loan(article, customer));

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


