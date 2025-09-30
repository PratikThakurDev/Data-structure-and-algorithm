#include <bits/stdc++.h> 
using namespace std ;

bool checkIthBit(int n, int i) {
    string binaryForm ;
    while ( n > 0 ) {
        binaryForm += (n % 2) == 0 ? '0' : '1' ;
        n = n / 2 ;
    }
    if ( binaryForm.size() > i) return false ;

    return binaryForm[i] == '1' ;
}

bool checkIthBit ( int n , int i ) {
     
    return ( (n & ( 1 << i))!= '0' ) ;
}

bool checkEven ( int n ) {

    return ( (n & 1) == '0' ) ;
}

bool isPowerOfTwo(int n) {
    string binary ;
    while ( n > 0 ) {
        binary += (n % 2) == 0 ? '0' : '1' ;
        n = n / 2 ;
    }
    for ( int i = 0 ; i < binary.size() - 1 ; i++ ) {
        if ( binary[i] == '1' ) return false ;
    }

    return true ;
}

int countSetBits( int n ) {
    int cnt = 0 ;
    // while ( n > 0 ) {
    //     cnt += n & 1 ;
    //     n = n >> 1 ;
    // }

    while ( n != 0 ) {
        n = n & ( n - 1 ) ;
        cnt++ ;
    }
    return cnt ;
}

void swapNum ( int a , int b ) {
    a = a ^ b ;
    b = a ^ b ;
    a = a ^ b ;
}

int divide(int dividend, int divisor) {
    if ( dividend == divisor ) return 1 ;
    bool sign = true ;
    long ans = 0 ;
    if ( dividend <= 0 && divisor > 0 ) sign = false ;
    if ( dividend >= 0 && divisor < 0 ) sign = false ;
    long n = labs ( dividend ) ;
    long d = labs ( divisor ) ;
    while ( n >= d ) {
        int cnt = 0 ;
        while ( n >= ( d << cnt + 1 )) {
            cnt++ ;
        }
        ans += 1<<cnt ;
        n = n - (d << cnt ) ;
    }
    if ( ans == 1<<31 && sign == true ) return INT_MAX ;
    if ( ans == 1<<31 && sign == false ) return INT_MIN ;
    return sign ? int ( ans ) : - int (ans) ;
}

int minBitFlips(int start, int goal) {
    int xorr = start ^ goal ;
    int cnt = 0 ;
    while ( xorr != 0 ) {
        xorr = xorr & ( xorr - 1 ) ;
        cnt ++ ;
    }
    return cnt ;
}

int xorrTillN ( int n ) {
    if ( n % 4 == 1 ) return 1 ;
    if ( n % 4 == 2 ) return n + 1 ;
    if ( n % 4 == 3 ) return 0 ; 
}

int findXorRange ( int l , int r ) {
    return xorrTillN(l - 1) ^ xorrTillN( r ) ;
}

vector<int> printPRimeFactors ( int n ) {
    vector<int> ans ;
    for ( int i = 2 ; i*i <= n ; i++ ) {
        if ( n % i == 0 ) {
            ans.push_back( i ) ;
            while ( n % i == 0 ) {
                n = n / 2 ;
            }
        }
    }
    if ( n != 1 ) ans.push_back(n) ;
}

int countPrimes(int n) {
    int cnt =0 ;
    vector<int> primeList( n + 1 , 1 ) ;
    for ( int i = 2 ; i*i <= n ; i++ ) {
        if ( primeList[i] == 1 ) {
            for ( int j = i * i ; j <= n ; j = j + i ) {
                primeList[j] = 0 ;
            }
        }
    }
    for ( int i = 2 ; i < n ; i++ ) {
        if ( primeList[i] == 1 ) cnt ++ ;
    }
    return cnt ;
}

int main() {

return 0 ;
}