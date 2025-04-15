import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SumCalculator extends JFrame {
    private JTextField num1Field, num2Field;
    private JLabel resultLabel;

    public SumCalculator() {
        setTitle("Sum Calculator");
        setSize(350, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(4, 2, 10, 10));
        JLabel num1Label = new JLabel("Enter first number:");
        num1Field = new JTextField();
        JLabel num2Label = new JLabel("Enter second number:");
        num2Field = new JTextField();
        JButton addButton = new JButton("Calculate Sum");
        resultLabel = new JLabel("Result: ");
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    double num1 = Double.parseDouble(num1Field.getText().trim());
                    double num2 = Double.parseDouble(num2Field.getText().trim());
                    double sum = num1 + num2;
                    resultLabel.setText("Result: " + sum);
                } catch (NumberFormatException ex) {
                    resultLabel.setText("Invalid Input!");
                }
            }
        });
        add(num1Label);
        add(num1Field);
        add(num2Label);
        add(num2Field);
        add(addButton);
        add(resultLabel);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        new SumCalculator();
    }
}
