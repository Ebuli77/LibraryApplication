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
	Article(Article & article); // hide copy constructor
protected:
	time_t loan_expiration_time;	///< expiration time
	string name;					///< name of article
	TYPE type;
	bool loaned;


public:
	Article(string name);

	virtual void setLoaned(bool loaned); //set the loaned flag
	virtual void setName(string name);
	virtual string getName() const;

	//virtual void setType(TYPE type);
	virtual TYPE getType() const;

	//Article(string name, TYPE type, time_t loan_time);
	virtual ~Article();

	virtual bool isLoaned() const; // Client can ask if book is available
	virtual bool isExpired() const; //Client can ask if their loan is expired

	//friend class Library;
};

#endif /* ARTICLE_H_ */
