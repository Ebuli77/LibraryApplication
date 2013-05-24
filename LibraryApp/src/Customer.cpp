/*
 * Customer.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include <iostream>

#include "Customer.h"

using namespace std;

Customer::Customer(): p_loans(0), firstname("N/A"), lastname("N/A")
{
	cout << "Customer " << firstname << " " << lastname << " created!" << endl;
}

Customer::Customer(string firstname, string lastname): p_loans(0), firstname(firstname), lastname(lastname)
{
	cout << "Customer " << firstname << " " << lastname << " created!" << endl;
}

Customer::~Customer()
{
	cout << "Customer " << firstname << " " << lastname << " deleted!" << endl;
}

void Customer::setFirstName(string firstname)
{
	this->firstname = firstname;
}

string Customer::getFirstName()
{
	return firstname;
}

void Customer::setLastName(string lastname)
{
	this->lastname = lastname;
}

string Customer::getLastName()
{
	return lastname;
}
