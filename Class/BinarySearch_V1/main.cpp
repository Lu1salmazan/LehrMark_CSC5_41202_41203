/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on February 2nd, 2016, 8:20 AM
    Purpose:  To develop a searching routine called Binary Search
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
void markSrt(int [],int);
int  binSrch(int [],int,int);

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
    markSrt(array,SIZE);
    
    //Print the array
    prntAry(array,SIZE,10);
    
    //Randomly create to find and do the Binary Search
    int val=rand()%90+10;//[10,99]
    cout<<val<<" was found int the Array at position = "
            <<binSrch(array,SIZE,val)<<endl;
    
    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Binary Search
//Inputs:
//  a->Array or List
//  n->Size of List
//Outputs:
//  pos->Where the value was found
//******************************************************************************
int binSrch(int a[],int n,int val){
    //Declare some variables
    unsigned int rngBeg=0,rngEnd=n-1;
    //Loop until found, or exit
    do{
        int middle=(rngEnd+rngBeg)/2;
        if(a[middle]==val)return middle;
        else if(a[middle]>val)rngEnd=middle-1;
        else rngBeg=middle+1;
    }while(rngBeg<=rngEnd);
    return -1;//Not found
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                      Mark Sort
//Inputs:
//  a->Array or List
//  n->Size of List
//Outputs:
//  a->Sorted Array
//******************************************************************************
void markSrt(int a[],int n){
    //Find smallest in each successive list
    //From the beginning of the list to the end
    //Outside Element of the list
    for(int i=0;i<n-1;i++){
        //Inside List above the Element
        for(int j=i+1;j<n;j++){
            //Swap
            if(a[i]>a[j]){
                int temp =a[j];
                a[j]=a[i];
                a[i]=temp;//Exclusive or XOR a=b
            }
        }
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