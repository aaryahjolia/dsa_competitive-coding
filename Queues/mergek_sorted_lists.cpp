//You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.

 
#include <bits/stdc++.h>
using namespace std;

// Defining singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Comparator function for priority queue
struct CompareNodes {
    bool operator()(const ListNode* a, const ListNode* b) const {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Creating min heap using priority queue
    priority_queue<ListNode*, vector<ListNode*>, CompareNodes> minHeap;
    
    // Push head nodes of all linked lists into the min heap
    for (auto list : lists) {
        if (list)
            minHeap.push(list);
    }
    
    // Creating dummy node as the head of the merged list
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    // Nodes in the min heap
    while (!minHeap.empty()) {
        // Get the node with the minimum value from the min heap
        ListNode* node = minHeap.top();
        minHeap.pop();
        
        // Append the node to the merged list
        tail->next = node;
        tail = tail->next;
        
        // Move to the next node in the linked list
        if (node->next)
            minHeap.push(node->next);
    }
    
    return dummy.next;
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& arr) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    
    for (int num : arr) {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    
    return dummy.next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage
    vector<vector<int>> input = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> lists;
    
    for (auto arr : input)
        lists.push_back(createLinkedList(arr));
    
    ListNode* mergedList = mergeKLists(lists);
    printLinkedList(mergedList);
    
    // Clean up the memory
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }
    
    return 0;
}
