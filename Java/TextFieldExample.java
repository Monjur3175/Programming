import javax.swing.*;
import java.awt.event.*;

public class TextFieldExample implements ActionListener {
    JTextField tf1, tf2, tf3;
    JButton b1, b2, b3, b4; // b3 for multiplication, b4 for division

    TextFieldExample() {
        JFrame f = new JFrame();
        tf1 = new JTextField();
        tf1.setBounds(50, 50, 250, 25);
        tf2 = new JTextField();
        tf2.setBounds(50, 100, 250, 25);
        tf3 = new JTextField();
        tf3.setBounds(50, 150, 250, 25);
        tf3.setEditable(false);
        b1 = new JButton("+");
        b1.setBounds(50, 200, 50, 50);
        b2 = new JButton("-");
        b2.setBounds(120, 200, 50, 50);
        b3 = new JButton("*"); // multiplication button
        b3.setBounds(190, 200, 50, 50);
        b4 = new JButton("/"); // division button
        b4.setBounds(260, 200, 50, 50);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        f.add(tf1);
        f.add(tf2);
        f.add(tf3);
        f.add(b1);
        f.add(b2);
        f.add(b3);
        f.add(b4);
        f.setSize(800, 600);
        f.setLayout(null);
        f.setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String s1 = tf1.getText();
        String s2 = tf2.getText();
        double a = Double.parseDouble(s1);
        double b = Double.parseDouble(s2);
        double c = 0;
        if (e.getSource() == b1) {
            c = a + b;
        } else if (e.getSource() == b2) {
            c = a - b;
        } else if (e.getSource() == b3) {
            c = a * b;
        } else if (e.getSource() == b4) {
            if (b != 0) {
                c = a / b;
            } else {
                tf3.setText("Error: Division by zero");
                return;
            }
        }
        // Format the result to display only two decimal places
        String result = String.format("%.2f", c);
        tf3.setText(result);
    }

    public static void main(String[] args) {
        new TextFieldExample();
    }
}