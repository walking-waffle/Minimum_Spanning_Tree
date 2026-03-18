#include "../include/graph.hpp"
#include "../include/kruskal.hpp"
#include "../include/prim.hpp"
#include <iostream>
#include <chrono>
using namespace std;

int main(int argc, char* argv[]) {
    if ( argc != 2 ) {
        cout << "Usage: ./main <file>\n";
        return 1;
    } // if

    vector<int> OA, EA, data;
    readCSRFile(argv[1], OA, EA, data);

    auto t1 = chrono::high_resolution_clock::now();
    auto mstK = kruskal(OA, EA, data);
    auto t2 = chrono::high_resolution_clock::now();

    int sumK = 0;
    for ( Edge &e : mstK ) sumK += e.weight;

    auto t3 = chrono::high_resolution_clock::now();
    auto mstP = prim(OA, EA, data);
    auto t4 = chrono::high_resolution_clock::now();

    int sumP = 0;
    for ( Edge &e : mstP ) sumP += e.weight;

    cout << "Kruskal: " << sumK << endl;
    cout << "Prim: " << sumP << endl;

    return 0;
}