#include <iostream>

#include <fstream>

#include<string>

using namespace std;

class Admin {
    private:
        string password="admin";
        string secretWord="default";

        bool checkPassword(string temp){
            return temp==password;
        }

    public:
        string getSecretWord(){
            return secretWord;
        }

        Admin(int i){
            string temp;
            int attempt=0;
            while(attempt!=3){
                cout<<"Enter password"<<endl;
                cin>>temp;
                if(checkPassword(temp)){
                    cout<<"The game can be played now"<<endl;
                    break;
                } else {
                    cout<<"Incorrect password"<<endl;
                    attempt++;
                }
            }
            if(attempt==3){
                cout<<"You are not authorized to be the admin"<<endl;
            }
        }

        void changePassword(){
            string temp;
            int count=0;
            while(count!=3){
                cout<<"Enter the old password"<<endl;
                cin>>temp;
                if(checkPassword(temp)){
                    cout<<"Enter new password"<<endl;
                    cin>>temp;
                    password=temp;
                    break;
                } else {
                    count++;
                }
            }
            if(count==3){
                cout<<"You are not authorised for the operation"<<endl;
            }
        }

        void adminOp(){
            string line;
            ifstream inFile;
            inFile.open("adminOperations.txt");
            while(getline(inFile,line)){
                cout<<line<<endl;
            }
        }

        void changeSecretWord(){
            string temp;
            int count=0;
            while(count!=3){
                cout<<"Enter password"<<endl;
                cin>>temp;
                if(checkPassword(temp)){
                    cout<<"Enter new secretword"<<endl;
                    cin>>temp;
                    secretWord=temp;
                    break;
                } else {
                    count++;
                }
            }
            if(count==3){
                cout<<"You are not authorised for the operation"<<endl;
            }
        }
};


class player{
    private:

        string playerName;

    public:
        void getInfo(){
            cout<<"Enter your name"<<endl;
            cin>>playerName;
        }

        void playerInstr(){
            string line;
            ifstream inFile;
            inFile.open("playerInstructions.txt");
            while(getline(inFile,line)){
                cout<<line;
            }
        }

        void gamePlay(Admin a1){
            string guess;
            string secretWord = a1.getSecretWord();
            while(true){
                cout<<"Guess the word"<<endl;
                cin>>guess;
                if(guess==secretWord){
                    cout<<"You won ! Congratulations !"<<endl;
                    break;
                } else if(guess<secretWord){
                    cout<<"Your guess is alphabetically too early"<<endl;
                } else {
                    cout<<"Your guess is alphabetically too late"<<endl;
                }

            }
        }
};

class banner{
    public:
        void displayBanner() {
    cout << R"(
  ____                         _     _                _   _                 
 / ___| _ __   ___  ___  ___  | |   (_)_ __ ___   ___| |_(_) ___  _ __  ___ 
 \___ \| '_ \ / _ \/ __|/ _ \ | |   | | '_ ` _ \ / _ \ __| |/ _ \| '_ \/ __|
  ___) | |_) |  __/\__ \  __/ | |___| | | | | | |  __/ |_| | (_) | | | \__ \
 |____/| .__/ \___||___/\___| |_____|_|_| |_| |_|\___|\__|_|\___/|_| |_|___/
       |_|                                                                  

                     🎮 WELCOME TO THE SECRET WORD GAME 🎮

  ➤ Guess the secret word chosen by the admin.
  ➤ You will get clues based on alphabetical order.
  ➤ Admin can manage the game settings and password.

  💡 Type "admin" to login as admin, "player" to play, or "0" to exit.
    )" << endl;
}

};


int main(){
    banner b1;
    b1.displayBanner();
    string line;
    Admin a1(1);
    while(true){
        cout<<"Type admin if you want to perform administrative operations or player to play the game or 0 to turn off the game"<<endl;
        cin>>line;
        if(line=="admin"){
            a1.adminOp();
            cin>>line;
            if(line=="1"){
                a1.changePassword();
            } else if(line=="2"){
                a1.changeSecretWord();
            }
        } else if(line=="player"){
            player p1;
            p1.playerInstr();
            p1.getInfo();
            p1.gamePlay(a1);
        } else if(line=="0"){
            cout<<"Game exited. Bye";
            break;
        }
    }
    return 0;
}
