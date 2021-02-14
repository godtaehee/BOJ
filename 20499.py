s = input()
kda = s.split('/')
if int(kda[0])+int(kda[2]) < int(kda[1]) or int(kda[1]) == 0:
    print("hasu")
else:
    print("gosu")
    
