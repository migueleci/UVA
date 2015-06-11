//UVA-10523            Very Easy !!!
//Accepted
import java.io.*;
import java.math.BigInteger;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    int n,a;
    String []inp;
    BigInteger ans,aux,base;
    while(br.ready()){
      inp=br.readLine().toString().split(" ");
      ans=BigInteger.ZERO;
      n=Integer.parseInt(inp[0]);
      a=Integer.parseInt(inp[1]);
      base=new BigInteger(a+"");
      for (int i = 1; i < n+1; i++) {
        aux=new BigInteger(i+"");
        ans=ans.add(aux.multiply(base.pow(i)));
      }
      pr.println(ans.toString());
      pr.flush();
    }
    br.close();
    pr.close();
  }
}
