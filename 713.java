//UVA-713        Adding Reversed Numbers
//Accepted
import java.io.*;
import java.math.BigInteger;

public class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    String []inp;
    int casos=Integer.parseInt(br.readLine());
    BigInteger ans;
    for (int i = 0; i < casos; i++) {
      inp=br.readLine().toString().split(" ");
      ans=new BigInteger(new StringBuilder(inp[0]).reverse().toString());
      ans=ans.add(new BigInteger(new StringBuilder(inp[1]).reverse().toString()));
      ans=new BigInteger(new StringBuilder(ans.toString()).reverse().toString());
      pr.println(ans.toString());
      pr.flush();
    }
    br.close();
    pr.close();
  }
}
