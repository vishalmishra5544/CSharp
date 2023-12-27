// See https://aka.ms/new-console-template for more information
using PracticePrograms;


//var result = GetMinMax(new List<long>() { 3, 2 ,1, 56 ,1000, 167 },6);
//var result = BirthdayCakeCandles(new List<int> { 3, 2, 1, 3 });

//AllDataStructures.ArrayPrograms();
AllDataStructures.ListPrograms();
Console.ReadKey();
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