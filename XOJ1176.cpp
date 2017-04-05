#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int x[] = {-1, -1, -1, 0, 1, 1,  1,  0};
int y[] = {-1,  0,  1, 1, 1, 0, -1, -1};

int a[10][10];
int n, m;

bool bound(int cx, int cy)
{
    if (cx >= 0 && cx < n && cy >= 0 && cy < m)
        return true;
    return false;
}

void clear(int cx, int cy)
{
    int nx, ny;
    a[cx][cy] = 0;
    for (int i = 0; i < 8; i++) 
    {
        nx = cx + x[i];
        ny = cy + y[i];
        if (bound(nx, ny) && a[nx][ny])
            clear(nx, ny);
    }
}

int main()
 {
    int i, j, nr = 0;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                clear(i, j);
                nr++;
            }
        }
    }
    printf("%d\n", nr);

    return 0;
}
