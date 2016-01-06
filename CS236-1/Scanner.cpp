//
//  Scanner.cpp
//  CS236-1
//
//  Created by Shaun Miller on 6/29/15.
//  Copyright (c) 2015 Shaun Miller. All rights reserved.
//

#pragma
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <regex>
#include <cctype>
#include <sstream>
#include "Scanner.h"
#include "Token.h"

using namespace std;

Scanner::Scanner()
{
    vector<Token> all_tokens;
}

void Scanner::make_output(string file_name)
{
    ofstream output_file(file_name);
    //cout << "Got to make output function";
    if(output_file.is_open())
    {
        for(unsigned int i = 0; i < this->all_tokens.size(); i++)
        {
            output_file << "(" + this->all_tokens[i].get_type_string() + "," + "\"" + this->all_tokens[i] .get_value() +
            "\"" + "," << this->all_tokens[i].get_line_num() << ")" << endl;
        }
        output_file << "Total Tokens = " << this->all_tokens.size() << endl;
    }
    else
    {
        cout << "Couldn't open an output file." << endl;
    }
    output_file.close();
}

void Scanner::parse_file(string filename)
{
    ifstream input;
    input.open(filename);
    int line_number = 1;
    char current;
    if (input.is_open())
    {
        //input.get(current);
        bool encountered_eof = false;
        while (input.get(current))
        {
            //cout << current << endl;
            switch(current)
            {
                {case'\n':
                    line_number++;
                    //input.get(current);
                    break;
                }
                {case'\r':
                    line_number++;
                    break;
                }
                {case'#':
                    //TODO: support multiline comments here
                    if(input.peek()=='#')
                    {
                        //Do Multi-Line Comment Thing
                    }
                    else
                    {
                        //Do Single-line Comment thing
                        string full_line = "";
                        full_line += current;
                        string line;
                        getline(input, line);
                        full_line += line;
                        cout << full_line << endl;
                        line_number++;
                        //input.get(current);
                        break;
                    }
                }
                {case':':
                    this->colon_from_parse(input, current, line_number);
                    break;
                }
                {case'\'':
                    this->string_from_parse(input, current, line_number);
                    break;
                }
                {case',':
                    TType type = COMMA;
                    Token toke(type, ",", line_number);
                    this->all_tokens.push_back(toke);
                    //input.get(current);
                    break;
                }
                {case'.':
                    TType type = PERIOD;
                    Token toke(type, ".", line_number);
                    this->all_tokens.push_back(toke);
                    //input.get(current);
                    break;
                }
                {case'\?':
                    TType type = Q_MARK;
                    Token toke(type, "?", line_number);
                    this->all_tokens.push_back(toke);
                    //input.get(current);
                    break;
                }
                {case'(':
                    TType type = LEFT_PAREN;
                    Token toke(type, "(", line_number);
                    this->all_tokens.push_back(toke);
                    //input.get(current);
                    break;
                }
                {case')':
                    TType type = RIGHT_PAREN;
                    Token toke(type, ")", line_number);
                    this->all_tokens.push_back(toke);
                    //input.get(current);
                    break;
                }
                {case'*':
                    TType type = MULTIPLY;
                    Token toke(type, "*", line_number);
                    this->all_tokens.push_back(toke);
                    //input.get(current);
                    break;
                }
                {case'+':
                    TType type = ADD;
                    Token toke(type, "+", line_number);
                    this->all_tokens.push_back(toke);
                    //input.get(current);
                    break;
                }
                {case' ':
                    //input.get(current);
                    break;
                }
                default:
                    this->default_from_parse(input, current, line_number);
                    break;
            }
        }
        TType type = END;
        Token toke(type, "", line_number);
        this->all_tokens.push_back(toke);
        encountered_eof = true;
        //switch(current)
    }
    else
    {
        cout << "Unable to open input file";
    }
    input.close();
}

