#include <stdio.h>
#include <windows.h>
#define M 300


int zamin(int arr[][M] ,int n,int kr1,int kc1,int kr2,int kc2){
int i=0,j=0;
int L1=kr2-kr1,L2=kc2-kc1;
for (i=0;i<L2;i++)
    printf("==");
    printf("=");
   // printf("=");
    printf("\n");
for (i=0;i<L1;i++)
{
    printf("|");
    for(j=0;j<L2;j++)
        if (arr[i+kr1][j+kc1]==0)
        printf(" |");
        else
        printf("*|");
        printf("\n");
}
for (i=0;i<L2;i++)
    printf("==");
    printf("=");
   // printf("=");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return 0;
}



void mokhtasat(int arr[][M],int n,int c, int r){
    int i=0,j=0;
    while(i<n && j<n){
        scanf("%d",&i);
        scanf("%d",&j);

        if((i<n && j<n))
            arr[j+c][i+r]=1;
    }
}
int checkh(int arr[][M],int i,int j){
    int a,b,u=0;
    for(a=-1;a<2;a++)
        for(b=-1;b<2;b++){
            if (b==0 && a==0 );
            else
                u+=arr[i+a][j+b];}

   return u;
}
void hazfoez(int arr[][M],int n,int *a1,int *a2 ,int *b1,int *b2){
    int brr[M][M];
    int i,j;
    for(i=0;i<M;i++)
        if(arr[*a1][i]==1)
        {
            (*a1)--;
            i=M;
        }
    for(i=0;i<M;i++)
        if(arr[*a2-1][i]==1)
        {
            (*a2)++;
            i=M;
        }
    for(i=0;i<M;i++)
        if(arr[i][*b1]==1)
        {
            (*b1)--;
            i=M;
        }
    for(i=0;i<M;i++)
        if(arr[i][*b2+1]==1)
        {
            (*b2)++;
            i=M;
        }

    for(i=*a1-1;i<*a2+1;i++){
            for(j=*b1-1;j<*b2+1;j++){
                if (arr[i][j]>0){
                    if (checkh(arr,i,j)==3 || checkh(arr,i,j)==2)
                         brr[i][j]=1;
                    else brr[i][j]=0;}
                else
                    if (checkh(arr,i,j)==3)
                         brr[i][j]=1;
                    else brr[i][j]=0;

            }

    }
    for(i=0;i<M;i++)
        for(j=0;j<M;j++)
            arr[i][j]=brr[i][j];

}



int main(){
    int n,t=0;
    int kr1,kr2,kc1,kc2;
    scanf("%d%d",&n,&t);
    int arr[M][M]={{0}};
    kr1=M/3;
    kr2=kr1+n;
    kc1=M/3;
    kc2=kc1+n;
    mokhtasat(arr,n,kc1,kr1);
    printf("\n\n\n\n\n\n\n\n");
    zamin(arr,n,kr1,kc1,kr2,kr2);
    int s=0;
    while(s<t && kc2-kc1<=2*n && kr2-kr1<=2*n){
    hazfoez(arr,n,&kr1,&kr2,&kc1,&kc2);
    zamin(arr,n,kr1,kc1,kr2,kr2);
    Sleep(1000);

    s++;}
    return 0;
         }
