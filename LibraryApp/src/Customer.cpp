/*
 * Customer.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include <iostream>

#include "Customer.h"

using namespace std;

Customer::Customer(): p_loans(0), name("N/A"), lastname("N/A")
{
	cout << "Customer " << name << " " << lastname << " created!" << endl;
}

Customer::Customer(string name, string lastname): p_loans(0), name(name), lastname(lastname)
{
	cout << "Customer " << name << " " << lastname << " created!" << endl;
}

Customer::~Customer()
{
	cout << "Customer " << name << " " << lastname << " deleted!" << endl;
}

void Customer::setName(string name)
{
	this->name = name;
}

string Customer::getName()
{
	return name;
}

void Customer::setLastname(string lastname)
{
	this->lastname = lastname;
}

string Customer::getLastname()
{
	return lastname;
}
