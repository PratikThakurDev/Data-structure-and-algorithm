#include <bits/stdc++.h> 
using namespace std ;

string removeOuterParentheses(string s) {
    string result ;
    int depth = 0 ;

    for ( char c : s) {
        if ( c == '(') {
            if (depth > 0 ) result += c ;
            depth ++ ;
        } else {
            depth-- ;
            if ( depth > 0 ) result += c ;
        }
    }
    return result ;
}

string reverseWords(string s) {
    s += " "; // add space at end to handle last word
    stack<string> st;
    string word = "";

    for (char c : s) {
        if (c == ' ') {
            if (!word.empty()) {
                st.push(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }

    string ans = "";
    while (!st.empty()) {
        ans += st.top();
        st.pop();
        if (!st.empty()) ans += " ";
    }
    return ans;
}

string largestOddNumber(string num) {
    int n = num.size() ;
    for ( int i = n - 1 ; i >= 0 ; i-- ) {
        if ( (num[i] - '0') % 2 != 0 ) {  // num[i] - '0' subtracts their ascii value 
            return num.substr(0 , i+1 ) ;
        }
    }
    return "" ;
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    for (int i = 0; i < strs[0].size(); ++i) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); ++j) {
            if (i == strs[j].size() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    vector<int> m1(256 , -1) ;
    vector<int> m2(256 , -1) ;


    for (int i = 0; i < s.size(); i++) {
        unsigned char c1 = s[i];
        unsigned char c2 = t[i];

        if (m1[c1] != -1 && m1[c1] != c2) return false;
        if (m2[c2] != -1 && m2[c2] != c1) return false;

        m1[c1] = c2;
        m2[c2] = c1;
    }

    return true;
}

vector<int> computeLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMPsearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0; // i: index for text, j: index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++; j++;
            if (j == m) return true; // Found match
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}

bool isAnagram(string s, string t) {
    int n = s.size() , m = t.size() ;

    if ( n != m ) return false ;
    vector<int> m1(256,0) ;
    for ( int i = 0 ; i < n ; i++ ) {
        unsigned char c1 = s[i];
        unsigned char c2 = t[i];
        m1[c1]++ ;
        m1[c2]-- ;
    }

    for ( int  freq : m1 ) {
        if ( freq != 0 ) return false ;
    }
    return true ;
}

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    vector<vector<char>> buckets(s.size() + 1) ;
    
    for ( auto [c , n] : freq ) {
        buckets[n].push_back(c) ;
    }

    string ans = "";
    for ( int freq = s.size() ; freq > 0 ; freq-- ) {
        for ( auto ch : buckets[freq] ) {
            ans.append( freq , ch ) ;
        }
    }
    return ans ;
}

int maxDepth(string s) {
    int n = s.size() ;
    int depth = 0 ; 
    int ans = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( s[i] == '(' ) {
            depth++ ;
            ans = max ( depth , ans ) ;
        }
        else if ( s[i] == ')' ) {
            depth-- ;
        }
    }
    return ans ;
}

 int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int total = 0;
    int prev = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        int value = roman[s[i]];
        if (value < prev)
            total -= value;
        else
            total += value;
        prev = value;
    }
    return total;
}

int myAtoi(string s) {
    int i = 0, n = s.size();

    while (i < n && s[i] == ' ') ++i;

    int sign = 1;
    if (i < n && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        ++i;
    }

    long num = 0;
    while (i < n && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        // Clamp result on overflow
        if (sign == 1 && num > INT_MAX) return INT_MAX;
        if (sign == -1 && -num < INT_MIN) return INT_MIN;
        ++i;
    }
    return sign * num;
}

string longestPalindrome(string s) {
    // int n = s.size() ;
    // int maxLength = 0 ;
    // string ans ;
    // for ( int i = 0 ; i < n ; i ++ ) {
    //     string temp = "" ;
    //     int length = 0 ;
    //     for ( int j = i ; j < n ; j++ ) {
    //         temp.append(1,s[j]) ;
    //         length = j - i + 1 ;
    //         string temp2 = temp ;
    //         reverse ( temp2.begin() , temp2.end()) ;
    //         if ( temp2 == temp ) {
    //             if ( length > maxLength ) {
    //                 maxLength = length ;
    //                 ans = temp ;
    //             }
    //         }
    //     }
    // }
    // return ans ;

    int n = s.size(), start = 0, maxLen = 1;
    for (int i = 0; i < n; ++i) {
        // Odd length palindrome
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            --l; ++r;
        }
        // Even length palindrome
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            --l; ++r;
        }
    }
    return s.substr(start, maxLen);

}

int beautySum(string s) {
    int total = 0;

    for (int i = 0; i < s.length(); ++i) {
        vector<int> freq(26, 0);
        for (int j = i; j < s.length(); ++j) {
            freq[s[j] - 'a']++;
            int mx = 0, mn = INT_MAX;
            for (int f : freq) {
                if (f > 0) {
                    mx = max(mx, f);
                    mn = min(mn, f);
                }
            }
            total += (mx - mn);
        }
    }
    return total;
}



int main( ) {

    cout<< beautySum("aabcb") ;
    return 0 ;
}