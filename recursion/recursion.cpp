#include <bits/stdc++.h>
using namespace std;

void solve1(int n) {
    if ( n <= 0) return;
    cout<<"hello"<<" ";
    solve1(n-1);
}

void solve3(int i ,int n) {
    if (i > n) return ;
    cout<<i<<" ";
    solve3(i+1,n);
}

void solve4(int n) {
    if (n < 1) return;
    cout<<n;
    solve4(n-1);
}

void getSum(int sum , int n) {
    if ( n < 0) {
        cout<<sum;
        return;
    } 
    getSum(sum+n,n-1);
}

void getfactorial(int factorial , int n) {
    if ( n < 1) {
        cout<<factorial;
        return;
    } 
    getfactorial(factorial*n,n-1); 
}

void reverseArray(int arr[],int start , int end , int n) {
    if ( start < end ) {
        swap(arr[start],arr[end]);
        reverseArray(arr,start+1,end-1,n);
    }
    else {
        for (int i = 0 ; i < n ; i++) {
            cout<<arr[i]<<" ";
        }
    }
}

bool isPalindrome(std::string &s) {
    string filtered;

    for (char ch : s) {
        if (isalnum(ch)) {
            filtered += tolower(ch);
        }
    }

    for (int i = 0; i < filtered.length() / 2; i++) {
        if (filtered[i] != filtered[filtered.length() - i - 1])
            return false;  
    }

    return true;  
}

int fib(int n) {
  if (n<=1) return n;

  int last = fib(n-1);
  int slast = fib(n-2);
  return last + slast;
}

//Subsequences 

int atoiHelper ( string s , int index , long long currentValue, int sign ) {
    if ( s.size() == index || !(isdigit(s[index])) ) return currentValue ;
    int digit = s[index] - '0' ;
    if (sign == 1) {
        if (currentValue > ((long long)(INT_MAX) - digit) / 10) {
            return INT_MAX;
        }
    } else {
        if (currentValue > ((long long )((-(long long)INT_MIN) - digit) / 10)) {
            return (long long)(-(long long)INT_MIN); 
        }
    }
    
    currentValue = currentValue * 10 + digit ;

    return ( atoiHelper ( s , index + 1 , currentValue , sign )) ;
}


int myAtoi ( string s ) {
    int sign = 1;
    int start_index = 0;
    while (start_index < s.length() && isspace(s[start_index])) {
        start_index++;
    }

    if (start_index == s.length()) return 0;

    if (s[start_index] == '-') {
        sign = -1;
        start_index++;
    } else if (s[start_index] == '+') {
        start_index++;
    }

    if (start_index == s.length() || !isdigit(s[start_index])) {
        return 0;
    }

    long long result = atoiHelper(s, start_index, 0 , sign );

    if (sign == -1 && result == (long long)(-(long long)INT_MIN)) {
        return INT_MIN;
    }
    if (sign == 1 && result == INT_MAX) {
        return INT_MAX;
    }
    return (int)(sign * result) ;
}

void backtrack( int n , int openCount , int closeCount , string current , vector<string > &result ) {
    if ( current.length() == 2*n ) {
        result.push_back( current ) ;
    }

    if ( openCount < n ) {
        backtrack( n , openCount + 1 , closeCount , current + '(' , result ) ;
    }

    if ( closeCount < openCount ) {
        backtrack ( n , openCount  , closeCount + 1 , current + ')' , result ) ;
    }

}

vector <string > generateParanthesis ( int n ) {
    vector <string > result ;
    backtrack( n , 0 , 0 , "" , result );
    return result ;
}

void backtrack2 ( vector<int>& nums , int index , int n , vector<int> subset , vector<vector<int>> &ans ) {
    if ( index >= n ) {
        ans.push_back( subset ) ;
        return ;
    }
    subset.push_back( nums[index ] ) ;
    backtrack2 ( nums , index + 1 , n , subset , ans ) ;
    subset.pop_back(  ) ;
    backtrack2 ( nums , index + 1 , n , subset , ans ) ;
} 

vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size() ;
    vector<vector<int>> ans ;
    vector<int> subset ;
    backtrack2( nums ,0, n , subset , ans ) ;
    return ans ;
}

