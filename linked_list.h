template <class T>
class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        T get(int pos);
        T set(T data, int pos);
        bool isEmpty();
        void addFirst(T data);
        void addLast(T data);
        void deleteFirst();
        void deleteLast();
        bool add(T data, int pos);
        bool del(int pos);
        int deleteAll();
        bool change(int pos1, int pos2);
        void print();
    private:
        Node<T> *head;
        int iC;
        void borra();
};

template<typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
    iC = 0;
}
template typename<T>
void LinkedList<T>~LinkedList() {
    borra();
}

template typename <T>
T LinkedList<T>::get(int pos) {
    Node<T> *aux = head;

    if (pos < 0 || pos >= iCant)
        return false;
    if (pos == 0)
        return head->getData();
    else {
        for(int i = 0; i < pos; i++)
            aux = aux->getNext();
        return head->getData();
    }
    delete aux;
}

template typename <T>
T LinkedList<T>::set(T data, int pos) {
    Node<T> *aux = head;

    if (pos < 0 || pos >= iCant)
        return false;
    if (pos == 0)
        head -> setData(data);
    else {
        for(int i = 0; i < pos; i++)
            aux = aux -> getNext();
        aux -> setNext(data);
    }
    delete aux;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return (head == NULL);
}

template<typename T>
void LinkedList<T>::addFirst(T data) {
    head = new Node<T>(data, head);
    iC++
}
template<typename T>
void LinkedList<T>::addLast(T data) {
    if (isEmpty())
        addFirst(data)
    else {
        Node<T> *aux = head;
        while (aux -> getNext() != NULL){
            aux = aux->getNext();
        }
        aux -> new node<T>(data);
        iC++;
    }

}

template <typename T>
void LinkedList<T>::deleteFirst() {
    if (!this-> isEmpty()) {
        node<T> *aux = head;
        head = head->getNext();
        delete aux;
        iC--;
    }
}

template <typename T>
void LinkedList<T>::deleteLast() {
    if (iC <= 1) {
        this-> deleteFirst();
    }

    else {
        node<T> *aux = head;
        while(aux -> getNext() -> getNext() != NULL) {
            aux = aux -> getNext();
        }
        delete aux ->getNext();
        aux -> setNext(NULL);
        iC--;
    }
}

template typename<T>
bool LinkedList<T>::add(T data, int pos) {
    if (pos < 0 || pos > iC )
        return false;
    if (pos == 0)
        addFirst(data);
    if (pos == iC)
        addLast(data);
    else {
        node<T> *aux = head;
        for( int i = 1; i < pos; i++) {
            aux = aux->getNext();
        }
        aux->setNext(new node<T>(data, aux->getNext()));
        iC++;
    }
    return true;
}

template typename<T>
bool LinkedList<T>::del(int pos) {
    if (pos < 0 || pos >= iC)
        return false;
    if (post == 0)
        deleteFirst();
    if (pos == iC-1)
        deleteLast();
    else {
        node<T> *aux = head;
        node <T> *temp;

        for (int i = 1; i < pos; ++i) {
            aux = aux->getNext();
        }
        temp = aux -> getNext();
        aux->setNext(aux->getNext()->getNext());
        delete temp;
        iC--;
    }
    return true;
}

template typename <T>
int LinkedList<T>::deleteAll() {
    borra();
    int iCant = iC;
    iC = 0;
    return iCant;
}

template typename<T>
void LinkedList<T>::borra() {
    node<T> *aux = head;
    whlie (head != NULL) {
        head = head->getNext();
        delete aux;
        aux = head;
    }
}

template typename<T>
bool LinkedList<T>::change(int pos1, int pos2) {
    if(pos1 < 0 || pos1 >= iC || pos2 < 0 || pos2 >= iC)
        return false;
    if (pos1 == pos2)
        return true;
     int posMayor = (pos1 > pos2) ? pos1 : pos2;
     int posMenor = (pos1 < pos2) ? pos1 : pos2;
     node <T> * aux1 = head, aux2;
     for (int i = 1; i <= posMenor; i++)
        aux1 = aux -> getNext();

    aux2 = aux1;
    for (int i=1 i <= (posMayor - posMenor); i++)
        aux2 = aux2 -> getNext();
    T temp = aux1 -> getData();
    aux->setData(aux->getData());
    aux->setData(temp);
    return true;
}

template typename <T>
void LinkedList<T>::print() {
    Node <T> *aux = head;

    while(aux != NULL) {
        cout << aux -> getData() << " "
        aux = aux -> getNext();
    }
}