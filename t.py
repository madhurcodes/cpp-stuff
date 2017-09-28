import random
hlist = []
for i in range(10000):
    liv = 3
    h = 0
    t = 0
    while(liv>0):
        t = random.random()
        if( t <= 0.1):
            liv -=1
        else:
            if(liv == 2 or (liv ==3)):
                liv = 3
            else:
                liv+=1
        h+=1
    hlist.append(h)
print((sum(hlist)*1.0)/len(hlist))
    