#pragma once
#include<fstream>
#include<string>
using namespace std;

void replace_start_with_begin(const char* file_name) {
    ifstream in(file_name);
    string str;

    while (!in.eof()) {         
        str += in.get();                // get() reads one symbol and returns it.
    }
    in.close();
    ofstream out(file_name);
    for (int i = 0; i + 4 < str.length(); i++) {
        if (str[i] == 's' && str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'r' && str[i + 4] == 't') {
            out << "begin";
            i += 4;
        }
        else {
            out << str[i];
        }
    }
    out.close();
}