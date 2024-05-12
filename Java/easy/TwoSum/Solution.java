class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> pastNums = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            Integer index = pastNums.get(target - nums[i]);
            if(index != null) {
                return new int[]{index, i};
            }
            pastNums.put(nums[i], i);
        }
        return null;
    }
}
