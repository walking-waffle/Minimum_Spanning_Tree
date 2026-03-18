#include "../include/union_find.hpp"

// 找出 u 所屬集合的 root
int findSet( int u, vector<int>& parent ) {
    if ( u != parent[u] )
        parent[u] = findSet( parent[u], parent );
    return parent[u];
} // findSet

// 把 u 和 v 所在集合合併
void unite( int u, int v, vector<int>& parent, vector<int>& rank ) {
    int ru = findSet( u, parent );
    int rv = findSet( v, parent );
    if ( ru != rv ) {
        if ( rank[ru] > rank[rv] ) parent[rv] = ru;
        else if ( rank[ru] < rank[rv] ) parent[ru] = rv;
        else { parent[rv] = ru; rank[ru]++; }
    } // if
} // unite