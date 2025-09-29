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

int main() {

return 0 ;
}