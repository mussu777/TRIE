#include <bits/stdc++.h>
using namespace std;

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // assumption, word will be in CAPS
        int idx = word[0] - 'a';
        TrieNode *child;

        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }
        // Recursion
        insertUtil(child, word.substr(1));
    }
    /** Inserts a word into the trie. */

    void insert(string word)
    {
        insertUtil(root, word);
    }


    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int idx = word[0] - 'a';
        TrieNode *child;

        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            return false;
        }
        // call Recursion
        return searchUtil(child, word.substr(1));
    }
    /** Returns if the word is in the trie. */

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prifixUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }

        int idx = word[0] - 'a';
        TrieNode *child;

        if (root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            return false;
        }
        // call Recursion
        return prifixUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix)
    {
        return prifixUtil(root, prefix);
    }
};