// See https://aka.ms/new-console-template for more information
var result = GetMinMax(new List<long>() { 3, 2 ,1, 56 ,1000, 167 },6);
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