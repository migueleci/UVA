//UVA-10862 		Connect the Cable Wires 
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	private static BigInteger[] f;
	
	private static void fib(){
		f[1] = f[2] = new BigInteger(1+"");
		for (int i = 3; i < 4010; i++)
			f[i] = f[i-1].add(f[i-2]);
	}
	
	public static void main(String[] args) throws Exception {
		f=new BigInteger[4010];
		fib();
		int num;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		num=Integer.parseInt(br.readLine().trim());
		while(num>0){
			System.out.println(f[2*num]);
			num=Integer.parseInt(br.readLine().trim());
		}
	}
}

