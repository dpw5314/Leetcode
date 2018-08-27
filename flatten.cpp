#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define leng 4
using namespace std;
//98

class Solution {
public:
    
    Node* flatten(Node* head) {
        Node *dummy = head;
        stack<Node*> sk;
        //priority_queue<Node*, vector<Node*>, Compare> pq;
        if(head && head->next) sk.push(head->next);
        if(head && head->child) sk.push(head->child);
        while(!sk.empty()){
            Node* cur = sk.top();
            sk.pop();
            head->next = cur;
            head->next->prev = head;
            head->child = nullptr;
            if(cur->next != nullptr){
                sk.push(cur->next);
                //cur->next = nullptr;
            }
            if(cur->child != nullptr){
                sk.push(cur->child);
                //cur->child = nullptr;
            }
            head = head->next;            
        }

        return dummy;
    }
};