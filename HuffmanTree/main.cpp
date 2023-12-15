#include <iostream>
using namespace std; 
enum BalanceValue {
    LH = -1,
    EH = 0,
    RH = 1
};
class HuffmanTree_AVL {
public:
    class Node;
private:
    Node* root;
public:
    // function here
    void insert(pair<char, int>); 
    void insert_rec(Node* node, pair<char, int>);
    class Node {
    private:
        BalanceValue balance;
        Node *left, *right;
        pair<char, int> data;
        friend class HuffmanTree_AVL;
    };
};



int main() {

}