#include <bits/stdc++.h> 
using namespace std ;

int search(vector<int>& nums, int target) {

    int n = nums.size() ;
    int low = 0 ;
    int high = n - 1 ;


    while ( low <= high ) {
        int mid = (low + high) / 2 ;
        if ( nums[mid] == target ) return mid ;
        else if ( nums[mid] < target ) low = mid + 1 ;
        else high = mid - 1 ;
    }

    return -1 ;
}

int lowerBound(vector<int> arr, int x) {
    int n = arr.size() ;
    int ans = 10 ;
    int low = 0 , high = n - 1 ;
    while ( low <= high ) {
        int mid = (low + high) / 2 ;
        if ( arr[mid] >= x ) {
            ans = mid ;
            high = mid - 1 ;
        } 
        else {
            low = mid + 1 ;
        }
    }
    return ans ;
}

int upperBound(vector<int> arr, int x) {
    int n = arr.size() ;
    int ans = 10 ;
    int low = 0 , high = n - 1 ;
    while ( low <= high ) {
        int mid = (low + high) / 2 ;
        if ( arr[mid] > x ) {
            ans = mid ;
            high = mid - 1 ;
        } 
        else {
            low = mid + 1 ;
        }
    }
    return ans ;
}

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size() ;
    int low = 0 , high = n - 1 ;
    int ans = n ;
    while ( low <= high ) {
        int mid = (low + high ) / 2 ;
        if ( nums[mid] >= target ) {
            ans = mid ;
            high = mid - 1 ;
        }
        else {
            low = mid + 1 ;
        }
    }
    return ans ;
}

int findFloor(vector<int>& nums, int x) {
    int n = nums.size() ;
    int low = 0 , high = n - 1 ;
    int floor = x ; 
    while ( low <= high ) {
        int mid = (low + high) / 2 ;
        if ( nums[mid] <= x ) {
            floor = nums[mid] ;
            low = mid + 1 ;
        } else {
            high = mid - 1 ;
        }
    }
    return floor ;
}

int findCeil(vector<int>& nums, int x) {
    int n = nums.size() ;
    int low = 0 , high = n - 1 ;
    int ceil = x ; 
    while ( low <= high ) {
        int mid = (low + high) / 2 ;
        if ( nums[mid] < x ) {
            low = mid + 1 ;
        } else {
            ceil = nums[mid] ;
            high = mid - 1 ;
        }
    }
    return ceil ;
}

pair <int,int> getFloorAndCeil( vector<int>& nums , int x ) {
    int floor = findFloor(nums , x) ;
    int ceil = findCeil( nums , x ) ;
    return make_pair(floor , ceil) ;
}

int findFirstOccuringIndex( vector<int>& nums , int target) {
    int n = nums.size() ;
    int low = 0 , high = n - 1 ;
    int ind = -1 ;
    while ( low <= high ) {
        int mid = (low + high ) / 2 ;
        if ( nums[mid] == target ) {
            ind = mid ;
            high = mid - 1 ;
        }
        else if ( nums[mid] < target ) {
            low = mid + 1 ;
        }
        else {
            high = mid - 1 ;
        }
    }
    return ind ;
}

int findLastOccuringIndex( vector<int>& nums , int target) {
    int n = nums.size() ;
    int low = 0 , high = n - 1 ;
    int ind = -1 ;
    while ( low <= high ) {
        int mid = (low + high ) / 2 ;
        if ( nums[mid] == target ) {
            ind = mid ;
            low = mid + 1 ;
        }
        else if ( nums[mid] < target ) {

            low = mid + 1 ;
        }
        else {
            high = mid - 1 ;
        }
    }
    return ind ;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int firstOccuringIndex = findFirstOccuringIndex(nums , target) ;
    int lastOccuringIndex = findLastOccuringIndex(nums , target ) ;
    vector<int> ans = {firstOccuringIndex,lastOccuringIndex} ;
    return ans ;
}

