/*
 * Loan.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "Loan.h"

Loan::Loan(Article *article, Customer *customer): customer(customer), article(article), loan_start_time(0), renew_count(3)
{

}

Loan::~Loan()
{
	// TODO Auto-generated destructor stub
}

Customer* Loan::getCustomer()
{
	return this->customer;
}

Article* Loan::getArticle()
{
	return this->article;
}

bool Loan::renewLoan()
{
	return true;
}

bool Loan::isExpired()
{
	return true;
}
