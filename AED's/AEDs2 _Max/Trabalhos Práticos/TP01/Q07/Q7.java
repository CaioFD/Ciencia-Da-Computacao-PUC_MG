import java.io.*;
import java.net.*;

public class Q7 {
  public static String obterHtmlml(String endereco) {
    //URL url;
    InputStream is = null;
    BufferedReader br;
    String resp = "", line;

    try {
     // url = new URL(endereco);
     // is = url.openStream();
      br = new BufferedReader(new InputStreamReader(is));

      while ((line = br.readLine()) != null) {
        resp += line + "\n";
      }
    } catch (MalformedURLException mue) {
      mue.printStackTrace();
    } catch (IOException ioe) {
      ioe.printStackTrace();
    }

    try {
      is.close();
    } catch (IOException ioe) {
    }

    return resp;
  }

  public static void contarElementos(String nomePagina, String link) {
    int qa = 0, qe = 0, qi = 0, qo = 0, qu = 0, qaa = 0, qea = 0, qia = 0, qoa = 0, qua = 0, qacr = 0, qecr = 0,
        qicr = 0, qocr = 0, qucr = 0, qat = 0, qot = 0, qac = 0, qec = 0, qic = 0, qoc = 0, quc = 0, qconsoantes = 0,
        qbr = 0, qtable = 0;

    String html = obterHtmlml(link);

    for (int i = 0; i < html.length(); i++) {
      if (html.charAt(i) == '<') {
        if (html.charAt(i + 1) == 'b' && html.charAt(i + 2) == 'r' && html.charAt(i + 3) == '>') {
          qbr++;
          i = i + 3;
        } else if (html.charAt(i + 1) == 't' && html.charAt(i + 2) == 'a' && html.charAt(i + 3) == 'b'
            && html.charAt(i + 4) == 'l' && html.charAt(i + 5) == 'e' && html.charAt(i + 6) == '>') {
          qtable++;
          i = i + 6;
        }
      } else {
        int carac = (int) html.charAt(i);
        switch (carac) {
          case 'a':
            qa++;
            break;
          case 'e':
            qe++;
            break;
          case 'i':
            qi++;
            break;
          case 'o':
            qo++;
            break;
          case 'u':
            qu++;
            break;
          case 225:
            qaa++;
            break;
          case 233:
            qea++;
            break;
          case 237:
            qia++;
            break;
          case 243:
            qoa++;
            break;
          case 250:
            qua++;
            break;
          case 224:
            qacr++;
            break;
          case 232:
            qecr++;
            break;
          case 236:
            qicr++;
            break;
          case 242:
            qocr++;
            break;
          case 249:
            qucr++;
            break;
          case 227:
            qat++;
            break;
          case 245:
            qot++;
            break;
          case 226:
            qac++;
            break;
          case 234:
            qec++;
            break;
          case 238:
            qic++;
            break;
          case 244:
            qoc++;
            break;
          case 251:
            quc++;
            break;
          default:
            if (html.charAt(i) >= 'b' && html.charAt(i) <= 'z') {
              qconsoantes++;
            }
            break;
        }
      }
    }

    MyIO.println("a(" + qa + ") e(" + qe + ") i(" + qi + ") o(" + qo + ") u(" + qu + ") á(" + qaa + ") é(" + qea
        + ") í(" + qia + ") ó(" + qoa + ") ú(" + qua + ") à(" + qacr + ") è(" + qecr + ") ì(" + qicr + ") ò("
        + qocr + ") ù(" + qucr + ") ã(" + qat + ") õ(" + qot + ") â(" + qac + ") ê(" + qec + ") î(" + qic
        + ") ô(" + qoc + ") û(" + quc + ") consoante(" + qconsoantes + ") <br>(" + qbr + ") <table>("
        + qtable + ") " + nomePagina);
  }

  public static void main(String[] args) {
    String str = MyIO.readLine();
    String link = "";
    boolean continua = true;

    if (str.length() == 3) {
      if (str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M') {
        continua = false;
      } else {
        link = MyIO.readLine();
        if (link.length() == 3) {
          if (link.charAt(0) == 'F' && link.charAt(1) == 'I' && link.charAt(2) == 'M') {
            continua = false;
          }
        }
      }
    } else {
      link = MyIO.readLine();
      if (link.length() == 3) {
        if (link.charAt(0) == 'F' && link.charAt(1) == 'I' && link.charAt(2) == 'M') {
          continua = false;
        }
      }
    }

    while (continua) {
      contarElementos(str, link);
      str = MyIO.readLine();

      if (str.length() == 3) {
        if (str.charAt(0) == 'F' && str.charAt(1) == 'I' && str.charAt(2) == 'M') {
          continua = false;
        } else {
          link = MyIO.readLine();
          if (link.length() == 3) {
            if (link.charAt(0) == 'F' && link.charAt(1) == 'I' && link.charAt(2) == 'M') {
              continua = false;
            }
          }
        }
      } else {
        link = MyIO.readLine();
        if (link.length() == 3) {
          if (link.charAt(0) == 'F' && link.charAt(1) == 'I' && link.charAt(2) == 'M') {
            continua = false;
          }
        }
      }
    }
  }
}