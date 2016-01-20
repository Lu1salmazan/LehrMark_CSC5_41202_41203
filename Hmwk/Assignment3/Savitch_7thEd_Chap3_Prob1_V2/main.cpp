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
    
    //Set the random number seed and declare the question
    srand(static_cast<unsigned int>(time(0)));
    char qwstion;     //Question, does player want to keep playing
    
    //Loop until player wants to Quit
    do{
        //Declare and initialize variables for apprxPI
        char computr;     //The computers play
        char player;      //The players move

        //Input the players turn
        do{
            cout<<endl<<"What is your move P,R,S?"<<endl;
            cin>>player;
            player=toupper(player);
        }while(!(player=='P'||player=='R'||player=='S'));

        //Computer Generated Play
        do{
            computr=rand()%4+80;
        }while(computr=='Q');

        //Output the moves by the computer and player
        cout<<"The Computer played "<<computr<<endl;
        cout<<"The Players move    "<<player<<endl;

        //Determine the result
        if(computr==player){
            cout<<"The result is a tie"<<endl;
        }else if(player=='P'&&computr=='R'){
            cout<<"The Player wins!"<<endl;
        }else if(player=='R'&&computr=='S'){
            cout<<"The Player wins!"<<endl;
        }else if(player=='S'&&computr=='P'){
            cout<<"The Player wins!"<<endl;
        }else{
             cout<<"The Player Loses!"<<endl;
        }

        //Keep playing?
        cout<<endl<<"Do you want to continue playing?"<<endl;
        cin>>qwstion;
    }while(toupper(qwstion)=='Y');
    
    //Exit stage right
    return 0;
}