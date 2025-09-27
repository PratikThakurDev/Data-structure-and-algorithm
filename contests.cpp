#include <bits/stdc++.h>
using namespace std ;

string majorityFrequencyGroup(string s) {
    unordered_map< char , int > freqMap ;
    unordered_map<int , string > freqGroup ; 
    int bestFreq = 0 ;
    int bestSize = 0 ;
    string res ;
    for ( char it : s ) {
        freqMap[it] ++ ;
    }

    for ( auto it : freqMap ) {
        freqGroup[it.second] += it.first ;
    }

    for (auto &p : freqGroup) {
        int freq = p.first;
        int size = p.second.size();
        
        if (size > bestSize || (size == bestSize && freq > bestFreq)) {
            bestSize = size;
            bestFreq = freq;
        }
    }

    return freqGroup[bestFreq] ;
}

pair<int,int> moveToNext(char c) {
    if (c == 'U') return {0, 1};
    if (c == 'D') return {0, -1};
    if (c == 'L') return {-1, 0};
    return {1, 0};
}

int distinctPoints(string s, int k) {    
    int n = s.size();
    vector<pair<int,int>> prefix(n+1, {0,0});

    for (int i = 0; i < n; i++) {
        auto [dx, dy] = moveToNext(s[i]);
        prefix[i+1] = {prefix[i].first + dx, prefix[i].second + dy};
    }
    
    pair<int,int> total = prefix[n];
    set<pair<int,int>> results;

    for (int i = 0; i + k <= n; i++) {
        int j = i + k;
        pair<int,int> removed = {prefix[j].first - prefix[i].first,
                                    prefix[j].second - prefix[i].second};
        pair<int,int> endPos = {total.first - removed.first,
                                total.second - removed.second};
        results.insert(endPos);
    }

    return results.size();
}