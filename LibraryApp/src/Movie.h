/*
 * Movie.h
 *
 *  Created on: 21.5.2013
 *      Author: makai
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include "Article.h"

class Movie: public Article
{
private:
	int duration;	///< duration in seconds
	int ageLimit;
	string genre; // genre of the movie
public:
	Movie(string name);
	virtual ~Movie();

	void setLoaned(bool loaned); //set the loaned flag
	void setName(string name);
	string getName() const;

	void setAgeLimit(int ageLimit);
	int getAgeLimit() const;

	void setGenre(string genre);
	string getGenre() const;

	Article::TYPE getType() const;
	bool isLoaned() const; // Client can ask if book is available
	bool isExpired() const; //Client can ask if their loan is expired

};

#endif /* MOVIE_H_ */
