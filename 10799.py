import sys
input = sys.stdin.readline
s = input()
stk = []
ans = 0
for i in range(len(s)):
    
    if s[i] == '(':
        stk.append(i)
    elif stk:
        if(stk[-1] == i-1):
            stk.pop()
            ans+=len(stk)
        else:
            stk.pop()
            ans+=1

print(ans)
        
