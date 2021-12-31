class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=False)
        for i in range(0, len(nums) - 1):
            if nums[i] == nums[i + 1]:
                nums1 = nums[i]
                break
        for j in range(0, len(nums)):
            if nums[j] != j + 1:
                nums2 = j + 1
                break
        return [nums1, nums2]
        # 没考虑到缺值在后