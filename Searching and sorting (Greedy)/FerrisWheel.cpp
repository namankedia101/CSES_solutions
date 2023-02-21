#include <bits/stdc++.h>
 
using namespace std;
 
#define endl "\n"
#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define vs vector<string>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define mll map<ll, ll>
 
//Graphs
class Graph{
 
    vvi v;
    ll sz;
 
    public:
 
    Graph(){
 
    }
 
    Graph(ll n){
        sz=n+1;
        v.resize(n+1);
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
        vector<bool>visited(sz+1,0);        
        queue<ll>q;
        q.push(x);
        visited[x]=1;
        while (!q.empty())
        {
            ll k=q.front();
            q.pop();
            
            for(auto p:v[k]){
                if(!visited[p]){
                    visited[p]=1;
                    q.push(p);
                }
            }
        }        
    }   
 
    void dfs(ll x,vi &visited){
        visited[x]=1;        
        
        for(auto y:v[x]){
            if(!visited[y]){
               dfs(y,visited);
            }
        }
        return ;        
    }
 
};
 
                                ////STRINGS\\\\
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
 
// Function for nth permutation
 
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
 
 
                            ////NUMBER THEORY\\\\
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
 
//count number of digits
ll countDigit(ll n) {return 1LL*floor(log10(n) + 1);}
 
//BITWISE AND OF A RANGE
ll rangeBitwiseAND(ll a,ll b){
    ll x=0;
 
    while(a!=b){
        a=a>>1;
        b=b>>1;
        x++;
    }
    return a<<x;
}
 
//MOD FUNCS
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mult(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
 
// find gcd of 2 numbers
ll gcd(ll a, ll b){if (a == 0)return b;return gcd(b % a, a);}
 
// Function to find gcd of array of numbers
ll gcdArr(vi arr, ll n){ll result = arr[0];for (int i = 0; i < n; i++)result = gcd(arr[i], result);return result;}
 
// find lcm of 2 numbers
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
 
//calc power a^b, BINARY EXPONENTIATION
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
 
//MODULAR EXPONENTIATION
ll modexp(ll a,ll b,ll M){
    ll res = 1;
    a%=M;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%M;
        a = (a * a)%M;
        b >>= 1;
    }
    return res;
}
 
//Modular Multiplicative Inverse (using FERMAT'S LITTLE THEOREM (WHEN MOD IS A PRIME))
ll inv1(ll a,ll M){ll res=modexp(a,M-2,M);return res;}
 
//findDistance between 2 points
long double findDistance(ll x1,ll y1,ll x2,ll y2){
    long double a,b,ans;
    a=binpow(abs(x2-x1),2);
    b=binpow(abs(y2-y1),2);
 
    ans=sqrtl(a+b);
 
    return ans;
}
 
//FUN WITH PRIMES
 
// SIEVE of ERASTOTHENIS
vi sieve(){
    ll n=100058;
    vi prime(n+1,1);
    prime[0]=0;
    prime[1]=0;
 
    for(ll i=2;i*i<=n;i++){
        if(prime[i]){
            for(ll j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
 
    return prime;
}
 
// PRIME FACTORIZATION AND STORING THERE COUNT
ll primeFactors(ll n)
{   //ll y=n;
    //vi primes(1e5+1,0);
    ll cnt=0;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){            
            if(i==2 || i==3 || i==5){
 
            }else{
                cnt=-1;break;
            }
            ll c=0;            
            while(n%i==0){
                n/=i;c++;
                cnt++;
            }
            //primes[i]=c;
        }
    }
 
    if(n>1 && (n==2 || n==3 || n==5)){//primes[n]=1;
    cnt++;}
    else if(n>1) cnt=-1;
 
        // for(ll i=2;i<=1e5;i++){
        //     if(primes[i])cout<<i<<"^"<<primes[i]<<" ";
        // }
        return cnt;
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
 
//NUMBER OF DIVISROS
void countDivisors(ll n, vi &v,ll m)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i){                
                cnt++;
            }    
            else {
                 cnt = cnt + 2;
            }
               
        }
    }
    return;
}
 
