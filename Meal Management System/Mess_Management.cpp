#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

// Class declarations
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

    void addMember();
    void viewMembers();
    void removeMember();
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
};

// User class method definitions
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

// Member class method definitions
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

    ofstream file("members.txt", ios::app);
    if (!file)
    {
        cout << "Error: Unable to open member data file.\n";
        return;
    }

    file << newMember.id << " " << newMember.name << " " << newMember.contact << " " << newMember.meal_count << "\n";
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
    while (file >> member.id >> member.name >> member.contact >> member.meal_count)
    {
        cout << "ID: " << member.id << ", Name: " << member.name << ", Contact: " << member.contact << ", Meals: " << member.meal_count << "\n";
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
    while (file >> member.id >> member.name >> member.contact >> member.meal_count)
    {
        if (member.id != idToRemove)
        {
            tempFile << member.id << " " << member.name << " " << member.contact << " " << member.meal_count << "\n";
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

// Expense class method definitions
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

// Meal class method definitions
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

// MessSystem class method definitions
void MessSystem::calculateBill()
{
    double totalExpenses = 0;
    int totalMeals = 0;

    // Calculate total expenses
    ifstream expenseFile("expenses.txt");
    if (!expenseFile)
    {
        cout << "Error: Unable to open expense data file.\n";
        return;
    }
    Expense expense;
    while (expenseFile >> expense.date >> ws)
    {
        getline(expenseFile, expense.description, ' ');
        expenseFile >> expense.amount;
        totalExpenses += expense.amount;
    }
    expenseFile.close();

    // Calculate total meals
    ifstream mealFile("meals.txt");
    if (!mealFile)
    {
        cout << "Error: Unable to open meal data file.\n";
        return;
    }
    Meal meal;
    while (mealFile >> meal.member_id >> meal.date >> meal.meals)
    {
        totalMeals += meal.meals;
    }
    mealFile.close();

    if (totalMeals == 0)
    {
        cout << "No meals recorded. Unable to calculate bill.\n";
        return;
    }

    double mealRate = totalExpenses / totalMeals;
    cout << "\nMeal Rate: " << mealRate << "\n";

    // Calculate and display bills for each member
    ifstream memberFile("members.txt");
    if (!memberFile)
    {
        cout << "Error: Unable to open member data file.\n";
        return;
    }
    Member member;
    cout << "\n--- Member Bills ---\n";
    while (memberFile >> member.id >> member.name >> member.contact >> member.meal_count)
    {
        double bill = member.meal_count * mealRate;
        cout << "Member ID: " << member.id << ", Name: " << member.name << ", Bill: " << bill << "\n";
    }
    memberFile.close();
}
void clearScreen()
{
    system("cls");
}
// Main menu
void mainMenu()
{
    int choice;
    User user;
    MessSystem messSystem;

    while (true)
    {
        cout << "\n--- Mess Management System ---\n";
        cout << "1. Login\n2. Register\n3. Manage Members\n4. Manage Expenses\n5. Manage Meals\n6. Calculate Bills\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (user.login())
            {
                cout << "Login successful!\n";
                // Proceed to mess management menu (to be implemented)
            }
            else
            {
                cout << "Invalid username or password.\n";
            }
            clearScreen();
            break;

        case 2:
            user.registerUser();
            clearScreen();
            break;
        case 3:
        {
            int memberChoice;
            Member member;
            while (true)
            {
                cout << "\n--- Member Management ---\n";
                cout << "1. Add Member\n2. View Members\n3. Remove Member\n4. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> memberChoice;

                switch (memberChoice)
                {
                case 1:
                    member.addMember();
                    break;
                case 2:
                    member.viewMembers();
                    break;
                case 3:
                    member.removeMember();
                    break;
                case 4:
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                }
                if (memberChoice==4)
                {
                    break;
                }
            }
            clearScreen();
            break;
        }
        case 4:
        {
            int expenseChoice;
            Expense expense;
            while (true)
            {
                cout << "\n--- Expense Management ---\n";
                cout << "1. Add Expense\n2. View Expenses\n3. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> expenseChoice;

                switch (expenseChoice)
                {
                case 1:
                    expense.addExpense();
                    break;
                case 2:
                    expense.viewExpenses();
                    break;
                case 3:
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                }
                if (expenseChoice==3)
                {
                    break;
                }
            }
            clearScreen();
            break;
        }
        case 5:
        {
            int mealChoice;
            Meal meal;
            while (true)
            {
                cout << "\n--- Meal Management ---\n";
                cout << "1. Add Meal\n2. View Meals\n3. Back to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> mealChoice;

                switch (mealChoice)
                {
                case 1:
                    meal.addMeal();
                    break;
                case 2:
                    meal.viewMeals();
                    break;
                case 3:
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
                }
                if (mealChoice == 3)
                {
                    break;
                }
            }
            clearScreen();
            break;
        }
        case 6:
            messSystem.calculateBill();
            clearScreen();
            break;
        case 7:
            cout << "Exiting...\n";
            clearScreen();
            return;
        default:
            cout << "Invalid choice. Try again.\n";
            clearScreen();
        }
    }
}

// Entry point
int main()
{
    cout << "Please Read the User Manual \'User manual.txt\' before use this mess management system" << endl;
    mainMenu();
    system("pause");
    return 0;
}
