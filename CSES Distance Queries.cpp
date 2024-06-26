#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define FOR(i,b) for(int i=0;i<b;i++)
#define FORwi(i,a,b) for(int i=a;i<b;i++)
#define get(v) FOR(i,(int)v.size()) cin>>v[i];
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define see(v) FOR(i,sz(v)) cout<<v[i]<<" "; cout<<endl;
#define gt(v) for(auto it=v.begin();it!=v.end();it++)
#define sz(v) v.size()
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define mpii map<int,int> 
#define mpll map<ll,ll> 
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pll pair<ll,ll>
typedef long long int ll;
typedef unsigned long long ull;
const int MOD=1000000007;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
 
int prime(long long int a){
    if(a==1) return 0;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return 0;
    }
    return 1;
}
 
string base_rep(ll n, ll b){  //for representation in any base
    if(n==0) return "0";
    string res="";
    while(n>0){
        res+=char('0'+n%b);
        n=n/b;
    }
    reverse(all(res));
    return res;
}
struct trip{
    int a;
    int b;
    ll w;
};
vector<int> child[250000];
vector<int> dist(250000,0);
vector<vector<int>> up(250000,vector<int>(18,0));
vector<int> adj[250000];
vector<bool> visited(250000,0);
const int l=18;

void dfs(int u){
    visited[u]=1;
    for(auto& v:adj[u]){
        if(!visited[v]){
            visited[v]=1;
            up[v][0]=u;
            for(int j=1;j<l;j++){
                up[v][j]=up[up[v][j-1]][j-1];
            }
            dist[v]=dist[u]+1;
            dfs(v);
        }
    }
}

int get_lca(int& a,int& b){
    if(dist[a]<dist[b]) swap(a,b);
    
    int k=dist[a]-dist[b];
    for(int j=l-1;j>=0;j--){
        if((1<<j)&k) a=up[a][j];
    }
    if(a==b) return a;
    for(int j=l-1;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }
    return up[a][0];
}

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);

    FOR(i,q){
        int u,v;
        cin>>u>>v;
        cout<<dist[u]+dist[v]-2*dist[get_lca(u,v)]<<endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    
    // freopen("helpcross.in", "r", stdin);
	// freopen("helpcross.out", "w", stdout);
        
    solve();
    
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
}
