#include "main.h"
int MAXSIZE;

struct Data {
    int freq = 0;
    int timestamp = 0;
};
/** Huffman tree node implement */
class HuffNode {
public:
    friend class HuffTree;
    virtual bool isLeaf() = 0;
    virtual int get_weight() = 0; 
    virtual ~HuffNode() = default;
};
// as
/** Huffman tree node: Leaf class */
class HuffLeafNode : public HuffNode{
private:
    char c;
    int weight;
    friend class HuffTree;
public:
    /** Constructor */
    HuffLeafNode(char c, int wt) : c(c), weight(wt) {}
    char get_c() const { return c; }
    int get_weight() override { return weight; }
    bool isLeaf() override { return true; }
    ~HuffLeafNode() override = default;
};

/** Huffman tree node: Internal class */
class HuffInternalNode : public HuffNode {
private: 
    int weight; 
    HuffNode* left;
    HuffNode* right;
    friend class HuffTree;
public:
    HuffInternalNode(HuffNode* l, HuffNode* r, int wt) : left(l), right(r), weight(wt) {}
    int get_weight() override { return weight; }
    bool isLeaf() override { return false; }
    ~HuffInternalNode() override {
        delete left;
        delete right;
    }
};

/** Huffman coding tree */
class HuffTree {
private:
    HuffNode* root; 
    int get_height_rec(HuffNode* node) {
        if (node->isLeaf()) return 1; 
        else if (auto* internalNode = dynamic_cast<HuffInternalNode*>(node)) {
            int height_left = get_height_rec(internalNode->left);
            int height_right = get_height_rec(internalNode->right);
            return std::max(height_left, height_right) + 1;
        }
        else throw out_of_range("Invalid node type");
    }
    HuffNode* rotateLeft(HuffNode* nodeRoot) {
        if (nodeRoot == nullptr || nodeRoot->isLeaf()) {
            // Basic case or node is a leaf
            return nodeRoot;
        }
        // Cast the node to an internal node
        HuffInternalNode* rootInternal = dynamic_cast<HuffInternalNode*>(nodeRoot);
        if (!rootInternal->right) {
            // If the right child is null, rotation is not possible
            return nodeRoot;
        }
        // Perform the rotation
        HuffInternalNode* newRoot = dynamic_cast<HuffInternalNode*>(rootInternal->right);
        rootInternal->right = newRoot->left;
        newRoot->left = rootInternal;

        return newRoot;
    }
    HuffNode* rotateRight(HuffNode* nodeRoot) {
        if (nodeRoot == nullptr || nodeRoot->isLeaf()) {
            // Basic case or node is a leaf
            return nodeRoot;
        }
        // Cast the node to an internal node
        HuffInternalNode* rootInternal = dynamic_cast<HuffInternalNode*>(nodeRoot);
        if (!rootInternal->left) {
            // If the right child is null, rotation is not possible
            return nodeRoot;
        }
        // Perform the rotation
        HuffInternalNode* newRoot = dynamic_cast<HuffInternalNode*>(rootInternal->left);
        rootInternal->left = newRoot->right;
        newRoot->right = rootInternal;

        return newRoot;
    }

public:
    friend class HuffNode;
    HuffTree(char c, int wt) {
        root = new HuffLeafNode(c, wt);
    }
    HuffTree(HuffInternalNode* node) {
        root = node;
    }
    HuffNode* get_root() { return root; }
    int get_weight() { return root->get_weight(); }
    int compareTo(HuffTree* that) {
        if (root->get_weight() < that->get_weight()) return -1; 
        else if (root->get_weight() == that->get_weight()) return 0; 
        else return 1;
    }
    int get_height() {
        return get_height_rec(root);
    }
    void insert(HuffTree* tree) {
        auto *newRoot = new HuffInternalNode(root, tree->root, root->get_weight() + tree->get_root()->get_weight());
        root = newRoot;
        // Check rotate 
        int 
    }
    ~HuffTree() {
        delete_tree(root);
        root = nullptr;
    }

    // Function to recursively delete the tree
    void delete_tree(HuffNode* node) {
        if (node != nullptr) {
            if (!node->isLeaf()) {
                // If it's an internal node, recursively delete left and right children
                HuffInternalNode* internalNode = dynamic_cast<HuffInternalNode*>(node);
                delete_tree(internalNode->left);
                delete_tree(internalNode->right);
            }
            // Delete the current node
            delete node;
        }
    }
};

/** Build hufftree from hufflist */
HuffTree* buildTree(vector<pair<char, Data>> HHeap) {
    HuffTree *tmp1 = nullptr, *tmp2 = nullptr, *mp3 = nullptr;
    while(HHeap.size() > 1) { // While two items left
        
    }
}

