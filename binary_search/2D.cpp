#include <bits/stdc++.h> 
using namespace std ;

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int totalRows = matrix.size() ;
    int totalColumns = matrix[0].size() ;
    // Brute Force ;
    // for ( int row = 0 ; row < totalRows ; row++ ) {
    //     for ( int column = 0 ; column < totalColumns ; column++ ) {
    //         if ( matrix[row][column] == target ) return true ;
    //     }
    // }
    // return false ;

    //Better Approach ;
    // for ( int row = 0 ; row < totalRows ; row++ ) {
    //     if ( matrix[row][0] <= target && matrix[row][totalColumns - 1] >= target ) {
    //         int low = 0 , high = totalColumns - 1 ;
    //         while ( low <= high ) {
    //             int mid = ( low + high ) / 2 ;
    //             if ( matrix[row][mid] == target ) return true ;
    //             if ( matrix[row][mid] < target ) low = mid + 1 ;
    //             else high = mid - 1 ;
    //         }
    //     }
    // }
    // return false ;

    //Optimal approach ;
    int row = -1 ;

    int rlow = 0 , rhigh = totalRows - 1 ;
    while ( rlow <= rhigh ) {
        int mid = ( rlow + rhigh ) / 2 ;
        if ( matrix[mid][0] <= target && matrix[mid][totalColumns - 1] >= target ) {
            row = mid ;
            break ;
        }
        if ( matrix[mid][0] > target ) rhigh = mid - 1 ;
        else rlow = mid + 1 ;
    }

    if ( row == -1 ) return false ;

    int clow = 0 , chigh = totalColumns - 1 ;
    while ( clow <= chigh ) {
        int mid = ( clow + chigh ) / 2 ;
        if ( matrix[row][mid] == target ) return true ;
        if ( matrix[row][mid] < target ) clow = mid + 1 ;
        else chigh = mid - 1 ;
    }

    return false ;
}

bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int totalRows = matrix.size() ;
    int totalColumns = matrix[0].size() ;

    //optimal approach ;
    int row = 0 , column = totalColumns - 1 ;
    while ( row < totalRows && column >= 0 ) {
        if ( matrix[row][column] == target ) return true ;
        if ( matrix[row][column] < target ) row++ ;
        else column-- ;
    }
    return false ;
}

int findMaxEleRow ( vector<vector<int>>& mat , int m , int n , int col ) {

    int index = -1 ;
    int maxValue = -1 ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( mat[i][col] > maxValue ) {
            maxValue = mat[i][col] ;
            index = i ;
        }
    }
    return index ;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int totalRows = mat.size() ;
    int totalColumns = mat[0].size() ;
    int low = 0 , high = totalColumns - 1 ;
    while ( low <= high ) {
        int mid = ( low + high ) / 2 ;
        int row = findMaxEleRow(mat , totalColumns,totalRows , mid) ;
        int left = mid - 1 >= 0 ? mat[row][mid-1] : -1 ;
        int right = mid + 1 < totalColumns ? mat[row][mid+1] : -1 ;
        if ( mat[row][mid] > left && mat[row][mid] > right ) return {row , mid } ;
        if ( mat[row][mid] < left ) high = mid - 1;
        else {
            low = mid + 1 ;
        }
    }
    return { -1 , -1 } ;
}

int upperBound ( vector<int> & arr , int num ) {
    int n = arr.size( ) ;
    int low = 0 , high = n - 1 ;
    while ( low <= high ) {
        int mid = ( low + high ) / 2 ;
        if ( arr[mid] <= num ) low = mid + 1 ;
        else high = mid - 1 ;
    }
    return low ;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }
    
    while ( low <= high ) {
        int cnt = 0 ;
        int mid = ( low + high ) / 2 ;
        for ( int i = 0 ; i < m ; i++ ) {
            cnt += upperBound( matrix[i] , mid ) ;
        }
        if ( cnt <= (n*m)/2 ) low = mid + 1 ;
        else high = mid - 1 ;
    }
    return low ;
}

int main () {

    
return 0 ;
}