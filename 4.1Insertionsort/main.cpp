#include <iostream>

using namespace std;

int main()
{
    int A[100];
    int i,j = 0;
    int num = 0;
    int temp = 0;//��ʱ�洢A[i] �����������������ƶ�һλ

    cin>>num;
    for(i=0;i<num;i++){
        cin>>A[i];
    }
    for(i=1;i<num;i++){
        temp = A[i];
        j = i-1;
        while(j>=0&&temp<A[j]){//i֮ǰ���������ź����  �����ʱ��tempС��A[j] ��Ӧ����ǰ�ƶ�һλֱ�����ֱ�tempС��������temp���뵽������һλ
            A[j+1] = A[j];
            j--;
        }
        //��ʱ���������
        //1.temp>A[j] ��ʱ����temp���뵽A[j]��һλ ��j+1
        //2.while������������ʱj=-1����temp���뵽0����Ҳ��j+!
        A[j+1] = temp;
    }
    for(i=0;i<num;i++){
        cout<<A[i]<<" ";
    }
}
