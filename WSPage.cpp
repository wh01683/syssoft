#include "Page.cpp"
#include <iostream>

class WSPage : public Page{

/** @author Robert Howerton
    @date 12/01/2014

Working Set page class which extends the Page class. This class was created to minimize redefinition errors and
*   to also give the Working Set algorithm the tools it needs to work with; namely the "iterationsSinceLastUse" variable
*
*   --iterationsSinceLastUse            :int keeps track of the number of time units elapsed since the particular page
*                                       had been called
*   --ref                               :bool keeps track of whether or not the page has been referenced or not
*   --inWS                              :bool if the page is in the WS (referenced within the last T iterations) then this
*                                       value is set to true
*   --func WSPage()                     :constructor. makes a WSPage class instance with the default reference bit set 1
*   --func getIts()                     :return int. gets iterations of current page
*   --func iterate()                    :void. iterates the page once
*   --func isReffed()                   :bool. returns whether or not the page is referenced
*   --func ref()                        :void. sets reference bit to true*
*   --func isInWS()                     :bool return to check if the page is in the working set or not
*   --func inWS()                       :sets "inWS" to true
*   --func use()                        :sets iterations to 0, ref, and inWS variables to true
* */




private:
    int iterationsSinceLastUse; //keeps track of the number of iterations since last use. this value will vary
    bool ref; //if referenced or not
    bool inWS; //if the page is in the working set, this value is true

public:

    WSPage(){
        ref = true;
        inWS = false;
    }

    int getIts(void){
        return iterationsSinceLastUse;
    }

    void iterate(void){
        iterationsSinceLastUse ++;
    }

    bool isReffed(void){
        return ref;
    }

    void reference(void){
        ref = true;
    }

    bool isInWS(void){
        return inWS;
    }

    void addToWS(void){
        inWS = true;
    }
    /* The "use" method changes the the iterations since last use to 0, and the reference and inWS variables to true
    @param void
    @return void
    * */
    void use(void){
        iterationsSinceLastUse = 0;
        ref = true;
        inWS = true;
    }
};
