#include<iostream>
#include<cstring>
using namespace std;

class HangMan{
private:
    string Word, Guess, letters;
    int nr=6;
public:
    HangMan(){
        Word="";
    }

    HangMan(string _Word){
        Word=_Word;
        for(int i=0;i<Word.length();i++)
            if(Word[i]!=' ') Guess+="_";
            else Guess+=" ";
    }

    void printUnknownWord() {
        cout<<Guess<<endl;
    }

    void printStats(){
        cout<<"Guess "<<Guess<<endl<<"Tried letters: "<<letters<<endl<<"You have "<<nr<<" guesses left.";
    }

    void guess(char c){
        letters+=c;
        int ok=0;
        for(int i=0;i<Word.length();i++){
            if (Word[i]==c){
                Guess[i] = c;
                ok = 1;
            }
            else if (isupper(Word[i])==1 && Word[i]==toupper(c)){
                Guess[i] = toupper(c);
                ok = 1;
            }
            else if (islower(Word[i])==1 && Word[i]==tolower(c)){
                Guess[i] = tolower(c);
                ok = 1;
            }
        }
        if(ok==1)
            cout<<"You hit the spot! Now you only have to guess "<<Guess<<endl;
        else {
            cout << "Unlucky! That was not it, but you still have " << nr << " guesses left"<<endl;
            nr--;
        }
    }

    int playerHasWon(){
        if (nr>0 && Word==Guess) return 1;
        return 0;
    }
};

int main() {

	HangMan game{"Thug POO"};

	game.printStats();
	game.printUnknownWord(); // Va afisa: "_ _ _ _   _ _ _"
	game.guess('P'); // Va afisa: "You hit the spot! Now you only have to guess _ _ _ _ _ P _ _"
	game.guess('o'); // Va afisa: "You hit the spot! Now you only have to guess _ _ _ _ _ P O O"
	game.printStats();

	game.guess('z'); // "Unlucky! That was not it, but you still have 5 guesses left"

	game.guess('t');
	game.guess('h');
	game.guess('u');
	game.guess('g');

	cout << game.playerHasWon() << endl; // va afisa 1, deoarece jucatorul a castigat
}
