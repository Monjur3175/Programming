#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class User
{
public:
    string username, password;

    bool login();
    void registerUser();
};

class Member
{
public:
    string name, contact;
    int id, meal_count;
    double investment;

    void addMember();
    void viewMembers();
    void removeMember();
    void addInvestment();
};

class Expense
{
public:
    string date, description;
    double amount;

    void addExpense();
    void viewExpenses();
};

class Meal
{
public:
    int member_id;
    string date;
    int meals;

    void addMeal();
    void viewMeals();
};

class MessSystem
{
public:
    vector<Member> members;
    vector<Expense> expenses;
    vector<Meal> meals;

    void calculateBill();
    void manageMemberExpense();
};

bool User::login()
{
    string inputUsername, inputPassword;
    cout << "Enter username: ";
    cin >> inputUsername;
    cout << "Enter password: ";
    cin >> inputPassword;

    ifstream file("users.txt");
    if (!file)
    {
        cout << "Error: Unable to open user data file.\n";
        return false;
    }

    string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword)
    {
        if (storedUsername == inputUsername && storedPassword == inputPassword)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void User::registerUser()
{
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (!file)
    {
        cout << "Error: Unable to open user data file for writing.\n";
        return;
    }

    file << username << " " << password << "\n";
    file.close();
    cout << "Registration successful!\n";
}

void Member::addMember()
{
    Member newMember;
    cout << "Enter member ID: ";
    cin >> newMember.id;
    cout << "Enter member name: ";
    cin.ignore();
    getline(cin, newMember.name);
    cout << "Enter contact: ";
    cin >> newMember.contact;
    newMember.meal_count = 0;
    newMember.investment = 0.0;

    ofstream file("members.txt", ios::app);
    if (!file)
    {
        cout << "Error: Unable to open member data file.\n";
        return;
    }

    file << newMember.id << " " << newMember.name << " " << newMember.contact << " " << newMember.meal_count << " " << newMember.investment << "\n";
    file.close();
    cout << "Member added successfully!\n";
}

void Member::viewMembers()
{
    ifstream file("members.txt");
    if (!file)
    {
        cout << "Error: Unable to open member data file.\n";
        return;
    }

    cout << "\n--- Member List ---\n";
    Member member;
    while (file >> member.id >> member.name >> member.contact >> member.meal_count >> member.investment)
    {
        cout << "ID: " << member.id << ", Name: " << member.name << ", Contact: " << member.contact << ", Meals: " << member.meal_count << ", Investment: " << member.investment << "\n";
    }
    file.close();
}

void Member::removeMember()
{
    int idToRemove;
    cout << "Enter member ID to remove: ";
    cin >> idToRemove;

    ifstream file("members.txt");
    ofstream tempFile("temp.txt");
    if (!file || !tempFile)
    {
        cout << "Error: Unable to open member data file.\n";
        return;
    }

    Member member;
    bool found = false;
    while (file >> member.id >> member.name >> member.contact >> member.meal_count >> member.investment)
    {
        if (member.id != idToRemove)
        {
            tempFile << member.id << " " << member.name << " " << member.contact << " " << member.meal_count << " " << member.investment << "\n";
        }
        else
        {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("members.txt");
    rename("temp.txt", "members.txt");

    if (found)
    {
        cout << "Member removed successfully!\n";
    }
    else
    {
        cout << "Member not found.\n";
    }
}

void Member::addInvestment()
{
    int memberID;
    double investmentAmount;
    cout << "Enter member ID: ";
    cin >> memberID;
    cout << "Enter investment amount: ";
    cin >> investmentAmount;

    ifstream file("members.txt");
    ofstream tempFile("temp.txt");
    if (!file || !tempFile)
    {
        cout << "Error: Unable to open member data file.\n";
        return;
    }

    Member member;
    bool found = false;
    while (file >> member.id >> member.name >> member.contact >> member.meal_count >> member.investment)
    {
        if (member.id == memberID)
        {
            member.investment += investmentAmount;
            found = true;
        }
        tempFile << member.id << " " << member.name << " " << member.contact << " " << member.meal_count << " " << member.investment << "\n";
    }

    file.close();
    tempFile.close();

    remove("members.txt");
    rename("temp.txt", "members.txt");

    if (found)
    {
        cout << "Investment added successfully!\n";
    }
    else
    {
        cout << "Member not found.\n";
    }
}

void Expense::addExpense()
{
    Expense newExpense;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> newExpense.date;
    cout << "Enter description: ";
    cin.ignore();
    getline(cin, newExpense.description);
    cout << "Enter amount: ";
    cin >> newExpense.amount;

    ofstream file("expenses.txt", ios::app);
    if (!file)
    {
        cout << "Error: Unable to open expense data file.\n";
        return;
    }

    file << newExpense.date << " " << newExpense.description << " " << newExpense.amount << "\n";
    file.close();
    cout << "Expense added successfully!\n";
}

void Expense::viewExpenses()
{
    ifstream file("expenses.txt");
    if (!file)
    {
        cout << "Error: Unable to open expense data file.\n";
        return;
    }

    cout << "\n--- Expense List ---\n";
    Expense expense;
    while (file >> expense.date >> ws)
    {
        getline(file, expense.description, ' ');
        file >> expense.amount;
        cout << "Date: " << expense.date << ", Description: " << expense.description << ", Amount: " << expense.amount << "\n";
    }
    file.close();
}

void Meal::addMeal()
{
    Meal newMeal;
    cout << "Enter member ID: ";
    cin >> newMeal.member_id;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> newMeal.date;
    cout << "Enter number of meals: ";
    cin >> newMeal.meals;

    ofstream file("meals.txt", ios::app);
    if (!file)
    {
        cout << "Error: Unable to open meal data file.\n";
        return;
    }

    file << newMeal.member_id << " " << newMeal.date << " " << newMeal.meals << "\n";
    file.close();
    cout << "Meal added successfully!\n";
}

void Meal::viewMeals()
{
    ifstream file("meals.txt");
    if (!file)
    {
        cout << "Error: Unable to open meal data file.\n";
        return;
    }

    cout << "\n--- Meal List ---\n";
    Meal meal;
    while (file >> meal.member_id >> meal.date >> meal.meals)
    {
        cout << "Member ID: " << meal.member_id << ", Date: " << meal.date << ", Meals: " << meal.meals << "\n";
    }
    file.close();
}

void MessSystem::calculateBill() {
    double totalExpenses = 0;
    int totalMeals = 0;

    ifstream expenseFile("expenses.txt");
    if (!expenseFile) {
        cout << "Error opening expenses.txt" << endl;
        return;
    }
    Expense expense;
    while (expenseFile >> expense.date >> ws) {
        getline(expenseFile, expense.description, ' ');
        expenseFile >> expense.amount;
        totalExpenses += expense.amount;
    }
    expenseFile.close();

    ifstream mealFile("meals.txt");
    if (!mealFile) {
        cout << "Error opening meals.txt" << endl;
        return;
    }
    Meal meal;
    while (mealFile >> meal.member_id >> meal.date >> meal.meals) {
        totalMeals += meal.meals;
    }
    mealFile.close();

    double mealRate = (totalMeals == 0) ? 0 : totalExpenses / totalMeals;

    cout << "\n--- Mess Bill Calculation ---\n"; // Added title
    cout << "Total Expenses: " << fixed << setprecision(2) << totalExpenses << endl; // Display total expenses
    cout << "Total Meals: " << totalMeals << endl;                               // Display total meals
    cout << "Meal Rate: " << fixed << setprecision(2) << mealRate << endl;       // Display meal rate

    ifstream memberFile("members.txt");
    if (!memberFile) {
        cout << "Error opening members.txt" << endl;
        return;
    }

    Member member;
    cout << "\n--- Member Bills (with Net Expense) ---\n";
    while (memberFile >> member.id >> member.name >> member.contact >> member.meal_count >> member.investment) {
        double bill = member.meal_count * mealRate;
        double netExpense = bill - member.investment;

        cout << "Member ID: " << member.id
             << ", Name: " << member.name
             << ", Bill: " << fixed << setprecision(2) << bill // Format to 2 decimal places
             << ", Investment: " << fixed << setprecision(2) << member.investment // Format to 2 decimal places
             << ", Net Expense: " << fixed << setprecision(2) << netExpense << "\n"; // Format to 2 decimal places
    }
    memberFile.close();
}

void MessSystem::manageMemberExpense() {
     double totalExpenses = 0;
    int totalMeals = 0;

    ifstream expenseFile("expenses.txt");
    if (!expenseFile) {
        cout << "Error opening expenses.txt" << endl;
        return;
    }
    Expense expense;
    while (expenseFile >> expense.date >> ws) {
        getline(expenseFile, expense.description, ' ');
        expenseFile >> expense.amount;
        totalExpenses += expense.amount;
    }
    expenseFile.close();

    ifstream mealFile("meals.txt");
    if (!mealFile) {
        cout << "Error opening meals.txt" << endl;
        return;
    }
    Meal meal;
    while (mealFile >> meal.member_id >> meal.date >> meal.meals) {
        totalMeals += meal.meals;
    }
    mealFile.close();

    double mealRate = (totalMeals == 0) ? 0 : totalExpenses / totalMeals;

    cout << "\n--- Mess Expense Management ---\n"; // Added title
    cout << "Total Expenses: " << fixed << setprecision(2) << totalExpenses << endl; // Display total expenses
    cout << "Total Meals: " << totalMeals << endl;                               // Display total meals
    cout << "Meal Rate: " << fixed << setprecision(2) << mealRate << endl;       // Display meal rate

    ifstream memberFile("members.txt");
    if (!memberFile) {
        cout << "Error opening members.txt" << endl;
        return;
    }

    Member member;
    cout << "\n--- Member Net Expenses ---\n";
    while (memberFile >> member.id >> member.name >> member.contact >> member.meal_count >> member.investment) {
        double totalBill = member.meal_count * mealRate;
        double netExpense = totalBill - member.investment;

        cout << "Member ID: " << member.id
             << ", Name: " << member.name
             << ", Total Bill: " << fixed << setprecision(2) << totalBill
             << ", Investment: " << fixed << setprecision(2) << member.investment
             << ", Net Expense: " << fixed << setprecision(2) << netExpense << "\n";
    }
    memberFile.close();
}

void clearScreen()
{
    system("cls");
}
void clearScreenWithDelay(int milliseconds)
{
    Sleep(milliseconds);
}

void mainMenu()
{
    int choice;
    User user;
    MessSystem messSystem;

    while (true)
    {
        cout << "\n--- Mess Management System ---\n"
             << "1. Login\n"
             << "2. Register\n"
             << "3. Add Member\n"
             << "4. View Members\n"
             << "5. Remove Member\n"
             << "6. Add Investment\n"
             << "7. Add Expense\n"
             << "8. View Expenses\n"
             << "9. Add Meal\n"
             << "10. View Meals\n"
             << "11. Calculate Bill\n"
             << "12. Manage Member Expense\n"
             << "13. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (user.login())
            {
                cout << "Login successful!\n";
            }
            else
            {
                cout << "Login failed. Try again.\n";
            }
            clearScreenWithDelay(3000);
            clearScreen();
            break;

        case 2:
            user.registerUser();
            clearScreenWithDelay(3000);
            clearScreen();
            break;

        case 3:
        {
            Member member;
            member.addMember();
            clearScreenWithDelay(3000);
            clearScreen();
            break;
        }

        case 4:
        {
            Member member;
            member.viewMembers();
            clearScreenWithDelay(10000);
            clearScreen();
            break;
        }

        case 5:
        {
            Member member;
            member.removeMember();
            clearScreenWithDelay(3000);
            clearScreen();
            break;
        }

        case 6:
        {
            Member member;
            member.addInvestment();
            clearScreenWithDelay(3000);
            clearScreen();
            break;
        }

        case 7:
        {
            Expense expense;
            expense.addExpense();
            clearScreenWithDelay(3000);
            clearScreen();
            break;
        }

        case 8:
        {
            Expense expense;
            expense.viewExpenses();
            clearScreenWithDelay(10000);
            clearScreen();
            break;
        }

        case 9:
        {
            Meal meal;
            meal.addMeal();
            clearScreenWithDelay(3000);
            clearScreen();
            break;
        }

        case 10:
        {
            Meal meal;
            meal.viewMeals();
            clearScreenWithDelay(10000);
            clearScreen();
            break;
        }

        case 11:
            messSystem.calculateBill();
            clearScreenWithDelay(10000);
            clearScreen();
            break;

        case 12:
            messSystem.manageMemberExpense();
            clearScreenWithDelay(10000);
            clearScreen();
            break;

        case 13:
            cout << "Exiting the system. Goodbye!\n";
            clearScreenWithDelay(3000);
            clearScreen();
            return;

        default:
            cout << "Invalid choice. Please try again.\n";
            clearScreenWithDelay(3000);
            clearScreen();
        }
    }
}

int main()
{
    cout<<"Please Read the user manual \'User Manual.pdf\' before using this Mess Management System"<<endl;
    mainMenu();
    system("Pause");
    return 0;
}
