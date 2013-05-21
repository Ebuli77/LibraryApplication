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
	int duration;	///< duration in seconds
public:
	CD(string name);
	virtual ~CD();
};

#endif /* CD_H_ */
