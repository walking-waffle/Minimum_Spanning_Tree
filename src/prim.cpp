#include "../include/prim.hpp"
#include "../include/heap.hpp"
#include <climits>

vector<int> prim( const vector<int>& OA, const vector<int>& EA, const vector<int>& data ) {
    int V = OA.size() - 1;
    vector<int> key( V, INT_MAX );
    vector<int> parent( V, -1 );

    MinHeap minHeap(V);

    for ( int v = 0; v < V; v++ ) {
        minHeap.array[v] = new MinHeapNode( v, key[v] );
        minHeap.pos[v] = v;
    } // for

    key[0] = 0;
    minHeap.array[0]->key = 0;
    minHeap.size = V;

    while ( minHeap.size != 0 ) {
        auto node = minHeap.extractMin();
        int u = node->v;

        for ( int i = OA[u]; i < OA[u + 1]; i++ ) {
            int v = EA[i];
            int w = data[i];
            if ( minHeap.isInMinHeap(v) && w < key[v] ) {
                key[v] = w;
                parent[v] = u;
                minHeap.decreaseKey(v, w);
            } // if
        } // for
    } // while

    return key;
} // prim