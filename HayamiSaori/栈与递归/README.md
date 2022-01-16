#### [682. 棒球比赛](https://leetcode-cn.com/problems/baseball-game/)

利用栈的性质

```C++
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int temp;
        vector<int> record;
        for(auto op:ops)
        {
            if(op == "C")
                record.pop_back();
            else if(op == "D")
            {
                temp = record[record.size() - 1] * 2;
                record.push_back(temp);
            }
            else if(op == "+")
            {
                temp = record[record.size() - 1] + record[record.size() - 2];
                record.push_back(temp);
            }
            else
                record.push_back(stoi(op));
        }
        temp = 0;
        for(auto r:record)
            temp += r;
        return temp;
    }
};
```

#### [71. 简化路径](https://leetcode-cn.com/problems/simplify-path/)

利用`split()`函数以`'/'`切分，分情况判断，设置一个栈存储当前目录

```python
class Solution:
    def simplifyPath(self, path: str) -> str:
        tree = []
        result = "/"
        temp = path.split('/')
        for t in temp:
            if t == "" or t == ".":
                continue
            elif t == "..":
                if len(tree) > 0:
                    tree.pop()
            else:
                tree.append(t)
        if len(tree) == 0:
            return result
        for t in tree:
            result += t
            result += '/'
        return result[:-1]
```

#### [388. 文件的最长绝对路径(*)](https://leetcode-cn.com/problems/longest-absolute-file-path/)

![image.png](https://pic.leetcode-cn.com/1639450162-vlRTXt-image.png)

```C++
class Solution {
public:
    int lengthLongestPath(string input) {
        stack<string> stk;//存放当前目录
        string curr = "";//存放当前的文件名称或者文件夹名称；
        int res = 0;//最长文件目录长度计数
        int ans = 0;//当前最长文件文件目录长度；
        int dirlong = 0;//当前栈中目录的长度；
        int i = 0;
        bool isfile = false;
        int j = 0;//统计\t个数；
        while(i<input.length()){
            while(input[i]!='\n'&&i<input.size()){
                curr.push_back(input[i]);
                if(input[i] == '.')
                isfile = true;
                i++;
            }

            if(isfile){//如果是文件，则统计长度；
                int err = stk.size()-j;
                for(int k = 0;k<err;k++){//先到达文件所在的目录；
                    dirlong -= stk.top().length()+1;
                    stk.pop();
                    }
                ans = dirlong+curr.length();
                curr.clear();
                res = max(res,ans); 
                isfile = false;            
            }
            else{//如果时目录，就进行压栈或者出栈操作
                int err = stk.size()-j;
                for(int k = 0;k<err;k++){
                    dirlong -= stk.top().length()+1;
                    stk.pop();
                    }
                stk.push(curr);
                dirlong += stk.top().length()+1;
                curr.clear();  
            }
            if(i>=input.size())break;//如果到达长度，循环结束，给出结果
                        
            //若没有结束就继续判断接下来\t的个数；
            i++;//跳过此个'\n'
            j=0;
            while(input[i]=='\t'){
                j++;
                i++;
            }
        }
        return res;
    }
};
```

#### [150. 逆波兰表达式求值](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)

利用栈实现

```C++
class Solution {
public:
    int OP(int src, int dst, string t)
    {
        if(t == "+")
            return src + dst;
        if(t == "-")
            return src - dst;
        if(t == "*")
            return src * dst;
        if(t == "/")
            return src / dst;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int src, dst;
        for(auto t:tokens)
        {
            if(t=="+" || t=="-" || t=="*" || t=="/")
            {
                dst = nums.top();
                nums.pop();
                src = nums.top();
                nums.pop();
                nums.push(OP(src, dst, t));
            }
            else
            {
                nums.push(stoi(t));
            }
        }
        return nums.top();
    }
};
```

#### [227. 基本计算器 II](https://leetcode-cn.com/problems/basic-calculator-ii/)

设置数字栈，符号栈

```C++
class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
```

#### [224. 基本计算器(*)](https://leetcode-cn.com/problems/basic-calculator/)

```C++
class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                i++;
            } else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};
```

#### [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

设置一个栈来实现

```C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        char temp;
        for(auto i:s)
        {
            if(i=='(' || i=='[' || i=='{')
                left.push(i);
            else
            {
                if(left.empty())
                    return false;
                temp = left.top();
                if( (i==')'&&temp!='(') || (i==']'&&temp!='[') || i=='}'&&temp!='{')
                    return false;
                left.pop();
            }
        }
        return left.empty() ? true : false;
    }
};
```

#### [636. 函数的独占时间(*)](https://leetcode-cn.com/problems/exclusive-time-of-functions/)

```python
class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        res = [0] * n
        stack = []
        for s in logs:
            temp = s.split(':')
            if temp[1] == 'start':
                stack.append(temp)
            else:
                time = int(temp[2]) - int(stack.pop()[2]) + 1
                res[int(temp[0])] += time
                if stack:
                    res[int(stack[-1][0])] -= time   
        return res
```

#### [591. 标签验证器(*)](https://leetcode-cn.com/problems/tag-validator/)

正则表达式

```python
class Solution:
    def isValid(self, code: str) -> bool:
        code = re.sub(r'<!\[CDATA\[.*?\]\]>|t', '-', code)
        prev = None
        while code != prev:
            prev = code
            code = re.sub(r'<([A-Z]{1,9})>[^<]*</\1>', 't', code)
        return code == 't'
```

#### [32. 最长有效括号](https://leetcode-cn.com/problems/longest-valid-parentheses/)

设置一个标记数组，将所有可以匹配的括号位置标记为1，问题转化为最长连续1的长度

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        mark = [0] * len(s)
        stack = []
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i)
            else:
                if len(stack) != 0:
                    mark[i] = 1
                    mark[stack[-1]] = 1
                    stack.pop()
        count = 0
        result = 0
        for i in range(len(mark)):
            if mark[i] == 1:
                count += 1
            else:
                count = 0
                continue
            result = max(count, result)
        return result
