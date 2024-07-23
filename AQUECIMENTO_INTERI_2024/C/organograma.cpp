#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    string data; // Nome do setor
    TreeNode* firstChild;  // Ponteiro para o primeiro setor sob responsabilidade
    TreeNode* nextSibling; // Ponteiro para o próximo setor sob responsabilidade do mesmo pai
};

void addChildOrdered(TreeNode* parent, TreeNode* child) {
    if (parent == NULL || child == NULL) {
        return;
    }

    // A lista de filhos está vazia ou o novo filho deve ser o primeiro
    if (parent->firstChild == NULL || child->data < parent->firstChild->data) {
        child->nextSibling = parent->firstChild;
        parent->firstChild = child;
    } else {
        TreeNode* current = parent->firstChild;
        TreeNode* prev = NULL;

        while (current != NULL && child->data > current->data) {
            prev = current;
            current = current->nextSibling;
        }

        prev->nextSibling = child;
        child->nextSibling = current;
    }
}

TreeNode* findSector(TreeNode* root, const string& value) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == value) {
        return root;
    }

    TreeNode* child = root->firstChild;
    while (child != NULL) {
        TreeNode* result = findSector(child, value);
        if (result != NULL) {
            return result;
        }
        child = child->nextSibling;
    }

    return NULL;
}

void printHierarchy(TreeNode* node) {
    if (node == NULL) {
        return;
    }

    cout << node->data << endl;

    TreeNode* child = node->firstChild;
    while (child != NULL) {
        printHierarchy(child);
        child = child->nextSibling;
    }
}

int main() {
    TreeNode* root = new TreeNode();

    string raiz;
    cin >> raiz;

    root->data = raiz;

    string texto;
    string fim = "fim";
    string pai;

    while (true) {
        cin >> texto >> pai;

        string aux = texto + " " + pai;

        if (aux == "fim entrada") {
            break;
        }

        TreeNode* node = new TreeNode();
        node->data = texto;

        TreeNode* parent = findSector(root, pai);
        addChildOrdered(parent, node);
    }

    cin >> texto;

    TreeNode* node = findSector(root, texto);

    printHierarchy(node);

    return 0;
}
