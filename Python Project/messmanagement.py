import os
import time
import tkinter as tk
from tkinter import messagebox
import bcrypt
def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

def clear_screen_with_delay(milliseconds):
    time.sleep(milliseconds / 1000)
    clear_screen()
class User:
    def __init__(self):
        self.username = ""
        self.password = ""
        self.is_logged_in = False

    def login(self, username, password):
        try:
            with open("users.txt", "r", encoding="utf-8") as file:
                for line in file:
                    stored_username, stored_password = line.strip().split()
                    if username == stored_username and bcrypt.checkpw(password.encode(), stored_password.encode()):
                        return True  # Successful login
                return False  # Login failed - username not found or password incorrect
        except FileNotFoundError:
            return None  # Indicate file not found error

    def register_user(self, username, password):
        try:
            hashed_password = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt()).decode('utf-8')
            with open("users.txt", "a", encoding="utf-8") as file:
                file.write(f"{username} {hashed_password}\n")
            return True
        except FileNotFoundError:
            return False

class Member:
    def __init__(self):
        self.id = 0
        self.name = ""
        self.contact = ""
        self.meal_count = 0
        self.investment = 0.0

    def add_member(self, id, name, contact):
        try:
            with open("members.txt", "a", encoding="utf-8") as file:
                file.write(f"{id} {name} {contact} {self.meal_count} {self.investment}\n")
            return True
        except FileNotFoundError:
            return False
        except Exception as e: # catch any other exception
            print(f"An error occurred: {e}")
            return False

    def view_members(self):
        members = []
        try:
            with open("members.txt", "r", encoding="utf-8") as file:
                for line in file:
                    member_data = line.strip().split()
                    try:
                        members.append(member_data)
                    except IndexError:
                        print(f"Skipping invalid line: {line.strip()}")
                        continue
            return members
        except FileNotFoundError:
            return None

    def remove_member(self, id_to_remove):
        try:
            with open("members.txt", "r", encoding="utf-8") as file:
                lines = file.readlines()

            with open("members.txt", "w", encoding="utf-8") as file:
                found = False
                for line in lines:
                    member_data = line.strip().split()
                    try:
                        if int(member_data[0]) != id_to_remove:
                            file.write(line)
                        else:
                            found = True
                    except (ValueError, IndexError):
                        print(f"Skipping invalid line: {line.strip()}")
                        file.write(line) #write the line anyway to avoid data loss
                        continue
            return found
        except FileNotFoundError:
            return None
        except ValueError:
            return None
        except Exception as e:
            print(f"An error occurred: {e}")
            return False


def add_investment(self):
    try:
        member_id = int(input("Enter member ID: "))
    except ValueError:
        print("Invalid input. Please enter a valid numeric ID.")
        return

    try:
        investment_amount = float(input("Enter investment amount: "))
    except ValueError:
        print("Invalid input. Please enter a valid numeric amount.")
        return

    try:
        with open("members.txt", "r") as file:
            lines = file.readlines()

        found = False  # Initialize a flag to check if the member exists

        with open("members.txt", "w") as file:
            for line in lines:
                member_data = line.strip().split()
                if int(member_data[0]) == member_id:
                    # Update the investment amount
                    member_data[4] = str(float(member_data[4]) + investment_amount)
                    found = True
                file.write(" ".join(member_data) + "\n")

        if found:
            print("Investment added successfully!!!")
        else:
            print("Member not found.")

    except FileNotFoundError:
        print("Error: Unable to open member data file.")
    except ValueError:
        print("Error: Invalid data format in the member data file.")



class Expense:
    def __init__(self):
        self.date = ""
        self.description = ""
        self.amount = 0.0

    def add_expense(self):
        self.date = input("Enter date (YYYY-MM-DD): ")
        self.description = input("Enter description: ")
        try:
            self.amount = float(input("Enter amount: "))
        except ValueError:
            print("Invalid input. Please enter a valid numeric amount.")
            return

        try:
            with open("expenses.txt", "a") as file:
                file.write(f"{self.date} {self.description} {self.amount}\n")
            print("Expense added successfully!!!!")
        except FileNotFoundError:
            print("Error: Unable to open expense data file.")

    def view_expenses(self):
        try:
            with open("expenses.txt", "r") as file:
                print("\n--- Expense List ---")
                for line in file:
                    expense_data = line.strip().split()
                    print(f"Date: {expense_data[0]}, Description: {expense_data[1]}, Amount: {expense_data[2]}")
        except FileNotFoundError:
            print("Error: Unable to open expense data file.")


