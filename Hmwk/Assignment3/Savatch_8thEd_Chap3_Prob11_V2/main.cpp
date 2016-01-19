/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 19, 2016, 10:40 AM
    Purpose:  Calculate e^x
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
    float etox=1,x;//e^x
    
    //Input the value x
    cout<<"Input x of e^x computation"<<endl;
    cin>>x;
    
    //Calculate e^x
    for(int n=1;n<=nTerms;n++){
        //Declare and initialize variables
        unsigned int factN=1;//N and N

        //Calculate the factorial
        for(int i=1;i<=n;i++){
            factN*=i;
        }
        
        //Calculate e^x with the above factorial
        etox+=pow(x,n)/factN;
    }
    
    //Output the results
    cout<<"The exact  value of e^"<<x<<"="<<exp(x)<<endl;
    cout<<"The approx value of e^"<<x<<"="<<etox<<endl<<endl;
    
    //Exit stage right
    return 0;
}