#include <iostream>
#include <cstring>
#include <queue>

/*
2018��12��11�� 09:10:20

����һ��Ҫ�ж��Ƿ�Ϊ��

*/
using namespace std;
int n;
const int N=100;

int g[N][N];
int mark[N];
//����
queue<int> q;

//��ʼ���ڽӾ��� ��ά�����ʼ��
void initGraph(){
    for(int i=0;i<=N;i++){
        memset(g[i],0,sizeof(int)*N);
    }
    memset(mark,0,sizeof(int)*N);
}

//��ӡ
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
    if(!q.empty()){//�� һ��Ҫ�ж��Ƿ�Ϊ��
        front = q.front();
        q.pop();
        BFS(front);
    }
}

int main()
{
    initGraph();
    int e,u,v;
    cout << "��������ͱ���" << endl;
    cin>>n>>e;
    cout << "���������˵�"<<endl;;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    print();
    BFS(1);


}
