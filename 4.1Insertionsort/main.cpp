#include <iostream>

using namespace std;

int main()
{
    int A[100];
    int i,j = 0;
    int num = 0;
    int temp = 0;//暂时存储A[i] 方便整个数组往后移动一位

    cin>>num;
    for(i=0;i<num;i++){
        cin>>A[i];
    }
    for(i=1;i<num;i++){
        temp = A[i];
        j = i-1;
        while(j>=0&&temp<A[j]){//i之前的数都是排好序的  如果此时的temp小于A[j] 则应该往前移动一位直到出现比temp小的数，将temp插入到该数后一位
            A[j+1] = A[j];
            j--;
        }
        //此时有两种情况
        //1.temp>A[j] 此时，将temp插入到A[j]后一位 即j+1
        //2.while遍历结束，此时j=-1，则将temp插入到0，即也是j+!
        A[j+1] = temp;
    }
    for(i=0;i<num;i++){
        cout<<A[i]<<" ";
    }
}
