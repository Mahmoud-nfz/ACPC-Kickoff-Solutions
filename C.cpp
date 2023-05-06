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

char ** M ;
int ** vis ;
int m,n ;

int dfs(int i, int j){
    if(i >= n-1 || j >= m-1 || i < 0 || j < 0)
        return 0 ;
    vis[i][j] = 1 ;
    if(M[i][j] != '.')
        return 0 ;
    if(M[i+1][j] != '.' || M[i+1][j+1] != '.' || M[i][j+1] != '.')
        return 0 ;
    int temp = 1 ;
    // if(i == 0 && j == 1) cout << temp << endl ;
    if(!vis[i][j+1])
       temp += dfs(i,j+1) ;
    if(!vis[i+1][j])
        temp += dfs(i+1,j) ;
    if(i>0 && !vis[i-1][j])
       temp += dfs(i-1,j) ;
    if(j>0 && !vis[i][j-1])
        temp += dfs(i,j-1) ;

    return temp ;
}

int main()
{
    fast ;
    // #warning TODO : comment out freopen
    // freopen("in","r",stdin) ;
    // freopen("out","w",stdout) ;
    int t , i , j , k , x , y ;
    // cin >> t ;
    t = 1 ;
    while(t--)
    {
        cin >> n >> m ;
        M = new char*[n] ;
        vis = new int*[n] ;
        fr(i,0,n)
            M[i] = new char[m] , vis[i] = new int[m] ;
        fr(i,0,n){
            fr(j,0,m){
                cin >> M[i][j] ;
                vis[i][j] = 0 ;
            }
        }

        int ans = 0 ;
        fr(i,0,n){
            fr(j,0,m){
                if(!vis[i][j] && M[i][j] == '.'){
                    int temp = dfs(i,j) ;
                    // cout << i << " " << j << " : " << temp << endl ;
                    ans = max(ans,temp) ;
                }
            }
        }
        cout << ans << endl ;
        
    }

}