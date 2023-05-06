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

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

int ** dpm ;
int k ;
int dp(int n , int c){
    if(n == 0)
        return 1 ;
    if(c >= k)
        return 0 ;
    if(dpm[n][c] != -1)
        return dpm[n][c] ;

    int temp = 0 ;
    fr(i,0,n){
        temp += pow(c+1,n-i)*dp(i,c+1) ;
    }
    temp += dp(n,c+1) ;

    dpm[n][c] = temp ;
    return temp ;
}

int main()
{
    fast ;
    #warning TODO : comment out freopen
    freopen("in","r",stdin) ;
    freopen("out","w",stdout) ;
    int t , n , m , i , j , x , y ;
    // cin >> t ;
    t = 1 ;
    while(t--)
    {
        cin >> n >> k ;
        char a[12] ;
        fr(i,0,k)
            cin >> a[k] ;

        dpm = new int*[n+3] ;
        fr(i,0,n+3)
            dpm[i] = new int[k+1] ;
        
        fr(i,0,n+3){
            fr(j,0,k+1){
                dpm[i][j] = -1 ;
            }
        }
        cout << dp(n,0) << endl ;
        outM(dpm,n,k+1) ;
    }

}