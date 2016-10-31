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

class Type{
    string name;
    int count;
    vector<Line> lines;
    
public:
    Type(){
        count = 0;
        name = "";
    }
    Type(string x){
        count = 0;
        name = x;
    }
    void add_line(Line x){
        lines.push_back(x);
    }
    int get_count(){
        return count;
    }
    string get_name(){
        return name;
    }
    vector<Line> get_lines(){
        return lines;
    }
    void set_count(int x){
        count = x;
    }
    void set_name(string x){
        name = x;
    }
    
};


class Source{
    string name;
    int count;
    vector<Line> lines;
    vector<Type> types;
    
public:
    Source(){
        count = 0;
        name = "";
    }
    Source(string x){
        count = 0;
        name = x;
    }
    int get_count(){
        return count;
    }
    string get_name(){
        return name;
    }
    vector<Line> get_lines(){
        return lines;
    }
    void set_count(int x){
        count = x;
    }
    void set_name(string x){
        name = x;
    }
    void add_line(Line x){
        lines.push_back(x);
    }
    void count_types(){
        bool add = false;
        
        vector<Source> typs;
        
        for(int i = 0; i < lines.size(); i++){
            
            for(int j = 0; j < typs.size(); j++){
                
                if(lines.at(i).get_source() == typs.at(j).get_name()){
                    typs.at(j).add_line(lines.at(i));
                    add = true;
                }
                
            }
            if(add == false){
                Type t(lines.at(i).get_source());
                t.add_line(lines.at(i));
                typs.push_back(t);
            }
            
            add = false;
        }
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
    
    
    //Creates Vector srcs which has Source types
    bool add = false;
    vector<Source> srcs;
    
    for(int i = 0; i < v.size(); i++){
        
        for(int j = 0; j < srcs.size(); j++){
            
            if(v.at(i).get_source() == srcs.at(j).get_name()){
                srcs.at(j).add_line(v.at(i));
                add = true;
            }
            
        }
        if(add == false){
            Source s(v.at(i).get_source());
            s.add_line(v.at(i));
            srcs.push_back(s);
        }
        
        add = false;
    }
    
    cout << v.at(7).get_as();
    
    return 0;
}
