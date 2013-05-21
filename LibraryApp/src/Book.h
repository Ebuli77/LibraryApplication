/*
 * Book.h
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#ifndef BOOK_H_
#define BOOK_H_

#include "Article.h"

class Book: public Article
{
private:
	int pages; ///< number of pages
public:
	Book(string name);
	virtual ~Book();
};

#endif /* BOOK_H_ */
