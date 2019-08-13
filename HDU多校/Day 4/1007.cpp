#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>

//#define Debug

using namespace std;

const int maxn = 1e6+5;
int goal[17][2] = {{3,3},{0,0},{0,1},{0,2},{0,3},{1,0},{1,1},{1,2},{1,3},{2,0},{2,1},{2,2},{2,3},{3,0},{3,1},{3,2}};//数字在矩阵中的坐标
int G[17][17];
int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};

int manhattan()//求曼哈顿距离
{
    int sum = 0;
    for( int i = 0; i < 4; ++i )
    {
        for( int j = 0; j < 4; ++j )
        {
            int w = G[i][j];
            if( w == 0 ) continue;
            sum += abs(goal[w][0]-i) + abs(goal[w][1]-j);
        }
    }
    return sum;
}
bool flag = 0;
void idastar(int x,int y,int pre,int step,int top)//IDA*
{
    if(step > 120) return;
    if( flag ) return ;
    for( int i = 0; i < 4; ++i )
    {
        if( flag ) return ;
        int nx = x+dx[i];
        int ny = y+dy[i];
        if( nx>3 || nx<0 || ny>3 || ny<0 ) continue;
        if(pre + i == 3) continue;
        swap(G[x][y],G[nx][ny]);
        int mht = manhattan();
        if(mht == 0)
        {
            puts("Yes");
            flag = 1;
            return;
        }
        if( mht + step <= top )
        {
            if( flag ) return;
            idastar(nx,ny,i,step+1,top);
        }
        swap(G[x][y],G[nx][ny]);
    }
}

int isok(int state[])//康拓展开判断是否可以到达
{
    int sum = 0;
    for( int i = 0; i < 16; ++i )
    {
        int num = 0;
        if( state[i] == 0 ) continue;
        for( int j = i+1; j < 16; ++j )
        {

            if((state[i] > state[j]) && state[j] != 0) num++;
            //cout<<state[i]<<" "<<state[j]<<" "<<num<<endl;
        }
        sum += num;
    }
    return sum;
}

int main()
{
#ifdef Debug
    freopen("Text.txt","r",stdin);
#endif // Debug
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int cnt = 0;
        int by,bx;
        int state[17];
        flag = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++) {
                scanf("%d", &G[i][j]);
                if(G[i][j] == 0) {
                    state[cnt] = 0;
                    bx = i, by = j;
                    cnt++;
                } else state[cnt++] = G[i][j];
            }
        }
        int ans = isok(state);
        if((ans+3-bx)%2 == 0) puts("Yes");
        else puts("No");
       // int ans = manhattan();
       // if( ans == 0 )
       // {
       //     printf("Yes\n");
       //     continue;
       // }
       // idastar(bx,by,-1,1,120);
       // if(flag) continue;
       // else puts("No");
        //puts("YES");
    }
    return 0;
}
