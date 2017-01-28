package interviews;

public class Yahoo {

}
Run Length Encoding for byte array

Input byte array [10, 10, 10, 255, 255, 0, 10] ==> output byte array [3, 10, 2, 255, 1, 0, 1, 10]

Class ByteArrayEncodeDecode {
    public byte[] encodeByteArray(byte[] input) {
        int n = input.length;
        if (n == 0) return new byte[];
        Arraylist<Byte> out = Arraylist<Byte>();
        byte prevByte = input[0];
        byte prevCount = 1;
        for (int i = 1; i < n; i++) {
            if(prevByte == input[i] && prevCount != 255){ //
                prevCount++;
            } else {
                out.add(prevCount);
                out.add(prevByte);
                prevByte = input[i];
                prevCount = 1;
            }
        }
        out.add(prevCount);
        out.add(prevByte);    
        return out.toArray();
    }
    
    public static void main() {
    }
}
// [] ==> []
// [1] ==> [1, 1]
// [1, 1, 1, 2, 2, 3] ==> [3, 1, 2, 2, 1, 3]
// [1 ... 300.....1] ==> [255, 1, 45, 1]


