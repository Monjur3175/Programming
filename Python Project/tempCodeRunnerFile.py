import os
if __name__ == '__main__':
    print("Welcome to Robospeaker 1.1 created by Monjur")
    while True:
        x = input("Enter what you want me to speak: ")
        if x.lower() == "q":  # Using `lower()` to handle case-insensitive input
            os.system("say 'Bye Bye Friend'")
            break
        command = f"say '{x}'"  # Add single quotes around the text
        os.system(command)
