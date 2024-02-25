from fractions import Fraction
x = Fraction(1, 2)
y = Fraction(1)
print(x.as_integer_ratio()) # print 1/2
# print(x.is_integer())
print(x.__round__())
print(float(x))