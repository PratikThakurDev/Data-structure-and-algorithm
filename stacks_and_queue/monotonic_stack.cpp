#include <bits/stdc++.h>
using namespace std ;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack <int> st ;
    int n = nums2.size() ;
    unordered_map<int,int> nge ;
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

vector<int> nextSmallerElements(vector<int>& nums) {
    int n = nums.size() ;
    stack<int> st ;
    vector<int> nse(n) ;
    for ( int i = n - 1 ; i >=0 ; i-- ) {
        while ( !st.empty() && nums[i] <= st.top() ) st.pop() ;
        nse[i] = st.empty() ? -1 : st.top() ;
        st.push( nums[i] ) ;
    }
    return nse ;
}

int trap(vector<int>& height) {
    int n = height.size() ;
    int lMax = 0 , rMax = 0 , total = 0 ;
    int l = 0 ;
    int r = n - 1 ;
    while ( l < r ) {
        if ( height[l] <= height[r] ) {
            if ( lMax > height[l] ) {
                total += lMax - height[l] ;
            } else lMax = height[l] ;
            l++ ;   
        } else {
            if ( rMax > height[r] ) {
                total += rMax - height[r] ;
            } else rMax = height[r] ;
            r-- ;
        }
    }
    return total ;
}