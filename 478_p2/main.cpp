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

class Link{
    string source;
    int a, b, cp;
    
public:
    Link(string x){
        parse_line(x);
    }
    void parse_line(string x){
        vector<string> y = split(x, '|');
        a = stoi(y[0]);
        b = stoi(y[1]);
        cp = stoi(y[2]);
        source = y[3];
    }
    int get_a(){
        return a;
    }
    int get_b(){
        return b;
    }
    int get_cp(){
        return cp;
    }
    string get_source(){
        return source;
    }
    
};

class Node{
    int id;
    int p_count;
    int c_count;
    vector<Link> peers;
    vector<Link> custs;
    
public:
    Node(){
        p_count = 0;
        c_count = 0;
        id = -1;
    }
    Node(int x){
        p_count = 0;
        c_count = 0;
        id = x;
    }
    int get_id(){
        return id;
    }
    int get_p_count(){
        return p_count;
    }
    int get_c_count(){
        return c_count;
    }
    vector<Link> get_peers(){
        return peers;
    }
    vector<Link> get_custs(){
        return custs;
    }
    void inc_p_count(){
        p_count++;
    }
    void inc_c_count(){
        c_count++;
    }
    void add_cxn(Link x){
        if(x.get_cp() == 0){
            peers.push_back(x);
            p_count++;
        }
        else{
            custs.push_back(x);
            c_count++;
        }
    }
    void print_edges(){
        cout << "Node " << id << "\n";
        cout << "   Peers (" << p_count <<"):\n";
        
        for (int i = 0; i < peers.size(); i++) {
            cout << "       " << peers.at(i).get_b() << "\n";
        }
        
        cout << "\n\n";
        cout << "   Customers (" << c_count <<"):\n";
        
        for (int i = 0; i < custs.size(); i++) {
            cout << "       " << custs.at(i).get_b() << "\n";
        }
        cout << "\n";
    }
    
   
};


int main(int argc, const char * argv[]) {
    
    vector<Link> v;
    
    string line;
    ifstream myfile ("/Users/ivancordoba/Desktop/478_p2/478_p2/input2.txt");
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            
            if(line[0] != '#'){
                Link x(line);
                v.push_back(x);
            }
        }
        myfile.close();
    }
    
    else cout << "Unable to open file";
    
    
    //Creates Vector srcs which has Source types
    vector<Node> nodes;
    
    Node n(v.at(0).get_a());
    n.add_cxn(v.at(0));
    nodes.push_back(n);
    
    for(int i = 1; i < v.size(); i++){
     
        if(v.at(i).get_a() != v.at(i-1).get_a()){
            Node n(v.at(i).get_a());
            n.add_cxn(v.at(i));
            nodes.push_back(n);
        }
        else{
            nodes.back().add_cxn(v.at(i));
        }
        
    }
    
    nodes.at(0).print_edges();
    
    
    
    return 0;
}
