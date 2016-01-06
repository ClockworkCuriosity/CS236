//
//  Token.h
//  CS236-1
//
//  Created by Shaun Miller on 6/29/15.
//  Copyright (c) 2015 Shaun Miller. All rights reserved.
//

#pragma once
#include<string>


using namespace std;

enum TType { COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, COLON, COLON_DASH, MULTIPLY, ADD, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, COMMENT, WHITESPACE, UNDEFINED, END };

class Token
{
public:
    Token(TType type, string value, int line_num);
    ~Token(void);
    TType get_type();
    string get_type_string();
    string get_value();
    int get_line_num();
    
    
private:
    TType type;
    string value;
    int line_num;
    static const string enumNames[];
    
    
};

