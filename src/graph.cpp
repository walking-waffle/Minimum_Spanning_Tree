#include "../include/graph.hpp"
#include <fstream>
#include <iostream>
using namespace std;

void readCSRFile( string fileName, vector<int> & OA, vector<int> & EA, vector<int> & data ) {
    ifstream in( fileName );
    if (!in) {
        cerr << "Cannot open file: " << fileName << endl;
        exit(1);
    } // if

    string graphType = "";
    int OAsize = 0, EAsize = 0;

    in >> graphType >> OAsize >> EAsize;

    int val = 0;
    while ( OAsize-- ) { in >> val; OA.push_back(val); }
    while ( EAsize-- ) { in >> val; EA.push_back(val); }
    while ( in >> val )  data.push_back(val);

    in.close();
} // readCSRFile