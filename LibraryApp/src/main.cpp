//============================================================================
// Name        : main.cpp
// Authors      : Tomi Lammi / Marko Kaikkonen / Matti Tastula
// Version     : 0.1
// Copyright   : 
// Description : Library Application
//============================================================================

#include <iostream>

#include "Library.h"
using namespace std;

int main() {
	Library *pLibrary = new Library();
	cout << "Hep" << endl;

	delete pLibrary;
	return 0;
}
