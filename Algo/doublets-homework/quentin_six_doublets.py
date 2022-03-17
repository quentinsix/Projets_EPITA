# -*- coding: utf-8 -*-
__license__ = 'Junior (c) EPITA'
__docformat__ = 'reStructuredText'
__revision__ = '$Id: doublets.py 2020-12-01'

"""
Doublet homework
2020-12
@author: quentin.six
"""

from algopy import graph, queue


###############################################################################
# Do not change anything above this line, except your login!
# Do not add any import


#   LEVEL 0

def __one_char_diff(word1,word2):
	cpt=0
	i=0
	while(i<len(word1) and cpt<=1):
		if(word1[i]!=word2[i]):
			cpt+=1
		i+=1
	return cpt==1



def build_graph(filename, k):
    """Build a graph with words of length k from a lexicon

    """
    G=graph.Graph(0,False,[])
    file=open(filename,"r")
    list_words=[]
    for word in file.readlines():
    	if(len(word.strip())==k):
    		G.labels.append(word.strip())
    file.close()
    G.order=len(G.labels)
    for i in range(G.order):
    	G.adjlists.append([])
    	for j in range(G.order):
    		if __one_char_diff(G.labels[j],G.labels[i]):
    			G.adjlists[i].append(j)
    return G

# G1=build_graph("lex_first.txt",3)
# G5=build_graph("lex_some.txt",3)
# G6=build_graph("lex_some.txt",4)

###############################################################################
#   LEVEL 1

def most_connected(G):
    """ The list of words that are directly linked to the most other words in G

    """
    maxi=0
    L=[]
    for lists in G.adjlists:
        if maxi<len(lists):
            maxi=len(lists)
    for i in range(G.order):
        if len(G.adjlists[i])==maxi:
            L.append(G.labels[i])
    return L

# print(most_connected(G1))

def is_chain(G, L):
    """ Test if L is a valid elementary *chain* in the graph G

    """
    try:
        a=G.labels.index(L[0])
    except ValueError:
        return False
    liste=[None]*G.order
    liste[a]=True
    for i in range(1,len(L),1):
        try:
            b=G.labels.index(L[i])
        except ValueError:
            return False
        if liste[b]:
        	return False
        else:
            liste[b]=True
            try:
                k=G.adjlists[a].index(b)
            except ValueError:
                return False
            a=b
    return True

# print(is_chain(G1,["ape","apt","man"]))

###############################################################################
#   LEVEL 2

def __dfs(G, x, M):
    M[x]=True
    for y in G.adjlists[x]:
        if not M[y]:
            __dfs(G,y,M)

def all_doublets(G, start):
    """ All words that can form a *doublet* with the start word in the lexicon in G

    """
    try:
        pos=G.labels.index(start)
    except ValueError:
        return []
    L=[None]*G.order
    __dfs(G,pos,L)
    liste=[]
    for i in range(G.order):
        if i!=pos and L[i]:
            liste.append(G.labels[i])
    return liste

# print(all_doublets(G1,G1.labels[0]))

def __bfs(G, s, dst, P):
    q=queue.Queue()
    q.enqueue(s)
    P[s]=-1
    while not q.isempty():
        x=q.dequeue()
        for y in G.adjlists[x]:
            if P[y]==None:
                P[y]=x
                if y==dst:
                    return True
                q.enqueue(y)
    return False
        

def __path_bfs(G, src, dst):
    P=[None]*G.order
    path=[]
    if __bfs(G,src,dst,P):
        while dst != -1:
            path.insert(0,dst)
            dst=P[dst]
    return path




def ladder(G,start,end):
    """ Find a *ladder* to the *doublet* (start, end) in G

    """
    try:
        pos1=G.labels.index(start)
        pos2=G.labels.index(end)
    except ValueError:
        return []
    path = __path_bfs(G,pos1,pos2)
    liste=[]
    for i in range(len(path)):
    	liste.append(G.labels[path[i]])
    return liste


# print(ladder(G1,"ape","man"))

###############################################################################
#   LEVEL 3

def no_solution(G):
    """ Find a *doublet* without solution in G
    
    """
    L=[None]*G.order
    __dfs(G,0,L)
    liste=[]
    for i in range(G.order):
        if L[i]==None:
            return (G.labels[0],G.labels[i])
    return (None,None)


# print(no_solution(G1))

def longest_doublet(G):
	L=ladder(G,G.labels[0],G.labels[1])
	for i in range(G.order):
		for j in range(i,G.order,1):
			liste=ladder(G,G.labels[i],G.labels[j])
			if len(L)<len(liste):
				L=liste
	return (L[0],L[len(L)-1],len(L))

# print(longest_doublet(G5))
# print(longest_doublet(G6))


###############################################################################
#   BONUS (just for the fun...)

def isomorphic(G1, G2):
    """BONUS: test if G1 and G2 are isomorphic

    """
    #FIXME
    pass
    
