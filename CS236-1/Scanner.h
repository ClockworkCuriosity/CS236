//
//  Scanner.h
//  CS236-1
//
//  Created by Shaun Miller on 6/29/15.
//  Copyright (c) 2015 Shaun Miller. All rights reserved.
//

#pragma once
#include <vector>
#include "Token.h"

using namespace std;

class Scanner
{
public:
    Scanner();
    ~Scanner(void);
    void make_output(string filename);
    //ifstream get_input(string filename);
    void parse_file(string filename);
    vector<string> get_input_old(string filename);
    void string_check(char current);
    void set_output_name(string output_name);
    void default_from_parse(ifstream &input, char &current, int &line_number);
    void string_from_parse(ifstream &input, char &current, int &line_number);
    void colon_from_parse(ifstream &input, char &current, int &line_number);
    void add_error(string filename, int line_number);
    bool keyword_checker(string &word, int &line_number);
    string get_errors();
    //void make_comment(ifstream input, char current);
    
private:
    vector<Token> all_tokens;
    string output_file_name;
    string errors;
};

