#include <iostream>
#include <cstring>
#include <queue>
/*
2018年12月10日 21:48:57
邻接链表

编程技巧：
    C++中队列的使用
        1.头文件 <queue>
        2.push   从尾入，从头出
        3.front    queue.front()取第一个元素 并没有从队列中剔除
                    队列取front 特别是下面将用该数做递归调用 需要先pop再调用
        4.pop
        5.判断队列是否为空 empty
*/
using namespace std;

const int N=100;//顶点个数
int mark[N];
int n;
queue<int> q;


//再写一遍邻接链表
struct Node{
    int v;
    Node *next;//链表中 该顶点的下一个顶点
};

struct HNode{//链表的顶点
    Node *first;
};

//顶点数组
HNode g[N];

//没必要对数组g进行初始化
//void initGraph(){
//    memset(g,0,)
//}

//插入一条边
void insertEdge(HNode &u,int v){//u顶点 v另一个端点
    //动态分配一个新的结点
    Node *n = new Node;//动态分配内存空间 返回的是首地址
    n->v = v;
    n->next = u.first;
    u.first = n;
}

//打印邻接链表
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

//广度优先
void BFS(int v){
    if(mark[v]==0) mark[v] = 1;//！ 这一行是为了主函数中调用BFS对初始顶点mark
    cout<<v<<" ";
    Node *cur = g[v].first;
    while(cur){
        if(mark[cur->v]==0){
            mark[cur->v] = 1;
            q.push(cur->v);
        }
        cur = cur->next;
    }
    if(!q.empty()){// !判断队列是否为空
        //BFS(q.front());// ! queue.front()取第一个元素 并没有从队列中剔除
        // !上面一行是错误的 队列取front 特别是下面将用该数做递归调用 需要先pop再调用
        front = q.front();
        q.pop();      // 剔除
        BFS(front);
    }
}


int main()
{
    int e,u,v;
    //初始化mark
    memset(mark,0,sizeof(int)*N);
    cout<<"顶点数和边数"<<endl;
    cin>>n>>e;
    cout<<"顶点和另一端点"<<endl;
    for(int i=0;i<e;i++){
        cin>>u>>v;
        insertEdge(g[u],v);
        insertEdge(g[v],u);
    }
    print();
    BFS(1);
}
