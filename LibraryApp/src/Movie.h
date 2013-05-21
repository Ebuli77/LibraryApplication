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
public:
	Movie(string name);
	virtual ~Movie();
};

#endif /* MOVIE_H_ */
