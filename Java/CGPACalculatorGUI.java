import java.awt.*;
import javax.swing.*;

public class CGPACalculatorGUI {
    private JFrame frame;
    private CardLayout cardLayout;
    private JPanel mainPanel;
    private JTextField nameField, rollField, numCoursesField;
    private JPanel coursePanel;
    private JTextField[] courseTitles, grades, credits;
    private int numCourses;
    private JLabel resultLabel, cgpaTextLabel;
    private int currentCourseIndex = 0;

    public CGPACalculatorGUI() {
        frame = new JFrame("CGPA Calculator");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);

        cardLayout = new CardLayout();
        mainPanel = new JPanel(cardLayout);

        createWelcomePage();
        createStudentInfoPage();
        createCourseEntryPage();
        createResultPage();

        frame.add(mainPanel);
        frame.setVisible(true);
    }

    private void createWelcomePage() {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout());
        JLabel label = new JLabel("Result Preparation", JLabel.CENTER);
        JButton startButton = new JButton("Start");

        startButton.addActionListener(e -> cardLayout.show(mainPanel, "StudentInfo"));
        
        panel.add(label, BorderLayout.CENTER);
        panel.add(startButton, BorderLayout.SOUTH);
        mainPanel.add(panel, "Welcome");
    }

    private void createStudentInfoPage() {
        JPanel panel = new JPanel(new GridLayout(3, 2));
        panel.add(new JLabel("Student Name: "));
        nameField = new JTextField();
        panel.add(nameField);
        
        panel.add(new JLabel("Student Roll: "));
        rollField = new JTextField();
        panel.add(rollField);
        
        JButton nextButton = new JButton("Next");
        nextButton.addActionListener(e -> cardLayout.show(mainPanel, "CourseEntry"));
        panel.add(nextButton);
        
        mainPanel.add(panel, "StudentInfo");
    }

    private void createCourseEntryPage() {
        JPanel panel = new JPanel(new BorderLayout());
        JPanel inputPanel = new JPanel(new GridLayout(2, 2));
        inputPanel.add(new JLabel("Number of Courses: "));
        numCoursesField = new JTextField();
        inputPanel.add(numCoursesField);
        JButton enterButton = new JButton("Enter");
        inputPanel.add(enterButton);
        panel.add(inputPanel, BorderLayout.NORTH);
        
        coursePanel = new JPanel();
        panel.add(coursePanel, BorderLayout.CENTER);
        
        enterButton.addActionListener(e -> addCourseFields());
        
        mainPanel.add(panel, "CourseEntry");
    }

    private void addCourseFields() {
        try {
            numCourses = Integer.parseInt(numCoursesField.getText());
            coursePanel.removeAll();
            coursePanel.setLayout(new GridLayout(4, 2));

            courseTitles = new JTextField[numCourses];
            grades = new JTextField[numCourses];
            credits = new JTextField[numCourses];

            showCourseFields(currentCourseIndex);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Please enter a valid number of courses.");
        }
    }

    private void showCourseFields(int index) {
        if (index >= numCourses) return;

        coursePanel.removeAll();
        coursePanel.setLayout(new GridLayout(4, 2));
        
        coursePanel.add(new JLabel("Course " + (index + 1) + " Title:"));
        courseTitles[index] = new JTextField();
        coursePanel.add(courseTitles[index]);
        
        coursePanel.add(new JLabel("Grade for " + (index + 1) + ":"));
        grades[index] = new JTextField();
        coursePanel.add(grades[index]);
        
        coursePanel.add(new JLabel("Credits for " + (index + 1) + ":"));
        credits[index] = new JTextField();
        coursePanel.add(credits[index]);

        JButton nextButton = new JButton("Next");
        nextButton.addActionListener(e -> {
            currentCourseIndex++;
            if (currentCourseIndex < numCourses) {
                showCourseFields(currentCourseIndex);
            } else {
                calculateCGPA();
            }
        });
        
        coursePanel.add(nextButton);
        
        coursePanel.revalidate();
        coursePanel.repaint();
    }

    private void createResultPage() {
        JPanel panel = new JPanel(new BorderLayout());

        cgpaTextLabel = new JLabel("CGPA Calculated!", JLabel.CENTER); // "CGPA Calculated" label
        cgpaTextLabel.setFont(new Font("Arial", Font.BOLD, 16));
        panel.add(cgpaTextLabel, BorderLayout.NORTH);

        resultLabel = new JLabel("", JLabel.CENTER);
        panel.add(resultLabel, BorderLayout.CENTER);

        JButton exitButton = new JButton("Exit");
        exitButton.addActionListener(e -> frame.dispose());
        panel.add(exitButton, BorderLayout.SOUTH);

        mainPanel.add(panel, "Result");
    }

    private void calculateCGPA() {
        try {
            float totalGradePoints = 0;
            float totalCredits = 0;
            
            for (int i = 0; i < numCourses; i++) {
                float grade = Float.parseFloat(grades[i].getText());
                float credit = Float.parseFloat(credits[i].getText());
                totalGradePoints += grade * credit;
                totalCredits += credit;
            }
            float cgpa = totalGradePoints / totalCredits;
            resultLabel.setText("CGPA: " + String.format("%.2f", cgpa));
            cardLayout.show(mainPanel, "Result");
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Please enter valid grades and credits.");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(CGPACalculatorGUI::new);
    }
}