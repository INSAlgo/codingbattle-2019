c = int(input())
n = int(input())
t_blue = []
t_yellow = []
for k in range(n):
    t, size = map(int, input().split())
    if t == 1:
        t_blue.append(size)
    else:
        t_yellow.append(size)
bag = [[set() for i in range(c+1)] for j in range(n+1)]
# fill knapsack with blue items, count how many we use
bag[0][0] = {0}
for k in range(len(t_blue)):
    index = k+1
    for cap in range(c+1):
        bag[index][cap] = bag[index - 1][cap].copy()
        # check if we can put selected item in bag
        if cap-t_blue[k] >= 0:
                # merge old possibilites with new
            bag[index][cap] = bag[index][cap].union(
                map(lambda x: x + 1, bag[index - 1][cap - t_blue[k]]))

# fill knapsack with yellow items, decrease count of objects
for k in range(len(t_yellow)):
    index = k + len(t_blue) + 1
    for cap in range(c+1):
        bag[index][cap] = bag[index - 1][cap].copy()
        # check if we can put selected item in bag
        if cap-t_yellow[k] >= 0:
                # merge old possibilites with new
            bag[index][cap] = bag[index][cap].union(
                map(lambda x: x - 1, bag[index - 1][cap - t_yellow[k]]))
# check last line for occurences of 0 in sets <=> the bag is balanced
best_cap = 0
for k in range(c+1):
    if 0 in bag[-1][k]:
        best_cap = k
print(best_cap)