class Meal:
    def __init__(self):
        self.member_id = 0
        self.date = ""
        self.meals = 0

    def add_meal(self):
        self.member_id = int(input("Enter member ID: "))
        self.date = input("Enter date (YYYY-MM-DD): ")
        self.meals = int(input("Enter number of meals: "))

        try:
            with open("meals.txt", "a") as file:
                file.write(f"{self.member_id} {self.date} {self.meals}\n")
            print("Meal added successfully!")
        except FileNotFoundError:
            print("Error: Unable to open meal data file.")

    def view_meals(self):
        try:
            with open("meals.txt", "r") as file:
                print("\n--- Meal List ---")
                for line in file:
                    meal_data = line.strip().split()
                    print(f"Member ID: {meal_data[0]}, Date: {meal_data[1]}, Meals: {meal_data[2]}")
        except FileNotFoundError:
            print("Error: Unable to open meal data file.")

class MessSystem:
    @staticmethod
    def calculate_bill():
        total_expenses = 0.0
        total_meals = 0

        try:
            with open("expenses.txt", "r", encoding="utf-8") as file:
                for line in file:
                    expense_data = line.strip().split()
                    total_expenses += float(expense_data[2])
        except FileNotFoundError:
            return None, None, None  # Indicate error

        try:
            with open("meals.txt", "r") as file:
                for line in file:
                    meal_data = line.strip().split()
                    total_meals += int(meal_data[2])
        except FileNotFoundError:
            return None, None, None  # Indicate error

        meal_rate = total_expenses / total_meals if total_meals > 0 else 0
        return total_expenses, total_meals, meal_rate

    @staticmethod
    def get_member_bills(meal_rate):
        member_bills = []
        try:
            with open("members.txt", "r") as file:
                for line in file:
                    member_data = line.strip().split()
                    try:  # Handle potential ValueError if data is corrupted
                        member_id, member_name = int(member_data[0]), member_data[1]
                        meal_count, investment = int(member_data[3]), float(member_data[4])
                        bill = meal_count * meal_rate
                        net_expense = bill - investment
                        member_bills.append([member_id, member_name, bill, investment, net_expense])
                    except (ValueError, IndexError): #handle both value and index error
                        print(f"Skipping invalid data line: {line.strip()}")
                        continue  # Skip to the next line
            return member_bills
        except FileNotFoundError:
            return None

    @staticmethod
    def manage_member_expense():
        total_expenses, total_meals, meal_rate = MessSystem.calculate_bill()
        if total_expenses is None: #check total expenses not None
            return None
        return MessSystem.get_member_bills(meal_rate)
class MessApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Mess Management System")
        self.user = User()
        self.member = Member()
        self.expense = Expense()
        self.meal = Meal()
        self.mess_system = MessSystem()
        self.current_frame = None  # To track the current frame

        self.create_login_register_widgets()

    def switch_frame(self, frame_class):
        new_frame = frame_class(self)
        if self.current_frame is not None:
            self.current_frame.destroy()
        self.current_frame = new_frame
        self.current_frame.pack()

    def create_login_register_widgets(self):
        self.switch_frame(LoginRegisterFrame)

    def create_main_menu(self):
        self.switch_frame(MainMenuFrame)


