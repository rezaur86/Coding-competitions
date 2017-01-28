package ctci;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Random;

public class chapter1 {
	// Q 1.1
	public Boolean isUnique(String s){
		HashMap <Character, Integer> strhash = 
				new HashMap<Character, Integer>();
		for (char ch : s.toCharArray()){
			if (strhash.containsKey(ch))
				return false;
			else strhash.put(ch, 1);
		}
		return true;
	}
	public Boolean isUniqueEff(String s){
		BitSet ascii_bits = new BitSet(128);
		for (char ch : s.toCharArray()){
			if (ascii_bits.get((int) ch) == true)
				return false;
			else ascii_bits.set((int) ch);
			
		}
		return true;
	}
	public String sort(String s){
		char[] char_s = s.toCharArray();
		java.util.Arrays.sort(char_s);
		return char_s.toString();
	}
	// Q 1.2
	public Boolean isPermutation(String s1, String s2){
		if (sort(s1).compareTo(sort(s2)) == 0) return true;
		else return false;
	}
	
	// Q 1.4
	public Boolean isPermutedPalindrom(String s){
		int[] alphabets = new int[26];
		for (int i=0; i<26; i++) alphabets[i] = 0;
		s = s.toLowerCase();
		for (char ch : s.toCharArray()){
			if (Character.isLetter(ch))
				alphabets[ch - 'a'] = (alphabets[ch - 'a'] + 1) % 2;
		}
		int sum = 0;
		for (int i=0; i<26; i++) sum += alphabets[i];
		if (sum <= 1)
			return true;
		else return false;
	}
	
	// Q 1.5
	public Boolean isOneAway(String s1, String s2){
		int[][] cost = new int[s1.length() + 1][];
		for (int l1=0; l1 < s1.length() + 1; l1++){
			cost[l1] = new int[s2.length() + 1];
			cost[l1][0] = l1;
		}
		for (int l2=0; l2 < s2.length() + 1; l2++){
			cost[0][l2] = l2;
		}
		for (int l1=1; l1 < s1.length() + 1; l1++){
			for (int l2=1; l2 < s2.length() + 1; l2++){
				int min_cost = cost[l1-1][l2-1];
				if (s1.charAt(l1-1) != s2.charAt(l2-1)){
					min_cost += 1;
				}
				if (min_cost > (cost[l1][l2-1] + 1))
					min_cost = cost[l1][l2-1] + 1;
				if (min_cost > (cost[l1-1][l2] + 1))
					min_cost = cost[l1-1][l2] + 1;
				cost[l1][l2] = min_cost;
			}
		}
		/*
		for (int l1=0; l1 < s1.length() + 1; l1++){
			for (int l2=0; l2 < s2.length() + 1; l2++){
				System.out.print(" " + cost[l1][l2]);
			}
			System.out.println("\n");
		}*/		
		if (cost[s1.length()][s2.length()] <= 1)
			return true;
		else return false;
	}
	// Q 1.6
	public String compression(String s){
		String compStr = "";
		int lastCharCount = 0;
		for (char ch : s.toCharArray()){
			if (lastCharCount > 0 && compStr.charAt(compStr.length()-1) != ch){
				compStr += lastCharCount;
				lastCharCount = 0;
			}
			if (lastCharCount == 0){
				compStr += ch;
				lastCharCount += 1;
			}
			else if (lastCharCount > 0 && compStr.charAt(compStr.length()-1) == ch){
				lastCharCount += 1;
			}
		}
		compStr += lastCharCount;				
		if (compStr.length() >= s.length())
			return s;
		else return compStr;
	}
	
	// Q 1.7
	public boolean rotateMatrix(int[][] matrix){
		if (matrix.length == 0 || matrix.length != matrix[0].length){
			return false;
		}
		int n = matrix.length;
		for (int layer=0; layer<n/2; layer++){
			int first = layer;
			int last = n-layer-1;
			for (int i=first; i<last; i++){
				int offset = i - first;
				int top = matrix[first][i];
				matrix[first][i] = matrix[last-offset][first];
				matrix[last-offset][first] = matrix[last][last-offset];
				matrix[last][last-offset] = matrix[i][last];
				matrix[i][last] = top;
			}
		}
		return true;
	}
	
	// Q 1.8
	public int[][] zeroMatrix(int[][] matrix){
		int[] rows = new int[matrix.length];
		int[] cols = new int[matrix[0].length];
		for (int i=0; i<rows.length; i++){
			for (int j=0; j<cols.length; j++){
				if (matrix[i][j]==0){
					rows[i] = i+1;
					cols[j] = j+1;
				}
			}
		}
		for (int i=0; i<rows.length; i++){
			for (int j=0; j<cols.length; j++){
				if (rows[i]!= 0 && cols[j]!=0){
					matrix[rows[i]-1][cols[j]-1] = 0;
				}
			}
		}
		return matrix;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		chapter1 ch1 = new chapter1();
		System.out.println("Q 1.1 " + ch1.isUniqueEff("abc"));
		System.out.println("Q 1.4 " + ch1.isPermutedPalindrom("Tact Coa"));
		System.out.println("Q 1.5 " + ch1.isOneAway("pale", "plet"));
		System.out.println("Q 1.6 " + ch1.compression("aabcccccaaa"));
		System.out.println("Q 1.6 " + ch1.compression("aabbccaaa"));
		System.out.print("Q 1.7 Input\n");
		int[][] matrix = new int[4][];
		for (int l1=0; l1 < 4; l1++){
			matrix[l1] = new int[4];
		}
		int c = 0;
		for (int l1=0; l1 < 4; l1++){
			for (int l2=0; l2 < 4; l2++){
				matrix[l1][l2] = 'A' + c;
				c++;
				System.out.print(" " + (char)matrix[l1][l2]);
			}
			System.out.print("\n");
		}
		ch1.rotateMatrix(matrix);
		System.out.print("Q 1.7 Output\n");
		for (int l1=0; l1 < 4; l1++){
			for (int l2=0; l2 < 4; l2++){
				System.out.print(" " + (char)matrix[l1][l2]);
			}
			System.out.print("\n");
		}

		System.out.print("Q 1.8 Input\n");
		Random rand = new Random(System.currentTimeMillis());
		int[][] numMatrix = new int[10][];
		for (int l1=0; l1 < 10; l1++){
			numMatrix[l1] = new int[10];
		}
		for (int l1=0; l1 < 10; l1++){
			for (int l2=0; l2 < 10; l2++){
				int new_rand = rand.nextInt(10);
				numMatrix[l1][l2] =  new_rand > 2 ? new_rand: 0;
				System.out.print(" " + numMatrix[l1][l2]);
			}
			System.out.print("\n");
		}
		ch1.zeroMatrix(numMatrix);
		System.out.print("Q 1.8 Output\n");
		for (int l1=0; l1 < 10; l1++){
			for (int l2=0; l2 < 10; l2++){
				System.out.print(" " + numMatrix[l1][l2]);
			}
			System.out.print("\n");
		}
	}
}
