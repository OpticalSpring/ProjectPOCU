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
			while (true) {
				if (*data < *curNode->Data) 
				{
					if (curNode->Left == nullptr)
					{
						cout << *curNode->Data<<"left" << *data <<  endl;
						curNode->Left = std::make_shared<TreeNode<T>>(curNode->Left, std::move(data));
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
						cout << *curNode->Data << "Right" << *data << endl;
						curNode->Right = std::make_shared<TreeNode<T>>(curNode->Right, std::move(data));
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
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return false;
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