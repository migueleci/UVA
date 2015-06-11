//UVA-11219          How old are you?
//Accepted
import java.io.*;
import java.util.GregorianCalendar;

public class Main {
  public static int getDiffYears(GregorianCalendar a, GregorianCalendar b) {
      int diff = b.get(b.YEAR) - a.get(a.YEAR);
      if (a.get(a.MONTH) > b.get(b.MONTH) || 
          (a.get(a.MONTH) == b.get(b.MONTH) && a.get(a.DATE) > b.get(b.DATE))) {
          diff--;
      }
      if(diff<0) diff=0;
      return diff;
  }
  
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    int casos=Integer.parseInt(br.readLine().toString());
    int i,dd,dm,dy,bd,bm,by;
    String date,birth;
    long days;
    GregorianCalendar dgc,bgc;
    for (i = 1; i <=casos; i++){
      br.readLine();
      date=br.readLine();
      birth=br.readLine();
      dd=Integer.parseInt(date.charAt(0)+""+date.charAt(1));
      dm=Integer.parseInt(date.charAt(3)+""+date.charAt(4));
      dy=Integer.parseInt(date.charAt(6)+""+date.charAt(7)+""+date.charAt(8)+""+date.charAt(9));
      bd=Integer.parseInt(birth.charAt(0)+""+birth.charAt(1));
      bm=Integer.parseInt(birth.charAt(3)+""+birth.charAt(4));
      by=Integer.parseInt(birth.charAt(6)+""+birth.charAt(7)+""+birth.charAt(8)+""+birth.charAt(9));
      dgc=new GregorianCalendar(dy, dm-1, dd);
      bgc=new GregorianCalendar(by, bm-1, bd);
      if (by>dy || (by==dy && bm>dm) || (by==dy && bm==dm && bd>dd)) 
        pr.println("Case #"+i+": Invalid birth date");
      else {
        days=getDiffYears(bgc,dgc);
        if(days>130) pr.println("Case #"+i+": Check birth date");
        else pr.println("Case #"+i+": "+days);
      }
      pr.flush();
    }
    br.close();
    pr.close();
  }
}
