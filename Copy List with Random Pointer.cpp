// LeetCode (Medium) | Copy List with Random Pointer | https://leetcode.com/problems/copy-list-with-random-pointer/description/

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
        if (head == nullptr) {
            return nullptr;
        }

        Node* current = head;

        while (current != nullptr) {
            Node* next_original = current->next;
            Node* clone = new Node(current->val);
            
            current->next = clone;
            clone->next = next_original;
            
            current = next_original;
        }

        current = head;
        while (current != nullptr) {
            Node* clone = current->next;
            
            if (current->random != nullptr) {
                clone->random = current->random->next;
            } else {
                clone->random = nullptr;
            }

            current = current->next->next;
        }

        Node* new_head = head->next;
        Node* clone_current = new_head;
        current = head;

        while (current != nullptr) {
            current->next = clone_current->next;

            if (clone_current->next != nullptr) {
                clone_current->next = clone_current->next->next;
            }

            current = current->next;
            clone_current = clone_current->next;
        }

        return new_head;
    }
};
