//
//  main.cpp
//  478_p2
//
//  Created by Ivan Cordoba on 10/30/16.
//  Copyright © 2016 Ivan Cordoba. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

class Line{
    string as, source, type;
    
public:
    Line(string x){
        parse_line(x);
    }
    void parse_line(string x){
        vector<string> y = split(x, '|');
        as = y[0];
        source = y[1];
        type = y[2];
        
    }
    void set_as(string x){
        as = x;
        return;
    }
    void set_source(string x){
        source = x;
        return;
    }
    void set_type(string x){
        type = x;
        return;
    }
    string get_as(){
        return as;
    }
    string get_source(){
        return source;
    }
    string get_type(){
        return type;
    }
};



int main(int argc, const char * argv[]) {
    
    vector<Line> v;
    
    string line;
    ifstream myfile ("/Users/ivancordoba/Desktop/478_p2/478_p2/input.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            if(line[0] != '#'){
                Line x(line);
                v.push_back(x);
            }
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    cout << v.at(7).get_as();
    
    return 0;
}
