#include <bits/stdc++.h> 
using namespace std ;

// bool checkIthBit(int n, int i) {
//     string binaryForm ;
//     while ( n > 0 ) {
//         binaryForm += n % 2 == 0 ? 0 : 1 ;
//         n = n / 2 ;
//     }
//     if ( binaryForm.size() > i) return false ;

//     return binaryForm[i] == '1' ;
// }

bool checkIthBit ( int n , int i ) {
     
    return ( (n & ( 1 << i))!= '0' ) ;
}

bool checkEven ( int n ) {
    
    return ( (n & 1) == '0' ) ;
}

