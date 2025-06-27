/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        std::unordered_map<Node*, Node*> oldToNew;
        
        
        Node* curr = head;
        
        // Step 1: Create all new nodes and store the mapping
        while (curr) {
            oldToNew[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Step 2: Assign next and random pointers
        curr = head;
        while (curr) {
            oldToNew[curr]->next = oldToNew[curr->next];     // handles nullptr
            oldToNew[curr]->random = oldToNew[curr->random]; // handles nullptr
            curr = curr->next;
        }

        return oldToNew[head];
    }


    
};
