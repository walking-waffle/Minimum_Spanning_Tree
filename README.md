# Minimum Spanning Tree (MST) - Kruskal & Prim (CSR Graph)

本專案實作兩種經典的最小生成樹（Minimum Spanning Tree, MST）演算法：
Kruskal 演算法（搭配 Union-Find）
Prim 演算法（搭配 Min Heap）
輸出 MST 的權重總和

### 使用
g++ -std=c++17 src/*.cpp -Iinclude -o main
./main ../data/filename

### 輸入圖形格式
圖的儲存方式採用 CSR（Compressed Sparse Row）格式
檔案內容開頭為：
WeightedAdjacencyGraph
offset array size (V)
edge array size (E)
o1
o2
.....
oV
e1
e2
.....
eE
w1
w2
.....
wE

- `WeightedAdjacencyGraph`：檔案格式標記（字串）
- `offset array (OA)`：
  - 長度為 `x = |V| + 1`
  - `OA[u] ~ OA[u+1]-1` 表示節點 `u` 的所有邊
- `edge array (EA)`：
  - 儲存每條邊的「終點節點」
- `weight array (data)`：
  - 對應每條邊的權重

### 檔案目錄結構
.
├── data/
│       testGraph
│
├── include/
│       graph.hpp
│       heap.hpp
│       kruskal.hpp
│       prim.hpp
│       union_find.hpp
│
├── src/
│       graph.cpp
│       heap.cpp
│       kruskal.cpp
│       main.cpp
│       prim.cpp
│       union_find.cpp

### Kruskal 演算法

1. 將所有邊依權重排序

2. 依序選擇最小邊

3. 使用 Union-Find 檢查是否形成 cycle

4. 若不形成則加入 MST，重複以上 2.~4. 直到所有節點皆加入集合

### Prim 演算法

1. 從起點（0）開始

2. 使用 Min Heap 選擇最小權重邊

3. 逐步擴展生成樹
