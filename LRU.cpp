#include "LRUPage.cpp"
#include <iostream>
#include <time.h>
using namespace std;


class LRU{

private:
long timeOfUse;
int LRUTableSize;

public:

LRUPage *LRUTable;

//constructor used to create a table of pages specific to
//the LRU class


LRU(int tableSize){

LRUTableSize = tableSize;
LRUTable = new LRUPage[tableSize];

    for (int i = 0; i < tableSize; i++){
        LRUTable[i].setAge(std::clock());
        }

}
/*
returns the oldest page in the table

*/
int getOldest(LRUPage *table){

long minAge = table[0].getAge();
int increment;
int oldestIndex;
LRUPage oldest;

        for (increment = 1; increment < LRUTableSize; increment++){

            if(LRUTable[increment].getAge() < minAge){
            oldest = LRUTable[increment];
            minAge = oldest.getAge();
            oldestIndex = increment;
            }
        }

return oldestIndex;

}


bool checkForPage(char page){

int inc;

    for(inc = 0; inc < LRUTableSize; inc ++){
        if(!LRUTable[inc].isSet()){
                    cout << "Empty page at " << inc << " adding page " << page << endl;
                    LRUTable[inc].setName(page);
                    return false;
                }
                if (LRUTable[inc].getName() == page){
                    cout << "Found page " << page << " at pos " << inc << endl;
                    return true;
                }
            }
            cout << "Page fault looking for: " << page << endl;
            int oldestPage = getOldest(LRUTable);
            LRUTable[oldestPage].setName(page);
            cout << "Added " << page << " to " << oldestPage << " : " << LRUTable[oldestPage].getName() << endl;
            LRUTable[oldestPage].setAge(std::clock());
            return false;
}



};
