#include <bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;
    Node* random ;

    // Constructor with data and next pointer
    Node(int data1, Node* next1  , Node* random1 = NULL) {
        data = data1;
        next = next1;
        random = random1 ;
    }

Node ( int data1 ) {
    data = data1 ;
    next = NULL ;
    random = NULL ;
}
};

// Convert an array to a linked list
Node* convertArr2LL(const vector<int> &arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++) {
        mover->next = new Node(arr[i]);
        mover = mover->next;
    }
    return head;
}

// Compute length of the linked list
int lengthOfLL(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Check if a value exists in the linked list
bool checkIfPresent(Node* head, int val) {
    while (head) {
        if (head->data == val) return true;
        head = head->next;
    }
    return false;
}

// Print the linked list
void printLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << '\n';
}

// Insert a new node at the head
Node* insertHead(Node* head, int val) {
    return new Node(val, head);
}

Node* deleteTail(Node* head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL)
        return NULL;
    // Initialize a temporary pointer to traverse the list
    Node* temp = head;
    // Traverse to the second last node in the list
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    // Delete the last node
    delete temp->next;
    // Set the next of the second last node to nullptr, effectively removing the last node
    temp->next = nullptr;
    // Return the head of the modified list
    return head;
}

Node* middleNode(Node* head) {
    // Brute force ;
    // int length = lengthOfLL(head) ;
    // int mid = (length / 2) + 1 ;
    // int cnt = 0 ;
    // Node* temp = head ;
    // while ( temp != NULL ) {
    //     cnt++ ;
    //     if ( cnt == mid ) {
    //         return temp ;
    //     }
    //     temp = temp->next ;
    // }

    Node* fast = head ;
    Node* slow = head ;
    while ( fast->next != NULL || fast != NULL ) {
        fast = fast->next->next ;
        slow = slow->next ;
    }
    return slow ;
}

Node* reverseList(Node* head ) {

    // Node* temp = head ;
    // Node* prev = NULL ;
    // iterative approach ;
    // while ( temp != NULL ) {
    //     Node* front = temp->next ;
    //     temp->next = prev ;
    //     prev = temp ;
    //     temp = front ;
    // }

    //recursive approach ;
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *child ;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
        child = nullptr ;
    }
};

ListNode *head, *tail; // head and tail of the LinkedList

