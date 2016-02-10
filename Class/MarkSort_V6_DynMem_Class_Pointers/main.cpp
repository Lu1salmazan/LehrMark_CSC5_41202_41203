/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on February 2nd, 2016, 8:20 AM
    Purpose:  To develop a sorting routine called Mark Sort
 *            using dynamic memory and a structure with pointer syntax ->,(*)
 */

//System Libraries
#include <iostream> //I/O
#include <iomanip>  //Formatting
#include <cstdlib>  //Random Functions
#include <ctime>    //Setting the seed with time
using namespace std;

//User Libraries
#include "array.h"

//Global Constants

//Function prototypes
Array *fillAry(int);
void prntAry(const Array *,int);
void markSrt(Array *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Initialize the seed
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables and initialize the size;
    Array *array=fillAry(100);
    
    //Print the array
    prntAry(array,10);
    
    //Test finding the smallest element in the list
    markSrt(array);
    
    //Print the array
    prntAry(array,10);
    
    //Reallocate memory
    delete []array->data;
    delete array;
    
    //Exit stage right
    return 0;
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
void markSrt(Array *a){
    //Find smallest in each successive list
    //From the beginning of the list to the end
    //Outside Element of the list
    for(int i=0;i<(*a).size-1;i++){
        //Inside List above the Element
        for(int j=i+1;j<a->size;j++){
            //Swap
            if((*a).data[i]>a->data[j]){
                int temp =a->data[j];
                a->data[j]=a->data[i];
                (*a).data[i]=temp;//Exclusive or XOR a=b
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
void prntAry(const Array *a,int perLine){
    //Loop and fill the array with random numbers
    cout<<endl;
    for(int i=0;i<(*a).size;i++){
        cout<<a->data[i]<<" ";
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
Array *fillAry(int n){
    //Declare and initialize our Array pointer
    Array *a=new Array;
    a->size=n;
    a->data=new int[n];
    //Loop and fill the array with random numbers
    for(int i=0;i<a->size;i++){
        (*a).data[i]=rand()%90+10;//[10,99]
    }
    return a;
}