## forward

刷题总结，刷题顺序参考自[从0开始刷Leetcode](https://leetcode-cn.com/circle/article/48kq9d)

刷题顺序[GithubPage版](https://cinzyae.github.io/Leetcode-Daily/)

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

## PR注意事项

如果不预先将本地仓库的commit信息合并，那么在PR的时候就会提交很多个commit，虽然PR管理员能帮忙Squash，但还是要了解一下怎么本地合并多个commit。

先来看一下产生多个commit然后提交的情况：

![例子](http://tva1.sinaimg.cn/large/0085EwgIgy1gy20y3jbe7j30w10ii44u.jpg)

产生的原因：

字母代表一条commit。

主仓库：[A, B,C]

而你的仓库[A,B,C,D,E,F..]。因此PR的时候就会导致C后的commit一起提交，需要做的事情就是将C后的commit合并成一条commit信息再提交。

假设现在有一条commit如下(git log查看commit信息)

![commit1](http://tva1.sinaimg.cn/large/0085EwgIgy1gy213yg9d1j30k9038jth.jpg)

此时你又新增了一条commit并且又提交到了你的仓库，再git log查看可见如下

![commit2](http://tva1.sinaimg.cn/large/0085EwgIgy1gy215yhc9pj30jt05c0w0.jpg)

此时我们如果提交pr而没进行git rebase，就会出现pr界面有这两条commit，但逻辑上他们应该是一致的，因此需要进行rebase。

---

1.

```bash
git log
```

找到你要合并的commit条目，比如需要合并cur和pre，那就复制pre的唯一ID。

如果有很多条，那就是最前的一条：比如cur，pre1，pre2....，pren，那就复制pren后的唯一ID

2.

```bash
git rebase -i ID
```

![image.png](http://tva1.sinaimg.cn/large/0085EwgIgy1gy21gsni3tj30s70fx7e7.jpg)

![image.png](http://tva1.sinaimg.cn/large/0085EwgIgy1gy21hq8eqmj30s70fxdpe.jpg)

保存后出现以下信息让你重写commit信息，也就是多变一后，这一个commit你要写什么信息。

![image.png](http://tva1.sinaimg.cn/large/0085EwgIgy1gy21rbb1fqj30s70fxagj.jpg)

完成这些后(我把commit信息都删掉，只留了一行”append readme“)，你再git log就会发现commit信息多变一了！

![image.png](http://tva1.sinaimg.cn/large/0085EwgIgy1gy21kkcb9lj30m405ljuq.jpg)

最后提交即可，如果这时候用git push -u origin master是一定会冲突的，无法提交上去，这时候我们就得force提交，将那两个commit覆盖，变成现在这个commit。

```bash
git push --force origin master
```



![image.png](http://tva1.sinaimg.cn/large/0085EwgIgy1gy21n51w6rj30kv04tq6d.jpg)

查看web端仓库，发现已经合并成一个了，可以安心pr了。

![image.png](http://tva1.sinaimg.cn/large/0085EwgIgy1gy21ogs7rej30xy06amzk.jpg)

