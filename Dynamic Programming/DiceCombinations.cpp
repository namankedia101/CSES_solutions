//MEMOIZATION

ll solve(ll n, vi &dp,ll M){    
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=0;
    for(ll i=1;i<=6;i++){
        dp[n]=mod_add(dp[n],solve(n-i,dp,M),M);
    }
 
    return dp[n];
}

//TABULATION

vi dp(n+1,0);
 
dp[0]=1;        

for(i=1;i<=n;i++){
    for(j=1;j<=6;j++){
        if(i-j>=0){
            dp[i]=(dp[i]%MOD + dp[i-j]%MOD)%MOD;
        }
    }
}

//TABULATION + SPACE OPTIMIZATION

cin>>n;
vi prev(6,0),curr(6,0);
prev[5]=1;

for(i=1;i<=n;i++){
    for(j=1;j<6;j++){
        curr[j-1]=prev[j];
    }
    curr[5]=0;
    for(j=0;j<6;j++){
        curr[5]=mod_add(prev[j],curr[5],MOD);
    }
    prev=curr;
}

cout<<curr[5]<<endl;
    
