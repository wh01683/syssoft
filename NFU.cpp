#include <iostream>
#include "Page.cpp"

using namespace std;

class NFU {

private:
	int nfuTableSize;
	int leastRecentPage;
	int count;
	int locat;
	int g;
	int stringS;
	Page * nfuTable;
	Page * nfuTableString;
	
public:
	
	int Value[5];
	NFU(int size, int fsize) {
	nfuTableSize = size;
	nfuTable = new Page[size];
	nfuTableString = new Page[fsize];
	count = 0;
	g = 0;
	}
	int getSize() {return nfuTableSize;}
	
	int getLeastRecentPage(void) { 

	int leastRecent; //keeps track of current index of the page that occurs the least
	for (int i = 0; i < getSize(); i ++) {
	count = 0;
cout << "location " << locat << endl;
	for (int z = 0; z < locat; z ++) {
//compares the value
//cout << "nfuTable[i].getName() " << nfuTable[i].getName() << " nfuTableString[z].getName() " << nfuTableString[z].getName() << endl;
	if (nfuTable[i].getName() == nfuTableString[z].getName()) 		{ 
		count = count + 1; 
		Value[i] = count;
		}
	}
	cout <<  nfuTable[i].getName() << " has " << Value[i] << 	endl;
	}
//Compare each value in the array and then figure out which one occurs the least often. It will then return the one that is and replace it.
	for (int i = 1; i < getSize(); i ++){
	leastRecent = 0;
		if (Value[leastRecent] < Value[i]){
		leastRecent = i;
		}
	}
	return leastRecent;
	}//leastrecent return

	void getLocation(int location) {
	locat = location;
	}

	void getStringSize(int string) {
	stringS = string;
	}

	void stringPage(char page) {
	for(int i = g; i < stringS; i++) {
		nfuTableString[i].setName(page);
		break;
		}
	g = g + 1;
	}
	bool checkForPage(char page) {
	int current;
	int spot;
		for(current = 0; current < getSize(); current++) {
		if(nfuTable[current].isSet() != true){ //checks whether the page was set or not
	cout << "Empty page at " << current << " adding page " << 	page << endl;
	nfuTable[current].setName(page); //sets name of the page at the table's current index to the name of the page replacing it
	return false;
	}
	if (nfuTable[current].getName() == page){
	cout << "Found page " << page << " at pos " << current << 	endl;
	return true;
	}
}
	cout << "Page fault looking for: " << page << endl;
//changes new index for furthest page, sets value using getFurthest method
	nfuTable[getLeastRecentPage()].setName(page); //replaces furthest page with the needed page
	cout << "Added " << page << " to " << getLeastRecentPage() 	<< " : " << nfuTable[getLeastRecentPage()].getName() << endl;
	return false;
	}
};
