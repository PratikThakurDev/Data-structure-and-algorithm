#include <bits/stdc++.h>
using namespace std;

void solve1() {
    int n;
    cin>>n;

    int count = 0 ;

    while (n > 0
    ) {
        n = n/10;
        count++;
    }
    cout<<count;
}

int reverse(int x) {
        long int reverseNum = 0;
        while ( x > 0 || x < 0 ) {
            reverseNum = reverseNum*10 + x%10;
            x = x/10;
        }
        return reverseNum;
    }

bool isPalindrome(int x) {

        if (x < 0) return false;

        int reverseNum = 0;
        int dup = x;
        while ( x > 0) {
            reverseNum = reverseNum*10 + x%10;
            x = x/10;
        }
        return dup == reverseNum;
    }

int findGCD(int n1,int n2) {
    //My approach
    // int gcd = 1;
    // int x = 1 ;
    // while (x < min(n1,n2)) {
    //     if (n1%x == 0 && n2%x == 0) {
    //         gcd = x;
    //         x++;
    //     } else x++;
    // }
    // return gcd;


    // Optimal approach
    while(n1 > 0 && n2 > 0) {
        if(n1 > n2) {
            n1 = n1 % n2;
        }
        else {
            n2 = n2 % n1; 
        }
    }
    if(n1 == 0) {
        return n2;
    }
    return n1;
}

bool isArmstrong(int n) {
    int newNum = 0;
    vector<int>digits;
    int dup = n;
    int count = 0;
    while (n>0) {
        digits.push_back(n%10);
        n = n/10;
        count += 1;
    }
    for ( int num : digits) {
        newNum += (int)(pow(num,count));
        
    }
    return newNum == dup;
}

void getDivisors(int n) {

    int x = 1;
    while (x <= n) {
        if (n%x == 0) cout<<x++<<" ";
        else x++;
    } 
}

void isPrime(int n) {
    int count = 0 ;
    for (int i = 1 ; i < sqrt(n) ; i++) {
        if ( n % i == 0) count++;
        if (n/i != i) count++;
    }
    if ( count > 2) cout<<"false";
    else cout<<"true";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;

    isPrime(n);

    return 0;
}
