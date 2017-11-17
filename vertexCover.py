# -*- coding:utf-8 -*-
def vertexCover():
    n,m=raw_input().split(" ")
    n=int(n);m=int(m)
    adjlist=[[] for i in range(n)]
    # print adjlist
    for i in range(m):
        e1,e2=raw_input().split(" ")
        adjlist[int(e1)].append(int(e2))
        adjlist[int(e2)].append(int(e1))
    k=input()#number of loop
    for i in range(k):
        nv=input()#number of vertexs
        vertexs=[];visited=[]
        vertexs=map(int,raw_input().split(' '))#store vertex
        count=0
        for e in vertexs:#
            for end in adjlist[e]:#
                if end not in visited:
                    count+=1
            visited.append(e)
        print ('No' if count<m else 'Yes')
vertexCover()
