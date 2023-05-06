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

int maxSubArraySum(int* a, int size)
{
    int max_so_far = -1, max_ending_here = 0, start = 0 ;
    int curr_odd = 0, odd_idx = -1 ;
 
    for (int i = 0; i < size; i++) {
        // cout << max_so_far << endl ;
        if(a[i]%2){
            curr_odd ++ ;
            if(curr_odd == 2){
                curr_odd = 1 ;
                while(start <= odd_idx){
                    max_ending_here -= 1 ;
                    start ++ ;
                }
            }

            odd_idx = i ;
        }
        max_ending_here = max_ending_here + 1;
        if (max_so_far < max_ending_here && curr_odd == 1)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    fast ;
    // #warning TODO : comment out freopen
    // freopen("in","r",stdin) ;
    // freopen("out","w",stdout) ;
    int t , n , m , i , j , k , x , y ;
    t = 1 ;
    while(t--)
    {
        cin >> n ;
        arr(a,n,0) ;
        fr(i,0,n)
            cin >> a[i] ;
        cout << maxSubArraySum(a,n) ;
    }

}