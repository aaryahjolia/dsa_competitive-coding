# Your everyday Git rhythm

Git gives you a deliberate pause before saving a checkpoint. First edit files, then choose what belongs in the next commit, then save that selection. That middle step is called **staging**.

Think of a commit like a photo album: your folder is the whole room, the staging area is the set of photos you picked, and the commit is the album you save with a caption.

## The three places to keep straight

- **Working tree:** the files you can see and edit right now.
- **Staging area** (also called the index): the exact changes queued for the next commit.
- **Commit history:** the saved snapshots you have already recorded.

The basic loop is:

```text
edit files → inspect → stage selected changes → inspect again → commit
```

## Start tracking a project

```bash
git init
```

Run this inside the project folder to create a repository. Git creates a hidden `.git` directory where it stores history and repository settings. It does not automatically stage or commit all your files.

To get help for a command, try `git help status` or `git status --help`.

## Check before you save

```bash
git status
```

Status is your friendly dashboard. It reports the current branch, staged changes, unstaged changes, and untracked files. If you are unsure what Git thinks is happening, start here.

Make a small change, then inspect it:

```bash
git diff
```

By default, `git diff` shows edits in tracked files that are **not staged yet**. New, untracked files do not appear in this diff until you stage them.

## Stage only what you mean

```bash
git add notes.md
```

This puts the current contents of `notes.md` into the staging area. You can stage several named files, or stage everything in the current directory with:

```bash
git add -A
```

Then inspect what is queued for the next commit:

```bash
git diff --cached
```

This shows the staged changes compared with the last commit. The word `cached` is an older name for the staging area. If the staged diff looks right, commit it. If not, edit or restage before saving.

For a big file where only some changes belong together, use:

```bash
git add -p notes.md
```

Git will offer changes in small chunks (called hunks) and ask which ones to stage. This is great for keeping a commit focused.

## Make a useful checkpoint

```bash
git commit -m "Explain the settings page"
```

The message is a label for your checkpoint. A good one says what the commit changes, so future-you can scan the history without opening every commit.

A commit records the staged snapshot. If a file has both staged and unstaged edits, the commit includes only the staged version. That is why checking `git diff --cached` before committing is a useful habit.

## Read your project’s story

```bash
git log --oneline --graph --decorate --all
```

This draws a compact view of the commit graph and shows branch names around it. For details about one commit:

```bash
git show <commit>
```

To compare your current working tree with the last commit, including staged and unstaged edits:

```bash
git diff HEAD
```

Or compare two commits:

```bash
git diff <older-commit> <newer-commit>
```

`HEAD` usually means “the commit my current branch is on.” A commit can also be named by a branch, tag, or ID.

## A complete mini-session

```bash
git status
git diff
git add README.md
git diff --cached
git commit -m "Add project overview"
git status
```

The final status should tell you whether the working tree is clean. If it is, your changes are safely recorded in history.

### Oops, I staged the wrong file

To remove a file from the staging area while keeping your edits in the working tree:

```bash
git restore --staged notes.md
```

To discard unstaged edits in a file, `git restore notes.md` can bring it back to the staged version. **That discards those edits**, so inspect with `git diff` first and make sure you really want to throw them away.
