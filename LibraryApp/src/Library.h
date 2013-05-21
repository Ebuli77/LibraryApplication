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
class Customer;

using namespace std;

class Library
{
private:
	vector<Article *> *p_articles;
	vector<Customer *> *p_customers;
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

	// loan operations
	bool setLoan(Article *article, Customer *customer);
	bool returnLoan(Article *article);
	bool updateLoan(Article *article);


};

#endif /* LIBRARY_H_ */
