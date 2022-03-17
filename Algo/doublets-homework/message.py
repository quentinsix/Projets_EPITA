import unittest
import time as t
import random as r
from algopy import graph as g
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
        self.assertCountEqual(["ford", "fork"], target.most_connected(G4))
        self.assertCountEqual(["oat", "sat"], target.most_connected(G3))

    def test_is_chain(self):
        G3 = target.build_graph("lexicons/lex_some.txt", 3)
        self.assertEqual(True, target.is_chain(G3, ['ape', 'apt', 'opt', 'oat', 'mat', 'man']))
        self.assertEqual(False, target.is_chain(G3, ['man', 'mat', 'sat', 'sit', 'pit', 'pig']))
        self.assertEqual(False, target.is_chain(G3, ['ape', 'apt', 'opt', 'oat', 'mat', 'oat', 'mat', 'man']))
        self.assertEqual(True, target.is_chain(G3, ['ape']))
        self.assertEqual(False, target.is_chain(G3, ['J']))

    def test_all_doublets(self):
        G3 = target.build_graph("lexicons/lex_some.txt", 3)
        self.assertCountEqual(['eel', 'een', 'ell', 'ilk', 'ill', 'ink', 'pie', 'pig', 'pin', 'pit'], target.all_doublets(G3, "pen"))
        self.assertCountEqual([], target.all_doublets(G3, "J"))

    def test_ladder(self):
        G3 = target.build_graph("lexicons/lex_some.txt", 3)
        G4 = target.build_graph("lexicons/lex_some.txt", 4)
        self.assertEqual(['ape', 'apt', 'opt', 'oat', 'mat', 'man'], target.ladder(G3, "ape", "man")) # plusieurs chemins possible
        self.assertEqual([], target.ladder(G3, "man", "pig"))
        self.assertEqual(['work', 'fork', 'ford', 'food'], target.ladder(G4, "work", "food")) # plusieurs chemins possible
        self.assertEqual([], target.ladder(G4, "J", "work"))
        self.assertEqual([], target.ladder(G4, "work", "J"))
        self.assertEqual([], target.ladder(G3, "J", "j"))
        self.assertEqual([], target.ladder(G4, "weed", "weed"))

    def test_no_solution(self):
        G3 = target.build_graph("lexicons/lex_some.txt", 3)
        G4 = target.build_graph("lexicons/lex_some.txt", 4)
        self.assertEqual((None, None), target.no_solution(G4))
        (s1,s2) = target.no_solution(G3)
        self.assertTrue([] == target.ladder(G3, s1, s2))

    def test_longest_doublet(self):
        G3 = target.build_graph("lexicons/lex_some.txt", 3)
        G4 = target.build_graph("lexicons/lex_some.txt", 4)
        (src, dst, _) = target.longest_doublet(G3)
        self.assertEqual(len(target.ladder(G3, src, dst)), 10)
        (src, dst, _) = target.longest_doublet(G4)
        self.assertEqual(len(target.ladder(G4, src, dst)), 13)



# class DMPerfs(unittest.TestCase):
#     def test_build_perf(self):
#         start = t.time()
#         for i in range(0,1000):
#             target.build_graph("lexicons/lex_more.txt", 3)
#             target.build_graph("lexicons/lex_more.txt", 4)
#         print("build -> ",t.time() - start)

#     def test_most_connected_perf(self):
#         G3 = target.build_graph("lexicons/lex_more.txt", 3)
#         G4 = target.build_graph("lexicons/lex_more.txt", 4)
#         start = t.time()
#         for i in range(0,1000):
#             target.most_connected(G4)
#             target.most_connected(G3)
#         print("most_connected -> ",t.time() - start)

#     def test_is_chain_perf(self):
#         G3 = target.build_graph("lexicons/lex_more.txt", 3)
#         G4 = target.build_graph("lexicons/lex_more.txt", 4)
#         L3 = ['tea', 'sea', 'set', 'bet', 'bey', 'buy', 'bud', 'bid', 'aid', 'ail', 'aim', 'air', 'fir', 'far', 'ear', 'err', 'ere', 'ore', 'one']
#         L4 = ['feed', 'weed', 'weld', 'wald', 'ward', 'card', 'cord', 'coed', 'cold', 'wold', 'wood', 'food', 'fool', 'foul', 'four']
#         (l3, l4) = (len(L3), len(L4))
#         start = t.time()
#         for i in range(0, 1000):
#             target.is_chain(G3, L3)
#             target.is_chain(G4, L4)
#         print("is_chain -> ",t.time() - start)

#     def test_all_doublets_perf(self):
#         G3 = target.build_graph("lexicons/lex_more.txt", 3)
#         G4 = target.build_graph("lexicons/lex_more.txt", 4)
#         (L3, L4) = (G3.labels, G4.labels)
#         (l3, l4) = (G3.order, G4.order)
#         r3 = [r.randint(0,l3-1)] * 1000
#         r4 = [r.randint(0,l4-1)] * 1000
#         start = t.time()
#         for i in range(1000):
#             target.all_doublets(G3, L3[r3[i]])
#             target.all_doublets(G4, L4[r4[i]])
#         print("all_doublets ->",t.time() - start)

#     def test_ladder_perf(self):
#         G3 = target.build_graph("lexicons/lex_more.txt", 3)
#         G4 = target.build_graph("lexicons/lex_more.txt", 4)
#         (L3, L4) = (G3.labels, G4.labels)
#         (l3, l4) = (G3.order, G4.order)
#         r3 = [r.randint(0,l3-1)] * 2000
#         r4 = [r.randint(0,l4-1)] * 2000
#         start = t.time()
#         for i in range(1000):
#             target.ladder(G3, L3[r3[i]], L3[r3[i + 1000]])
#             target.ladder(G4, L4[r4[i]], L4[r4[i + 1000]])
#         print("ladder ->", t.time() - start)

#     def test_no_solution_perf(self):
#         G3 = target.build_graph("lexicons/lex_more.txt", 3)
#         G4 = target.build_graph("lexicons/lex_more.txt", 4)
#         start = t.time()
#         for i in range(1000):
#             target.no_solution(G3)
#             target.no_solution(G4)
#         print("no solution ->", t.time() - start)

#     def test_longest_doublets_perf(self):
#         G3 = target.build_graph("lexicons/lex_more.txt", 3)
#         G4 = target.build_graph("lexicons/lex_more.txt", 4)
#         start = t.time()
#         for i in range(1000):
#             target.longest_doublet(G3)
#             target.longest_doublet(G4)
#         print("longest doublet ->", t.time() - start)


if __name__ == '__main__':
    unittest.main()