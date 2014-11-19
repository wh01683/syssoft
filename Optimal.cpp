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
  int loc;
  Page * OPTTable;
  
  public:

/** Constructor to create a new Optimal page table using the Page class.
*/
  OPT( int size ){
  OPTTableSize = size;
  OPTTable = new Page[size];
  loc = 0; // 0 = loc
  }

int Value [10]; //holds value distances for table from current location.

int getSize() { return OPTTableSize; }



/** Compares each value with similar values ahead of its current location. This returns
that value that is furthest from the current. That value is to be deleted.
*/
int getFurthest(void){
  int furthestaway; //keeps track of current index of the furthest page
  for (int i = 0; i < getSize(); i ++) {
    for (int z = loc; z < getSize(); z ++) {
      //compares the value
      if (OPTTable[i].getName() == z.getName()) { //I need to compare with each value that is currently ahead of its location. On the list. Is there a simple way of doing this?
        Value[i] = z; //If positive, this should store how far the next similar value is from current.
      }
      else{
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
  int inc;
  for (int i = 0; i < getSize(); i ++){
    loc = loc + 1;
    if (OPTTable[i].getName() == page){
      cout << "Found page " << page << " at pos " << i << endl;
      return true;
      }
    }

  for(inc = 0; inc < getSize(); inc ++){
    loc = loc + 1;
    if(OPTTable[inc].isSet() != true){ //checks whether the page was set or not
      cout << "Empty page at " << inc << " adding page " << page << endl;
      OPTTable[inc].setName(page); //sets name of the page at the table's current index to the name of the page replacing it
      return false;
    }
  }


cout << "Page fault looking for: " << page << endl;
loc = loc + 1;
//changes new index for furthest page, sets value using getFurthest method
OPTTable[getFurthest()].setName(page); //replaces furthest page with the needed page
cout << "Added " << page << " to " << getFurthest() << " : " << OPTTable[getFurthest()].getName() << endl;
return false;
}
};

