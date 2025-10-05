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

vector<int> previousSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top() ;
        st.push(nums[i]);
    }
    return pse;
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

vector<int> nextSmallerElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] >= nums[i])
            st.pop();
        if (!st.empty())
            nse[i] = st.top();
        st.push(i);
    }
    return nse;
}

vector<int> previousSmallerElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] > nums[i])
            st.pop();
        if (!st.empty())
            pse[i] = st.top();
        st.push(i);
    }
    return pse;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse = previousSmallerElement(arr);
    vector<int> nse = nextSmallerElements(arr);
    int mod = 1e9 + 7;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        long long freq = left * right;
        sum = (sum + freq * arr[i]) % mod;
    }
    return (int) sum;
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size() ;
    vector<int> ans ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( asteroids[i] > 0 ) ans.push_back(asteroids[i]) ;
        else {
            while ( !ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i] )) ans.pop_back() ;
            if( !ans.empty() && ans.back() == abs(asteroids[i] ) ) ans.pop_back() ;
            else if ( ans.empty() || ans.back() < 0 ) ans.push_back( asteroids[i]) ;
        }
    }
    return ans ;
}

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> nge(n, n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i])
            st.pop();
        if (!st.empty())
            nge[i] = st.top();
        st.push(i);
    }
    return nge;
}

vector<int> previousGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> pge(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i])
            st.pop();
        if (!st.empty())
            pge[i] = st.top();
        st.push(i);
    }
    return pge;
}


long long subArrayRanges(vector<int>& nums) {
    int n = nums.size() ;
    vector<int> pse = previousSmallerElement (nums) ;
    vector<int> pge = previousGreaterElement (nums) ;
    vector<int> nse = nextSmallerElements ( nums ) ;
    vector<int> nge = nextGreaterElements (nums ); 
    long long miniSum = 0 ;
    long long maxiSum = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        int left1 = i - pse[i] ;
        int right1 = nse[i] - i ;
        int left2 = i - pge[i] ;
        int right2 = nge[i] - i ;
        long long freq1 = left1 * right1 * 1LL ;
        long long freq2 = left2 * right2 * 1LL ;
        miniSum += freq1 * nums[i] * 1LL ;
        maxiSum += freq2 * nums[i] * 1LL ;
        
    }
    return maxiSum - miniSum ;
}

int main () {

return 0 ;
}