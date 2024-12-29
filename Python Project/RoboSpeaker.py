import pyttsx3

if __name__ == '__main__':
    engine = pyttsx3.init()
    print("Welcome to Robospeaker 1.1 created by Monjur")
    while True:
        x = input("Enter what you want me to speak: ")
        if x.lower() == "q":  
            print("Bye Bye Friend")  
            engine.say("Bye Bye Friend")  
            engine.runAndWait()
            break
        engine.say(x)  
        engine.runAndWait()