```

#### [385. 迷你语法分析器(*)](https://leetcode-cn.com/problems/mini-parser/)

```C++
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.empty()) return NestedInteger();
        if(s[0]!='[')  return NestedInteger(stoi(s));
        if(s.size()<=2) return NestedInteger();
        NestedInteger res;
        int start=1,cnt=0;
        for (int i=1;i<s.size();i++){
            if(cnt==0&&(s[i]==','||i==s.size()-1)){
                res.add(deserialize(s.substr(start,i-start)));
                start=i+1;
            } 
            else if(s[i]=='[') cnt++;
            else if(s[i]==']') cnt--;
        }
        return res;
    }
};
```

#### [341. 扁平化嵌套列表迭代器(*)](https://leetcode-cn.com/problems/flatten-nested-list-iterator/)

```java
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return empty list if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private List<Integer> list = new ArrayList<>();
    private int index;

    private void add(List<NestedInteger> nestedList)
    {
        for(NestedInteger nestedInteger:nestedList)
        {
            if(nestedInteger.isInteger())
            {
                list.add(nestedInteger.getInteger());
            }
            else
            {
                add(nestedInteger.getList());
            }
        }
    }
    public NestedIterator(List<NestedInteger> nestedList) {
        add(nestedList);
    }

    @Override
    public Integer next() {
        return list.get(index++);
    }

    @Override
    public boolean hasNext() {
        return index < list.size();
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
```

#### [394. 字符串解码(*)](https://leetcode-cn.com/problems/decode-string/)

递归实现

```C++
class Solution {
public:
    string src; 
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS
            return "";
        }

        char cur = src[ptr]; int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            // String -> Digits [ String ] String
            // 解析 Digits
            repTime = getDigits(); 
            // 过滤左括号
            ++ptr;
            // 解析 String
            string str = getString(); 
            // 过滤右括号
            ++ptr;
            // 构造字符串
            while (repTime--) ret += str; 
        } else if (isalpha(cur)) {
            // String -> Char String
            // 解析 Char
            ret = string(1, src[ptr++]);
        }
        
        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};
```


