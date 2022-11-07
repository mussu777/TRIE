#include <bits/stdc++.h>  
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;


    TrieNode(char ch)
    {
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    
    // Function for INSERT

    void insertUtil(TrieNode* root, string word)
    {
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        // assumption , word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // RECURSION
        return insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    
    // Function for SEARCH

    bool searchUtil(TrieNode* root , string word)
    {
        // Base Case 
        if(word.length() == 0)
        {
            return root->isTerminal; 
        }

        int index = word[0] - 'A';
        TrieNode* child;
        
        // Present 
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else
        {
            // Absent 
            return false;
        }

        // Recursion
        return searchUtil(child , word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root , word);
    }


    // Function for Remove

    void removeUtil(TrieNode* root, string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = false;
            return ;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursion
        return removeUtil(child, word.substr(1));
    }

    void removeWord(string word){
        removeUtil(root, word);
        return ;
    }



};


int main()
{
    Trie *t = new Trie();
    
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("DON");
    t->insertWord("TIME");

    cout<< endl;
    cout<< "Present or Not = " << t->searchWord("ARM") << endl;
    cout<< endl;

    cout<< "Present or Not = " << t->searchWord("TIM") << endl;
    cout<< endl;
    
    t->removeWord("DON");
    cout<<"Remove word = " << t->searchWord("DON")<<endl;

    return 0;
}