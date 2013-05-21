/*
 * Article.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "Article.h"

Article::Article(): p_customer(0), p_reserver(0)
{

}

Article::~Article()
{
	// TODO Auto-generated destructor stub
}

bool Article::isLoaned()
{
	return false;
}

bool Article::isReserved()
{
	return false;
}

bool Article::isExpired()
{
	return false;
}

Customer *Article::getCustomer()			///< returns article's current holder
{
	return 0;
}

vector<Customer *> *Article::getLoanQueue() ///< returns the waiting customer vector
{
	return 0;
}
