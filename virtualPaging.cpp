#include <iostream>
#include <string>
#include "FIFO.cpp"
using namespace std;

int main(){
//    string input;
//    cout << "Enter a string:\n";
//    getline(cin,input);
//    cout << "\nYou entered " <<input << endl;
    string test = "abcdaec";
    FIFO fifo (4);
    string::iterator it;
    for(std::string::size_type i = 0; i < test.size(); ++i) {
        fifo.checkForPage(test[i]);
    }
}