// Problem Link:- http://www.spoj.com/problems/AIBOHP/

// The palindrome problem in WCC-14.
// The maximaum length which is a palindome in a given string can be found via..
// reverse the string. Now find the lcs between original and reversed string.
#include<iostream>
#include<string.h>
int lcs(char a[],char b[]);
using namespace std;

int strreve(char str[]){
int i=0,l=strlen(str)-1;char temp;int q=l+1;
while(i<l){
    temp=str[i];
    str[i]=str[l];
    str[l]=temp;
    i++;l--;
    }
    str[q]='\0';
    return 0;
}
int main(){
int t;
cin >> t;
while(t--){
    char orig[100000],rev[100000];
    cin >> orig;
    // reverse te sstring.
    strcpy(rev,orig);
    strreve(rev);
    int cost=lcs(orig,rev);
    int diff=strlen(orig)-cost;
    cout<<diff<<endl;
    orig[0]='\0';
    rev[0]='\0';
    }
return 0;
}
int lcs(char orig[],char rev[]){
    int temp,i,j;
    int l=strlen(orig);
    if (l==0) return 0;
    else if (l==1) return 1;
    int val[2][l+1];
   // cout<<orig<<" "<<rev<<endl;
    for(i=0;i<=l;i++)
    {
        val[0][i]=0;
    }// Initialisation of the val array.
    val[1][0]=0;val[0][0]=0;
    for(i=1;i<=l;i++){
        for(j=1;j<=l;j++)
        {  // val[0][i]=0;
            if(orig[i-1]==rev[j-1]) {val[1][j]=val[0][j-1]+1;/*cout<<orig[i]<<i<<" "<<rev[j]<<j<<endl;*/}
            else val[1][j]=max(val[0][j],val[1][j-1]);
        }
        for(j=0;j<=l;j++){
            val[0][j]=val[1][j];
            //cout<< val[1][j]<<" ";
        }
        //cout<<endl;
    }
   // cout << "ans"<<val[1][l]<<endl;
    return val[1][l];
}
