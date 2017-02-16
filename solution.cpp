#include<bits/stdc++.h>

#define loop(i,n) for(int i=0;i<n;i++) 
#define loop1(i,n) for(int i=1;i<=n;i++) 
#define loops(i,m,n) for(int i=m;i<=n;i++)
#define mloop(it,m) for(map<int,int> ::iterator it=m.begin();it!=m.end();++it)
#define ll long long int
#define ini(n,v) memset(n,v,sizeof(n))
#define F first 
#define S second 
#define mp make_pair
#define pb push_back
#define pid pair<int,double>
#define pii pair<int,int> 
#define p_q priority_queue
#define MOD 1000000007
using namespace std;
void multiply(ll ans[2][2],ll mat[2][2])
{
	ll temp1=((ans[0][0]*mat[0][0])%MOD+(ans[0][1]*mat[1][0])%MOD)%MOD;
 	ll temp2=((ans[0][0]*mat[0][1])%MOD+(ans[0][1]*mat[1][1])%MOD)%MOD;
  	ll temp3=((ans[1][0]*mat[0][0])%MOD+(ans[1][1]*mat[1][0])%MOD)%MOD;
  	ll temp4=((ans[1][0]*mat[0][1])%MOD+(ans[1][1]*mat[1][1])%MOD)%MOD;
 	ans[0][0]=temp1;
  	ans[0][1]=temp2;
  	ans[1][0]=temp3;
  	ans[1][1]=temp4;
}
void power(ll ans[2][2], ll n)
{
    if(n == 0 || n == 1)
        return;
    ll mat[2][2] = {{1,1},{1,0}};
   	power(ans, n/2);
    multiply(ans, ans);
 	if (n%2 != 0)
       multiply(ans, mat);
}
ll solve(ll n)
{
	ll ans[2][2] = {{1,1},{1,0}};
  	if (n == 0)
    	return 0;
  	power(ans, n-2);
  	return (ans[0][0]*3+ans[0][1]*2)%MOD;
}
int main()
{
	freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		ll num;
		cin>>num;
		cout<<solve(num)<<"\n";
	}
	return 0;
}	