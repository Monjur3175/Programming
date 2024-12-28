s="monjur is a good boy"

#Writing in a file

# with open("text.txt","w") as f:
#     f.write(s)

# fp=open("text.txt","w")
# fp.write(s)
# fp.close()

#Reading in a file

# fp=open("monjur.txt","r")
# s=fp.read()
# print(s)

# with open("monjur.txt","r") as f:
#    s= f.read()
#    print(s)

with open("text.txt","a") as f:
    f.write(s)