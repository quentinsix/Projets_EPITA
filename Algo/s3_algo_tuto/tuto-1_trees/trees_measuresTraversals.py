# -*- coding: utf-8 -*-

from algopy import tree, treeasbin
from algopy import queue

"""
Measures
"""

def size(T):
    """
    T: Tree
    """    
    s = 1
    for i in range(T.nbchildren):
        s += size(T.children[i])
    return s

def sizeasbin(B):
    """
    B: TreeAsBin
    """    
    s = 1
    child = B.child
    while child != None :
        s += sizeasbin(child)
        child = child.sibling
    return s

def sizeasbin2(B):
    if B == None:
        return 0
    else:
        return 1 + sizeasbin2(B.child) + sizeasbin2(B.sibling)
                
# height

def height(T):
    h = 0
    for child in T.children:
        h = max(h, height(child)+1)
    return h

def heightasbin(B):
    h = -1
    C = B.child
    while C != None:
        h = max(h, heightasbin(C))
        C = C.sibling
    return h + 1

def heightasbin2(B):
    if B == None:
        return -1
    else:
        return max(1 + heightasbin2(B.child), heightasbin2(B.sibling))


     
"""
Traversals
"""

"""
Depth First Search
"""

# simple DFS (without intermediate)

def dfs(T):
    print(T.key)    # preorder
    for child in T.children:
        dfs(child)
    # postorder

def dfsasbin(B):
    print(B.key)    # preorder
    C = B.child
    while C:
        dfs(C)
        C = C.sibling
    # postorder

# full dfs (with intermediate)        

def dfs_full(T):
    print(T.key)    # preorder
    if T.nbchildren != 0:
        for i in range(T.nbchildren - 1):
            dfs(T.children[i])
            # intermediate
        dfs(T.children[T.nbchildren-1])
    # postorder
        
def dfsasbin_full(B):
    print(B.key) # preorder
    if B.child != None:
        child = B.child
        while child.sibling != None:
            dfsasbin(child)
            child = child.sibling
             # intermediate
        dfsasbin(child)
    # postorder
        

"""
Breadth First Search
"""


# first version: a "end level mark" (None) is added in the queue

def bfs(T):
    """
    returns the width of T (Tree)
    """
    q = queue.Queue()
    q.enqueue(T)
    q.enqueue(None)
    (cur, m) = (0, 0)
    
    while not q.isempty():
        T = q.dequeue()
        if T == None:
            m = max(m, cur)
            cur = 0
            if not q.isempty():
                q.enqueue(None)
        else:
            cur += 1
            for child in T.children:
                q.enqueue(child)
    return m

#second version: two queues + does not computes width: displays keys...

def bfsasbin(B):
    """
    B: TreeAsBin
    """
    q = queue.Queue()
    q2 = queue.Queue()
    q.enqueue(B)
    while not q.isempty():
        B = q.dequeue()
        print(B.key)
        child = B.child
        while child:
            q2.enqueue(child)
            child = child.sibling
        if q.isempty():
            print()
            (q, q2) = (q2, q)
