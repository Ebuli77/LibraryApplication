/*
 * Article.h
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#ifndef ARTICLE_H_
#define ARTICLE_H_

#include <ctime>
#include <vector>

class Customer;

using namespace std;

class Article
{
private:
	time_t loan_time;				///< time when loan is made
	time_t loan_expiration_time;	///< expiration time

	vector<Customer *> *p_customer; ///< customer who has this loan
	vector<Customer *> *p_reserver; ///< cutomers who are waiting in queue for this loan to be returned
public:
	Article();
	virtual ~Article();

	bool isLoaned();
	bool isReserved();
	bool isExpired();

	Customer *getCustomer();			///< returns article's current holder
	vector<Customer *> *getLoanQueue(); ///< returns the waiting customer vector


};

#endif /* ARTICLE_H_ */
