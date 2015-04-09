//Solution to problem: http://www.spoj.com/problems/MTOTALF/en/

// some ground rules that always initialise an array created. learn the use of memset;
#include<queue>
#include<iostream>
#include<limits.h>
using namespace std;
int n,path_flow;
int graph[100][100],rgraph[100][100];
bool bfs(int src,int snk,int parent[]){
    int visited[100],i,u,v;
    for(i=0;i<52;i++) visited[i]=false;
    queue <int> q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;
    while(!q.empty()){
            u=q.front();
            q.pop();
            for(v=0;v<52;v++){
                if(rgraph[u][v]>0 && visited[v]==false){
                    q.push(v);
                    visited[v]=true;
                    parent[v]=u;
             //       cout <<"u v "<<u<<v<<endl;
                }
            }
    }
    return visited[snk];
}

int ffm(int graph[100][100],int src,int snk){
queue<int> q;
int v,temp=0,last,par;
int parent[56];
while(bfs(src,snk,parent)){
       // cout << "p\n";
      //  cin >> temp;
        int min_flow=INT_MAX;
        last=snk;
        while(last!=src){
        par=parent[last];
        min_flow=min(min_flow,rgraph[par][last]);
        last=parent[last];
        }
        last=snk;
        while(last!=src){
        par=parent[last];
        rgraph[par][last]-=min_flow;
        rgraph[last][par]+=min_flow;
        last=parent[last];
        }
        path_flow+=min_flow;
}
cout << path_flow << endl;
return path_flow;
}

int main(){
    int u,v,k,cap,src,snk;
    char x,y;
    cin >> n;
    k=n;
    while(k--){
    cin >> x >> y >> cap;
    if(x <93 ) u=x-65; else u=x-71;
    if (y <93) v=y-65; else v=y-71;
    
    rgraph[v][u]+=cap;
    rgraph[u][v]+=cap;
  //  cout << u <<v<<graph[u][v]<<endl;
    }
    //cout << "Input Complete\n";
    ffm(graph,0,25);
}
