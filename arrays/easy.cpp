#include <bits/stdc++.h>
using namespace std;

void findLargest ( int arr[] , int n ) {
    int maxEle = arr[0] ;
    for ( int i = 0 ; i < n ; i++) {
        if ( arr[i] > maxEle ) {
            maxEle = arr[i] ;
        }
    }
    cout<<maxEle;
}

bool isSorted ( int arr[] , int n) {

    if ( n < 2) return true ;

    for ( int i = 0 ; i < n-1 ; i++) {
        if ( arr[i] > arr[i+1] ) {
            return false ;

        }
    }
    return true ;
}

void findSecondLargest ( int arr[] , int n ) {

    if ( n < 2 ) {
        cout << "max value : " << arr[0] << endl;
        cout << "second max value : " << "No second element" << endl;
        return;
    }

    int maxEle = arr[0] ;
    int secondMax = INT_MIN ;

    for ( int i = 0 ; i < n ; i++) {
        if ( arr[i] > maxEle ) {
            secondMax = maxEle ;
            maxEle = arr[i] ;
        }
        else if ( arr[i] != maxEle && arr[i] > secondMax) {
            secondMax = arr[i] ;
        }
    }

    cout << "max value : " << maxEle << endl;

    if (secondMax == INT_MIN)
        cout << "second max value: No second element" << endl;
    else
        cout << "second max value: " << secondMax << endl;

}

void removeDuplicate( vector <int> &arr , int n) {
    int i = 0 ;
    for ( int j = 1 ; j < n ; j++) {
        if ( arr[i] != arr[j]) {
            arr[i+1] = arr[j] ;
            i++ ;
        }
    }
    cout<<"Number of unique elements in the array : "<< i+1 ;

}

void rotateLeft ( vector <int> &arr , int n , int k) {
    k = k % n ;
    reverse(arr.begin(), arr.begin() + (k));
    reverse(arr.begin() + (k), arr.end());
    reverse(arr.begin(), arr.end());

    for (auto it : arr) {
        cout << it << " " ;
    }
}

void rotateRight ( vector <int> &arr , int n , int k) {
    k = k % n ;
    reverse(arr.begin(), arr.begin() + (n - k));
    reverse(arr.begin() + (n - k), arr.end());
    reverse(arr.begin(), arr.end());

    for (auto it : arr) {
        cout << it << " " ;
    }
}

void zeroesAtEnd ( vector <int> &nums , int n ) {
    int j = -1 ;

    for ( int i = 0 ; i < n ; i++ ) {
        if ( nums[i] == 0 ) {
            j = i ;
            break ;
        }
    }

    if ( j == -1) return ;

    for ( int i = j+1 ; i < n ; i++) {
        if (nums[i] != 0) {
            swap(nums[i],nums[j]) ;
            j++ ;
        }
    }

    for ( auto it : nums) {
        cout<<it <<" " ;
    }
}

void search( vector <int> arr , int n ,int num) {
    for ( int i = 0 ; i < n ; i++) {
        if ( arr [i] == num ) {
            cout<< i ;
            return ;
        }
    }
    cout<<-1 ;
}

void unionOfArrays ( vector <int> arr1 , vector <int> arr2 , int n1 , int n2 ) {
    int i = 0 ;
    int j = 0 ;
    vector <int> final ;

    while ( i < n1 && j < n2) {
        if ( arr1[i] < arr2[j]) {
            final.push_back(arr1[i]) ;
            i++ ;
        }
        else if ( arr1[i] > arr2[j]) {
            final.push_back(arr2[j]) ;
            j++ ;
        }
        else {
            final.push_back(arr1[i]) ;
            i++ ;
            j++ ;
        } 
    }

    while ( i < n1) {
        final.push_back(arr1[i]) ;
        i++ ;
    }
    while ( j < n2) {
        final.push_back(arr2[j]) ;
        j++ ;
    }

    for (auto it : final) {
        cout << it << " " ;
    }
}

void missingNum( vector <int> nums , int n ) {
    int sumWithoutElement = 0 ;
    int sumWithElement = 0 ;
    for (int i = 0 ; i <= n ; i++) {
        if ( i < n ) {
            sumWithoutElement += nums[i] ;
            sumWithElement += i ;
        }
        else {
            sumWithElement += i ;
        }
    }

    cout<<"missing Element : " << sumWithElement-sumWithoutElement ;
}

void maxConsecutiveOnes ( vector <int> &nums ) {
    int n = nums.size() ;
    int maxCount = 0 ;
    int temp = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( nums[i] == 1) {
            temp++ ;
            maxCount = max(maxCount , temp) ;
        }
        else {
            temp = 0 ;
        }
    }
    cout<< maxCount ;
}

void singleNumber ( vector <int> &nums ) {
    int n = nums.size() ;
    // unordered_map <int , int> map ;
    // for ( int i = 0 ; i < n ; i++) {
    //     map[nums[i]]++ ;
    // }

    // for ( auto it : map) {
    //     if ( it.second == 1) {
    //         cout<<it.first ;
    //     }
    // }

    //Optimal approach
    int XOR = 0 ;
    for (int i = 0 ; i < n ; i++ ) {
        XOR = XOR^nums[i] ;
    }
    cout<< XOR ;
}

void longestSubarray ( vector <int > &nums , int k) {
    //Brute force
    int n = nums.size() ;
    int maxLength = 0 ;
    
    // for ( int i = 0 ; i < n ; i++ ) {
    //     int sum = 0 ;
    //     for ( int j = i ; j < n ; j++) {
    //         sum += nums[j] ;
    //         if ( sum == k ) {
    //             maxLength = max(maxLength,j-i+1) ;
    //         }
    //     }
    // }
    // cout << maxLength ;

    //Better approach for only positive using Hash map  (Optimal for positive and negative )

    // map<long long , int > preSumMap ;
    // int sum = 0 ;
    // int len = 0 ;
    // for ( int i = 0 ; i < n ; i++ ) {
    //     sum += nums[i] ;
        
    //     if ( sum == k ) {
    //         maxLength = max(maxLength, i+1) ;
    //     }
    //     long long rem = sum - k ;
    //     if ( preSumMap.find(rem) != preSumMap.end() ) {
    //         len = i - preSumMap[rem] ;
    //         maxLength = max(len , maxLength) ;
    //     }
    //     if ( preSumMap.find(sum) != preSumMap.end() ) {
    //         preSumMap[sum] = i ;
    //     } 
    // }
    // cout<<maxLength ;

    // optimal approach (only positives)

    int right ,  left = 0 ;
    long long sum = nums[0] ;

    while ( right < n ) {
        
        while ( sum > k && left<=right) {
            sum -= nums[left] ;
            left++ ;
        } 
    
        if ( sum == k ) {
            maxLength = max(maxLength , right - left + 1) ;
        }

        right++ ;

        if (right < n) {
            sum += nums[right] ;

        }
    }
    cout << maxLength ;
}


int main() {

    vector <int> nums = {1,1,2,3,3,4,4,4} ;
    vector <int> arr2 = {1,2,3,4,5,6} ;

    int n2 = arr2.size( ) ;
    longestSubarray( nums , 6) ;    

    return(0);
}