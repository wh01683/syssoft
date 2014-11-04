#include <cstdio>
#include <ctime>
#include "Page.cpp"
using namespace std;
/**
* Implementation of a virtual memory page for the Least Recently Used algorithm (LRU).
* This class extends the Page class.
*
* -- marked             : boolean value to store whether a page has been recently accessed
* -- func isMarked()    : Check whether the page is marked.
* -- func mark()        : Function to mark a page as just accessed.
* -- func unmark()      : Set the marked attribute for the memory page to false.
* -- func setAge()      : Set the age of the page. Used when the page is accessed.
* -- func getAge()      : Returns the age of the page. Used when determining oldest page of the array.
*/
class LRUPage : public Page{

private:
    bool marked;
    long age;

public:
/** Constructs new page; marked true by default
@param none
@return new LRU page*/
    LRUPage(){
        marked = true;
    }

/** Checks whether page is marked or not
@param no parameters
@return boolean whether marked or not*/
    bool isMarked(void){
        return marked;
    }

/** Marks page
@param no parameters
@return no return*/
    void mark(void){
        marked=true;
    }

/** Unmarks page
@param no parameters
@return no return*/
    void unmark(void){
        marked=false;
    }
/** Sets new age
@param void
@return no return*/
    void access(void){
    age = std::clock();
    marked = true;
    };

/** gets age of the page
@param no parameters
@return returns age*/
    long getAge(){return age;};

};
