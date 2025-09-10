#include <bits/stdc++.h> 
using namespace std ;

class Node {
public :
    int data ;
    Node* next ;
    Node* prev ;

    Node ( int data1 , Node* next1 = NULL , Node* prev1 = NULL ) {
        data = data1 ;
        next = next1 ;
        prev = prev1 ;
    }
} ;

Node* convertArr2DLL ( vector<int> & arr ) {
    int n = arr.size( ) ;
    Node* head = new Node ( arr[0] ) ;
    Node* temp = head ;
    for ( int i = 1 ; i < n ; i++ ) {
        Node* nextNode = new Node ( arr[i] ) ;
        Node* prev = temp ;
        temp->next = nextNode ;
        temp = nextNode ;
        temp->prev = prev ;
    }
    return head ;
}

Node* insertAtTail ( Node* head , int k ) {

    Node* newNode = new Node ( k ) ;
    if ( head == NULL ) return newNode ;
    Node* temp = head ;

    while ( temp->next != NULL ) {
        temp = temp->next ;
    }

    temp->next = newNode ;
    newNode->prev = temp ;

    return head ;
}

Node* deleteTail ( Node* head ) {
    if ( head == NULL || head->next == NULL ) return NULL ;
    Node* tail = head ;
    while ( tail->next != NULL ) {
        tail = tail->next ;
    }
    Node* newTail = tail->prev ;
    newTail->next = NULL ;
    tail->prev = NULL ;
    delete tail ;
    return head ;
}

Node* reverseDLL ( Node* head ) {
    if ( head == NULL || head->next == NULL ) {
        if ( head ) head->prev = NULL ;
        return head ;
    }
    Node* newHead = reverseDLL ( head->next ) ;
    Node* front = head->next ;
    head->prev = front ;
    front->next = head ;
    head->next = NULL ;
    return newHead ; 
}

Node* deleteAllOccurOfX ( Node* head , int x ) {
    if ( head == NULL || head->next == NULL ) {
        if ( head && head->data == x ) return NULL ;
        return head ;
    }
    Node* current = head ;
    while ( current != NULL ) {
        Node* delNode = NULL ;
        Node* nextNode = current->next ;
        Node* prevNode = current->prev ;
        if ( current->data == x ) {
            if ( current == head ) head = head->next ;
            
            if (nextNode) nextNode->prev = prevNode ;
            if (prevNode) prevNode->next = nextNode ;
            delNode = current ;
        }
        current = nextNode ;
        if (delNode) delete delNode ;
    }
    return head ;
}

vector <pair<int,int>> findPairsWithGivenSum ( Node* head , int target ) {
    vector<pair<int,int> > result ;
    if ( head == NULL ) return result ;
    Node* left = head ;
    Node* right = head ;
    while ( right->next != NULL ) right = right->next ;

    while ( left != right && left != right->next ) {
        int sum = left->data + right->data ;
        if ( sum == target ) {
            result.push_back( {left->data , right->data}) ;
            left = left->next ;
            right = right->prev ;
        }
        else if ( sum < target ) {
            left = left->next ;
        }
        else right = right->prev ;
    }
    return result ;
}

Node* removeDuplicates( Node* head ) {
    if ( head == NULL || head->next == NULL ) return head ;
    Node* temp = head ;
    while ( temp != NULL || temp->next != NULL ) {
        Node* nextNode = temp->next ;
        while ( nextNode->data == temp->data ) {
            nextNode = nextNode->next ;
        }
        temp->next = nextNode ;
        if ( nextNode) nextNode->prev = temp ;
        temp = temp->next ;
    }
    return head ;
}

int main( ) {


return 0 ;
}