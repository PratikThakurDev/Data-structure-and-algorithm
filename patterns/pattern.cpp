#include <bits/stdc++.h>
using namespace std;

void solve10() {

    int n ;
    cin>>n;
    for( int i = 1 ; i < 2*n ; i++) {
        int stars = i;
        if(stars > n) {
            stars = 2*n-i;
        }
        for( int j = 0 ; j < stars ; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }

}

void solve11() {
    int n;
    cin>>n;
    int num = 1;
    for ( int i =0 ; i < n ; i++) {
        
        for ( int j = 0 ; j < i+1 ; j++) {
            
            if ( num == 1) {
                cout<<num<<" ";
                num = 0;
            }
            
            else {
                cout<<num<<" ";
                num = 1;
            }
            

        }
        cout<<"\n";
    }
}

void solve12() {
    int n ;
    cin>>n;
    for (int i = 1 ; i < n+1 ; i++) {

        for ( int j = 1 ; j < i+1 ; j++) {
            cout<<j;
        }

        for ( int j = 0 ; j < (n-i)*2 ; j++) {
            cout<<" ";
        }

        for ( int j = i; j > 0 ; j--) {
            cout<<j;
        }
        cout<<"\n";
    }
}

void solve13() {
    int n;
    cin>>n;
    int num = 1;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < i+1 ; j++) {
            cout<<num<<" ";
            num = num + 1;
        }
        cout<<endl;
    }
}

void solve14() {
    string str = "ABCDE";
    for ( int i = 0 ; i < str.length() ; i++) {
        for ( int j = 0 ; j < i+1 ; j++) {
            cout<<str[j];
        }
        cout<<endl;
    }
}

void solve15() {
    string str = "ABCDE";
    for ( int i = 0 ; i < str.length() ; i++) {
        for ( int j = 0 ; j < str.length()-i ; j++) {
            cout<<str[j];
        }
        cout<<endl;
    }
}

void solve16() {
    string str = "ABCDE";
    for (int i = 0 ; i < str.length() ; i++) {
        for (int j = 0  ; j < i + 1 ; j++) {
            cout<<str[i];
        }
        cout<<endl;
    }
}

void solve17() {
    string str = "ABCD";

    for ( int i = 0 ; i < str.length() ; i++) {

        for ( int j  = 0 ; j < str.length() - i ; j++) {
            cout<<" ";
        }
        
        for ( int j = 0 ; j < i + 1 ; j++) {
            cout<<str[j];
        }

        if ( i > 0) {
            for ( int j = i ; j > 0 ; j--) {
                cout<<str[j-1];
            }
        }

        for ( int j  = 0 ; j < str.length() - i ; j++) {
            cout<<" ";
        }

        cout<<endl;
    }
}

void solve18() {
    int n;
    cin>>n;
    for (int i = 0 ; i < n ; i++) {
        for (char ch = 'E'-i ; ch <= 'E'; ch++) {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

void solve19() {
    int n;
    cin>>n;

    for (int i = 0 ; i < n ; i++) {
        
        for (int j = n-i ; j > 0 ; j-- ) {
            cout<<"*";
        }

        for (int j = 0 ; j < 2*i ; j++) {
            cout<<" ";
        }

        for (int j = n-i ; j > 0 ; j-- ) {
            cout<<"*";
        }
        cout<<endl;
    }

    for (int i = 0 ; i < n ; i++) {

        for (int j = 0 ; j < i+1 ; j++ ) {
            cout<<"*";
        }

        for (int j = 0 ; j < 2*n-2*i-2 ; j++) {
            cout<<" ";
        }

        for (int j = 0 ; j < i+1 ; j++ ) {
            cout<<"*";
        }
        cout<<endl;
    }
}

void solve20() {
    int n;
    cin>>n;

    for (int i = 1 ; i < 2*n ; i++) {

        if (i <= n) {
            
            for (int j = 0 ; j < i ; j++) {
                cout<<"*";
            }

            for (int j = 0 ; j < 2*n-2*i ; j++) {
                cout<<" ";
            }

            for (int j = 0 ; j < i ; j++) {
                cout<<"*";
            } 
            cout<<endl;

        } else {
            
            for (int j = 0 ; j < 2*n-i ; j++) {
                cout<<"*";
            }

            for (int j = 0 ; j < 2*i-2*n ; j++) {
                cout<<" ";
            }

            for (int j = 0 ; j < 2*n-i ; j++) {
                cout<<"*";
            }
            cout<<endl;
        }

    }
}

void solve21() {
    int n;
    cin>>n;
    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            if ( i == 0 || j == 0 || j == n-1 || i == n-1) {
                cout<<"*";
            } else {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

void solve22() {
    int n ;
    cin>>n ;

    for ( int i = 0 ; i < 2*n -1 ; i++ ) {
        for ( int j = 0 ; j < 2*n -1 ; j++) {
            int top = i;
            int bottom = 2*n - 2 - i;
            int left = j;
            int right = 2*n - 2 - j;
            cout<<n-min(min(top,bottom),min(left,right));
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve19();
    return 0;
}
