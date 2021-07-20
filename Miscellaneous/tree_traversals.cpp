#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
  Node(int key)
    {
        this->key = key;
        left = right = NULL;
    }
};

void inorder(struct Node* node){
  if(node == NULL){
    return;
  }
  inorder(node->left);

  cout << node->key << " ";

  inorder(node->right);
}

void preorder(struct Node* node){
  if(node == NULL){
    return;
  }
  cout << node->key << " ";

  preorder(node->left);

  preorder(node->right);
}

void postorder(struct Node* node){
  if(node == NULL){
    return;
  }
  postorder(node->left);

  postorder(node->right);

  cout << node->key << " ";
}

int n;
vector<int> key, l, r; 
struct Node* root;

void makeLTree(struct Node* node, int count){
  if(count == 0){
    node->left = new Node(key[l[count]]);
    if(l[l[count]] != -1){
    makeLTree(node->left, l[count]);
    } else {
      return;
    } 
  }
  if(l[count] != -1){
    node->left = new Node(key[l[count]]);
  }
  if(r[count] != -1){
    node->right = new Node(key[r[count]]);
  }
  if(l[l[count]] != -1){
    makeLTree(node->left, l[count]);
  } else if (r[r[count]] != -1){
    makeLTree(node->right, r[count]);
  }
  return;
}

void makeRTree(struct Node* node, int count){
  if(count == 0){
    node->right = new Node(key[r[count]]);
    if(r[r[count]] != -1){
    makeRTree(node->right, r[count]);
    } else {
      return;
    }
  }
  if(l[count] != -1){
    node->left = new Node(key[l[count]]);
  }
  if(r[count] != -1){
    node->right = new Node(key[r[count]]);
  }
  if(r[r[count]] != -1){
    makeRTree(node->right, r[count]);
  } else if(l[l[count]] != -1){
    makeRTree(node->left, l[count]);
  }
  return;
}

int main(){
  cin >> n; 
  key.resize(n);
  l.resize(n);
  r.resize(n);
  for (int a=0; a<n; a++) {
    cin >> key[a] >> l[a] >> r[a];
  }
  struct Node* root = new Node(key[0]);
  makeLTree(root, 0);
  makeRTree(root, 0);
  inorder(root);
  cout << "\n";
  preorder(root);
  cout << "\n";
  postorder(root);
}
