#include <stdio.h>
#define MAX 100 

int get(int n)
{
	printf("\n\n��������Ϊ%d\n",n);
	int a[MAX];
	int x=2;
	int index=0;
	a[index++]=x;
	n-=x;
	//��n�ֽ�Ž�����
	while(n>a[index-1]){
		a[index]=a[index-1]+1;
		n-=a[index];
		index++;
	} 
	int num=index-1;
	//����������Ӻ���ǰ�ֳ�1��������
	while(n){
		a[num]++; 
		num=(num-1+index)%(index); 
		n--;
	} 

	//�������
	printf("�ֽ��������Ϊ��"); 
	for(int i=0;i<index;i++){
		printf("%d;",a[i]);
	} 
	
	//�������˻� 
	int result=1;
	for(int i=0;i<index;i++){
		result*=a[i];
	 } 
	 printf("\n���˻�Ϊ��%d\n",result);
	
	return 0;
 }

int main(){
	int a;
	int n[10]={10,22,15,14,13,16,17,33,25,20};
	printf("10�����Ե���\n");
	for(int i=0;i<=9;i++){
		printf("%d;",n[i]);
	} 
	printf("\n");
	for(int i=0;i<=9;i++){
		a=n[i];
		get(a);
	}
	
	return 0;
	
}
