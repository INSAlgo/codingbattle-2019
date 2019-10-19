# read and store p, b and f as integers from the input (3 lines)
p = int(input())
b = int(input())
f = int(input())

# print the expected result, that is to say:
# p - (500 x f + 4 x b) if this number is positive;
# 0 otherwise
print(max(p - (500*f + 4*b), 0))
