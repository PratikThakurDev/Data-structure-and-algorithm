#include <bits/stdc++.h> 
using namespace std ;
 
vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ans ;
    for ( int num : nums ) {
        while ( !ans.empty() ) {
            int prev = ans.back() ;
            int curr = num ;
            int GCD = gcd( prev , curr ) ;
            if ( GCD == 1 ) {
                break ;
            }
            ans.pop_back() ;
            int lcm = (prev/GCD) * curr ;
            num = lcm ;
        }
        ans.push_back( num ) ;
    }

    return ans ;
}

class FoodRatings {
public : 
    unordered_map<string , set<pair<int, string>>> cuisineToFoods ;
    unordered_map<string , pair<int, string >> foodInfo ;

    FoodRatings ( vector<string> & foods , vector<string>& cuisines, vector<int> & ratings ) {
        for (int i = 0 ; i < foods.size() ; i++ ) {
            string food = foods[i] ;
            string cuisine = cuisines[i] ;
            int rating = ratings[i] ;
            cuisineToFoods[cuisine].insert( {-rating , food }) ;
            foodInfo[food] = {rating , cuisine } ;
        }
    }

    void changeRating( string food , int newRating) {
        auto [oldRating , cuisine ] = foodInfo[food] ;
        cuisineToFoods[cuisine].erase({-oldRating , food }) ;
        cuisineToFoods[cuisine].insert( {-newRating , food }) ;
        foodInfo[food] = {newRating , cuisine } ;
    }

    string highestRated( string cuisine ) {
        return cuisineToFoods[cuisine].begin()->second ;
    }

} ;

class TaskManager {
public:

    unordered_map< int , set<pair<int , int >>> Add ;
    unordered_map< int , pair<int , int >> taskInfo ;
    set< pair<int,int> > taskList ;
    TaskManager(vector<vector<int>>& tasks) {
        for ( int i = 0 ; i < tasks.size() ; i++ ) {
            int userId = tasks[i][0] ;
            int taskId = tasks[i][1] ;
            int priority = tasks[i][2] ;
            Add[userId].insert({-priority , -taskId}) ;
            taskInfo[taskId] = {userId , priority } ;
            taskList.insert( {-priority , -taskId}) ;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        Add[userId].insert({-priority , -taskId })  ;
        taskInfo[taskId] = {userId , priority } ;
        taskList.insert({-priority , -taskId }) ;
    }
    
    void edit(int taskId, int newPriority) {
        int oldPriority = taskInfo[taskId].second ;
        taskInfo[taskId].second = newPriority ;
        int user = taskInfo[taskId].first ;
        auto& mySet = Add[user] ;
        taskList.erase({-oldPriority , -taskId}) ;
        taskList.insert({-newPriority , -taskId}) ;
        mySet.erase({-oldPriority , -taskId}) ;
        mySet.insert({-newPriority , -taskId}) ;
    }
    
    void rmv(int taskId) {
        int userId = taskInfo[taskId].first ;
        int priority = taskInfo[taskId].second ;
        auto& mySet = Add[userId ] ;
        mySet.erase({-priority , -taskId}) ;
        taskInfo.erase(taskId) ;
        taskList.erase({-priority , -taskId}) ;
    }
    
    int execTop() {
        if ( taskList.empty()) return -1 ;
        int taskId = -taskList.begin()->second ;
        int userId = taskInfo[taskId].first ;
        rmv( taskId ) ;
        return userId ;
    }
};

class Spreadsheet {
public:

    unordered_map<int ,vector<int>> spreadSheet ;
    Spreadsheet(int rows) {
        for ( int i = 0 ; i < 26 ; i++ ) {
            spreadSheet[i] = vector<int> (rows , 0) ;
        }
    }
    
    void setCell(string cell, int value) {
        spreadSheet[cell[0]-'A'][stoi(cell.substr(1)) - 1] = value ;
    }
    
