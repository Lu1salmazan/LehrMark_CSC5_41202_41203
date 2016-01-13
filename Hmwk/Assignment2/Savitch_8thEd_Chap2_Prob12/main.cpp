/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 13, 2016, 10:52 AM
    Purpose:  Calculate the Square Root by the Babylonian/Newton's Method
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
    
    //Input data
    cout<<"Input the value to computer the sqrt of?"<<endl;
    cin>>n;
    
    //Approximate the square root first pass
    guess=n/2;//Only perform once to start the process
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output the results
    cout<<"The input value      = "<<n<<endl;
    cout<<"sqrt("<<n<<")="<<sqrt(n)<<endl;
    cout<<"The first pass r     = "<<r<<endl;
    cout<<"The first pass guess = "<<guess<<endl;
    
    //Approximate the square root second pass
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output the results
    cout<<"The second pass r     = "<<r<<endl;
    cout<<"The second pass guess = "<<guess<<endl;
    
    //Approximate the square root third pass
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output the results
    cout<<"The third pass r     = "<<r<<endl;
    cout<<"The third pass guess = "<<guess<<endl;
    
    //Approximate the square root fourth pass
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output the results
    cout<<"The fourth pass r     = "<<r<<endl;
    cout<<"The fourth pass guess = "<<guess<<endl;
    
    //Approximate the square root fifth pass
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output the results
    cout<<"The fifth pass r     = "<<r<<endl;
    cout<<"The fifth pass guess = "<<guess<<endl;
    
    //Approximate the square root sixth pass
    r=n/guess;
    guess=(guess+r)/2;
    
    //Output the results
    cout<<"The sixth pass r     = "<<r<<endl;
    cout<<"The sixth pass guess = "<<guess<<endl;

    //Exit stage right
    return 0;
}