package Solution;

import java.util.Scanner;
import java.util.StringTokenizer;

public class BinarySearch {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int arrSize, requestsSize;

        arrSize = Integer.parseInt(in.nextLine());
        int[] arr = new int[arrSize];
        StringTokenizer st1 = new StringTokenizer(in.nextLine(), " ");
        for (int i = 0; i < arrSize; i++)
        {
            arr[i] = (Integer.parseInt(st1.nextToken()));
        }

        requestsSize = Integer.parseInt(in.nextLine());
        int[] requests = new int[requestsSize];
        int[][] answer = new int[requestsSize][3];
        StringTokenizer st2 = new StringTokenizer(in.nextLine(), " ");
        for (int i = 0; i < requestsSize; i++)
        {
            requests[i] = (Integer.parseInt(st2.nextToken()));
        }

        boolean flag = false;
        int m = requestsSize - 1;
        while (m >= 0)
        {
            flag = false;
            int l = 0, r = arrSize;
            while (l < r)
            {
                int k = (r + l)/2;

                if(arr[k] < requests[m])
                {
                    l = k + 1;
                }
                else  if (arr[k] > requests[m]){
                    r = k;
                }
                else  if (arr[k] == requests[m])
                {
                    flag = true;
                    answer[m][0] = 1;
                    break;
                }
            }

            if (!flag)
            {
                answer[m][0] = 0;
            }
            m--;
        }

        m = requestsSize - 1;
        while (m >= 0)
        {
            int l = 0, r = arrSize;
            while (l < r)
            {
                int k = (r + l)/2;

                if(arr[k] < requests[m])
                {
                    l = k + 1;
                }
                else {
                    r = k;
                }
            }

            answer[m][1] = l;
            m--;
        }

        m = requestsSize - 1;
        while (m >= 0)
        {
            int l = 0, r = arrSize;
            while (l < r)
            {
                int k = (r + l)/2;

                if(arr[k] > requests[m])
                {
                    r = k;
                }
                else {
                    l = k + 1;
                }
            }

            answer[m][2] = l;
            m--;
        }

        for (int i = 0; i < requestsSize; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                System.out.print(answer[i][j] + " ");
            }
            System.out.println("");
        }
    }
}

/*
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class BinarySearch {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        int arrSize, requestsSize;
        Vector<Integer> arr = new Vector<Integer>();
        Vector<Integer> requests = new Vector<Integer>();
        Vector<Vector<Integer>> answer = new Vector<Vector<Integer>>();

        arrSize = Integer.parseInt(in.nextLine());
        StringTokenizer st1 = new StringTokenizer(in.nextLine(), " ");
        for (int i = 0; i < arrSize; i++)
        {
            arr.addElement(Integer.parseInt(st1.nextToken()));
        }

        requestsSize = Integer.parseInt(in.nextLine());
        StringTokenizer st2 = new StringTokenizer(in.nextLine(), " ");
        for (int i = 0; i < requestsSize; i++)
        {
            requests.addElement(Integer.parseInt(st2.nextToken()));
        }

        for(int i = 0; i < requestsSize; i++)
        {
            answer.addElement(new Vector<Integer>());
        }

        boolean flag = false;
        int m = requestsSize - 1;
        while (m >= 0)
        {
            flag = false;
            int l = 0, r = arrSize;
            while (l < r)
            {
                int k = (r + l)/2;

                if(arr.elementAt(k) < requests.elementAt(m))
                {
                    l = k + 1;
                }
                else  if (arr.elementAt(k) > requests.elementAt(m)){
                    r = k;
                }
                else  if (arr.elementAt(k) == requests.elementAt(m))
                {
                    flag = true;
                    answer.elementAt(m).addElement(1);
                    break;
                }
            }

            if (!flag)
            {
                answer.elementAt(m).addElement(0);
            }
            m--;
        }

        m = requestsSize - 1;
        while (m >= 0)
        {
            int l = 0, r = arrSize;
            while (l < r)
            {
                int k = (r + l)/2;

                if(arr.elementAt(k) < requests.elementAt(m))
                {
                    l = k + 1;
                }
                else {
                    r = k;
                }
            }

            answer.elementAt(m).addElement(l);
            m--;
        }

        m = requestsSize - 1;
        while (m >= 0)
        {
            int l = 0, r = arrSize;
            while (l < r)
            {
                int k = (r + l)/2;

                if(arr.elementAt(k) > requests.elementAt(m))
                {
                    r = k;
                }
                else {
                    l = k + 1;
                }
            }

            answer.elementAt(m).addElement(l);
            m--;
        }

        for (int i = 0; i < answer.size(); i++)
        {
            for (int j = 0; j < 3; j++)
            {
                System.out.print(answer.elementAt(i).elementAt(j) + " ");
            }
            System.out.println("");
        }
    }
}
*/