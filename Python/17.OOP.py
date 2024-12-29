class Employee:
    def __init__(self,name,salary):
        self.name=name
        self.salary=salary

    def getsalary(self):
        print(self.salary)

Raihan = Employee("Monjur","546699")
print(Raihan.salary)
print(Raihan.name)
Raihan.getsalary()
