import java.applet.Applet; 
import java.awt.Graphics; 
public class HelloApplet extends Applet { 
    public void paint(Graphics g) { 
        g.drawString("Hello, World!", 20, 20); 
    } 
}
/*The type Applet has been deprecated since version 9 and marked for removalJava(16778626)
java.applet.Applet
Deprecated. The Applet API is deprecated, no replacement.

An applet is a small program that is intended not to be run on its own, but rather to be embedded inside another application*/