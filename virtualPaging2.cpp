#include <iostream>
#include <stdlib.h>
#include <string>
#include "FIFO.cpp"
#include "LRU.cpp"
#include "Optimal.cpp"
#include "NFU.cpp"


/**
@author Trent Holliday, Robert Howerton, Jared Baker, Denzel Kent
@date 12/01/2014


This is the test area for the page replacement algorithms. Each algorithm has its own page fault counter.
*/


using namespace std;

int main(int argc, char* argv[]){
    string alphabet[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
    string test;
    if(argc > 1){
        test = argv[1];
    }else{
        int length = rand() % 15 + 5;
        int i;
        for(i=0;i<length; i++){
            test.append(alphabet[rand() % 9]);
        }
    }
    test = "abaacdedbbace";
    int numRuns = 10;
    int pageFaultCounterLRU = 0;
    int pageFaultCounterFIFO = 0;
    int pageFaultCounterOPT = 0;
    int pageFaultCounterNFU = 0;
    int pageFaultCounterWS = 0;

    /** First in First Out algorithm test area.*/
    int startFIFO = clock();
    FIFO fifo(4);
    cout << "Testing FIFO..." << endl;
    string::iterator it;
    for (std::string::size_type i = 0; i < test.size(); ++i) {
        if (fifo.checkForPage(test[i]) == false) pageFaultCounterFIFO++;
    }
    int endFIFO = clock() - startFIFO; //time executed
    /** Least Recently Used algorithm test area.*/
    int startLRU = clock();
    LRU lru(4);
    cout << "Testing LRU..." << endl;
    for (std::string::size_type i = 0; i < test.size(); ++i) {
        if (lru.checkForPage(test[i]) == false) pageFaultCounterLRU++;

    }

    int endLRU = clock() - startLRU; //time executed

    int startOPT = clock();
    OPT opt(4, test.size());
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

int startNFU = clock();
NFU nfu(4, test.size());
nfu.getStringSize(test.size());
cout << "NFU Test Zone - Stand Back Dawg" << endl;
cout << "#######################################" << endl;
cout << " " << endl;
for(std::string::size_type i = 0; i < test.size(); ++i) {
nfu.stringPage(test[i]); //sets up string to reference future strings
}
for(std::string::size_type i = 0; i < test.size(); ++i) {
nfu.getLocation(i);
if (nfu.checkForPage(test[i]) == false) {
pageFaultCounterNFU ++;
 //calls location of page fault
}
}

int endNFU = clock() - startNFU; //time executed
   /* int startWS = clock();
    WorkingSet ws = WorkingSet(4);
    cout << "Testing WS..." << endl;
    for (std::string::size_type i = 0; i < test.size(); ++i) {
        if (ws.checkForPage(test[i]) == false) pageFaultCounterWS++;

    }

    int endWS = clock() - startWS; //time executed*/

    /** Below is an extremely complex display feature for the test results*/

    cout <<" "<<endl;
    cout <<"######################"<<endl;
    cout <<"#####Test Results#####"<<endl;
    cout <<"######################"<<endl;
    cout << "Page string: " << test << endl << endl;
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
cout << "Execution time for NFU algorithm: " << endNFU << " milliseconds." << endl;
cout << "NFU Page Faults: " << pageFaultCounterNFU << endl;
cout << " "<<endl;
    /*cout <<"WS"<<endl;
    cout <<"-------------------------"<<endl;
    cout << "Execution time for Working Set algorithm: " << endWS << " milliseconds." << endl;
    cout << "Working Set Page Faults: " << pageFaultCounterWS << endl;
    cout <<" "<<endl;*/
}//end main method
