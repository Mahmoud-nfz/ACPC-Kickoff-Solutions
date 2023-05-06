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
int n , m ;

char M[8][8] ;
int attacked[8][8] ;


bool isValidMove(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void getPossibleKnightMoves(int i, int j) {

    // Possible relative movements for a knight in one move
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (isValidMove(x, y)) {
            attacked[x][y] = 1 ;
        }
    }
}


bool canKingMoveToSafeSquare(int i, int j) {

    // Possible relative movements for a king in one move
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (isValidMove(x, y) && !attacked[x][y]) {
            return true;
        }
    }

    return false;
}

int within_limits(int i, int j, int addi = 0 , int addj = 0){
    int x = i + addi , y = j + addj ;
    return x >= 0 && y >=0 && x < 8 && y < 8 ;
}

void attack(char p, int i, int j)
{
    if(p == 'Q' || p == 'B'){
        int add = 1 ;
        while(within_limits(i,j,add,add)){
            attacked[i+add][j+add] = 1 ;
            if(M[i+add][j+add] != '.' && M[i+add][j+add] != 'K')
                break ;
            add ++ ;
        }
        add = -1 ;
        while(within_limits(i,j,add,add)){
            attacked[i+add][j+add] = 1 ;
            if(M[i+add][j+add] != '.' && M[i+add][j+add] != 'K')
                break ;
            add -- ;
        }
        add = 1 ;
        while(within_limits(i,j,add,-add)){
            // if(p == 'Q')
            // cout << i+add << " " << j-add << endl ;
            attacked[i+add][j-add] = 1 ;
            if(M[i+add][j-add] != '.' && M[i+add][j-add] != 'K')
                break ;
            add ++ ;
        }
        add = -1 ;
        // if(p == 'Q' && i == 3)
        //     cout << "starting at " << i << " " << j << endl ;
        while(within_limits(i,j,add,-add)){
            // if(p == 'Q' && i == 3)
            // cout << i+add << " " << j-add << endl ;
            attacked[i+add][j-add] = 1 ;
            if(M[i+add][j-add] != '.' && M[i+add][j-add] != 'K')
                break ;
            add -- ;
        }
    }
    if(p == 'R' || p == 'Q'){
        int add = 1 ;
        while(within_limits(i,j,add,0)){
            // cout << i + add << " " << j << endl ;
            // cout << M[i+add][j] << endl ;
            attacked[i+add][j] = 1 ;
            if(M[i+add][j] != '.' && M[i+add][j] != 'K')
                break ;
            add ++ ;
        }
        add = -1 ;
        while(within_limits(i,j,add,0)){
            attacked[i+add][j] = 1 ;
            if(M[i+add][j] != '.' && M[i+add][j] != 'K')
                break ;
            add -- ;
        }
        add = 1 ;
        while(within_limits(i,j,0,add)){
            attacked[i][j+add] = 1 ;
            if(M[i][j+add] != '.' && M[i][j+add] != 'K')
                break ;
            add ++ ;
        }
        add = -1 ;
        while(within_limits(i,j,0,add)){
            attacked[i][j+add] = 1 ;
            if(M[i][j+add] != '.' && M[i][j+add] != 'K')
                break ;
            add -- ;
        }
    }
    if(p == 'P'){
        if(within_limits(i,j,-1,1))
            attacked[i-1][j+1] = 1 ;
        if(within_limits(i,j,-1,-1))
            attacked[i-1][j-1] = 1 ;
    }
    if(p == 'N'){
        getPossibleKnightMoves(i,j) ;
    }
}

int main()
{
    fast ;
    // #warning TODO : comment out freopen
    // freopen("in","r",stdin) ;
    // freopen("out","w",stdout) ;
    int t , i , j , k , x , y ;
    cin >> t ;
    while(t--)
    {
        n = 8 ; m = 8 ;
        fr(i,0,n){
            fr(j,0,m){
                attacked[i][j] = 0 ;
            }
        }
        x = -1 ; y = -1 ;
        fr(i,0,n){
            fr(j,0,m){
                cin >> M[i][j] ;
            }
        }
        fr(i,0,n){
            fr(j,0,m){
                if(M[i][j] != '.' && M[i][j] != 'K')
                    attack(M[i][j],i,j) ;
                if(M[i][j] == 'K')
                    x = i , y = j ;
            }
        }
        // outM(attacked,n,m) ;
        if(canKingMoveToSafeSquare(x,y))
            cout << "Yes\n" ;
        else cout << "No\n" ;

    }

}