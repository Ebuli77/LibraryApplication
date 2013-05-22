/*
 * CD.h
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#ifndef CD_H_
#define CD_H_

#include "Article.h"

class CD: public Article
{
private:
	CD(CD& cd);
	int duration;	///< duration in seconds
public:
	CD(string name);
	virtual ~CD();

	void setDuration(int duration);//set duration in seconds
	int getDuration() const; //get duration

	void setLoaned(bool loaned); //set the loaned flag
	void setName(string name);
	string getName() const;
	void setAuthor(string author);
	string getAuthor() const;
	void setAmount(int amount);
	int getAmount() const;

	//virtual void setType(TYPE type);
	Article::TYPE getType() const;

	bool isLoaned() const; // Client can ask if book is available
	bool isExpired() const; //Client can ask if their loan is expired


};

#endif /* CD_H_ */
