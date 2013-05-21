/*
 * Article.h
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#ifndef ARTICLE_H_
#define ARTICLE_H_

#include <ctime>
#include <vector>
#include <string>

class Customer;

using namespace std;

class Article
{
public:

	enum TYPE {
		NONE,
		BOOK,
		CD,
		MOVIE
	};

private:
	time_t loan_expiration_time;	///< expiration time
	string name;					///< name of article
	TYPE type;
	bool loaned;

protected:
	void setLoaned(bool loaned);	///< mark as loaned, return false is already is loaned

	void setName(string name);
	string getName();

	void setType(TYPE type);
	void getType();



public:

	Article(string name);
	//Article(string name, TYPE type, time_t loan_time);
	virtual ~Article();

	bool isLoaned();
	bool isExpired();

	friend class Library;
};

#endif /* ARTICLE_H_ */
