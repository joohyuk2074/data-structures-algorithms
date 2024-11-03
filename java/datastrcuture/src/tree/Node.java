package tree;

public class Node<T> {

    public T data;
    public int height;
    public Node<T> leftChild;
    public Node<T> rightChild;

    public Node(T data, int height, Node<T> leftChild, Node<T> rightChild) {
        this.data = data;
        this.height = height;
        this.leftChild = leftChild;
        this.rightChild = rightChild;
    }
}