// for all subsets having their sum equal to target 
void backtrack3 ( vector<int>& nums , int index , int n , vector<int> subset , vector<vector<int>> &ans , long long s , long long &sum ) {
    if ( index >= n ) {
        if ( s == sum ) {
        ans.push_back( subset ) ;
        }
        return ;
    }
    subset.push_back( nums[index ] ) ;
    s += nums[index] ;
    backtrack3 ( nums , index + 1 , n , subset , ans , s , sum ) ;
    s -= nums[index] ;
    subset.pop_back(  ) ;
    backtrack3 ( nums , index + 1 , n , subset , ans ,s , sum ) ;
} 

vector<vector<int>> subsets2(vector<int>& nums , long long sum ) {
    int n = nums.size() ;
    vector<vector<int>> ans ;
    vector<int> subset ;
    backtrack3( nums ,0, n , subset , ans , 0, sum ) ;
    return ans ;
}

// for only one subset having sum equal to target 
bool backtrack4 ( vector<int>& nums , int index , int n , vector<int> subset , vector<vector<int>> &ans , long long s , long long &sum ) {
    if ( index >= n ) {
        if ( s == sum ) {
        ans.push_back( subset ) ;
        return true ;
        }
        return false ;
    }
    subset.push_back( nums[index ] ) ;
    s += nums[index] ;
    if (backtrack4 ( nums , index + 1 , n , subset , ans , s , sum ) == true ) return true ;
    s -= nums[index] ;
    subset.pop_back(  ) ;
    if (backtrack4 ( nums , index + 1 , n , subset , ans , s , sum ) == true ) return true ;
    
    return false ;
} 

vector<vector<int>> subsets3(vector<int>& nums , long long sum ) {
    int n = nums.size() ;
    vector<vector<int>> ans ;
    vector<int> subset ;
    backtrack4( nums ,0, n , subset , ans , 0, sum ) ;
    return ans ;
}

int search ( vector<int> candidates , int x ) {
    int n = candidates.size() ;
    for ( int i = 0 ; i < n ; i++ ) {
        if ( candidates[i] == x ) return i ;
    }
    return -1 ;
}

void findCombinations ( vector<int>& candidates , int target , int n , int index , vector<int> combination , vector<vector<int>> &ans) {
    if ( index == n ) {
        if ( target == 0 ) {
            ans.push_back( combination ) ;
        }
        return ;
    }

    if ( candidates[index] <= target ) {
        combination.push_back( candidates[index]) ;
        findCombinations ( candidates , target - candidates[index] , n , index , combination , ans );
        combination.pop_back() ;
    }
    findCombinations ( candidates , target , n , index + 1 , combination , ans ) ;

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> ans ;
    int n = candidates.size() ;
    vector<int> combination ;
    findCombinations ( candidates , target , n , 0 , combination , ans ) ;
    return ans ;
}

