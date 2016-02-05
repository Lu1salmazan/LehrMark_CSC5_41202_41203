/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on February 2nd, 2016, 8:20 AM
    Purpose:  Calculate the Population Standard Deviation
 */

//System Libraries
#include <iostream> //I/O
#include <iomanip>  //Formatting
#include <cstdlib>  //Random Functions
#include <ctime>    //Setting the seed with time
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
float mean(int [],int);
float stdev(int [],int,float);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables
    const int SIZE=100;
    int array[SIZE];
    
    //Fill the array with random 2 digit numbers
    fillAry(array,SIZE);
    
    //Print the array
    prntAry(array,SIZE,10);
    
    //Calculate the mean and standard deviation
    float mu=mean(array,SIZE);
    float sigma=stdev(array,SIZE,mu);
    
    //Print the array
    cout<<"The mean = "<<mu<<" and standard deviation = "<<sigma<<endl;
    
    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Standard Deviation
//Inputs:
//  a->The list of values
//  n->Number of array elements
//  avg->The mean of the distribution
//Outputs:
//  std->The standard deviation of the distribution
//******************************************************************************
float stdev(int a[],int n,float avg){
    float sum2=0;
    for(int i=0;i<n;i++){
        sum2+=((a[i]-avg)*(a[i]-avg));
    }
    return sqrt(sum2/n);
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Mean
//Inputs:
//  a->The list of values
//  n->Number of array elements
//Outputs:
//  avg->The mean of the distribution
//******************************************************************************
float mean(int a[],int n){
    float sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return sum/n;
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
void prntAry(int a[],int n,int perLine){
    //Loop and fill the array with random numbers
    cout<<endl;
    for(int i=0;i<n;i++){
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
void fillAry(int a[],int n){
    //Loop and fill the array with random numbers
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;//[10,99]
    }
}