# -*- coding: utf-8 -*-
"""
Oct. 2020
S3 - trees applications
"""

from algopy import tree, treeasbin
from algopy import queue



"""
tree -> dot
"""

# warning: the following versions do not work if keys are not unique 
# see algopy/tree.py for a version that uses id

def dot(T):
    """Write down dot format of tree.

    Args:
        T (Tree).

    Returns:
        str: String storing dot format of tree.

    """

    s = "graph {\n"
    q = queue.Queue()
    q.enqueue(T)
    while not q.isempty():
        T = q.dequeue()
        for child in T.children:
            s = s + "   " + str(T.key) + " -- " + str(child.key) + "\n"
            q.enqueue(child)
    s += "}"
    return s

def dotBin(B):
    """Write down dot format of tree.

    Args:
        B (TreeAsBin).

    Returns:
        str: String storing dot format of tree.

    """

    s = "graph {\n"
    q = queue.Queue()
    q.enqueue(B)
    while not q.isempty():
        B = q.dequeue()
        C = B.child
        while C:
            s = s + "   " + str(B.key) + " -- " + str(C.key) + "\n"
            q.enqueue(C)
            C = C.sibling
    s += "}"
    return s

'''
tree -> list representation
'''

def tree2list(T):
    s = '(' + str(T.key)
    for child in T.children:
        s += tree2list(child)
    s += ')'
    return s

def treeAsBin2list(B):
    s = '(' + str(B.key)
    C = B.child
    while C != None:
        s += treeAsBin2list(C)
        C = C.sibling
    s += ')'
    return s
    

'''
Average Arity: 
sum of the number of children per node divided by the number of internal nodes
'''

# with "classical" implem
def __countnodes(T):
    """
    returns (nb internal nodes, nb children)
    """
    if T.nbchildren == 0:
        return (0, 0)
    internnodes = 1
    nbchildren = T.nbchildren
    for child in T.children:
        (nbi, nbc) = __countnodes(child)
        internnodes += nbi
        nbchildren += nbc
    return (internnodes, nbchildren)
        
        
def average_arity(T):
    (nbi, nbc) = __countnodes(T)
    if nbi != 0:
        return nbc / nbi
    else:
        return 0
    # or return (nbc/nbi if nbi != 0 else 0)
    
# with TreeAsBin
def __countnodestab(B):
    if B.child == None:
        return (0, 0)
    else:
        Bchild = B.child
        internnodes, nbchildren = 1, 0
        while Bchild != None:
            (nbi, nbc) = __countnodestab(Bchild)
            internnodes += nbi
            nbchildren += nbc + 1
            Bchild = Bchild.sibling
        return internnodes, nbchildren

def average_arity_TAB(B):
    (nbi, nbc) = __countnodestab(B)
    return (nbc/nbi if nbi != 0 else 0)

#using the binary structure (BONUS)...
def __arity2(B):
    ''' 
    return (nb links, nb internal nodes)
    '''
    if B.child == None:
        (links, nodes) = (0, 0)
    else:
        (l, n) = __arity2(B.child)
        (links, nodes) = (l + 1, n + 1)
        
    if B.sibling != None:
        (l, n) = __arity2(B.sibling)
        links += l + 1
        nodes += n

    return (links, nodes)

def average_arity_TAB2(B):
    (links, nodes) = __arity2(B)
    return 0 if nodes == 0 else links / nodes

"""
equality Tree & TreeAsBin
"""

# with return in loop
def same(T, B):
    if T.key != B.key:
        return False
    else:
        Bchild = B.child
        for Tchild in T.children:
            if Bchild == None or not(same(Tchild, Bchild)):
                return False
            Bchild = Bchild.sibling
    return Bchild == None

def same2(T, B):
    if B.key != T.key:
        return False
    i = 0
    C = B.child
    while i < T.nbchildren and C != None:
        if not same2(T.children[i], C):
            return False
        i += 1
        C = C.sibling
    return C == None and i == T.nbchildren

# without return in the loop
def same3(T, B):
    if T.key != B.key:
         return False
    else:
         Bchild = B.child
         i = 0
         while i < T.nbchildren and Bchild and same3(T.children[i], Bchild):
             i += 1
             Bchild = Bchild.sibling
         return i == T.nbchildren and Bchild == None
         


"""
TreeAsBin -> Tree
"""

def treeasbin_to_tree(B):
    T = tree.Tree(B.key, [])
    child = B.child
    while child != None:
        T.children.append(treeasbin_to_tree(child))
        child = child.sibling
    return T


    
"""
Tree -> TreeAsBin
"""

def tree_to_treeasbin_(T):
    B = treeasbin.TreeAsBin(T.key, None, None)
    if T.nbchildren != 0:
        B.child = tree_to_treeasbin(T.children[0])
        last = B.child
        for i in range(1, T.nbchildren):    
            last.sibling = tree_to_treeasbin_(T.children[i])
            last = last.sibling
    return B

def tree_to_treeasbin(T):
    B = treeasbin.TreeAsBin(T.key, None, None)
    firstchild = None
    for i in range(T.nbchildren-1, -1, -1):
        C = tree_to_treeasbin(T.children[i])
        C.sibling = firstchild
        firstchild = C
    
    B.child = firstchild
    return B



"""
"list representation" -> Tree (int keys)
"""

def __list2tree(s, i=0): 
        i = i + 1 # to skip the '('
        key = ""
        while s[i] != '(' and s[i] != ')':  # s[i] not in "()"
            key += s[i]
            i += 1
        T = tree.Tree(int(key), [])
        while s[i] == '(':  # a new child
            (C, i) = __list2tree(s, i)
            T.children.append(C)
        i += 1
        return (T, i)

def from_list(s):
    (T, _) = __list2tree(s)
    return T