void Scanner::default_from_parse(ifstream &input, char &current, int &line_number)
{
    if(isalpha(current))
    {
        string word;
        
        while(isalnum(input.peek()))
        {
            word += current;

            input.get(current);
            //word += current;
            //add those characters to a string until you
        }
        //cout << word;
        word += current;
        if (this->keyword_checker(word, line_number)==false)
        {
            //Do the ID thing
            //word += current;
            TType type = ID;
            Token toke(type, word, line_number);
            this->all_tokens.push_back(toke);
            //input.get(current);
        }
        
    }
    else if(current=='\n')
    {
        line_number++;
    }
    else
    {
        //TODO: hard coded output file name!  MAGIC!
        this->make_output("output.txt");
        cout << current << endl;
        cout << "Input error on line " << line_number << endl;
        //exit(0);
    }
    //cout << "I bet it hits here";
}

bool Scanner::keyword_checker(string &word, int &line_number)
{
    string up_word;
    for(unsigned int i = 0; i < word.size(); i++)
    {
        up_word += toupper(word[i]);
    }
    //cout << up_word;
    if(up_word.compare("SCHEMES")==0)
    {
        TType type = SCHEMES;
        Token toke(type, word, line_number);
        this->all_tokens.push_back(toke);
        return true;
    }
    else if(up_word.compare("FACTS")==0)
    {
        TType type = FACTS;
        Token toke(type, word, line_number);
        this->all_tokens.push_back(toke);
        return true;
    }
    else if(up_word.compare("RULES")==0)
    {
        TType type = RULES;
        Token toke(type, word, line_number);
        this->all_tokens.push_back(toke);
        return true;
    }
    else if(up_word.compare("QUERIES")==0)
    {
        TType type = QUERIES;
        Token toke(type, word, line_number);
        this->all_tokens.push_back(toke);
        return true;
    }
    else
    {
        return false;
    }

}

void Scanner::string_from_parse(ifstream &input, char &current, int &line_number)
{
    string word;
    //Add that first quotation mark
    word += current;
    //get the next input so we can see what it is
    input.get(current);
    //but don't forget to add it is the string, too!
    word += current;
    //now, as long as the current character isn't a quotation mark, keep accepting input and adding it to the string! :)
    while(current!='\'')
    {
        //TODO: I need to deal with end of file here, as well as end of line
        if(current=='\n')
        {
            //TODO: find a better way
            //TODO: MAGIC FILENAME HERE
            this->make_output("output.txt");
            //cout << current << endl;
            cout << "Input error on line " << line_number << endl;
            exit(0);
        }
        else
        {
            input.get(current);
            word += current;
            //add those characters to a string until you
        }
    }
    //cout << current << endl;
    TType type = STRING;
    Token toke(type, word, line_number);
    this->all_tokens.push_back(toke);
}

void Scanner::colon_from_parse(ifstream &input, char &current, int &line_number)
{
    if(input.peek()=='-')
    {
        TType type = COLON_DASH;
        Token toke(type, ":-", line_number);
        this->all_tokens.push_back(toke);
        input.get(current);
    }
    else
    {
        TType type = COLON;
        Token toke(type, ":", line_number);
        this->all_tokens.push_back(toke);
    }
}

void Scanner::string_check(char current)
{
    
}

//void make_comment(ifstream input, char current)
//{
//    string full_line = "";
//    full_line += current;
//    string line;
//    getline(input, line);
//    full_line += line;
//    cout << full_line;
//}


// This is the old get_input function, before I knew that peek exists!  It could yet prove useful, so it's only commented out.
vector<string> Scanner::get_input_old(string filename)
{
    ifstream myfile(filename);
    vector<string> input_by_line;
    if (myfile.is_open())
    {
        string line;
        while(getline(myfile, line))
        {
            input_by_line.push_back(line);
            cout << line << endl;
        }
    }
    myfile.close();
    return input_by_line;
}

Scanner::~Scanner(void)
{
}

