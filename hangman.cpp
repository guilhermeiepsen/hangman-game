//HANGMAN GAME

#include <iostream>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

#define WORDSIZE 30
#define CHANCES 6

int main()
{
    int wordSize = 0;
    char secretWord[WORDSIZE], mistakenLetters[CHANCES+1], letter, playAgain;
    int i = 0, chances, sizeMistakenLetters;
    bool mistake, gameWin, position[WORDSIZE], checkMistakenLetter;

    do {
        
        for(i=0; i<CHANCES+1; i++) {
            mistakenLetters[i] = '\0';    
        }

        gameWin = false;
        chances = CHANCES;
        sizeMistakenLetters = 0;

        cout << "please close your eyes, the secret word will be written." << endl;

        cout << "type down the screct word" << endl;
        cin >> secretWord;
        fflush(stdin);
        
        system("cls");

        wordSize = 0;
        while (secretWord[wordSize] != '\0') {
            position[wordSize] = false;
            wordSize ++;
        }

        cout << "the secret word contains " << wordSize << " letters" << endl;

        while(chances > 0 && !gameWin) {

            cout << "Remaining chances: " << chances << endl;

            cout << "Secret Word: ";
            
            for(i=0; i<wordSize; i++) {
            
                if(position[i])
                    cout << secretWord[i];
                else
                    cout << "_";

            }
            cout << "\ntype a letter:" << endl;

            cin >> letter;
            fflush(stdin);


            mistake = true;
            gameWin = true;
            for(i=0; i<wordSize; i++) {
                if(secretWord[i] == letter) {
                    position[i] = true;
                    mistake = false;
                }

                if(position[i] == false)
                    gameWin = false;
            }
            
            
            if(mistake) {
                
                i=0;
                checkMistakenLetter = true;
                while(mistakenLetters[i] != '\0') {
                    if(mistakenLetters[i] == letter)
                        checkMistakenLetter = false; //the letter was found in the array mistakenLetters
                i++;
                }
                
                if(checkMistakenLetter) { //there was no such letter in the array mistakenLetters
                    chances --;
                    mistakenLetters[sizeMistakenLetters] = (char)letter;
                    sizeMistakenLetters ++;
                }    
            }
            
            system("cls");
            
            i = 0;
            cout << "Mistaken letters: ";
            while(mistakenLetters[i] != '\0') {
                cout << (char)mistakenLetters[i] << " ";
                i++;
            }
        
            cout << endl;
        }
        
        if(gameWin)
            cout << "YOU'VE WON! :DDDDDDD" << endl;
        else
            cout << "You've lost! :((((" << endl;

        cout << "the word was: " << secretWord << endl;
        
        cout << "Do you wish to play again? (Y/N) \n";
        
        cin >> playAgain;
        fflush(stdin);
        system("cls");

    } while (toupper(playAgain) == 'Y');

    return 0;
}
