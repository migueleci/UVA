import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Main {
  public static void main(String[] args) throws Exception {
    int q,s,f,act,casos=1,tem;
    int []acum;
    String cad;
    String[] tmp;
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    while(br.ready()){
      cad=br.readLine().toString();
      if(cad==null) break;
      acum=new int[cad.length()];
      acum[0]=cad.charAt(0)-'0';
      for (int i = 1; i < cad.length(); i++) acum[i]=acum[i-1]+cad.charAt(i)-'0'; 
      q=Integer.parseInt(br.readLine().toString());
      System.out.println("Case "+(casos++)+":");
      for (int i = 0; i < q; i++) {
        tmp = br.readLine().toString().split(" ");
        s=Integer.parseInt(tmp[0]);
        f=Integer.parseInt(tmp[1]);
        if(s>f){ tem =f; f=s; s=tem; }
        if(s==0) act=acum[f];
        else act=acum[f]-acum[s-1];
          if(act==f-s+1 || act==0) System.out.println("Yes");
          else System.out.println("No");
      }
    }
  }
}

