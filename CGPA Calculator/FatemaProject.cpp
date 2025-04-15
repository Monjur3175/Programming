#include <iostream>
#include <string>  // For using string type
#include <iomanip> // For controlling decimal places
using namespace std;

class CGPACalculator
{
private:
    string studentName;
    string studentRoll;
    int numSubjects;
    string subjectNames[10]; // Array to store subject names (assuming max 10 subjects)
    float grades[10];        // Array for grades
    float credits[10];       // Array for credits

    // Function to convert numeric grade to letter grade
    string getLetterGrade(float grade)
    {
        if (grade >= 4.0)
            return "A+";
        else if (grade >= 3.75)
            return "A";
        else if (grade >= 3.5)
            return "A-";
        else if (grade >= 3.25)
            return "B+";
        else if (grade >= 3.0)
            return "B";
        else if (grade >= 2.75)
            return "B-";
        else if (grade >= 2.5)
            return "C+";
        else if (grade >= 2.25)
            return "C";
        else if (grade >= 2.0)
            return "D";
        else
            return "F"; // For grades below 2.0
    }

public:
    void inputDetails()
    {
        cout << endl;
        cout << "\t\t**CGPA CALCULATOR" << endl;
        cout << "\t\t1st year 1st semester" << endl;
        cout << "-------------------------------------------" << endl;

        cout << "\tEnter the student's name: ";
        getline(cin, studentName);

        cout << "\tEnter the student's roll number: ";
        getline(cin, studentRoll);
        cout << endl;

        cout << "Enter the number of subjects: ";
        cin >> numSubjects;
        cin.ignore(); // To ignore the newline character left by cin
        cout << endl;

        float totalGradePoints = 0;
        float totalCredits = 0;

        for (int i = 0; i < numSubjects; ++i)
        {
            cout << "Enter the name of Subject " << i + 1 << ": ";
            getline(cin, subjectNames[i]); // Input subject name

            cout << "Enter grade for " << subjectNames[i] << " (out of 4.0): ";
            cin >> grades[i];

            // Validate grade input
            while (grades[i] < 0.0 || grades[i] > 4.0)
            {
                cout << "Invalid grade. Please enter a grade between 0.0 and 4.0: ";
                cin >> grades[i];
            }

            // Display corresponding letter grade
            cout << "Letter Grade: " << getLetterGrade(grades[i]) << endl;

            cout << "Enter credit hours for " << subjectNames[i] << ": ";
            cin >> credits[i];

            // Validate credit input
            while (credits[i] <= 0)
            {
                cout << "Invalid credit hours. Please enter a positive value: ";
                cin >> credits[i];
            }
            cin.ignore(); // To ignore the newline character left by cin

            totalGradePoints += grades[i] * credits[i];
            totalCredits += credits[i];
            
            
            cout << endl;
        }

        float semesterCGPA = totalGradePoints / totalCredits;

        // Display CGPA rounded to 2 decimal places
        cout << fixed << setprecision(2); // Limit to 2 decimal places
        cout << "Total Grade Points: " << totalGradePoints << endl;
        cout << "Total Credits: " << totalCredits << endl;
        cout << "Semester CGPA: " << semesterCGPA << endl;
    }
};

int main()
{
    CGPACalculator calculator;
    calculator.inputDetails();
    return 0;
}
