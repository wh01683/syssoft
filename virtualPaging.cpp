#include <iostream>
#include <string>
#include "FIFO.cpp"
#include "LRU.cpp"
#include "Optimal.cpp"

/** This is the test area for the page replacement algorithms. Each algorithm has its own page fault counter.
*/


using namespace std;

int main(){
//    string input;
//    cout << "Enter a string:\n";
//    getline(cin,input);
//    cout << "\nYou entered " <<input << endl;

    string test = "aabcaeacbdacadkacbaasa";
    int pageFaultCounterLRU = 0;
    int pageFaultCounterFIFO = 0;
    int pageFaultCounterOPT = 0;
    
/** First in First Out algorithm test area.
*/
int startFIFO = clock();
    FIFO fifo (4);
    cout << "FIFO Test Zone - Please Stand Back" << endl;
    cout << "#######################################" << endl;
    cout <<" "<<endl;
    string::iterator it;
    for(std::string::size_type i = 0; i < test.size(); ++i) {
        if (fifo.checkForPage(test[i]) == false) pageFaultCounterFIFO ++;
        fifo.checkForPage(test[i]);

        }
int endFIFO = clock() - startFIFO; //time executed
cout <<" "<<endl;
/** Least Recently Used algorithm test area.
*/
int startLRU = clock();
    LRU lru(5);
    cout << "LRU Test Zone - Please Stand Back" << endl;
    cout << "#######################################" << endl;
    for(std::string::size_type i = 0; i < test.size(); ++i) {
        if (lru.checkForPage(test[i]) == false) pageFaultCounterLRU ++;
        lru.checkForPage(test[i]);

        }

int endLRU = clock() - startLRU; //time executed


int startOPT = clock();
    OPT opt(4);
    cout << "Optimal Test Zone - Please Stand Back" << endl;
    cout << "#######################################" << endl;
    cout <<" "<<endl;
        for(std::string::size_type i = 0; i < test.size(); ++i) {
        if (opt.checkForPage(test[i]) == false) pageFaultCounterOPT ++;
        opt.checkForPage(test[i]);
        
        }

    int endOPT = clock() - startOPT; //time executed

cout <<" "<<endl;
/** Below is an extremely complex display feature for the test results*/

cout <<" "<<endl;
cout <<"######################"<<endl;
cout <<"#####Test Results#####"<<endl;
cout <<"######################"<<endl;
cout <<" "<<endl;
cout << "Execution time for FIFO algorithm: " << endFIFO << " milliseconds." << endl;
cout << "FIFO Page Faults: " << pageFaultCounterFIFO << endl;
cout <<" "<<endl;
cout << "Execution time for LRU algorithm: " << endLRU << " milliseconds." << endl;
cout << "LRU Page Faults: " << pageFaultCounterLRU << endl;
cout <<" "<<endl;
cout << "Execution time for Optimal algorithm: " << endOPT << " milliseconds." << endl;
cout << "Optimal Page Faults: " << pageFaultCounterOPT << endl;
cout <<" "<<endl;

}//end main method
