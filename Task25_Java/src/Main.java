/*
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Scanner;

class Node {
    private long data;
    private Node left;
    private Node right;
    private int leftChildren, rightChildren;
    private static int maxDiff = -1;
    static int possibleDeleteNotesCount = 0;
    static int deleteCountBuff;
    public Node(long data) {
        this.data = data;
        this.left = this.right = null;
        leftChildren = rightChildren = 0;
    }

    public int calcChildren()
    {
        if (this == null)
            return 0;

        if (left != null)
            leftChildren = left.calcChildren();
        else leftChildren = 0;
        if (right != null)
            rightChildren = right.calcChildren();
        else rightChildren = 0;

        return leftChildren + rightChildren + 1;
    }

    public static void insertNode(Node root, long newData) {
        if (root == null)
            root = new Node(newData);
        else if (newData == root.data)
            return;
        else if (newData > root.data)
            if (root.right != null)
                insertNode(root.right, newData);
            else
                root.right = new Node(newData);
        else if (newData < root.data)
            if (root.left != null)
                insertNode(root.left, newData);
            else
                root.left = new Node(newData);
    }

    public static void printTree(Node root, FileWriter  out) throws IOException {
        if (root == null)
            return;

        out.write(root.data + "\n");
        printTree(root.left, out);
        printTree(root.right, out);
    }

    public static Node deleteNode(Node root, int key)
    {
        if (root == null)
            return root;

        if (root.data > key)
        {
            root.left = deleteNode(root.left, key);
            return root;
        }
        else if (root.data < key)
        {
            root.right = deleteNode(root.right, key);
            return root;
        }

        if (root.left == null)
        {
            Node temp = root.right;
            return temp;
        }
        else if (root.right == null)
        {
            Node temp = root.left;
            return temp;
        }
        else
        {
            Node succParent = root;
            Node succ = root.right;
            while (succ.left != null) {
                succParent = succ;
                succ = succ.left;
            }
            if (succParent != root)
                succParent.left = succ.right;
            else
                succParent.right = succ.right;

            root.data = succ.data;

            return root;
        }
    }

    public int findDeleteKey()
    {
        ArrayList<Integer> possibleVector = new ArrayList<>();

        possibleVector.ensureCapacity(possibleDeleteNotesCount);
        while (possibleVector.size() < possibleDeleteNotesCount) {
            possibleVector.add(null);
        }

        deleteCountBuff = possibleDeleteNotesCount;
        findFunction(possibleVector);

        int count = possibleDeleteNotesCount;
        count /= 2;

        return possibleVector.get(count);
    }

    public void findFunction(ArrayList<Integer> notesVector) {
        if (this == null)
            return;

        if (this.left != null) {
            this.left.findFunction(notesVector);
        }
        if (Math.abs(this.leftChildren - this.rightChildren) == maxDiff) {
            deleteCountBuff--;
            notesVector.set(deleteCountBuff, (int) this.data);
        }
        if (this.right != null) {
            this.right.findFunction(notesVector);
        }
    }

    public static void deleteMedKey(Node root) throws IOException {
        root.findMaxDifference();

        FileWriter fout = new FileWriter("tst.out");

        if (possibleDeleteNotesCount % 2 == 0) {

            printTree(root, fout);

            fout.close();

            return;
        }

        int deleteKey = root.findDeleteKey();
        root = deleteNode(root, deleteKey);


        printTree(root, fout);

        fout.close();
    }

    public void findMaxDifference() {
        if (this == null)
            return;

        if (Math.abs(this.leftChildren - this.rightChildren) > maxDiff) {
            maxDiff = Math.abs(this.leftChildren - this.rightChildren);
            possibleDeleteNotesCount = 1;
        } else if (Math.abs(this.leftChildren - this.rightChildren) == maxDiff) {
            possibleDeleteNotesCount++;
        }

        if (this.left != null) {
            this.left.findMaxDifference();
        }
        if (this.right != null) {
            this.right.findMaxDifference();
        }
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("tst.in"));

        int newKey;
        if (scanner.hasNextInt())
        {
            newKey = scanner.nextInt();
        }
        else
        {
            return;
        }

        Node root = new Node(newKey);
        while (scanner.hasNextInt()) {
            newKey = scanner.nextInt();
            Node.insertNode(root, newKey);
        }

        root.calcChildren();

        Node.deleteMedKey(root);

        scanner.close();
    }
}
*/


