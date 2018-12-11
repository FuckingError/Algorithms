#include <iostream>
#include <cstring>
#include <queue>
/*
2018��12��10�� 21:48:57
�ڽ�����

��̼��ɣ�
    C++�ж��е�ʹ��
        1.ͷ�ļ� <queue>
        2.push   ��β�룬��ͷ��
        3.front    queue.front()ȡ��һ��Ԫ�� ��û�дӶ������޳�
                    ����ȡfront �ر������潫�ø������ݹ���� ��Ҫ��pop�ٵ���
        4.pop
        5.�ж϶����Ƿ�Ϊ�� empty
*/
using namespace std;

const int N=100;//�������
int mark[N];
int n;
queue<int> q;


//��дһ���ڽ�����
struct Node{
    int v;
    Node *next;//������ �ö������һ������
};

struct HNode{//����Ķ���
    Node *first;
};

//��������
HNode g[N];

//û��Ҫ������g���г�ʼ��
//void initGraph(){
//    memset(g,0,)
//}

//����һ����
void insertEdge(HNode &u,int v){//u���� v��һ���˵�
    //��̬����һ���µĽ��
    Node *n = new Node;//��̬�����ڴ�ռ� ���ص����׵�ַ
    n->v = v;
    n->next = u.first;
    u.first = n;
}

//��ӡ�ڽ�����
void print(){
    Node *cur;
    for(int i=1;i<=n;i++){
        cout<<i;
        cur = g[i].first;
        while(cur){
            cout<<"-->"<<cur->v;
            cur = cur->next;
        }
        cout<<endl;
    }
}

//�������
void BFS(int v){
    if(mark[v]==0) mark[v] = 1;//�� ��һ����Ϊ���������е���BFS�Գ�ʼ����mark
    cout<<v<<" ";
    Node *cur = g[v].first;
    while(cur){
        if(mark[cur->v]==0){
            mark[cur->v] = 1;
            q.push(cur->v);
        }
        cur = cur->next;
    }
    if(!q.empty()){// !�ж϶����Ƿ�Ϊ��
        //BFS(q.front());// ! queue.front()ȡ��һ��Ԫ�� ��û�дӶ������޳�
        // !����һ���Ǵ���� ����ȡfront �ر������潫�ø������ݹ���� ��Ҫ��pop�ٵ���
        front = q.front();
        q.pop();      // �޳�
        BFS(front);
    }
}


int main()
{
    int e,u,v;
    //��ʼ��mark
    memset(mark,0,sizeof(int)*N);
    cout<<"�������ͱ���"<<endl;
    cin>>n>>e;
    cout<<"�������һ�˵�"<<endl;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        insertEdge(g[u],v);
        insertEdge(g[v],u);
    }
    print();
    BFS(1);
}
