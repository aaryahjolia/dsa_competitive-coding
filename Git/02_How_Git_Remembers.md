# How Git remembers your work

Imagine you are writing a game. One day the score works, the next day the menu works, and then a mysterious bug turns every score into `42`. Git is your project’s save system: it helps you record useful checkpoints, compare them, and return to earlier work.

## Version control is a project time machine

A version control system tracks changes to files over time. That is handy when you work alone (try a new feature without losing the stable version) and essential when you work with other people (see what changed and combine everyone’s work).

Git can also help find when a bug appeared. If a test passed in one old commit and fails in a newer one, `git bisect` can search through the commits to narrow down the change that introduced it. It is a little like a very focused game of “hot or cold.”

## A commit is a saved snapshot

A Git commit records a project snapshot along with details such as its author, time, message, and parent commit or commits. Git’s storage is efficient: identical file contents can be shared by many snapshots instead of copied over and over.

Git organizes the contents of a project as objects:

- A **blob** holds file contents. It does not remember the filename.
- A **tree** holds names and points to blobs (files) or other trees (folders).
- A **commit** points to the top-level tree and records who made the snapshot, when, why, and which commit or commits came before it.

Picture a project like this:

```text
project (tree)
├── foo (tree)
│   └── bar.txt (blob)
└── info.txt (blob)
```

The tree remembers the folder structure and names; the blobs hold the bytes inside files.

## History is a graph, not just a stack

If you only ever worked in a straight line, history could look like a row of save points:

```text
A ── B ── C
```

But real work branches. You might fix a bug and build a feature at the same time:

```text
          F1 ── F2   (feature)
         /         \
A ── B ─────────── M
         \         /
          X1 ── X2   (bug-fix)
```

Each letter is a commit. `F1` and `X1` both started from `B`, so those efforts can move forward independently. `M` is a merge commit that has both lines of work as parents. Sometimes Git can join branches by simply moving a branch pointer forward; that is called a **fast-forward** and does not need a new merge commit.

This history shape is a **directed acyclic graph** (DAG): commits point back to their parent commits, and the arrows never form a loop. The graph allows parallel work without forcing a single shared timeline.

## Commits have IDs; names are pointers

Git identifies each stored object by a hash of its contents and type. A commit ID often looks like a long hexadecimal string. The exact hash format depends on the repository; you usually do not need to memorize or type the whole thing because Git accepts an unambiguous short prefix.

Names such as branch names and tags make history easier to navigate. A branch like `main` is a movable pointer to a commit. When you make a new commit on `main`, that pointer advances. A tag usually marks a specific point, such as a release.

`HEAD` tells Git what you currently have checked out. Most of the time it points to your current branch, which in turn points to a commit. If you check out a commit directly, `HEAD` points straight to that commit instead; this is called **detached HEAD**. It is fine for looking around, but create a branch if you want new commits to have a named home.

Git objects are immutable once created: changing a file makes a new blob/tree/commit rather than editing an old snapshot. References such as branches can move to point at different commits. This is why a commit ID identifies one exact snapshot and its metadata.

## A tiny mental model

You can picture a commit roughly like this:

```text
commit {
    parent commits
    author and timestamp
    message
    project snapshot (the top-level tree)
}
```

The implementation has more details, but this model is enough to make sense of the history graph and the commands in the next lessons.

For the official deep dive, see Git’s [data model](https://git-scm.com/docs/gitdatamodel).
