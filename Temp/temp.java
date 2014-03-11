import java.net.*;
import java.io.*;
public class temp {
  public static void main(String []args) {

    String inputLine;
    try {
      URL url = new URL("http://www.baidu.com");
      File outputFile = new File("dat1.txt");
      FileOutputStream out = new FileOutputStream(outputFile);
      InputStreamReader isr = new InputStreamReader(url.openStream());
      BufferedReader in = new BufferedReader(isr);
      while ((inputLine = in.readLine()) != null) {
        System.out.println(inputLine);
        for (int i=0; i<inputLine.length(); i++)
          out.write(inputLine.charAt(i));
        out.write('\n');
      }

      in.close();
      out.close();
    } catch (MalformedURLException e) {
        System.out.println(e.toString());
    } catch (IOException e) {
        System.out.println(e.toString());
    }
  }
}