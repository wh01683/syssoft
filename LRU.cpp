#include "LRUPage.cpp"
#include <iostream>
#include <time.h>
using namespace std;
/**
Implementation of the Least Recently Used (LRU) algorithm used in virtual page replacement. The algorithm operates on the assumption
that a page's history of use may determine its future of use.

-- LRUTableSize             : value to keep track of the page table's size
-- LRUTable                 : pointer to an LRUPage object; used in construction of page tables
-- func


*/

class LRU{

private:
int LRUTableSize;
LRUPage * LRUTable;

public:
/** Constructor to create a new LRU page table using the LRUPage class, sets age of each page during construction
@param tableSize size of the page table to be created
@return LRU new LRU object of size tableSize
*/
LRU( int size ){
LRUTableSize = size;
LRUTable = new LRUPage[size];
 //for (int i = 0; i < size; i++){
 //LRUTable[i].access();}
}


int getSize(){return LRUTableSize;}

/** Obtains the index value of the oldest page in the page table. This is the page to be deleted and replaced
@param LRUPage object to check the age of
@return returns the index location value of the oldest page in the page table to be deleted.
*/
int getOldest(void){

long minAge = LRUTable[0].getAge(); //Intitializes minAge value as the age of the first page in the array
int increment; //keeps track of current index value
int oldestIndex; //keeps track of current index of the oldest page

        for (increment = 1; increment < LRUTableSize; increment++){ //initialized at one, because index 0's properties are already saved

            if(LRUTable[increment].getAge() < minAge){ //embedded min finder
            minAge = LRUTable[increment].getAge(); //new min age is set to age of current page
            oldestIndex = increment; //sets index tracker to current index
            }
        }
       return oldestIndex;
}

/** This is the 'guts' of the LRU algorithm so to speak. This method checks for the required page (in the form of a single
* character). If an empty page is found in the LRUPage table, the page is placed at this spot in the table. The table index is checked
* for emptiness using a boolean set value; property of the page class. See page class documentation for details.
* much of this code was copied from FIFO.cpp for the sake of uniformity, but the comparion & decision making strategy are different
@param page object required by the system
@return true if the page was already in the table and false if it was not
*/
bool checkForPage(char page){


            int inc; //incrementor
            for (int i = 0; i < getSize(); i ++){
                    if (LRUTable[i].getName() == page){
                        cout << "Found page " << page << " at pos " << i << endl;
                        LRUTable[i].access();
                        return true;
                        break;
                    }
            }
            for(inc = 0; inc < getSize(); inc ++){
                    if(LRUTable[inc].isSet() != true){ //checks whether the page was set or not
                        cout << "Empty page at " << inc << " adding page " << page << endl;
                        LRUTable[inc].setName(page); //sets name of the page at the table's current index to the name of the page replacing it
                        LRUTable[inc].access(); //sets new age for page at that location
                        return false;
                        break;
                    }
            }

            cout << "Page fault looking for: " << page << endl;
            //declares new index for oldest page, sets value using getOldest method
            LRUTable[getOldest()].setName(page); //replaces oldest page with the needed page
            cout << "Added " << page << " to " << getOldest() << " : " << LRUTable[getOldest()].getName() << endl;
            LRUTable[getOldest()].access(); //sets new age for page at that location
            return false;

    return 0;
    }

};
