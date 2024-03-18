public class Solution {
    public string SortSentence(string s) {
        string[] arrTmp = s.Split(' ');
        int len = arrTmp.Length;
        string[] arrString = new string[len];
        foreach(string ss in arrTmp){
            int index = Int32.Parse(ss.Substring(ss.Length - 1)) - 1;
            arrString[index] = ss.Substring(0, ss.Length - 1);
        }
        return String.Join(' ', arrString);
    }
}