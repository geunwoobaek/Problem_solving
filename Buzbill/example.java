class Solution {
    public boolean isPelinDrom(String str) {
        for (int s = 0, e = str.length() - 1; s <= e; s++, e--) {
            if (str.charAt(s) != (str.charAt(e)))
                return false;
        }
        return true;
    }

    public int solution2(int s, String str) {
        for (int e = str.length(); i > s; i--) {
            if (isPelinDrom(str.substring(s, e)) == true)
                return e - s + 1;
        }
    }

    public int solution(String s) {
        int answer = 0;
        for (int i = 0; i < s.length(); i++) {
            int cur=solution2(i,s);
            answer=max(cur,answer);
        }
        return answer;
    }
}