import java.awt.*;
import java.awt.event.*;
import java.awt.Frame;
class mypro1 extends Frame implements KeyListener
{
 Frame f =new Frame("21 MATCHSTICKS GAME");
  Flowlayout flow = new Flowlayout();
  Label intro = new Label("PLEASE PICK 2,3 OR 4 MATCHSTICKS");
  Label computer =new Label ("COMPUTER");
  Label player =new Label("PLAYER");
  Label remaining =new Label("REMAINING");
  Label result =new Label("RESULT");
  TextField tcomputer =new TextField();
  TextField tplayer =new TextField();
  TextField tremain =new TextField();
  TextField tresult =new TextField();
 mypro1(String s)
  {
    super(s);
    f.add(intro);
    f.add(computer);
    f.add(tcomputer);
    f.add(player);
    f.add(tplayer);
    f.add(remaining);
    f.add(tremain);
    setText.tremain=21;
    tcomputer.addKeyListener(this);
    tplayer.addKeyListener(this);
    tremain.addKeyListener(this);
    tresult.addKeyListener(this);
    add(result);
    add(tresult);  
    f.setSize(600,600);
    f.setLayout(flow);
    f.setVisible(true);
    
  }
  }
  public void KeyPressed(KeyEvent ke)
  {
   int kc=ke.getKeyCode();
   tremain=tremain-kc;
   setText.tremain=tremain;
   tcomputer=5-kc;
   setText.tremain=tremain-tcomputer;
   if(kc==1)
    setText.result("NO OF MATCHSTICKS LEFT IS 1\nYOU LOOSE!!!");
  } 
  public void keyTyped(KeyEvent ke){ } 
  public void keyReleased(KeyEvent ke){ }

 
  public static void main(Sring args[]){
   mypro1 m=new mypro1("21 matchsticks game");
  }
 