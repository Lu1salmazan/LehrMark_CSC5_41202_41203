/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 19, 2016, 8:40 PM
    Purpose:  Calculate PI
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants
const float PI=4*atan(1);

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //The problem to solve
    cout<<endl<<"Solution to Savitch 8thEd Chap3 Prob12"<<endl;
    cout<<endl<<"The finite sum for PI"<<endl<<endl;
    
    //Declare and initialize variables for apprxPI
    float apprxPI=1;    //Approximate value of PI to start
    unsigned int nTerms;//Number of terms to limit sum of PI
    char sign=-1;       //Alternating sign of the PI sequence
    
    //Input the number of terms in the sequence
    cout<<"Input number of Terms to approximate PI"<<endl;
    cin>>nTerms;
    
    //Approximate PI/4
    for(int i=2,j=3;i<=nTerms;i++,j+=2){
        apprxPI+=(sign/static_cast<float>(j));
        sign*=-1;
    }
    apprxPI*=4;//Multiply by 4 once to approximate PI
    
    //Output the results
    cout<<"The exact  value of PI="<<PI<<endl;
    cout<<"The number of terms it took to approx PI="<<nTerms<<endl;
    cout<<"The approx value of PI="<<apprxPI<<endl<<endl;
    
    //Exit stage right
    return 0;
}