import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Scanner;

class Node {
    private long data;
    private Node left;
    private Node right;
    private int leftChildren, rightChildren;
    private static int maxDiff = -1;
    static int possibleDeleteNotesCount = 0;
    static int deleteCountBuff;
    public Node(long data) {
        this.data = data;
        this.left = this.right = null;
        leftChildren = rightChildren = 0;
    }

    public int calcChildren() {
        if (this == null) {
            return 0;
        }

        leftChildren = (left != null) ? left.calcChildren() : 0;
        rightChildren = (right != null) ? right.calcChildren() : 0;

        return leftChildren + rightChildren + 1;
    }

    public static void insertNode(Node root, long newData) {
        if (root == null)
            root = new Node(newData);
        else if (newData == root.data)
            return;
        else if (newData > root.data)
            if (root.right != null)
                insertNode(root.right, newData);
            else
                root.right = new Node(newData);
        else if (newData < root.data)
            if (root.left != null)
                insertNode(root.left, newData);
            else
                root.left = new Node(newData);
    }

    public static void printTree(Node root, Appendable  out) throws IOException {
        if (root == null)
            return;

        out.append(root.data + "\n");
        printTree(root.left, out);
        printTree(root.right, out);
    }

    public static Node deleteNode(Node root, int key)
    {
        if (root == null)
            return root;

        if (root.data > key)
        {
            root.left = deleteNode(root.left, key);
            return root;
        }
        else if (root.data < key)
        {
            root.right = deleteNode(root.right, key);
            return root;
        }

        if (root.left == null)
        {
            Node temp = root.right;
            return temp;
        }
        else if (root.right == null)
        {
            Node temp = root.left;
            return temp;
        }
        else {
            long min = findMinData(root.right).data;
            root.data = min;
            root.right = deleteNode(root.right, (int)min);

            return root;
        }
    }

    public int findDeleteKey() {
        ArrayList<Integer> possibleVector = new ArrayList<>();

        possibleVector.ensureCapacity(possibleDeleteNotesCount);
        while (possibleVector.size() < possibleDeleteNotesCount) {
            possibleVector.add(null);
        }

        deleteCountBuff = possibleDeleteNotesCount;
        findFunction(possibleVector);

        int count = possibleDeleteNotesCount;
        count /= 2;

        return possibleVector.get(count);
    }

    public void findFunction(ArrayList<Integer> notesVector) {
        if (this == null)
            return;

        if (this.left != null) {
            this.left.findFunction(notesVector);
        }
        if (Math.abs(this.leftChildren - this.rightChildren) == maxDiff) {
            deleteCountBuff--;
            notesVector.set(deleteCountBuff, (int) this.data);
        }
        if (this.right != null) {
            this.right.findFunction(notesVector);
        }
    }

    public static void deleteMedKey(Node root) throws IOException {
        root.findMaxDifference();

        FileWriter fout = new FileWriter("tst.out");

        if (possibleDeleteNotesCount % 2 == 0) {
            //printTree(root, System.out);
            printTree(root, fout);

            fout.close();

            return;
        }

        int deleteKey = root.findDeleteKey();
        root = deleteNode(root, deleteKey);

        //printTree(root, System.out);
        printTree(root, fout);

        fout.close();
    }

    public void findMaxDifference() {
        if (this == null)
            return;

        if (Math.abs(this.leftChildren - this.rightChildren) > maxDiff) {
            maxDiff = Math.abs(this.leftChildren - this.rightChildren);
            possibleDeleteNotesCount = 1;
        } else if (Math.abs(this.leftChildren - this.rightChildren) == maxDiff) {
            possibleDeleteNotesCount++;
        }

        if (this.left != null) {
            this.left.findMaxDifference();
        }
        if (this.right != null) {
            this.right.findMaxDifference();
        }
    }

    private static Node findMinData(Node root) {
        if (root.left != null)
            return findMinData(root.left);
        else
            return root;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new File("tst.in"));

        int newKey;
        if (scanner.hasNextInt())
        {
            newKey = scanner.nextInt();
        }
        else
        {
            return;
        }
        //Node root = null;
        Node root = new Node(newKey);
        while (scanner.hasNextInt()) {
            newKey = scanner.nextInt();
            Node.insertNode(root, newKey);
        }

        root.calcChildren();

        Node.deleteMedKey(root);

        scanner.close();
    }
}