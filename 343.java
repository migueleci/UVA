//UVA-343         What Base Is This?
//Accepted
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    while(br.ready()){
      String[] line = br.readLine().trim().split("\\s+");
      String a = line[0];
      String b = line[1];
      String[] bases_a = new String[37];
      String[] bases_b = new String[37];
      int maxa = -1, maxb = -1, n;
      for(int i = 0 ; i < a.length(); i++){
        n=a.charAt(i)-'0';
        if(Character.isAlphabetic(a.charAt(i))) n=a.charAt(i)-'A'+10; 
        maxa = Math.max(n, maxa);
      }
      maxa = Math.max(1, maxa);
      for(int i = maxa+1; i <= 36; i++){
        if(i==1)bases_a[i] = new BigInteger(a).toString();
        else bases_a[i] = new BigInteger(a,i).toString(); 
      }
      for(int i = 0 ; i < b.length(); i++){
        n=b.charAt(i)-'0';
        if(Character.isAlphabetic(b.charAt(i))) n=b.charAt(i)-'A'+10; 
        maxb = Math.max(n, maxb);
      }
      maxb = Math.max(1, maxb);
      for(int i = maxb+1; i <= 36; i++){
        if(i==1)bases_b[i] = new BigInteger(b).toString();
        else bases_b[i] = new BigInteger(b,i).toString(); 
      }
      boolean sePuede = false;
      for(int i = maxa+1 ; i <= 36 && !sePuede; i++){
        for(int j = maxb+1; j<= 36 && !sePuede; j++){
          if(bases_a[i].equals(bases_b[j])){
            System.out.println(String.format("%s (base %d) = %s (base %d)", line[0], i, line[1], j));
            sePuede = true;
          }
        }
      }
      if(!sePuede){
        System.out.println(String.format("%s is not equal to %s in any base 2..36", line[0], line[1]));
      }
    }
  }
}
