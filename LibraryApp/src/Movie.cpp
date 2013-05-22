/*
 * Movie.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "Movie.h"

Movie::Movie(string name): Article(name)
{
	// TODO Auto-generated constructor stub
	duration=0;
	ageLimit=0;
	genre = " ";
}

Movie::~Movie()
{
	// TODO Auto-generated destructor stub
}

void Movie::setLoaned(bool loaned)
{
	this->loaned=loaned;
}

bool Movie::isLoaned() const
{
	return this->loaned;
}

bool Movie::isExpired() const
{
	return false;
}

void Movie::setName(string name)
{
	this->name=name;
}

string Movie::getName() const
{
	return this->name;
}

void Movie::setAuthor(string author)
{
	this->author=author;
}

string Movie::getAuthor()const
{
	return this->author;
}

void Movie::setAmount(int amout)
{
	this->amount=amount;
}

int Movie::getAmount() const
{
	return this->amount;
}

Article::TYPE Movie::getType() const
{
	return this->type;
}

void Movie::setGenre(string genre)
{
	this->genre=genre;
}
string Movie::getGenre() const
{
	return this->genre;
}

void Movie::setAgeLimit(int agelimit)
{
	this->ageLimit=agelimit;
}

int Movie::getAgeLimit() const
{
	return this->ageLimit;
}
