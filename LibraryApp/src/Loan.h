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
	Customer *p_customer;
	Article *p_article;
	time_t loan_start_time;
	int renew_count;
public:
	Loan(Article *article, Customer *customer);
	virtual ~Loan();
};

#endif /* LOAN_H_ */
