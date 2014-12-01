#include <iostream>
#include <string>
#include "FIFO.cpp"
#include "LRU.cpp"
#include "Optimal.cpp"
#include "WorkingSet.cpp"

/** This is the test area for the page replacement algorithms. Each algorithm has its own page fault counter.
*/


using namespace std;

int main(){

    string test = "aabcaeacbdacadkacbaasa";
    int pageFaultCounterLRU = 0;
    int pageFaultCounterFIFO = 0;
    int pageFaultCounterOPT = 0;
    int pageFaultCounterWS = 0;

/** First in First Out algorithm test area.*/
int startFIFO = clock();
    FIFO fifo (4);
    cout << "FIFO Test Zone - Please Stand Back" << endl;
    cout << "#######################################" << endl;
    cout <<" "<<endl;
    string::iterator it;
    for(std::string::size_type i = 0; i < test.size(); ++i) {
        if (fifo.checkForPage(test[i]) == false) pageFaultCounterFIFO ++;
        }
int endFIFO = clock() - startFIFO; //time executed
cout <<" "<<endl;
/** Least Recently Used algorithm test area.*/
int startLRU = clock();
    LRU lru(5);
    cout << "LRU Test Zone - Please Stand Back" << endl;
    cout << "#######################################" << endl;
    for(std::string::size_type i = 0; i < test.size(); ++i) {
        if (lru.checkForPage(test[i]) == false) pageFaultCounterLRU ++;

        }

int endLRU = clock() - startLRU; //time executed

int startOPT = clock();
    OPT opt(4, test.size());
    opt.getstringsize(test.size());
    cout << "Optimal Test Zone - Please Stand Back" << endl;
    cout << "#######################################" << endl;
    cout <<" "<<endl;
        for(std::string::size_type i = 0; i < test.size(); ++i) {
            opt.stringpage(test[i]); //sets up string to reference future strings
            }
        for(std::string::size_type i = 0; i < test.size(); ++i) {
            if (opt.checkForPage(test[i]) == false) {
                pageFaultCounterOPT ++;
                opt.getlocation(i); //calls location of page fault
                }
            }
        int endOPT = clock() - startOPT; //time executed
    cout <<" "<<endl;

    int startWS = clock();
    WorkingSet ws = WorkingSet(4);
    cout << "Working Set Test Zone - Please Stand Back" << endl;
    cout << "#######################################" << endl;
    cout <<" "<<endl;
    for(std::string::size_type i = 0; i < test.size(); ++i) {
        if (ws.checkForPage(test[i]) == false) pageFaultCounterWS ++;

    }

    int endWS = clock() - startWS; //time executed

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
cout << "Execution time for Working Set algorithm: " << endWS << " milliseconds." << endl;
cout << "Working Set Page Faults: " << pageFaultCounterWS << endl;
cout <<" "<<endl;
}//end main method
