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
long long a[1000005],b[1000005];
void solve(){
    a[1]=1;
    b[1]=1;
    for(int i=2;i<=1000000;i++){
        a[i]=((a[i-1]*2)%MOD+b[i-1]%MOD)%MOD;
        b[i]=((b[i-1]*4)%MOD+a[i-1]%MOD)%MOD;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    
    // freopen("helpcross.in", "r", stdin);
	// freopen("helpcross.out", "w", stdout);
 
 
    solve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(a[n]+b[n])%MOD<<endl;
    }
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
}
