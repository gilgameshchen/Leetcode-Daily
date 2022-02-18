## [1926. 迷宫中离入口最近的出口](https://leetcode-cn.com/problems/nearest-exit-from-entrance-in-maze/)

```java
class Solution {
    class Node {
        int x;
        int y;
        int step;

        public Node(int x, int y, int step) {
            this.x = x;
            this.y = y;
            this.step = step;
        }
    }

    public int nearestExit(char[][] maze, int[] entrance) {
        return bfs(maze, entrance[0], entrance[1]);
    }

    public int bfs(char[][] maze, int i, int j) {
        Deque<Node> q = new LinkedList<>();
        q.addLast(new Node(i, j, 0));
        maze[i][j] = '+';   

        int m = maze.length;
        int n = maze[0].length;

        int[] dx = new int[]{0, 0, -1, 1};
        int[] dy = new int[]{1, -1, 0, 0};
        while (!q.isEmpty()) {
            Node cur = q.pollFirst();

            if (!(cur.x == i && cur.y ==j) && (cur.x == 0 || cur.x == m - 1 || cur.y == 0 || cur.y == n - 1)) return cur.step;

            for (int k = 0; k < 4; k++) {
                int row = cur.x + dx[k];
                int col = cur.y + dy[k];
                if (row >= 0 && row < m && col >= 0 && col < n && maze[row][col] == '.') {
                    q.add(new Node(row, col, cur.step + 1));
                    maze[row][col] = '+';
                }
            }
        }
        return -1;
    }
}
```

bfs的标准模板就是用一个queue，先存对头，然后再while(!q.isEmpty()) {

​	// 1.pollLast,然后check。

 // 2.将四个方向的节点入队，同时要记录其已走过（maze[row] [col] = '+'）

}