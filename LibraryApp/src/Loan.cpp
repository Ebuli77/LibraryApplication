/*
 * Loan.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "Loan.h"

Loan::Loan(Article *article, Customer *customer): p_customer(customer), p_article(article), loan_start_time(0), renew_count(3)
{

}

Loan::~Loan() {
	// TODO Auto-generated destructor stub
}

