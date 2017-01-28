package ctci;

public class Chapter5 {
	// Q 5.1
	public int insertion(int N, int M, int i, int j) {
		int mask = ~(~(~0 << (j - i + 1)) << i);
		int clear_N = N & mask;
		return clear_N | (M << i);
	}
	
	// Q 5.2
	public String binString(double d) {
		String bin = new String();
		while (d > 0 && bin.length() <= 32) {
			if (d * 2 >= 1) bin += '1';
			else bin += '0';
			d = d * 2 >= 1 ? d * 2 - 1 : d * 2;
		}
		return bin;
	}
	
	// Q 5.3
	public int flipBitToWin(int n) {
		if (~n == 0) return Integer.BYTES*8;
		int prevOnes = 0;
		int ones = 0;
		int bestOnes = 0;
		while (n != 0) {
			if ((n & 1) == 1) {
				ones++;
			}
			else {
				prevOnes = (n & 2) == 0 ? 0 : ones;
				ones = 0;
			}
			if (prevOnes + ones + 1 > bestOnes) {
				bestOnes = prevOnes + ones + 1;
			}
			n >>>= 1;
		}
		return bestOnes;
	}
	
	// Q 5.4
	public int getNextNumber(int n) {
		int c = n;
		int c0 = 0;
		int c1 = 0;
		while ((c & 1) == 0 && c != 0){
			c0++;
			c >>= 1;
		}
		while ((c & 1) == 1 && c != 0){
			c1++;
			c >>= 1;
		}
		if (c0 + c1 == Integer.BYTES-1 || c0 + c1 == 0) return -1;
		c = c | 1;
		c = c << (c0 + 1);
		c = (c << (c1 - 1));
		c = c | ~(~0 << (c1 - 1));
		return c;
	}
	
	public int getPrevNumber(int n) {
		int c = n;
		int c0 = 0;
		int c1 = 0;
		while ((c & 1) == 1){
			c1++;
			c >>= 1;
		}
		if (c == 0) return -1;
		while ((c & 1) == 0 && c != 0){
			c0++;
			c >>= 1;
		}
		if (c0 + c1 == Integer.BYTES-1 || c0 + c1 == 0) return -1;
		c = c & (~0 << 1);
		c = c << (c1 + 1);
		c = c | ~(~0 << (c1 + 1));
		c = c << (c0 - 1);
		return c;
	}
    
    public static void main(String[] args) {
		Chapter5 ch5 = new Chapter5();
		System.out.println("Q 5.1 " + ch5.insertion(1024, 19, 2, 6));
		System.out.println("Q 5.2 " + ch5.binString(0.6250));
		System.out.println("Q 5.3 " + ch5.flipBitToWin(1767));
		System.out.println("Q 5.4 " + ch5.getNextNumber(13948));
		System.out.println("Q 5.4 " + ch5.getPrevNumber(ch5.getNextNumber(13948)));
	}
}
