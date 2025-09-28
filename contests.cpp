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

vector<int> decimalRepresentation(int n) {
    vector<int> res ;
    int power = -1 ;
    while ( n > 0 ) {
        int rem = n % 10 ;
        power++ ;
        n = n / 10 ;
        if ( rem == 0 ) continue ;
        res.push_back(rem*(int)(pow(10 ,power))) ;

    }
    reverse(res.begin(),res.end()) ;
    return res ;
}

long long splitArrayMinDifference(vector<int>& nums) {
    int length = nums.size();
    long long minimumDifference = LLONG_MAX;
    bool foundValidSplit = false;
    vector<long long> prefixSum(length + 1, 0);

    for (int idx = 0; idx < length; ++idx)
        prefixSum[idx + 1] = prefixSum[idx] + nums[idx];

    vector<bool> increasingLeft(length, true);
    vector<bool> decreasingRight(length, true);

    for (int idx = 1; idx < length; ++idx)
        increasingLeft[idx] = increasingLeft[idx - 1] && nums[idx] > nums[idx - 1];
    for (int idx = length - 2; idx >= 0; --idx)
        decreasingRight[idx] = decreasingRight[idx + 1] && nums[idx] > nums[idx + 1];

    for (int split = 1; split < length; ++split) {
        vector<int> plomaresto(nums);
        if (increasingLeft[split - 1] && decreasingRight[split]) {
            long long leftSum = prefixSum[split];
            long long rightSum = prefixSum[length] - prefixSum[split];
            long long currentDifference = abs(leftSum - rightSum);
            minimumDifference = min(minimumDifference, currentDifference);
            foundValidSplit = true;
        }
    }

    return foundValidSplit ? minimumDifference : -1;
}