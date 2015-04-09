Problem Link:- http://www.codechef.com/FEB15/problems/CHEFGRPH

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Point pair<long long int,long long int>
#define mod 1000000007

pair <Point, Point> edge[500000];
long long int m,n,k,f;
long long int cover[500000];// whether we have calculated for that column or not
map <long long int , long long int> visited;
map <Point, long long int> p_val;
bool comp (const pair <Point, Point>& i,const pair <Point, Point>& j) {
     return (i.second.first < j.second.first); }
long long int poww(long long int a, long long int b){
    long long int temp;
    if(b == 1) return a;
    else if (b<= 0) return 1;
    if(b%2 == 0) temp = (poww(a,b/2)%mod)*(poww(a,b/2)%mod);
    else {
        temp = (poww(a,b/2)%mod)*(poww(a,b/2)%mod);
        temp%=mod;
        temp *= a;
    }
    return temp%mod;
}
// this line needs to be improved
long long int modd(long long int diff){
    long long int x = diff,temp=1;
    //while(x--) temp = (temp*(diff%mod))%mod;
    temp=poww(m,diff);
    //cout << "Modd loop completed"<< temp<< " "<< diff<<endl;
    return temp;
    }

long long int findd(long long int value) {
    long long int *up = upper_bound(cover, cover+f+1, value),p;
        //cout << "Findd returns for " <<*(up - 1) << " "<< value;
        return *(up - 1);
  }

long long int jump(long long int from, long long int to){
	// assuming n+2  columns are there.
	long long int diff = to-from,x;
	//cout << "to :" << to << "from :"<< from << endl;
	if (to != n-1) {x=(visited[from] * modd(diff))%mod;}
	else {x=(visited[from] * modd(diff-1))%mod;}
	//cout << "vis(from)= "<<visited[from]<<" " <<"from "<< from<<" jump value :"<< x << endl;
	return x;
}

long long int acf(pair <Point, Point> edg){
    //cout << "\nIn acf :\n";
	long long int ways = findd(edg.first.first -1), temp;
	// marker has to be the last column from where edge originates.
	// check if any edge ends on the starting from our edge..???
	temp = 0;
	//cout << "Findd : " << ways  <<" Edge.ftft : "<<edg.first.first<< endl;
	// little bit amibguous....
	if(edg.first.first != 0)
        temp = jump(ways, edg.first.first -1);
	else temp =1;
	temp += p_val[edg.first];
	p_val[edg.second] += temp%mod;
	//cout << "acf :" << temp <<endl;
	//cout << "\nout acf :\n";
	return temp;
}


int main(){
	// variable defining
	long long int a,i,j,l,o,p,t,last,diff,temp;
	cin >> n >> m >> k;
	//m = 2,n=6;k=2;
	n +=2;
	i = 0;
	for(i=0;i<k;i++){
		cin >> edge[i].first.first >> edge[i].first.second >> edge[i].second.first >> edge[i].second.second;
	}
	//cout << "Input complete\n";
	last = 0;
	visited[0] = 1;
	sort(edge, edge + k, comp);
	//for(i=0;i<k;i++){
		//cout << edge[i].first.first << " "<< edge[i].first.second << " "<< edge[i].second.first << " "<< edge[i].second.second;
		//cout <<endl;
	//}
	cover[0] = 0;
	for(i=0;i<k;i++){
        f = i;
		// Normal jumping method calculated from last known value.
		temp = 0;
		if(visited[edge[i].second.first] == 0) // onlu=y if that is not previosly visited
			{temp = jump(last, edge[i].second.first);
        //cout << "Jump && i" << temp << " "<< i << endl;
        }

		// Now arc adding
		temp += acf(edge[i]);
		temp %= mod;
		//cout << "Count agter acf " << temp << endl;
		last = edge[i].second.first;
        //cout << "Visited[5] 1 " << visited[5] <<" "<< edge[i].second.first<< endl;
		visited[edge[i].second.first] += temp;
		visited[edge[i].second.first] %= mod;
		cover[i+1] = edge[i].second.first;
		//cout << "Visited[5] 2 :" << visited[5]<< endl;
	}
//for(i=0;i<k+1;i++) cout << "Please\n" <<cover[i];
if(visited[n-1] == 0) visited[n-1] = jump(edge[k-1].second.first, n-1);
cout << visited[n-1]%mod;
return 0;
}