// See https://aka.ms/new-console-template for more information
using PracticePrograms;
using System.Text;


//var result = GetMinMax(new List<long>() { 3, 2 ,1, 56 ,1000, 167 },6);
//var result = BirthdayCakeCandles(new List<int> { 3, 2, 1, 3 });

//AllDataStructures.ArrayPrograms();
//AllDataStructures.ListPrograms();
//Console.WriteLine(IsPowerofTwo(61));
//Console.WriteLine(DoUnion(new int[5]{1,2,4,3,0 },5,new int[4] {6,7,3,1},4));
//Console.WriteLine(ReverseWord("abcde"));
//ReverseInGroups(new List<long> { 1,2,3,4,5}, 5, 3);
//Console.WriteLine(IsPossible(4,new int[4] { 18 ,1, 16, 17 }));
Rotate(new int[5] { 1, 2, 3, 4, 5 }, 1);
//OOPS.OOPSPrograms();
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
static void ReverseInGroups(List<long> arr, int n, int k)
{    
    for(int i=0;i<n;i+=k)
    {
        Reverse(arr,i,k);
    }
}
static void Reverse(List<long> arr, int start,int k)
{
    int end = (start + k-1) > arr.Count-1?arr.Count-1:start+k-1;
    while (start < end)
    {
        arr[start] = arr[start] ^ arr[end];
        arr[end] = arr[start] ^ arr[end];
        arr[start] = arr[start] ^ arr[end];
        start++;
        end--;
    }
}
static string IsSubset(int[] a1, int[] a2, int n, int m)
{
    //Your code here
    if (m > n)
    {
        return "No";
    }
    Dictionary<int, int> d = new Dictionary<int, int>(n);
    foreach (var ele in a1)
    {
        if (d.ContainsKey(ele))
            d[ele] += 1;
        else
            d.Add(ele, 1);
    }

    foreach (var ele in a2)
    {
        if (!d.ContainsKey(ele))
            return "No";
        d[ele]--;
        if (d[ele] == 0)
            d.Remove(ele);
    }
    return "Yes";
}

static bool IsPossible(int N, int[] coins)
{
    // code here
    //return Recursion(coins,0,0,N);
    int[,] dp = new int[N+1, 2025];
    for (int i = 0; i < N+1; i++)
    {
        for (int j = 0; j < 2025; j++)
        {
            dp[i, j] = -1;
        }
    }
    int possible = Memoization(coins, 0, 0, N, dp);

    if (possible == 1)
        return true;
    else
        return false;
}

static bool Recursion(int[] coins, int currInd, int sum, int N)
{
    if (sum != 0 && (sum == 2024 || sum % 20 == 0 || sum % 24 == 0))
    {
        return true;
    }
    if (currInd == N)
    {
        return false;
    }
    bool take = Recursion(coins, currInd + 1, sum + coins[currInd], N);
    if (take)
        return take;
    bool noTake = Recursion(coins, currInd, sum, N);
    if (noTake)
        return noTake;
    return false;
}

static int Memoization(int[] coins, int currInd, int sum, int N, int[,] dp)
{
    if (sum > 0 && (sum == 2024 || sum % 20 == 0 || sum % 24 == 0))
    {
        return dp[currInd, sum] = 1;
    }
    if (currInd >= N)
    {
        return dp[currInd, sum] = 0;
    }
    if (dp[currInd, sum] != -1)
        return dp[currInd, sum];
    int noTake = Memoization(coins, currInd+1, sum, N, dp);
    if (noTake == 1)
        return dp[currInd, sum] = 1;
    int take = Memoization(coins, currInd + 1, sum + coins[currInd], N, dp);
    if (take == 1)
        return dp[currInd, sum] = 1;    
    return dp[currInd, sum] = 0;
}
static void Rotate(int[] arr, int k)
{
    ReverseArr(arr, 0, k - 1);
    ReverseArr(arr, k, arr.Length - 1);
    ReverseArr(arr, 0, arr.Length - 1);
}
static void ReverseArr(int[] arr, int start, int end)
{
    while (start < end)
    {
        arr[start] = arr[start] ^ arr[end];
        arr[end] = arr[start] ^ arr[end];
        arr[start] = arr[start] ^ arr[end];
        start++;
        end--;
    }
}