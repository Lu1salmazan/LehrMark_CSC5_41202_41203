/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 19, 2016, 10:40 AM
    Purpose:  Factorial
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    unsigned int n,factN=1;//N and N!
    
    //Input data
    cout<<"Enter the number you would like to compute the factorial n!"<<endl;
    cout<<"The limit of this calculation is <=13"<<endl;
    cin>>n;
    
    //Calculate the factorial
    for(int i=1;i<=n;i++){
        factN*=i;
    }
    
    //Output the results
    cout<<n<<"!="<<factN<<endl;

    //Exit stage right
    return 0;
}