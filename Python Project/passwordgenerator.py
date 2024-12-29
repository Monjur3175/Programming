import random

chars="qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&*()_"
lenght=int(input("Enter the lenght: "))
password=""
for a in range(lenght):
    password+=random.choice(chars)

print(password)