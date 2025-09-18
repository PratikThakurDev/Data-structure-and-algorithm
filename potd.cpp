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
            Add[userId].insert{-priority , -taskId} ;
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

int main ( ) {

return 0;
}