/*
 * Article.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include <iostream>
#include "Article.h"

using namespace std;

Article::Article(string name): loan_expiration_time(0), name(name), type(NONE), loaned(false)
{
	amount=0;
}

/*
Article(string name, TYPE type, time_t loan_time): name(name), loan_time(loan_time), type(type)
{

}*/


Article::~Article()
{
	cout << "Article " << getName() << " deleted!" << endl;
	// TODO Auto-generated destructor stub
}

bool Article::isLoaned() const
{
	return false;
}

string Article::getName() const
{
	return this->name;
}

void Article::setLoaned(bool loaned)
{
	///< mark as loaned, return false is already is loaned
}

void Article::setName(string name)
{
	this->name=name;
}

void Article::setAuthor(string author)
{
	this->author=author;
}

string Article::getAuthor() const
{
	return this->author;
}

void Article::setAmount(int amount)
{
	this->amount=amount;
}

int Article::getAmount() const
{
	return this->amount;
}

/*
void Article::setType(TYPE type)
{
	this->type=type;
}
*/
Article::TYPE Article::getType() const
{
	return this->type;
}


bool Article::isExpired()const
{
	return false;
}
