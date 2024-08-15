//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        Node *temp = head;
        Node *head1 = NULL;
        while(temp!=NULL){
            Node *node = new Node(temp->data);
            node->next = head1;
            head1 = node;
            temp = temp->next;
        }
        int carry = 1;
        Node *temp1 = head1;
        while(temp1->next !=NULL && carry !=0){
            temp1->data = temp1->data + carry;
            carry = temp1->data /10;
            temp1->data = temp1->data %10;
            temp1 = temp1->next;
        }
        temp1->data = temp1->data + carry;
        carry = temp1->data /10;
        temp1->data = temp1->data %10;
        if(carry!=0){
            Node *c = new Node(carry);
            temp1->next = c;
        }
        Node *temp2 = head1;
        head = NULL;
        while(temp2!=NULL){
            Node *newnode = new Node(temp2->data);
            newnode ->next = head;
            head = newnode;
            temp2 = temp2->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends
