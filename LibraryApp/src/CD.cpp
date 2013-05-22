/*
 * CD.cpp
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "CD.h"

CD::CD(string name): Article(name)
{
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
