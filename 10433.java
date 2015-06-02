//UVA-10433 		Automorphic Numbers
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) throws Exception {
		BigInteger num1,num2;
		String numero, res;
		int i,pos;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		while(br.ready()){
			numero=br.readLine().trim();
			num1=new BigInteger(numero);
			num2=num1.multiply(num1);
			res=num2.toString();
			//System.out.println("numero="+numero);
			//System.out.println("res="+res);
			if(numero.length()>res.length() || (numero.length()==1 && numero.charAt(0)=='0') ) System.out.println("Not an Automorphic number.");
			else{
				pos=res.length()-numero.length();
				for (i = 0; i < numero.length(); i++) if(numero.charAt(i)!=res.charAt(pos+i)) break;
				if(i==numero.length()) System.out.println("Automorphic number of "+numero.length()+"-digit.");
				else System.out.println("Not an Automorphic number.");
			}
		}
	}
}

