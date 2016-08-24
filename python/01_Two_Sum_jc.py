class Solution(object):
    def twoSum(self, nums, target):
        map = dict()
        result = [0,0]
        for i in range(len(nums)):
            if(map.has_key(nums[i])):
                result[0] = map.get(nums[i],None)
                result[1] = i
                break
            else:
                map[target - nums[i]] = i;
        return result
        
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        