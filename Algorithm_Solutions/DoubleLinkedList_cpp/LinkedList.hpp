template <typename T>
typename LinkedList<T>::LinkedList() : head(NULL), tail(NULL), size(0) {}

template <typename T>
LinkedList<T>::Node::Node() : next(NULL), prev(NULL), data(T()) {}

template <typename T>
LinkedList<T>::Node::Node(const T& ndata) : next(NULL), prev(NULL), data(ndata) {}

// Returns the number of elements in the List
template <typename T>
int LinkedList<T>::size() const {
    return size;
}

//clear the list
template <typename T>
void LinkedList<T>::clear() {
    Node *iter = head->next;
    while(iter->next) {
        delete iter->prev;
        iter = iter->next;
    }
    delete iter;
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//destructor, calls the clear
template <typename T>
LinkedList<T>::~LinkedList() {
    this->clear();
}

//insert at list head
template <typename T>
void LinkedList<T>::push_front(const T& data) {
    Node* temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        tail = temp;
        size++;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
    size++:

}

//insert at list tail
template <typename T>
void LinkedList<T>::push_back(const T& data) {
    Node *temp = new Node(data);
    if (tail == nullptr) {
        head = temp;
        tail = temp;
        size++;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
    size++;
    return;
}

template <typename T>
void insert(const T& data, int index) {
    if (index == 0)  {
        push_front(data);
        return;
    }
    else if (index >= size) {
        push_back(data);
        return;
    }

    Node *temp = new Node(data);
    if (index >=size/2) {
        Node *iter = tail;
        int iter_index = size-1;
        while(iter_index != index) {
            iter = iter->prev;
            iter_index--;
        }
        iter->prev->next = temp;
        temp->prev = iter->prev
        temp->next = iter;
        iter->prev = temp;
        size++;
    }
    else {
        Node *iter = head;
        int iter_index = 0;
        while (iter_index != index) {
            iter = iter->next;
            iter_index++;
        }
        iter->prev->next = temp;
        temp->prev = iter->prev;
        temp->next = iter;
        iter->prev - temp;
        size++;
    }
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return;
    }
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
    size--;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (size == 1) {
        this->pop_front();
    }
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
    size--;
}

template <typename T>
void LinkedList<T>::remove(int index) {
    if (index == 0)
        pop_front();
    else if (index == size-1)
        pop_back();
    else if (index >= size || index < 0)
        return;
    else {
        if (index >=size/2) {
	        Node *iter = tail;
	        int iter_index = size-1;
	        while(iter_index != index) {
	            iter = iter->prev;
	            iter_index--;
	        }
	        iter->prev->next = iter->next;
	        iter->next->prev = iter->prev;
	        delete iter;
	        size--;
    	}
    	else {
	        Node *iter = head;
	        int iter_index = 0;
	        while (iter_index != index) {
	            iter = iter->next;
	            iter_index++;
	        }
	        iter->prev->next = iter->next;
	        iter->next->prev = iter->prev;
	        delete iter;
	        size--;
	    }

    }
}

template <typename T>
bool LinkedList<T>::empty() const {
    return size == 0;
}

template <typename T>
LinkedList<T>::Node* LinkedList<T>::get(int index) const {
    if (index >=size/2) {
        Node *iter = tail;
        int iter_index = size-1;
        while(iter_index != index) {
            iter = iter->prev;
            iter_index--;
        }
        return iter;
    }
    else {
        Node *iter = head;
        int iter_index = 0;
        while (iter_index != index) {
            iter = iter->next;
            iter_index++;
        }
        return iter;
    }
}
