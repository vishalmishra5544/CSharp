using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    class QueueUsingArray
    {
        //Your code here
        private int[] arr;
        private int front;
        private int rear;

        public QueueUsingArray()
        {
            arr = new int[100005];
            front = 0;
            rear = 0;
        }

        public void push(int x)
        {
            //Your code here
            if (rear == arr.Length - 1)
                return;
            arr[rear++] = x;
        }

        public int pop()
        {
            //Your code here
            if (rear == 0 || front == rear)
                return -1;
            int t = arr[front++];
            return t;
        }
    }
    internal class AllQueuePrograms
    {
        //Function to reverse first k elements of a queue.
        public Queue<int> modifyQueue(Queue<int> q, int k)
        {
            // add code here.
            Stack<int> st = new Stack<int>();
            for (int i = 0; i < k; i++)
            {
                st.Push(q.Dequeue());
            }
            int s = q.Count();
            for (int i = 0; i < k; i++)
            {
                q.Enqueue(st.Pop());
            }
            while (s-- > 0)
            {
                int curr = q.Dequeue();
                q.Enqueue(curr);
            }
            return q;
        }
    }
}
