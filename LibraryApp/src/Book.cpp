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

}

Book::~Book()
{
	// TODO Auto-generated destructor stub
}
void Book::setLoaned(bool loaned)
{
	this->setLoaned(loaned);
}
void Book::setName(string name)
{
	this->name=name;
}
void Book::setPages(int pages)
{
	this->pages=pages;
}

int Book::getPages() const
{
	return this->pages;
}
