#include <bits/stdc++.h> 
using namespace std ;
 
vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ans ;
    for ( int num : nums ) {
        while ( !ans.empty() ) {
            int prev = ans.back() ;
            int curr = num ;
            int GCD = gcd( prev , curr ) ;
            if ( GCD == 1 ) {
                break ;
            }
            ans.pop_back() ;
            int lcm = (prev/GCD) * curr ;
            num = lcm ;
        }
        ans.push_back( num ) ;
    }

    return ans ;
}

int main ( ) {

return 0;
}