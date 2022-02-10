#### [排列数字](https://www.acwing.com/problem/content/844/)

用一个visited数组来表示数字i是否已经访问。dfs进入前设置为true，dfs后设置为false，从而达到回溯的目的。

```java
import java.util.*;

class Main {
    static int[] path;
    static boolean[] visited;
    static int n;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        path = new int[n];
        visited = new boolean[n + 1];
        
        dfs(0);
    }
    
    public static void dfs(int u) {
        if (u == n) {
            for (int i = 0; i < n; i++) System.out.print(path[i] + " ");
            System.out.println();
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                path[u] = i;
                visited[i] = true;
                dfs(u + 1);
                visited[i] = false;
            }
        }
    } 
}
```

#### [17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

```java
class Solution {
    List<String> res;
    int n;
    Map<Character, String> map;
    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0 || digits == null) return new ArrayList<String>();
        map = new HashMap<>();
        map.put('2', "abc");
        map.put('3', "def");
        map.put('4', "ghi");
        map.put('5', "jkl");
        map.put('6', "mno");
        map.put('7', "pqrs");
        map.put('8', "tuv");
        map.put('9', "wxyz");

        res = new ArrayList<>();
        n = digits.length();
        StringBuffer sb = new StringBuffer();
        dfs(digits, 0, sb);
        return res;
    }

    public void dfs(String digits, int cur, StringBuffer sb) {
        if (cur == n) {
            res.add(sb.toString());
            return;
        }

        String letters = map.get(digits.charAt(cur));
        for (int i = 0; i < letters.length(); i++) {
            sb.append(letters.charAt(i));
            dfs(digits, cur + 1, sb);
            sb.deleteCharAt(cur);
        }
    } 
}
```

#### [22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)

```java
class Solution {
    List<String> res;
    public List<String> generateParenthesis(int n) {
        res = new ArrayList<>();
        dfs(n, n, new StringBuffer());
        return res;
    }

    public void dfs(int l, int r, StringBuffer sb) {
        if (l == 0 && r == 0) {
            res.add(sb.toString());
            return;
        }
        if (l > r) return;
        if (l > 0) {
            dfs(l - 1, r, sb.append("("));
            sb.deleteCharAt(sb.length() - 1);
        }
        if (r > 0) {
            dfs(l, r - 1, sb.append(")"));
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
```

## [51. N 皇后](https://leetcode-cn.com/problems/n-queens/)

```java
class Solution {
    String[][] g;
    boolean[] col, dg, udg;
    int num;
    List<List<String>> res;
    public List<List<String>> solveNQueens(int n) {
        g = new String[n][n];
        res = new ArrayList<>();
        num = n;
        col = new boolean[20];
        dg = new boolean[20];
        udg = new boolean[20];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) g[i][j] = ".";
        }
        dfs(0);
        return res;
    }

    public void dfs(int u) {
        if (u == num) {
            List<String> t = new ArrayList<>();
            for (int i = 0; i < num; i++) {
                StringBuffer sb = new StringBuffer();
                for (int j = 0; j < num; j++) {
                    sb.append(g[i][j]);
                }
                t.add(sb.toString());
            }
            res.add(t);
            return;
        }

        for (int i = 0; i < num; i++) {
            if (!col[i] &&
             !dg[u + i] &&
              !udg[num - u + i]) {
                g[u][i] = "Q";
                col[i] = true;
                dg[u + i] = true;
                udg[num - u + i] =  true;
                dfs(u + 1);
                col[i] = false;
                dg[u + i] = false;
                udg[num - u + i] = false;
                g[u][i] = ".";
            }
        }
    }
}
```

