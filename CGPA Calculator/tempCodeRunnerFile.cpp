#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;

class CGPACalculator
{
private:
    string studentName;
    string studentRoll;
    int currentSemester;
    vector<int> numSubjects;
    vector<vector<float>> subjectGrades;
    vector<vector<int>> subjectCredits;
    vector<float> semesterCGPA;
    vector<int> semesterCredits;

public:
    void displayTitleAndInstructions()
    {
        cout << "******************* CGPA Calculator *******************" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Instructions: " << endl;
        cout << "1. Enter the student's name and roll number." << endl;
        cout << "2. Specify the current semester (1 to 8)." << endl;
        cout << "3. For each semester, enter the number of subjects." << endl;
        cout << "4. Enter the grade (on a 4.0 scale) and credit hours for each subject." << endl;
        cout << "5. The program will calculate the CGPA for each semester and the overall CGPA." << endl;
        cout << "6. The results will be saved in a text file." << endl;
        cout << "-------------------------------------------------------" << endl;
    }

    void inputDetails()
    {
        cout << "Enter the student's name: ";
        getline(cin, studentName);

        cout << "Enter the student's roll number: ";
        getline(cin, studentRoll);

        cout << "Enter the current semester (1 to 8): ";
        cin >> currentSemester;
        cout << "\n";
        numSubjects.resize(currentSemester);
        subjectGrades.resize(currentSemester);
        subjectCredits.resize(currentSemester);
        semesterCGPA.resize(currentSemester);
        semesterCredits.resize(currentSemester);

        for (int i = 0; i < currentSemester; ++i)
        {
            cout << "For Semester " << i + 1 << ":\n";

            cout << "Enter the number of subjects: ";
            cin >> numSubjects[i];

            subjectGrades[i].resize(numSubjects[i]);
            subjectCredits[i].resize(numSubjects[i]);

            float totalWeightedGrade = 0;
            semesterCredits[i] = 0;

            for (int j = 0; j < numSubjects[i]; ++j)
            {
                cout << "Enter grade for Subject " << j + 1 << " (on a 4.0 scale): ";
                cin >> subjectGrades[i][j];

                cout << "Enter credit hours for Subject " << j + 1 << ": ";
                cin >> subjectCredits[i][j];

                totalWeightedGrade += subjectGrades[i][j] * subjectCredits[i][j];
                semesterCredits[i] += subjectCredits[i][j];
            }
            semesterCGPA[i] = totalWeightedGrade / semesterCredits[i];
            cout << endl;
        }
    }

    float calculateOverallCGPA()
    {
        float totalWeightedCGPA = 0;
        int totalCredits = 0;

        for (int i = 0; i < currentSemester; ++i)
        {
            totalWeightedCGPA += semesterCGPA[i] * semesterCredits[i];
            totalCredits += semesterCredits[i];
        }

        return totalWeightedCGPA / totalCredits;
    }

    void saveToFile()
    {
        ofstream file("CGPA_Result.txt");
        file << "Student Name: " << studentName << endl;
        file << "Roll Number: " << studentRoll << endl;
        file << "Current Semester: " << currentSemester << endl;
        for (int i = 0; i < currentSemester; ++i)
        {
            file << "Semester " << i + 1 << " CGPA: " << semesterCGPA[i]
                 << " (Credits: " << semesterCredits[i] << ")" << endl;
        }
        file << "Overall CGPA: " << calculateOverallCGPA() << endl;
        file.close();
    }

    void displayFooter()
    {
        cout << "-------------------------------------------------------" << endl;
        cout << "Result saved Successfully in .txt file" << endl;
        cout << "Result will be shown in the .txt file" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "CGPA Calculator was made by Monjur Morshed." << endl;
    }
};

int main()
{
    CGPACalculator calculator;
    calculator.displayTitleAndInstructions();
    calculator.inputDetails();
    calculator.saveToFile();
    calculator.displayFooter();
    system("pause");
    return 0;
}
