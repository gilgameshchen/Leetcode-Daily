#### [203. 移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/)

设立一前一后两个指针

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p = head;
    struct ListNode *q;
    if(p == NULL)
        return p;
    if(p -> next == NULL && p -> val != val)
        return p;
    while(p != NULL)
    {
        q = p -> next;
        if(q != NULL && q -> val == val)
        {
            p -> next = q -> next;
            free(q);
        }
        else
            p = p -> next;
    }
    if(head != NULL && head -> val == val)
        return head -> next;
    else
        return head;
}
```

#### [237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)

将下一个节点（若存在）的值赋给该节点，然后删除下一个节点

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *p;
    if(node -> next == NULL)
        free(node);
    else
    {
        node -> val = node -> next -> val;
        p = node -> next;
        node -> next = node -> next -> next;
        free(p);
    }
}
```

#### [19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

设置快慢两个指针，快指针先走`N`步，然后两个指针一起走，直到快指针到达最后一个节点，删除慢指针的后一个节点即可

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p=head, *q=head;
    int i = 0;
    for(i=0; i<n; i++)
        p = p -> next;
    if(p == NULL)
        return head -> next;
    while(p -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }
    q -> next = q -> next -> next;
    return head;
}
```

#### [430. 扁平化多级双向链表(*)](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        function<Node*(Node*)> dfs = [&](Node* node) {
            Node* cur = node;
            // 记录链表的最后一个节点
            Node* last = nullptr;

            while (cur) {
                Node* next = cur->next;
                //  如果有子节点，那么首先处理子节点
                if (cur->child) {
                    Node* child_last = dfs(cur->child);

                    next = cur->next;
                    //  将 node 与 child 相连
                    cur->next = cur->child;
                    cur->child->prev = cur;

                    //  如果 next 不为空，就将 last 与 next 相连
                    if (next) {
                        child_last->next = next;
                        next->prev = child_last;
                    }

                    // 将 child 置为空
                    cur->child = nullptr;
                    last = child_last;
                }
                else {
                    last = cur;
                }
                cur = next;
            }
            return last;
        };

        dfs(head);
        return head;
    }
};
```

#### [61. 旋转链表](https://leetcode-cn.com/problems/rotate-list/)

先求出链表长度，然后取余数`k`，将倒数第k个节点作为头结点，表尾接上原来的头结点即可

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if(k == 0 || head == NULL || head -> next == NULL)
        return head;
    int lenth=1, i;
    struct ListNode *p=head, *q=head;
    for(q=head; q->next!=NULL; q=q->next)
        lenth++;
    if(k % lenth == 0)
        return head;
    int n = lenth - k % lenth;
    for(i=0; i<n-1; i++)
        p = p -> next;
    q -> next = head;
    head = p -> next;
    p -> next = NULL;
    return head;
}
```

#### [24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode dummyHead;
    dummyHead.next = head;
    struct ListNode* temp = &dummyHead;
    while (temp->next != NULL && temp->next->next != NULL) {
        struct ListNode* node1 = temp->next;
        struct ListNode* node2 = temp->next->next;
        temp->next = node2;
        node1->next = node2->next;
        node2->next = node1;
        temp = node1;
    }
    return dummyHead.next;
}
```

#### [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)

将原链表每个节点摘下，按头插法插入到新节点中

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode temp;
    struct ListNode *p;
    p = head -> next;
    temp.next = head;
    temp.next->next = NULL;
    head = p;
    while(head -> next != NULL)
    {
        p = head -> next;
        head -> next = temp.next;
        temp.next = head;
        head = p;
    }
    head -> next = temp.next;
    return head;
}
```

