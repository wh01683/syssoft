#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "FIFO.cpp"
#include "LRU.cpp"
#include "Optimal.cpp"
#include "WorkingSet.cpp"

/**
@author Trent Holliday, Robert Howerton, Jared Baker
@date 12/01/2014


This is the test area for the page replacement algorithms. Each algorithm has its own page fault counter.
*/


using namespace std;

int main(int argc, char* argv[]){
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    string test="";
    int numOfPages;
    srand ( time(NULL) );
    if (argc == 2) {
        test = argv[1];
    }
    else if (argc == 3) {
        test = argv[1];
        istringstream ss(argv[2]);
        if (!(ss >> numOfPages)) {
            cerr << "ERROR: Invalid number of pages '" << argv[2] << "'\n";
            return 1;
        }
    }
    else{
        int length = rand() % 16 + 5;
        int i;
        for(i=0;i<length; i++){
            char letter = alphabet[rand() % 9];
            test += letter;
        }
        numOfPages = 4;
    }

    int pageFaultCounterLRU = 0;
    int pageFaultCounterFIFO = 0;
    int pageFaultCounterOPT = 0;
    int pageFaultCounterWS = 0;

    /** First in First Out algorithm test area.*/
    int startFIFO = clock();
    FIFO fifo(numOfPages);
    cout << "Testing FIFO..." << endl;
    string::iterator it;
    for (std::string::size_type i = 0; i < test.size(); ++i) {
        if (fifo.checkForPage(test[i]) == false) pageFaultCounterFIFO++;
    }
    int endFIFO = clock() - startFIFO; //time executed
    /** Least Recently Used algorithm test area.*/
    int startLRU = clock();
    LRU lru(numOfPages);
    cout << "Testing LRU..." << endl;
    for (std::string::size_type i = 0; i < test.size(); ++i) {
        if (lru.checkForPage(test[i]) == false) pageFaultCounterLRU++;

    }

    int endLRU = clock() - startLRU; //time executed

    int startOPT = clock();
    OPT opt(numOfPages, test.size());
    opt.getstringsize(test.size());
    cout << "Testing Optimal..." << endl;
    for (std::string::size_type i = 0; i < test.size(); ++i) {
        opt.stringpage(test[i]); //sets up string to reference future strings
    }
    for (std::string::size_type i = 0; i < test.size(); ++i) {
        if (opt.checkForPage(test[i], i) == false) {
            pageFaultCounterOPT++;
        }
    }
    int endOPT = clock() - startOPT; //time executed

    int startWS = clock();
    WorkingSet ws = WorkingSet(numOfPages);
    cout << "Testing WS..." << endl;
    cout << " " << endl;
    for (std::string::size_type i = 0; i < test.size(); ++i) {
        if (ws.checkForPage(test[i]) == false) pageFaultCounterWS++;

    }

    int endWS = clock() - startWS; //time executed

    /** Below is an extremely complex display feature for the test results*/

    cout <<" "<<endl;
    cout <<"######################"<<endl;
    cout <<"#####Test Results#####"<<endl;
    cout <<"######################"<<endl;
    cout << "Page string: '" << test << "'" << endl;
    cout << "Number slots in page table: " << numOfPages << endl << endl;
    cout <<"FIFO"<<endl;
    cout <<"-------------------------"<<endl;
    cout << "Execution time for FIFO algorithm: " << endFIFO << " milliseconds." << endl;
    cout << "FIFO Page Faults: " << pageFaultCounterFIFO << endl;
    cout <<" "<<endl;
    cout <<"LRU"<<endl;
    cout <<"-------------------------"<<endl;
    cout << "Execution time for LRU algorithm: " << endLRU << " milliseconds." << endl;
    cout << "LRU Page Faults: " << pageFaultCounterLRU << endl;
    cout <<" "<<endl;
    cout <<"Optimal"<<endl;
    cout <<"-------------------------"<<endl;
    cout << "Execution time for Optimal algorithm: " << endOPT << " milliseconds." << endl;
    cout << "Optimal Page Faults: " << pageFaultCounterOPT << endl;
    cout <<" "<<endl;
    cout <<"WS"<<endl;
    cout <<"-------------------------"<<endl;
    cout << "Execution time for Working Set algorithm: " << endWS << " milliseconds." << endl;
    cout << "Working Set Page Faults: " << pageFaultCounterWS << endl;
    cout <<" "<<endl;

    return 0;
}//end main method
