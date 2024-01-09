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
    }
}
