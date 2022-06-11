// 19BCP002 Aditya Gandhi AI_Lab5

#include<iostream>
#include<sstream>
#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
#include<iterator>
#include<string>
#include<algorithm>
#include <array>
#include<math.h>

using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl cout<<"\n";
#define int long long
#define lld long double
#define f(i,a,n) for(int i=a;i<n;i++)
#define rf(i,a,n) for(int i=n-1;i>=a;i--)
#define read(arr,n) for(int i=0;i<n;i++)cin>>arr[i];
#define read1(vec,n)
#define in cin>>
#define out cout<<
#define fr first
#define sc second
#define VC vector<int>
#define pi pair<int, int>
#define VP vector<pair<int,int>>
#define SC set<int>
#define MS multiset<int>
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007
#define all(x) (x).begin(), (x).end()
#define sortall(x)  sort(all(x))


int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int lcm(int a, int b)
{
    return (a*b)/(gcd(a,b));
}

int mpow(int base, int exponent){
    if(exponent==0)
        return 1;
    else if(exponent%2==0)
    {
        int y = mpow(base, exponent/2);
        return (y*y)%MOD;
    }
    else{
        return((base%MOD)*(mpow(base, exponent-1)%MOD))%MOD;
    }
}


//ascii 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
//convert char/string numbers to real numbers -> (number value in ASCII) - 48
//longest positive integer in int form - INT_MAX, in long long int form - LLONG_MAX
//longest negative integer in int form - INT_MIN, in long long int form - LLONG_MIN

int n,j;
bool prime[100001];
int primes[100001];

void seiveoferatosthences(int n)
{
    memset(prime,true,sizeof(prime));
    for(int p=2; p*p<=n; p++)
    {
        if(prime[p]==true)
        {
            for(int i=p*p; i<=n; i+=p)
            {
                prime[i]=false;
            }
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(prime[i])
        {
            primes[j] = i;
            j++;
        }
    }
}

void bfs_jug(int j1, int j2, int t)
{
    if(t> j1+j2)
    {
        out "Never possible";
        nl
        return;
    }

    map<pi, int> m;
    queue<pi> q;
    vector<pi> path;
    q.push({0, 0} );
    bool ans = false;

    while( !q.empty() )
    {
        pi f = q.front();
        // out f.first<<" "<<f.second
        q.pop();

        if( m[{f.first, f.second} ]== 1)
            continue;

        if ( (f.first>j1) || (f.first<0))
            continue;

        if ((f.second>j2) || (f.second<0))
            continue;

        m[ {f.first, f.second} ]=1;
        path.pb({f.first, f.second});

        if(f.first==t || f.second==t  )
        {
            ans= true;
            if (f.first==t)
            {
                if (f.second!=0)
                    path.push_back( { f.first, 0} );
            }
            else
            {
                if (f.first != 0)
                    path.push_back( {0, f.second} );
            }

            f(i,0,path.size())
            {
                out path[i].first<<" "<<path[i].second;
                nl
            }
            break;
        }
        q.push( {j1, f.second} );
        q.push( {f.first, j2} );

        f(j,0,max(j1, j2))
        {
            // 2 contents to 1
            int c=f.first+j;
            int d=f.second-j;
            if (c==j1 || (d==0 && d>=0) )
                q.push({c, d});

            //1st jug contents to 2
            c=f.first-j;
            d=f.second+j;

            if ( (c ==0 && c>= 0) || d==j2)
                q.push( {c, d} );
        }

        // Empty both one by   one
        q.push({ j1, 0} );
        q.push({ 0, j2});

    }
    if(ans ==false)
        out "Not possible"<<endl;
    return;
}

void solve()
{
    int j1, j2, t;
    out "Enter both jug capacities: ";
    in j1>>j2;
    out "Enter the amount of water required: ";
    in t;
    bfs_jug(j1, j2, t);
}

int32_t main()
{

    int t;
    t = 1;
    //in t;
    while(t--)
    {
        solve();
    }
    return 0;
}
