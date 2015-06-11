//UVA-10925         Krakovia
//Accepted
import java.io.*;
import java.math.BigInteger;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    String []inp;
    int n,f,casos=1;
    inp=br.readLine().split(" ");
    n=Integer.parseInt(inp[0]);
    f=Integer.parseInt(inp[1]);
    BigInteger ans;
    while(n+f>0){
      ans=BigInteger.ZERO;
      for (int i = 0; i < n; i++) ans=ans.add(new BigInteger(br.readLine()));
      pr.println("Bill #"+(casos++)+" costs "+ans.toString()+": each friend should pay "+ans.divide(new BigInteger(f+"")));
      pr.println("");
      pr.flush();
      
      inp=br.readLine().split(" ");
      n=Integer.parseInt(inp[0]);
      f=Integer.parseInt(inp[1]);
    }
    br.close();
    pr.close();
  }
}
