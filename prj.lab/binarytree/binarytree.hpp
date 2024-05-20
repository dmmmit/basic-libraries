//
// Created by dimau on 20.05.2024.
//

#ifndef MISIS2024S_23_09_UROSOV_D_I_BINARYTREE_H
#define MISIS2024S_23_09_UROSOV_D_I_BINARYTREE_H
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    // Конструктор
    BinarySearchTree();

    // Деструктор
    ~BinarySearchTree();

    // Метод для получения корневого узла дерева
    TreeNode *root();

    // Метод для добавления узла в дерево
    void add(int data);

    // Метод для проверки наличия узла в дереве
    bool has(int data);

    // Метод для поиска узла в дереве
    TreeNode *find(int data);

    // Метод для удаления узла из дерева
    void remove(int data);
    //найти ноду
    // если лист - просто удалить
    // если у ноду есть один из потомков
    // если есть оба - минимальный узел в правом поддереве заменяет текущую

    // Метод для нахождения минимального значения в дереве
    int min();

    // Метод для нахождения максимального значения в дереве
    int max();

private:
    TreeNode *root_;

    void clear_some_node(TreeNode *node);

};
#endif //MISIS2024S_23_09_UROSOV_D_I_BINARYTREE_H
