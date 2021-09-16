#include <string>
#include <unordered_map>
using namespace std;
#define SHORT

#ifdef SHORT
class Trie {
 public:
  unordered_map<char, Trie *> neighbours;
  bool is_end;

  Trie() { is_end = false; }

  void insert(string word) {
    Trie *curr = this;
    for (char ch : word) {
      if ((curr->neighbours.find(ch)) == (curr->neighbours.end())) {
        curr->neighbours[ch] = new Trie();
      }
      curr = curr->neighbours[ch];
    }
    curr->is_end = true;
  }

  bool search(string word) {
    Trie *curr = this;
    for (char ch : word) {
      if ((curr->neighbours.find(ch)) == (curr->neighbours.end())) {
        return false;
      }
      curr = curr->neighbours[ch];
    }
    return (curr->is_end);
  }

  bool startsWith(string prefix) {
    Trie *curr = this;
    for (char ch : prefix) {
      if ((curr->neighbours.find(ch)) == (curr->neighbours.end())) {
        return false;
      }
      curr = curr->neighbours[ch];
    }
    return true;
  }
};

#else
class node {
 public:
  unordered_map<char, node *> u;
  bool endofWord;

  node() { endofWord = false; }
};

class Trie {
  node *root;

 public:
  /** Initialize your data structure here. */
  Trie() { root = new node(); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    node *curr = root;

    for (int i = 0; i < word.length(); i++) {
      if (curr->u.find(word[i]) == curr->u.end()) {
        curr->u[word[i]] = new node();
      }

      curr = curr->u[word[i]];
    }

    curr->endofWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    node *curr = root;

    for (int i = 0; i < word.length(); i++) {
      if (curr->u.find(word[i]) == curr->u.end()) return false;
      curr = curr->u[word[i]];
    }

    return curr->endofWord;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    node *curr = root;

    for (int i = 0; i < prefix.length(); i++) {
      if (curr->u.find(prefix[i]) == curr->u.end()) return false;

      curr = curr->u[prefix[i]];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#endif