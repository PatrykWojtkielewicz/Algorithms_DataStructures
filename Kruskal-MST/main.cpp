#include <bits/stdc++.h>

// Disjoint set data structure
class DSU 
{
    private:
        std::vector<int> parent, rank;
    
    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n);

            for(size_t i=0; i<n; ++i)
            {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int find(int i)
        {
            if(parent[i] == i)
                return i;
            else
                return parent[i] == find(parent[i]);
        }

        void unite(int x, int y)
        {
            int s1 = find(x), s2 = find(y);
            
            if(s1 != s2)
            {
                if(rank[s1] < rank[s2])
                    parent[s1] = s2;
                else if(rank[s1] > rank[s2])
                    parent[s2] = s1;
                else
                    parent[s2] = s1, rank[s1]++;
            }
        }
};

bool compareWeights(std::vector<int>&a, std::vector<int>&b)
{
    return a[2] <= b[2];
}

int kruskalMST(int V, std::vector<std::vector<int>> &edges)
{
    std::sort(edges.begin(), edges.end(), compareWeights);

    DSU dsu(V);
    int cost=0, count=0;

    // Traversing sorted edges
    for(auto &e : edges)
    {
        int x=e[0], y=e[1], w=e[2];

        // Checking for cycles
        if(dsu.find(x) != dsu.find(y))
        {
            dsu.unite(x, y);
            cost += w;
            if (++count == V-1) break;
        }
    }
    return cost;
}

int main()
{
    // Each edge is coded as follows: {source, destination, weight}
    std::vector<std::vector<int>> edges = {
        {0, 1, 4}, {0, 2, 3}, {1, 2, 5}, {1, 3, 2}, {2, 3, 7}, {3, 4, 2}, {4, 0, 4}, {4, 1, 4}, {4, 5, 6}
    };

    std::cout <<  kruskalMST(6, edges);

    return 0;
}