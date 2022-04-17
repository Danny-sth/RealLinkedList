template<class T> class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	int getSize() { return this->size; }
	void clear();
	void push_back(T data);
	T& operator[](const int index);
	void pop_front();
	void push_front(T data);
	void insert(T value, const int index);
	void removeAt(int index);
	void popBack();

private:
	template<class T> class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

	};
	Node<T>* head;
	int size;

	Node<T>* getPrevious(const int index)
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		return previous;
	}
};

template<class T> LinkedList<T>::LinkedList()
{
	size = 0;
	head = nullptr;
}

template<class T> LinkedList<T>::~LinkedList()
{
	clear();
}

template<class T>
void LinkedList<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<class T>
void LinkedList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<class T> T& LinkedList<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<class T>
void LinkedList<T>::pop_front()
{
	Node<T>* tmp = head->pNext;
	delete head;
	head = tmp;
	size--;
}

template<class T>
void LinkedList<T>::push_front(T data)
{
	this->head = new Node<T>(data, head);
	size++;
}

template<class T>
void LinkedList<T>::insert(T value, const int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		Node<T>* previous = getPrevious(index);

		previous->pNext = new Node<T>(value, previous->pNext);
		size++;
	}

}

template<class T>
void LinkedList<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = getPrevious(index);

		Node<T>* toDel = previous->pNext;
		previous->pNext = toDel->pNext;
		delete toDel;
	}
}

template<class T>
void LinkedList<T>::popBack()
{
	removeAt(size - 1);
}