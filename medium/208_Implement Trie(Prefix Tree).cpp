class TrieNode{
public:
    TrieNode* next[26];
    bool is_word;
    
    TrieNode(bool b=false){
        memset(next,0,sizeof(next));
        is_word=b;
    }
};

class Trie { //prefix tree
public:
    
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int w_size=word.size();
        TrieNode* tmp=root;
        for(int i=0;i<w_size;i++){
            if(!tmp->next[word[i]-'a']) tmp->next[word[i]-'a']=new TrieNode();
            tmp=tmp->next[word[i]-'a'];
        }
        tmp->is_word=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmp=find(word);
        return tmp && tmp->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix)!=NULL;
    }

private:
    TrieNode* find(string key){
        TrieNode* tmp=root;
        int k_size=key.size();
        for(int i=0;i<k_size && tmp;i++) tmp=tmp->next[key[i]-'a'];
        return tmp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
