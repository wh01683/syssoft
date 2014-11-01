#include <string>
using namespace std;

/**
* Basic implementation of a virtual memory page.
* -- pageName : String containing the name of the page
*
*/
class Page{
    private:
        string pageName;

    public:
        Page(string name){
            pageName = name;
        }
        string getName(void) {
            return pageName;
        }
};