    void resetCell(string cell) {
        spreadSheet[cell[0]-'A'][stoi(cell.substr(1)) - 1] = 0 ; 
    }
    
    int getValue(string formula) {
        formula = formula.substr(1) ;
        int operatorPos = formula.find('+') ;
        int val1 ;
        int val2 ;
        string part1 = formula.substr(0,operatorPos) ;
        string part2 = formula.substr(operatorPos + 1 ) ;
        if ( isalpha(part1[0])) {
            val1 = spreadSheet[part1[0]-'A'][stoi(part1.substr(1)) - 1] ;
        } else val1 = stoi(part1) ;
        if ( isalpha(part2[0])) {
            val2 = spreadSheet[part2[0]-'A'][stoi(part2.substr(1)) - 1] ;
        } else val2 = stoi(part2) ;
        return val1 + val2 ;
    }
};

class Router {
private:
    int maxCapacity;
    deque<vector<int>> packetQueue;
    unordered_set<string> existingPackets;
    unordered_map<int, vector<int>> destinationToTimestamps;

    string makePacketKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        maxCapacity = memoryLimit ;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string packetKey = makePacketKey(source, destination, timestamp);
        if (existingPackets.find(packetKey) != existingPackets.end()) {
            return false;
        }

        if (packetQueue.size() == maxCapacity) {
            vector<int>& oldestPacket = packetQueue.front();
            string oldestKey = makePacketKey(oldestPacket[0], oldestPacket[1], oldestPacket[2]);

            existingPackets.erase(oldestKey);

            auto& timestamps = destinationToTimestamps[oldestPacket[1]];
            auto it = lower_bound(timestamps.begin(), timestamps.end(), oldestPacket[2]);
            if (it != timestamps.end() && *it == oldestPacket[2]) {
                timestamps.erase(it);
            }

            packetQueue.pop_front();
        }

        packetQueue.push_back({source, destination, timestamp});
        existingPackets.insert(packetKey);
        destinationToTimestamps[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetQueue.empty()) {
            return {};
        }

        vector<int> oldestPacket = packetQueue.front();
        packetQueue.pop_front();

        string packetKey = makePacketKey(oldestPacket[0], oldestPacket[1], oldestPacket[2]);
        existingPackets.erase(packetKey);

        auto& timestamps = destinationToTimestamps[oldestPacket[1]];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), oldestPacket[2]);
        if (it != timestamps.end() && *it == oldestPacket[2]) {
            timestamps.erase(it);
        }

        return oldestPacket;
    }

    int getCount(int destination, int startTime, int endTime) {
        if (destinationToTimestamps.find(destination) == destinationToTimestamps.end()) {
            return 0;
        }

        const auto& timestamps = destinationToTimestamps[destination];
        auto lower = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto upper = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        return distance(lower, upper);
    }
};

