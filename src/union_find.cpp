#include "../include/union_find.hpp"

int findSet( int u, vector<int>& parent ) {
    if ( u != parent[u] )
        parent[u] = findSet( parent[u], parent );
    return parent[u];
} // findSet

void unite( int u, int v, vector<int>& parent, vector<int>& rank ) {
    int ru = findSet( u, parent );
    int rv = findSet( v, parent );
    if ( ru != rv ) {
        if ( rank[ru] > rank[rv] ) parent[rv] = ru;
        else if ( rank[ru] < rank[rv] ) parent[ru] = rv;
        else { parent[rv] = ru; rank[ru]++; }
    } // if
} // unite