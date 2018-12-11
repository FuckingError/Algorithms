#include <iostream>
#include <cstring>
/*
2018年12月10日 17:12:33
深度优先查找 使用邻接表 也就是邻接链表 表示图

数据结构：
    图的存储
        1.数组 存放顶点
        2.链表
    标记
        数组

注意点：
    1.结构体中的成员要初始化 结构体类型的数组初始化使用memset
    2.在顶点的结构体中 加一个num成员 用于记录当前顶点的邻接点个数  也可以不需要num
    3.在遍历链表的时候，for循环从first开始遍历 循环Num次 <=num
    4.这里DFS函数参数为 指定的遍历起始点 mark 和 打印遍历到的顶点的代码写在for循环外
    5.引用和指针的区别
    6.无向图 构建邻接链表时 在for循环中两次调用insertEdge

效率分析：复杂度和图的规模成正比 基本操作次数等于2*E边数

*/

using namespace std;

const int N = 100;//最大顶点个数
int n,m = 0;//图的顶点数 和 边数
int mark[N];//标记是否已经被访问

//结构体 结点
struct Node{
    int v;//该结点编号
    Node *next;//邻接结点
};

//链表的顶点
struct Hnode{
    Node *first;
    int num;//统计一共有多少边
};

//图的顶点构成的数组
Hnode g[N];

//  初始化g[N] mark[N] 主要是对Hnode中的num 和 mark清零
void initGraph(){
    memset(&g,0,sizeof(struct Hnode)*N);
    memset(mark,0,sizeof(int)*N);
}

//插入一条边 ! 无向图 双向链表
//使用引用  注意引用和指针的区别 在C++中推荐使用引用代替指针 因为指针不安全
void insertEdge(Hnode &p,int v){
    Node *q = new Node;//动态内存分配 返回的是开辟内存单元的首地址
    q->v = v;
    q->next = p.first;//->是给指针类型用的
    p.first = q;
    p.num++;//每添加一条边 则num++ 统计一共有多少边.
}

//打印邻接表 测试用的
void print(int n){//参数为顶点个数
    Hnode u;
    Node *cur;
    for(int i=1;i<=n;i++){
        u = g[i];
        cur = u.first;
        cout<<i;
        for(int j=1;j<=u.num;j++){// ! j<=u.num
            cout<<"--->"<<cur->v;
            cur = cur->next;
        }
        cout<<endl;
    }
}

// ! 注意啊 首先要把起始点的mark置为1
void DFS(int v){//参数说明：DFS的起点
    mark[v] = 1;
    cout<<v<<" ";

    Hnode u = g[v];//当前顶点
    Node *cur = u.first;//当前的邻接顶点
    for(int i=1;i<=u.num;i++){
        if(mark[cur->v]==0){
//            mark[cur->v] = 1;  在这里mark的话 整个深度优先查找的起始点就没有被mark 所以提前到for循环外 因为每次DFS中的参数就是遍历到的点，把它mark
//            cout<<cur->v<<" ";  这里也是提前到for循环外 原因同上一行一样
            DFS(cur->v);
        }
        cur = cur->next;
    }
}

int main()
{
    int u,v;//u是顶点 v是边的另一个端点
    cout<<"图的顶点数和边数"<<endl;
    cin>>n>>m;
    cout<<"输入各边"<<endl;
    //初始化Graph 和 mark数组
    initGraph();
    for(int i = 1;i<=m;i++){
        cin>>u>>v;
        insertEdge(g[u],v);
        insertEdge(g[v],u);
    }
    print(n);
    DFS(1);

}
