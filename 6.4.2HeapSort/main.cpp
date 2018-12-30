#include <iostream>

using namespace std;
const int N = 100;
int H[N];
int i = 0,j = 0;
int n = 0;//待排序的个数
/*
2018年12月30日 19点04分
堆排序

堆：使用数组实现(数组 从第1为开始 而不是0)

# 堆的建立逻辑挺难的 需要再次复习


编程技巧：
    1.当算法中需要以数组位进行计算取该数组中别的位置的元素时 数组应该从1开始(减少思维上的负担 一会0 一会1)
    2.同一个数组中比较大小后获取位置 比 获取值更重要

*/

void HeapBottomUp(int index,int tail){
        int p = H[index];//存储父母结点的值 用于后面值交换用的
        int k = index;
        int s1 = index*2;
        int s2 = s1+1;
        int smax = 0;
        // 如果s1=n 说明最后一个父母节点只有一个子节点 此时的s2就会超出数组范围就得注意越界问题

        //if语句 先考虑特殊情况 再考虑普遍情况
        //从下到上遍历父母结点 只要确保父母节点都大于子节点即可
        while(s1<=tail){
            if(s1==tail){
                smax = s1;
            }else{
                smax = H[s1]>H[s2]?s1:s2;// ！ 同一个数组中比较大小后获取位置 比 获取值更重要
            }
            //如果父母结点小于子节点则 交换
            if(p<H[smax]){
                H[k] = H[smax];
                H[smax] = p;
                //！ 交换结束后 将小值换到下层，子树也就需要调整
                k = smax; // !从smax开始遍历
                p = H[k];
                s1 = k*2;
                s2 = s1+1;
            }else{
                break;
            }
        }
}

/*构建堆
堆用数组存储 前n/2个是父母节点 后面是叶子结点
从底层父母结点开始往上层遍历 与子节点最大值比较，如果小，则交换位置
*/
void BuildHeap(){
    //如果父母结点为n 则子节点为2*n 和 2*n+1
    // ！数组得从1开始
    for(i=n/2;i>0;i--){
        HeapBottomUp(i,n);
    }
}

/*
删除结点
*/

void Delete(int tail){
    //交换根节点和最后一个叶节点
    int temp = H[1];
    H[1] = H[tail];
    H[tail] = temp;
    HeapBottomUp(1,tail-1);
}

//堆排序
void HeapSort(){
    for(i=n;i>1;i--){
        // ！Delete 在堆排序中就是将目前最大值放到目前数组的最后面 所以这里得i>1 而不能i>2
        Delete(i);
    }
}

//打印
void print(){
    for(i=1;i<=n;i++) cout<<H[i]<<" ";
}

int main()
{
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>H[i];
    }
    BuildHeap();
    HeapSort();
    print();
    return 0;
}
