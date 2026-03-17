#pragma once
#include <vector>
using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge &other) const;
};

vector<Edge> kruskal(vector<int>& OA, vector<int>& EA, vector<int>& data);