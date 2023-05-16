#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct coordinate{
float x;
float y;
}Point;
float max(float a,float b){
return a>b?a:b;
}
void rands(Point xy[],int n){
int i;
for(i=0;i<n;i++){
  xy[i].x=rand()/(RAND_MAX+1.0)*100;
  xy[i].y=rand()/(RAND_MAX+1.0)*100;
  }
  return;
}
void paixux(Point a[],int low,int high){
  Point tmp;
  tmp=a[low];
  int i=low;
  int j=high;
  if(low<high){
  while(i<j){
  while(i<j&&a[j].x>tmp.x){
  j--;
  }
  a[i]=a[j];
  while(i<j&&a[i].x<tmp.x){
  i++;
  }
  a[j]=a[i];
  }
  a[i]=tmp;
  paixux(a,low,i-1);
  paixux(a,i+1,high);
  }
  else{
  return;}
}
float mins(Point xy[],int n){
int i,j;
float sum=0;
float s[4];
rands(xy,n);
paixux(xy,0,n-1);
for(i=0;i<n;i++){
if(i==0){
    s[0]=xy[i].x*xy[i].y;
    s[1]=xy[i].x*(100-xy[i].y);
    sum+=max(s[0],s[1]);
}
else if(i==n-1){
    s[0]=(xy[i].x-xy[i-1].x)*xy[i].y;
    s[1]=(xy[i].x-xy[i-1].x)*(100-xy[i].y);
    s[2]=(100-xy[i].x)*xy[i].y;
    s[3]=(100-xy[i].x)*(100-xy[i].y);
    sum+=max(s[0],max(s[1],max(s[2],s[3])));
    }
else{
     s[0]=(xy[i].x-xy[i-1].x)*xy[i].y;
     s[1]=(xy[i].x-xy[i-1].x)*(100-xy[i].y);
     sum+=max(s[0],s[1]);
}
}
return sum;
}
int main(){
 int n[]={5,10,13,3,15,16,20,25,26,27};
 float m;
 for(int i=0;i<=9;i++){
 	Point xy[101];
 	m=mins(xy,n[i]);
 	printf("\n\n\n点的个数为%d",n[i]);
 	printf("\n最大矩形面积之和：%f\n",m);
	printf("\n最大矩形面积之和占总面积的比例：%f\n",m/10000);
 }
printf("over");


}
