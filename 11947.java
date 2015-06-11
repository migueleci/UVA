//UVA-11947           Cancer or Scorpio
//Accepted
import java.io.*;
import java.util.GregorianCalendar;

public class Main {
  public static String zodiac(GregorianCalendar gc){
    int mm=gc.get(gc.MONTH)+1,dd=gc.get(gc.DAY_OF_MONTH),yy=gc.get(gc.YEAR);
    if((mm==1 && dd>=21) || (mm==2 && dd<=19)) return "aquarius";
    else if((mm==2 && dd>=20) || (mm==3 && dd<=20)) return "pisces";
    else if((mm==3 && dd>=21) || (mm==4 && dd<=20)) return "aries";
    else if((mm==4 && dd>=21) || (mm==5 && dd<=21)) return "taurus";
    else if((mm==5 && dd>=22) || (mm==6 && dd<=21)) return "gemini";
    else if((mm==6 && dd>=22) || (mm==7 && dd<=22)) return "cancer";
    else if((mm==7 && dd>=23) || (mm==8 && dd<=21)) return "leo";
    else if((mm==8 && dd>=22) || (mm==9 && dd<=23)) return "virgo";
    else if((mm==9 && dd>=24) || (mm==10 && dd<=23)) return "libra";
    else if((mm==10 && dd>=24) || (mm==11 && dd<=22)) return "scorpio";
    else if((mm==11 && dd>=23) || (mm==12 && dd<=22)) return "sagittarius";
    else return "capricorn";
  }
  
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter pr = new PrintWriter(System.out);
    int casos=Integer.parseInt(br.readLine().toString());
    int i,dd,mm,yy;
    String date;
    GregorianCalendar gc;
    for (i = 1; i <=casos; i++){
      date=br.readLine();
      mm=Integer.parseInt(date.charAt(0)+""+date.charAt(1));
      dd=Integer.parseInt(date.charAt(2)+""+date.charAt(3));
      yy=Integer.parseInt(date.charAt(4)+""+date.charAt(5)+""+date.charAt(6)+""+date.charAt(7));
      gc=new GregorianCalendar(yy, mm-1, dd);
      gc.add(gc.DATE, 40*7);
      pr.printf("%d %02d/%02d/%02d %s\n", i,gc.get(gc.MONTH)+1,gc.get(gc.DAY_OF_MONTH),gc.get(gc.YEAR),zodiac(gc));
      pr.flush();
    }
    br.close();
    pr.close();
  }
}
