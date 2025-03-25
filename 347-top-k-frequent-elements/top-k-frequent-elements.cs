public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        Dictionary<int, int> dicTemp = new Dictionary<int, int>();
        foreach(int num in nums){
            if(!dicTemp.ContainsKey(num)){
                dicTemp.Add(num, 0);
            }
            dicTemp[num]++;
        }
        var heap = new PriorityQueue<int, int>();
        foreach (var entry in dicTemp) {
            heap.Enqueue(entry.Key, entry.Value);
            if (heap.Count > k) {
                heap.Dequeue();
            }
        }
        
        var res = new int[k];
        for (int i = 0; i < k; i++) {
            res[i] = heap.Dequeue();
        }
        return res;
    }
}