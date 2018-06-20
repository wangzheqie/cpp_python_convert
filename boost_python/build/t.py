from  inner_member_pointer import PyB
from  inner_member_pointer import PyTheA

b = PyB()
print(b.getName())
b.init()
print(b.getA())

the_a = PyTheA()
print(the_a.capImage())
print(the_a.getWidth())


b.getA()

#print("the a: ",the_a.capImage())
#print("the a: ", the_a.getWidth())
