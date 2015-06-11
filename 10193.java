//UVA-10193            All You Need Is Love
//Accepted
import java.io.*;
import java.math.BigInteger;

public class Main {
  public static BigInteger changeBase(BigInteger num){
    BigInteger ans=BigInteger.ZERO;
    BigInteger dig,base;
    String cad=new StringBuilder(num.toString()).reverse().toString();
    for (int i = 0; i < cad.length(); i++) {
      dig=new BigInteger(cad.charAt(i)+"");
      base=new BigInteger(2+"");
      ans=ans.add(dig.multiply(base.pow(i)));
    }
    return ans;
  }
  
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    BigInteger n1,n2,gcd;
    int casos=Integer.parseInt(br.readLine());
    for (int i = 1; i <= casos; i++) {
      n1=new BigInteger(br.readLine());
      n2=new BigInteger(br.readLine());
      n1=changeBase(n1);
      n2=changeBase(n2);
      //pr.println(n1.toString()+" "+n2.toString());
      gcd=n1.gcd(n2);
      if(gcd.compareTo(new BigInteger(1+""))>0) pr.println("Pair #"+i+": All you need is love!");
      else pr.println("Pair #"+i+": Love is not all you need!");
      pr.flush();
    }
    br.close();
    pr.close();
  }
}