class RESTAURANT_Gojo {
    class Tree_BST;
private:
    vector<Tree_BST> areaTable;
public:
    RESTAURANT_Gojo() : areaTable(MAXSIZE) {}
    void insertAreaTable(int result);
    void remove_KOKUSEN();
    void print_LIMITLESS(int num);
private:
    class Tree_BST {
        class Node;
    private:
        Node* root;
        queue<int> queueTime;
    public:
        Tree_BST(): root(nullptr) {}
        int size() { return (int)queueTime.size(); }
        void insert(int result);
        void remove_rec(Node* toDelete);
        void remove();
        void print_rec(Node* node);
        void print();
    private:
        class Node {
        private:
            int result;
            Node* left;
            Node* right;
            friend class Tree_BST;
        public:
            explicit Node(int result) : result(result), left(nullptr), right(nullptr) {};
        };
    };
};

void simulate(const string &filename)
{
    string item;
    ifstream  myfile(filename);
    if (myfile.is_open()) {
        while (myfile >> item) {
            if (item == "MAXSIZE") {
                myfile>>item;
                MAXSIZE = stoi(item);
                cout << "MAXSIZE: " << MAXSIZE << endl;
            }
            else if (item == "LAPSE") {
                myfile>>item;
                LAPSE(item);
            }
            else if (item == "KOKUSEN") {
                KOKUSEN();
            }
            else if (item == "KEITEIKEN") {
                myfile>>item;
                KEITEIKEN(stoi(item));
            }
            else if (item == "HAND") {
                HAND();
            }
            else if (item == "LIMITLESS") {
                myfile>>item;
                LIMITLESS(stoi(item));
            }
            else if (item == "CLEAVE") {
                myfile>>item;
                CLEAVE(stoi(item));
            }
        }
    }
    else cout << "Can not open file\n";
	cout << "Good Luck";
}
// ==================LAPSE CODE======================

bool cmp (pair<char, Data>& a, pair<char, Data>& b) {
    if (a.second.freq > b.second.freq) return false;
    else if (a.second.freq == b.second.freq) return a.second.timestamp < b.second.timestamp;
    else return true;
}
char CAESAR(char x, int num) {
    num = num % 26;
    int star_a = 65;
    int star_A = 97;
    int num_alphabet = 26;
    if (isupper(x))return char(int(x + num - star_a) % num_alphabet + star_a);
    // Encrypt Lowercase letters
    else return char(int(x + num - star_A) % num_alphabet + star_A);
}
void LAPSE(const string & name) {
    cout << "Call LAPSE\nName: " << name << "\n";
    map<char, Data> mp;
    for (size_t i = 0, n = name.size(); i < n; i++) {
        char c = name[i];
        if(mp.find(c) == mp.end()) {
            mp[c].freq = 1;
            mp[c].timestamp = (int)i;
        }
        else mp[c].freq++;
    }
    // convert MAP to VECTOR for CAESAR encoding
    vector<pair<char, Data>> vec;
    vec.reserve(mp.size());
    for (auto i : mp) vec.emplace_back(i);
    for (auto i : vec) {
        cout << "Char: " << i.first << endl;
        cout << "Fre: " << i.second.freq << endl;
    }
    cout << "AFTER CAESAR\n";
    mp.clear();
    for (auto i : vec) {
        i.first = CAESAR(i.first, i.second.freq);
        cout << "Char: " << i.first << endl;
        cout << "Fre: " << i.second.freq << endl;
        char c = i.first;
        if (mp.find(c) == mp.end()) {
            mp[c].freq = i.second.freq;
            mp[c].timestamp = 0; // reset value for SORTING
        }
        // Accumulate the same values
        else mp[c].freq++;
    }
    vector<pair<char, Data>> listX;
    listX.reserve(mp.size());
    for (auto i : mp)  listX.emplace_back(i);
    sort(listX.begin(), listX.end(), cmp);
    cout << "AFTER ACCUMULATE AND SORT\n";
    cout << "LIST X IS\n";
    for (auto i : listX) {
        cout << "Char: " << i.first << endl;
        cout << "Fre: " << i.second.freq << endl;
    }

    cout << "End LAPSE\n";
}
// ==================END LAPSE CODE==================
void KOKUSEN(){
    cout << "Call KEITEIKEN\n";
    cout << "End KEITEIKEN\n";
}
void KEITEIKEN(int num) {
    cout << "Call KEITEIKEN\nNum: " << num << "\n";
    cout << "End KEITEIKEN\n";
}
void HAND() {}
void LIMITLESS(int num) {
    cout << "Call LIMITLESS\nNum: " << num << "\n";
    cout << "End LIMITLESS\n";
}
void CLEAVE(int num) {
    cout << "Call CLEAVE\nNum: " << num << "\n";
    cout << "End CLEAVE\n";
}