int findRotation( vector<int>& nums ) {
    int n = nums.size() ;
    int rotations = 0 ;
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        if ( nums[i] > nums[i + 1] ) {
            rotations = i + 1 ;
            break ;
        }
    }
    return rotations ;
}

int searchInRotatedSortedArray(vector<int>& nums, int target) {
    // better approach ;
    // int rotations = findRotation( nums ) ;

    // sort(nums.begin() , nums.end() ) ;
    // int n = nums.size() ;
    // int low = 0 ;
    // int high = n - 1 ;

    // while ( low <= high ) {
    //     int mid = (low + high) / 2 ;
    //     if ( nums[mid] == target ) return (mid + rotations) % n ;
    //     else if ( nums[mid] < target ) low = mid + 1 ;
    //     else high = mid - 1 ;
    // }

    // return -1 ;

    //optimal
    int n = nums.size() ; 
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target) return mid;

        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else { 
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

bool searchInRotatedSortedArray2(vector<int>& nums, int target) {
    //  nlogn approach ;
    // int n = nums.size() ;
    // sort (nums.begin() , nums.end()) ;
    // int low = 0 , high = n - 1 ;
    // while ( low <= high ) {
    //     int mid = ( low + high ) / 2 ; 
    //     if ( nums[mid] == target ) return true ;
    //     if ( nums[mid] < target ) {
    //         low = mid + 1 ;
    //     }
    //     else {
    //         high = mid - 1 ;
    //     }
    // }
    // return false ;

    //logn approach ;
    int n = nums.size() ;
    int low = 0 , high = n - 1 ;
    while ( low <= high ) {
        int mid = ( low + high ) / 2 ;
        if ( nums[mid] == target ) return true ;
        if ( nums[low] == nums[mid] && nums[mid] == nums[high] ) {  // if all three positions have same elements  trim down the search space 
            low = low + 1 ;
            high = high - 1 ;
            continue ;
        }
        if ( nums[low] <= nums[mid] ) {     //left side is sorted 
            if ( nums[low] <= target && target <= nums[mid] ) {   //target present in the left side 
                high = mid - 1 ;
            }
            else {     // target present on the other side 
                low = mid + 1 ;
            }
        }
        else { //right side is sorted 
            if ( nums[mid] <= target && target <= nums[high] ) {  //target on the right side 
                low = mid + 1 ;
            }
            else {   //target on the other side 
                high = mid - 1 ;
            }
        }
    }
    return false ;
}

int findMin(vector<int>& nums) {
    int n = nums.size() ;
    int low = 0 , high = n - 1 ;
    int mini = INT_MAX ;
    while ( low <= high ) {
        int mid = ( low + high ) / 2 ;
        mini = min ( nums[mid] , mini) ;
        if ( nums[low] <= nums[mid] ) {
            mini = min ( nums[low] , mini ) ;
            low = mid + 1 ;
        }
        else {
            high = mid - 1 ;
        }  
    }
    return mini ;
}

int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else { //if right part is sorted:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            high = mid - 1;
        }
    }
    return index;
}

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size() ;
    int low = 0 , high = n - 1 ;

    if ( n == 1 ) return nums[0] ;
    if ( nums[low] != nums[low + 1] ) return nums[low] ;
    if ( nums[high] != nums[high - 1]) return nums[high] ;

    while ( low <= high ) {
        int mid = ( low + high ) / 2 ;

        if ( nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1] ) return nums[mid] ;

        if ( (mid % 2 == 0 && nums[mid] == nums[mid - 1]) || (mid % 2 == 1 && nums[mid] == nums[mid + 1]) ) {
            high = mid - 1 ;
        }

        else {
            low = mid + 1 ;
        }
    }
    return -1 ;

}

