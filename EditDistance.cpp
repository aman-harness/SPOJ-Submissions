// Problem Link: http://www.spoj.com/problems/EDIST/
// Edit distance problem of WCC 14 SPOJ

// DYNAMIC PROGRAMMING SOLUTIONS

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int minn(int x,int y) {if(x<y) return x; else return y;}
int dist[2005][2005];
int distt(char input[],char orig[]){
    int x= strlen(input),temp;
    int y= strlen(orig);
    for(int i=0;i<=x;i++) dist[i][0]=i;
    for(int i=0;i<=y;i++) dist[0][i]=i;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++){
            if(input[i-1]==orig[j-1]) temp=0;
                else temp=1;
            dist[i][j]=minn(minn(dist[i-1][j],dist[i][j-1])+1,dist[i-1][j-1]+temp);
    }
    return dist[x][y];
}
int main(){
int a,b,c,i,j,m,n,p,t;
cin >>t;
char input[2005],orig[2005];
while(t--){
cin >>input >> orig;
cout << distt(input,orig) << endl;
}
return 0;
}
