/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on February 2nd, 2016, 8:20 AM
    Purpose:  To develop a linear search routine to find a value
              but utilizing vectors!
 */

//System Libraries
#include <iostream> //I/O
#include <iomanip>  //Formatting
#include <cstdlib>  //Random Functions
#include <ctime>    //Setting the seed with time
#include <vector>   //Dynamic array element
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void fillAry(vector<int> &);
void prntAry(vector<int> &,int);
int linSrch(vector<int> &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables
    int size=100;
    vector<int> array(size);
    
    //Fill the array with random 2 digit numbers
    fillAry(array);
    
    //Print the array
    prntAry(array,10);
    
    //Find a random value
    int val=rand()%90+10;
    cout<<endl<<val<<" found at position index = "
            <<linSrch(array,val)<<endl;
    
    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Linear Search
//Inputs:
//  a->Array or List
//  n->Size of List
//  val->Value to find
//Outputs:
//  pos->Index where value is found
//******************************************************************************
int linSrch(vector<int> &a,int val){
    for(int i=0;i<a.size()-1;i++){
        if(val==a[i])return i;
    }
    return -1;//Sentinel not found
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                     Print Array
//Inputs:
//  a->List
//  n->Size of the array
//  perLine->How many list elements per line to print
//Outputs:
//  a->Printed List
//******************************************************************************
void prntAry(vector<int> &a,int perLine){
    //Loop and fill the array with random numbers
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                     Fill Array
//Inputs:
//  a->List
//  n->Size of the array
//Outputs:
//  a->List initialized with random 2 digit numbers
//******************************************************************************
void fillAry(vector<int> &a){
    //Loop and fill the array with random numbers
    for(int i=0;i<a.size();i++){
        a[i]=rand()%90+10;//[10,99]
    }
}