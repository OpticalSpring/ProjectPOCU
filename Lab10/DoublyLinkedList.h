#pragma once
#include <iostream>
#include <memory>
using namespace std;
namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
	private:
		std::shared_ptr<Node<T>> mRootNode;
		unsigned int mListLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
	{
		mRootNode = nullptr;
		mListLength = 0;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRootNode == nullptr)
		{
			mRootNode = std::make_shared<Node<T>>(std::move(data));

		}
		else
		{
			std::shared_ptr<Node<T>> curNode = std::make_shared<Node<T>>(std::move(data));
			operator[](mListLength - 1)->Next = curNode;
			curNode->Previous = operator[](mListLength - 1);
		}
		mListLength++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (index < 0)
		{
			return;
		}
		if (index > GetLength() - 1)
		{
			Insert(std::move(data));
			return;
		}
		std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(std::move(data));
		std::shared_ptr<Node<T>> curNode = mRootNode;

		if (index == 0)
		{
			newNode->Next = curNode;
			curNode->Previous = newNode;
			mRootNode = newNode;
			mListLength++;
			return;
		}
		unsigned int count = 0;

		while (count < index)
		{
			curNode = curNode->Next;
			count++;
		}
		newNode->Next = curNode;
		newNode->Previous = curNode->Previous.lock();
		curNode->Previous.lock()->Next = newNode;
		curNode->Previous = newNode;
		mListLength++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		if (GetLength() == 0)
		{
			return false;
		}
		std::shared_ptr<Node<T>> curNode = mRootNode;
		if (*curNode->Data == data)
		{
			mRootNode = curNode->Next;
			if (curNode->Next != nullptr)
			{
				curNode->Next->Previous.lock() = nullptr;
			}
			mListLength--;
			return true;
		}
		while (true)
		{
			curNode = curNode->Next;
			if (curNode == nullptr)
			{
				return false;
			}
			if (*curNode->Data == data)
			{
				curNode->Previous.lock()->Next = curNode->Next;
				curNode->Previous.lock() = nullptr;
				if (curNode->Next != nullptr) {

					curNode->Next->Previous = curNode->Previous;
					curNode->Next = nullptr;
				}

				mListLength--;
				return true;
			}
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		if (GetLength() == 0)
		{
			return false;
		}
		std::shared_ptr<Node<T>> curNode = mRootNode;
		if (*curNode->Data == data)
		{
			return true;
		}
		for (size_t i = 0; i < mListLength - 1; i++)
		{
			curNode = curNode->Next;
			if (*curNode->Data == data)
			{
				return true;
			}
		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{

		if (index >= mListLength)
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> curNode = mRootNode;
		for (size_t i = 0; i < index; i++)
		{
			curNode = curNode->Next;
		}
		return curNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mListLength;
	}
}