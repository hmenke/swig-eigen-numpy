import example

t = example.Test()

print("vector view")

x = t.viewvec()
print(x)
t.showvec()
x[0] = 5
print(x)
t.showvec()

print("vector copy")

y = t.copyvec()
print(y)
t.showvec()
y[0] = -2
y.resize(10)
print(y)
t.showvec()

print("getvec")

t.getvec(y)
print(y)

print("matrix view")

x = t.viewmat()
print(x)
t.showmat()
x[0] = 5+2j
print(x)
t.showmat()

print("matrix copy")

y = t.copymat()
print(y)
t.showmat()
y[0] = -2
print(y)
t.showmat()

print("getmat")

t.getmat(y)
print(y)


print("sparse matrix view")

x = t.viewspmat()
print(x)
t.showspmat()
x[0] = 5+2j
print(x)
t.showspmat()

print("sparse matrix copy")

y = t.copyspmat()
print(y)
t.showspmat()
y[0] = -2
print(y)
t.showspmat()

print("getspmat")

t.getspmat(y)
print(y)

print("killvec")

x = t.viewvec()
print(x)
t.killvec()
print(x)
x[0] = 5
print(x)
t.showvec()

print("killmat")

x = t.viewmat()
print(x)
t.killmat()
print(x)
x[0] = 5
print(x)
t.showmat()

print("killspmat")

x = t.viewspmat()
print(x)
t.killspmat()
print(x)
x[0] = 5
print(x)
t.showspmat()

print("Calling Python destructors!")
