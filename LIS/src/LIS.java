import java.io.*;
import java.util.Scanner;
import java.util.Vector;

public class LIS {

    public static int upperBound(Vector<Integer> arr, int request)
    {
        int l = 0, r = arr.size();
        while (l < r)
        {
            int k = (r + l)/2;

            if(arr.elementAt(k) > request)
                r = k;
            else
                l = k + 1;
        }

        return l;
    }

    public static int findLisLength(Vector<Integer> inputSequence)
    {
        int ans = 0;
        Vector<Integer> subseqLengths = new Vector<>();
        subseqLengths.setSize(inputSequence.size() + 1);
        for (int i = 0; i < subseqLengths.size(); i++)
            subseqLengths.setElementAt(Integer.MAX_VALUE, i);
        subseqLengths.setElementAt(Integer.MIN_VALUE, 0);

        for (int i = 0; i < inputSequence.size(); i++)
        {
            int l = upperBound(subseqLengths, inputSequence.elementAt(i));
            if (subseqLengths.elementAt(l - 1) < inputSequence.elementAt(i)
                    && inputSequence.elementAt(i) < subseqLengths.elementAt(l))
                subseqLengths.setElementAt(inputSequence.elementAt(i), l);
        }

        for (int l = 0; l <= inputSequence.size(); l++)
            if (subseqLengths.elementAt(l) < Integer.MAX_VALUE)
                ans = l;

        return ans;
    }


    public static void main(String[] args) throws FileNotFoundException
    {
        File inputFile = new File("input.txt");
        Scanner in = new Scanner(inputFile);

        int n = in.nextInt();
        Vector <Integer> sequence = new Vector<>();
        for (int i = 0; i < n; i++)
            sequence.addElement(in.nextInt());
        in.close();

        File outputFile = new File("output.txt");
        PrintWriter writer = new PrintWriter(outputFile);
        writer.println(findLisLength(sequence));
        writer.close();
    }
}
