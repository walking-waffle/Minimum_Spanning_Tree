import sys
import random
import networkx as nx
import matplotlib.pyplot as plt

if len(sys.argv) < 2:
    print("Usage:")
    print("  ws  n k p")
    print("  plc n m p")
    print("  ba  n m")
    sys.exit(1)

graph_type = sys.argv[1]

try:
    if graph_type == "ws":
        # Watts-Strogatz
        if len(sys.argv) != 5:
            raise ValueError
        n = int(sys.argv[2])
        k = int(sys.argv[3])
        p = float(sys.argv[4])

        g = nx.connected_watts_strogatz_graph(n, k, p, tries=100)

    elif graph_type == "plc":
        # Powerlaw Cluster
        if len(sys.argv) != 5:
            raise ValueError
        n = int(sys.argv[2])
        m = int(sys.argv[3])
        p = float(sys.argv[4])

        g = nx.powerlaw_cluster_graph(n, m, p)

    elif graph_type == "ba":
        # Barabasi-Albert
        if len(sys.argv) != 4:
            raise ValueError
        n = int(sys.argv[2])
        m = int(sys.argv[3])

        g = nx.barabasi_albert_graph(n, m)

    else:
        print("Unknown graph type:", graph_type)
        sys.exit(1)

except ValueError:
    print("Parameter error!")
    sys.exit(1)


print("isConnected:", nx.is_connected(g))
print("isDirected:", nx.is_directed(g))

# 加權重 (1~100)
for u, v in g.edges():
    g[u][v]['weight'] = random.randint(1, 100)

# 轉有向圖
g = g.to_directed()

# 檔名根據類型
filename = f"{graph_type}.el"

# 把權重一起寫進去
nx.write_edgelist(g, filename, data=['weight'])

print("n:", g.number_of_nodes())
print("m:", g.number_of_edges())
print("finish")

# 大圖不顯示
if g.number_of_nodes() <= 1000:
    nx.draw(g)
    plt.show()
else:
    print("節點數量超過 1000 圖形無法視覺化")