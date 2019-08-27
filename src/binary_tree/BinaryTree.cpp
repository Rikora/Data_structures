#include "BinaryTree.hpp"

namespace ds
{
	BinaryTree::BinaryTree() : m_root(nullptr) {}

	BinaryTree::~BinaryTree()
	{
		destroyTree();
	}

	// Public functions
	void BinaryTree::insert(int key)
	{
		if (m_root == nullptr)
		{
			m_root = std::make_unique<Node>(key);
		}
		else
		{
			insert(key, m_root.get());
		}
	}

	Node* BinaryTree::find(int key)
	{
		return find(key, m_root.get());
	}

	void BinaryTree::destroyTree()
	{
		destroyTree(m_root.get());
	}
	//

	// Private functions.
	void BinaryTree::destroyTree(Node* leaf)
	{
		if (leaf != nullptr)
		{
			destroyTree(leaf->leftChild.get());
			destroyTree(leaf->rightChild.get());
			leaf = nullptr;
		}
	}

	void BinaryTree::insert(int key, Node* leaf)
	{
		if (key < leaf->key)
		{
			if (leaf->leftChild == nullptr)
			{
				leaf->leftChild = std::make_unique<Node>(key);
			}
			else
			{
				insert(key, leaf->leftChild.get());
			}
		}
		else if (key >= leaf->key)
		{
			if (leaf->rightChild == nullptr)
			{
				leaf->rightChild = std::make_unique<Node>(key);
			}
			else
			{
				insert(key, leaf->rightChild.get());
			}
		}
	}

	Node* BinaryTree::find(int key, Node* leaf)
	{
		if (leaf != nullptr)
		{
			if (key == leaf->key)
			{
				return leaf;
			}
			else if (key < leaf->key)
			{
				return find(key, leaf->leftChild.get());
			}
			else
			{
				return find(key, leaf->rightChild.get());
			}
		}
		
		return nullptr;
	}
	//
}