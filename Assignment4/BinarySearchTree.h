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
		void Insert(unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const weak_ptr<TreeNode<T>> GetRootNode() const;

		static vector<T> TraverseInOrder(const shared_ptr<TreeNode<T>> startNode);
	private:
		shared_ptr<TreeNode<T>> mRootNode;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(unique_ptr<T> data)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = make_shared<TreeNode<T>>(move(data));
			return;
		}

		shared_ptr<TreeNode<T>> p = mRootNode;
		shared_ptr<TreeNode<T>> q = nullptr;

		while (p)
		{
			q = p;

			if (*p->Data >= *data)
			{
				p = p->Left;
			}
			else
			{
				p = p->Right;
			}
		}

		if (*q->Data >= *data)
		{
			q->Left = make_shared<TreeNode<T>>(move(data));
			q->Left->Parent = q;
		}
		else
		{
			q->Right = make_shared<TreeNode<T>>(move(data));
			q->Right->Parent = q;
		}
	}

	template<typename T>
	const weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
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
	vector<T> BinarySearchTree<T>::TraverseInOrder(const shared_ptr<TreeNode<T>> startNode)
	{
		vector<T> v;

		if (startNode == nullptr)
		{
			return v;
		}

		stack<shared_ptr<TreeNode<T>>> s;
		shared_ptr<TreeNode<T>> curNode = startNode;
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