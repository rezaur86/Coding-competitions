package leetcode;

import java.util.List;

import ctci.Chapter5;

public class RobHouse {
    public int rob(int[] nums) {
    	if (nums.length == 0) return 0;
    	if (nums.length == 1) return nums[0];
    	int[] robMax = new int[nums.length];
    	robMax[0] = nums[0];
    	robMax[1] = Math.max(nums[0], nums[1]);
    	for (int i = 2 ; i < nums.length; i++) {
    		robMax[i] = Math.max(robMax[i-2] + nums[i], robMax[i-1]);
    	}
    	return robMax[nums.length - 1];
    }

    public int robHouseRecursive(int[] nums, int n) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return nums[0];
        }
        return Math.max(robHouseRecursive(nums, n-2) + nums[n], robHouseRecursive(nums, n-1));
    }

    public int robCircularStreet(int[] nums) {
    	if (nums.length == 0) return 0;
    	int[] robTemp = new int[nums.length];
    	int[] robHelper = new int[nums.length];
    	int n = nums.length - 1;
    	if (nums.length == 1) return nums[0];
    	if (nums.length == 2) return Math.max(nums[0], nums[1]);
    	if (nums.length == 3) return Math.max(Math.max(nums[0], nums[1]), nums[2]);
    	robTemp[0] = nums[0];
    	robHelper[0] = 0;
    	robTemp[1] = Math.max(nums[0], nums[1]);
    	robHelper[1] = nums[1];
    	for (int i = 2 ; i < nums.length; i++) {
    	    robHelper[i] = Math.max(robHelper[i-2] + nums[i], robHelper[i-1]);
    		robTemp[i] = Math.max(robTemp[i-2] + nums[i], robTemp[i-1]);
    	}
    	return Math.max(robHelper[n-2] + nums[n], robTemp[n-1]);
    }

    public static void main(String[] args) {
		int[] robNums = {5,2,6,5};
		System.out.println("Output of robbing " + (new RobHouse()).rob(robNums));
	}
}
