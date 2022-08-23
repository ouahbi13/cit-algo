# L = "{'a':'b', 'n':{'i':'r'}}"
# dicti = eval(L)
# print(type(dicti))
# print(type(dicti['n']['i']))
# S = "{'a':'b', 'book':{'titles':['r','t']}}"
#


def remove(my_string, car):
    s = ""
    for c in my_string:
        if c != car:
            s += c
    return s



def JSONE(S, path):
    dicti = eval(S)
    x = dicti
    if not isinstance(x, dict):
        return None
    for step in path:
        try:
            if '[' not in step:
                x = x[step]

            else:
                substeps = step.split('[')
                substeps = list(map(lambda x: remove(x, ']'), substeps))
                for i in range(len(substeps)):
                    try:
                        x = x[eval(substeps[i])]
                    except:
                        x = x[substeps[i]]


        except:
            return None
    return x

S = input()
Q = int(input())

answers = []
for  i in range(Q):
    path = input().split(".")[1:]
    answers.append((JSONE(S, path)))

for answer in answers:
    print(answer)


