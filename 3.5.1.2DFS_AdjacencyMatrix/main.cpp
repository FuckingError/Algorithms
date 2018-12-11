#include <iostream>
#include <cstring>
/*
2018��12��10�� 21:02:52

�ڽӾ�����ŵ����� ����д�������ڽ������
���� Ч��û���ڽӾ����  ��Ϊ������һ���ж�:�Ƿ�Ϊ���ڵ�.

Ч�ʷ�����v^2
*/
using namespace std;

const int N =100;//��󶥵����
int map[N][N];//�ڽӾ���
int n;//������
int mark[N];

//��ʼ��map ��mark
void initMap(){
    for(int i=0;i<N;i++){
        memset(map[i],0,sizeof(int)*N);
    }
    memset(mark,0,sizeof(int)*N);
}

//��ӡ�ڽӾ���
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


void DFS(int u){//����Ϊ��ǰ����
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
    int e,u,v;//e����
    cout<<"��������ͱ���"<<endl;
    cin>>n>>e;
    cout<<"����ߵĶ˵�"<<endl;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        map[u][v] = 1;
        map[v][u] = 1;
    }
    print();
    DFS(1);

}
