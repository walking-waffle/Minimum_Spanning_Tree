#pragma once
#include <vector>
#include <string>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const;
};

void readCSRFile( string fileName, vector<int>& OA, vector<int>& EA, vector<int>& data );