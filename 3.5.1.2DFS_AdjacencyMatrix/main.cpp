#include <iostream>
#include <cstring>
/*
2018年12月10日 21:02:52

邻接矩阵的优点在于 代码写起来比邻接链表简单
但是 效率没有邻接矩阵高  因为它多了一个判断:是否为相邻点.

效率分析：v^2
*/
using namespace std;

const int N =100;//最大顶点个数
int map[N][N];//邻接矩阵
int n;//顶点数
int mark[N];

//初始化map 和mark
void initMap(){
    for(int i=0;i<N;i++){
        memset(map[i],0,sizeof(int)*N);
    }
    memset(mark,0,sizeof(int)*N);
}

//打印邻接矩阵
void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j!=0){
                cout<<j<<" ";
            }else if(j==0&&i!=0){
                cout<<i<<" ";
            }else{
                cout<<map[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}


void DFS(int u){//参数为当前顶点
    cout<<u<<" ";
    mark[u] = 1;
    for(int i=0;i<n;i++){
        if(map[u][i]==1&&mark[i]==0){
            DFS(i);
        }
    }
}

int main()
{
    int e,u,v;//e边数
    cout<<"顶点个数和边数"<<endl;
    cin>>n>>e;
    cout<<"输入边的端点"<<endl;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        map[u][v] = 1;
        map[v][u] = 1;
    }
    print();
    DFS(1);

}
