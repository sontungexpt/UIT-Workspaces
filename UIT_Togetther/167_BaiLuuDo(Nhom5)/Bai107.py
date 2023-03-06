x = eval(input("Nhap x: "))

xx = (x * 3.14)/180

s = 1
t = 1
m = 1
dau = -1
e = 1
i = 2

while e >= 10**-6:
    t = t * xx * xx
    m = m * (i-1)*i
    e = t/m
    s += dau * e
    dau = -dau
    i += 2

print(s)
