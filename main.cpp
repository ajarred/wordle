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

string generateRandomWord() {
    string words[] = {"MAJOR", "MINOR", "ALIEN", "BRAVO", "CHAOS", "DELTA", "EARTH"};
    int numWords = sizeof(words)/sizeof(words[0]);
    srand(time(0));
    return words[rand() % numWords];
}

void playWordle() {
    string answer = generateRandomWord();
    cout << "WORDLE\n";
    for (int i=0; i<6; i++) {
        string userInput;
        getline(cin,userInput);
        while (!(isValidWord(userInput))) {
            cout << "invalid input\n";
            getline(cin, userInput);
        }
        userInput = convertToUppercase(userInput);
        string result = checkGuess(userInput,answer);
        if (result == "RRRRR") {
            cout << "You win\n";
            break;
        } else {
            cout << result << "\n";
        }
    }
    cout << "You lose. The word was " << answer << '\n';
}

int main(int argc, char* argv[])
{
    playWordle();
    return 0;
}
