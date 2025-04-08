#include<stdio.h>
int a[10][10];
int D[10][10];
int n;
void floyd(int a[10][10],int n){
int i,j,k;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
D[i][j]=a[i][j];

}
}
for(k=0;k<n;k++){
for(i=0;i<n;i++){
for(j=0;j<n;j++){
D[i][j]=min(D[i][j],(D[i][k]+D[k][j]));
}}}}
int min(int a,int b){
if(a<b)return a;
else return b;
}

int main(){
printf("enter number of vertices\n");
scanf("%d",&n);
printf("enter input matrix\n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
scanf("%d",&a[i][j]);

}
}
floyd(a,n);
printf("distance matrix\n");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
printf("%d ",D[i][j]);
}
printf("\n");
}
return 0;
}
