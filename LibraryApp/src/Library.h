/*
 * Library.h
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <vector>

class Article;
class Loan;
class Customer;

using namespace std;

class Library
{
private:
	vector<Article *> *articles;
	vector<Customer *> *customers;
	vector<Loan *> *loans;

public:
	Library();
	virtual ~Library();

	// library content handlers
	bool addArticle(Article *article);
	bool deleteArticle(Article *article);
	vector<Article *> *getArticles();

	// customer handlers
	bool addCustomer(Customer *customer);
	bool deleteCustomer(Customer *customer);
	vector<Customer *> *getCustomers();


	vector<Loan *> *getLoans();

	// loan operations
	bool startLoan(Article *article, Customer *customer);
	bool returnLoan(Article *article);
	bool updateLoan(Article *article);

	// return vector table of expired tables. creates new dynamic table with expired articles.
	// client must release memory with delete.
	vector<Article *> *getExpired();


};

#endif /* LIBRARY_H_ */
