#1,1,2,2,1,2,7
def singleNumber(num,n):
    ones=0;twos=0
    for e in range(n):
        ones=(ones^e)&(~twos)
        twos=(twos^e)&(~ones)
    return ones
num=[1,1,2,2,1,2,7]
print singleNumber(num,len(num))
