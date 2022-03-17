
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



def count_words(T):
    """ count words in tree T
    
    """
    nb=0
    if(T.key[1]):
        nb+=1
    for child in T.children:
        nb+=count_words(child)
    return nb



def longest_word_length(T):
    """ longest word length
    
    """
    h=0
    for child in T.children:
        h=max(h,longest_word_length(child)+1)
    return h


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



###############################################################################
## search and list


def word_list(T):
    """ generate the word list
    """
    return __word_list(T,"",[])




def search_word(T, word):
    """ search for a word in a tree
    
    """
    for w in word_list(T):
    	if(w==word):
    		return True
    return False

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
    

###############################################################################
## Build

def build_lexicon(T, filename):
    """ save the tree in a file
    
    """
    file = open(filename,'w')
    for word in word_list(T):
    	file.write(word+"\n")
    file.close()


def __add_word(T,word,nb,fin):
	if fin:
		val_bool=False
		if nb==len(word)-1:
			val_bool= True
		T.children.append(ptree.Tree(((word[nb]),val_bool),None))
		if nb==len(word)-1:
			return T
	cond=False
	for i in range (T.nbchildren):
		if nb==len(word)-1 and word[nb]==T.children[i].key[0]:
			T.children[i].key[1]==True
		else:
			if word[nb]==T.children[i].key[0]:
				cond=True
				__add_word(T.children[i],word,nb+1,fin)
	if not cond:
		__add_word(T,word,nb,True)
	return T


def add_word(T, word):
    """ add a word in the tree
    
    """
    if not search_word(T,word):
    	return __add_word(T,word,0,False)
    else:
    	return T



def build_tree(filename):
    """ build the prefix tree from a file of words
    
    """
    file=open(filename,"r")
    T=ptree.Tree(('', False))
    for word in file.readlines():
    	add_word(T,word.strip())
    file.close()
    return T

