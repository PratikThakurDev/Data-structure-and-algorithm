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
    StackUsingArray ( int size ) {
        top = -1 ;
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

class QueueUsingArray{
    int maxSize ;
    int start ;
    int end ;
    int * arr ;
    int currSize ;
    public :

    QueueUsingArray() {
        int maxSize = 1000 ;
        arr = new int[maxSize] ;
        end = -1 , start = -1, currSize = 0 ;
    }

    QueueUsingArray( int maxSize ) {
        (*this).maxSize = maxSize ;
        arr = new int[maxSize] ;
        end = -1 , start = -1, currSize = 0 ;
    }

    void push ( int newElement) {
        if ( currSize == maxSize ) {
            cout << "Queue is full " ;
        }
        if ( end == -1 ) {
            start = 0 , end = 0 ;
        } else {
            end = ( end + 1 ) % maxSize ;
            arr[end] = newElement ;
            currSize++ ;
        }
    }

    int pop () {
        if ( start == -1 ) {
            cout << "queue empty" ;
        }
        int popped = arr[start] ;
        if ( currSize == 1) {
            start = -1 , end = -1 ;
        } else {
            start = ( start + 1 ) % maxSize ;
            currSize-- ;
            return popped ;
        }
    }

    int top () { 
        if ( start == -1 ) {
            cout << " Queue empty " ;
        }
        return arr[start] ;
    }
    int size () {
        return currSize ;
    }
} ;

class MyStack {
public:
    queue <int> q ;
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size() ;
        q.push(x) ;
        for ( int i = 0 ; i < s ; i++ ) {
            q.push( q.front()) ;
            q.pop() ;
        }
    }
    
    int pop() {
        int popped = q.front() ;
        q.pop() ;
        return popped ;
    }
    
    int top() {
        return q.front() ;
    }
    
    bool empty() {
        if ( q.size() == 0 ) return true ;
        return false ;
    }
};

class MyQueue {
public:
    stack <int> input , output ;
    MyQueue() {
        
    }
    
    void push(int x) {
        while ( !input.empty() ) {
            output.push( input.top() ) ;
            input.pop() ;
        }
        input.push(x) ;
        while ( !output.empty() ) {
            input.push( output.top() ) ;
            output.pop() ;
        }
    }
    
    int pop() {
        if ( input.empty()) {} ;
        int val = input.top() ;
        input.pop() ;
        return val ;
    }
    
    int peek() {
        return input.top() ;
    }
    
    bool empty() {
        if ( input.empty() ) return true ;
        return false ;
    }
};


int main ( ) {


return 0 ;
}