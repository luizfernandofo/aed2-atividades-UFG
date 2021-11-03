#include<iostream>

#define MAX 1024

using std::cin;
using std::cout;
using std::endl;

char imagem[MAX][MAX];

int n, m;

int clicks=0;

int vecx[] = {1, -1, 0, 0};
int vecy[] = {0, 0, -1, 1};

bool inBound(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return (imagem[i][j] == '.');
}

void DFS(int i, int j)
{
    imagem[i][j] = 'v';

    for (int k = 0; k < 4; k++)
    {
        if( inBound(i + vecx[k], j + vecy[k]) )
            DFS(i + vecx[k], j + vecy[k]);
    }
    
    return;
}

int main(void)
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> imagem[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(imagem[i][j] == '.')
            {
                clicks++;
                DFS(i, j);
            }            
        }
    }

    cout << clicks << endl;    

    return 0;
}
