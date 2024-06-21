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
vector<pii> adj[N+9];
vector<int> parent(N+9,-1);
vector<ll> dist(N+9,INT64_MAX);

void solve(){
    int n,m;
    cin>>n>>m;
    FOR(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    dist[1]=0;
    priority_queue<pair<ll,int>> q;
    q.push({0,1});
    while(!q.empty()){
        int a=q.top().ss;q.pop();
        if(visited[a]) continue;
        visited[a]=true;
        for(auto u:adj[a]){
            int b=u.ff,w=u.ss;
            if(dist[a]+w<dist[b]){
                dist[b]=dist[a]+w;
                q.push({-dist[b],b});
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";

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
