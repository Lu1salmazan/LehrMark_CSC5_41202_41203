/* 
    Author: Dr. Mark E. Lehr
    Created on January 5, 2016, 11:15 AM
    Purpose:  No Mistakes
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
    short c,b=20000,a=30000;

    //Calculate or map inputs to outputs
    c=a+b;
    
    //Output the results
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<c<<" = "<<a<<" + "<<b<<endl;

    //Exit stage right
    return 0;
}