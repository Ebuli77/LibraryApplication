/*
 * CD.cpp
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "CD.h"
#include <iostream>

using namespace std;

CD::CD(string name): Article(name)
{
	cout << "\nAdded CD " << name << endl;
	type=Article::CD;
	duration=0;

}

CD::~CD()
{

}

void CD::setDuration(int duration)
{
	this->duration=duration;
}

int CD::getDuration() const
{
	return this->duration;
}

void CD::setName(string name)
{
	this->name=name;
}

string CD::getName() const
{
	return this->name;
}

void CD::setAuthor(string author)
{
	this->author=author;
}

string CD::getAuthor() const
{
	return this->getAuthor();
}

void CD::setAmount(int amount)
{
	this->amount=amount;
}

int CD::getAmount() const
{
	return this->amount;
}

void CD::setLoaned(bool loaned)
{
	this->loaned=loaned;
}


bool CD::isLoaned() const
{
	return this->loaned;
}

bool CD::isExpired() const
{
	return false;
}
