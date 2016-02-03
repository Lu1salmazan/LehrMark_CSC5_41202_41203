/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on February 2nd, 2016, 8:20 AM
    Purpose:  To develop a sorting routine called Selection Sort
 */

//System Libraries
#include <iostream> //I/O
#include <iomanip>  //Formatting
#include <cstdlib>  //Random Functions
#include <ctime>    //Setting the seed with time
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void fillAry(int [],int);
void prntAry(int [],int,int);
void selSrt(int [],int);

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
    
    //Test finding the smallest element in the list
    selSrt(array,SIZE);
    
    //Print the array
    prntAry(array,SIZE,10);
    
    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Selection Sort
//Inputs:
//  a->Array or List
//  n->Size of List
//Outputs:
//  a->Sorted Array
//******************************************************************************
void selSrt(int a[],int n){
    //Find smallest in each successive list
    //From the beginning of the list to the end
    //Outside Element of the list
    for(int i=0;i<n-1;i++){
        int val=a[i],pos=i;
        //Inside List above the Element
        for(int j=i+1;j<n;j++){
            //Swap
            if(val>a[j]){
                val=a[j];pos=j;
            }
        }
        //Swap
        a[pos]=a[i];
        a[i]=val;
    }
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