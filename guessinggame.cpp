#include<iostream>
using namespace std;

int main(void){
int number = 5;
int num;
    cout<<"Welcome to my guessing game,please follow the rules below."<<endl;
    cout<<"1. You are to guess a random integer,you have just three attempts at that."<<endl;
    cout<<"2. After the third attempt,if you guess wrongly,you lose the game,so choose wisely"<<endl;
    cout<<"PLEASE INPUT THE NUMBER[Hint: It is a one digit number]: ";
    cin>>num;
if(num == number){
    cout<<"Congratulations,you won on the first try."<<endl;
} else {
    cout<<"Incorrect. Second attempt: ";
    cin>>num;

if(num == number){
    cout<<"Good Job, you had it on your second attempt."<<endl;
}
    else{
    cout<<"Incorrect. Last Attempt: ";
    cin>>num;

    if(num == number){
        cout<<"Real Lucky. You had it on your very last attempt."<<endl;
} else{
        cout<<"GAME OVER,RESTART THE GAME!"<<endl;
    }
}
}
}