int findPeakElement(vector<int>& nums) {
    int n = nums.size() ;
    
    if ( n == 1 ) return 0 ;
    if ( nums[0] > nums[1] ) return 0 ;
    if ( nums[n - 1] > nums[n - 2] ) return n - 1 ;

    int low = 1 , high = n - 2 ;

    while ( low <= high ) {
        int mid = (low + high) / 2 ;
        if ( nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1] ) return mid ;
        if ( nums[mid - 1] > nums[mid] ) {
            high = mid - 1 ;
        }
        else {
            low = mid + 1 ;
        }
    }
    return -1 ;
}

int floorSqrt(int n) {
    int low = 1 , high = n ;
    int ans = 0 ;
    while ( low <= high ) {
        long long mid = ( low + high ) / 2 ;
        long long val = mid * mid ;
        if ( val <= (long long)(n) ) {
            ans = mid ;
            low = mid + 1 ;
        }
        else {
            high = mid - 1 ;
        }
    }
    return ans ;
}

int NthRoot(int n, int m) {
    int low = 1 , high = m ;
    while ( low <= high ) {
        int mid = ( low + high ) / 2 ;
        int val = pow( mid , n ) ;
        if ( val == m ) return mid ;
        if ( val > m ) {
            high = mid - 1 ;
        }
        else {
            low = mid + 1 ;
        }
    }
    return -1 ;
}

int findMax(const vector<int>& piles) {
    int maxi = INT_MIN;
    for (auto pile : piles) {
        maxi = max(maxi, pile);
    }
    return maxi;
}

