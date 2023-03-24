//APPROACH- (RECURSIVE)


//////////////////////////////////////////////////////// APPROACH - TC =(x.n^2) , SC= (x.n) ////////////////////////////////////////////////////////
vi v(n);
vc(n,v);

vvi dp(x+1,vi(n,0));

for(i=0;i<n;i++){
    dp[0][i]=1;
    if(v[i]<=x){
        dp[v[i]][i]=1;
    }
}

for(i=1;i<=x;i++){
    for(k=0;k<n;k++){
        if(!dp[i][k])continue;
        for(j=k;j<n;j++){
            if(i+v[j]<=x){
                dp[i+v[j]][j]=mod_add(dp[i][k],dp[i+v[j]][j],MOD);
            }
        }
    }
}

for(i=0;i<n;i++)ans+=dp[x][i];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////APPROACH - TC =(x.n) , SC= (x.n), when sum is in outer loop//////////////////////////////////////////////////////////
vi v(n);
vc(n,v);

vvi dp(x+1,vi(n,0));

sort(ALL(v));

for(i=0;i<n;i++){
    dp[0][i]=1;
}

for(i=1;i<=x;i++){
    for(j=0;j<n;j++){
        if(j-1>=0){
            dp[i][j]=mod_add(dp[i][j],dp[i][j-1],MOD);
        }
        if(i-v[j]>=0){
            dp[i][j]=mod_add(dp[i][j],dp[i-v[j]][j],MOD);
        }
    }
}
ans=dp[x][n-1];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////APPROACH - TC =(x.n) , SC= (x.n), when coin is in outer loop//////////////////////////////////////
vi v(n);
vc(n,v);

vvi dp(n,vi(x+1,0));

sort(ALL(v));

for(i=0;i<n;i++){
    dp[i][0]=1;
}

for(j=0;j<n;j++){
    for(i=1;i<=x;i++){
        if(i-v[j]>=0){
            dp[j][i]=mod_add(dp[j][i],dp[j][i-v[j]],MOD);
        }
        if(j-1>=0){
            dp[j][i]=mod_add(dp[j][i],dp[j-1][i],MOD);
        }
    }
}
ans=dp[n-1][x];
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////// APPROACH - TC =(x.n) , SC= (x) ////////////////////////////////////////////////////////
vi v,dp(x+1,0);
vc(n,v);

dp[0]=1;
for(i=0;i<n;i++){
  for(j=1;j<=x;j++){
      if(j-v[i]>=0){
          dp[j]=mod_add(dp[j],dp[j-v[i]],MOD);
      }
  }
}
cout<<dp[x];
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
