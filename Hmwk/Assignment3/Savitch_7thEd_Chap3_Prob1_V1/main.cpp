/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 20, 2016, 8:55 AM
    Purpose:  Play paper-rock-scissors with the computer
 */

//System Libraries
#include <iostream> //I/O
#include <cstdlib>  //Rand function
#include <ctime>    //Time to set the Random number seed
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //The problem to solve
    cout<<endl<<"Solution to Savitch 7thEd Chap3 Prob1"<<endl;
    cout<<endl<<"The Rock-Paper-Scissor Game"<<endl<<endl;
    
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare and initialize variables for apprxPI
    char computr;     //The computers play
    char player;      //The players move
    
    //Input the players turn
    do{
        cout<<"What is your move P,R,S?"<<endl;
        cin>>player;
        player=toupper(player);
    }while(!(player=='P'||player=='R'||player=='S'));

    
    //Computer Generated Play
    do{
        computr=rand()%4+80;
    }while(computr=='Q');

    
    //Output the results
    cout<<"The Computer played "<<computr<<endl;
    cout<<"The Players move    "<<player<<endl;
    
    //Exit stage right
    return 0;
}