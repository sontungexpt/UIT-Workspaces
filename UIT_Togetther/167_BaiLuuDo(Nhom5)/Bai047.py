import math
n = eval(input("Nhap n: "))

s = 0
i = 1

while i <= n:
    s = s + math.sqrt(1 + 1/(i*i) + 1/((i+1)*(i+1)))
    i = i+1
    
print(s)
