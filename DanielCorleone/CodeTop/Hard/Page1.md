#### [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

#####  思路

模拟即可。每次先找到第k个节点，然后将其翻转。

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode start = head;
        ListNode end = head;
        for (int i = 0; i < k; i++) {
            if (end == null) return head;
            end = end.next;
        }

        ListNode res = reverse(start, end);
        start.next = reverseKGroup(end, k);
        return res;
    }
    

    public ListNode reverse(ListNode start, ListNode end) {
        ListNode pre = start;
        ListNode cur = null;
        while (pre != end) {
            ListNode next = pre.next;
            pre.next = cur;
            cur = pre;
            pre = next;
        }
        return cur;
    }
}   
```

