package leetcode;

import java.util.ArrayList;
import java.util.List;

import ctci.Chapter5;

public class PowerSet {
    public List<List<Integer>> powerSet(int[] nums) {
    	List<List<Integer>> pSet = powerSetHelper(nums, 0, nums.length-1);
    	ArrayList<Integer> emptySet = new ArrayList<Integer>();
    	pSet.add(emptySet);
    	return pSet;
    }
    
    public List<List<Integer>> powerSetHelper(int[] num, int i, int j) {
    	if (i==j) {
    		List<List<Integer>> powerSet = new ArrayList<List<Integer>>();
    		ArrayList<Integer> set = new ArrayList<Integer>();
    		set.add(num[i]);
    		powerSet.add(set);
    		return powerSet;
    	}
    	List<List<Integer>> powerSet = powerSetHelper(num, i, j-1);
    	List<List<Integer>> newPowerSet = new ArrayList<List<Integer>>();
    	for (int x = 0; x < powerSet.size(); x++) {
    		ArrayList<Integer> set = new ArrayList<Integer>();
    		set.addAll(powerSet.get(x));
    		set.add(num[j]);
    		newPowerSet.add(set);
    	}
    	powerSet.addAll(newPowerSet);
    	ArrayList<Integer> set = new ArrayList<Integer>();
		set.add(num[j]);
		powerSet.add(set);
		return powerSet;
    }

    public static void main(String[] args) {
		int[] num = {1, 2, 3, 4};
		System.out.println("Power Set of ");
		List<List<Integer>> pSet = (new PowerSet()).powerSet(num);
		for (int i = 0; i < pSet.size(); i++) {
			for (int j = 0; j < pSet.get(i).size(); j++) {
				System.out.print(" " + pSet.get(i).get(j));
			}
			System.out.print(" ;");
		}
		System.out.print("\n");
	}
}
