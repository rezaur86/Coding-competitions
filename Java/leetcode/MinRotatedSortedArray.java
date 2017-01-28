package leetcode;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
public class MinRotatedSortedArray {
    public int findMin(int[] nums) {
        if (nums.length == 1) return nums[0];
        int n = nums.length;
        int first = 0;
        int last = 1;
        while (first != last && nums[first] <= nums[last]) {
            if (nums[first] == nums[last]) {
                while(first < last && nums[first] == nums[last]) {
                    first++;
                }
                if (first < last) break;
            }
            int temp = last;
            last = Math.min(last * 2, n-1);
            first = temp;
        }
        if (first == last && last == n-1) return nums[0];
        int min = Integer.MAX_VALUE;
        for (int i = first; i <= Math.min(last, n-1); i++) {
            if (min > nums[i]) {
                min = nums[i];
            }
        }
        return min;
    }
}
