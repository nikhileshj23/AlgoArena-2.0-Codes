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
const int N=150000;
vector<bool> visited(N+9,0);
vector<int> adj[N+9];
vector<int> parent(N+9,-1);
int cycle_start,cycle_end;

bool dfs(int u,int s){
    visited[u]=true;
    for(int t:adj[u]){
        if(t==s) continue;
        if(visited[t]){
            cycle_start=t;
            cycle_end=u;
            return true;
        }
        parent[t]=u;
        if(dfs(t,u)) return true;
    } 
    return false;
}

void solve(){
    int n,m;
    cin>>n>>m;
    FOR(i,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cycle_start=-1;
    for(int i=1;i<=n;i++){
        if(!visited[i]&&dfs(i,parent[i])) break;
    }
    if(cycle_start==-1) cout<<"IMPOSSIBLE"<<endl;
    else{
        vi cycle;
        cycle.pb(cycle_start);
        for(int v=cycle_end;v!=cycle_start;v=parent[v]){
            cycle.pb(v);
        }
        cycle.pb(cycle_start);
        
        cout<<cycle.size()<<endl;
        see(cycle);
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
