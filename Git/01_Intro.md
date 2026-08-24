Version control system are tools that are used to keep track of changes t source code or other colections of files or folders. It helps track the history of changes to some set of documents and really sueful for collaboraton so really sueful for working with group of people on software project.
It stores a snapshot, the state of the folder at that time. Also stores bunch of metadata like who authored the file, who made the changes or time when change was made. 
It is useful for inidividual use as well, you can work on features while working on bugs by branches, etc.
Version control system or Git is powerful in a way also such that, there is a unit test which was passing, but after few merges, it's failing and you dont know which merge caused this regression. Git can binary search the changes and point out to change which introduced this regression.
Lets say a project consists of following:
(Root) - root directory
|
|- foo <- called "tree" or folder
|   - bar.txt <- called "blob" or files
|- info.txt <- also "blob"

The directories are called tree, tree can contain other trees or blobs. Blobs can't contain trees. root is the root directory being tracked.
One way to remember state is to get a snapshot of the root, then take other snapshot at interval of time, etc. basically making a linear chain.
Git doesn't use this, it uses directed acyclic graph to model history.
Snapshots are stored like following:
O <- O <- O (feature) <- O
      |                  |
      | <- O (bugfix) <- |
O are snapshots that points to its parent. In linear, we can only do one work at one time on root. With git's DAG, there are 2 O's simultaneously, one for bugfix and one for feature. When we merge it, the last O points to both O which means 2 parent snapshots.

Psuedocode for this is:
type blob = array<byte>
type tree = map<string, tree|blob> (string is directory name, maps to other directory or files)
type commit = struct{ <- git calls commit to snapshots
    parentCommits: array<commit>, (stored as hash)
    author: string,
    message: string,
    snapshot: tree (root tree)
}

In disk, it is stored as objects. Psuedocode:
type object = blobl|tree|commit
objects = map<string, object> (string is SHA-1 Hash like commit hash, object is object to store)

def store(O):
    id=SHA1(O)
    object[id]=O
def load(id):
    return object[id]

SHA-1 are hexadecimal string that are 40 chars long (160 bit hash) Ex: 4af32cb...7f
So every commit is identified by this hash, but its unreadable to human. So solution to this in git is, git maintains references, a mapping of hash to human readable name.
references = map<string, string>
Ex:("Fixed encoding Bug", "4af32cb...7f")
So we can identify snapshots in history by this reference string instead of hash. References are used to point to a particular commit in the DAG.

Given git's design for history, the whole graph is immutable. We can add new things but can't manipulate
anything in there. 
References are mutable. So we can change the string name to any other commit, but we can't change hash string since for that we'll have to change the object which is not permitted.

At high level, git commands are just manipulation to objects or references data.

Commands:
1. git init
To initialise git repo in any root directory
2. git help <command>
Give info about that command i.e. git help init
3. git status
Provides the status of the current git repo, what files are tracked, what are not tracked, etc.
Let's say we create a file now. we want to make a snapshot of this current content, but there's no direct command. It's because git gives you flexibility of what changes to include in next snapshot/commit. So there is something called staging area at high level, which tells git what to include in next snapshot/commit. Now, git status will say no commits but there is an untracked file.
4. git add file.txt ('git add -A' for all files)
Adds a file/folder to staging area where it's ready now to be commited (creating a snapshot)
git status will now identify file to be committed
5. git commit
This actually creates a snapshot/commit. It'll ask for message to later identify what changes were merge or associate this commit hash with.
Now we have a single node in our DAG with this commit.
6. git log ('--all --graph --decorate' arguments to view it as graph, add '--oneline' to see minimal version of graph)
It helps visualize the history or the commit graph from starting.
-> HEAD is a special pointer which points to current directory, master is the main branch which tells the latest point in DAG.
7. git checkout <hash or 'master' or filename>
If you give hash, it changes HEAD to that node/commit and you'll see directory at that point of commit. It changes HEAD to point at that node but master will be still at latest node. To switch HEAD to master back, git checkout master. Any uncommitted changes will not allow to checkout, you can either commit it or pass '-f' argument to force it to overwrite the content and your unsaved content will be lost.
8. git diff hello.txt
This compares the file between the current directory and HEAD and tells what changed in that file. You can also compare between different snapshots/commits with 'git diff 4f2a4g HEAD hello.txt'.
9. git branch
Shows all the branches in the git repo. Use 'git branch xyz' to create a branch. Initially, HEAD will point to master, and xyz is also at master. 'git checkout xyz' switches HEAD to xyz. Short command to create and change to branch is 'git checkout -b xyz'. (-vv argument to see all branches)
10. git merge xyz
If you have 2 branches like xyz and abc and you want to merge xyz in master to make it latest code, checkout to master and then run git merge xyz, by this, since xyz is ahead of master, master will move to xyz commit and head will now point to master which is same as xyz.
git merge --abort to abort the merge and restore the state. If conflicts happens, resolve it by editing the file of what content you want to have, then run git merge --continue.
Now, xyz and abc branch are parent of master since master contains both changes from xyz and abc and it has moved forward.
11. git remote add <name> <url>
To add a remote repo, use this command. name is generally kept as origin, url is remote repo url like github or gitlab. Only git remote will show remote repo configured.
12. git push <remote> <local branch>:<remote branch>
If we want to push local code to remote repo, we can use this command. remote is origin we named, local branch is branch name you wish to push like master and remote branch name is what you want to name that remote branch. Ex: git push origin master:master. Now git log will also show info about this remote repo.
13. git clone <url> <folder name>
To clone remote repo to local, use this. Folder name is optional, it will take remote repo name by default. URL is github url of repo. (--shallow command will just pull latest commit and not entire version history)
14. git branch --set-upstream-to=<origin/master>
If you dont want to write long git push command everytime, you can set local checked out branch to track remote master branch (Ex: origin/master). Now git push command will know to push it to origin's master branch. (Or run git push -u origin main to set upstream also)
15. git fetch <remote> and git merge
fetch command will fetch the changes from remote repo, giving name is optional. It will not move current HEAD to that latest fetched code, use merge command to move HEAD to that.
16. git pull
Shorter command to fetch changes from remote repo and change HEAD to that latest copy
17. git rebase
It's alternative to merging or cleaning up commits. It is NOT meant to be run from main/master branch, but always from another branch. Never rebase shared commits or code to be pushed to github. Rebase takes all code from master and merge it to current branch, flattening the git graph from 2 different graph of indivudual branch to one single line of commits.

Other useful commands:
1. git add -p file.txt
Lets you interactively stage pieces of code instead of whole file, useful when you have to commit only certain lines.
2. git diff --cached
Shows what changes and lines are in staging ready to commit.
3. git blame file.txt
Shows what all lines are there in file, who committed it and by which commit hash
4. git show <commit_hash>
Shows info about that commit, message, what changed
5. git stash
Resets the HEAD to last commit, but any uncommited changes are not lost, they are stored somewhere. Use git stash pop to restore the uncommited changes.