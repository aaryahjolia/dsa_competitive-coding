# Branches, merges, and rebase

Branches are Git’s “try this idea over here” button. A branch is a lightweight name pointing to a commit, so creating one is quick. It lets you work on a feature or fix without moving the branch you started from.

## Make a branch and switch to it

```bash
git switch -c add-search
```

This creates `add-search` at your current commit and switches to it. Older tutorials often use `git checkout -b add-search`; that still works, but `switch` is easier to understand because it only switches branches.

See your branches with:

```bash
git branch
git branch -vv
```

The `*` marks the current branch. `-vv` also shows upstream information when configured.

Switch between existing branches with:

```bash
git switch main
git switch add-search
```

Git normally protects uncommitted changes when you switch. If switching would overwrite them, Git stops and asks you to deal with those changes first. Check `git status`; then commit, stash, or otherwise handle the edits before trying again.

## Bring the work back with merge

When the feature is ready, switch to the branch that should receive it and merge:

```bash
git switch main
git merge add-search
```

There are two common outcomes:

**Fast-forward:** if `main` has not moved since `add-search` split off, Git can simply move `main` forward to the feature commit. No merge commit is needed.

```text
Before:  A ── B (main)
                  \
                   F1 ── F2 (add-search)

After:   A ── B ── F1 ── F2 (main, add-search)
```

**Three-way merge:** if both branches have new commits, Git combines their histories and usually creates a merge commit with two parents.

```text
          F1 ── F2 ──┐
         /            \
A ── B ── M1 ───────── M2 (main)
```

The exact graph depends on the commits already made. The important idea is that merge keeps both lines of history and joins them.

## When Git asks you to resolve a conflict

Sometimes both branches changed the same lines in incompatible ways. Git pauses and marks the conflicting section in the file. It has not chosen a winner; you decide what the final text should be.

1. Run `git status` to find the conflicted files.
2. Open each file and edit the conflict markers (`<<<<<<<`, `=======`, `>>>>>>>`) into the version you want to keep.
3. Stage each resolved file with `git add <file>`.
4. Finish the merge with `git merge --continue` (or commit if Git asks you to do so).

If you want to abandon the merge and return to how things were before it started, use:

```bash
git merge --abort
```

## Rebase: replay commits onto a newer starting point

Suppose `main` moved ahead while you were working on a feature. Rebase can replay your feature commits so they start from the latest `main`:

```bash
git switch add-search
git rebase main
```

Before:

```text
      F1 ── F2 (add-search)
     /
A ── B ── M1 ── M2 (main)
```

After:

```text
A ── B ── M1 ── M2 ── F1' ── F2' (add-search)
```

Git replays the changes from `F1` and `F2` on top of `M2`. The new commits (`F1'`, `F2'`) have new IDs because their parents changed. This can make a branch’s history look like one tidy line.

If a conflict happens during rebase, resolve the file, stage it, then run `git rebase --continue`. To stop and return to the pre-rebase state, run `git rebase --abort`.

### The shared-branch rule of thumb

Use rebase for commits that are still your own local work. Avoid rebasing commits that other people may already have based work on, because rebase replaces those commits with new ones. For shared history, merging is usually the less surprising choice.

Official references: [`git switch`](https://git-scm.com/docs/git-switch), [`git merge`](https://git-scm.com/docs/git-merge), and [`git rebase`](https://git-scm.com/docs/git-rebase).
