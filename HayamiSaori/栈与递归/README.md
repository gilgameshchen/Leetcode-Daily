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

