/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:28:42 by aribesni          #+#    #+#             */
/*   Updated: 2022/08/16 10:28:46 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct      s_node {

    struct s_node   *parent;
    struct s_node   *left;
    struct s_node   *right;
    int             data;
    int             color;
}                   t_node;

class RedBlackTree {

    public :

        t_node  *root;
        t_node  *TNULL;
/*
        void initializeNULLNode(t_node* node, t_node* parent) {

            node->data = 0;
            node->parent = parent;
            node->left = nullptr;
            node->right = nullptr;
            node->color = 0;
        }

        // Preorder
        void    preOrderHelper(t_node* node) {

            if (node != TNULL)
            {
                cout << node->data << " ";
                preOrderHelper(node->left);
                preOrderHelper(node->right);
            }
        }

        // Inorder
        void    inOrderHelper(t_node* node) {

            if (node != TNULL) 
            {
                inOrderHelper(node->left);
                cout << node->data << " ";
                inOrderHelper(node->right);
            }
        }

        // Post order
        void    postOrderHelper(t_node* node)
        {
            if (node != TNULL)
            {
                postOrderHelper(node->left);
                postOrderHelper(node->right);
                cout << node->data << " ";
            }
        }

        t_node* searchTreeHelper(t_node* node, int key) {

            if (node == TNULL || key == node->data)
                return node;
            if (key < node->data)
                return searchTreeHelper(node->left, key);
            return searchTreeHelper(node->right, key);
        }
*/
        void    balance_after_delete(t_node* x) {

            t_node* s;

            while (x != root && x->color == 0)
            {
                if (x == x->parent->left)
                {
                    s = x->parent->right;
                    if (s->color == 1)
                    {
                        s->color = 0;
                        x->parent->color = 1;
                        leftRotate(x->parent);
                        s = x->parent->right;
                    }
                    if (s->left->color == 0 && s->right->color == 0)
                    {
                        s->color = 1;
                        x = x->parent;
                    } 
                    else
                    {
                        if (s->right->color == 0)
                        {
                            s->left->color = 0;
                            s->color = 1;
                            rightRotate(s);
                            s = x->parent->right;
                        }
                        s->color = x->parent->color;
                        x->parent->color = 0;
                        s->right->color = 0;
                        leftRotate(x->parent);
                        x = root;
                    }
                }
                else
                {
                    s = x->parent->left;
                    if (s->color == 1)
                    {
                        s->color = 0;
                        x->parent->color = 1;
                        rightRotate(x->parent);
                        s = x->parent->left;
                    }
                    if (s->right->color == 0 && s->right->color == 0)
                    {
                        s->color = 1;
                        x = x->parent;
                    } 
                    else
                    {
                        if (s->left->color == 0)
                        {
                            s->right->color = 0;
                            s->color = 1;
                            leftRotate(s);
                            s = x->parent->left;
                        }
                        s->color = x->parent->color;
                        x->parent->color = 0;
                        s->left->color = 0;
                        rightRotate(x->parent);
                        x = root;
                    }
                }
            }
            x->color = 0;
        }

        void    rbTransplant(t_node* u, t_node* v) {
            
            if (u->parent == nullptr)
                root = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }

        void    balance_after_insert(t_node* k) {

            t_node* u;

            while (k->parent->color == 1)
            {
                if (k->parent == k->parent->parent->right)
                {
                    u = k->parent->parent->left;
                    if (u->color == 1)
                    {
                        u->color = 0;
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        k = k->parent->parent;
                    }
                    else
                    {
                        if (k == k->parent->left)
                        {
                            k = k->parent;
                            rightRotate(k);
                        }
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        leftRotate(k->parent->parent);
                    }
                }
                else
                {
                    u = k->parent->parent->right;
                    if (u->color == 1)
                    {
                        u->color = 0;
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        k = k->parent->parent;
                    }
                    else
                    {
                        if (k == k->parent->right)
                        {
                            k = k->parent;
                            leftRotate(k);
                        }
                        k->parent->color = 0;
                        k->parent->parent->color = 1;
                        rightRotate(k->parent->parent);
                    }
                }
                if (k == root)
                    break;
            }
            root->color = 0;
        }

        // void    print_node(t_node* root, string indent, bool last) {

        //     if (root != TNULL)
        //     {
        //         cout << indent;
        //         if (last)
        //         {
        //             cout << "R----";
        //             indent += "   ";
        //         }
        //         else
        //         {
        //             cout << "L----";
        //             indent += "|  ";
        //         }
        //         string sColor = root->color ? "RED" : "BLACK";
        //         cout << root->data << "(" << sColor << ")" << endl;
        //         print_node(root->left, indent, false);
        //         print_node(root->right, indent, true);
        //     }
        // }

    // public:

        RedBlackTree() {

            TNULL = new t_node;
            TNULL->color = 0;
            TNULL->left = nullptr;
            TNULL->right = nullptr;
            root = TNULL;
        }
