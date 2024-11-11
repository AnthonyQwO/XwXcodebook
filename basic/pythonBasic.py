parser:
int(eval(num.replace("/","//")))

from fractions import Fraction
from decimal import Decimal, getcontext, ROUND_HALF_UP, ROUND_CEILING, ROUND_FLOOR
getcontext().prec = 250 # set precision
getcontext().rounding = ROUND_HALF_UP

itwo = Decimal(0.5)
two = Decimal(2)

format(x, '0.10f') # set precision

N = 200
def angle(cosT):
  """given cos(theta) in decimal return theta"""
  for i in range(N):
    cosT = ((cosT + 1) / two) ** itwo
  sinT = (1 - cosT * cosT) ** itwo
  return sinT * (2 ** N)
pi = angle(Decimal(-1))

"""round to 2 decimal places"""
sum = Decimal(input())
sum.quantize(Decimal('.00'), ROUND_HALF_UP)

"""Fraction"""
x = Fraction(1, 3) # 1/3
x.as_integer_ratio() # (1, 3)

"""input list of integers"""
arr = list(map(int, input().split()))

""""把字元轉成ascii再轉回字串"""
chr(ord('a'))
