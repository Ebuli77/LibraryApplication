/*
 * Customer.h
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <vector>
#include <string>

class Article;
using namespace std;

class Customer
{
private:
	vector<Article *> p_loans;
	string firstname;
	string lastname;

	bool setArticle(Article *article);
	bool removeArticle(Article *article);

	friend class Library;
public:
	Customer();
	Customer(string firstname, string lastname);

	void setFirstName(string firstname);
	string getFirstName();

	void setLastName(string lastname);
	string getLastName();

	virtual ~Customer();



};

#endif /* CUSTOMER_H_ */
