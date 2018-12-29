#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#define N 100
using namespace std;
/*
时间：2018年12月29日 15点25分
分治法 最近对问题


代码问题：
    1.对一个数组部分的进行排序:使用sort
        sort(a,a+5)

    2.函数需要返回多个变量
        我这里是用结构体解决的
*/
int i=0;

//使用结构体 存储坐标
struct Loca{
    double x;
    double y;
}L[N];

//使用结构体 存储最近对
struct Pair{
    Loca p1;
    Loca p2;
    double distance;
};

//将点对按x排序 从小到大
bool cmp_x(Loca p,Loca q){
    return p.x<q.x;
}

//按y排序 从小到大
bool cmp_y(Loca p,Loca q){
    return p.y<q.y;
}

//打印数组
void print(int n,Loca l[]){
    for(i=0;i<n;i++){
        cout<<"("<<l[i].x<<","<<l[i].y<<")"<<" ";
    }
    cout<<endl;
}

//计算距离
void Distance(Loca p,Loca q,Pair *pair){
    pair->distance = pow(p.x-q.x,2)+pow(p.y-q.y,2);
    pair->p1 = p;
    pair->p2 = q;
}
double Distance(Loca p,Loca q){
    return pow(p.x-q.x,2)+pow(p.y-q.y,2);
}

//蛮力求解最近距离
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


//将p分为两部分 递归分别求出两部分里面的最小距离 得出整体上的最小距离
Pair ECP(Loca P[],int n){//EfficientClosestPair
    //递归到n=3就开始计算最近距离
    if(n<=3){
        return forceClosest(P);
    }else{
        //动态内存分配
        int ln = n/2; //左半部分点个数
        int rn = n-n/2; //右半部分点个数
        Loca mid = P[ln];
        Loca *pl = new Loca[ln];
        Loca *pr = new Loca[rn];
        //复制
        i = 0;
        while(i<n/2) {pl[i] = P[i];i++;}   //这里最好不要将i写在赋值里面 因为等号前后都有i
        while(i<n)  {pr[i-ln] = P[i];i++;}
        //递归调用
        Pair pair1 = ECP(pl,ln);
        Pair pair2 = ECP(pr,rn);
        Pair minP = pair1.distance<pair2.distance?pair1:pair2;
        double d = sqrt(minP.distance);

        //考虑两点分别处在中位线两边
        //得到S  S是以中位线距离为d的区域
        Loca S[n];
        i = ln-1;
        int j = 0;
        while(mid.x-pl[i].x<d&&i>=0) S[j++] = pl[i--];
        i = 0;
        while(pr[i].x-mid.x<d&&i<rn) S[j++] = pr[i++];

        //将S按y排序
        sort(S,S+j,cmp_y);

        //计算出S中的最近距离
        int k = 0;
        for(i=0;i<j-1;i++){
            k = i+1;
            while(k<j&&(d = Distance(S[i],S[i+1]))<minP.distance){//这里d用来暂时存放距离
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
    cout<<"点对数："<<endl;
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
