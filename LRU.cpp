#include "LRUPage.cpp"
#include <iostream>
#include <time.h>
using namespace std;
/**
Abstract: Implementation of the Least Recently Used (LRU) algorithm used in virtual page replacement. The algorithm operates 
on the assumption that a page's history of use may determine its future of use.

-- LRUTableSize             : value to keep track of the page table's size
-- LRUTable                 : pointer to an LRUPage object; used in construction of page tables
-- func getOldest           : Checks the table for the oldest page based on the age set during construction and
                              during page replacement. The function utilizes a minimum finding method and returns the
                              table index of the oldest page found. Finds oldest based on the minimum age value based
                              on the fact that time is incremental and grows larger with age; hence, the lowest age value
                              is also the oldest
-- func checkForPage        : checks the table for the page required. If the required page is not in the table, AND
                              there is space in the table, the function will place the required page in an empty spot.
                              If the table is already full, the function then checks the table for the oldest page 
                              using the getOldest method and will replace the oldest page with the page required.


*/

class LRU{

private:
int LRUTableSize;

public:
LRUPage *LRUTable;


/** Constructor to create a new LRU page table using the LRUPage class, sets age of each page during construction
@param tableSize size of the page table to be created
@return LRU new LRU object of size tableSize
*/
LRU(int tableSize){

LRUTableSize = tableSize;
LRUTable = new LRUPage[tableSize];

    for (int i = 0; i < tableSize; i++){
        LRUTable[i].setAge(std::clock());

        }

}

/** Obtains the index value of the oldest page in the page table. This is the page to be deleted and replaced
@param LRUPage object to check the age of
@return returns the index location value of the oldest page in the page table to be deleted.
*/
int getOldest(LRUPage *table){
/*
*
*/
long minAge = table[0].getAge(); //Intitializes minAge value as the age of the first page in the array
int increment; //keeps track of current index value
int oldestIndex; //keeps track of current index of the oldest page

        for (increment = 1; increment < LRUTableSize; increment++){ //initialized at one, because index 0's properties are already saved

            if(LRUTable[increment].getAge() < minAge){ //embedded min finder
            minAge = LRUTable[increment].getAge(); //new min age is set to age of current page
            oldestIndex = increment; //sets index tracker to current index
            }
        }
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

    for(inc = 0; inc < LRUTableSize; inc ++){
        if(!LRUTable[inc].isSet()){ //checks whether the page was set or not
                    cout << "Empty page at " << inc << " adding page " << page << endl;
                    LRUTable[inc].setName(page); //sets name of the page at the table's current index to the name of the page replacing it
                    return false;
                }
                if (LRUTable[inc].getName() == page){
                    cout << "Found page " << page << " at pos " << inc << endl;
                    return true;
                }
            }
            cout << "Page fault looking for: " << page << endl;
            int oldestPage = getOldest(LRUTable); //declares new index for oldest page, sets value using getOldest method
            LRUTable[oldestPage].setName(page); //replaces oldest page with the needed page
            cout << "Added " << page << " to " << oldestPage << " : " << LRUTable[oldestPage].getName() << endl;
            LRUTable[oldestPage].setAge(std::clock()); //sets new age for page at that location
            return false;
}

};
