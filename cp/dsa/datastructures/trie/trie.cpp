
struct vertex {
  char alphabet;
  bool exist;
  vector<vertex*> child;
  vertex(char a): alphabet(a), exist(false) { child.assign(26, NULL); }
};

class Trie {
private:
  vertex* root;
public:
  Trie() { root = new vertex('!'); }

  void insert(string word) {
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) {
      int alphaNum = word[i]-'A';
      if (cur->child[alphaNum] == NULL)
        cur->child[alphaNum] = new vertex(word[i]);
      cur = cur->child[alphaNum];
    }
    cur->exist = true;
  }

  bool search(string word) {
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) {
      int alphaNum = word[i]-'A';
      if (cur->child[alphaNum] == NULL)
        return false;
      cur = cur->child[alphaNum];
    }
    return cur->exist;
  }

  bool startsWith(string prefix) {
    vertex* cur = root;
    for (int i = 0; i < (int)prefix.size(); ++i) {
      int alphaNum = prefix[i]-'A';
      if (cur->child[alphaNum] == NULL)
        return false;
      cur = cur->child[alphaNum];
    }
    return true;
  }
};
