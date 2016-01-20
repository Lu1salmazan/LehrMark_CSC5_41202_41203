/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 19, 2016, 9:10 PM
    Purpose:  Find the range of minimum and maximum output of random function
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //The problem to solve
    cout<<endl<<"Investigate the random number generator"<<endl<<endl;
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize variables for apprxPI
    unsigned int nRand;     //Number of calls to random function
    unsigned int min=rand();//Initialize the minimum value
    unsigned int max=rand();//Initialize the maximum value
    
    //Input the number of terms in the sequence
    cout<<"Input number of random calls"<<endl;
    cin>>nRand;
    
    //Find min and max
    for(int i=1;i<=nRand;i++){
        unsigned int r=rand();
        if(r>max)max=r;
        if(r<min)min=r;
    }
    
    //Output the results
    cout<<"The minimum value found = "<<min<<endl;
    cout<<"The maximum value found = "<<max<<endl;
    
    //Exit stage right
    return 0;
}