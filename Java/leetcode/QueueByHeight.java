package leetcode;

import java.util.Arrays;
import java.util.Comparator;

public class QueueByHeight {
	class HeightQueueComparator implements Comparator<int[]> {
		public int compare(int[] o1, int[] o2) {
			// TODO Auto-generated method stub
			return o1[0] == o2[0] ? (o1[1] - o2[1]) : -(o1[0] - o2[0]); // to order descending
		}
	}
	
    public int[][] reconstructQueue(int[][] people) {
        if (people.length <= 1) return people;
    	Arrays.sort(people, new HeightQueueComparator());
        int[][] out = new int[people.length][];
        out[0] = people[0];
        for (int i = 1; i < people.length; i++) {
            int h = people[i][0];
            int k = people[i][1];
            int indexOut = 0;
            while (k > 0) {
            	if (out[indexOut][0] >= h){
            		k--;
            	}
            	indexOut++;
            }
            for (int j = i; j >= indexOut; j--) {
            	out[j] = out[j-1];
            }
            out[indexOut] = people[i];            
        }
        return out;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
