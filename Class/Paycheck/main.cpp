/* 
    Author: Dr. Mark E. Lehr
    Created on January 5, 2016, 09:30 AM
    Purpose:  Calculate Paycheck, Straight Time
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float         payRate=1e1f;//Pay Rate in $'s/hour
    unsigned char hrsWrkd=40;  //Hours worked (hrs)

    //Calculate or map inputs to outputs
    float payChk=payRate*hrsWrkd;//Pay check ($'s)
    
    //Output the results
    cout<<"Pay Rate     = $ "<<payRate<<"'s/hr"<<endl;
    cout<<"Hours Worked =   "<<hrsWrkd<<" hrs"<<endl;
    cout<<"Hours Worked =   "<<static_cast<int>(hrsWrkd)<<" hrs"<<endl;
    cout<<"Pay Check    = $" <<payChk<<endl;

    //Exit stage right
    return 0;
}