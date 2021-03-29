#pragma once

#include <memory>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		std::shared_ptr<TreeNode<T>> RemoveSeqence(std::shared_ptr<TreeNode<T>> node, T _vaule);
		std::shared_ptr<TreeNode<T>> SearchMaxNode(std::shared_ptr<TreeNode<T>> node);
	private:
		std::shared_ptr<TreeNode<T>> mRootNode;


		

	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = std::make_shared<TreeNode<T>>(std::move(data));
		}
		else
		{
			std::shared_ptr<TreeNode<T>> curNode = mRootNode;
			while (true)
			{
				if (*data < *curNode->Data)
				{
					if (curNode->Left == nullptr)
					{
						cout << *curNode->Data << " Left " << *data << endl;
						curNode->Left = std::make_shared<TreeNode<T>>(curNode, std::move(data));
						return;
					}
					else
					{
						curNode = curNode->Left;
					}
				}
				else
				{
					if (curNode->Right == nullptr)
					{
						cout << *curNode->Data << " Right " << *data << endl;
						curNode->Right = std::make_shared<TreeNode<T>>(curNode, std::move(data));
						return;
					}
					else
					{
						curNode = curNode->Right;
					}
				}
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{

		return mRootNode;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		if (mRootNode == nullptr)
		{
			return false;
		}

		std::stack<std::shared_ptr<TreeNode<T>>> s;
		std::shared_ptr<TreeNode<T>> curNode = mRootNode;

		while (curNode != nullptr || s.empty() == false)
		{
			while (curNode != nullptr)
			{
				s.push(curNode);
				curNode = curNode->Left;
			}

			curNode = s.top();
			s.pop();

			if (*curNode->Data == data)
			{
				return true;
			}

			curNode = curNode->Right;
		}

		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		if (Search(data)) 
		{
			RemoveSeqence(mRootNode, data);
			cout << "Delete" << data << endl;
			return true;
		}
		else 
		{
			return false;
		}
	}

	template <typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::RemoveSeqence(std::shared_ptr<TreeNode<T>> node, T _vaule)
	{
		if (node == nullptr || node->Data == nullptr)
			return node;
		else if (*node->Data > _vaule)
			node->Left = RemoveSeqence(node->Left, _vaule);
		else if (*node->Data < _vaule)
			node->Right = RemoveSeqence(node->Right, _vaule);
		else {
			std::shared_ptr<TreeNode<T>> ptr = node;
			//자식이없을떄 
			if (node->Right == nullptr && node->Left == nullptr)
			{
				node.reset();
				node = nullptr;
			}
			//자식이 하나일떄 
			else if (node->Right == nullptr)
			{
				node = node->Left;
				ptr.reset();
				ptr = nullptr;
			}
			else if (node->Left == nullptr)
			{
				node = node->Right;
				ptr.reset();
				ptr = nullptr;
			}
			//자식이 두개일떄 :: 왼쪽 노드중 가장큰값 찾아 부모노드로 바꾸기 
			else {
				ptr = SearchMaxNode(node->Left);
				node->Data = std::move(ptr->Data);
				node->Left = RemoveSeqence(node->Left, *node->Data);
			}
		}
		return node;
	}

	template<typename T>
	inline std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::SearchMaxNode(std::shared_ptr<TreeNode<T>> node)
	{
		if (node == nullptr)
			return nullptr;
		while (node->Right != nullptr)
		{
			node = node->Right;
		}
		return node;
	}



	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;

		if (startNode == nullptr)
		{
			return v;
		}

		std::stack<std::shared_ptr<TreeNode<T>>> s;
		std::shared_ptr<TreeNode<T>> curNode = startNode;
		while (curNode != nullptr || s.empty() == false)
		{
			while (curNode != nullptr)
			{
				s.push(curNode);
				curNode = curNode->Left;
			}

			curNode = s.top();
			s.pop();

			v.push_back(*curNode->Data);

			curNode = curNode->Right;
		}
		return v;
	}
}