#include "Page.cpp"
#include <iostream>
#include <time.h>
using namespace std;
/**
Implements Optimal algorithm used in virtual page replacement. The algorythm looks into the page's future to decide what will be used
-- OPTTableSize : value to keep track of the page table's size
-- OPTTable : pointer to an Page object; used in construction of page tables
-- func
*/
class OPT {

  private:
  int OPTTableSize;
  int OPTString;
  int loc;
  Page * OPTTable;
  
  public:

/** Constructor to create a new Optimal page table using the Page class.
*/
  OPT( int size, int StringSize ){
  OPTTableSize = size;
  OPTTable = new Page[size];
  OPTString = StringSize;
  loc = 0; // 0 = loc
  }

int Value [10]; //holds value distances for table from current location.

int getSize() { return OPTTableSize; }



/** Compares each value with similar values ahead of its current location. This returns
that value that is furthest from the current. That value is to be deleted.
*/
int getFurthest(void){
        cout << "Inside getFurthest" << endl;
  int furthestaway; //keeps track of current index of the furthest page
  for (int i = 0; i < loc; i ++) {
      cout << "getFurthest i-" << i << " loc - " << loc << endl;
    for (int z = loc + 1; z < OPTString; z ++) {
        cout << "getFurthest i-" << i << ", z-" << z << endl;
      //compares the value
      if (OPTTable[i].getName() == OPTTable[z].getName()) { //I need to compare with each value that is currently ahead of its location. On the list. Is there a simple way of doing this?
          cout << "Found match for " << OPTTable[i].getName() << endl;
          Value[i] = z; //If positive, this should store how far the next similar value is from current.
      }
      else{
          cout << "Else - set value[" << i<<"]" << " to " << getSize() +1 <<endl;
        Value[i] = getSize() + 1; //If no value matches, returns the highest possible size value. Thus it will be replaced.
      }
    }
  }



//In theory, should compare each value in the array and then figure out which one is furthest away. It will then return the one that is and replace it.
  for (int i = 1; i < getSize(); i ++){
    furthestaway = Value[0];
    if (furthestaway < Value[i]){
      furthestaway = Value[i];
    }
  }
  return furthestaway;
}

bool checkForPage(char page){
  for (int i = 0; i < getSize(); i ++){
    if (OPTTable[i].getName() == page){
      cout << "Found page " << page << " at pos " << i << endl;
      return true;
      }
      else if (OPTTable[i].isSet() != true){ //checks whether the page was set or not
        cout << "Empty page at " << i << " adding page " << page << endl;
        OPTTable[i].setName(page); //sets name of the page at the table's current index to the name of the page replacing it
        return false;
    }
    else {
      loc = i;
      cout << "Page fault looking for: " << page << endl;
      //changes new index for furthest page, sets value using getFurthest method
      int furthestPosition = getFurthest();
      OPTTable[furthestPosition].setName(page); //replaces furthest page with the needed page
      cout << "Added " << page << " to " << furthestPosition << " : " << OPTTable[furthestPosition].getName() << endl;
      return false;
    }
    }
}



};

