class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        count = 0
        for i in range(0, len(nums) - 1):
            if nums[i] != nums[i + 1]:
                count += 1
                if count == 2:
                    return nums[i + 1]
        return nums[0]
