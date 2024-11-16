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

    public Node<T> LLRotation(Node<T> p) {
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

    public Node<T> RRRotation(Node<T> p) {
        Node<T> pr = p.rightChild;
        Node<T> prl = pr.leftChild;

        pr.leftChild = p;
        p.rightChild = prl;

        p.height = nodeHeight(p);
        pr.height = nodeHeight(pr);

        if (root == p) {
            root = pr;
        }

        return pr;
    }

    public Node<T> LRRotation(Node<T> p) {
        Node<T> pl = p.leftChild;
        Node<T> plr = p.rightChild;

        pl.rightChild = plr.leftChild;
        p.leftChild = plr.rightChild;

        plr.leftChild = pl;
        plr.rightChild = p;

        pl.height = nodeHeight(pl);
        p.height = nodeHeight(p);
        plr.height = nodeHeight(plr);

        if (p == root) {
            root = plr;
        }

        return plr;
    }

    public Node<T> RLRotation(Node<T> p) {
        Node<T> pr = p.rightChild;
        Node<T> prl = pr.leftChild;

        pr.leftChild = prl.rightChild;
        p.rightChild = prl.leftChild;

        prl.rightChild = pr;
        prl.leftChild = p;

        // Update height
        pr.height = nodeHeight(pr);
        p.height = nodeHeight(p);
        prl.height = nodeHeight(prl);

        if (root == p) {
            root = prl;
        }

        return prl;
    }
}
