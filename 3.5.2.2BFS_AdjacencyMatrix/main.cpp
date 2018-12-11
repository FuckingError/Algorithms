#include <iostream>
#include <cstring>
#include <queue>

/*
2018年12月11日 09:10:20

队列一定要判断是否为空

*/
using namespace std;
int n;
const int N=100;

int g[N][N];
int mark[N];
//队列
queue<int> q;

//初始化邻接矩阵 二维数组初始化
void initGraph(){
    for(int i=0;i<=N;i++){
        memset(g[i],0,sizeof(int)*N);
    }
    memset(mark,0,sizeof(int)*N);
}

//打印
void print(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0&&j!=0) cout<<j;
            else if(j==0&&i!=0) cout<<i;
            else cout<<g[i][j];
            cout<<" ";
        }
        cout<<endl;
    }
}

//BFS
void BFS(int v){
    if(mark[v]==0) mark[v]=1;
    cout<<v<<" ";
    int front;
    for(int i=1;i<=n;i++){
        if(g[v][i]==1&&mark[i]==0){
            q.push(i);
            mark[i] = 1;
        }
    }
    if(!q.empty()){//！ 一定要判断是否为空
        front = q.front();
        q.pop();
        BFS(front);
    }
}

int main()
{
    initGraph();
    int e,u,v;
    cout << "顶点个数和边数" << endl;
    cin>>n>>e;
    cout << "输入两个端点"<<endl;;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    print();
    BFS(1);


}
