import math

x = eval(input("Nhap x: "))
n = eval(input("Nhap n: "))

s = 0
t = 1
i = 1
while i <= n:
    t *= x
    s = math.sqrt(t + s)
    i += 1

print(s)
