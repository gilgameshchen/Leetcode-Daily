set defaultcommit=%date%
@echo git start:
git remote add upstream git@github.com:gilgameshchen/Leetcode-Daily.git
git remote -v
git fetch upstream
git checkout master
git merge upstream/master
git add .
@set /p commit=input day:
@ if defined commit (git commit -m "%commit%") else (git commit -m "%defaultcommit%")
git push
@echo finish
@pause