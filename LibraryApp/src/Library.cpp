/*
 * Library.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "Library.h"

Library::Library()
{
	// TODO Auto-generated constructor stub

}

Library::~Library()
{
	// TODO Auto-generated destructor stub
}

// library content handlers
bool Library::addArticle(Article *article)
{
	return false;
}

bool Library::deleteArticle(Article *article)
{
	return false;
}

vector<Article *> *Library::getArticles()
{
	return 0;
}

// customer handlers
bool Library::addCustomer(Customer *customer)
{
	return 0;
}

bool Library::deleteCustomer(Customer *customer)
{
	return false;
}

// loan operations
bool Library::setLoan(Article *article, Customer *customer)
{
	return false;
}

bool Library::returnLoan(Article *article)
{
	return false;
}

bool Library::updateLoan(Article *article)
{
	return false;
}
