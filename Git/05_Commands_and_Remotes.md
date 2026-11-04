# Git commands and remotes

Your local repository is your own workshop. A **remote** is another copy of the repository, often hosted on GitHub, GitLab, or a team server. Remotes help you share commits and bring other people’s commits into your workshop.

## Clone a project

```bash
git clone <url>
```

This downloads a repository, its history, and the working files into a new folder. To choose the folder name:

```bash
git clone <url> my-project
```

The clone usually configures the source repository as a remote named `origin`.

## See or add a remote

```bash
git remote -v
```

This shows the remote names and their URLs. To connect an existing local repository to a remote:

```bash
git remote add origin <url>
```

`origin` is a conventional nickname, not a magic word. You can choose another name, but most examples use `origin` for the main shared repository.

## Fetch, merge, pull

Fetch is the “go see what’s new” step:

```bash
git fetch origin
```

Git downloads new commits and updates remote-tracking names such as `origin/main`. It does **not** switch your current branch or change your files. You can inspect what arrived and then decide what to do.

To bring `origin/main` into your current branch with a merge:

```bash
git merge origin/main
```

`git pull` is a shortcut that fetches and then integrates a remote branch into the current branch. Integration is usually a merge, but it can be configured to rebase. If you are learning, use `git fetch` first when you want to inspect incoming work before combining it.

## Push your commits

```bash
git push -u origin main
```

This sends your local `main` commits to `origin` and sets the upstream relationship (`-u`) so Git knows which remote branch this local branch follows. After that, `git push` and `git pull` can often infer the destination/source.

If you are working on a feature branch, push that branch by name:

```bash
git push -u origin add-search
```

The upstream is a convenience relationship. It does not mean the remote branch is your current local branch; it tells Git which remote branch to compare or synchronize with.

## Handy command shelf

| What you want | Command | What it does |
| --- | --- | --- |
| See current changes | `git status` | Summarizes staged, unstaged, and untracked files. |
| View unstaged edits | `git diff` | Compares working files with the staging area. |
| View staged edits | `git diff --cached` | Shows what the next commit would include. |
| Stage part of a file | `git add -p file.txt` | Lets you choose changes in chunks. |
| Browse history | `git log --oneline --graph --decorate --all` | Draws a compact commit graph with branch names. |
| Inspect a commit | `git show <commit>` | Shows commit details and its changes. |
| See who last changed each line | `git blame file.txt` | Displays the latest commit attribution for lines. |
| List branches | `git branch -vv` | Shows local branches and upstream details. |
| Ask for command help | `git help <command>` | Opens the manual for that command. |

`git blame` is a clue-finder, not a blame-finder: use it to learn when a line changed and which commit to inspect with `git show`.

## Pause unfinished work with stash

If you need to switch tasks before your current edits are ready for a commit, stash can temporarily put those changes aside:

```bash
git stash push -m "unfinished search page"
```

Later, bring the most recent stash back and remove it from the stash list:

```bash
git stash pop
```

Or apply it while keeping the saved stash around:

```bash
git stash apply
```

Stash is a temporary shelf, not a substitute for commits. Check `git status` after applying or popping; changes can conflict with the work you did in the meantime.

## A quick collaboration routine

```bash
git status
git fetch origin
git log --oneline --graph --decorate --all
git switch -c my-feature
# edit, then stage and commit your work
git add -A
git diff --cached
git commit -m "Add my feature"
git push -u origin my-feature
```

The final push publishes your branch so teammates can review it or merge it. Before staging with `git add -A`, run `git status` and make sure generated files, secrets, or unrelated edits are not being swept into the commit.

Official references: [`git fetch`](https://git-scm.com/docs/git-fetch), [`git pull`](https://git-scm.com/docs/git-pull), and [`git push`](https://git-scm.com/docs/git-push).
