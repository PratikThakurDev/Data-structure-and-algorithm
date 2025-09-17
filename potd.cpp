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

int main ( ) {

return 0;
}