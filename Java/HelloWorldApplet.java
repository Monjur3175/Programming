import java.applet.Applet;
import java.awt.Graphics;

@SuppressWarnings("removal")
public class HelloWorldApplet extends Applet {
    // Override the paint method to display text
    public void paint(Graphics g) {
        // Draw the string "Hello, World!" at position (50, 50)
        g.drawString("Hello, World!", 50, 50);
    }
}