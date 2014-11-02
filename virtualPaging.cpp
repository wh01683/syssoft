#include <iostream>
#include <string>
#include "FIFO.cpp"
#include "LRU.cpp"

/** This is the test area for the page replacement algorithms. Each algorithm has its own page fault counter.
*/


using namespace std;

int main(){
//    string input;
//    cout << "Enter a string:\n";
//    getline(cin,input);
//    cout << "\nYou entered " <<input << endl;

    string test = "abcdaeabbbeeeeac";
    int pageFaultCounterLRU = 0;
    int pageFaultCounterFIFO = 0;

/** First in First Out algorithm test area.
*/
    FIFO fifo (4);
    string::iterator it;
    for(std::string::size_type i = 0; i < test.size(); ++i) {
        fifo.checkForPage(test[i]);
        if (fifo.checkForPage(test[i]) == false) pageFaultCounterFIFO ++;
        }
cout << pageFaultCounterFIFO << endl;



/** Least Recently Used algorithm test area.
*/
    LRU lru (4);
    for(std::string::size_type i = 0; i < test.size(); ++i) {
        lru.checkForPage(test[i]);
        if (lru.checkForPage(test[i]) == false) pageFaultCounterLRU ++;
        }
cout << pageFaultCounterLRU << endl;


}//end main method
