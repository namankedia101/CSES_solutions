#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define mll map<ll, ll>
#define pdd pair<double, double>
 
//Graphs
 
class Graph{
 
    vvi v;
 
    public:
 
    Graph(ll n){
        v.resize(n);
    }
 
    void addElt(ll x,ll y, bool isDirected){
        if(isDirected){
            v[x].push_back(y);
        }else {
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
 
    void bfs(ll x){
        vector<bool>visited(v.size(),0);
        queue<ll>q;
        q.push(x);
        visited[x]=1;
        while (!q.empty())
        {
            ll k=q.front();
            cout<<k<<" ";
            for(auto p:v[k]){
                if(!visited[p]){
                    q.push(p);
                    visited[p]=1;
                }
            }
        }        
    }
 
    void dfs(ll x,vi visited){
 
    }
 
};
 
//is pallindrome
bool isPalindrome(string S)
{
    string P = S;
 
    reverse(P.begin(), P.end());
 
    if (S == P) {
        return true;
    }
        return false;
    
}
 
//count number of digits
int countDigit(long long n) {
  return floor(log10(n) + 1);
}
 
 
// find gcd of 2 numbers
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
 
    return gcd(b % a, a);
}
 
// Function to find gcd of array of
// numbers
ll findGCD(vi arr, ll n)
{
    ll result = arr[1];
    for (int i = 1; i <= n; i++)
        result = gcd(arr[i], result);
  
    return result;
}
 
// find lcm of 2 numbers
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
 
//calc power a^b
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
bool cmp(const pll&a,const pll &b){
    if(a.first==b.first)
    return a.second>b.second;
 
    return a.first<b.first;
}
 
ll factmod(ll n, ll p) {
    ll res=1;
 
    for(ll i=1;i<=n;i++){
        res=(res*i)%p;
    }
 
    return res%p;
}
 
//FUN WITH PRIMES
bool sieve(ll x){
    ll n=1e6;
    bool prime[n];
    memset(prime, true, sizeof(prime));
    prime[1]=0;
    prime[0]=0;
    for (int p = 2; p * p <= 1e6; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    return prime[x];
}
 
void primeFactors(ll n)
{   ll y=n;
    vi primes(1e5+1,0);
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        n = n/2;
        primes[2]++;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            n = n/i;
            primes[i]++;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    // if (n > 2){
    //     primes[n]++;
    // }
    n=y;
    ll a=LONG_LONG_MIN,b=1;
    for(ll i=2;i<=1e5;i++){
            if(primes[i]>a){
                a=primes[i];b=i;
            }
        }
 
        while(n>1 && n%b==0 && a!=0){
            n=n/b;
        }
 
        if(n==1){
            cout<<a<<endl;
            while(a--)cout<<b<<" ";
        }else{
            if(a==0){cout<<1<<endl<<n;}
            else{
                cout<<a<<endl;
                n=n*b;
                a--;
                while(a--)cout<<b<<" ";
                cout<<n;
            }
        }
        cout<<endl;
        return;
}
 
long long maxPrimeFactors(long long n)
{
    // Initialize the maximum prime factor
    // variable with the lowest one
    long long maxPrime = -1;
 
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        maxPrime = 2;
        n >>= 1; // equivalent to n /= 2
    }
  // n must be odd at this point
     while (n % 3 == 0) {
        maxPrime = 3;
        n=n/3;
    }
 
    // now we have to iterate only for integers
    // who does not have prime factor 2 and 3
    for (int i = 5; i <= sqrt(n); i += 6) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
      while (n % (i+2) == 0) {
            maxPrime = i+2;
            n = n / (i+2);
        }
    }
 
    // This condition is to handle the case
    // when n is a prime number greater than 4
    if (n > 4)
        maxPrime = n;
 
    return maxPrime;
}
 
ll smallestDivisor(ll n)
{
    // if divisible by 2
    if (n % 2 == 0)
        return 2;
 
    // iterate from 3 to sqrt(n)
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
 
    return n;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
           
    ll t,ans=0;
    cin>>t;
 
    vi v(t);
    for(ll i=0;i<t;i++)cin>>v[i];
 
    for(ll i=1;i<t;i++){
        if(v[i]-v[i-1]<0){
            ans+=abs(v[i]-v[i-1]);
            v[i]=v[i-1];
        }
    }
 
    cout<<ans;
    return 0;
};