/*
        void    preorder() { preOrderHelper(this->root); }

        void    inorder() { inOrderHelper(this->root); }

        void    postorder() { postOrderHelper(this->root); }

        t_node* searchTree(int k) { return (searchTreeHelper(this->root, k)); }
*/
        t_node* minimum(t_node* node) {

            while (node->left != TNULL)
                node = node->left;
            return (node);
        }

        t_node* maximum(t_node* node) {

            while (node->right != TNULL)
                node = node->right;
            return (node);
        }

        t_node* previous_node(t_node* x) {

            if (x->right != TNULL)
                return (minimum(x->right));
            t_node* y = x->parent;
            while (y != TNULL && x == y->right)
            {
                x = y;
                y = y->parent;
            }
            return (y);
        }

        t_node* next_node(t_node* x) {

            if (x->left != TNULL)
                return (maximum(x->left));
            t_node* y = x->parent;
            while (y != TNULL && x == y->left)
            {
                x = y;
                y = y->parent;
            }
            return (y);
        }

        void    leftRotate(t_node* x) {

            t_node* y = x->right;
            x->right = y->left;
            if (y->left != TNULL)
                y->left->parent = x;
            y->parent = x->parent;
            if (x->parent == nullptr)
                this->root = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }

        void    rightRotate(t_node* x) {

            t_node* y = x->left;
            x->left = y->right;
            if (y->right != TNULL)
                y->right->parent = x;
            y->parent = x->parent;
            if (x->parent == nullptr)
                this->root = y;
            else if (x == x->parent->right)
                x->parent->right = y;
            else
                x->parent->left = y;
            y->right = x;
            x->parent = y;
        }

        // Inserting a node
        void    insert(int key) {

            t_node* node = new t_node;
            t_node* y = nullptr;
            t_node* x = this->root;

            node->parent = nullptr;
            node->data = key;
            node->left = TNULL;
            node->right = TNULL;
            node->color = 1;
            while (x != TNULL) {

                y = x;
                if (node->data < x->data)
                    x = x->left;
                else
                    x = x->right;
            }
            node->parent = y;
            if (y == nullptr)
                root = node;
            else if (node->data < y->data)
                y->left = node;
            else
                y->right = node;
            if (node->parent == nullptr)
            {
                node->color = 0;
                return ;
            }
            if (node->parent->parent == nullptr)
                return ;
            balance_after_insert(node);
        }

        // t_node* getRoot() { return (this->root); }

        void    deleteNode(int key) {

            t_node* z = TNULL;
            t_node  *x, *y;
            t_node* node = this->root;

            while (node != TNULL)
            {
                if (node->data == key)
                    z = node;
                if (node->data <= key)
                    node = node->right;
                else
                node = node->left;
            }
            if (z == TNULL)
            {
            std::cout << "Key not found in the tree" << std::endl;
            return ;
            }
            y = z;
            int y_original_color = y->color;
            if (z->left == TNULL)
            {
                x = z->right;
                rbTransplant(z, z->right);
            } 
            else if (z->right == TNULL)
            {
                x = z->left;
                rbTransplant(z, z->left);
            }
            else
            {
                y = minimum(z->right);
                y_original_color = y->color;
                x = y->right;
                if (y->parent == z)
                    x->parent = y;
                else
                {
                    rbTransplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                }
                rbTransplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
            }
            delete z;
            if (y_original_color == 0)
                balance_after_delete(x);
        }

        // void printTree() {

        //     if (root)
        //         print_node(this->root, "", true);
        // }
};
