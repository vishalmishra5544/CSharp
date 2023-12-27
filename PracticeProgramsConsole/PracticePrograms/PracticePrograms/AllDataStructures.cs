using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PracticePrograms
{
    public class NumberComparer : IComparer<int>
    {
        public int Compare(int x, int y)
        {
            return x.CompareTo(y);
        }
    }
    public class Employee
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public long Salary { get; set; }
        public Employee() { }
        public Employee(int id,string name,long salary)
        {
            Id = id;
            Name = name;
            Salary = salary;
        }
    }
    internal static class AllDataStructures
    {
        public static void ArrayPrograms() 
        {
            int[] array = new int[5] { 11,2,3,14,5};
            array[0] = 1;            
            Array.Sort(array);
            Array.Reverse(array);
            Array.Sort(array,new NumberComparer());
            int[] tempArray=new int[5];
            Array.Copy(array, tempArray, array.Length-3);
           // Array.Copy(array, tempArray, array.Length);
            foreach(int x in tempArray)
            {
                Console.Write(x+" ");
            }
        }
        public static void ListPrograms() 
        {
            List<int> list = new List<int>() { 11,2,3,14,5};//count=5,capacity=8
            Console.WriteLine(list.Count+" "+list.Capacity);
            list = new List<int>(7) { 11,3,2,14,5};//best
            list.Add(11);
            list.Remove(2);
            list.RemoveRange(3, 1);
            list.AddRange(new List<int> { 2,3,5});
            var temp = list.Aggregate((accumulator, x) => accumulator + x);
            temp = list.Aggregate(10,(acu,x)=>acu+x);
            temp = list.Aggregate(10,(acu,x)=>acu+x,x=>x*-1);
            var avg = list.Average(x => x);
            var isAllPositive = list.All(x=>x>0);
            var has4=list.Any(x => x == 4);
            has4 = list.Exists(x => x == 4);
            var sum = list.Sum(x=>x);
            var min = list.Min();
            min = list.Min(x=>x);
            var minBy = list.MinBy(x => x);
            //Filtering
            var where = list.Where(x=>x>3); //defered execution
            where = list.Where(x=>x>3).ToList(); //immediate
            var ofType = list.OfType<int>();
            //Projection
            var select = list.Select(x=>x.ToString());
            //Sorting
            list.Sort();
            list.Sort(new NumberComparer());
            var orderBy = list.OrderBy(x=>x);
            orderBy = list.OrderByDescending(x=>x);
            orderBy = list.OrderBy(x=>x).ThenBy(x=>x).ThenByDescending(x=>x);
            //Grouping
            var groupBy = list.GroupBy(x=>x);
            groupBy = list.ToLookup(x=>x); //immediate
            //Elements Selection
            var first = list.First();
            first = list.First(x=>x>4);
            var firstOrDefault = list.FirstOrDefault();
            firstOrDefault = list.FirstOrDefault(x=>x>4); //same for last,single
            
            foreach(var ele in list)
            {
                Console.Write(ele+" ");
            }
        }
        static void StackPrograms() { }
        static void QueuePrograms() { }
        static void HeapPrograms() { }
        static void HashSetPrograms() { }
        static void SortedSetPrograms() { }
        static void DictionaryPrograms() { }
        static void SortedDictionaryPrograms() { }
        static void BitsetPrograms() { }

    }
}
