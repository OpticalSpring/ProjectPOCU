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
		shared_ptr<TreeNode<T>> p = mRootNode;
		shared_ptr<TreeNode<T>> q = nullptr;
		shared_ptr<TreeNode<T>> child = nullptr;
		while (p)
		{
			if (data == *p->Data)
				break;
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
		else {
			if (p->Left == nullptr && p->Right == nullptr) 
			{
				if (q) 
				{
					if (q->Right == p)
					{
						q->Right = nullptr;
						cout << "삭제된 값 :  " << *p->Data;
					}
					else if (q->Left == p)
					{
						q->Left = nullptr;
						cout << "삭제된 값 :   " << *p->Data;
					}
				}
				else
				{
					mRootNode = nullptr; // 부모노드가 NULL인 노드는 루트노드이다. 루트노드를 삭제한다.
					cout << "삭제 대상이 루트노드입니다. 트리가 비어있습니다. " << "\n";
				}
			}
			else if (p->Left == nullptr || p->Right == nullptr) // 하나의 서브트리를 가지는 경우의 삭제이다.
			{
				cout << "삭제 대상이 하나의 서브트리를 가지고 있습니다." << "\n";
				child = (p->Left != nullptr) ? p->Left : p->Right; // 하나의 서브트리가 왼쪽인경우와 오른쪽인 경우를 찾아냈다.
				if (q) // 부모노드가 NULL이 아닌경우 부모노드의 링크와 삭제대상의 서브트리를 이어준다.
				{
					if (q->Left == p)
					{
						q->Left = child;
						cout << "삭제된 값  :   " << *p->Data;
					}
					else if (q->Right == p)
					{
						q->Right = child;
						cout << "삭제된 값 :   " << *p->Data;
					}
				}
				else
				{
					mRootNode = child; // 부모노드가 NULL인 경우 삭제대상은 루트노드이다. 루트는 자식이 된다.
					cout << "삭제 대상이 루트노드입니다. " << "\n";
				}
			}
			else // 두개의 서브트리를 가지는 경우의 삭제이다.
			{
				cout << "삭제 대상이 두개의 서브트리를 가지고 있습니다 . 오른쪽 서브트리에서 가장 작은 값을 찾습니다. " << "\n";
				shared_ptr<TreeNode<T>> search_p = p;
				shared_ptr<TreeNode<T>> search = 0;
				search = search_p->Right;
				while (search->Left != 0) // 오른쪽 서브트리에서 가장 작은 값을 찾는다.
				{
					search_p = search;
					search = search->Left;
				}
				if (search_p->Left == search)
				{
					search_p->Left = search->Right;
				}
				else
					search_p->Right = search->Right;
				cout << "삭제될 값 : " << *p->Data << "교체 될 값 : " << *search->Data << "\n";

				p->Data = move(search->Data);
				search.reset();
				search_p.reset();
			}

		}
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