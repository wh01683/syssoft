#include <string>
using namespace std;

/**
* Basic implementation of a virtual memory page.
*
* -- pageName                   : String containing the name of the page
* -- func getName()             : Method to get the name of the Page.
* -- func setName(string)       : Used to set the name of the Page.
* -- func isSet()               : Helper method to check whether the Page has been given a value yet.
*
*/
class Page{
    private:
        string pageName;

    public:
        string getName(void) {
            return pageName;
        }
        void setName(string name){
            pageName = name;
        }
        bool isSet(void){
            return pageName.empty();
        }
};