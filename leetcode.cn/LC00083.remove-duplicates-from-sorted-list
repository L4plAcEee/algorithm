/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 题目指明有序，那就直接利用有序性即可
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            while (cur->next != nullptr && cur->next->val == cur->val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            cur = cur->next;
        }
        return head;
    }
    // 哈希表缓存，遍历链表，利用哈希表查重。
    ListNode* deleteDuplicates_in_hash(ListNode* head) {
        if (head == nullptr) return nullptr;

        // 1. 只需要存 int 值
        unordered_set<int> s;
        
        ListNode* cur = head;
        ListNode* pre = nullptr; // 用于执行删除操作的前驱节点

        while (cur != nullptr) {
            // 2. 检查当前值是否已存在
            if (s.count(cur->val)) {
                // --- 发现重复：删除 cur ---
                pre->next = cur->next;  // 1. 前驱跳过当前
                delete cur;             // 2. 释放内存 (如果是刷题可省略，工程中必须写)
                cur = pre->next;        // 3. cur 指向下一个，pre 不动
            } else {
                // --- 首次出现：加入集合 ---
                s.insert(cur->val);
                pre = cur;              // pre 跟进
                cur = cur->next;        // cur 前进
            }
        }
        return head;
    }
};
