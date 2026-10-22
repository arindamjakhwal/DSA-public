
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap: smallest node value comes first
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Add the first node of every non-empty list
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            // Extract the smallest node
            ListNode* node = pq.top();
            pq.pop();

            // Append it to the merged list
            tail->next = node;
            tail = tail->next;

            // Add the next node from the same list
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
