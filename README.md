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
```
.
├── data/
│   ├── testGraph
│
├── include/
│   ├── graph.hpp
│   ├── heap.hpp
│   ├── kruskal.hpp
│   ├── prim.hpp
│   ├── union_find.hpp
│
├── src/
│   ├── graph.cpp
│   ├── heap.cpp
│   ├── kruskal.cpp
│   ├── main.cpp
│   ├── prim.cpp
│   ├── union_find.cpp
```

### Kruskal 演算法
策略：每次選擇「最小權重」且「不形成 cycle」的邊

##### 步驟
1. 將所有邊依照權重 由小到大排序
2. 初始化空的 MST
3. 依序選擇最小邊
4. 若加入該邊 不會形成 cycle → 加入 MST
5. 重複直到 MST 有 V − 1 條邊

##### Cycle 判斷方法

Disjoint Set（Union-Find）

find(x) → 找集合 root
union(x,y) → 合併集合

如果：
find(u) == find(v)
代表加入會形成 cycle

### Prim 演算法
策略：從一個節點開始，逐步擴展最小生成樹

##### 步驟
1. 選擇一個起點，將他加入 MST
2. 找出所有「從 MST 內部連到外部」的邊。 例如：(u, v). u ∈ MST, v ∉ MST
3. 從這些邊中選擇權重最小的邊，將該邊加入 MST
4. 重複 2 和 3 直到所有節點加入

##### 找出權重最小的方法
使用 min heap 實作 Priority Queue
