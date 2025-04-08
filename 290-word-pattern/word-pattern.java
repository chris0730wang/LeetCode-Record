class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] words = s.split(" ");
        if(pattern.length() != words.length) return false;

        Map<Character, String> chartoword = new HashMap<>();
        Map<String, Character> wordtochar = new HashMap<>();

        for(int i = 0; i < pattern.length(); i++){
            char c = pattern.charAt(i);
            String word = words[i];

            if(!chartoword.containsKey(c)){
                chartoword.put(c, word);
            }

            if(!wordtochar.containsKey(word)){
                wordtochar.put(word, c);
            }

            if(!chartoword.get(c).equals(word) || !wordtochar.get(word).equals(c)) return false;
        }

        return true;
    }
}