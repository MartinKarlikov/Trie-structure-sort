# Trie-structure-sort
Focused entirely on the Trie structure working with strings.

The structure is used as a mean to understand a part of the BurstSort algorithm which will be implemented using this Trie structure.
This is the more "theoretical" part.
This project also served as a way to use pointers to functions and void pointers in general.
There a couple functions of the Trie that can be made quicker (size of the trie, count of words in the trie)
but i wanted to show the implementation of the traverse function + helper functions as it is reused and c++
gives us an easy way to implement different functions reusing this traverse function as the only thing that changes
is the action that is used when a word is found.

Main reason for the algorithm is it's speed in sorting strings.Asymptotically speaking it is linear.
Almost everything in it is based on induction on the length of the string.
