/*
 * Book.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "Book.h"

Book::Book(string name): Article(name)
{
	pages=0;
	type=Article::BOOK;
}

Book::~Book()
{
	// TODO Auto-generated destructor stub
}

void Book::setLoaned(bool loaned)
{
	this->setLoaned(loaned);
}
bool Book::isLoaned() const
{
	return this->loaned;
}

void Book::setName(string name)
{
	this->name=name;
}

string Book::getName() const
{
	return this->name;
}

void Book::setPages(int pages)
{
	this->pages=pages;
}

int Book::getPages() const
{
	return this->pages;
}

Article::TYPE Book::getType() const
{
	return this->type;
}
