#include <iostream>
#include <cstring>
/*
2018��12��10�� 17:12:33
������Ȳ��� ʹ���ڽӱ� Ҳ�����ڽ����� ��ʾͼ

���ݽṹ��
    ͼ�Ĵ洢
        1.���� ��Ŷ���
        2.����
    ���
        ����

ע��㣺
    1.�ṹ���еĳ�ԱҪ��ʼ�� �ṹ�����͵������ʼ��ʹ��memset
    2.�ڶ���Ľṹ���� ��һ��num��Ա ���ڼ�¼��ǰ������ڽӵ����  Ҳ���Բ���Ҫnum
    3.�ڱ��������ʱ��forѭ����first��ʼ���� ѭ��Num�� <=num
    4.����DFS��������Ϊ ָ���ı�����ʼ�� mark �� ��ӡ�������Ķ���Ĵ���д��forѭ����
    5.���ú�ָ�������
    6.����ͼ �����ڽ�����ʱ ��forѭ�������ε���insertEdge

Ч�ʷ��������ӶȺ�ͼ�Ĺ�ģ������ ����������������2*E����

*/

using namespace std;

const int N = 100;//��󶥵����
int n,m = 0;//ͼ�Ķ����� �� ����
int mark[N];//����Ƿ��Ѿ�������

//�ṹ�� ���
struct Node{
    int v;//�ý����
    Node *next;//�ڽӽ��
};

//����Ķ���
struct Hnode{
    Node *first;
    int num;//ͳ��һ���ж��ٱ�
};

//ͼ�Ķ��㹹�ɵ�����
Hnode g[N];

//  ��ʼ��g[N] mark[N] ��Ҫ�Ƕ�Hnode�е�num �� mark����
void initGraph(){
    memset(&g,0,sizeof(struct Hnode)*N);
    memset(mark,0,sizeof(int)*N);
}

//����һ���� ! ����ͼ ˫������
//ʹ������  ע�����ú�ָ������� ��C++���Ƽ�ʹ�����ô���ָ�� ��Ϊָ�벻��ȫ
void insertEdge(Hnode &p,int v){
    Node *q = new Node;//��̬�ڴ���� ���ص��ǿ����ڴ浥Ԫ���׵�ַ
    q->v = v;
    q->next = p.first;//->�Ǹ�ָ�������õ�
    p.first = q;
    p.num++;//ÿ���һ���� ��num++ ͳ��һ���ж��ٱ�.
}

//��ӡ�ڽӱ� �����õ�
void print(int n){//����Ϊ�������
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

// ! ע�Ⱑ ����Ҫ����ʼ���mark��Ϊ1
void DFS(int v){//����˵����DFS�����
    mark[v] = 1;
    cout<<v<<" ";

    Hnode u = g[v];//��ǰ����
    Node *cur = u.first;//��ǰ���ڽӶ���
    for(int i=1;i<=u.num;i++){
        if(mark[cur->v]==0){
//            mark[cur->v] = 1;  ������mark�Ļ� ����������Ȳ��ҵ���ʼ���û�б�mark ������ǰ��forѭ���� ��Ϊÿ��DFS�еĲ������Ǳ������ĵ㣬����mark
//            cout<<cur->v<<" ";  ����Ҳ����ǰ��forѭ���� ԭ��ͬ��һ��һ��
            DFS(cur->v);
        }
        cur = cur->next;
    }
}

int main()
{
    int u,v;//u�Ƕ��� v�Ǳߵ���һ���˵�
    cout<<"ͼ�Ķ������ͱ���"<<endl;
    cin>>n>>m;
    cout<<"�������"<<endl;
    //��ʼ��Graph �� mark����
    initGraph();
    for(int i = 1;i<=m;i++){
        cin>>u>>v;
        insertEdge(g[u],v);
        insertEdge(g[v],u);
    }
    print(n);
    DFS(1);

}
