//UVA-11821         High-Precision Number
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
    if(ans.charAt(ans.length()-1)=='.') ans=ans.substring(0, ans.length()-1);
    return ans;
  }
  
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    BigDecimal ans=BigDecimal.ZERO;
    String num;
    int casos=Integer.parseInt(br.readLine());
    while(casos>0){
      num=br.readLine();
      if(num.length()==1 && num.charAt(0)=='0'){
        pr.println(numform(ans.toPlainString()));
        ans=BigDecimal.ZERO;
        casos --;
      } else ans=ans.add(new BigDecimal(num));
      pr.flush();
    }
    br.close();
    pr.close();
  }
}
