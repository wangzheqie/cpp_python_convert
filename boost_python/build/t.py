#/usr/bin/env python2.7
# -*- coding: utf-8 -*-

from  inner_member_pointer import PyB
from  inner_member_pointer import PyTheA
from  inner_member_pointer import PyA

b = PyB()
b.init() # if not init(), b.getA() is None
print(b.getWidth())

# new a PyTheA in python
a = PyTheA()
print(a)
print(type(a))
a.capImage()
print(a.getWidth())

# return a PyThA from c++
the_a = b.getA()
print(the_a)
print(type(the_a))
the_a.capImage()
# print(the_a.getWidth())

