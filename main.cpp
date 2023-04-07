#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convertToUppercase(string word) {
    transform(word.begin(),word.end(),word.begin(),::toupper);
    return word;
}

int main()
{
    string userInput;
    getline(cin,userInput);
    userInput = convertToUppercase(userInput);
    cout << userInput;
    return 0;
}