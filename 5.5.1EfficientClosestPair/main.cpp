#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define N 100
using namespace std;
/*
ʱ�䣺2018��12��29�� 15��25��
���η� ���������


�������⣺
    1.��һ�����鲿�ֵĽ�������:ʹ��sort
        sort(a,a+5)

    2.������Ҫ���ض������
        ���������ýṹ������
*/
int i=0;

//ʹ�ýṹ�� �洢����
struct Loca{
    double x;
    double y;
}L[N];

//ʹ�ýṹ�� �洢�����
struct Pair{
    Loca p1;
    Loca p2;
    double distance;
};

//����԰�x���� ��С����
bool cmp_x(Loca p,Loca q){
    return p.x<q.x;
}

//��y���� ��С����
bool cmp_y(Loca p,Loca q){
    return p.y<q.y;
}

//��ӡ����
void print(int n,Loca l[]){
    for(i=0;i<n;i++){
        cout<<"("<<l[i].x<<","<<l[i].y<<")"<<" ";
    }
    cout<<endl;
}

//�������
void Distance(Loca p,Loca q,Pair *pair){
    pair->distance = pow(p.x-q.x,2)+pow(p.y-q.y,2);
    pair->p1 = p;
    pair->p2 = q;
}
double Distance(Loca p,Loca q){
    return pow(p.x-q.x,2)+pow(p.y-q.y,2);
}

//��������������
Pair forceClosest(Loca P[]){
    Pair pair[4];
    Distance(P[0],P[1],pair);
    pair[3] = pair[0];
    Distance(P[0],P[2],pair+1);
    Distance(P[1],P[2],pair+2);
    for(i=1;i<3;i++){
        if(pair[i].distance<pair[3].distance) pair[3] = pair[i];
    }
    return pair[3];
}


//��p��Ϊ������ �ݹ�ֱ�����������������С���� �ó������ϵ���С����
Pair ECP(Loca P[],int n){//EfficientClosestPair
    //�ݹ鵽n=3�Ϳ�ʼ�����������
    if(n<=3){
        return forceClosest(P);
    }else{
        //��̬�ڴ����
        int ln = n/2; //��벿�ֵ����
        int rn = n-n/2; //�Ұ벿�ֵ����
        Loca mid = P[ln];
        Loca *pl = new Loca[ln];
        Loca *pr = new Loca[rn];
        //����
        i = 0;
        while(i<n/2) {pl[i] = P[i];i++;}   //������ò�Ҫ��iд�ڸ�ֵ���� ��Ϊ�Ⱥ�ǰ����i
        while(i<n)  {pr[i-ln] = P[i];i++;}
        //�ݹ����
        Pair pair1 = ECP(pl,ln);
        Pair pair2 = ECP(pr,rn);
        Pair minP = pair1.distance<pair2.distance?pair1:pair2;
        double d = sqrt(minP.distance);

        //��������ֱ�����λ������
        //�õ�S  S������λ�߾���Ϊd������
        Loca S[n];
        i = ln-1;
        int j = 0;
        while(mid.x-pl[i].x<d&&i>=0) S[j++] = pl[i--];
        i = 0;
        while(pr[i].x-mid.x<d&&i<rn) S[j++] = pr[i++];

        //��S��y����
        sort(S,S+j,cmp_y);

        //�����S�е��������
        int k = 0;
        for(i=0;i<j-1;i++){
            k = i+1;
            while(k<j&&(d = Distance(S[i],S[i+1]))<minP.distance){//����d������ʱ��ž���
                minP.distance = d;
                minP.p1 = S[i];
                minP.p2 = S[i+1];
            }
        }
        return minP;
    }
}

int main()
{
    int n=0;
    cout<<"�������"<<endl;
    cin>>n;

    for(i=0;i<n;i++){
        cin>>L[i].x>>L[i].y;
    }
    sort(L,L+n,cmp_x);
    Pair p;
    p = ECP(L,n);
    cout<<p.distance<<endl;;
    cout<<"p1: ("<<p.p1.x<<","<<p.p1.y<<")"<<endl;
    cout<<"p2: ("<<p.p2.x<<","<<p.p2.y<<")"<<endl;
}
