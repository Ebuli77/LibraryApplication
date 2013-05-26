/*
 * Loan.h
 *
 *  Created on: 21.5.2013
 *      Author: Marko Kaikkonen
 */

#ifndef LOAN_H_
#define LOAN_H_

#include <ctime>
class Customer;
class Article;

class Loan
{
private:
	Customer *customer;
	Article *article;
	time_t loan_start_time;
	int renew_count;
public:
	Loan(Article *article, Customer *customer);
	Customer *getCustomer() const;
	Article *getArticle() const;
	bool renewLoan();
	bool isExpired();
	virtual ~Loan();
};

#endif /* LOAN_H_ */
