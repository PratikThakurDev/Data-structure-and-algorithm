#include <bits/stdc++.h>
using namespace std;

vector <int> twoSum ( vector <int > &nums , int target) {
    //Brute force
    long long sum = 0 ;
    int n = nums.size() ;
    // for (int i = 0 ; i < n ; i++) {
    //     for ( int j = 0 ; j < n ; j++) {
    //         if ( i != j) {
    //             sum = nums[i] + nums[j] ;
    //         }
    //         if (sum == target && i != j ) {
    //             return {i,j} ;
    //         }
            
    //     }
    // }
    // return {-1,-1} ;

    // Better approach using hashmap 

    unordered_map <int , int > mpp ; 

    for ( int i = 0 ; i < n ; i ++) {
        sum = nums[i] ;
        long long rem = target - sum ;
        if ( mpp.find(rem) != mpp.end() ) {
            return { mpp[rem] , i } ;
        }
        mpp[sum] = i ; 
    }
    return {-1,-1} ;

}

void sortColors(vector<int>& nums) {
    
    int n = nums.size() ;
    int low = 0 ;
    int mid = 0 ;
    int high = n-1 ;

    while ( mid <= high) {
        if ( nums[mid] == 0) {
            swap(nums[low],nums[mid]) ;
            mid++ ;
            low++ ;
        }

        else if ( nums[mid] == 1) {
            mid++ ;
        }

        else if ( nums[mid] == 2) {
            swap(nums[mid],nums[high]) ;
            high-- ;
        }
    }
    
}

int majorityElement( vector < int > &nums ) {
    // int n = nums.size() ;
    // map <int ,int > mpp ;
    // for ( int i = 0 ; i < n ; i++) {
    //     mpp[nums[i]]++ ;
    // }

    // for (auto it : mpp) {
    //     if (it.second > n/2) {
    //         return it.first ;
    //     }
    // }
    // return -1 ;

    //optimal approach ;
    int n = nums.size() ;
    int el = 0 ;
    int count = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( count == 0) {
            el = nums[i] ;
            count = 1 ;
        } 
        else if ( el == nums[i] ) {
            count ++ ;
        }
        else {
            count -- ;
        }
    }
    int c = 0 ;
    for ( int i = 0 ; i < n ; i++) {
        if ( nums[i] == el) {
            c++ ;
        }
    }
    if ( c > n/2) return el;
    return -1 ;
    
}

void maxSubArray ( vector <int> &nums ) {
    int n = nums.size() ;
    int maxSum = INT_MIN ;
    // for (int i = 0 ; i < n ; i ++) {
    //     int sum = 0 ;
    //     for (int j = 0 ; j < n ; j++) {
    //         sum += nums[j] ;
    //     }
    //     maxSum = max(maxSum , sum ) ;
    // }
    // return maxSum ;
    int sum = 0 ;
    int start = 0 ;
    int ansStart = 0 ;
    int ansEnd = 0 ; 
    for (int i = 0 ; i < n ; i++) {
        if (sum == 0) start = i ;
        sum += nums[i] ;
        if ( sum > maxSum ){
            maxSum = sum ;
            ansStart = start ;
            ansEnd = i ;
        }
        if (sum < 0) {
            sum = 0 ;
        }
    }
    for ( int i = ansStart ; i <= ansEnd ; i++) {
        cout<<nums[i] << ' ' ;
    }


}

int maxProfit ( vector <int> &prices) {
    // int n = prices.size() ;
    // int profit = 0 ; 
    // int maxprofit = 0 ;
    // for (int i = 0 ; i < n ; i ++) {
    //     for (int j = i+1 ; j < n ; j++) {
    //         profit = prices[j]-prices[i] ;
    //         maxProfit = max(profit,maxProfit) ; 
    //     }
    // }
    // return maxProfit ;
    int maxPro = 0;
    int n = prices.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    
    return maxPro;  
}

vector<int> rearrangeArray(vector<int>& nums) {
    // int n = nums.size() ;
    // int pairNumber = 0 ;
    // vector <int> pos ;
    // vector <int> neg ;
    // for (int i = 0 ; i < n ; i++ ) {
    //     if (nums[i] > 0) {
    //         pos.push_back(nums[i]) ;
    //     }
    //     else if (nums[i] < 0) {
    //         neg.push_back(nums[i]) ;
    //     }
    // }

    // for (int i = 0 ; i < n ; i++) {

    //     if (i % 2 == 0) {
    //         nums[i] = pos[pairNumber] ;
    //     }
    //     else if ( i % 2 != 0 ) {
    //         nums[i] = neg[pairNumber] ;
    //         pairNumber++ ;
    //     }
    // }

    //optimal
    int n = nums.size() ;
    int posIndex = 0 ; 
    int negIndex = 1 ;
    vector <int > ans (n,0) ;
    for (int i = 0 ; i < n ; i++) {
        if ( nums[i] < 0) {
            ans[negIndex] = nums[i] ;
            negIndex += 2 ;
        } else {
            ans[posIndex] = nums[i] ;
            posIndex += 2 ;
        }
    }
    return ans ;
}

void nextPermutation(vector<int>& nums) {

    int ind = -1 ;
    int n = nums.size() ;
    for (int i = n-2 ; i >= 0 ; i--) {
        if ( nums[i] < nums[i+1]) {
            ind = i ;
            break ;
        }
    }

    if ( ind == -1 ) {
        reverse(nums.begin(),nums.end()) ;
        return ;
    }
    for ( int i = n-1 ; i > ind ; i-- ) {
        if ( nums[i] > nums[ind]) {
            swap(nums[i],nums[ind]) ;
            break ;
        }
    }

    reverse (nums.begin()+ind+1 , nums.end()) ;
    return ;
}

