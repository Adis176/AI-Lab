// BFS & DFS

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


stack<int> a1;
set<int> p;
vector<int> ans;


void dfs(map<int, VC> m, int s, int d, bool& pos2)
{
    a1.push(s);
    ans.pb(s);
    p.insert(s);
    if(s==d)
    {
        pos2 = true;
        while( !a1.empty() )
        {
            a1.pop();
        }
        out "DFS: ";
        for(int i=0;i<ans.size()-1;i++)
        {
            out ans[i]<<" ";
        }
        out ans[ans.size()-1]<<endl;
        return;
    }

    while( !a1.empty() )
    {
        if(pos2 == false)
        {
            int k = a1.top();
            for(auto &x : m[k])
            {
                if(p.find(x)==p.end())
                {
                    dfs(m, x, d, pos2);
                }
            }
            a1.pop();
        }
    }
}

void bfs (map<int, VC> m, int s, int d, bool& pos1)
{
    queue<int> q;
    VC path;
    q.push(s);
    set<int> vi;
    vi.insert(s);
    while(!q.empty())
    {
        int k = q.front();
        q.pop();
        path.pb(k);
        if(k==d)
        {
            break;
        }
        for(auto &x : m[k])
        {
            if(vi.find(x)==vi.end())
            {
                vi.insert(x);
                q.push(x);
            }
        }
    }

    if(path.size()!=0 && path[path.size()-1]==d )
    {
        pos1 = true;
        out "BFS: ";
        for(int i=0;i<path.size()-1;i++)
        {
            out path[i]<<" ";
        }
        out path[path.size()-1]<<endl;
    }
    else
    {
        out "Impossible to traverse\n";
    }
    
    return;
}

void solve()
{
    map<int,vector<int>> m;
    int edge;
    out "Enter the number of edges: ";
    in edge;
    cout<<"\n Enter the edge: ";
    for(int i=0;i<edge;i++)
    {
        int x,y;
        in x>>y;
        m[x].pb(y);
    }
    int s,d;
    out "Source: ";
    in s;
    out "Destination: ";
    in d;

    bool pos1 = false, pos2 = false;
    bfs(m, s, d, pos1);
    dfs(m, s, d, pos2);

    if(pos1==false && pos2==false)
        out "Impossible to traverse\n";
    return;
}


int32_t main()
{
    int t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}
