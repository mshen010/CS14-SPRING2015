Hash Table:
    Pros: -Find occurs on an average constant runtime O(1)
          -Insertion is also relatively short compared to self-balancing trees
    Cons: -None noticeable from the runtime tests
Self-Balancing Tree:
    Pros: -None noticeable from the runtime tests
    Cons: -Find takes around O(logn) runtime, slowed than the hash table
          -Insertion takes an even longer time, O(logn) to O(n)

Deletion can be easily compared as well using this same algorithm