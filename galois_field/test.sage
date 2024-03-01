

k = GF(3)
v = k.fetch_int(0)
print(type(v))
print(v)

g = GF(2^2)
b = g.fetch_int(0)
print(type(v))
print(v)

def inverse(a, field):
    for x in range(field):
        if(a*x)%field ==1:
            return x

#addition of different fields is not allowed
#print(b+v)

for i in range(1,3):
    v = k.fetch_int(i)
    v = inverse(int(v),3)
    print(v)
print()

for i in range(1,4):
    v = g.fetch_int(i)
    v = 1/v
    print(v.integer_representation())

def is_power_of_two(n):
    return n > 0 and (n & (n - 1)) == 0

# Example usage
print(is_power_of_two(1))   # True, as 2^0 = 1
print(is_power_of_two(2))   # True, as 2^1 = 2
print(is_power_of_two(3))   # False, not a power of 2
print(is_power_of_two(4))   # True, as 2^2 = 4
print(is_power_of_two(16))  # True, as 2^4 = 16
print(is_power_of_two(18))  # False, not a power of 2
