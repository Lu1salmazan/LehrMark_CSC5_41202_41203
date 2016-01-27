/* 
    File:   main.cpp
    Author: Dr. Mark E. Lehr
    Created on January 25, 2016, 10:08 AM
    Purpose:  Simple Game of Craps
 */

//System Libraries
#include <iostream>//I/O
#include <cstdlib> //srand and rand function
#include <ctime>   //time to set the random number seed
#include <fstream> //File I/O
#include <iomanip> //Formatting
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare and initialize variables
    const unsigned int LIMIT=1500;//Table single bet limit = $1500
    unsigned short wins=0,losses=0,games;
    unsigned short w2=0,w3=0,w4=0,w5=0,w6=0,w7=0,w8=0,w9=0,w10=0,w11=0,w12=0;
    unsigned short l2=0,l3=0,l4=0,l5=0,l6=0,l7=0,l8=0,l9=0,l10=0,l11=0,l12=0;
    unsigned int cntRoll,maxRoll=0,totRoll=0,totWL;
    float wallet,bet;//$'s
    char  yes;//Character to answer if winning double the bet
    ofstream out;
    //Open the file
    out.open("CardGame.dat");
    
    //Input data and validate
    cout<<"How many games of Craps would you like to play"<<endl;
    cout<<"Utilize a number between 10,000 and 40,000"<<endl;
    cin>>games;
    while(games<10000||games>40000){
        cout<<"How many games of Craps would you like to play"<<endl;
        cout<<"Utilize a number between 10,000 and 40,000"<<endl;
        cin>>games;
    }
    cout<<"How much do you have to gamble$?"<<endl;
    cin>>wallet;
    cout<<"How much would you like to bet/game$?"<<endl;
    cin>>bet;
    cout<<"If you win would you like to double your bet (y/n)"<<endl;
    cin>>yes;
    //Modify the bet based upon the table limiit
    bet=bet<LIMIT?bet:LIMIT;//Ternary Operator
    
    //Throw the dice
    for(int game=1;game<=games;game++){
        cntRoll=0;
        char die1=rand()%6+1;//Number between [1,6]
        char die2=rand()%6+1;//Number between [1,6]
        char sum=die1+die2;
        cntRoll++;//Every time dice are thrown, Increment
        if(sum==2||sum==3||sum==12){
            losses++;
            switch(sum){
                case 2:{l2++;break;}
                case 3:{l3++;break;}
                case 4:{l4++;break;}
                case 5:{l5++;break;}
                case 6:{l6++;break;}
                case 7:{l7++;break;}
                case 8:{l8++;break;}
                case 9:{l9++;break;}
                case 10:{l10++;break;}
                case 11:{l11++;break;}
                case 12:{l12++;break;}
                default:cout<<"Not Possible"<<endl;
            }
            wallet-=bet;
        }else if(sum==7||sum==11){
            wins++;
            switch(sum){
                case 2:{w2++;break;}
                case 3:{w3++;break;}
                case 4:{w4++;break;}
                case 5:{w5++;break;}
                case 6:{w6++;break;}
                case 7:{w7++;break;}
                case 8:{w8++;break;}
                case 9:{w9++;break;}
                case 10:{w10++;break;}
                case 11:{w11++;break;}
                case 12:{w12++;break;}
                default:cout<<"Not Possible"<<endl;
            }
            wallet+=bet;
            bet=(yes=='y')?2*bet:bet;//Another Ternary
            bet=bet<LIMIT?bet:LIMIT;//Ternary Operator
        }else{
            //roll again
            bool kpRln=true;
            do{
                die1=rand()%6+1;//Number between [1,6]
                die2=rand()%6+1;//Number between [1,6]
                char sum2=die1+die2;
                cntRoll++;//Every time dice are thrown, Increment
                switch(sum2==7){
                    case true:{
                        losses++;
                        switch(sum){
                            case 2:{l2++;break;}
                            case 3:{l3++;break;}
                            case 4:{l4++;break;}
                            case 5:{l5++;break;}
                            case 6:{l6++;break;}
                            case 7:{l7++;break;}
                            case 8:{l8++;break;}
                            case 9:{l9++;break;}
                            case 10:{l10++;break;}
                            case 11:{l11++;break;}
                            case 12:{l12++;break;}
                            default:cout<<"Not Possible"<<endl;
                        }
                        wallet-=bet;
                        kpRln=false;
                    }
                    default:
                        if(sum==sum2){
                            wins++;
                            switch(sum){
                                case 2:{w2++;break;}
                                case 3:{w3++;break;}
                                case 4:{w4++;break;}
                                case 5:{w5++;break;}
                                case 6:{w6++;break;}
                                case 7:{w7++;break;}
                                case 8:{w8++;break;}
                                case 9:{w9++;break;}
                                case 10:{w10++;break;}
                                case 11:{w11++;break;}
                                case 12:{w12++;break;}
                                default:cout<<"Not Possible"<<endl;
                            }
                            wallet+=bet;
                            kpRln=false;
                        }
                }
            }while(kpRln);
        }
        totRoll+=cntRoll;
        if(cntRoll>maxRoll)maxRoll=cntRoll;
    }
    totWL =w2+w3+w4+w5+w6+w7+w8+w9+w10+w11+w12;
    totWL+=l2+l3+l4+l5+l6+l7+l8+l9+l10+l11+l12;
    
    //Output the results to screen
    cout<<"Out of "<<games<<" played"<<endl;
    cout<<"You won "<<wins<<" games and "<<endl;
    cout<<"You lost "<<losses<<" games"<<endl;
    cout<<"Percentage wise"<<endl;
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"You won "<<100.0f*wins/games<<" % games and "<<endl;
    cout<<"You lost "<<100.0f*losses/games<<" % games"<<endl;
    cout<<"The average roll per game = "
            <<static_cast<float>(totRoll)/games<<endl;
    cout<<"The maximum roll per game = "<<maxRoll<<endl;
    cout<<"Your wins and losses total = "<<wins+losses<<endl;
    cout<<"My Wallet Contains $"<<wallet<<endl;
    cout<<"My Bets were = $"<<bet<<endl;
    cout<<"Individual Statistics"<<endl;
    cout<<"Throw     Wins     Losses"<<endl;
    cout<<"    2"<<setw(9)<<w2<<setw(11)<<l2<<endl;
    cout<<"    3"<<setw(9)<<w3<<setw(11)<<l3<<endl;
    cout<<"    4"<<setw(9)<<w4<<setw(11)<<l4<<endl;
    cout<<"    5"<<setw(9)<<w5<<setw(11)<<l5<<endl;
    cout<<"    6"<<setw(9)<<w6<<setw(11)<<l6<<endl;
    cout<<"    7"<<setw(9)<<w7<<setw(11)<<l7<<endl;
    cout<<"    8"<<setw(9)<<w8<<setw(11)<<l8<<endl;
    cout<<"    9"<<setw(9)<<w9<<setw(11)<<l9<<endl;
    cout<<"   10"<<setw(9)<<w10<<setw(11)<<l10<<endl;
    cout<<"   11"<<setw(9)<<w11<<setw(11)<<l11<<endl;
    cout<<"   12"<<setw(9)<<w12<<setw(11)<<l12<<endl;
    cout<<"The total wins and losses = "<<totWL<<endl;
    cout<<"Individual Statistics Percentages"<<endl;
    cout<<"Throw     Wins     Losses"<<endl;
    cout<<"    2"<<setw(9)<<100.0f*w2/(w2+l2)<<setw(11)<<100.0f*l2/(w2+l2)<<endl;
    cout<<"    3"<<setw(9)<<100.0f*w3/(w3+l3)<<setw(11)<<100.0f*l3/(w3+l3)<<endl;
    cout<<"    4"<<setw(9)<<100.0f*w4/(w4+l4)<<setw(11)<<100.0f*l4/(w4+l4)<<endl;
    cout<<"    5"<<setw(9)<<100.0f*w5/(w5+l5)<<setw(11)<<100.0f*l5/(w5+l5)<<endl;
    cout<<"    6"<<setw(9)<<100.0f*w6/(w6+l6)<<setw(11)<<100.0f*l6/(w6+l6)<<endl;
    cout<<"    7"<<setw(9)<<100.0f*w7/(w7+l7)<<setw(11)<<100.0f*l7/(w7+l7)<<endl;
    cout<<"    8"<<setw(9)<<100.0f*w8/(w8+l8)<<setw(11)<<100.0f*l8/(w8+l8)<<endl;
    cout<<"    9"<<setw(9)<<100.0f*w9/(w9+l9)<<setw(11)<<100.0f*l9/(w9+l9)<<endl;
    cout<<"   10"<<setw(9)<<100.0f*w10/(w10+l10)<<setw(11)<<100.0f*l10/(w10+l10)<<endl;
    cout<<"   11"<<setw(9)<<100.0f*w11/(w11+l11)<<setw(11)<<100.0f*l11/(w11+l11)<<endl;
    cout<<"   12"<<setw(9)<<100.0f*w12/(w12+l12)<<setw(11)<<100.0f*l12/(w12+l12)<<endl;
    cout<<"The total wins and losses = "<<totWL<<endl;
    
    
    //Output the results to a file
    out<<"Out of "<<games<<" played"<<endl;
    out<<"You won "<<wins<<" games and "<<endl;
    out<<"You lost "<<losses<<" games"<<endl;
    out<<"Percentage wise"<<endl;
    out<<fixed<<setprecision(2)<<showpoint;
    out<<"You won "<<100.0f*wins/games<<" % games and "<<endl;
    out<<"You lost "<<100.0f*losses/games<<" % games"<<endl;
    out<<"The average roll per game = "
            <<static_cast<float>(totRoll)/games<<endl;
    out<<"The maximum roll per game = "<<maxRoll<<endl;
    out<<"Your wins and losses total = "<<wins+losses<<endl;
    out<<"My Wallet Contains $"<<wallet<<endl;
    out<<"My Bets were = $"<<bet<<endl;
    out<<"Individual Statistics"<<endl;
    out<<"Throw     Wins     Losses"<<endl;
    out<<"    2"<<setw(9)<<w2<<setw(11)<<l2<<endl;
    out<<"    3"<<setw(9)<<w3<<setw(11)<<l3<<endl;
    out<<"    4"<<setw(9)<<w4<<setw(11)<<l4<<endl;
    out<<"    5"<<setw(9)<<w5<<setw(11)<<l5<<endl;
    out<<"    6"<<setw(9)<<w6<<setw(11)<<l6<<endl;
    out<<"    7"<<setw(9)<<w7<<setw(11)<<l7<<endl;
    out<<"    8"<<setw(9)<<w8<<setw(11)<<l8<<endl;
    out<<"    9"<<setw(9)<<w9<<setw(11)<<l9<<endl;
    out<<"   10"<<setw(9)<<w10<<setw(11)<<l10<<endl;
    out<<"   11"<<setw(9)<<w11<<setw(11)<<l11<<endl;
    out<<"   12"<<setw(9)<<w12<<setw(11)<<l12<<endl;
    out<<"The total wins and losses = "<<totWL<<endl;
    out<<"Individual Statistics Percentages"<<endl;
    out<<"Throw     Wins     Losses"<<endl;
    out<<"    2"<<setw(9)<<100.0f*w2/(w2+l2)<<setw(11)<<100.0f*l2/(w2+l2)<<endl;
    out<<"    3"<<setw(9)<<100.0f*w3/(w3+l3)<<setw(11)<<100.0f*l3/(w3+l3)<<endl;
    out<<"    4"<<setw(9)<<100.0f*w4/(w4+l4)<<setw(11)<<100.0f*l4/(w4+l4)<<endl;
    out<<"    5"<<setw(9)<<100.0f*w5/(w5+l5)<<setw(11)<<100.0f*l5/(w5+l5)<<endl;
    out<<"    6"<<setw(9)<<100.0f*w6/(w6+l6)<<setw(11)<<100.0f*l6/(w6+l6)<<endl;
    out<<"    7"<<setw(9)<<100.0f*w7/(w7+l7)<<setw(11)<<100.0f*l7/(w7+l7)<<endl;
    out<<"    8"<<setw(9)<<100.0f*w8/(w8+l8)<<setw(11)<<100.0f*l8/(w8+l8)<<endl;
    out<<"    9"<<setw(9)<<100.0f*w9/(w9+l9)<<setw(11)<<100.0f*l9/(w9+l9)<<endl;
    out<<"   10"<<setw(9)<<100.0f*w10/(w10+l10)<<setw(11)<<100.0f*l10/(w10+l10)<<endl;
    out<<"   11"<<setw(9)<<100.0f*w11/(w11+l11)<<setw(11)<<100.0f*l11/(w11+l11)<<endl;
    out<<"   12"<<setw(9)<<100.0f*w12/(w12+l12)<<setw(11)<<100.0f*l12/(w12+l12)<<endl;
    out<<"The total wins and losses = "<<totWL<<endl;

    //Exit stage right
    out.close();
    return 0;
}