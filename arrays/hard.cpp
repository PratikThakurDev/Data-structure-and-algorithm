#include <bits/stdc++.h>
using namespace std;

vector <int> generateRow ( int row ) {
    long long ans = 1 ;
    vector <int> ansRow ;
    ansRow.push_back(1) ;
    for ( int col = 1 ; col < row ; col++ ) {
        ans = ans * (row - col) ;
        ans = ans / col ;
        ansRow.push_back(ans) ;
    }
    return ansRow ;
}

vector<vector<int>> generate(int numRows) {
    vector < vector < int >> ans ;
    for ( int i = 1 ; i <= numRows ; i++ ) {
        ans.push_back(generateRow(i)) ;
    }
    return ans ;
}

bool isPresent ( int num , vector < int > ans) {
    for ( auto it : ans) {
        if (it == num) {
            return true ;
        }
    }
    return false ;
}

vector<int> majorityElement2(vector<int>& nums) {
//     int n = nums.size() ;
// better approach
    // int n = nums.size() ;
    // vector <int > ans ;
    // map < int , int > mpp ;
    // for ( int i = 0 ; i < n ; i ++ ) {
    //     mpp[nums[i]] ++ ;
    // }
    // for ( auto it : mpp ) {
    //     if ( it.second > n/3) {
    //         ans.push_back(it.first) ;
    //     }
    // }
    // return ans ;

// optimal approach ;
    int count1 = 0 , count2 = 0 ;
    int ele1 = INT_MIN , ele2 = INT_MIN ; 
    int n = nums.size() ;
    vector <int> ans ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( count1 == 0 && ele2 != nums[i]) {
            count1 ++ ;
            ele1 = nums[i] ;
        }
        else if ( count2 == 0 && ele1 != nums[i]) {
            count2 ++ ;
            ele2 = nums[i] ;
        }
        else if ( ele1 == nums[i]) {
            count1 ++ ;
        }
        else if ( ele2 == nums[i]) {
            count2 ++ ;
        }
        else {
            count1-- ;
            count2-- ;
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == ele1) cnt1++;
        if (nums[i] == ele2) cnt2++;
    }

    if (cnt1 > n/3) ans.push_back(ele1);
    if (cnt2 > n/3) ans.push_back(ele2);

    return ans ;
}
 
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size() ;
    // better approach
    // set<vector<int>> st;

    // for (int i = 0; i < n; i++) {
    //     set<int> hashset;
    //     for (int j = i + 1; j < n; j++) {
    //         int third = -(nums[i] + nums[j]);

    //         if (hashset.find(third) != hashset.end()) {
    //             vector<int> temp = {nums[i], nums[j], third};
    //             sort(temp.begin(), temp.end());
    //             st.insert(temp);
    //         }
    //         hashset.insert(nums[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    //optimal 
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;

                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }
    return ans;

}

vector<vector<int>> fourSum(vector<int>& nums , int target) {
    //Better approach ;
    // int n = nums.size() ;
    // set<vector<int>> st ;

    // for ( int i = 0 ; i < n ; i++ ) {
    //     for ( int j = i + 1 ; j < n ; j++ ) {
    //         set <int> hashSet ;
    //         for ( int k = j + 1 ; k < n ; k++ ) {
    //             long long sum = nums[i] + nums[j] + nums[k] ;
    //             long long fourth = target - (sum) ;
    //             if ( hashSet.find(fourth) != hashSet.end()) {
    //                 vector<int> temp = {nums[i] , nums[j] , nums[k] , (int)fourth} ;
    //                 sort(temp.begin(),temp.end()) ;
    //                 st.insert(temp) ;
    //             }
    //             hashSet.insert(nums[k]) ;
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(),st.end()) ;
    // return ans ;

    //optimal ;
    int n = nums.size() ;
    vector<vector<int>> ans ;
    sort ( nums.begin() , nums.end ()) ;
    for (int i = 0 ; i < n ; i++ ) {
        if ( i > 0 && nums[i] == nums[i-1]) continue ;
        for ( int j = i + 1 ; j < n ; j++ ) {
            if ( j > i+1 && nums[j] == nums[j-1]) continue ;
            int k = j + 1 ;
            int l = n - 1 ;
            while (k < l) {
                long long sum = nums[i] + nums [j] ;
                sum += nums[k] ;
                sum += nums[l] ;
                if ( sum == target) {
                    vector<int > temp = { nums[i], nums[j] , nums[k] , nums[l] } ;
                    ans.push_back(temp) ;
                    l-- ;
                    k++ ;
                    while (k < l && nums[k] == nums[k-1]) k++ ;
                    while ( k < l && nums[l] == nums[l+1]) l-- ;
                } 
                else if ( sum < target ) {
                    k++ ;
                    while (k < l && nums[k] == nums[k-1]) k++ ;
                }  
                else {
                    l-- ;
                    while ( k < l && nums[l] == nums[l+1]) l-- ;
                }
            }
        }
    }
    return ans ;
}

