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

#### [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

```C++
class Solution {
private:
    void reverseLinkedList(ListNode *head) {
        // 也可以使用递归反转一个链表
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode;
        // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
        // 建议写在 for 循环里，语义清晰
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }

        // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; i++) {
            rightNode = rightNode->next;
        }

        // 第 3 步：切断出一个子链表（截取链表）
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;

        // 注意：切断链接
        pre->next = nullptr;
        rightNode->next = nullptr;

        // 第 4 步：同第 206 题，反转链表的子区间
        reverseLinkedList(leftNode);

        // 第 5 步：接回到原来的链表中
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }
};
```

#### [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

```C++
class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};
```

#### [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int CF=0, lenth1=1, lenth2=1;
    struct ListNode *small, *big, *p;
    for(p=l1; p->next!=NULL; p=p->next)
        lenth1++;
    for(p=l2; p->next!=NULL; p=p->next)
        lenth2++;
    small = (lenth1 < lenth2) ? l1 : l2;
    big = (small != l1) ? l1 : l2;
    for(p=big; small!=NULL; small=small->next)
    {
        p -> val += small -> val;
        if(CF == 1)
            p -> val += 1;
        CF = (p -> val >= 10) ? 1 : 0;
        p -> val = p -> val % 10;
        p = p -> next;
    }
    if(CF == 1)
    {
        for(; p!=NULL; p=p->next)
        {
            if(CF == 0)
                break;
            else
            {
                CF = (p -> val == 9) ? 1 : 0;
                p -> val = (p -> val + 1) % 10;
            }
        }
    }
    if(CF == 1)
    {
        struct ListNode *add = (struct ListNode *)malloc(sizeof(struct ListNode));
        add -> next = NULL;
        add -> val = 1;
        for(p=big; p->next!=NULL; p=p->next);
        p -> next = add;
    }
    return big;
}
```

#### [445. 两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii/)

直接使用之前做过的链表翻转和逆序链表相加即可

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
struct ListNode* myaddTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int CF=0, lenth1=1, lenth2=1;
    struct ListNode *small, *big, *p;
    for(p=l1; p->next!=NULL; p=p->next)
        lenth1++;
    for(p=l2; p->next!=NULL; p=p->next)
        lenth2++;
    small = (lenth1 < lenth2) ? l1 : l2;
    big = (small != l1) ? l1 : l2;
    for(p=big; small!=NULL; small=small->next)
    {
        p -> val += small -> val;
        if(CF == 1)
            p -> val += 1;
        CF = (p -> val >= 10) ? 1 : 0;
        p -> val = p -> val % 10;
        p = p -> next;
    }
    if(CF == 1)
    {
        for(; p!=NULL; p=p->next)
        {
            if(CF == 0)
                break;
            else
            {
                CF = (p -> val == 9) ? 1 : 0;
                p -> val = (p -> val + 1) % 10;
            }
        }
    }
    if(CF == 1)
    {
        struct ListNode *add = (struct ListNode *)malloc(sizeof(struct ListNode));
        add -> next = NULL;
        add -> val = 1;
        for(p=big; p->next!=NULL; p=p->next);
        p -> next = add;
    }
    return big;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    return reverseList(myaddTwoNumbers(l1, l2));
}
```

#### [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

递归解法

```C
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL)
        return list2;
    if(list2==NULL)
        return list1;
    if(list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next,list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1,list2->next);
        return list2;
    }
}
```

#### [23. 合并K个升序链表(*)](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

分治法

```C++
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
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
```

