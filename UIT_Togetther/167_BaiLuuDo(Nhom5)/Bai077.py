k = eval(input("Nhap k: "))
n = eval(input("Nhap n: "))

s =0
i=1

while i<=n:
    s=s+pow(i,k)
    i=i+1

print(s)