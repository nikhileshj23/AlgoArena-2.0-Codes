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
// const int N=1e9+7;
// ll power(ll a,ll b){
//     ll res=1;
//     while(b>0){
//         if(b%2==1) res=(res*(a%N))%N;
//         a=(a*a)%N;
//         b>>=1;
//     }
//     return res;
// }

int N=1e5;
vector<bool> pr(N+10,true);
vector<int> primes;
bool pp(ll n,ll i){
    while(n%i==0) n/=i;
    return n==1;
}
string s;
int char_count[26];
vector<string> prems;
void search(const string& curr=""){
    if(curr.size()==s.size()){
        prems.pb(curr);
        return;
    }
    for(int i=0;i<26;i++){
        if(char_count[i]){
            char_count[i]--;
            search(curr+(char)('a'+i));
            char_count[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL); 

    cin>>s;
    for(char c:s) char_count[c-'a']++;

    search();
    cout<<prems.size()<<endl;
    for(const string& st:prems) cout<<st<<endl;
    
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // } 
   

}
