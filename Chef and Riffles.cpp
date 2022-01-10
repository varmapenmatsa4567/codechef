#include <bits/stdc++.h>
using namespace std;

void display(int v[],int n)
{
    for(int i=0;i<n;i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}

bool equal(int v1[],int v2[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(v1[i]!=v2[i]) return false;
    }
    return true;
}

void solve()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int v1[n],v2[n],v3[n];
    int s = 0;
    int flag = 1;
    for(int i=1;i<=n;i++){
        v1[i-1] = i;
        v3[i-1] = i;
    }
    for(int i=0;i<n;i++)
    {
        int p=0;
        for(int j=0;j<n-1;j+=2){
            v2[p] = v1[j];
            p++;
        }
        for(int j=1;j<n;j+=2){
            v2[p] = v1[j];
            p++;
        }
        s++;
        for(int j=0;j<n;j++){
            v1[j] = v2[j]; 
        }
        if(i==k-1){
            flag=0;
            display(v1,n);
            break;
        }
        if(equal(v1,v3,n)){
            break;
        }
    }
    if(flag){
        k = k%s;
        for(int i=0;i<k;i++)
        {
            int p = 0;
            for(int j=0;j<n-1;j+=2){
                v2[p] = v1[j];
                p++;
            }
            for(int j=1;j<n;j+=2){
                v2[p] = v1[j];
                p++;
            }
            for(int j=0;j<n;j++){
                v1[j] = v2[j]; 
            }
        }
        display(v1,n);
    }
    
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
