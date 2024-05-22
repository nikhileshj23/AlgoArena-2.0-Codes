#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define FOR(i,b) for(ll i=0;i<b;i++)
#define FORwi(i,a,b) for(int i=a;i<b;i++)
#define get(v) FOR(i,v.size()) cin>>v[i];
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
#define pll pair<ll,ll>
typedef long long int ll;
typedef unsigned long long ull;
 
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
  
vector<string> solve(int n){
    if(n==1){
        return {"0","1"};
    }else{
        vector<string> v=solve(n-1);
        vector<string> v2;
        for(int i=0;i<int(sz(v));i++) v2.pb('0'+v[i]);
        for(int i=0;i<int(sz(v));i++) v2.pb('1'+v[sz(v)-i-1]);
        return v2; 
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    int n;
    cin>>n;
    vector<string> s=solve(n);
    for(string x:s) cout<<x<<endl;
    
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // } 
   
 
}
