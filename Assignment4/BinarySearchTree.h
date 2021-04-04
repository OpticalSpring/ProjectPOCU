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
		shared_ptr<TreeNode<T>> p = mRootNode;
		shared_ptr<TreeNode<T>> q = nullptr;
		while (p)
		{
			if (data == *p->Data)
			{
				break;
			}
			if (data < *p->Data)
			{
				q = p;
				p = p->Left;
			}
			else
			{
				q = p;
				p = p->Right;
			}
		}
		if (!p)
		{
			return false;
		}
		return true;
	}
	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		shared_ptr<TreeNode<T>> p = mRootNode;
		shared_ptr<TreeNode<T>> q = nullptr;
		shared_ptr<TreeNode<T>> child = nullptr;
		while (p)
		{
			if (data == *p->Data)
			{
				break;
			}
			if (data < *p->Data)
			{
				q = p;
				p = p->Left;
			}
			else
			{
				q = p;
				p = p->Right;
			}
		}
		if (!p)
		{
			return false;
		}
		else
		{
			if (p->Left == nullptr && p->Right == nullptr)
			{
				if (q)
				{
					if (q->Right == p)
					{
						q->Right = nullptr;
					}
					else if (q->Left == p)
					{
						q->Left = nullptr;
					}
				}
				else
				{
					mRootNode = nullptr;
				}
			}
			else if (p->Left == nullptr || p->Right == nullptr)
			{

				child = (p->Left != nullptr) ? p->Left : p->Right;
				if (q)
				{
					if (q->Left == p)
					{
						q->Left = child;
					}
					else if (q->Right == p)
					{
						q->Right = child;
					}
				}
				else
				{
					mRootNode = child;
				}
			}
			else
			{

				shared_ptr<TreeNode<T>> searchPtr = p;
				shared_ptr<TreeNode<T>> search = nullptr;
				search = searchPtr->Right;
				while (search->Left != nullptr)
				{
					searchPtr = search;
					search = search->Left;
				}
				if (searchPtr->Left == search)
				{
					searchPtr->Left = search->Right;
				}
				else
				{
					searchPtr->Right = search->Right;
				}


				p->Data = move(search->Data);
				search.reset();
				searchPtr.reset();
			}

		}
		return true;
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