class MovieRentingSystem {
private:
    unordered_map<int, set<vector<int>>> unrentedMovies;
    set<vector<int>> rentedMovies;
    map<pair<int, int>, int> priceLookup;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (const auto& entry : entries) {
            int shop = entry[0], movie = entry[1], price = entry[2];
            unrentedMovies[movie].insert({price, shop});
            priceLookup[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        int count = 0;
        for (const auto& info : unrentedMovies[movie]) {
            result.push_back(info[1]);
            if (++count == 5) break;
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = priceLookup[{shop, movie}];
        unrentedMovies[movie].erase({price, shop});
        rentedMovies.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceLookup[{shop, movie}];
        rentedMovies.erase({price, shop, movie});
        unrentedMovies[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        int count = 0;
        for (const auto& rental : rentedMovies) {
            result.push_back({rental[1], rental[2]});
            if (++count == 5) break;
        }
        return result;
    }
};

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int,int> freqMap ;
    for (int num : nums) {
        freqMap[num] += 1 ;
    }

    int maxFreq = 0 ;
    for (auto it : freqMap) {
        if (it.second > maxFreq) {
            maxFreq = it.second ;
        }
    }

    int total = 0 ;
    for (auto it : freqMap) {
        if (it.second == maxFreq) total += maxFreq ;
    }
    return total ;
}

int compareVersion(string version1, string version2) {
    vector<int> v1, v2;
    size_t pos = 0, found;

    while ((found = version1.find('.', pos)) != string::npos) {
        v1.push_back(stoi(version1.substr(pos, found - pos)));
        pos = found + 1;
    }
    v1.push_back(stoi(version1.substr(pos)));

    pos = 0;
    while ((found = version2.find('.', pos)) != string::npos) {
        v2.push_back(stoi(version2.substr(pos, found - pos)));
        pos = found + 1;
    }
    v2.push_back(stoi(version2.substr(pos)));

    int n = max(v1.size(), v2.size());
    for (int i = 0; i < n; ++i) {
        int num1 = i < (int)v1.size() ? v1[i] : 0;
        int num2 = i < (int)v2.size() ? v2[i] : 0;
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
    }
    return 0;
}

string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) return "0";
    string ans;
    if ((numerator < 0) ^ (denominator < 0)) ans += '-';
    long long n = abs((long long)numerator);
    long long d = abs((long long)denominator);
    ans += to_string(n / d);
    n %= d;
    if (n == 0) return ans;
    ans += '.';
    unordered_map<long long, int> pos;
    string frac;
    while (n != 0) {
        if (pos.count(n)) {
            frac.insert(pos[n], "(");
            frac += ")";
            break;
        }
        pos[n] = frac.size();
        n *= 10;
        frac += to_string(n / d);
        n %= d;
    }
    return ans + frac;
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(triangle.back()); // Initialize dp with last row elements

    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col <= row; col++) {
            dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
        }
    }
    return dp[0];
}

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int k = n - 1; k >= 2; --k) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                count += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }
    return count;
}

double euclidConstants ( vector<int> point1 , vector<int> point2 ) {
    int x = point1[0] - point2[0] ;
    int y = point1[1] - point2[1] ;
    return sqrt(x*x + y*y) ;
}

bool isValidTriangle ( double a , double b , double c ) {
    return a + b > c && a + c > b && b + c > a ;
}

double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size() ;
    double maxArea = 0 ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = i + 1 ; j < n ; j++ ) {
            for ( int k = j + 1 ; k < n ; k++ ) {
                double a = euclidConstants( points[i] , points[j]) ;
                double b = euclidConstants( points[j] , points[k]) ;
                double c = euclidConstants( points[k] , points[i]) ;
                if ( ! (isValidTriangle( a , b , c))) continue ;
                double s = (a + b + c ) / 2 ;
                maxArea = max ( maxArea , sqrt(s*(s-a)*(s-b)*(s-c))) ;
            }
        }
    }
    return maxArea ;
}

// int largestPerimeter(vector<int>& nums) {
//     int n = nums.size() ;
//     int i = 0 , j = 1 , k = 2 ;
//     int maxPeri = 0 ;
//     for ( int i = 0 ; i < n ; i++ ) {
//         for ( int j = i + 1 ; j < n ; j++ ) {
//             for ( int k = j + 1 ; k < n ; k++ ) {
//                 int a = nums[i] ;
//                 int b = nums[j] ;
//                 int c = nums[k] ;
//                 if ( isValidTriangle(a,b,c) ) {
//                     int peri = a + b + c ;
//                     maxPeri = max ( maxPeri , peri ) ;
//                 }
//             }
//         }

//     }
//     return maxPeri ;
// }

int largestPerimeter ( vector<int>& nums ) {
    int n = nums.size() ;
    int maxPeri = 0 ;
    for (int k = n - 1; k >= 2; --k) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                int peri = nums[i] + nums[j] + nums[k] ;
                maxPeri = max ( maxPeri , peri ) ;
                j--;
            } else {
                i++;
            }
        }
    }
    return maxPeri ;
}

int main ( ) {

return 0;
}