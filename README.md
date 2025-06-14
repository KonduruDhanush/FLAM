# FLAM
Android Assignment - Set 1
## Problem 1: Least Recently Used(LRU) Cache
A cache has limited capacity, so when new items are added beyond that capacity, it should evict the item that was used the longest time ago. The cache needs to support two main operations: retrieving the value of a key (get) and inserting/updating a key-value pair (put). If the cache is full during insertion, it must remove the least recently used item to make space.
<br/>
The core challenge here is to perform both operations in constant time, i.e., O(1). This is achieved by combining a hash map (for direct access to key-value pairs) with a doubly linked list (to maintain the order of usage). The most recently used items are kept at the front of the list, and the least recently used ones at the back. Each time an item is accessed or inserted, it's moved to the front.
## Problem 2: Custom HashMap Implementation
This problem involves implementing a simplified version of a HashMap without using any built-in hash table libraries such as unordered_map, map, or dict.The objective is to create a structure that supports insertion, retrieval, and deletion of elements with average-case time complexity of O(1).
<br/>
Includes an implementation of a MyHashMap class which internally uses a fixed-size array of buckets, where each bucket is a linked list that handles hash collisions using chaining. When a key-value pair is inserted, a simple hash function determines the appropriate bucket, and the key is either added or updated. For retrieval and deletion, the linked list in the corresponding bucket is traversed to find the target key.
This solution ensures that operations are handled efficiently, even when multiple keys map to the same bucket. It also respects the constraint of handling large input sizes and many keys.
