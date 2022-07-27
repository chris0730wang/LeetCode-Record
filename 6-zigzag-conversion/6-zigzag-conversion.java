class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1)    return s;
        StringBuilder b = new StringBuilder();
        int interval = 2 * numRows - 2;
        int n = s.length();
        for(int i = 0; i < numRows; i++){
            int j = i;
            while(j < n){
                if(interval != 0)
                    b.append(s.charAt(j));
                j += interval;
                if(i != 0 && j < n)
                    b.append(s.charAt(j));
                j += 2 * i;
            }
            interval -= 2;
        }
        return b.toString();
    }
}