void findCombinations2(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombinations2(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombinations2(0, target, candidates, ans, ds);
  return ans;
}

void subsetSumsHelper ( int ind , vector<int>& arr , vector<int> &ans , int sum , int n ) {
    if ( n == ind ) {
        ans.push_back( sum ) ;
        return ;
    } 
    subsetSumsHelper ( ind + 1 , arr, ans , sum + arr[ind] , n ) ;
    subsetSumsHelper ( ind + 1 , arr, ans , sum , n ) ;
}

vector < int > subsetSums(vector < int > arr, int n) {
    vector<int> ans ;
    subsetSumsHelper ( 0 , arr,  ans , 0 , n) ;
    sort( ans.begin() , ans.end() ) ;
    return ans ;
}

void subsetWithDupHelper ( int n , int ind , vector<int> &nums , vector<vector<int>> &ans , vector<int> &ds ) {
    ans.push_back( ds ) ;
    for ( int i = ind ; i < n ; i++ ) {
        if ( i != ind && nums[i] == nums[i - 1]) continue ;
        ds.push_back( nums[i] ) ;
        subsetWithDupHelper ( n , i + 1 , nums , ans , ds ) ;
        ds.pop_back() ;
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size() ;
    vector<vector<int>> ans ;
    vector<int> ds ;
    sort( nums.begin() , nums.end() ) ;
    subsetWithDupHelper( n , 0 , nums , ans , ds ) ;
    return ans ;
}

void findCombinations3 ( int ind , vector<int>& nums , int length , int target , vector<int> &ds , vector<vector<int>> &ans ) {
    if ( ind == 9 ) {
        if ( target == 0 && length == 0 ) {
            ans.push_back( ds ) ;
        }
        return ;
    }

    if ( length != 0 && target >= nums[ind] ) {
        ds.push_back( nums[ind]) ;
        findCombinations3 ( ind + 1 , nums , length - 1 , target - nums[ind] , ds , ans ) ;
        ds.pop_back() ;
    }
    findCombinations3 ( ind + 1 , nums , length , target , ds , ans ) ;

}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans ;
    vector<int> ds ;
    vector<int> nums = {1,2,3,4,5,6,7,8,9} ;
    findCombinations3 ( 0 ,nums , k , n , ds ,ans );
    return ans ;
}

void backtrack6 ( int n ,string &s , vector<string> &ans , vector<string> &mapping , int ind , string current ) {
    if ( s.empty () ) return ;
    if ( ind == n ) {
        ans.push_back( current ) ;
        return ;
    }
    string letters = mapping[s[ind] - '0'] ;
    for ( char c : letters ) {
        current.push_back(c) ;
        backtrack6 ( n , s , ans , mapping , ind + 1 , current ) ;
        current.pop_back() ;
    }

}

vector<string> letterCombinations ( string s ) {
    int n = s.size() ;
    vector<string> mapping = {
        "",    "",    "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> ans ;
    string current ;
    backtrack6 ( n, s , ans , mapping , 2 , current ) ;
    return ans ;
}

bool isPalindrome ( string &s , int left , int right ) {

    while ( left <= right ) {
        if ( s[left] != s[right] ) {
            return false ;
        }
        left++ ;
        right-- ;
    }
    return true ;
}

void partitionHelper ( int index , vector<vector<string>> & ans , vector<string> &ds , string &s , int n ) {
    if ( index == n ) {
        ans.push_back( ds ) ;
        return ;
    }
    for ( int i = index ; i < n ; i++ ) {
        if ( isPalindrome ( s , index , i )) {
            ds.push_back(s.substr(index , i - index +1  ) ) ;
            partitionHelper ( i + 1 , ans , ds , s , n) ;
            ds.pop_back() ;
        }
    }
}

vector<vector<string>> partition(string s) {
    int n = s.size() ;
    vector<vector<string>> ans ;
    vector<string> ds ;
    partitionHelper(0 , ans , ds ,s , n) ;
    return ans ;
}

bool dfs(string &word, vector<vector<char>> &board, int row, int col, int index) {
    if (index == word.size()) return true;

    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index])
        return false;

    char temp = board[row][col];
    board[row][col] = '#';  

    bool found = dfs(word, board, row + 1, col, index + 1) ||
                 dfs(word, board, row - 1, col, index + 1) ||
                 dfs(word, board, row, col + 1, index + 1) ||
                 dfs(word, board, row, col - 1, index + 1);

    board[row][col] = temp; 
    return found;
}

bool exist(vector<vector<char>> &board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dfs(word, board, i, j, 0)) return true;
        }
    }
    return false;
}

bool isSafe(int row, int col, vector < string > board, int n) {
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0) {
    if (board[row][col] == 'Q')
        return false;
    row--;
    col--;
    }

    col = dupcol;
    row = duprow;
    while (col >= 0) {
    if (board[row][col] == 'Q')
        return false;
    col--;
    }

    row = duprow;
    col = dupcol;
    while (row < n && col >= 0) {
    if (board[row][col] == 'Q')
        return false;
    row++;
    col--;
    }
    return true;
}

void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
    if (col == n) {
    ans.push_back(board);
    return;
    }
    for (int row = 0; row < n; row++) {
    if (isSafe(row, col, board, n)) {
        board[row][col] = 'Q';
        solve(col + 1, board, ans, n);
        board[row][col] = '.';
    }
    }
}

vector < vector < string >> solveNQueens(int n) {
    vector < vector < string >> ans;
    vector < string > board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
    board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}

bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;

    if (board[row][i] == c)
      return false;

    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  return true;
}

bool solveSudoku(vector < vector < char >> & board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {
          if (isValid(board, i, j, c)) {
            board[i][j] = c;

            if (solveSudoku(board))
              return true;
            else
              board[i][j] = '.';
          }
        }

        return false;
      }
    }
  }
  return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fib(5);

    return 0;
}
