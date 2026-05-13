#include "headers.hpp"

string readFile(string filename)
{
    ifstream file(filename);
    string text;
    string line;
    while (getline(file, line))
    {
        text += line + "\n";
    }
    file.close();
    return text;
}

void replaceMe(string& text)
{
    int pos;
    while ((pos = text.find("me")) != string::npos){
        text.replace(pos, 2, "you");
    }
}

void findWordsWithDigits(string text)
{
    string word = "";
    for (int i = 0; i <= text.length(); i++){
        if (text[i] != ' '){
            word += text[i];
        }
        else{
            int count = 0;
            for (int j = 0; j < word.length(); j++){
                if (isdigit(word[j])){
                    count++;
                }
            }
            if (count > 0){
                cout << "Слово: " << word << endl;
                cout << "Количество цифр: " << count << endl;
                cout << "Цифры: ";

                for (int j = 0; j < word.length(); j++){
                    if (isdigit(word[j])){
                        cout << word[j] << " ";
                    }
                }   
                cout << "\n\n";
            }
            word = "";
        }
    }
}

