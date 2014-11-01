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
*
*/
class LRUPage : public Page{
private:
    bool marked;
public:
    LRUPage(string name) : Page(name){
        marked = true;
    }
    bool isMarked(void){
        return marked;
    }
    void mark(void){
        marked=true;
    }
    void unmark(void){
        marked=false;
    }
};