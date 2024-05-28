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
int count(vi& v,int lo,int hi){
    if(lo==hi) return 0;
    else if(hi-lo==1){
        if(v[lo]>v[hi]) return 1;
        else return 0;
    }else{
        int mid=(hi+lo)/2;
        int ans1=count(v,lo,mid);
        int ans2=count(v,mid+1,hi);
        
        vector<int> v1(v.begin()+lo,v.begin()+mid+1),v2(v.begin()+mid+1,v.begin()+hi+1);
        sort(all(v1));sort(all(v2));
        int ans=ans1+ans2;
        
        int c1=0,c2=0;
        while(c1<v1.size()&&c2<v2.size()){
            if(v1[c1]>v2[c2]){
                ans+=v1.size()-c1;
                c2++;
            }else c1++;
        }
        
        return ans;
    }
}

int solve(){
    int n;
    cin>>n;
    vi v(n);
    get(v);
    cout<<count(v,0,n-1);
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 
    
    // freopen("paintbarn.in", "r", stdin);
	// freopen("paintbarn.out", "w", stdout);

    solve();

    // int t;
    // cin>>t;
    // while(t--){
    //     if(solve()){
    //         yes
    //     }else no
    // }
}
