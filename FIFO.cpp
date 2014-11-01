#include "Page.cpp"
#include <iostream>
using namespace std;

/**
* Implementation of First In First Out virtual memory replacement algorithm.
* Initialize the object with the number of pages you want to keep stored in the page table.
*
* -- firstPageIndex             : Integer value representing the location of the oldest or first page inserted in the table
* -- pageTableSize              : The size of the array of Pages
*
* -- func getFirstPage          : returns the index of the oldest page
* -- func incrementFirstPage    : Used to set the index position for the new oldest page. If the current oldest page is
*                                 at the end of the array it will set the index position to the beginning.
* -- func checkForPage          : Takes a given char value and loops through the array of pages looking for a matching page.
*                                 If it finds an empty element in the Page array it adds the specified page to that position.
*                                 If it finds a matching page then it does nothing. If it cannot find the page in the array
*                                 then that means we have a page fault and it will replace the oldest page with the page we
*                                 are looking for.
*/
class FIFO{
    private:
        int firstPageIndex;
        int pageTableSize;
    public:
        Page *pageTable;
        FIFO(int tableSize){
            pageTableSize = tableSize;
            pageTable = new Page[tableSize];
            firstPageIndex = 0;
        }
        int getFirstPage(void){
            return firstPageIndex;
        }
        void incrementFirstPage(void){
            if(firstPageIndex == pageTableSize-1){
                firstPageIndex = 0;
            }else{
                firstPageIndex++;
            }
        }
        bool checkForPage(char page){
            int ele;
            for(ele=0; ele < pageTableSize; ele++){
                if(!pageTable[ele].isSet()){
                    cout << "Empty page at " << ele << " adding page " << page << endl;
                    pageTable[ele].setName(page);
                    return false;
                }
                if (pageTable[ele].getName() == page){
                    cout << "Found page " << page << " at pos " << ele << endl;
                    return true;
                }
            }
            cout << "Page fault looking for: " << page << endl;
            pageTable[getFirstPage()].setName(page);
            cout << "Added " << page << " to " << getFirstPage() << " : " << pageTable[getFirstPage()].getName() << endl;
            incrementFirstPage();
            return false;
        }

};