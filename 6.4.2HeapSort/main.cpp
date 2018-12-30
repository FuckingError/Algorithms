#include <iostream>

using namespace std;
const int N = 100;
int H[N];
int i = 0,j = 0;
int n = 0;//������ĸ���
/*
2018��12��30�� 19��04��
������

�ѣ�ʹ������ʵ��(���� �ӵ�1Ϊ��ʼ ������0)

# �ѵĽ����߼�ͦ�ѵ� ��Ҫ�ٴθ�ϰ


��̼��ɣ�
    1.���㷨����Ҫ������λ���м���ȡ�������б��λ�õ�Ԫ��ʱ ����Ӧ�ô�1��ʼ(����˼ά�ϵĸ��� һ��0 һ��1)
    2.ͬһ�������бȽϴ�С���ȡλ�� �� ��ȡֵ����Ҫ

*/

void HeapBottomUp(int index,int tail){
        int p = H[index];//�洢��ĸ����ֵ ���ں���ֵ�����õ�
        int k = index;
        int s1 = index*2;
        int s2 = s1+1;
        int smax = 0;
        // ���s1=n ˵�����һ����ĸ�ڵ�ֻ��һ���ӽڵ� ��ʱ��s2�ͻᳬ�����鷶Χ�͵�ע��Խ������

        //if��� �ȿ���������� �ٿ����ձ����
        //���µ��ϱ�����ĸ��� ֻҪȷ����ĸ�ڵ㶼�����ӽڵ㼴��
        while(s1<=tail){
            if(s1==tail){
                smax = s1;
            }else{
                smax = H[s1]>H[s2]?s1:s2;// �� ͬһ�������бȽϴ�С���ȡλ�� �� ��ȡֵ����Ҫ
            }
            //�����ĸ���С���ӽڵ��� ����
            if(p<H[smax]){
                H[k] = H[smax];
                H[smax] = p;
                //�� ���������� ��Сֵ�����²㣬����Ҳ����Ҫ����
                k = smax; // !��smax��ʼ����
                p = H[k];
                s1 = k*2;
                s2 = s1+1;
            }else{
                break;
            }
        }
}

/*������
��������洢 ǰn/2���Ǹ�ĸ�ڵ� ������Ҷ�ӽ��
�ӵײ㸸ĸ��㿪ʼ���ϲ���� ���ӽڵ����ֵ�Ƚϣ����С���򽻻�λ��
*/
void BuildHeap(){
    //�����ĸ���Ϊn ���ӽڵ�Ϊ2*n �� 2*n+1
    // ������ô�1��ʼ
    for(i=n/2;i>0;i--){
        HeapBottomUp(i,n);
    }
}

/*
ɾ�����
*/

void Delete(int tail){
    //�������ڵ�����һ��Ҷ�ڵ�
    int temp = H[1];
    H[1] = H[tail];
    H[tail] = temp;
    HeapBottomUp(1,tail-1);
}

//������
void HeapSort(){
    for(i=n;i>1;i--){
        // ��Delete �ڶ������о��ǽ�Ŀǰ���ֵ�ŵ�Ŀǰ���������� ���������i>1 ������i>2
        Delete(i);
    }
}

//��ӡ
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
