#include <iostream>
#include <algorithm>
using namespace std;
struct item{
    int weight;//��Ʒ������ 
    int value;//��Ʒ�ļ�ֵ 
    float bi;//��Ʒ��λ�����ļ�ֵ 
    float rate;//ʹ���ʣ�1������Ʒ�������룬С��1�����ָ����� 
}items[100];
bool cmp(const item &a,const item &b){
    return a.bi>b.bi;
}
int main(){
    int n;//n����Ʒ
    float c;//��������Ϊc
    cout<<"������Ʒ�����ͱ���������"<<endl; 
    cin>>n>>c;
    cout<<"��������ÿ����Ʒ�ļ�ֵ��������"<<endl;
    float v[n],w[n];//v[n]��n����Ʒ�ļ�ֵ��w[n]��n����Ʒ������ 
    for(int i=0;i<n;i++){
        cin>>items[i].value>>items[i].weight;
        items[i].bi=items[i].value/items[i].weight;//���㵥λ������ֵ
        items[i].rate=0;//��ʼ��ÿ����Ʒ��ʹ���� 
    }
    sort(items,items+n,cmp);//���յ�λ�����ļ�ֵ���� 
    int sum=0,j=0;
    for(j=0;j<n;j++){
        if(items[j].weight<=c){//ѡ��λ��ֵ�������Ĳ��Ҳ��������������� 
            items[j].rate=1;
            sum+=items[j].weight;
            c-=items[j].weight;
            cout<<"�أ�"<<items[j].weight<<"����ֵ��"<<items[j].value<<"����Ʒ�������˱���"<<endl<<"���������"<<items[j].rate<<endl;
        }
        else break;
    } 
    if(j<n){//��Ʒδװ�� 
        items[j].rate=c/items[j].weight;//����������ʣc,�����δװ�����Ʒ��װ���ٵı��� 
        sum+=items[j].rate*items[j].weight;//����װ�벿�ֱ�����Ʒ������ 
        cout<<"�أ�"<<items[j].weight<<"����ֵ��"<<items[j].value<<"�������˱���"<<endl<<"���������"<<items[j].rate<<endl; 
    }
    return 0;    
}
