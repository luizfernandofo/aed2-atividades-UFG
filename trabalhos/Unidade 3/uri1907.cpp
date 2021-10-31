#include<iostream>

using namespace std;

enum Color
{
    BLACK,
    GRAY,
    WHITE
};

struct Vec2
{
    int x, y;
};

struct Pixel
{
    char pixel;
    Vec2 parent;
    Color color;

    Pixel()
    {
        parent.x = parent.y = -1;
        color = WHITE;
    }
};

void dfs_visit(Pixel **imagem, int i, int j, int *n, int *m)
{

    imagem[i][j].color = GRAY;

    if(i > 0 && imagem[i-1][j].pixel == '.' && imagem[i-1][j].color == WHITE)
    {
        imagem[i-1][j].parent.x = i;
        imagem[i-1][j].parent.y = j;
        dfs_visit(imagem, i-1, j, n, m);
    }

    if(i < ((*n)-1) && imagem[i+1][j].pixel == '.' && imagem[i+1][j].color == WHITE)
    {
        imagem[i+1][j].parent.x = i;
        imagem[i+1][j].parent.y = j;
        dfs_visit(imagem, i+1, j, n, m);
    }

    if(j > 0 && imagem[i][j-1].pixel == '.' && imagem[i][j-1].color == WHITE)
    {
        imagem[i][j-1].parent.x = i;
        imagem[i][j-1].parent.y = j;
        dfs_visit(imagem, i, j-1, n, m);
    }

    if(j < ((*m)-1) && imagem[i][j+1].pixel == '.' && imagem[i][j+1].color == WHITE)
    {
        imagem[i][j+1].parent.x = i;
        imagem[i][j+1].parent.y = j;
        dfs_visit(imagem, i, j+1, n, m);
    }

    imagem[i][j].color = BLACK;

    return;
}


int main(void)
{
    Pixel **imagem;
    int n, m;

    uint32_t clicks=0;

    cin >> n >> m;

    // aloca as linhas da matriz
    imagem = new Pixel*[n];

    // aloca as colunas da matriz
    for (int i = 0; i < n; i++)
    {
        imagem[i] = new Pixel[m];
    }

    // lê os caracteres
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> imagem[i][j].pixel;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(imagem[i][j].color == WHITE && imagem[i][j].pixel == '.')
            {
                dfs_visit(imagem, i, j, &n, &m);
            }
        }  
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(imagem[i][j].parent.x == -1 && imagem[i][j].pixel == '.')
            {
                clicks += 1;
            }
        }  
    }

    cout << clicks << endl;

    // free das colunas alocadas
    for (int i = 0; i < n; i++)
    {
        delete[] imagem[i];
    }

    // free das linhas alocadas
    delete[] imagem;

    return 0;
}
