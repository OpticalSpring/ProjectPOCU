#pragma once
#include <iostream>
#include <memory>

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
		std::shared_ptr<Node<T>> rootNode;
		unsigned int listLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
	{
		rootNode = nullptr;
		listLength = 0;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (rootNode == nullptr) 
		{
			rootNode = std::make_shared<Node<T>>(std::move(data));
			
		}
		else 
		{
			std::shared_ptr<Node<T>> curNode = std::make_shared<Node<T>>(std::move(data));
			operator[](listLength-1)->Next = curNode;
			curNode->Previous = operator[](listLength-1);
		}
		listLength++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> curNode = rootNode;
		if (*curNode->Data == data)
		{
			rootNode = curNode->Next;
			listLength--;
			return true;
		}
		for (size_t i = 0; i < listLength - 1; i++)
		{
			curNode = curNode->Next;
			if (*curNode->Data == data)
			{
				curNode->Next->Previous = curNode->Previous;
				std::shared_ptr<Node<T>> objPtr = curNode->Previous.lock();
				objPtr->Next = curNode->Next;
				listLength--;
				return true;
			}
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		
		std::shared_ptr<Node<T>> curNode = rootNode;
		if (*curNode->Data == data)
		{
			return true;
		}
		for (size_t i = 0; i < listLength-1; i++)
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

		if (index >= listLength) 
		{
			return nullptr;
		}

		std::shared_ptr<Node<T>> curNode = rootNode;
		for (size_t i = 0; i < index; i++)
		{
			curNode = curNode->Next;
		}
		return curNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return listLength;
	}
}