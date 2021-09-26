#include<iostream>
#include<vector>

using namespace std;

struct disjointSets
{
    vector<int> parent , rank;

    // Constructor.
    disjointSets()
    {
        parent.reserve(100000);
        rank.reserve(100000);
        
    }

    void setup(int n)
    {
        parent.resize(n);
        rank.resize( n, 0 );

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find( int u )
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }

        return parent[u];
    }

    // Union by rank
    void merge( int x, int y )
    {
        x = find(x), y = find(y);

        // Tree with smaller height becomes subtree
        if (rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;

        if(rank[x] == rank[y])
            rank[y]++;
    }
    
};


int main(void)
{
    int N;
    int K;
    char op;
    int b1,b2;

    struct disjointSets bancos;

    cin >> N >> K;

    bancos.setup(N);

    while(K--)
    {
        cin >> op >> b1 >> b2;

        if(op == 'C')
        {  
            if(bancos.find(b1) == bancos.find(b2))
                cout << 'S' << endl;
            else
                cout << 'N' << endl;
        }
        else
        {
            bancos.merge(b1, b2);
        }
    }
    
    return 0;
}
