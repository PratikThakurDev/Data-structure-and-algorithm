#include <bits/stdc++.h>
using namespace std ;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack <int> st ;
    int n = nums2.size() ;
    unordered_map<int,int> nge ( n , -1);
    for ( int i = n - 1 ; i >=0 ; i--) {
        while ( !st.empty() && st.top() <= nums2[i % n]) {
            st.pop() ;
        } 
        nge[nums2[i]] = st.empty() ? -1 : st.top() ;
        st.push(nums2[i]) ;
    }

    vector<int> result ;
    for ( auto it : nums1 ) {
        result.push_back(nge[it]) ;
    }
    return result;
}

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size() ;
    stack<int> st ;
    vector<int> nge ;
    for ( int i = 2*n - 1 ; i >=0 ; i-- ) {
        while ( !st.empty() && nums[i % n] >= st.top() ) st.pop() ;
        if ( i < n ) {
            nge[i] = st.top() ;
        }
        st.push( nums[i%n] ) ;
    }
    return nge ;
}

vector<int> nextGreaterElementsII(vector<int>& nums) {
    int n = nums.size() ;
    stack<int> st ;
    vector<int> nge(n) ;
    for ( int i = 2*n - 1 ; i >=0 ; i-- ) {
        while ( !st.empty() && nums[i % n] >= st.top() ) st.pop() ;
        if ( i < n ) {
            nge[i] = st.empty() ? -1 : st.top() ;
        }
        st.push( nums[i%n] ) ;
    }
    return nge ;
}