//Function to return the XOR of all subarrays
ll subarrayXor(vi &arr, ll n, ll m)
{
      //declaring the hashtable
      //and initializing it with a count of 1
      //for 0
    unordered_map<ll,ll> HashTable;
    HashTable[0] = 1;
    ll count = 0, curSum = 0;
    for (ll i = 0; i < n; i++)
    {
        curSum ^= arr[i];
        if (HashTable[curSum ^ m] > 0)
            count += HashTable[curSum ^ m];
        HashTable[curSum]++;
    }
    return count;
}
 
bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;
 
    return (ceill((long double)log2(n)) == floorl((long double)log2(n)));    
}
 
//FACTORIAL
ll modFact(ll n, ll p)
{
    if (n >= p)
        return 0;
 
    ll result = 1;
    for (ll i = 1; i <= n; i++)
        result = (result * i) % p;
 
    return result;
}
                                            //OPERATIONS ON MATRICES\\
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
 
void rotate90Clockwise(ll a[][2])
{
 
    // Traverse each cycle
    ll N=2;
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
 
void printBoundary(int a[][50], int m, int n)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1
                || j == n - 1)
                cout << a[i][j] << " ";
            else
                cout << " "
                     << " ";
        }
        cout << "\n";
    }
}
 
vvi generateMatrix(ll n) {
        ll r1 = 0, r2 = n-1;
        ll c1 = 0, c2 = n-1;
        ll val = 0;
		
        vvi v(n, vi (n));
        while(r1 <= r2 && c1 <= c2)
        {
            // left to right (row will be fixed)
            for(ll i = c1; i <= c2; ++i)
                v[r1][i] = ++val;
				
				// move down(col will be fixed)
            for(ll i = r1+1; i <= r2; ++i)
                v[i][c2] = ++val;
				
            if(r1 < r2 && c1 < c2)
            {
                // move right to left (row will be fixed)
                for(ll i = c2-1; i>c1; --i)
                    v[r2][i] = ++val;
					
					// move up (col will be fixed)
					for(ll i = r2; i>r1; --i) 
                    v[i][c1] = ++val;
            }
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        return v;
    }
 
vvi printSnake(ll N)
{
    ll M=N,x=1,y=N*N;
    bool f=1;
 
    vvi ans(N,vi(N));
    // Traverse through all rows
    for (int i = 0; i < M; i++) {
 
        // If current row is even, print from
        // left to right
        if (i % 2 == 0) {
            for (int j = 0; j < N; j++){
                if(f){
                    ans[i][j]=x;
                    x++;f=0;
                }else{
                    ans[i][j]=y;
                    y--;f=1;
                }
            }
    
            // If current row is odd, print from
            // right to left
        }
        else {
            for (int j = N - 1; j >= 0; j--){
                if(!f){
                    ans[i][j]=y;y--;
                    f=1;
                }else{
                    ans[i][j]=x;
                    x++;      
                    f=0;              
                }
            }
        }
    }
    return ans;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
 
void vc(ll n,vi &v){
    v.resize(n,0);
    for(ll i=0;i<n;i++)cin>>v[i];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
 
    // ll t;
    // cin>>t;    
 
    // while(t--){
        ll n,m,i=0,j=0,k=1,l=-1,r=0,mid,ans=0,c0=0,c1=0,x=1,y=0,z,MOD=1e9 + 7,a=LONG_LONG_MAX,b=LONG_LONG_MIN,c=0,d=LONG_LONG_MIN,e,f=0;        
        cin>>n>>x; 
 
        vi v1;
        vc(n,v1);
 
        sort(v1.begin(),v1.end());
        reverse(v1.begin(),v1.end());
 
        i=0,j=n-1;
 
        while(i<j){
            d=x-v1[i];
            if(v1[j]<=d){
                ans++;j--;i++;
            }else{
                ans++;i++;
            }
        }
        if(i==j)ans++;
        cout<<ans;
        cout<<endl;
 
    //}        
return 0;
}
