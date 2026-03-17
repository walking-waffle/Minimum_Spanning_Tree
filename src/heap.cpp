#include "../include/heap.hpp"

MinHeapNode::MinHeapNode(int vertex, int k) : v(vertex), key(k) {}

MinHeap::MinHeap(int capacity) : size(0), capacity(capacity), pos(capacity), array(capacity) {}

void MinHeap::swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
} // swapMinHeapNode

void MinHeap::minHeapify( int idx ) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if ( ( left < size ) && ( array[left]->key < array[smallest]->key ) )
        smallest = left;
    if ( ( right < size ) && ( array[right]->key < array[smallest]->key ) )
        smallest = right;

    if ( smallest != idx ) {
        MinHeapNode* smallestNode = array[smallest];
        MinHeapNode* idxNode = array[idx];

        pos[smallestNode->v] = idx;
        pos[idxNode->v] = smallest;

        swapMinHeapNode( &array[smallest], &array[idx] );
        minHeapify( smallest );
    } // if
} // minHeapify

MinHeapNode* MinHeap::extractMin() {
    if ( size == 0 ) return nullptr;

    MinHeapNode* root = array[0];
    MinHeapNode* lastNode = array[size - 1];
    array[0] = lastNode;

    pos[root->v] = size - 1;
    pos[lastNode->v] = 0;

    size--;
    minHeapify(0);

    return root;
} // extractMin

void MinHeap::decreaseKey(int v, int key) { 
    int i = pos[v]; 
    array[i]->key = key; 
    while ( i && ( array[i]->key < array[(i - 1) / 2]->key ) ) { 
        pos[array[i]->v] = (i - 1) / 2; 
        pos[array[(i - 1) / 2]->v] = i; 
        swapMinHeapNode( &array[i], &array[(i - 1) / 2] ); 
        i = (i - 1) / 2; 
    } // while 
} // decreaseKey

bool MinHeap::isInMinHeap(int v) const { 
    return pos[v] < size; 
} // isInMinHeap