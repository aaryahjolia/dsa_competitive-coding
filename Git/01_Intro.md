# Introduction to Git

## What is version control?

Version control systems are tools used to keep track of changes to source code or other collections of files and folders. They help track the history of changes to a set of documents and are especially useful for collaboration and working with a group on a software project.

Git stores a snapshot: the state of a folder at a particular time. It also stores metadata, such as who authored the changes and when they were made.

Version control is useful for individuals, too. You can work on features while fixing bugs by using branches.

Git is also powerful when tracking down regressions. For example, a unit test may pass at first but fail after a few merges. If you do not know which change caused the regression, Git can binary-search through the changes and point to the one that introduced it.

## How Git represents a project

Let’s say a project consists of the following:

```text
(Root) - root directory
|
|- foo <- called "tree" or folder
|   - bar.txt <- called "blob" or file
|- info.txt <- also a "blob"
```

Directories are called trees. A tree can contain other trees or blobs, but blobs cannot contain trees. The root is the top-level directory being tracked.

One way to remember the state of a project is to take a snapshot of the root directory, then take more snapshots at intervals, making a linear chain. Git does not use only a linear chain; it uses a directed acyclic graph (DAG) to model history. Snapshots can be stored like this:

```text
O <- O <- O (feature) <- O
      |                  |
      | <- O (bugfix) <- |
```

Each `O` represents a snapshot that points to its parent. In a linear history, we can work on only one thing at a time on the root directory. With Git’s DAG, two branches can have commits at the same time: one for a bug fix and one for a feature. When we merge them, the final `O` points to both `O`s, which means it has two parent snapshots.

Pseudocode for this model:

```text
type blob = array<byte>
type tree = map<string, tree|blob>  # directory names map to other directories or files
type commit = struct {              # Git calls snapshots "commits"
    parentCommits: array<commit>    # stored as hashes
    author: string,
    message: string,
    snapshot: tree (root tree)
}
```

## Git objects and references

On disk, Git stores data as objects. Pseudocode:

```text
type object = blob|tree|commit
objects = map<string, object> (string is a SHA-1 hash, object is the object being stored)

def store(O):
    id = SHA1(O)
    object[id] = O

def load(id):
    return object[id]
```

SHA-1 hashes are hexadecimal strings that are 40 characters long (160-bit hashes). For example: `4af32cb...7f`.

Every commit is identified by this hash, but it is not human-readable. To solve this, Git maintains references: mappings from hashes to human-readable names.

```text
references = map<string, string>
Example: ("Fixed encoding Bug", "4af32cb...7f")
```

We can use a reference string instead of a hash to identify a snapshot in history. References point to particular commits in the DAG.

Given Git’s design for history, the object graph is immutable: we can add new objects, but we cannot manipulate existing objects. References are mutable, though. We can change a reference to point to another commit, but we cannot change a hash string without changing the object it identifies.

At a high level, Git commands manipulate objects or references.

## Commands

1. **`git init`**

   Initializes a Git repository in the root directory.

2. **`git help <command>`**

   Shows information about a command. For example: `git help init`.

3. **`git status`**

   Shows the status of the current Git repository, including which files are tracked and which are untracked.

   Let’s say we create a file and want to make a snapshot of its current contents. There is no direct command to do this because Git gives us the flexibility to choose which changes to include in the next snapshot or commit. The staging area tells Git what to include in that commit. At this point, `git status` will say there are no commits and that there is an untracked file.

4. **`git add file.txt`** (or **`git add -A`** for all files)

   Adds a file or folder to the staging area, where it is ready to be committed (included in a snapshot). `git status` will now show the file as ready to be committed.

5. **`git commit`**

   Creates a snapshot or commit. Git will ask for a message so you can later identify what changes were made or associate the commit hash with the change.

   Now we have a single node in our DAG representing this commit.

6. **`git log`** (with `--all --graph --decorate` to view the history as a graph; add `--oneline` for a shorter version)

   Helps visualize the history or commit graph from the beginning.

   `HEAD` is a special pointer to the current directory. `master` is the main branch, which identifies the latest point in the DAG.