int maxLen (vector<int>& nums ) {
    int n = nums.size() ;
    unordered_map <int , int > mpp ;
    int maxi = 0 ;
    long long sum = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        sum += nums[i] ;
        if ( sum == 0 ) {
            maxi = i + 1 ;
        }  
        else {
            
            if ( mpp.find(sum) != mpp.end()) {
                maxi = max(maxi , i - mpp[sum]) ;
            }
            else {
                mpp[sum] = i ;
            }
        }
    }
    return maxi ;
}

int subarraysWithXorK(vector<int> nums, int k) {
    //Better approach ;

    int n = nums.size() ;
    int count = 0 ;

    //Generating all the Subarrays ;
    // for ( int i = 0 ; i < n ; i++ ) {
    //     int finalXOR ;
    //     for ( int j = i ; j < n ; j++) {
    //         finalXOR = finalXOR ^ nums[j] ;
    //         if ( finalXOR == k ) {
    //             count++ ;
    //         }
    //     }
    // }

    //optimal approach ;
    int xorr = 0 ;
    map <int , int > mpp ;

    for ( int i = 0 ; i < n ; i++ ) {
        xorr = xorr ^ nums[i];
        int x = xorr ^ k;
        count += mpp[x];
        mpp[xorr]++;
    }
    return count ;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size() ;
    vector< vector<int>> ans ;
    sort(intervals.begin(),intervals.end()) ;
    
    // for ( int i = 0 ; i < n ; i++) {
    //     int start = intervals[i][0] ;
    //     int end = intervals[i][1] ;
    //     if ( !ans.empty() && ans.back()[1] >= end ) continue ;
    //     for ( int j = i+1 ; j < n ; j++ ) {
            
    //         if ( intervals[j][0] <= end) {
    //             end = max( end , intervals[j][1] ) ;
    //         }
    //         else {
    //             break ;
    //         }
    //     }
    //     ans.push_back({start,end}) ;
    // }

    //optimal 

    for ( int i = 0 ; i < n ; i++ ) {
        if ( ans.empty() || ans.back()[1] < intervals[i][0]) {
            ans.push_back(intervals[i]) ;
        }
        else {
            ans.back()[1] = max ( ans.back()[1] , intervals[i][1]) ;
        }
    }

    return ans ;
}

void merge1(long long arr1[], long long arr2[], int n, int m) {

    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    vector<int> temp ;
    int i = 0 , j = 0 ;

    while ( i < m && j < n) {
        if ( nums1[i] > nums2[j] ) {
            temp.push_back(nums2[j]) ;
            j++ ;
        }
        else if ( nums1[i] < nums2[j] ) {
            temp.push_back(nums1[i]) ;
            i++ ;
        }
    }

    while ( i < m ) {
        temp.push_back(nums1[i]) ;
        i++ ;
    }

    while ( j < n ) {
        temp.push_back(nums2[j]) ;
        j++ ;
    }

    for ( int k = 0 ; k < m+n ; k++ ) {
        nums1[k] = temp[k] ;
    }

}

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size(); // size of the array

    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    long long val1 = S - SN;

    long long val2 = S2 - S2N;

    val2 = val2 / val1;

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

int merge3(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort1(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort1(arr, low, mid);  // left half
    cnt += mergeSort1(arr, mid + 1, high); // right half
    cnt += merge3(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    return mergeSort1(a, 0, n - 1);
}

void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

int countPairs(vector<int> &nums, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)nums[i] > 2 * (long long)nums[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &nums, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(nums, low, mid);  // left half
    cnt += mergeSort(nums, mid + 1, high); // right half
    cnt += countPairs(nums, low, mid, high); //Modification
    merge(nums, low, mid, high);  // merging sorted halves
    return cnt;
}

int reversePairs(vector<int>& nums) {
    int n = nums.size() ;
    return mergeSort(nums, 0, n - 1);
}

int maxProduct(vector<int>& nums) {
    int n = nums.size() ;
    int prefix = 1 ;
    int suffix = 1 ;
    int result = INT_MIN ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( prefix == 0 ) prefix = 1 ; 
        if ( suffix == 0 ) suffix = 1 ;
        prefix = prefix * nums[i] ;
        suffix = suffix * nums[n - i - 1] ;
        result = max ( result , max ( prefix , suffix )) ;
    }
    return result ;
}


int main () {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18},} ;

    vector<vector<int>> ans = merge(intervals) ;

    return (0) ;
}