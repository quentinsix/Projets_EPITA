#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Undergraduates - S3
first functions on graphs
"""

from algopy import graph, graphmat



############################### Degrees ######################################

# GraphMat

def degrees_mat(Gmat):
    """
    Gmat: GraphMat undirected
    returns the degree vector (a list in Python)
    """
    
    deg = [0] * Gmat.order # a new list of length Gmat.order filled with 0
    for x in range(Gmat.order):
        for y in range(Gmat.order):
#            if G.adj[x][y]: # edge x -- y
            deg[x] += Gmat.adj[x][y]
        deg[x] += Gmat.adj[x][x]       # loops count twice
    return deg

# not in tutorial
def in_out_degrees_mat(Gmat):
    """
    Gmat: GraphMat directed
    returns in-degree and out-degree vectors (tuple)
    """
    
    indeg = [0] * Gmat.order
    outdeg = [0] * Gmat.order
    for x in range(Gmat.order):
        for y in range(Gmat.order):
            indeg[x] += Gmat.adj[y][x]
            outdeg[x] += Gmat.adj[x][y]
            
    return (indeg, outdeg)
    
# Graph

def in_out_degrees(G):   
    """
    G: Graph directed
    returns in-degree and out-degree vectors (tuple)
    """
    indeg = [0] * G.order
    outdeg = [0] * G.order

    for x in range(G.order):    
        for y in G.adjlists[x]:
            # edge x -> y
            indeg[y] += 1
            outdeg[x] += 1
    return (indeg, outdeg)

# not in tutorial    
def out_degrees(G):
    """
    G: Graph directed
    returns out-degree vector
    """
    return [len(G.adjlists[x]) for x in range(G.order)]

############################### Dot ######################################
# simple dot format (to display graphs, without labels)
# the final versions will be in algopy/graph.py and graphmat.py

# GraphMat
def dot_mat(G):
    """Dot format of graph.

    Args:
        GraphMat

    Returns:
        str: String storing dot format of graph.

    """

    if G.directed:
        s = "digraph {\n"
        link = " -> "
    else:
        s = "graph {\n"
        link = " -- "
    k = G.order        
    for x in range(G.order):
        if not G.directed:
            k = x + 1
        for y in range(k):
            for _ in range(G.adj[x][y]):
                s += str(x) + link + str(y) + "\n"
    return s + '}'

# Graph
def dot(G):
    """Dot format of graph.

    Args:
        Graph

    Returns:
        str: String storing dot format of graph.

    """

    if G.directed:
        link = " -> "
        s = "digraph {\n"
    else:
        link = " -- "
        s = "graph {\n"
    
    for x in range(G.order):
        for y in G.adjlists[x]:
            if G.directed or y >= x:
                s += str(x) + link + str(y) + "\n"
       
    s += "}"
    return s    

"""
if you cannot use Graphviz here, copy the result of
print(dot(G1))
here: https://dreampuf.github.io/GraphvizOnline
"""

def display(G):
    """
    *Warning:* Made for use within IPython/Jupyter only.

    """
    
    try:
        from graphviz import Source
        from IPython.display import display
    except:
        raise Exception("Missing module: graphviz and/or IPython.")
    display(Source(dot(G)))

############################### Load ######################################
# simple load (without labels or other optionnal informations)
# the final versions will be in algopy/graph.py and graphmat.py
#       in algopy => replace graphmat.Graphmat by GraphMat 
#                 => replace graph.Graph by Graph

def load(filename,):
    """Build a new graph from a GRA file.

    Args:
        filename (str): File to load.

    Returns:
        Graph: New graph.

    Raises:
        FileNotFoundError: If file does not exist.

    """

    f = open(filename)
    directed = bool(int(f.readline()))
    order = int(f.readline())
#    G = graphmat.GraphMat(order, directed)  
    G = graph.Graph(order, directed)
    for line in f.readlines():
        edge = line.strip().split(' ')
        (src, dst) = (int(edge[0]), int(edge[1]))
        G.addedge(src, dst)
    f.close()
    return G
    
    