#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

// define a structure to hold bid information
// n/a

// Internal structure for tree node is completed by Initializing
// a Bid called bid and a left and right node pointer.
struct Node {
	int item;
	struct Node* left;
	struct Node* right;

	//Default Constructor for Node
	Node() {
		left = nullptr;
		right = nullptr;
	}

	Node(int vip): Node() {
		this -> item = vip;
	}
};

class BinarySearchTree {

private:
    Node* root;

    void addNode(Node* node, int item);
    void inOrder(vector<int>* list, Node* node);
    void preOrder(vector<int>* list, Node* node);
    void postOrder(vector<int>* list, Node* node);
    void levelOrder(vector<int>* list, Node* node);

public:
    BinarySearchTree();
    void Insert(int item);
    void InOrder();
    void PreOrder();
    void PostOrder();
    void LevelOrder();
};





/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    // initialize housekeeping variables
	root = nullptr;
}

/**
 * Insert int
 */
void BinarySearchTree::Insert(int item) {
    //Implement inserting a bid into the tree
	//if tree is empty then make the node the root
	if (root == nullptr) {
		root = new Node(item);
	}
	//if tree has a root then call addNode to recurse through tree to add node
	else {
		this->addNode(root, item);
	}
}

/**
 * Add an int vi to some node (recursive)
 *
 * @param node Current node in tree
 * @param int vi to be added
 */
void BinarySearchTree::addNode(Node* node, int item) {
    //Implement inserting a numVal into the tree
	//If node is larger than numVal then add to left subtree
	if (node->item > item) {
		if (node->left == nullptr) {
			node->left = new Node(item);
		}
		else (this->addNode(node->left, item));
	}
	//If node is less than numVal then add to right subtree
	else {
		if (node->right == nullptr) {
			node->right = new Node(item);
		}
		else (this->addNode(node->right, item));
	}
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
	vector<int> listItems;
	this->inOrder(&listItems, root);

	cout << listItems.at(0);

	for (unsigned int i=1; i < listItems.size(); ++i) {
		cout << " " << listItems.at(i);
	}
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
	vector<int> listItems;
	this->preOrder(&listItems, root);

	cout << listItems.at(0);

	for (unsigned int i=1; i < listItems.size(); ++i) {
		cout << " " << listItems.at(i);
	}
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
	vector<int> listItems;
	this->postOrder(&listItems, root);

	cout << listItems.at(0);

	for (unsigned int i=1; i < listItems.size(); ++i) {
		cout << " " << listItems.at(i);
	}
}

/**
 * Traverse the tree in level-order
 */
void BinarySearchTree::LevelOrder() {
	vector<int> listItems;
	this->levelOrder(&listItems, root);

	cout << listItems.at(0);

	for (unsigned int i=1; i < listItems.size(); ++i) {
		cout << " " << listItems.at(i);
	}
}

void BinarySearchTree::inOrder(vector<int>* list, Node* node)  {
	//Verify if bst is empty and return the empty node if it is
	//Else, iterate though left side of BST
	if (node != nullptr) {
		this->inOrder(list, node->left);
		//add items to vector
		list->push_back(node->item);
	    //Iterate though right side of tree
		this->inOrder(list, node->right);
	}
}

void BinarySearchTree::preOrder(vector<int>* list, Node* node)  {
	//Verify if bst is empty and return the empty node if it is

	if (node != nullptr) {
		//add items to vector
		list->push_back(node->item);

		//Iterate though left side of BST
		preOrder(list, node->left);

	    //Iterate though right side of tree
		preOrder(list, node->right);
	}
}

void BinarySearchTree::postOrder(vector<int>* list, Node* node)  {
	//Verify if bst is empty and return the empty node if it is

	if (node != nullptr) {

		//Iterate though left side of BST
		postOrder(list, node->left);

	    //Iterate though right side of tree
		postOrder(list, node->right);

		//add items to vector
		list->push_back(node->item);
	}
}

void BinarySearchTree::levelOrder(vector<int>* list, Node* node)  {
	//Verify if bst is empty and return the empty node if it is

	if (node != nullptr) {

		//queue for level traversal
		queue<Node*> q;

		//enter current node and initialize height
		q.push(node);

		while (q.empty() == false) {
			//add data from front of queue to vector
			//and remove it from queue
			Node* qNode = q.front();
			list->push_back(qNode->item);
			q.pop();

			//add left child to queue
			if (qNode->left != nullptr) {
				q.push(qNode->left);
			}

			//add right child to queue
			if (qNode->right != nullptr) {
				q.push(qNode->right);
			}
		}
	}
}


int main()
{
    // Define a binary search tree to hold all integers
    BinarySearchTree* bst;

    bst = new BinarySearchTree();

    int n;
    cout << "How many elements?";
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int vi;
        cout << "Enter element " << i << ": ";
        cin >> vi; cin.ignore();
        bst->Insert(vi);
    }

    bst->PreOrder();
    cout << endl;
    bst->InOrder();
    cout << endl;
    bst->PostOrder();
    cout << endl;
    bst->LevelOrder();
}
