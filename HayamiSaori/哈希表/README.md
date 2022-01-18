#### [217. 存在重复元素](https://leetcode-cn.com/problems/contains-duplicate/)

利用python集合

```python
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        mark = set()
        for n in nums:
            if n in mark:
                return True
            else:
                mark.add(n)
        return False
```

