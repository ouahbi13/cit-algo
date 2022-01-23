'''
    The minimum distance to light the whole street is either:
        - The position of the first lantern (imagine the situation where the position of all the latnerns is l)
        - The difference of the length of the street and the last lantern (imagine all lanterns are positioned in 0)
        - The half of the maximum difference between two laterns: max[ (a_(i+1)-a_i)/2 ]
'''

n, l = list(map(int, input().split(' ')))
positions = list(map(int, input().split(' ')))
positions.sort()

max_diff = 0
for i in range(n-1):
    if positions[i+1] - positions[i] > max_diff:
        max_diff = positions[i+1] - positions[i]

print(max([positions[0], max_diff/2, l-positions[n-1]]))