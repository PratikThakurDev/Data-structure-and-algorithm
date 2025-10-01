#include <bits/stdc++.h>
using namespace std ;

class StackUsingArray{
    int size ;
    int * arr ;
    int top ;
    public : 
    StackUsingArray (){
        top = -1 ;
        size = 1000 ;
        arr = new int[size] ;
    }
    void push(int x) {
        top++ ;
        arr[top] = x ;
    }
    int pop() {
        int x = arr[top] ;
        top-- ;
        return x ;
    }
    int Top() {
        return arr[top] ;
    }
    int Size () {
        return top + 1 ;
    }
} ;





int main ( ) {


return 0 ;
}