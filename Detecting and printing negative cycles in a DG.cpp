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
struct trip{
    int a;
    int b;
    ll w;
};
 
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> dist(n+1,0);
    dist[1]=0;
    vector<trip> edge;
    FOR(i,m){
        int a,b;ll w;
        cin>>a>>b>>w;
        edge.pb({a,b,w});
    }
    for(int i=0;i<n;i++){
        for(auto e:edge){
            int a,b;ll w;
            a=e.a;b=e.b;w=e.w;
            if(dist[a]!=LLONG_MAX){
                dist[b]=min(dist[b],dist[a]+w);                
            }
        }
    }
    bool f=true;
    vector<ll> par(n+1,-1);
    for(int i=0;i<n;i++){
        for(auto e:edge){
            int a,b;ll w;
            a=e.a;b=e.b;w=e.w;
            ll z=dist[b];
            dist[b]=min(dist[b],dist[a]+w);
            if(z!=dist[b]){
                f=false;
                par[b]=a;
            }
        }
    }
    if(f) no
    else{
        int x=0;
        for(int i=1;i<=n;i++){
            if(par[i]!=-1){
                x=i;
                break;
            }
        }
        vector<ll> cycle;
        unordered_set<int> st;
        while(st.find(x)==st.end()){
            cycle.push_back(x);
            st.insert(x);
            x=par[x];
        }
        cycle.pb(x);
        reverse(all(cycle));
        yes
        unordered_set<ll> final;
        for(auto i:cycle){
            cout<<i<<" ";
            if(final.find(i)!=final.end()) break;
            final.insert(i);
        }
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
