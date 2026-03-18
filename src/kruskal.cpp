#include "../include/graph.hpp"
#include "../include/kruskal.hpp"
#include "../include/union_find.hpp"
#include <algorithm>

// 依照 weight 由小到大排序
bool Edge::operator<(const Edge &other) const {
    return weight < other.weight;
}

// 將 CSR 轉成邊集合
static vector<Edge> getEdges( vector<int>& OA, vector<int>& EA, vector<int>& data ) {
    vector<Edge> edges;
    int n = OA.size() - 1;
    for ( int u = 0; u < n; u++ )
        for ( int i = OA[u]; i < OA[u + 1]; i++ )
            edges.push_back( {u, EA[i], data[i]} );

    return edges;
} // getEdges

vector<Edge> kruskal( vector<int>& OA, vector<int>& EA, vector<int>& data ) {
    vector<Edge> edges = getEdges( OA, EA, data );
    sort( edges.begin(), edges.end() );

    // init
    int n = OA.size() - 1;
    vector<int> parent(n), rank(n, 0);
    for ( int i = 0; i < n; i++ ) parent[i] = i;

    vector<Edge> mst;
    for ( Edge &e : edges ) {
        // 檢查邊的兩點是否在同個 set
        if ( findSet( e.u, parent ) != findSet( e.v, parent ) ) {
            unite( e.u, e.v, parent, rank );
            mst.push_back(e);
        } // if
    } // for

    return mst;
} // kruskal
