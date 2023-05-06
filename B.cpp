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

int main()
{
    fast ;
    // #warning TODO : comment out freopen
    // freopen("in","r",stdin) ;
    // freopen("out","w",stdout) ;
    int t , n , m , i , j , k , x , y ;
    // cin >> t ;
    t = 1 ;
    while(t--)
    {
        cin >> n ;
        vi even,odd ;
        arr(a,n,0) ;
        fr(i,0,n){
            cin >> a[i] ;
            if(a[i]%2)
                odd.pb(a[i]) ;
            else
                even.pb(a[i]) ;
        }
        sort(odd.begin(),odd.end());
        reverse(odd.begin(),odd.end());
        ll s = 0 ;
        for (auto c : even)
            s += c ; 
        i = 0 ;
        while(i < odd.size()/2){
            s += odd[2*i] + odd[2*i+1] ;
            i ++ ;
        }
        if(s == 0)
            cout << -1 << endl ;
        else
            cout << s << endl ;
    }

}