/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on February 2nd, 2016, 8:20 AM
    Purpose:  Calculate the Population Standard Deviation
              using a standard normal trick
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
const int MAXRND=pow(2,31)-1;

//Function prototypes
void fillAry(float [],int);
void prntAry(float [],int,int);
float mean(float [],int);
float stdev(float [],int,float);
float rnd01();
float stdNrml();
void maxmin(float[],int,float &,float &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables
    const int SIZE=500000;
    float array[SIZE];
    
    //Fill the array with random 2 digit numbers
    fillAry(array,SIZE);
    
    //Print the array
    prntAry(array,SIZE,10);
    
    //Calculate the mean and standard deviation
    float mu=mean(array,SIZE);
    float sigma=stdev(array,SIZE,mu);
    float min,max;
    maxmin(array,SIZE,min,max);
    
    //Print the array
    cout<<"The mean = "<<mu<<" and standard deviation = "<<sigma<<endl;
    cout<<"The min value = "<<min<<" The max value = "<<max<<endl;
    
    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Min Max
//Inputs:
//  a->The list of values
//  n->Number of array elements
//Outputs:
//  max->Maximum value of the distribution
//  min->Minimum value of the distribution
//******************************************************************************
void maxmin(float a[],int n,float &min,float &max){
    max=min=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max)max=a[i];
        if(a[i]<min)min=a[i];
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                    Standard Normal 
//Outputs:
//  Random number with mean=0 and stdev=1
//******************************************************************************
float stdNrml(){
    float sum=0;
    for(int i=1;i<=12;i++){
        sum+=rnd01();
    }
    return sum-6;//center the random number
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                    Random Number float between [0,1])
//Outputs:
//  What the function does
//******************************************************************************
float rnd01(){
    return static_cast<float>(rand())/MAXRND;
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
float stdev(float a[],int n,float avg){
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
float mean(float a[],int n){
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
void prntAry(float a[],int n,int perLine){
    //Loop and fill the array with random numbers
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(6)<<a[i];
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
void fillAry(float a[],int n){
    //Loop and fill the array with random numbers
    for(int i=0;i<n;i++){
        a[i]=stdNrml();//[-6,6]
    }
}