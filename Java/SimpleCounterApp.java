import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleCounterApp {
    public static void main(String[] args) {
        // Create the JFrame
        JFrame frame = new JFrame("Simple Counter");
        frame.setSize(300, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new java.awt.FlowLayout());

        // Create the label
        JLabel label = new JLabel("Count: 0");
        frame.add(label);

        // Create the button
        JButton button = new JButton("Click Me");
        frame.add(button);

        // Add action listener to the button
        button.addActionListener(new ActionListener() {
            int count = 0; // Counter variable

            @Override
            public void actionPerformed(ActionEvent e) {
                count++; // Increment the count
                label.setText("Count: " + count); // Update the label
            }
        });

        // Make the frame visible
        frame.setVisible(true);
    }
}