class LoginRegisterFrame(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        tk.Label(self, text="Username:").grid(row=0, column=0)
        self.username_entry = tk.Entry(self)
        self.username_entry.grid(row=0, column=1)

        tk.Label(self, text="Password:").grid(row=1, column=0)
        self.password_entry = tk.Entry(self, show="*")
        self.password_entry.grid(row=1, column=1)

        tk.Button(self, text="Login", command=self.login).grid(row=2, column=0, columnspan=2)
        tk.Button(self, text="Register", command=self.register).grid(row=3, column=0, columnspan=2)

    def login(self):
        username = self.username_entry.get()
        password = self.password_entry.get()
        if self.master.user.login(username, password):
            messagebox.showinfo("Success", "Login successful!")
            self.master.create_main_menu()
        else:
            messagebox.showerror("Error", "Invalid credentials.")

    def register(self):
        username = self.username_entry.get()
        password = self.password_entry.get()
        if self.master.user.register_user(username, password):
            messagebox.showinfo("Success", "Registration successful!")
        else:
            messagebox.showerror("Error", "Registration failed.")
class AddMemberWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Add Member")

        # Labels and Entry fields for member details
        tk.Label(self, text="Name:").grid(row=0, column=0, padx=5, pady=5)
        self.name_entry = tk.Entry(self)
        self.name_entry.grid(row=0, column=1, padx=5, pady=5)

        tk.Label(self, text="ID:").grid(row=1, column=0, padx=5, pady=5)
        self.id_entry = tk.Entry(self)
        self.id_entry.grid(row=1, column=1, padx=5, pady=5)

        tk.Label(self, text="Contact Number:").grid(row=2, column=0, padx=5, pady=5)
        self.contact_entry = tk.Entry(self)
        self.contact_entry.grid(row=2, column=1, padx=5, pady=5)

        tk.Label(self, text="Investment:").grid(row=3, column=0, padx=5, pady=5)
        self.investment_entry = tk.Entry(self)
        self.investment_entry.grid(row=3, column=1, padx=5, pady=5)

        # Button to submit member details
        tk.Button(self, text="Add Member", command=self.add_member).grid(row=4, column=0, columnspan=2, pady=10)are placed using grid

    def add_member(self):
        try:
            member_id = int(self.id_entry.get())  # Get and convert ID to integer
            name = self.name_entry.get()  # Get name
            contact = self.contact_entry.get()  # Get contact

            # Call the Member class's add_member method
            if self.master.member.add_member(member_id, name, contact):
                messagebox.showinfo("Success", "Member added successfully!")
                self.destroy()  # Close the Add Member window after success
            else:
                messagebox.showerror("Error", "Failed to add member. Check if the ID already exists or other error.")

        except ValueError:
            messagebox.showerror("Error", "Invalid ID. Please enter a valid integer ID.")
        except Exception as e:  # Catch other potential errors
            messagebox.showerror("Error", f"An unexpected error occurred: {e}")

class ViewMembersWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("View Members")

        members = master.member.view_members()

        if members:
            tree = tk.Treeview(self, columns=("ID", "Name", "Contact", "Meals", "Investment"), show="headings")
            tree.heading("ID", text="ID")
            tree.heading("Name", text="Name")
            tree.heading("Contact", text="Contact")
            tree.heading("Meals", text="Meals")
            tree.heading("Investment", text="Investment")
            for member in members:
                try:
                    tree.insert("", tk.END, values=member)
                except IndexError:
                    print(f"Skipping invalid member data: {member}")
                    continue
            tree.pack(fill="both", expand=True) #Treeview is packed to show in window
        else:
            tk.Label(self, text="No members found.").pack()

class RemoveMemberWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Remove Member")

        tk.Label(self, text="Enter Member ID to Remove:").pack(padx=5, pady=5)
        self.id_entry = tk.Entry(self)
        self.id_entry.pack(padx=5, pady=5)

        tk.Button(self, text="Remove", command=self.remove_member).pack(pady=10) #Widgets are placed using pack

    def remove_member(self):
        try:
            id_to_remove = int(self.id_entry.get())
            if self.master.member.remove_member(id_to_remove):
                messagebox.showinfo("Success", "Member removed successfully!")
                self.destroy()
            else:
                messagebox.showerror("Error", "Member not found.")
        except ValueError:
            messagebox.showerror("Error", "Invalid ID. Please enter a number.")
        except Exception as e:
            messagebox.showerror("Error", f"An unexpected error occurred: {e}")

        class AddInvestmentWindow(tk.Toplevel):
            def __init__(self, master):
                super().__init__(master)
                self.title("Add Investment")

                tk.Label(self, text="Member ID:").grid(row=0, column=0, padx=5, pady=5)
                self.id_entry = tk.Entry(self)
                self.id_entry.grid(row=0, column=1, padx=5, pady=5)

                tk.Label(self, text="Investment Amount:").grid(row=1, column=0, padx=5, pady=5)
                self.amount_entry = tk.Entry(self)
                self.amount_entry.grid(row=1, column=1, padx=5, pady=5)

                tk.Button(self, text="Add Investment", command=self.add_investment).grid(row=2, column=0, columnspan=2,
                                                                                         pady=10)  # Widgets are placed using grid
            def add_investment(self):
                try:
                    member_id = int(self.id_entry.get())
                    investment_amount = float(self.amount_entry.get())

                    # Call a method to update the investment (you'll need to implement this)
                    if self.update_member_investment(member_id, investment_amount):
                        messagebox.showinfo("Success", "Investment added successfully!")
                        self.destroy()
                    else:
                        messagebox.showerror("Error", "Failed to add investment. Check Member ID or amount.")

                except ValueError:
                    messagebox.showerror("Error", "Invalid input. Please enter numbers.")
                except Exception as e:
                    messagebox.showerror("Error", f"An unexpected error occurred: {e}")

            def update_member_investment(self, member_id, investment_amount):
                try:
                    with open("members.txt", "r") as file:
                        lines = file.readlines()

                    found = False
                    with open("members.txt", "w") as file:
                        for line in lines:
                            member_data = line.strip().split()
                            try:
                                if int(member_data[0]) == member_id:
                                    current_investment = float(member_data[4])
                                    member_data[4] = str(current_investment + investment_amount)
                                    found = True
                            except (IndexError, ValueError):
                                print(f"Skipping invalid line: {line.strip()}")
                                continue
                            file.write(" ".join(member_data) + "\n")

                    return found

                except FileNotFoundError:
                    print("Members file not found.")
                    return False
                except Exception as e:
                    print(f"An error occurred: {e}")
                    return False

        class AddExpenseWindow(tk.Toplevel):
            def __init__(self, master):
                super().__init__(master)
                self.title("Add Expense")

                tk.Label(self, text="Date (YYYY-MM-DD):").grid(row=0, column=0, padx=5, pady=5)
                self.date_entry = tk.Entry(self)
                self.date_entry.grid(row=0, column=1, padx=5, pady=5)

                tk.Label(self, text="Description:").grid(row=1, column=0, padx=5, pady=5)
                self.description_entry = tk.Entry(self)
                self.description_entry.grid(row=1, column=1, padx=5, pady=5)

                tk.Label(self, text="Amount:").grid(row=2, column=0, padx=5, pady=5)
                self.amount_entry = tk.Entry(self)
                self.amount_entry.grid(row=2, column=1, padx=5, pady=5)

                tk.Button(self, text="Add Expense", command=self.add_expense).grid(row=3, column=0, columnspan=2,
                                                                                   pady=10)  # Widgets are placed using grid

    def add_expense(self):
        try:
            date = self.date_entry.get()
            description = self.description_entry.get()
            amount = float(self.amount_entry.get())

            if self.master.expense.add_expense(date, description, amount):  # Call Expense class method
                messagebox.showinfo("Success", "Expense added successfully!")
                self.destroy()  # Close the window
            else:
                messagebox.showerror("Error", "Failed to add expense.")

        except ValueError:
            messagebox.showerror("Error", "Invalid amount. Please enter a number.")
        except Exception as e:
            messagebox.showerror("Error", f"An unexpected error occurred: {e}")

        class ViewExpensesWindow(tk.Toplevel):
            def __init__(self, master):
                super().__init__(master)
                self.title("View Expenses")
                expenses = self.master.expense.view_expenses()

                if expenses:
                    tree = tk.Treeview(self, columns=("Date", "Description", "Amount"), show="headings")
                    tree.heading("Date", text="Date")
                    tree.heading("Description", text="Description")
                    tree.heading("Amount", text="Amount")

                    for expense in expenses:
                        try:
                            tree.insert("", tk.END, values=expense)
                        except IndexError:
                            print(f"Skipping invalid expense data: {expense}")
                            continue
                    tree.pack(fill="both", expand=True)  # Treeview is packed to show in window
                else:
                    tk.Label(self, text="No expenses found.").pack()

        class AddMealWindow(tk.Toplevel):
            def __init__(self, master):
                super().__init__(master)
                self.title("Add Meal")

                tk.Label(self, text="Member ID:").grid(row=0, column=0, padx=5, pady=5)
                self.member_id_entry = tk.Entry(self)
                self.member_id_entry.grid(row=0, column=1, padx=5, pady=5)

                tk.Label(self, text="Date (YYYY-MM-DD):").grid(row=1, column=0, padx=5, pady=5)
                self.date_entry = tk.Entry(self)
                self.date_entry.grid(row=1, column=1, padx=5, pady=5)

                tk.Label(self, text="Number of Meals:").grid(row=2, column=0, padx=5, pady=5)
                self.meals_entry = tk.Entry(self)
                self.meals_entry.grid(row=2, column=1, padx=5, pady=5)

                tk.Button(self, text="Add Meal", command=self.add_meal).grid(row=3, column=0, columnspan=2,
                                                                             pady=10)  # Widgets are placed using grid

    def add_meal(self):
        try:
            member_id = int(self.member_id_entry.get())
            date = self.date_entry.get()
            meals = int(self.meals_entry.get())

            if self.master.meal.add_meal(member_id, date, meals):
                messagebox.showinfo("Success", "Meal added successfully!")
                self.destroy()
            else:
                messagebox.showerror("Error", "Failed to add meal.")
        except ValueError:
            messagebox.showerror("Error", "Invalid input. Please enter numbers for ID and meals.")
        except Exception as e:
            messagebox.showerror("Error", f"An unexpected error occurred: {e}")

class ViewMealsWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("View Meals")
        meals = self.master.meal.view_meals()

        if meals:
            tree = tk.Treeview(self, columns=("Member ID", "Date", "Meals"), show="headings")
            tree.heading("Member ID", text="Member ID")
            tree.heading("Date", text="Date")
            tree.heading("Meals", text="Meals")

            for meal in meals:
                try:
                    tree.insert("", tk.END, values=meal)
                except IndexError:
                    print(f"Skipping invalid meal data: {meal}")
                    continue
            tree.pack(fill="both", expand=True) #Treeview is packed to show in window
        else:
            tk.Label(self, text="No meals found.").pack()

class MainMenuFrame(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.master = master  # Store the master for easier access

        # Use a consistent grid layout
        self.columnconfigure(0, weight=1)  # Make columns expandable
        self.columnconfigure(1, weight=1)

        tk.Button(self, text="Add Member", command=self.add_member_window).grid(row=0, column=0, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="View Members", command=self.view_members).grid(row=0, column=1, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="Remove Member", command=self.remove_member_window).grid(row=1, column=0, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="Add Investment", command=self.add_investment_window).grid(row=1, column=1, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="Add Expense", command=self.add_expense_window).grid(row=2, column=0, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="View Expenses", command=self.view_expenses).grid(row=2, column=1, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="Add Meal", command=self.add_meal_window).grid(row=3, column=0, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="View Meals", command=self.view_meals).grid(row=3, column=1, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="Calculate Bill", command=self.calculate_bill).grid(row=4, column=0, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="Show Member Expenses", command=self.manage_member_expense).grid(row=4, column=1, sticky="ew", padx=5, pady=5)
        tk.Button(self, text="Logout", command=self.logout).grid(row=5, column=0, columnspan=2, sticky="ew", padx=5, pady=5)

    def logout(self):
        self.master.create_login_register_widgets()

    def add_member_window(self):
        AddMemberWindow(self.master)

    def view_members(self):
        ViewMembersWindow(self.master)

    def remove_member_window(self):
        RemoveMemberWindow(self.master)

    def add_investment_window(self):
        AddInvestmentWindow(self.master)

    def add_expense_window(self):
        AddExpenseWindow(self.master)

    def view_expenses(self):
        ViewExpensesWindow(self.master)

    def add_meal_window(self):
        AddMealWindow(self.master)

    def view_meals(self):
        ViewMealsWindow(self.master)

    def calculate_bill(self):
        total_expenses, total_meals, meal_rate = self.master.mess_system.calculate_bill()
        if total_expenses is not None:
            messagebox.showinfo("Bill Information", f"Total Expenses: {total_expenses}\nTotal Meals: {total_meals}\nMeal Rate: {meal_rate:.2f}")
        else:
            messagebox.showerror("Error", "Could not calculate bill. Check expense and meal data.")


    def manage_member_expense(self):
         member_expenses = self.master.mess_system.manage_member_expense()
         if member_expenses is not None:
             output_string = ""
             for member in member_expenses:
                 output_string += f"ID: {member[0]}, Name: {member[1]}, Bill: {member[2]:.2f}, Investment: {member[3]:.2f}, Net Expense: {member[4]:.2f}\n"
             messagebox.showinfo("Member Expenses", output_string)
         else:
             messagebox.showerror("Error", "Could not calculate member expenses.")


class AddMemberWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Add Member")
        # ... (Add member form widgets and logic here)


class ViewMembersWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("View Members")
        # ... (View members display logic here)


class RemoveMemberWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Remove Member")


class AddInvestmentWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Add Investment")


class AddExpenseWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Add Expense")


class ViewExpensesWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("View Expenses")


class AddMealWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("Add Meal")


class ViewMealsWindow(tk.Toplevel):
    def __init__(self, master):
        super().__init__(master)
        self.title("View Meals")


if __name__ == "__main__":
    for filename in ["users.txt", "members.txt", "expenses.txt", "meals.txt"]:
        if not os.path.exists(filename):
            open(filename, 'a').close()
    app = MessApp()
    app.mainloop()