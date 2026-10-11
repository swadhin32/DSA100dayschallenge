/*
96. Trie Implementation
    Pattern: Trie

Problem Statement:
Implement a Trie (Prefix Tree) that supports efficient insertion and searching of words.

Implement the following operations:

* insert(word)
    Inserts the string word into the Trie.
* search(word)
    Returns true if word exists in the Trie, otherwise returns false.
* startsWith(prefix)
    Returns true if there is any previously inserted word that starts with prefix, otherwise returns false.

Example:

Input:

Trie trie;

trie.insert(“apple”);

trie.search(“apple”);

trie.search(“app”);

trie.startsWith(“app”);

trie.insert(“app”);

trie.search(“app”);

Output:

true
false
true
true

Explanation:

After inserting "apple":

search("apple")
→ true

search("app")
→ false

Because "app" itself has not been inserted as a complete word.

However:

startsWith("app")
→ true

because "apple" starts with "app".

After inserting "app":

search("app")
→ true

Core Concepts:
✅ Trie / Prefix Tree
✅ Tree-like Data Structure
✅ Character-by-Character Traversal
✅ Prefix Searching
✅ HashMap / Array of Children

Main Logic:
Each Trie node represents a character.

For example, inserting:

apple

creates a path:

root → a → p → p → l → e

The final node stores:
👉 isEnd = true

This tells us that a complete word ends there.

Important Insight:
A Trie is especially useful when problems involve:

👉 Prefixes
👉 Dictionary words
👉 Autocomplete
👉 Word searching

Unlike a normal HashMap,
a Trie naturally represents relationships between prefixes and words.

━━━━━━━━━━━━━━━━━━

⚡ Advanced Data Structures Unlocked:

LRU Cache → Combine two data structures to achieve O(1)

Trie → Build a tree specifically for strings and prefixes

Next up:

97. Word Break
98. Number of Islands II

The final stretch is getting spicy 🌶️🔥
*/


// https://youtube.com/shorts/8H0Cj3GNniA?si=WUtX3Cib1LNvocR2

public class Trie
{
    private class TrieNode
    {
        public TrieNode[] children = new TrieNode[26];
        public bool isEnd;
    }

    private TrieNode root;

    public Trie()
    {
        root = new TrieNode();
    }

    public void Insert(string word)
    {
        TrieNode current = root;

        foreach (char c in word)
        {
            int index = c - 'a';

            if (current.children[index] == null)
            {
                current.children[index] = new TrieNode();
            }

            current = current.children[index];
        }

        current.isEnd = true;
    }

    public bool Search(string word)
    {
        TrieNode current = root;

        foreach (char c in word)
        {
            int index = c - 'a';

            if (current.children[index] == null)
                return false;

            current = current.children[index];
        }

        return current.isEnd;
    }

    public bool StartsWith(string prefix)
    {
        TrieNode current = root;

        foreach (char c in prefix)
        {
            int index = c - 'a';

            if (current.children[index] == null)
                return false;

            current = current.children[index];
        }

        return true;
    }
}