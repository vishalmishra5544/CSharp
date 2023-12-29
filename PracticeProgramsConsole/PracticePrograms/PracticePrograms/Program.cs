// See https://aka.ms/new-console-template for more information
using PracticePrograms;
using System.Text;


//var result = GetMinMax(new List<long>() { 3, 2 ,1, 56 ,1000, 167 },6);
//var result = BirthdayCakeCandles(new List<int> { 3, 2, 1, 3 });

//AllDataStructures.ArrayPrograms();
//AllDataStructures.ListPrograms();
//Console.WriteLine(IsPowerofTwo(61));
//Console.WriteLine(DoUnion(new int[5]{1,2,4,3,0 },5,new int[4] {6,7,3,1},4));
Console.WriteLine(ReverseWord("abcde"));
Console.ReadKey();

static bool IsPowerofTwo(long n)
{
    // Your code here
    /* int noOfSetBits = 0;
     long temp = n;
     int length =(int)Math.Floor(Math.Log2(n) + 1);
     while (noOfSetBits < 2 && length > 0)
     {
         if ((temp & 1) == 1)
         {
             noOfSetBits++;
         }
         temp = temp >> 1;
         length--;
     }
     return noOfSetBits == 1;*/
    return (n > 0) && ((n & (n - 1))==0);
}
static int DoUnion(int[] a, int n, int[] b, int m)
{
    HashSet<int> h = new HashSet<int>(n + m);
    foreach (int ele in a)
        h.Add(ele);
    foreach (int ele in b)
        h.Add(ele);
    return h.Count;

}
static List<long> GetMinMax(List<long> a, int n)
{
    //return new List<long>(){a.Min(),a.Max()};
    long min = long.MaxValue, max = long.MinValue;
    foreach (var ele in a)
    {
        if (ele < min)
            min = ele;
        if (ele > max)
            max = ele;
    }
    return new List<long>() { min, max };
}

static int BirthdayCakeCandles(List<int> candles)
{
    SortedDictionary<int, int> dict = new SortedDictionary<int, int>();
    foreach (int ele in candles)
    {
        if (dict.ContainsKey(ele))
        {
            dict[ele] += 1;
        }
        else
        {
            dict.Add(ele, 1);
        }
    }
    return dict.Last().Value;
}

static string ReverseWord(string str)
{
    /*var charList = str.ToCharArray();
    int l = 0, r = str.Length - 1;
    while(l<r)
    {
        charList[l] = (char)((int) charList[l] ^ (int) charList[r]);
        charList[r] = (char)((int) charList[l] ^ (int) charList[r]);
        charList[l] = (char)((int) charList[l] ^ (int) charList[r]);
        l++;r--;
    }
    return new string(charList);*/
    StringBuilder rev = new StringBuilder();
    for (int i = str.Length - 1; i >= 0; i--)
        rev.Append(str[i]);
    return rev.ToString();
}
static bool Check(List<long> A, List<long> B, int N)
{
    //Your code here    
    Dictionary<long, long> h = new Dictionary<long, long>();
    foreach (long ele in A)
    {
        if (h.ContainsKey(ele))
        {
            h[ele] += 1;
        }
        else
            h.Add(ele, 1);
    }
    foreach (long ele in B)
    {
        if (!h.ContainsKey(ele))
            return false;
        h[ele] -= 1;
        if (h[ele] == 0)
            h.Remove(ele);
    }
    return true;
}