void leaderOfArray ( vector<int> &arr) {
    // int n = arr.size() ;
    // bool isLeader = true ;
    // for (int i = 0 ; i < n-1 ; i++) {
    //     for (int j = i+1 ; j < n ; j++) {
    //         if ( arr[i] < arr[j]){
    //             isLeader = false ;
    //         }
    //     }
    //     if (isLeader) cout << arr[i] << " " ;
    //     isLeader = true ;
    // }
    // cout << arr[n-1] ;

    //optimal 
    int n = arr.size() ;
    int maxi = INT_MIN ;
    for ( int i = n- 1 ; i >= 0 ; i--) {
        if ( arr[i] > maxi) {
            cout << arr[i] << " " ;
            maxi = arr[i] ;
        }
    }
}

int longestConsecutive(vector<int>& nums) {
    // sort(nums.begin(),nums.end()) ;
    // int length = 1 ;
    // int longest = 1 ;
    // int lastSmaller = INT_MIN ;
    // int n = nums.size() ;
    // for (int i = 0 ; i < n ; i++) {
    //     if ( nums[i]-1 == lastSmaller) {
    //         length++ ;
    //         lastSmaller = nums[i] ;
    //     }
    //     else if ( nums[i]-1 != lastSmaller) {
    //         length = 1 ;
    //         lastSmaller = nums[i] ;
    //     }
    //     longest = max( longest , length ) ;
    // }
    // return longest ;

    // optimal approach ;
    unordered_set<int> st ;
    int n = nums.size() ;
    int longest = 1;
    for (int i = 0 ; i < n ; i++) {
        st.insert(nums[i]) ;
    }

    for ( auto it : st) {
        if ( st.find(it -1 ) == st.end()) {
            int count = 1 ;
            int x = it ;
            while ( st.find(x+1) != st.end()) {
                count += 1;
                x += 1 ;
            }
            longest = max ( longest , count ) ;
        }
        
    }
    return longest ;
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix,int n , int m ) {
    // int col[m] = {0} ;
    // int row[n] = {0} ;
    // for ( int i = 0 ; i < n ; i++) {
    //     for ( int j = 0 ; j < m ; j++) {
    //         if (matrix[i][j] == 0) {
    //             row[i] = 1 ;
    //             col[j] = 1 ;
    //         }
    //     }
    // }
    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < m ; j++) {
    //         if ( row[i] || col[j] ) {
    //             matrix[i][j] = 0 ;
    //         }
    //     }
    // }
    // return matrix ;

    //optimal ;
    int col0 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;

                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

void rotate(vector<vector<int>>& matrix ) {

    int n = matrix.size() ;
    int m = matrix[0].size() ;

    // vector<vector<int>> ans (m, vector<int>(n))  ;
    // for ( int i = 0 ; i < n ; i++ ) {
    //     for ( int j = 0 ; j < m ; j++) {
    //         ans[j][n-1-i] = matrix[i][j] ;
    //     }
    // } 

    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < m ; j++) {
    //         cout << matrix[i][j] << " " ;
    //     }
    //     cout<< endl;
    // }
 
    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < m ; j++) {
    //         cout << ans[i][j] << " " ;
    //     }
    //     cout<< endl;
    // }

    for (int i = 0 ; i < n ; i++ ) {
        for (int j = 0 ; j < m ; j++) {
            if ( i > j) {
                swap(matrix[i][j] , matrix[j][i]) ;                
            }
        }
    }

    for (int i = 0 ; i < n ; i++) {
        reverse(matrix[i].begin() , matrix[i].end()) ;
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cout << matrix[i][j] << " " ;
        }
        cout<< endl;
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size() ;
    int m = matrix[0].size() ;

    vector<int > ans  ;

    int top = 0  , left = 0 ;
    int bottom = n - 1 ;
    int right = m - 1 ;

    while ( top <= bottom && left <= right ) {
        //left to right ;
        for ( int i = left ; i <= right ; i++ ) {
            ans.push_back(matrix[top][i]) ; 
        }
        top++ ;

        //top to bottom ;
        for ( int i = top ; i <= bottom ; i++) {
            ans.push_back(matrix[i][right]) ;
        }
        right -- ;

        if (top <= bottom) {
            //right to left ;
            for ( int i = right ; i >= left ; i-- ) {
                ans.push_back(matrix[bottom][i]) ;
            }
            bottom-- ;
        }

        if ( left <= right) {
            //bottom to top ;
            for ( int i = bottom ; i >= top ; i -- ) {
                ans.push_back(matrix[i][left]) ;
            } 
            left++ ;           
        }

    }
    return ans ;

}

int subarraySum(vector<int>& nums, int k) {
    // int n = nums.size() ;
    // int count = 0 ;
    // for ( int i = 0 ; i < n ; i++ ) {
    //     int sum = 0 ;
    //     for ( int j = i ; j < n ; j++ ) {
    //         sum += nums[j] ;
    //         if ( sum == k) {
    //             count++ ;
    //         }
    //     }
    // }
    // return count ;

    // optimal 
    int n = nums.size();
    map <int,int >  mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; 
    for (int i = 0; i < n; i++) {
        preSum += nums[i];

        int remove = preSum - k;

        cnt += mpp[remove];

        mpp[preSum] += 1;
    }
    return cnt;
}




int main () {
    vector<int> nums = {3,1,2,4} ;

    cout << subarraySum(nums , 6 ) ;

    return (0) ;
}