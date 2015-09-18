template <class T>
class Node {
    public:
        Node(T data);
        Node(T data, Node<T> *next);
        T getData();
        Node<T>* getNext(); //se usa el * del apuntador cuando es un valor de retorno.
        void setData(T data);
        void setNext(Node<T> *next);

    private:
        T data;
        Node<T> *next; //apuntador tipo nodo de tipo generico.

};

template <typename T>
Node<T>::Node(T data){
    this-> data = data;
    this->next = NULL;
}

template <typename T>
Node<T>::Node(T data, Node<T> *nnext) {
    this-> data = data;
    this-> next = nnext;
}

template <typename T>
T Node<T>::getData(){
    return this-> data;
}

template  <typename T>
Node<T>* Node<T>::getNext(){
    return next;
}

template  <typename T>
void Node<T>::setData(T data){
    this-> data = data;
}

template  <typename T>
void Node<T>::setNext(Node<T> *next){
    this-> next = next;
}