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
    public interface IPerson
    {
        string Name { get; set; }
        string Gender { get; set; }
    }
    public class Employee : IPerson
    {
        public int Id { get; set; }
        public long Salary { get; set; }
        public DayOfWeek ShiftDay { get; set; }
        public string Name { get ; set ; }
       
        // public string Gender { get => throw new NotImplementedException(); set => throw new NotImplementedException(); }  via show potential fixes
        public string Gender { get; set; } 

        public Employee() { }
        public Employee(int id,string name,long salary)
        {
            Id = id;
            Name = name;
            Salary = salary;
        }
    }
    public class Manager : Employee
    {
        public Manager()
        {
                
        }
        public Manager(string level="B")
        {
            Level = level;
        }
        public int ExperienceInYears { get; set; }
        public string Level { get; set; }
        int DoRandomWork()
        {
            Random random = new Random();
            return random.Next(1, 100);
        }
    }
    
    //[Flags]
    public enum DayOfWeek : short
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    }
    internal static class OOPS
    {
        public static void OOPSPrograms()
        {
            Employee emp = new Employee();
            Manager manager = new Manager();
            Manager manager1 = new Manager("A");
            //Manager manager2 = emp; // Not valid
            //Manager manager2 = (Manager)emp; //Gives Error
            emp = manager;
            Console.WriteLine(true.ToString());
            Console.WriteLine(DayOfWeek.Friday);
            IPerson person = new Employee();
            IPerson person2 = new Manager();
            person = new Manager();
            person = person2;
            manager = (Manager)person;
            emp = (Employee)person;
        }
    }
    internal static class AllDataStructures
    {
        public static void ArrayPrograms() 
        {
            int[] array = new int[5] { 11,2,3,14,5};
            /*
            int[] array2 = new int[7]{ 1,2,3,4 };// not valid
            int[] array3 = new int[5];
            array3 = {1} //not valid
            */
            array[0] = 1;            
            Array.Sort(array);
            Array.Reverse(array);
            Array.Sort(array,new NumberComparer());
            int[] tempArray=new int[5];
            Array.Copy(array, tempArray, array.Length-3);
            // Array.Copy(array, tempArray, array.Length);
            string s = "1 2 3 4 5 6";
            var stringArray = s.Split(' ');
            int[] arr = new int[stringArray.Length];
            arr = Array.ConvertAll(stringArray, int.Parse);
            foreach(int x in arr)
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
        static void LinkedListPrograms()
        {

        }
        static void StackPrograms() { }
        static void QueuePrograms() { }
        static void HeapPrograms() { }
        static void HashSetPrograms() { }
        static void SortedSetPrograms() { }
        static void DictionaryPrograms() 
        {
           Dictionary<int,int> d = new Dictionary<int,int>(5);
        }
        static void SortedDictionaryPrograms() { }
        static void BitsetPrograms() { }

    }
}
