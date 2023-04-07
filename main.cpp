#include <iostream>
#include <string>
#include <algorithm>

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

int main(int argc, char* argv[])
{
    if (argc != 1) 
    {
        cerr << "Error: incorrect number of command line arguments\n"
        << "Usage: " << argv[0] << endl;
        return 1;
    }
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
    }
    return 0;
}