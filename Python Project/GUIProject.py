import customtkinter
import tkinter as tk
from tkinter import messagebox
import sqlite3

# Database setup (create if it doesn't exist)
conn = sqlite3.connect('mess_management.db')
cursor = conn.cursor()
cursor.execute('''
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        username TEXT UNIQUE NOT NULL,
        password TEXT NOT NULL,
        is_admin INTEGER DEFAULT 0 -- 0 for regular user, 1 for admin
    )
''')
conn.commit()
conn.close()

customtkinter.set_appearance_mode("System")
customtkinter.set_default_color_theme("blue")

class App(customtkinter.CTk):
    def __init__(self):
        super().__init__()

        self.title("Mess Management Login")
        self.geometry("400x300")

        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure((0, 1, 2), weight=1)

        self.frame = customtkinter.CTkFrame(master=self)
        self.frame.grid(row=0, column=0, padx=20, pady=20, sticky="nsew")

        self.frame.grid_columnconfigure(0, weight=1)
        self.frame.grid_rowconfigure((0, 1, 2, 3), weight=1)

        self.label = customtkinter.CTkLabel(master=self.frame, text="Login", font=customtkinter.CTkFont(size=20, weight="bold"))
        self.label.grid(row=0, column=0, pady=(0, 20))

        self.username_entry = customtkinter.CTkEntry(master=self.frame, placeholder_text="Username")
        self.username_entry.grid(row=1, column=0, pady=(0, 10))

        self.password_entry = customtkinter.CTkEntry(master=self.frame, placeholder_text="Password", show="*")
        self.password_entry.grid(row=2, column=0, pady=(0, 10))

        self.login_button = customtkinter.CTkButton(master=self.frame, text="Login", command=self.login_event)
        self.login_button.grid(row=3, column=0, pady=(0, 10))

    def login_event(self):
        username = self.username_entry.get()
        password = self.password_entry.get()

        try:
            conn = sqlite3.connect('mess_management.db')
            cursor = conn.cursor()
            cursor.execute("SELECT * FROM users WHERE username=? AND password=?", (username, password))
            user = cursor.fetchone()
            conn.close()

            if user:
                messagebox.showinfo("Login Successful", f"Welcome, {username}!")
                # Open the main application window (replace with your main app)
                self.destroy() # Close the login window
                main_app = MainApplication(user[3]) # Pass admin status
                main_app.mainloop()

            else:
                messagebox.showerror("Login Failed", "Incorrect username or password.")

        except sqlite3.Error as e:
            messagebox.showerror("Database Error", str(e))

class MainApplication(customtkinter.CTk):
    def __init__(self, is_admin):
        super().__init__()
        self.title("Mess Management System")
        self.geometry("800x600")

        if is_admin:
            admin_label = customtkinter.CTkLabel(self, text="Admin Panel")
            admin_label.pack()
        else:
            user_label = customtkinter.CTkLabel(self, text="User Panel")
            user_label.pack()
            # Add user functionalities here

if __name__ == "__main__":
    app = App()
    app.mainloop()