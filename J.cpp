#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <math.h>

typedef long long ll ;

#define pairi pair <int,int>
#define pairll pair <long long,long long>
#define vi vector <int> 
#define vll vector <long long> 
#define mapi map <int,int> 
#define mapill map <int,long long> 
#define seti set <int> 
#define setll set <long long> 
#define pb push_back
#define fr(i,a,b) for(int i = a ; i < b ; i++)
#define fir(i,a,b) for(int i = b ; i >= a ; i--)
#define tarr(a,n,typ,val) typ *a = new typ[n] ; fr(i,0,n) a[i] = val
#define arr(a,n,val) tarr(a,n,int,val)
#define tmatrix(M,n,m,typ) typ**M = new typ*[n] ; fr(i,0,n) M[i] = new typ[m]
#define matrix(M,n,m) tmatrix(M,n,m,int)
#define outA(a,n) fr(_,0,n) cout << (a)[_] << " " ; cout << endl 
#define outV(v) outA(v,v.size())
#define outM(M,n,m) fr(__,0,n) { outA((M)[__],m) ; }
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define yes(check) cout << (check ? "YES" : "NO") << endl

using namespace std;

int n, t[400004];

void build(int* a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2] , t[v*2+1]);
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(sum(v*2, tl, tm, l, min(r, tm)),
           sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}


int main()
{
    fast ;
    // #warning TODO : comment out freopen
    // freopen("in","r",stdin) ;
    // freopen("out","w",stdout) ;
    int t , m , i , j , k , x , y , q ;
    // cin >> t ;
    t = 1 ;
    while(t--)
    {
        cin >> n ;
        mapi pos ;
        arr(a,n,0) ;
        fr(i,0,n){
            cin >> a[i] ;
            pos[a[i]] = i ;
        }
        arr(diff,n,0) ;
        fr(i,1,n)
            diff[i] = a[i] - a[i-1] ;
        build(diff,1,0,n-1) ;
        cin >> q ;
        while(q--){
            cin >> x >> k ;
            int ans = sum(1,0,n-1,pos[x]+1,n-1) ;
            // cout << ans << endl ;
            if(k >= ans)
                cout << "YES\n" ;
            else
                cout << "NO\n" ;
        }
    }

}