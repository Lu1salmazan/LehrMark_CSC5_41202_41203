/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 25, 2016, 08:35 AM
    Purpose:  Power Function Example with random inputs
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int pow(int,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Variables to be using in timing
    //Beginning and Ending of the integer vs. double function
    unsigned int begi,endi,begd,endd,loop=400000000;
    unsigned int baseTme;//Base time in seconds
    
    //Declare and initialize variables
    int x;//Base of the problem
    int y;//Exponent of the problem
    int z;//The result of a^b
    
    //Calculate the base time
    begi=static_cast<unsigned int>(time(0));
    for(int i=0;i<=loop;i++){
        x=rand()%5+1;//[1,5]
        y=rand()%11;//[0,10]
    }
    endi=static_cast<unsigned int>(time(0));
    baseTme=endi-begi;
     
    //Output the results
    cout<<"The base time taken = "<<baseTme<<"(secs)"<<endl;
    
    //Calculate or map inputs to outputs
    begi=static_cast<unsigned int>(time(0));
    for(int i=0;i<=loop;i++){
        x=rand()%5+1;//[1,5]
        y=rand()%11;//[0,10]
        z=pow(x,y);
    }
    endi=static_cast<unsigned int>(time(0));
    
    //Output the results
    cout<<"The Integer Function is called "<<loop<<" times"<<endl;
    cout<<"The total time taken = "<<endi-begi-baseTme<<"(secs)"<<endl;
    
    //Compare our function with the cmath library using doubles
    double dx;//Base of the problem
    double dy;//Exponent of the problem
    double dz;//The result of a^b
    
    //Call math library function
    begd=static_cast<unsigned int>(time(0));
    for(int i=0;i<=loop;i++){
        dx=rand()%5+1;//[1,5]
        dy=rand()%11;//[0,10]
        dz=pow(dx,dy);
    }
    endd=static_cast<unsigned int>(time(0));
    
    //Output the results
    cout<<"The Library Function is called "<<loop<<" times"<<endl;
    cout<<"The total time taken = "<<endd-begd-baseTme<<"(secs)"<<endl;
    
    //Exit stage right
    return 0;
}

//000000001111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
/*                        Power Function                                      */
/******************************************************************************/
//Inputs
//  a->Integer Base
//  b->Integer Power-Exponent
//Output
//  c->Integer z=a^b
int pow(int a,int b){
    if(b<=0)return 1;
    if(b==1)return a;
    int abd2=pow(a,b/2);
    if(b%2)return abd2*abd2*a;//If odd
    return abd2*abd2;         //else even
}