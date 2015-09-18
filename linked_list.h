template <class T>
class LinkedList {
    public:
        LinkedList();
        LinkedList(const LinkedList<T> &lista);
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
        void operator=(const LinkedList<T> &lista);
        void operator+=(const LinkedList<T> &lista);
        void operator+=(T dato);
        bool operator==(const LinkedList<T> &lista);
        void reverse();
    private:
        Node<T> *head;
        int iC;
        void borra();
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
    iC = 0;
}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &lista) {
    iC = lista -> iC;

    Node<T> *aux = lista -> head;
    for (int i = 0; i < iC; i++){
        aux -> addLast(aux -> getData());
        aux = aux -> getNext();
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    borra();
}

template <typename T>
T LinkedList<T>::get(int pos) {
    Node<T> *aux = head;

    if (pos < 0 || pos >= iC)
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

template <typename T>
T LinkedList<T>::set(T data, int pos) {
    Node<T> *aux = head;

    if (pos < 0 || pos >= iC)
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

template <typename T>
bool LinkedList<T>::isEmpty() {
    return (head == NULL);
}

template <typename T>
void LinkedList<T>::addFirst(T data) {
    head = new Node<T>(data, head);
    iC++;
}
template <typename T>
void LinkedList<T>::addLast(T data) {
    if (isEmpty())
        addFirst(data);
    else {
        Node<T> *aux = head;
        while (aux -> getNext() != NULL){
            aux = aux->getNext();
        }
        aux = new Node<T>(data);
        iC++;
    }

}

template <typename T>
void LinkedList<T>::deleteFirst() {
    if (!this-> isEmpty()) {
        Node<T> *aux = head;
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
        Node<T> *aux = head;
        while(aux -> getNext() -> getNext() != NULL) {
            aux = aux -> getNext();
        }
        delete aux ->getNext();
        aux -> setNext(NULL);
        iC--;
    }
}

template <typename T>
bool LinkedList<T>::add(T data, int pos) {
    if (pos < 0 || pos > iC )
        return false;
    if (pos == 0)
        addFirst(data);
    if (pos == iC)
        addLast(data);
    else {
        Node<T> *aux = head;
        for( int i = 1; i < pos; i++) {
            aux = aux->getNext();
        }
        aux->setNext(new Node<T>(data, aux->getNext()));
        iC++;
    }
    return true;
}

template <typename T>
bool LinkedList<T>::del(int pos) {
    if (pos < 0 || pos >= iC)
        return false;
    if (pos == 0)
        deleteFirst();
    if (pos == iC-1)
        deleteLast();
    else {
        Node<T> *aux = head;
        Node <T> *temp;

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

template <typename T>
int LinkedList<T>::deleteAll() {
    borra();
    int iCant = iC;
    iC = 0;
    return iCant;
}

template <typename T>
void LinkedList<T>::borra() {
    Node<T> *aux = head;
    while (head != NULL) {
        head = head->getNext();
        delete aux;
        aux = head;
    }
}

template <typename T>
bool LinkedList<T>::change(int pos1, int pos2) {
    if(pos1 < 0 || pos1 >= iC || pos2 < 0 || pos2 >= iC)
        return false;
    if (pos1 == pos2)
        return true;
     int posMayor = (pos1 > pos2) ? pos1 : pos2;
     int posMenor = (pos1 < pos2) ? pos1 : pos2;
     Node <T> * aux1 = head, aux2;
     for (int i = 1; i <= posMenor; i++)
        aux1 = aux -> getNext();

    aux2 = aux1;
    for (int i=1; i <= (posMayor - posMenor); i++)
        aux2 = aux2 -> getNext();
    T temp = aux1 -> getData();
    aux->setData(aux->getData());
    aux->setData(temp);
    return true;
}

template <typename T>
void LinkedList<T>::print() {
    Node <T> *aux = head;

    while(aux != NULL) {
        cout << aux -> getData() << " " ;
        aux = aux -> getNext();
    }
}

template <typename T>
void LinkedList<T>::operator=(const LinkedList<T> &lista) {
    iC = lista -> iC;
    Node<T> *aux = head;
    for( int i = 0; i < iC; i++){
        aux -> addLast(aux -> getData());
        aux = aux -> getNext();
    }
}

template <typename T>
void LinkedList<T>::operator+=(const LinkedList<T> &lista) {
    Node<T> *aux = lista -> head;
    for (int i = 0; i < lista -> iC; i++){
        addLast(aux->getData());
        aux =  aux -> getNext();
    }
}

template <typename T>
void LinkedList<T>::operator+=(T data) {
    addLast(data);
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &lista) {
    Node<T> *aux, *aux2= lista -> head, head;
    if (iC != lista -> iC) { return false; }
    for (int i = 0; i < iC; i++) {
        if (aux2 -> getData(i) == lista -> getData(i)) {
            aux2 -> getNext();
            aux = aux -> getNext();
        }
        else {
            return false;
        }
    }
    return true;
}

template <typename T>
void LinkedList<T>::reverse() {

}