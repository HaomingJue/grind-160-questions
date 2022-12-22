#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return recursiveReverseList(head);
    }

    ListNode* iterativeReverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        while ( cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }

    ListNode* recursiveReverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = recursiveReverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return prev;
    }
};