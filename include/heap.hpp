#pragma once
#include <vector>
using namespace std;

class MinHeapNode {
public:
    int v;
    int key;
    MinHeapNode(int vertex, int k);
};

class MinHeap {
private:
    void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b);
public:
    int size;
    int capacity;
    vector<int> pos;
    vector<MinHeapNode*> array;

    MinHeap(int capacity);
    void minHeapify(int idx);
    MinHeapNode* extractMin();
    void decreaseKey(int v, int key);
    bool isInMinHeap(int v) const;
};