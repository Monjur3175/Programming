import customtkinter
import tkinter as tk
from tkinter import messagebox

customtkinter.set_appearance_mode("System")  # Modes: "System" (standard), "Dark", "Light"
customtkinter.set_default_color_theme("blue")  # Themes: "blue" (standard), "green", "dark-blue"


class App(customtkinter.CTk):
    def __init__(self):
        super().__init__()

        self.title("CustomTkinter Login")
        self.geometry("400x300")

        # Configure grid layout (4x4)
        self.grid_columnconfigure(0, weight=1)
        self.grid_rowconfigure((0, 1, 2), weight=1)

        self.frame = customtkinter.CTkFrame(master=self)
        self.frame.grid(row=0, column=0, padx=20, pady=20, sticky="nsew")

        self.frame.grid_columnconfigure(0, weight=1)
        self.frame.grid_rowconfigure((0, 1, 2, 3), weight=1)

        self.label = customtkinter.CTkLabel(master=self.frame, text="Login",
                                            font=customtkinter.CTkFont(size=20, weight="bold"))
        self.label.grid(row=0, column=0, pady=(0, 20))

        self.username_entry = customtkinter.CTkEntry(master=self.frame, placeholder_text="Username")
        self.username_entry.grid(row=1, column=0, pady=(0, 10))

        self.password_entry = customtkinter.CTkEntry(master=self.frame, placeholder_text="Password",
                                                     show="*")  # Show asterisks for password
        self.password_entry.grid(row=2, column=0, pady=(0, 10))

        self.login_button = customtkinter.CTkButton(master=self.frame, text="Login", command=self.login_event)
        self.login_button.grid(row=3, column=0, pady=(0, 10))

        self.checkbox = customtkinter.CTkCheckBox(master=self.frame, text="Remember Me")
        self.checkbox.grid(row=4, column=0, pady=(0, 10))

    def login_event(self):
        username = self.username_entry.get()
        password = self.password_entry.get()

        # Basic validation (replace with your actual login logic)
        if username == "test" and password == "password":
            messagebox.showinfo("Login Successful", "Welcome!")
            # Optionally, you might want to close the login window:
            # self.destroy()
        else:
            messagebox.showerror("Login Failed", "Incorrect username or password.")


if __name__ == "__main__":
    app = App()
    app.mainloop()