/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 25, 2016, 10:08 AM
    Purpose:  Testing throwing dice
 */

//System Libraries
#include <iostream>//I/O
#include <cstdlib>  //srand and rand function
#include <ctime>   //time to set the random number seed
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare and initialize variables
    const unsigned short MAXTHRW=36000;//Max number of throws
    //Frequency of our dice throws
    unsigned short frq2=0,frq3=0,frq4=0,frq5=0,frq6=0;
    unsigned short frq7=0,frq8=0,frq9=0,frq10=0,frq11=0,frq12=0;
    unsigned short total;
    
    //Input data
    
    //Throw the dice
    for(int throws=1;throws<=MAXTHRW;throws++){
        char die1=rand()%6+1;//Number between [1,6]
        char die2=rand()%6+1;//Number between [1,6]
        char sum=die1+die2;
        switch(sum){
            case 2:frq2++;break;
            case 3:frq3++;break;
            case 4:frq4++;break;
            case 5:frq5++;break;
            case 6:frq6++;break;
            case 7:frq7++;break;
            case 8:frq8++;break;
            case 9:frq9++;break;
            case 10:frq10++;break;
            case 11:frq11++;break;
            case 12:frq12++;break;
            default: cout<<"Not Possible"<<endl;
        }
    }
    total=frq2+frq3+frq4+frq5+frq6+frq7+frq8+frq9+frq10+frq11+frq12;
    
    //Output the results
    cout<<"The throw statistics are"<<endl;
    cout<<"2 was thrown "<<frq2<<" times"<<endl;
    cout<<"3 was thrown "<<frq3<<" times"<<endl;
    cout<<"4 was thrown "<<frq4<<" times"<<endl;
    cout<<"5 was thrown "<<frq5<<" times"<<endl;
    cout<<"6 was thrown "<<frq6<<" times"<<endl;
    cout<<"7 was thrown "<<frq7<<" times"<<endl;
    cout<<"8 was thrown "<<frq8<<" times"<<endl;
    cout<<"9 was thrown "<<frq9<<" times"<<endl;
    cout<<"10 was thrown "<<frq10<<" times"<<endl;
    cout<<"11 was thrown "<<frq11<<" times"<<endl;
    cout<<"12 was thrown "<<frq12<<" times"<<endl;
    cout<<"The total number of throws = "<<total<<endl;
    
    //Exit stage right
    return 0;
}