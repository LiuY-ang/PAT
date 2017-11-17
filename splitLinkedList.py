#-*— coding:utf-8 -*-
def solution():
    fnk=raw_input().split(" ")
    firstAdress=fnk[0];n=int(fnk[1]);k=int(fnk[2])
    if n==0:#链表的节点个数为0，则直接返回
        return
    negative=[];greater=[];ok=[];mapping={}#negative存储负数，greater存储大于k的数，ok存储在[0,k]之间的数
    for i in range(n):
        avn=raw_input().split(" ")#处理输入
        mapping[avn[0]]=avn#按照地址存储在map中
    nextAdress=firstAdress#从链表中的第一个节点开始遍历“链表”
    while nextAdress!='-1':
        avn=mapping[nextAdress]
        val=int(avn[1])#分开存储节点中的值
        if val<0:
            negative.append(avn)
        elif val>k:
            greater.append(avn)
        else:
            ok.append(avn)
        nextAdress=avn[2]#赋值为下一个节点的值
    negativelength=len(negative);oklength=len(ok);greaterlength=len(greater)#得到个节点的长度
    if negativelength!=0:#先输出负数
        i=0
        while i<negativelength-1:
            print negative[i][0],negative[i][1],negative[i+1][0]
            i+=1
        if oklength==0 and greaterlength==0:#如果只有负数的情况
            print negative[i][0],negative[i][1],"-1"
        elif greaterlength!=0 and oklength==0:#没有在[0,k]中的数
            print negative[i][0],negative[i][1],greater[0][0]
        else:#其它情况下，即ok数组的长度不为0的情况
            print negative[i][0],negative[i][1],ok[0][0]
    if oklength!=0:#输出[0,k]之间的数
        i=0
        while i<oklength-1:
            print ok[i][0],ok[i][1],ok[i+1][0]
            i+=1
        if greaterlength==0:#如果greaterlength为空的话
            print ok[i][0],ok[i][1],"-1"
        else:#greaterlength不为0
            print ok[i][0],ok[i][1],greater[0][0]
    if greaterlength!=0:#输出大于k的数
        i=0
        while i<greaterlength-1:
            print greater[i][0],greater[i][1],greater[i+1][0]
            i+=1
        print greater[i][0],greater[i][1],'-1'
solution()