long long calculateTotalHours(const vector<int>& piles, int hourly) {
    long long totalH = 0;
    for (auto pile : piles) {
        totalH += ceil(1.0 * pile / hourly);
    }
    return totalH;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = findMax(piles);
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long totalH = calculateTotalHours(piles, mid);
        if (totalH <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int findMaxDays(vector<int>& bloomDay) {
    int maxi = INT_MIN ;
    for ( auto it : bloomDay ) {
        maxi = max( maxi , it ) ;
    }
    return maxi ;
}

// int minDays(vector<int>& bloomDay, int m, int k) {
//     // brute force i thought of T.C -> O(N*MAXDAYS) ;
//     int n = bloomDay.size() ;
//     if ((long long)m * k > n) return -1;
//     int dayNumber = 1 ;
//     int maxDays = findMaxDays(bloomDay) ;
//     while ( dayNumber <= maxDays ) {
//         int adj = 0 ;
//         int bouqets = 0 ;
//         for (int i = 0 ; i < n ; i++ ) {
//             if ( dayNumber >= bloomDay[i] ) {
//                 adj++ ;
//             }
//             else {
//                 adj = 0 ;
//             }
//             if ( adj == k ) {
//                 bouqets++ ;
//                 adj = 0 ;
//             }
//         }
//         if ( bouqets >= m ) return dayNumber ;
//         dayNumber++ ;
//     }
//     return -1 ;
// }

bool possible(vector<int> &bloomDay, int day, int m, int k) {
    int n = bloomDay.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (bloomDay[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    long long val = m * 1ll * k * 1ll;
    int n = bloomDay.size(); //size of the bloomDay
    if (val > n) return -1; //impossible case.
    //find maximum and minimum:
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }

    //apply binary search:
    int low = mini, high = maxi;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(bloomDay, mid, m, k)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

// int smallestDivisor(vector<int>& nums, int threshold) {
    //brute force ;
    // int n = nums.size() ;
    // int maxi = INT_MIN ;
    // for ( int i = 0 ; i < n ; i++ ) {
    //     maxi = max( maxi , nums[i]) ;
    // }
    
    // for ( int i = 1 ; i <= maxi ; i++ ) {
    //     long long sum = 0 ;
    //     for ( int j = 0 ; j < n ; j++ ) {
    //         sum += ceil( (double)nums[j] / (double)i ) ;
    //     }
    //     if ( sum <= (long long) threshold ) {
    //         return i ;
    //     }
    // }
    // return -1;
// }

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if (n > limit) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

// int findMax(const vector<int>& piles) {
//     int maxi = INT_MIN;
//     for (auto pile : piles) {
//         maxi = max(maxi, pile);
//     }
//     return maxi;
// }

// long long sumOfAll( vector<int> &weights ) {
//     long long sum = 0 ;
//     for ( auto it : weights ) {
//         sum += it ;
//     }
//     return sum ;
// }

// int shipWithinDays(vector<int>& weights, int days) {
//     int n = weights.size() ;
//     long long sum = 0 ;
//     int dayNo = 1 ;
//     long long maxCap = sumOfAll(weights) ;
//     long long leastCap = findMax(weights) ;
//     while ( leastCap <= (int)maxCap) {

//         for ( int i = 0 ; i < n ; i++ ) {
//             if ( sum + weights[i] > leastCap ) {
//                 dayNo++ ;
//                 sum = weights[i] ;
//             }
//             else if (sum == leastCap ) {
//                 sum = 0 ;
//                 dayNo++ ;
//             }
//             else {
//                 sum += weights[i];
//             }
//         }

//         if (sum == leastCap ) {
//                 sum = 0 ;
//                 dayNo++ ;
//         }

//         if ( dayNo <= days ) {
//             return leastCap ;
//         }
//         leastCap++ ;
//     }
//     return -1 ;
// }

int findDays(vector<int> &weights, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); //size of array.
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    //Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid);
        if (numberOfDays <= d) {
            //eliminate right half
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
}

int missingK(vector < int > vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
}

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); //size of array
    int cntCows = 1; //no. of cows placed
    int last = stalls[0]; //position of last placed cow.
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; //place next cow.
            last = stalls[i]; //update the last location.
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size(); //size of array
    //sort the stalls[]:
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    //apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}

int countStudents ( vector<int > &arr , int pages ) {
    int n = arr.size() ;
    long long pagesStudent = 0 ;
    int students = 1 ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( pagesStudent + arr[i] <= pages ) {
            pagesStudent += arr[i] ;
        }
        else {
            pagesStudent = arr[i] ;
            students++ ;
        }
    }
    return students ;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int partitions = countPartitions(a, mid);
        if (partitions > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

// long double minimiseMaxDistance(vector<int> &arr, int k) {
//     int n = arr.size(); 
//     vector <int> howMany (n-1 , 0) ;

//     for ( int gasStations = 1 ; gasStations <= k ; gasStations++) {
//         int maxInd = -1 ;
//         int maxSecLength = 0 ;
//         Brute force approach ;
//         for ( int i = 0 ; i < n - 1 ; i++ ) {
//             double diff = arr[i + 1] - arr[i] ; 
//             double secLength = diff / double (howMany[i]+1) ;
//             if ( secLength > maxSecLength ) {
//                 maxSecLength = secLength ;
//                 maxInd = i ;
//             }
//         }
//         howMany[maxInd] ++ ;  
//     }

//     double maxAns = -1 ;
//     for ( int i = 0 ; i < n - 1 ; i++ ) {
//         double diff = arr[i + 1] - arr[i] ;
//         double secLength = diff / double( howMany[i] + 1) ;
//         maxAns = max ( secLength , maxAns ) ;
//     }
//     return maxAns ;
// }

int gasStationsReq ( vector <int> & arr , long double dist ) {
    int n = arr.size() ;
    int cnt = 0 ;
    for ( int i = 0 ; i < n - 1 ; i++ ) {
        int numberInBetween = (arr[i + 1] - arr[i]) / dist ;
        if ( arr[i + 1] - arr [i] == numberInBetween * dist ) {
            numberInBetween-- ;
        }
        cnt += numberInBetween ;
    }
    return cnt ;
}
    
long double minimiseMaxDistance ( vector<int> & arr , int k ) {
    int n = arr.size () ;
    long double low = 0 , high = 0 ;
    for ( int i = 0 ; i < n - 1 ; i ++) {
        long double dist = arr[i+1] - arr[i] ;
        high = max ( high , dist ) ;
    }

    while ( high - low > 1e-6) {
        long double mid = (low + high) / 2.0 ;
        int cnt = gasStationsReq( arr , mid ) ;
        if ( cnt > k ) {
            low = mid ;
        }
        else {
            high = mid ;
        }
    }
    return high ;
}

// brute force ;
// double median(vector<int>& a, vector<int>& b) {
//     int n = a.size(), m = b.size();
//     int ind1 = 0, ind2 = 0;
//     vector<int> temp;

//     while (ind1 < n && ind2 < m) {
//         if (a[ind1] <= b[ind2]) {
//             temp.push_back(a[ind1++]);
//         } else {
//             temp.push_back(b[ind2++]);
//         }
//     }
//     while (ind1 < n) temp.push_back(a[ind1++]);
//     while (ind2 < m) temp.push_back(b[ind2++]);

//     int total = n + m;
//     if (total % 2 == 0) {
//         return (temp[total/2 - 1] + temp[total/2]) / 2.0;
//     } else {
//         return temp[total/2];
//     }
// }

// better approach ;
// double median ( vector<int> & a , vector <int> & b ) {
//     int n1 = a.size () , n2 = b.size() ;
//     int n = n1 + n2 ;
//     int ind1 = n / 2 , ind2 = ind1 - 1 ;
//     int ind1el = -1 , ind2el = -1 ;
//     int i = 0 , j = 0 ;
//     int cnt = 0 ;

//     while ( i < n1 && j < n2 ) {
//         if ( a[i] <= b[j] ) {
//             if ( cnt == ind1 ) ind1el = a[i] ;
//             if ( cnt == ind2 ) ind2el = a[i] ;
//             cnt++ ;
//             i++ ;
//         }
//         else {
//             if ( cnt == ind1 ) ind1el = b[j] ;
//             if ( cnt == ind2 ) ind2el = b[j] ;
//             cnt ++ ;
//             j++ ;
//         }
//     }

//     while ( i < n1 ) {
//         if (cnt == ind1) ind1el = a[i];
//         if (cnt == ind2) ind2el = a[i];
//         cnt++;
//         i++;
//     }

//     while ( j < n2 ) {
//         if ( cnt == ind1 ) ind1el = b[j] ;
//         if ( cnt == ind2 ) ind2el = b[j] ;
//         j ++ ;
//         cnt ++ ;
//     }

//     if ( n % 2 == 0) return double((ind1el + ind2el) / 2.0) ;
//     else return double ( ind2el ) ;

// }

// optimal approach ;
double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median(b, a);

    int n = n1 + n2; 
    int left = (n1 + n2 + 1) / 2; //length of left half

    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; 
}

int kthElement(vector<int> &a, vector<int> & b , int m , int n , int k ) {
    if ( m > n ) return kthElement(b , a , n , m , k ) ;

    int left = k ;
    int low = max( 0 , k - n ), high = min ( k , m ) ;
    while ( low <= high ) {
        int mid1 = (low + high ) / 2 ;
        int mid2 = left - mid1 ;
        int l1 = INT_MIN , l2 = INT_MIN ;
        int r1 = INT_MAX , r2 = INT_MAX ;
        if ( mid1 < m ) r1 = a[mid1] ;
        if ( mid2 < n ) r2 = b[mid2] ;
        if ( mid1 - 1 >= 0 ) l1 = a[mid1 - 1] ;
        if ( mid2 - 1 >= 0 ) l2 = b[mid2 - 1] ;
        if ( r1 >= l1 && r2 >= l2 ) return max (l1 , l2 ) ;
        else if ( r2 < l1 ) high = mid1 - 1 ; 
        else low = mid1 + 1 ;
    }
    return 0 ;
}

int main () {

    vector<int> nums = { 4,5,6,7,0,1,2 } ;
    vector<int> bloomDay = {7,7,7,7,12,7,7} ;
    cout << minDays(bloomDay , 2 , 3);

    return 0 ;
}