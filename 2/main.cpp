#include <iostream>
#include <string>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int num = l1->val + l2->val + carry;
        ListNode* list = new ListNode( num % 10, nullptr);
        carry = num / 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* node = list;
        while(l1 != nullptr && l2 != nullptr) {
            num = l1->val + l2->val + carry; 
            node->next = new ListNode( num % 10, nullptr);
            carry = num / 10;
            node = node->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 == nullptr) {
            while(l2 != nullptr) {
                num = l2->val + carry;
                node->next = new ListNode( num % 10, nullptr);
                carry = num / 10;
                node = node->next;

                l2 = l2->next;
            }
        } 
        if(l2 == nullptr) {
            while(l1 != nullptr) {
                num = l1->val + carry;
                node->next = new ListNode( num % 10, nullptr);
                carry = num / 10;
                node = node->next;

                l1 = l1->next;
            }
        }
        if (carry > 0) {
            node->next = new ListNode(carry, nullptr);
        }
        return list;
    }
};

ListNode* vectorToList(vector<int> v) {
    ListNode* list = new ListNode(v[0], nullptr);
    ListNode* node = list;
    for(int i=1; i<v.size(); i++) {
       node->next = new ListNode(v[i], nullptr);
       node = node->next;
    }
    return list;
}

string listToString(ListNode* l) {
    string str = "[";
    while(l != nullptr) {
        str += to_string(l->val);
        l = l->next;
        if(l != nullptr) {
            str += ",";
        }
    }
    str += "]";
    return str;
}

int main() {
    Solution sol;
    ListNode *l1, *l2, *out;

    vector<int> input_1 {2,4,3};
    vector<int> input_2 {5,6,4};
    l1 = vectorToList(input_1);
    l2 = vectorToList(input_2);
    out = sol.addTwoNumbers(l1, l2);
    cout << "Input: " << listToString(l1) << " " << listToString(l2) << endl;
    cout << "Desired Output: [7,0,8]" << endl;
    cout << "Your Output: " << listToString(out) << endl;
    cout << endl;
    
    vector<int> input_3 {0};
    vector<int> input_4 {0};
    l1 = vectorToList(input_3);
    l2 = vectorToList(input_4);
    out = sol.addTwoNumbers(l1, l2);
    cout << "Input: " << listToString(l1) << " " << listToString(l2) << endl;
    cout << "Desired Output: [0]" << endl;
    cout << "Your Output: " << listToString(out) << endl;
    cout << endl;

    vector<int> input_5 {9,9,9,9,9,9,9};
    vector<int> input_6 {9,9,9,9};
    l1 = vectorToList(input_5);
    l2 = vectorToList(input_6);
    out = sol.addTwoNumbers(l1, l2);
    cout << "Input: " << listToString(l1) << " " << listToString(l2) << endl;
    cout << "Desired Output: [8,9,9,9,0,0,0,1]" << endl;
    cout << "Your Output:    " << listToString(out) << endl;
    cout << endl;
}