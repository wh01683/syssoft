#include "LRUPage.cpp"
#include <iostream>

/**
@Author: Robert Howerton
@Description: This program is designed to demonstrate the working set page replacement algorithm.
@Function: The working set algorithm employs a timer, a "working set" (hence the name), and a moving time window of fixed size T
the time window moves across the working set. If a particular page is not referenced for 4 iterations, that page's location
is automatically freed for use by another page.


--Moving Window         :int value keeping track of the page window size
--wSet                  :char array keeping a working set of all characters in the current working set


*/
class WorkingSet{

final int MovingWindow = 4;

private:

LRUPage * WSTable;
int WSTableSize;

public:

/** Constructor to create a new working set
@param size for new working set implementation
@return new working set
*/
WorkingSet(int size){
WSTableSize = size;
WorkingSet = new LRUPage(size);
}


/**method to check for the requested page
@param char: page to be checked for
@return: true if found, false if not found
*/
bool checkForPage(char page){

            int inc; //incrementor
            for (int i = 0; i < getSize(); i ++){
                    if (WorkingSet[i].getName() == page){
                        cout << "Found page " << page << " at pos " << i << endl;
                        WorkingSet[i].access();
                        return true;
                        break;
                    }
            }
            for(inc = 0; inc < getSize(); inc ++){
                    if(WorkingSet[inc].isSet() != true){ //checks whether the page was set or not
                        cout << "Empty page at " << inc << " adding page " << page << endl;
                        WorkingSet[inc].setName(page); //sets name of the page at the table's current index to the name of the page replacing it
                        WorkingSet[inc].access(); //sets new age for page at that location
                        return false;
                        break;
                    }
            }

            cout << "Page fault looking for: " << page << endl;
            //declares new index for oldest page, sets value using getOldest method
            WorkingSet[getOldest()].setName(page); //replaces oldest page with the needed page
            cout << "Added " << page << " to " << getOldest() << " : " << WorkingSet[getOldest()].getName() << endl;
            WorkingSet[getOldest()].access(); //sets new age for page at that location
            return false;

    return 0;
    }



}
/** Method to cycle through the working set and delete old pages (outside time window 4)
@param void
@return void
*/
void executor(void){


}




}
