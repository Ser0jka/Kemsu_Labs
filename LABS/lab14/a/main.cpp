#include "headers.hpp"

int main()
{
    string text = readFile("input.txt");
    replaceMe(text);
    findWordsWithDigits(text);
    cout << "\nТекст после замены:\n";
    cout << text;

    return 0;
}