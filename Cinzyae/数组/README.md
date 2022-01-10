#Tips

<h4>一. 数组</h4>
<table>
    <thead>
        <tr>
            <th>题目分类</th>
            <th>题目编号</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>数组的遍历</td>
            <td><a href="https://leetcode-cn.com/problems/max-consecutive-ones/" title="最大连续 1 的个数"
                    target="blank">485</a>、<a href="https://leetcode-cn.com/problems/teemo-attacking/" title="提莫攻击"
                    target="blank">495</a>、<a href="https://leetcode-cn.com/problems/third-maximum-number/"
                    title="第三大的数" target="blank">414</a>、<a
                    href="https://leetcode-cn.com/problems/maximum-product-of-three-numbers/" title="三个数的最大乘积"
                    target="blank">628</a></td>
        </tr>
        <tr>
            <td>统计数组中的元素</td>
            <td><a href="https://leetcode-cn.com/problems/set-mismatch/" title="错误的集合" target="blank">645</a>、<a
                    href="https://leetcode-cn.com/problems/degree-of-an-array/" title="数组的度" target="blank">697</a>、<a
                    href="https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/"
                    title="找到所有数组中消失的数字" target="blank">448</a>、<a
                    href="https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/" title="数组中重复的数据"
                    target="blank">442</a>、<a href="https://leetcode-cn.com/problems/first-missing-positive/"
                    title="缺失的第一个正数" target="blank">41</a>、<a href="https://leetcode-cn.com/problems/h-index/"
                    title="H 指数" target="blank">274</a></td>
        </tr>
        <tr>
            <td>数组的改变、移动</td>
            <td><a href="https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/" title="最小操作次数使数组元素相等"
                    target="blank">453</a>、<a href="https://leetcode-cn.com/problems/non-decreasing-array/"
                    title="非递减数列" target="blank">665</a>、<a href="https://leetcode-cn.com/problems/move-zeroes/"
                    title="移动零" target="blank">283</a></td>
        </tr>
        <tr>
            <td>二维数组及滚动数组</td>
            <td><a href="https://leetcode-cn.com/problems/pascals-triangle/" title="杨辉三角" target="blank">118</a>、<a
                    href="https://leetcode-cn.com/problems/pascals-triangle-ii/" title="杨辉三角 II"
                    target="blank">119</a>、<a href="https://leetcode-cn.com/problems/image-smoother/" title="图片平滑器"
                    target="blank">661</a>、<a href="https://leetcode-cn.com/problems/range-addition-ii/" title="范围求和 II"
                    target="blank">598</a>、<a href="https://leetcode-cn.com/problems/battleships-in-a-board/"
                    title="甲板上的战舰" target="blank">419</a></td>
        </tr>
        <tr>
            <td>数组的旋转</td>
            <td><a href="https://leetcode-cn.com/problems/rotate-array/" title="轮转数组" target="blank">189</a>、<a
                    href="https://leetcode-cn.com/problems/rotate-function/" title="旋转函数" target="blank">396</a></td>
        </tr>
        <tr>
            <td>特定顺序遍历二维数组</td>
            <td><a href="https://leetcode-cn.com/problems/spiral-matrix/" title="螺旋矩阵" target="blank">54</a>、<a
                    href="https://leetcode-cn.com/problems/spiral-matrix-ii/" title="螺旋矩阵 II" target="blank">59</a>、<a
                    href="https://leetcode-cn.com/problems/diagonal-traverse/" title="对角线遍历" target="blank">498</a></td>
        </tr>
        <tr>
            <td>二维数组变换</td>
            <td><a href="https://leetcode-cn.com/problems/reshape-the-matrix/" title="重塑矩阵" target="blank">566</a>、<a
                    href="https://leetcode-cn.com/problems/rotate-image/" title="旋转图像" target="blank">48</a>、<a
                    href="https://leetcode-cn.com/problems/set-matrix-zeroes/" title="矩阵置零" target="blank">73</a>、<a
                    href="https://leetcode-cn.com/problems/game-of-life/" title="生命游戏" target="blank">289</a></td>
        </tr>
        <tr>
            <td>前缀和数组</td>
            <td><a href="https://leetcode-cn.com/problems/range-sum-query-immutable/" title="区域和检索 - 数组不可变"
                    target="blank">303</a>、<a href="https://leetcode-cn.com/problems/range-sum-query-2d-immutable/"
                    title="二维区域和检索 - 矩阵不可变" target="blank">304</a>、<a
                    href="https://leetcode-cn.com/problems/product-of-array-except-self/" title="除自身以外数组的乘积"
                    target="blank">238</a></td>
        </tr>
        <tr>
            <td>题解</td>
            <td><a href="https://leetcode-cn.com/circle/article/oalBEI/" target="_blank">数组篇</a></td>
        </tr>
    </tbody>
</table>

- 41. 缺失的第一个正数  
    使用提供的数组，对元素进行标记来得到统计的效果。    
    标记方法：
        - 加上最大值，后续使用取余抵消影响。
        - 负数
    ```python
    class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        Maxnum = 2 ** 32
        nums.append(0) # 鸵鸟
        lennums = len(nums)

        for i, num in enumerate(nums):
            if num <= 0:
                nums[i] = Maxnum
            if num % Maxnum > lennums:
                nums[i] = Maxnum

        for i, num in enumerate(nums):
            nums[num % Maxnum - 1] += Maxnum

        for i, num in enumerate(nums):
            if num <= Maxnum:
                return i + 1
        return lennums
    ```

