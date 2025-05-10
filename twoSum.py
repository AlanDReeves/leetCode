class Solution:
    # n^2 version
    def twoSumSlow(self, nums: list[int], target: int) -> list[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
    def twoSumFast(self, nums: list[int], target: int) -> list[int]:
        seen = dict()
        for i in range(len(nums)):
            seen[nums[i]] = i
        for j in range(len(nums)):
            if (target - nums[j]) in seen and seen[target - nums[j]] != j:
                return [j, seen[target - nums[j]]]