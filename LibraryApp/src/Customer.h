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
	string name;
	string lastname;

	bool setArticle(Article *article);
	bool removeArticle(Article *article);

	friend class Library;
public:
	Customer();
	Customer(string name, string lastname);

	void setName(string name);
	string getName();

	void setLastname(string name);
	string getLastname();

	virtual ~Customer();



};

#endif /* CUSTOMER_H_ */