void PrintList(ListNode *head) // Function to print the LinkedList
{
    ListNode *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

void InsertatLast(int value) // Function for creating a LinkedList
{

    ListNode *newnode = new ListNode(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}

bool hasCycle(ListNode *head) { 

    if ( head == NULL && head->next == NULL ) return false ;
    ListNode* slow = head ;
    ListNode* fast = head ;
    while ( fast != NULL && fast->next != NULL ) {
        fast = fast->next->next ;
        slow = slow->next ;
        if ( fast == slow ) return true ;
    }
    return false ;
}

ListNode *detectCycle(ListNode *head) {
    if ( head == NULL || head->next == NULL ) return NULL ;
    ListNode* slow = head ;
    ListNode* fast = head ;
    while ( fast != NULL && fast->next != NULL ) {
        fast = fast->next->next ;
        slow = slow->next ;
        if ( fast == slow ) {
            slow = head ;
            while ( slow != fast ) {
                slow = slow->next ;
                fast = fast->next ;
            }
            return slow ;
        }
    }
    return NULL ;
}

ListNode *SegregatetoOddEVen(ListNode* head) {
    if ( head == NULL || head->next == NULL ) return head ;
    ListNode* odd = head ;
    ListNode* even = head->next ;
    ListNode* evenHead = even ;
    while ( even != NULL && even->next != NULL ) {
        odd->next = odd->next->next ;
        even->next = even->next->next ;
        odd = odd->next ;
        even = even->next ;
    }
    odd->next = evenHead ;
    return head ;
}

ListNode* DeleteNthNodefromEnd(ListNode* head, int n) {
    if ( head == NULL || head->next == NULL ) return NULL ;
    ListNode* slow = head ;
    ListNode* fast = head ;
    for ( int i = 1 ; i < n ; i++ ) {
        fast = fast->next ;
    }
    if ( fast == NULL ) return head->next ;
    while ( fast->next != NULL ) {
        slow = slow->next ;
        fast = fast->next ;
    }
    slow->next = slow->next->next ;
    return head ;
}

ListNode* deleteMiddle(ListNode* head) {

    if ( head ==NULL || head->next == NULL ) return NULL ;
    ListNode* fast = head ;
    ListNode* slow = head ;
    fast = fast->next->next ; // Becoz we want node just before the middle one 
    while ( fast != NULL && fast->next != NULL ) {
        fast = fast->next->next ;
        slow = slow->next ;
    }
    slow->next = slow->next->next ;

    return head ;
}

ListNode* merge2LL ( ListNode* list1 , ListNode* list2 ) {
    ListNode* dummyNode = new ListNode(-1) ;
    ListNode* temp = dummyNode ;
    while ( list1 != NULL && list2 != NULL ) {
        if ( list1->val > list2->val ) {
            temp->next = list2 ;
            list2 = list2->next ;
        }
        else{
            temp->next = list1 ;
            list1 = list1->next ;
        }
        temp = temp->next ;
    }
    while ( list1 != NULL ) {
        temp->next = list1 ;
        list1 = list1->next ;
        temp = temp->next ;
    }
    while ( list2 != NULL ) {
        temp->next = list2 ;
        list2 = list2->next ;
        temp = temp->next ;
    }

    return dummyNode->next ;
}

ListNode* middleNode ( ListNode* head ) {
    if ( head == NULL || head->next == NULL ) return head ;
    ListNode*  fast = head ;
    ListNode* slow = head ;
    fast = fast->next->next ;
    while( fast != NULL && fast->next != NULL ) {
        fast = fast->next->next ;
        slow = slow-> next ;
    }
    return slow ;
}


ListNode* sortList ( ListNode* head ) {
    if ( head == NULL || head->next == NULL ) return head ;
    ListNode* middle = middleNode(head) ;
    ListNode* right = middle->next ;
    ListNode* left = head ;
    middle->next = NULL ;
    left = sortList(left) ;
    right = sortList(right) ;
    return merge2LL(left , right ) ;
}

// Node* deleteAllOccurOfX(Node* head, int x) {
//     if ((head) == NULL)
//         return;

//     Node* current = head;
//     Node* next;

//     while (current != NULL) {

//         if (current->data == x) {

//             if ( current == head ) head = head->next ;
//             Node* nextNode = current->next ;
//             Node* prevNode = current->prev ;
//             if (prevNode) prevNode->next = nextNode;
//             else head = nextNode;                   
//             if (nextNode) nextNode->prev = prevNode;
//             free(current) ;
//             current = nextNode ;
            
//         } else {
//             current = current->next ;
//         }
//     }
//     return head ;
// }

int lengthOFLL ( ListNode* head ) {
    int cnt = 0 ;
    ListNode* temp = head ;
    while ( temp != NULL ) {
        cnt++ ;
        temp = temp->next ;
    }
    return cnt ;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if ( headA == NULL || headB == NULL ) return NULL ;
    ListNode* temp1 = headA ;
    ListNode* temp2 = headB ;
    while ( temp1 != temp2 ) {
        temp1 = temp1 -> next ;
        temp2 = temp2 -> next ;
        if ( temp1 == temp2 ) return temp1 ;
        if ( temp1 == NULL ) temp1 = headB ;
        if ( temp2 == NULL ) temp2 = headA ;
    }
    return temp1 ;
}

ListNode* reverseLL ( ListNode* head ) {
    if ( head == NULL || head -> next == NULL ) return head ;
    ListNode* newHead = reverseLL ( head->next ) ;
    ListNode* front = head->next ;
    front->next = head ;
    head->next = NULL ;
    return newHead ;
    
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0 ;
    ListNode* newHead1 = reverseLL ( l1 );
    ListNode* newHead2 = reverseLL ( l2 );
    ListNode* temp1 = newHead1 ;
    ListNode* temp2 = newHead2 ;
    ListNode* dummyNode = new ListNode ( -1 ) ;
    ListNode* temp = dummyNode ;
    while ( temp1 && temp2 ) {
        ListNode* nextNode = new ListNode( ((temp1->val + temp2->val + carry ) % 10)  ) ;
        carry = ( temp1->val + temp2->val + carry ) / 10 ;
        temp->next = nextNode ;
        temp = temp->next ;
        temp1 = temp1->next ;
        temp2 = temp2->next ;
        
    }
    while ( temp1 ) {
        ListNode* nextNode = new ListNode((temp1->val + carry) % 10) ;
        carry = (temp1->val + carry) / 10 ;
        temp->next = nextNode ;
        temp = temp->next ;
        temp1 = temp1->next ;
    }
    while ( temp2 ) {
        ListNode* nextNode = new ListNode((temp2->val + carry) % 10) ;
        carry = (temp2->val + carry) / 10 ;
        temp->next = nextNode ;
        temp = temp->next ;
        temp2 = temp2->next ;
    }
    if ( carry != 0 ) {
        ListNode* nextNode = new ListNode(carry);
        temp->next = nextNode ;
        temp = temp->next ;
    }
    return dummyNode->next ;

}

ListNode* findKthNode ( ListNode* head , int k ) {
    ListNode* temp = head ;
    while ( temp != NULL &&  k > 1 ) {
        temp = temp->next ;
        k-- ;
    }
    return temp ;
}

ListNode* reverseKGroup(ListNode* head, int k ) {
    ListNode* temp = head ;
    ListNode* prev = NULL ;
    while ( temp != NULL ) {
        ListNode* kthNode = findKthNode ( temp , k ) ;
        if ( kthNode == NULL ) {
            prev->next = temp ;
            break ;
        }
        ListNode* nextNode = kthNode->next ;
        kthNode->next = NULL ;
        reverseLL ( temp ) ;
        if ( temp == head ) head = kthNode ;
        else prev->next = kthNode ;
        prev = temp ;
        temp = nextNode ;
    }
    return head ;
}

ListNode* rotateRight(ListNode* head, int k) { 
    int length = lengthOFLL( head ) ;
    int rotations = k % length ;
    ListNode* kthNode = head ;
    for ( int i = 1 ; i < length - rotations ; i++ ) {
        kthNode = kthNode->next ;
    }
    if ( kthNode->next == NULL ) return head ;
    ListNode* newHead = kthNode->next ;
    kthNode->next = NULL ;
    ListNode* temp = newHead ;
    while ( temp->next != NULL ) {
        temp = temp->next ;
    }
    temp->next = head ;
    return newHead ;
}

// ListNode* flattenLinkedList(ListNode* head) {
//     vector<int> arr ;
//     ListNode* temp = head ;
//     while ( temp != NULL ) {
//         ListNode* childNode = temp ;
//         while ( childNode != NULL ) {
//             arr.push_back(childNode->val) ;
//             childNode = childNode->child ;
//         }
//         temp = temp->next ;
//     }
//     ListNode* dummyNode = new ListNode ( -1 ) ;
//     temp = dummyNode ;
//     sort( arr.begin() , arr.end()) ;
//     for ( auto val : arr ) {
//         ListNode* nextNode = new ListNode(val) ;
//         temp->next = nextNode ;
//         temp = temp->next ;
//     }
//     return dummyNode->next ;
// }

ListNode* merge ( ListNode* list1 , ListNode* list2 ) {
    ListNode* t1 = list1 ;
    ListNode* t2 = list2 ;
    ListNode* dummyNode = new ListNode ( -1 ) ;
    ListNode* temp = dummyNode ;
    while ( t1->child != NULL && t2->child != NULL ) {
        if ( t1->val > t2->val ) {
            temp->child = t2 ;
            t2 = t2->child ;
        }
        else {
            temp->child = t1 ;
            t1 = t1->child ;
        }
        temp = temp->child ;
    }

    if ( t1 ) {
        temp->child = t1 ;
        temp = temp->child ;
    }

    if ( t2 ) {
        temp->child = t2 ;
        temp = temp->child ;
    }

    return dummyNode->child ;
}

ListNode* flattenLinkedList( ListNode* head ) {
    if ( head == NULL || head->next == NULL ) return head ;
    ListNode* mergeHead = flattenLinkedList( head->next ) ;
    head = merge(  head , mergeHead ) ;
    return head ;
}

Node* copyNodes ( Node* head ) {
    Node* temp = head ;
    while ( temp != NULL ) {
        Node* nextElement = temp->next ;
        Node* copy = new Node ( temp->data ) ;
        copy ->next = nextElement ;
        temp->next = copy ;
        temp = nextElement ;
    }
    return head ;
}

void addingRandomPointer ( Node* head ) {
    Node* temp = head ;
    Node* res = temp->next ;
    while ( temp != NULL ) {
        if ( temp->random != NULL ) {
            res->random = temp->random->next ;
        }
        temp = temp->next->next ;
        res = temp->next ;
    }
}

Node* getDeepCopy ( Node* head ) {
    Node* temp = head ;
    Node* dummyNode = new Node ( -1 ) ;
    Node* res = dummyNode ;
    while ( temp != NULL ) {
        res->next = temp->next ;
        res = res->next ;
        temp->next = temp ->next->next ;
        temp = temp->next ;
    }
    return dummyNode->next ;
}

Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;
    copyNodes( head ) ;
    addingRandomPointer ( head ) ;
    return getDeepCopy ( head ) ;
}

int main() {
    // Sample array and value for insertion
    vector<int> arr = {12, 8, 5, 7};
    int val = 100;

    // Create linked list from array
    Node* head = convertArr2LL(arr);

    // Insert new node at head
    head = insertHead(head, val);

    // Print linked list
    printLL(head);

    // Additional: Check length and search a value
    cout << "Length: " << lengthOfLL(head) << endl;
    cout << "Is 7 present? " << (checkIfPresent(head, 7) ? "Yes" : "No") << endl;

    return 0;
}
