import java.util.Hashtable;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        Hashtable table = new Hashtable();
        String subStr = new String();
        int curLenMax = 0;
        Integer beginIndex;
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            /*  If this character is already in the table,
                See if this character is before the first character
                of current sub-string, if it is, just append this character
                if not, rebuild sub-string, after all this, update hash table*/
            if(table.containsKey(c)) {
                beginIndex = (Integer) table.get(c);
                char subBeginChar = subStr.charAt(0);
                Integer subBeginCharIndex = (Integer) table.get(subBeginChar);
                if(beginIndex.compareTo(subBeginCharIndex) < 0) {
                    subStr = subStr + c;
                } else {
                    subStr = s.substring(beginIndex.intValue() + 1, i + 1);                    
                }
                table.remove(c);
                table.put(c,new Integer(i));
            } 
            /*  If this character is not in the table, just append this character，
                and add this entry into the hash table */
            else {
                table.put(c,new Integer(i));
                subStr = subStr + c;
            }
            /*  Update current max length   */
            if(subStr.length() > curLenMax) {
                curLenMax = subStr.length();
            }
        }
        return curLenMax;
    }
}