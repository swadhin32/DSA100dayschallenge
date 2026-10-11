/*
95. LRU Cache
    Pattern: HashMap + Doubly Linked List

Problem Statement:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

* LRUCache(int capacity) initializes the cache with a positive capacity.
* int get(int key) returns the value of the key if it exists in the cache, otherwise returns -1.
* void put(int key, int value) updates the value if the key already exists. Otherwise, add the key-value pair to the cache.
* If the cache exceeds its capacity, remove the least recently used key.

Both get and put operations should run in O(1) average time.

Example:

Input:
LRUCache cache = new LRUCache(2);

cache.put(1, 1);
cache.put(2, 2);

cache.get(1);

cache.put(3, 3);

cache.get(2);

Output:
1
-1

Explanation:

After:
put(1,1)
Cache = [1]

put(2,2)
Cache = [1,2]

get(1)
Key 1 becomes recently used.

Cache = [2,1]

put(3,3)
Cache capacity is 2, so the least recently used key 2 is removed.

Cache = [1,3]

get(2)
Key 2 no longer exists.

Output = -1

Core Concepts:
✅ HashMap
✅ Doubly Linked List
✅ O(1) Get
✅ O(1) Put
✅ Cache Eviction
✅ Maintaining Recency Order

Main Logic:
Use two data structures together:

HashMap:
👉 Quickly find a node using its key.

Doubly Linked List:
👉 Maintain the order of usage.

Keep:

* Most recently used node near the front.
* Least recently used node near the back.

Whenever a key is accessed or inserted:
👉 Move it to the front.

When capacity is exceeded:
👉 Remove the node from the back.

Important Insight:
HashMap gives us:
O(1) lookup

Doubly Linked List gives us:
O(1) insertion + deletion

Together:
🔥 O(1) LRU Cache
*/

public class LRUCache
{
    private class Node
    {
        public int key;
        public int value;
        public Node prev;
        public Node next;

        public Node(int key, int value)
        {
            this.key = key;
            this.value = value;
        }
    }

    private Dictionary<int, Node> map;
    private int capacity;

    private Node head;
    private Node tail;

    public LRUCache(int capacity)
    {
        this.capacity = capacity;
        map = new Dictionary<int, Node>();

        head = new Node(0, 0);
        tail = new Node(0, 0);

        head.next = tail;
        tail.prev = head;
    }

    private void AddToFront(Node node)
    {
        node.next = head.next;
        node.prev = head;

        head.next.prev = node;
        head.next = node;
    }

    private void Remove(Node node)
    {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public int Get(int key)
    {
        if (!map.ContainsKey(key))
            return -1;

        Node node = map[key];

        Remove(node);
        AddToFront(node);

        return node.value;
    }

    public void Put(int key, int value)
    {
        if (map.ContainsKey(key))
        {
            Node node = map[key];

            node.value = value;

            Remove(node);
            AddToFront(node);

            return;
        }

        Node newNode = new Node(key, value);

        map[key] = newNode;
        AddToFront(newNode);

        if (map.Count > capacity)
        {
            Node lru = tail.prev;

            Remove(lru);
            map.Remove(lru.key);
        }
    }
}