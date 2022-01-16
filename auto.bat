set defaultcommit=%date%
@echo git start:
git remote add upstream git@github.com:gilgameshchen/Leetcode-Daily.git
git remote -v
git fetch upstream
git checkout master
git merge upstream/master
git add .
@ for /f "delims=" %%A in ('git config user.name') do set "gitusername=%%A"
@set /p commit=input day:   
@ if defined commit (git commit -m "%gitusername% finish day %commit%") else (git commit -m "%defaultcommit%")
git push
@echo finish
@pause