- 665. 非递减数列   
    直接判断困难时，可将修改后的数组再进行判断。
    ```python
    class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        flag1 = 0
        flag2 = 0
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                flag2 += 1

                numL = nums[i]
                numR = nums[i + 1]

                nums[i] = numR
                for j in range(len(nums) - 1):
                    if nums[j] > nums[j + 1]:
                        flag1 += 1

                nums[i] = numL
                nums[i + 1] = numL
                for j in range(len(nums) - 1):
                    if nums[j] > nums[j + 1]:
                        flag1 += 1

                if flag1 > 1:
                    return False
                else:
                    flag1 = 0
                    nums[i] = numL
                    nums[i + 1] = numR

        return True if flag2 <= 1 else False
    ```

- 661. 图片平滑器   
    边界判断复杂时，可先构造出可能的值，再进行判断该值是否在区间内。
    ```python
    class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        n = len(img)
        m = len(img[0])
        img2 = [[0 for i in range(m)] for j in range(n)]
        for i in range(n):
            for j in range(m):
                acc = 0
                count = 0
                for p in range(i - 1, i + 2):
                    for q in range(j - 1, j + 2):
                        if 0 <= q < m and 0 <= p < n:
                            acc += img[p][q]
                            count += 1
                img2[i][j] = int(acc / count)
        return img2
    ```

- 189. 轮转数组     
    三次反转消耗空间O(1)    
    循环消耗时间O(n)    
    切片消耗空间O(1)   
    ```python
    class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        lennums = len(nums)

        # 1
        # for i in range(k):
        # nums[:] = nums[lennums - 1 :] + nums[: lennums - 1]
        
        # 2
        # k = k % lennums
        # nums[:] = nums[lennums - k :] + nums[: lennums - k]

        # 3
        k %= lennums
        nums[:] = nums[::-1]
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]
    ```

- 498. 对角线遍历   
    x,y 初值确定
    ```python
    class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        m = len(mat)
        n = len(mat[0])
        outlist = []
        direction = False
        maxmn = m + n - 1
        for sum in range(maxmn):
            if direction:
                for i in range(sum + 1):
                    if (i < m) and (sum - i < n):
                        outlist.append(mat[i][sum - i])
            else:
                for i in range(sum + 1):
                    if (sum - i < m) and (i < n):
                        outlist.append(mat[sum - i][i])
            direction = not direction
        return outlist
    ```

- 73. 矩阵置零  
    使用设定行列为标记行列时可以固定第一行第一列为标记行列，省去判断的麻烦
    ```python
    class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        flag = False
        x, y = -1, -1
        for i in range(m):
            if flag:
                break
            for j in range(n):
                if matrix[i][j] == 0:
                    flag = True
                    x, y = i, j
                    break
        if x < 0:
            return
        print(x, y)

        # for i in range(m):
        #     if matrix[i][y] != 0:
        #         matrix[i][y] = 1
        # for j in range(n):
        #     if matrix[x][j] != 0:
        #         matrix[x][j] = 1

        print(matrix)

        for i in range(x + 1, m):
            for j in range(n):
                if j == y:
                    continue
                elif matrix[i][j] == 0:
                    matrix[i][y] = 0
                    matrix[x][j] = 0

        print(matrix)

        for i in range(m):
            if i == x:
                continue
            if matrix[i][y] == 0:
                for k in range(n):
                    matrix[i][k] = 0
        for j in range(n):
            if j == y:
                continue
            if matrix[x][j] == 0:
                for k in range(m):
                    matrix[k][j] = 0

        for i in range(m):
            matrix[i][y] = 0
        for j in range(n):
            matrix[x][j] = 0
    ```

- 303. 区域和检索 - 数组不可变  
    一维：可存储从开始累计的和
    ```python
    class NumArray:
    def __init__(self, nums: List[int]):
        self.localnum = []
        self.localnum[:] = nums
        for i in range(1, len(nums)):
            self.localnum[i] += self.localnum[i - 1]
        print(self.localnum)

    def sumRange(self, left: int, right: int) -> int:
        if left == 0:
            return self.localnum[right]
        return self.localnum[right] - self.localnum[left - 1]
    ```

- 304. 二维区域和检索 - 矩阵不可变  
    二维：可储存一行之和，省去存储从开始累计的和
    ```python
    class NumMatrix:

        def __init__(self, matrix: List[List[int]]):
            m, n = len(matrix), (len(matrix[0]) if matrix else 0)
            self.sums = [[0] * (n + 1) for _ in range(m + 1)]
            _sums = self.sums

            for i in range(m):
                for j in range(n):
                    _sums[i + 1][j + 1] = _sums[i][j + 1] + _sums[i + 1][j] - _sums[i][j] + matrix[i][j]

        def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
            _sums = self.sums

            return _sums[row2 + 1][col2 + 1] - _sums[row1][col2 + 1] - _sums[row2 + 1][col1] + _sums[row1][col1]
    ```
    
- 238. 除自身以外数组的乘积     
    维护两个递乘序列，分别从数组头和尾开始累乘，将二者适当的乘积作为结果
    ```python
    class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res, p, q = [1], 1, 1
        for i in range(len(nums) - 1):
            p *= nums[i]
            res.append(p)
        print(res)
        for i in range(len(nums) - 1):
            q *= nums[len(nums) - 1 - i]
            res[len(nums) - 2 - i] *= q
        return res
    ```