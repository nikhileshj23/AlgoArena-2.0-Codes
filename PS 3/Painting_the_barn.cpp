#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define FOR(i,b) for(int i=0;i<b;i++)
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
int mat[1002][1002];
int res[1000][1000];
void solve(){
    int n,k;
    cin>>n>>k;
    FOR(i,n){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<x2;i++){
            mat[i][y1]++;
        }
        for(int i=x1;i<x2;i++){
            mat[i][y2]--;
        }
    }
    
    FOR(i,1001){
        int sum=0;
        FOR(j,1001){
            sum+=mat[i][j];
            res[i][j]=sum;
        }
    }

    int ans=0;
    FOR(i,1000){
        FOR(j,1000){
            if(res[i][j]==k) ans++;
        }
    }
    cout<<ans<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    
    freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
    
    solve();

    // int t;
    // cin>>t;
    // while(t--)  solve();
}
