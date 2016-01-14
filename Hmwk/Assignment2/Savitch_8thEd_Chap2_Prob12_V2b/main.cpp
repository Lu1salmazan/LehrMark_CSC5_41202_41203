/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 13, 2016, 10:52 AM
    Purpose:  Calculate the Square Root by the Babylonian/Newton's Method
    Version 2:  Uses Loop to end calculation
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    float n;//Input the value to obtain it's square root
    float r,guess;//Intermediate values which asymptotically approach sqrt(n)
    float tol=0.001f;//Accuracy of the results/tolerance
    int   counter;//See how many loops it took to get the answer
    
    //Input data
    cout<<"Input the value to computer the sqrt of?"<<endl;
    cin>>n;
    
    //Approximate the square
    guess=n/2;//Only perform once to start the process
    r=n/guess;
    
    //Output the initial values
    cout<<"The input value      = "<<n<<endl;
    cout<<"sqrt("<<n<<")="<<sqrt(n)<<endl;
    
    //Approximate the square root
    for(counter=0;abs((r-guess)/guess)*100>tol;counter++){
        r=n/guess;
        guess=(guess+r)/2;
    }
    
    //Output the results
    cout<<"The r     = "<<r<<endl;
    cout<<"The guess = "<<guess<<endl;
    cout<<"The loop executed "<<counter<<" times"<<endl;

    //Exit stage right
    return 0;
}