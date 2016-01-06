//
//  main.cpp
//  CS236-1
//
//  Created by Shaun Miller on 6/29/15.
//  Copyright (c) 2015 Shaun Miller. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <regex>
#include <cctype>
#include "Token.h"
#include "Scanner.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //string x = argv[1];
    string x = "in61.txt";
    Scanner S;
    //const map<char,int> p_mark = {{',', 1}, {'.', 1}, {'?', 1}, {'(', 1}, {')', 1}, {':', 1}, {'\*', 1}, {'\+', 1}}; //NOT FINISHED
    cout << "Compiled and functional so far, not necessarily right!" << endl;
    
    S.parse_file(x);
    S.make_output(argv[2]);
    
    return 0;
}
