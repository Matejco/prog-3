#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    // insert (bst)
    Node* insert(Node* node, int x) {
        if (node == nullptr)
            return new Node(x);
        if (x < node->val)
            node->left = insert(node->left, x);
        else
            node->right = insert(node->right, x);
        return node;
    }

    void insert(int x) {
        root = insert(root, x);
    }

    bool find(Node* node, int x) {
        if (!node)
            return false;
        if (node->val == x)
            return true;
        if (x < node->val)
            return find(node->left, x);
        else
            return find(node->right, x);
    }

    bool find(int x) {
        return find(root, x);
    }

    int sum(Node* node) {
        if (!node)
            return 0;
        return node->val + sum(node->left) + sum(node->right);
    }

    int sum() {
        return sum(root);
    }

    // DFS rekurzivno
    void preorder(Node* node) {
        if (!node)
            return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(Node* node) {
        if (!node)
            return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

    void postorder(Node* node) {
        if (!node)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->val << " ";
    }

    // DFS ne rekurzivno
    void preorder_iter() {
        if (!root)
            return;

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* cur = st.top(); st.pop();
            cout << cur->val << " ";

            if (cur->right)
                st.push(cur->right);
            if (cur->left)
                st.push(cur->left);
        }
    }

    void inorder_iter() {
        stack<Node*> st;
        Node* cur = root;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            cout << cur->val << " ";
            cur = cur->right;
        }
    }

    void postorder_iter() {
        if (!root)
            return;

        stack<Node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            Node* cur = st1.top(); st1.pop();
            st2.push(cur);

            if (cur->left)
                st1.push(cur->left);
            if (cur->right)
                st1.push(cur->right);
        }

        while (!st2.empty()) {
            cout << st2.top()->val << " ";
            st2.pop();
        }
    }

    // BFS
    void bfs() {
        if (!root)
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            cout << cur->val << " ";
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
};

int main() {
    BST t;

    t.insert(8);
    t.insert(3);
    t.insert(10);
    t.insert(1);
    t.insert(6);
    t.insert(14);
    t.insert(4);
    t.insert(7);
    t.insert(13);

    cout << "rekurzivno DFS" << endl;
    cout << "preorder: ";
    t.preorder(t.root);
    cout << endl;
    cout << "inorder: ";
    t.inorder(t.root);
    cout << endl;
    cout << "postorder: ";
    t.postorder(t.root);
    cout << endl;

    cout << "ne rekurzivno DFS" << endl;
    cout << "preorder: ";
    t.preorder_iter();
    cout << endl;
    cout << "inorder: ";
    t.inorder_iter();
    cout << endl;
    cout << "postorder: ";
    t.postorder_iter();
    cout << endl;

    cout << "BFS: ";
    t.bfs();
    cout << endl;

    cout << "najdi 7: " << (t.find(7) ? "YES" : "NO") << endl;
    cout << "najdi 100: " << (t.find(100) ? "YES" : "NO") << endl;

    cout << "Sum = " << t.sum() << endl;

    return 0;
}