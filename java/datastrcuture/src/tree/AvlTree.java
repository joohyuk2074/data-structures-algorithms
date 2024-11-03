package tree;

public class AvlTree<T> {

    private Node<T> root;

    public AvlTree(Node<T> root) {
        this.root = root;
    }

    public int nodeHeight(Node<T> p) {
        if (p == null) {
            return 0;
        }

        int leftHeight = (p.leftChild != null) ? p.leftChild.height : 0;
        int rightHeight = (p.rightChild != null) ? p.rightChild.height : 0;

        return Math.max(leftHeight, rightHeight) + 1;
    }

    public int balanceFactor(Node<T> p) {
        if (p == null) {
            return 0;
        }

        int leftHeight = (p.leftChild != null) ? p.leftChild.height : 0;
        int rightHeight = (p.rightChild != null) ? p.rightChild.height : 0;

        return leftHeight - rightHeight;
    }

    public Node<T> lLRotation(Node<T> p) {
        Node<T> pl = p.leftChild;
        Node<T> plr = pl.rightChild;

        pl.rightChild = p;
        p.leftChild = plr;

        p.height = nodeHeight(p);
        pl.height = nodeHeight(pl);

        if (root == p) {
            root = pl;
        }

        return pl;
    }
}
