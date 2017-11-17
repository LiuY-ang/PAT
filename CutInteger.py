def solution():
    n=input()
    for i in range(n):
        num=input()
        numstr=str(num)
        a=int(numstr[0:len(numstr)/2])
        b=int(numstr[len(numstr)/2:])
        # print a,b
        divisor=a*b
        if divisor==0:
            print "No"
            continue
        result= (num%(divisor)==0)
        print ("Yes" if result==True else "No")
solution()
