
#include "WSPage.cpp"
#include <iostream>

/*
@Author: Robert Howerton
@Description: This program is designed to demonstrate the working set page replacement algorithm.
@Function: The working set algorithm employs a timer, a "working set" (hence the name), and a moving time window of fixed size T
the time window moves across the working set. If a particular page is not referenced for 4 iterations, that page's location
is automatically freed for use by another page.


--Moving Window         :int value keeping track of the page window size
--wSet                  :char array keeping a working set of all characters in the current working set
*/


class WorkingSet {

private:

    WSPage * WSTable;
    int WSTableSize;
    int t = 0;

public:

    #define MOVINGWINDOW = 4;


    WorkingSet(int size) {
        WSTableSize = size;
        WSTable = new WSPage[size];
    }


/**method to check for the requested page
//@param char: page to be checked for
//@return: true if found, false if not found
/
*/

    bool checkForPage(char page) {

        int inc; //incrementor

        for (int i = 0; i < WSTableSize; i++) {
            if (WSTable[i].getName() == page) {
                cout << "Found page " << page << " at pos " << i << endl;
                WSTable[i].ref();
                return true;
                break;
            }
        }

        for (inc = 0; inc < WSTableSize; inc++) {
            if (WSTable[inc].isSet() != true) { //checks whether the page was set or not
                cout << "Empty page at " << inc << " adding page " << page << endl;
                WSTable[inc].setName(page); //sets name of the page at the table's current index to the name of the page replacing it
                WSTable[inc].ref(); //sets new age for page at that location
                return false;
                break;
            }
        }

        cout << "Page fault looking for: " << page << endl;
        //declares new index for oldest page, sets value using getOldest method
        WSTable[getPageWithGreatestIterationsSinceLastReference()].setName(page); //replaces oldest page with the needed page
        cout << "Added " << page << " to " << getPageWithGreatestIterationsSinceLastReference() << " : " << WSTable[getPageWithGreatestIterationsSinceLastReference()].getName() << endl;
        WSTable[getPageWithGreatestIterationsSinceLastReference()].use(); //sets new age for page at that location
        return false;

        return 0;
    }


/*
 Method to cycle through the working set and delete old pages (outside time window 4)
//this method will also maintain the working set
//
//@param void
//@return void
*/

    void executor(void) {
/*
*int t is the time window incrementer
*t will start at 0 and increment to 3 over time. once 3 is reached (4 total iterations), the entire WS Table is cycled through and all pages which
//are not set are deleted.*/


        if (t == 3) {
            t = 0;
/*
If the target page is not marked AND not in the working set, delete it
*/

            for (int k = 0; k < WSTableSize; k++) {
                if (!WSTable[k].isReffed() && findInWorkingSet(WSTable[k]) == false) WSTable[k].setName('\0');
            }
        }
        else
            t++;

    }

/*
*method used to find target page in the working set
@param page to be looked for
@return boolean true if found, false if not found
*/

    bool findInWorkingSet(WSPage page) {

        for (int i = 0; i < WSTableSize; i++) {
            if (WSTable[i].isInWS()) return true;
            }

        return false;
       }

    int getPageWithGreatestIterationsSinceLastReference(){
        int tempGreatestIndex = 0;
        int tempGreatestIts = WSTable[0].getIts();
        for (int i = 0; i < WSTableSize; i ++){
            if (tempGreatestIts < WSTable[i].getIts()){
                tempGreatestIndex = i;
                tempGreatestIts = WSTable[i].getIts();
            }
        }
        return tempGreatestIndex;

    }

};





