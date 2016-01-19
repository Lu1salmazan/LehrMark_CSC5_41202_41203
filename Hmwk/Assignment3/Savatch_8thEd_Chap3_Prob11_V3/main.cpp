/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 19, 2016, 10:40 AM
    Purpose:  Calculate e^x using a tolerance and in 1 line
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
    //The problem to solve
    cout<<endl<<"Solution to Savitch 8thEd Chap3 Prob11"<<endl;
    cout<<endl<<"The finite sum for e^x"<<endl<<endl;
    //Declare and initialize variables for etox
    const unsigned char nTerms=13;
    float tol=1e-3f,term=1,etox=1,x;//e^x
    float nTerm;//Counter to determine how many terms
    //Input the value x
    cout<<"Input x of e^x computation"<<endl;
    cin>>x;
    
    //Calculate e^x
    for(nTerm=1;term>tol;term*=x/nTerm++,etox+=term);
    
    //Output the results
    cout<<"The exact  value of e^"<<x<<"="<<exp(x)<<endl;
    cout<<"The number of terms it took to approx e^"<<x<<"="<<nTerm<<endl;
    cout<<"The approx value of e^"<<x<<"="<<etox<<endl<<endl;
    
    //Exit stage right
    return 0;
}