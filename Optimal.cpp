#include "Page.cpp"
#include <iostream>
#include <time.h>

using namespace std;
/** @author Jared Baker
    @date 12/01/2014
Implements Optimal algorithm used in virtual page replacement. The algorythm looks into the page's future to decide what will be used
-- OPTTableSize : value to keep track of the page table's size
-- OPTTable : pointer to an Page object; used in construction of page tables
-- func
*/
class OPT {
  private:
    int OPTTableSize;
    int loc;
    int g;
    int StringSize;
    Page * OPTTable;
    Page * OPTTableString;
  public:
/** Constructor to create a new Optimal page table using the Page class.
*/
    OPT( int size, int fsize){
      OPTTableSize = size;
      OPTTable = new Page[size];
      OPTTableString = new Page[fsize];
      loc = 0;
      g = 0;
      StringSize = 0;
    }

  int Value [10]; //holds value distances for table from current location.
  int getSize() { return OPTTableSize; }
/** Compares each value with similar values ahead of its current location. This returns
that value that is furthest from the current. That value is to be deleted.
*/
  int getFurthest(void){
    int furthestaway; //keeps track of current index of the furthest page
    for (int i = 0; i < getSize(); i ++) {
    for (int z = loc + 1; z < StringSize - loc; z ++) {
//compares the value
    if (OPTTable[i].getName() == OPTTableString[z].getName()) { //I need to compare with each value that is currently ahead of its location. On the list. Is there a simple way of doing this?
      Value[i] = z; //If positive, this should store how far the next similar value is from current.
      break;
    }
    else{
      Value[i] = StringSize + 1; //If no value matches, returns the highest possible size value. Thus it will be replaced.
    }
  }
}
//Compare each value in the array and then figure out which one is furthest away. It will then return the one that is and replace it.
  furthestaway = 0;
  for (int i = 0; i < getSize(); i ++){
      if (furthestaway < Value[i]){
        furthestaway = i;
      }
    }
    return furthestaway;
  }

void getstringsize(int string){
  StringSize = string;
  }

void getlocation(int location){
  loc = location;
  }

void stringpage(char page){
  for (int i = g; i < StringSize; i ++){
    OPTTableString[i].setName(page);
    break;
    }
  g = g + 1;
}

bool checkForPage(char page){
  for (int i = 0; i < getSize(); i ++){
    if(OPTTable[i].isSet() != true){ //checks whether the page was set or not
   //   cout << "Empty page at " << i << " adding page " << page << endl;
      OPTTable[i].setName(page); //sets name of the page at the table's current index to the name of the page replacing it
      return false;
    }
  if (OPTTable[i].getName() == page){
   // cout << "Found page " << page << " at pos " << i << endl;
    return true;
    }
  }
 // cout << "Page fault looking for: " << page << endl;
//changes new index for furthest page, sets value using getFurthest method
  OPTTable[getFurthest()].setName(page); //replaces furthest page with the needed page
 // cout << "Added " << page << " to " << getFurthest() << " : " << OPTTable[getFurthest()].getName() << endl;
  return false;
  }
};


