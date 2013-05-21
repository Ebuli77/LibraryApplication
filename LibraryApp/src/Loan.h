/*
 * Loan.h
 *
 *  Created on: 21.5.2013
 *      Author: Marko Kaikkonen
 */

#ifndef LOAN_H_
#define LOAN_H_

class Customer;
class Article;

class Loan
{
private:
	Customer *p_customer;
	Article *p_article;
public:
	Loan(Customer *customer, Article *article);
	virtual ~Loan();
};

#endif /* LOAN_H_ */