7. **`git checkout <hash or 'master' or filename>`**

   If you provide a hash, Git changes `HEAD` to that commit, and you will see the directory as it was at that point. `HEAD` points to that commit, while `master` stays at its latest commit. To switch `HEAD` back to `master`, use `git checkout master`.

   Uncommitted changes may prevent you from checking out another commit. You can commit them or pass the `-f` argument to force the checkout, which will overwrite the content and lose your unsaved changes.

8. **`git diff hello.txt`**

   Compares the file in the current directory with the version at `HEAD` and shows what changed. You can also compare different snapshots or commits with `git diff 4f2a4g HEAD hello.txt`.

9. **`git branch`**

   Shows all branches in the Git repository. Use `git branch xyz` to create a branch. Initially, `HEAD` points to `master`, and `xyz` points to the same commit as `master`. `git checkout xyz` switches `HEAD` to `xyz`. The shorter command to create and switch to a branch is `git checkout -b xyz`. Use the `-vv` argument to see all branches.

10. **`git merge xyz`**

    If you have two branches, such as `xyz` and `abc`, and want to merge `xyz` into `master`, check out `master` and run `git merge xyz`. Since `xyz` is ahead of `master`, `master` will move to the `xyz` commit, and `HEAD` will point to `master`, which is now at the same commit as `xyz`.

    Use `git merge --abort` to abort the merge and restore the previous state. If conflicts happen, resolve them by editing the file to contain the content you want, then run `git merge --continue`.

    Now, the `xyz` and `abc` branches are parents of `master`, since `master` contains changes from both `xyz` and `abc` and has moved forward.

11. **`git remote add <name> <url>`**

    Adds a remote repository. The name is generally `origin`, and the URL is the remote repository’s URL, such as GitHub or GitLab. Run `git remote` to show the configured remote repositories.

12. **`git push <remote> <local branch>:<remote branch>`**

    Pushes local code to a remote repository. The remote is the name you gave it (often `origin`), the local branch is the branch you want to push (such as `master`), and the remote branch is the name you want to give that branch on the remote. For example: `git push origin master:master`. Now `git log` will also show information about this remote repository.

13. **`git clone <url> <folder name>`**

    Clones a remote repository to your local machine. The folder name is optional; if omitted, Git uses the repository’s name by default. The URL is the repository URL, such as a GitHub URL. The `--shallow` option pulls only the latest commit, not the entire version history.

14. **`git branch --set-upstream-to=<origin/master>`**

    If you do not want to write the long `git push` command every time, you can set the checked-out local branch to track the remote `master` branch (for example, `origin/master`). Then `git push` will know to push it to the `master` branch on `origin`. Alternatively, run `git push -u origin main` to set the upstream as well.

15. **`git fetch <remote>` and `git merge`**

    The `fetch` command downloads changes from a remote repository; the remote name is optional. It does not move the current `HEAD` to the newly fetched code. Use `merge` to move `HEAD` to that code.

16. **`git pull`**

    A shorter command that fetches changes from a remote repository and moves `HEAD` to the latest copy.

17. **`git rebase`**

    An alternative to merging, or a way to clean up commits. It is **not** meant to be run from the `main` or `master` branch; it should be run from another branch. Never rebase shared commits or code that is going to be pushed to GitHub. Rebase takes all the code from `master` and merges it into the current branch, flattening the Git graph from two separate branch histories into one line of commits.

## Other useful commands

1. **`git add -p file.txt`**

   Lets you interactively stage pieces of code instead of the whole file. This is useful when you want to commit only certain lines.

2. **`git diff --cached`**

   Shows the changes and lines in the staging area that are ready to commit.

3. **`git blame file.txt`**

   Shows the lines in a file, who committed them, and the commit hash associated with each line.

4. **`git show <commit_hash>`**

   Shows information about a commit, including its message and what changed.

5. **`git stash`**

   Resets `HEAD` to the last commit, but does not lose uncommitted changes; they are stored temporarily. Use `git stash pop` to restore the uncommitted changes.
