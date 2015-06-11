//UVA-10464         Big Big Real Numbers
//Accepted
import java.io.*;
import java.math.BigDecimal;

public class Main {
  public static String numform(String num){
    String ans="";
    int i,j,k;
    for(i=0;i<num.length() && num.charAt(i)=='0';i++) ;
    for(j=num.length()-1;j>=0 && num.charAt(j)=='0';j--) ;
    for(k=i;k<j+1;k++) ans+=num.charAt(k);
    if(ans.charAt(0)=='.') ans='0'+ans;
    if(ans.charAt(ans.length()-1)=='.') ans+='0';
    return ans;
  }
  
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    BigDecimal n1,n2;
    String []num;
    int casos=Integer.parseInt(br.readLine());
    while(casos-->0){
      num=br.readLine().split("\\s+");
      n1=new BigDecimal(numform(num[0]));
      n2=new BigDecimal(numform(num[1]));
      pr.println(numform(n1.add(n2).toPlainString()));
      pr.flush();
    }
    br.close();
    pr.close();
  }
}
