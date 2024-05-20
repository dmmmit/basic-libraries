
#include <binarytree/binarytree.hpp>
#include <stdexcept>


BinarySearchTree::BinarySearchTree() {
    root_ = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    clear_some_node(root_);
}

void BinarySearchTree::clear_some_node(TreeNode* node) {
    if (node != nullptr) {
        clear_some_node(node->left);
        clear_some_node(node->right);
        delete node;
    }
}
TreeNode* BinarySearchTree::root() {
    if (root_ != nullptr) {
        return root_;

    }        throw std::logic_error("Tree is empty");


}
void BinarySearchTree::add(int data) {
    TreeNode *new_node = new TreeNode(data);

    if (root_ == nullptr) {
        root_ = new_node;
    } else {
        TreeNode *curr = root_;
        TreeNode *sec = nullptr;

        while (curr != nullptr) {
            sec = curr;
            if (data < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (data < sec->data) {
            sec->left = new_node;
        } else {
            sec->right = new_node;
        }
    }
}
TreeNode *BinarySearchTree::find(int data) {
    TreeNode *curr = root_;
    while (curr != nullptr) {
        if (curr->data == data) {
            return curr;
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    throw std::logic_error("BinarySearchTree Can't find the element");
}

void BinarySearchTree::remove(int data) {
    TreeNode *curr = root_;
    TreeNode *sec = nullptr;

    while (curr != nullptr && curr->data != data) {
        sec = curr;
        if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (curr == nullptr) {
        throw std::logic_error("The tree is empty, it cannot be deleted");
    }

    if (curr->left == nullptr) {
        if (sec == nullptr) {
            root_ = curr->right;
        } else if (curr == sec->left) {
            sec->left = curr->right;
        } else {
            sec->right = curr->right;
        }
        delete curr;
    } else if (curr->right == nullptr) {
        if (sec == nullptr) {
            root_ = curr->left;
        } else if (curr == sec->left) {
            sec->left = curr->left;
        } else {
            sec->right = curr->left;
        }
        delete curr;
    } else {
        TreeNode *tmp = curr->right;
        TreeNode *tmp_sec = curr;

        while (tmp->left != nullptr) {
            tmp_sec = tmp;
            tmp = tmp->left;
        }

        curr->data = tmp->data;

        if (tmp == tmp_sec->left) {
            tmp_sec->left = tmp->right;
        } else {
            tmp_sec->right = tmp->right;
        }

        delete tmp;
    }
}
bool BinarySearchTree::has(int data) {
    TreeNode *curr = root_;

    while (curr != nullptr) {
        if (curr->data == data) {
            return true;
        } else if (data < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return false;
}


int BinarySearchTree::min() {
    if (root_ != nullptr) {
        TreeNode* tmp = root_;
        while (tmp->left != nullptr) {
            tmp = tmp->left;
        }
        return tmp->data;
    }
    else {
        throw std::logic_error("Tree is empty");

    }
}

int BinarySearchTree::max() {
    if (root_ != nullptr) {
        TreeNode* tmp = root_;
        while (tmp->right != nullptr) {
            tmp = tmp->right;
        }
        return tmp->data;
    }
    else {
        throw std::logic_error("Tree is empty");

    }
}