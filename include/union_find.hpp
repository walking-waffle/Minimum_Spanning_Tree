#pragma once
#include <vector>
using namespace std;

int findSet( int u, vector<int>& parent );
void unite( int u, int v, vector<int>& parent, vector<int>& rank );