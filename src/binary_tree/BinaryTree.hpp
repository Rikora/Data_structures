#pragma once

#include <memory>

namespace ds
{
	struct Node
	{
		Node() = default;
		Node(int key) : key(key), leftChild(nullptr), rightChild(nullptr) {}

		int key;
		std::unique_ptr<Node> leftChild;
		std::unique_ptr<Node> rightChild;
	};

	class BinaryTree
	{
	public:
		BinaryTree();
		~BinaryTree();

		void insert(int key);
		Node* find(int key);
		void destroyTree();

	private:
		void destroyTree(Node* leaf);
		void insert(int key, Node* leaf);
		Node* find(int key, Node* leaf);

		std::unique_ptr<Node> m_root;
	};
}