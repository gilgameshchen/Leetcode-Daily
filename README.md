## forward

刷题总结，刷题顺序参考自[从0开始刷Leetcode](https://leetcode-cn.com/circle/article/48kq9d)

刷题顺序[本地精简版](./leetcode.html)

## 个人经验

Leetcode有模拟面试按钮，可以设定时间，模拟面试场景。~以求头脑清醒~

Easy ：5min

medium：10min

hard：15min

## How to Contribute

### 首次Clone

1.fork此[repo](https://github.com/gilgameshchen/Leetcode-Daily)

2.进入到自己fork后的repo

![personal repo](http://tva1.sinaimg.cn/large/0085EwgIgy1gxu0amyb66j30ex02i750.jpg)

3.clone自己的repo到本地

>git clone xxx.github.com

### 后续pull request

1.在你修改代码以前，请一定要保证自己的repo和[主repo](https://github.com/gilgameshchen/Leetcode-Daily)同步

![fetch and merge](http://tva1.sinaimg.cn/large/0085EwgIgy1gxu0czx3dsj30d308dq4m.jpg)

如图，这样表示已经和主项目同步。如果没有，点击`fetch and merge`

2.在你本地的shell中，执行`git pull`.这个步骤是为了将本地文件和你的仓库同步

可以这么理解：主项目--->你的仓库---->本地。

第一个箭头：fetch and merge

第二个箭头：git pull

3.至此，你才可以进行修改本地文件，并将修改提交到你的仓库

```bash
git add .
git commit -m "???"
git push -u origin master
```

4.此时，情况是你的仓库，本地文件的更改领先于主仓库，那么如何将你的修改合并到主项目？==》pull request

![pull requset](http://tva1.sinaimg.cn/large/0085EwgIgy1gxu0ieyavmj30cj06dmyd.jpg)

点击open pull request，填写你的pr信息，等待鹏神同意合并即可。

