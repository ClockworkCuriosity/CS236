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
    
    string x = argv[1];
    Scanner S;
    S.set_output_name(argv[2]);
    
    S.parse_file(x);
    //if no errors, make the output.
    if(S.get_errors()=="")
    {
        S.make_output(argv[2]);
    }
    
    return 0;
}
