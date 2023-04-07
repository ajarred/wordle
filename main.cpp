#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

string convertToUppercase(string word) {
    transform(word.begin(),word.end(),word.begin(),::toupper);
    return word;
}

bool isValidWord(string word) {
    if (word.length() != 5) {
        return false;
    }
    for (char c:word) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}

string checkGuess(string guess, string answer) {
    if (!(isValidWord(guess))) {
        return "Invalid guess";
    }
    string result = "";
    for (int i=0; i < guess.length(); i++) {
        if (guess[i] == answer[i]) {
            result += "R";
        } else if (guess.find(answer[i]) != string::npos) {
            result += "Y";
        } else {
            result += "X";
        }
    }
    return result;
}

int main(int argc, char* argv[])
{
    if (argc != 1) 
    {
        cerr << "Error: incorrect number of command line arguments\n"
        << "Usage: " << argv[0] << endl;
        return 1;
    }
    
    string words[] = {"MAJOR", "MINOR", "ALIEN", "BRAVO", "CHAOS", "DELTA", "EARTH"};
    int numWords = sizeof(words)/sizeof(words[0]);
    
    srand(time(0));
    
    string guessWord = words[rand() % numWords];
    bool userWon = false;
    
    for (int i=0; i<6; i++) {
        string userInput;
        getline(cin,userInput);
        while (!(isValidWord(userInput))) {
            cout << "invalid input\n";
            cout << "please input again\n";
            getline(cin, userInput);
        }
        userInput = convertToUppercase(userInput);
        cout << userInput << '\n';
        string result = checkGuess(userInput,guessWord);
        if (result == "RRRRR") {
            cout << "You win\n";
            userWon = true;
            break;
        } else {
            cout << result << "\n";
            cout << "Guess again\n";
        }
    }
    if (!userWon) {
        cout << "No more guesses\n" << "Correct word:"
        << guessWord << '\n';
    }
    return 0;
}
