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
    int t , n , m , i , j , k , x , y, q ;
    // cin >> t ;
    t = 1 ;
    while(t--)
    {
        cin >> n ;
        cin >> x >> y ;
        arr(xi,n,0) ;
        arr(yi,n,0) ;
        map<int,seti> cols , rows ;
        fr(i,0,n){
            cin >> xi[i] >> yi[i] ;
            cols[xi[i]].insert(yi[i]) ;
            rows[yi[i]].insert(xi[i]) ;
        }
        cin >> q ;
        while(q -- ){
            char c ;
            cin >> c ;
            if(c == 'R'){
                if(rows[y].upper_bound(x) != rows[y].end()){
                    x = *rows[y].upper_bound(x) ;
                }
            }
            else if(c == 'L'){
                if(rows[y].lower_bound(x) != rows[y].begin()){
                    auto it = rows[y].lower_bound(x) ;
                    it -- ;
                    x = *it ;
                }
            }
            else if(c == 'U'){
                if(cols[x].upper_bound(y) != cols[x].end()){
                    y = *cols[x].upper_bound(y) ;
                }
            }
            else if(c == 'D'){
                if(cols[x].lower_bound(y) != cols[x].begin()){
                    auto it = cols[x].lower_bound(y) ;
                    it -- ;
                    y = *it ;
                }
            }

            cout << x << " " << y << endl ;
        }
    }

}