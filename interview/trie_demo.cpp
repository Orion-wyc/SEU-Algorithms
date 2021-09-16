#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode *> children;
  bool EOW;  // End Of Word
  TrieNode() { this->EOW = false; }
};

class Trie {
 public:
  Trie() { root = new TrieNode(); }

  void insert(const string &word) {
    TrieNode *curr = root;
    for (char c : word) {
      if ((curr->children.find(c)) == (curr->children.end())) {
        curr->children[c] = new TrieNode();
      }
      curr = curr->children[c];
    }
    curr->EOW = true;
  }

  bool search(const string &word) {
    TrieNode *curr = root;
    for (char c : word) {
      if ((curr->children.find(c)) == (curr->children.end())) {
        return false;
      }
      curr = curr->children[c];
    }
    return curr->EOW;
  }

  bool startswith(const string &prefix) {
    TrieNode *curr = root;
    for (char c : prefix) {
      if ((curr->children.find(c)) == (curr->children.end())) {
        return false;
      }
      curr = curr->children[c];
    }
    return true;
  }

  void release_trie(TrieNode *p) {
    if (p->children.size()!=0) {
      for (auto c : p->children) {
        release_trie(c.second);
      }
    }
    ++ cnt;
    delete p;
  }

  ~Trie() {
    // 内存清理部分
    cnt = 0;
    release_trie(root);
    cout<< "TrieNode released = " << cnt <<endl;
  }

 private:
  TrieNode *root;
  int cnt;
};

int main() {
  string words[3] = {"abc", "abedf", "ccc"};
  Trie trie;
  for (auto &word : words) {
    trie.insert(word);
  }
  string search_words[3] = {"abc", "abe", "zzz"};
  for (auto s : search_words) {
    cout << s << trie.search(s) << endl;
  }

  string prefix_words[4] = {"a", "abe", "c", "zzz"};
  for (auto s : prefix_words) {
    cout << s << trie.startswith(s) << endl;
  }

  return 0;
}
