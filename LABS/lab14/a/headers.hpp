#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string readFile(string filename);
void replaceMe(string& text);
void findWordsWithDigits(string text);