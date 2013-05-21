/*
 * Article.cpp
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#include "Article.h"

using namespace std;

Article::Article(string name): loan_expiration_time(0), name(name), type(NONE), loaned(false)
{

}

/*
Article(string name, TYPE type, time_t loan_time): name(name), loan_time(loan_time), type(type)
{

}
*/

Article::~Article()
{
	// TODO Auto-generated destructor stub
}

bool Article::isLoaned()
{
	return false;
}
