//
//  Token.cpp
//  CS236-1
//
//  Created by Shaun Miller on 6/29/15.
//  Copyright (c) 2015 Shaun Miller. All rights reserved.
//

#include<string>
#include<sstream>
#include"Token.h"

const string Token::enumNames[19] = {"COMMA", "PERIOD", "Q_MARK", "LEFT_PAREN", "RIGHT_PAREN", "COLON", "COLON_DASH", "MULTIPLY", "ADD", "SCHEMES", "FACTS", "RULES", "QUERIES", "ID", "STRING", "COMMENT", "WHITESPACE", "UNDEFINED", "EOF"};

Token::Token(TType itype, string ivalue, int iline_num)
{
    type = itype;
    value = ivalue;
    line_num = iline_num;
    
    
}

TType Token::get_type()
{
    return type;
}

string Token::get_type_string()
{
    return enumNames[type];
}

string Token::get_value()
{
    return value;
}

int Token::get_line_num()
{
    return line_num;
}

Token::~Token(void)
{
}