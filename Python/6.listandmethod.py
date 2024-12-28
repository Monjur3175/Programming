#List is mutable

l1=[89,3,5,123,7,"Monjur"]
print(type(l1))
print(l1)
l1.remove("Monjur")
print(l1.count(123))
l1.sort()
print(l1)
l1.pop()
print(l1)

l1.extend([5,6,9,222])
print(l1)


print(l1.index(222))
#l1.clear()
#print(l1)

l1[0]="M"
print(l1)
