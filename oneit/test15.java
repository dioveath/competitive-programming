

public class Test15 {
    public static int addSubtractPairwise(int[] arg){
	int result = 0;
	for(int i = 0; i < arg.length - 1; i++){
	    if(i % 2 == 0) result += a[i] * a[i+1];
	    else result -= (i == arg.length - 1) ? a[i] : a[i] * a[i+1];
	}
	return result;
    }

    public static void main(String[] args){
	System.out.println("ans: " + addSubtractPairwise([1, 2, 3]));
    }
}
