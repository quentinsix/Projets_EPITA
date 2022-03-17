import unittest
from algopy import graph as g
from algopy import queue as q
login = "quentin_six"
target = __import__(login+"_doublets")

class DMTests(unittest.TestCase):
    def test_build_graph(self):
        self.assertEqual(g.todot(g.load("files/some3.gra")), g.todot(target.build_graph("lexicons/lex_some.txt", 3)))
        self.assertEqual(g.todot(g.load("files/some4.gra")), g.todot(target.build_graph("lexicons/lex_some.txt", 4)))
        self.assertEqual(g.todot(g.load("files/more3.gra")), g.todot(target.build_graph("lexicons/lex_more.txt", 3)))
        self.assertEqual(g.todot(g.load("files/more4.gra")), g.todot(target.build_graph("lexicons/lex_more.txt", 4)))

    def test_most_connceted(self):
        G3 = target.build_graph("lexicons/lex_some.txt", 3)
        G4 = target.build_graph("lexicons/lex_some.txt", 4)
        self.assertEqual(["ford", "fork"], target.most_connected(G4))
        self.assertEqual(["oat", "sat"], target.most_connected(G3))

    def test_is_chain(self):
        G3 = target.build_graph("lexicons/lex_some.txt", 3)
        self.assertEqual(True, target.is_chain(G3, ['ape', 'apt', 'opt', 'oat', 'mat', 'man']))
        self.assertEqual(False, target.is_chain(G3, ['man', 'mat', 'sat', 'sit', 'pit', 'pig']))
        self.assertEqual(False, target.is_chain(G3, ['ape', 'apt', 'opt', 'oat', 'mat', 'oat', 'mat', 'man']))
        # self.assertEqual(True, target.is_chain(G3, []))
        self.assertEqual(True, target.is_chain(G3, ['ape']))
        self.assertEqual(False, target.is_chain(G3, ['J']))

    def test_all_doublets(self):
        G3 = target.build_graph("lexicons/lex_some.txt", 3)
        self.assertCountEqual(['eel', 'een', 'ell', 'ilk', 'ill', 'ink', 'pie', 'pig', 'pin', 'pit'], target.all_doublets(G3, "pen"))
        self.assertCountEqual([], target.all_doublets(G3, "J"))


if __name__ == '__main__':
    unittest.main()