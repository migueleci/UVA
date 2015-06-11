//UVA-10235           Simply Emirp
//Accepted
import java.io.*;
import java.math.BigInteger;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    BigInteger num,rev;
    while(br.ready()) {
      num=new BigInteger(br.readLine());
      rev=new BigInteger(new StringBuilder(num.toString()).reverse().toString());
      if(!num.isProbablePrime(10)) pr.println(num.toString()+" is not prime.");
      else if(rev.isProbablePrime(10) && rev.compareTo(num)!=0) pr.println(num.toString()+" is emirp.");
      else pr.println(num.toString()+" is prime.");
      
      pr.flush();
    }
    br.close();
    pr.close();
  }
}
