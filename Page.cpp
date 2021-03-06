#include <string>
#ifndef PAGE_CPP
#define PAGE_CPP
using namespace std;

/** @author Trent Holiday, Robert Howerton, Jared Baker
    @date 12/01/2014
* Basic implementation of a virtual memory page.
*
* -- pageName                   : Char representing name of the page
* -- func getName()             : Method to get the name of the Page.
* -- func setName(string)       : Used to set the name of the Page.
* -- func isSet()               : Helper method to check whether the Page has been given a value yet.
*
*/

class Page{

    private:
        char pageName;

    public:
        char getName(void) {
            return pageName;
        }
        void setName(char name){
            pageName = name;
        }
        bool isSet(void){
            return pageName != '\0';
        }
};

#endif
