/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 19, 2016, 9:10 PM
    Purpose:  Calculate PI with random numbers
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
const float PI=4*atan(1);
const float MXRND=pow(2,31)-1;

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //The problem to solve
    cout<<endl<<"Solution to Savitch 8thEd Chap3 Prob12"<<endl;
    cout<<endl<<"The stocastic integration of PI"<<endl<<endl;
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize variables for apprxPI
    float apprxPI;        //Approximate value of PI to start
    unsigned int nDarts;  //Number of darts to throw at the target
    unsigned int inCirc=0;//Number of darts in circle
    
    //Input the number of terms in the sequence
    cout<<"Input number of Darts to approximate PI"<<endl;
    cin>>nDarts;
    
    //Approximate PI/4
    for(int i=1;i<=nDarts;i++){
        float x=rand()/MXRND;
        float y=rand()/MXRND;
        if(x*x+y*y<1.0)inCirc++;
    }
    apprxPI=4.0*inCirc/nDarts;//Multiply by 4 once to approximate PI
    
    //Output the results
    cout<<"The exact  value of PI="<<PI<<endl;
    cout<<"The number of Darts thrown to approx PI="<<nDarts<<endl;
    cout<<"The approx value of PI="<<apprxPI<<endl<<endl;
    
    //Exit stage right
    return 0;
}