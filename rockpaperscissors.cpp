#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));
    cout<<"WELCOME TO ROCK-PAPER-SCISSORS AGAINST THE COMPUTER"<<endl;
    int choice;
    int Choice1;

    do {
        cout<<" 1. Play rock"<<endl;
        cout<<" 2. Play paper"<<endl;
        cout<<" 3. Play scissors"<<endl;
        cout<<"What are you picking(PICK THE NUMBER THAT CORRESPONDS TO WHAT YOU WANT)?: ";
        cin>>choice;

     if(choice < 1 || choice > 3){
        cout<<"Error,choose again"<<endl;
     }
    } while (choice < 1 || choice > 3);

    Choice1 = (rand()%3) + 1;
    cout<<"The computer(User 2) chose"<<Choice1<<endl;

    if(choice == Choice1){
        cout<<"This is a TIE!"<<endl;
    } else if(choice == 1 && Choice1 == 3 || choice == 2 && Choice1 == 1 || choice == 3 && Choice1 == 2){
    cout<<"YOU WON! Congatulations."<<endl;
    } else {
    cout<<"You lose. User 2 (The Computer) won. You can try again."<<endl;
    }
    return 0;
}
