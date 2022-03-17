
__license__ = 'Nathalie (c) EPITA'
__docformat__ = 'reStructuredText'
__revision__ = '$Id: prefixtrees.py 2020-10-16'

"""
Prefix Trees homework
2020-10 - S3
@author: quentin.six
"""

from algopy import ptree

###############################################################################
# Do not change anything above this line, except your login!
# Do not add any import

##############################################################################
## Measure

Tree1 = ptree.Tree(('', False),
             [ptree.Tree(('c', False),
                   [ptree.Tree(('a', False),
                         [ptree.Tree(('s', False),
                               [ptree.Tree(('e', True)),
                                ptree.Tree(('t', True),
                                     [ptree.Tree(('l', False),
                                           [ptree.Tree(('e', True))])])])]),
                    ptree.Tree(('i', False),
                         [ptree.Tree(('r', False),
                               [ptree.Tree(('c', False),
                                     [ptree.Tree(('l', False),
                                           [ptree.Tree(('e', True))])])]),
                          ptree.Tree(('t', False),
                               [ptree.Tree(('y', True))])]),
                    ptree.Tree(('o', False),
                         [ptree.Tree(('m', False),
                               [ptree.Tree(('e', True))]),
                          ptree.Tree(('u', False),
                               [ptree.Tree(('l', False),
                                     [ptree.Tree(('d', True))])])])]),
        ptree.Tree(('f', False),
             [ptree.Tree(('a', False),
                   [ptree.Tree(('m', False),
                         [ptree.Tree(('e', True)),
                          ptree.Tree(('o', False),
                               [ptree.Tree(('u', False),
                                     [ptree.Tree(('s', True))])])]),
                    ptree.Tree(('n', True),
                         [ptree.Tree(('c', False),
                               [ptree.Tree(('y', True))])])])])])

T = ptree.Tree(('', False),
         [ptree.Tree(('c', False),
               [ptree.Tree(('a', False),
                     [ptree.Tree(('r', True), [ptree.Tree(('d', True))]),
                      ptree.Tree(('t', True))])]),
          ptree.Tree(('f', False),
               [ptree.Tree(('a', False), [ptree.Tree(('n', True))]),
                ptree.Tree(('u', False), [ptree.Tree(('n', True))])])
         ])

def count_words(T):
    """ count words in tree T
    
    """
    nb=0
    if(T.key[1]):
        nb+=1
    for child in T.children:
        nb+=count_words(child)
    return nb

print(count_words(Tree1))

def longest_word_length(T):
    """ longest word length
    
    """
    h=0
    for child in T.children:
        h=max(h,longest_word_length(child)+1)
    return h

print(longest_word_length(Tree1))

def __word_list(T,l,liste):
    """ generate the word list
    """
    if(T.key[1]):
    	liste.append(l)
    for child in T.children:
        __word_list(child,l+child.key[0],liste)
    return liste

def average_length(T):
    """ average word length

    """
    nb=0
    for w in __word_list(T,"",[]):
    	nb+=len(w)
    return nb/count_words(T)


print(average_length(Tree1))
  

print(count_words(T))
print(longest_word_length(T))
print(average_length(T))
###############################################################################
## search and list


def word_list(T):
    """ generate the word list
    """
    return __word_list(T,"",[])


# print(word_list(Tree1))
# print(word_list(T))


def search_word(T, word):
    """ search for a word in a tree
    
    """
    for w in word_list(T):
    	if(w==word):
    		return True
    return False

print(search_word(Tree1, "fabulous"))
print(search_word(Tree1, "famous"))   


def __Is_Prefix(prefix,word):
	i=0
	while i<(len(word))and i<(len(prefix)):
		if (prefix[i]!=word[i]):
			return False
		i+=1
	if(len(prefix)<=len(word)):
		return True
	else:
		return False

def completion(T, prefix):
    """ generate the list of words with a common prefix
    
    """
    liste=[]
    for w in word_list(T):
    	if(__Is_Prefix(prefix,w)):
    		liste.append(w)
    return liste
    
print(completion(Tree1, "fan"))
print(completion(Tree1, "ci"))
print(completion(Tree1, "what"))
###############################################################################
## Build

def build_lexicon(T, filename):
    """ save the tree in a file
    
    """
    file = open(filename,'w')
    for word in word_list(T):
    	file.write(word+"\n")
    file.close()

build_lexicon(Tree1,"test.txt")


# def __add_word(T,word,nb,fin,indice):
# 	if fin:
# 		val_bool=False
# 		if nb==len(word)-1:
# 			val_bool= True
# 		T.children.insert(indice,ptree.Tree(((word[nb]),val_bool),None))
# 		if nb==len(word)-1:
# 			return T
# 	cond=False
# 	i=0
# 	while (i < T.nbchildren) and not(fin):
# 		if nb==len(word)-1 and word[nb]==T.children[i].key[0]:
# 			T.children[i].key[1]==True
# 		else:
# 			if word[nb]==T.children[i].key[0]:
# 				cond=True
# 				__add_word(T.children[i],word,nb+1,fin,i)
			
# 		i=i+1
# 	if not fin:
# 		__add_word(T,word,nb,True,i)
# 	return T


def __add_word(T,word,indice,fin):
	#ajout en feuille
	if(T.nbchildren==0):
		if(indice==len(word)-1):
			T.children.append(ptree.Tree(((word[indice]),True),None))
			return T
		else:
			T.children.append(ptree.Tree(((word[indice]),False),None))
			__add_word(T.children[0],word,indice+1,fin)
	#insertion dans un noeud interbe
	i=0
	while i<T.nbchildren and word[indice]<T.children[i].key[0]:
		i=i+1
	if word[indice]==T.children[i-1].key[0]:
		__add_word(T.children[i-1],word,indice+1,fin)
	else:
		if(word[indice]>T.children[i-1].key[0]):
			T.children.insert(i-1,ptree.Tree((word[nb]),True),None)
		else:

	return T

def __word_list1(T,l,liste):
    """ generate the word list
    """
    if(T.key[1]):
    	liste.append(l)
    for child in T.children:
        __word_list(child,l+child.key[0],liste)
    return liste

def add_word(T, word):
    """ add a word in the tree
    
    """
    if not search_word(T,word):
    	return __add_word(T,word,0,False,0)
    else:
    	return T


# print(word_list(add_word(T,"caca")))
# print(word_list(add_word(T,"cac")))

def build_tree(filename):
    """ build the prefix tree from a file of words
    
    """
    file=open(filename,"r")
    T=ptree.Tree(('', False))
    for word in file.readlines():
    	add_word(T,word.strip())
    file.close()
    return T

print(word_list(build_tree("wordList1.txt")))
# print(word_list(build_tree("wordList2.txt")))
# (build_tree("list_fr.txt"))

