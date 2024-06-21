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


void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1,vector<ll>(n+1,1e15));
    FOR(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=min(c,dist[a][b]);dist[b][a]=min(c,dist[a][b]);
    }

    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=0;i<=n;i++) dist[i][i]=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(dist[i][j]==1e15) dist[i][j]=-1;
        }
    }
    FOR(i,q){
        int a,b;
        cin>>a>>b;
        cout<<dist[a][b]<<endl;
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
