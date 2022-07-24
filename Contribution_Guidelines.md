# Contribution Guidelines

Hey coders and learners, 
We are very much pleased to have you onboard with our journey.

### Read this entire file to know how to start contributing in our repository.

Steps to contribute your code in any of the mentioned dsa folder:
1. [Star](https://help.github.com/en/articles/about-stars) :star: the repository.
2. [Fork](https://help.github.com/en/articles/fork-a-repo) the repository into your github account.
3. Clone the repository into your local system by using git clone command OR edit it online on github website.
4. Make a new Branch with the command `git checkout -b new_branch_name` and make changes in that branch only.
5. Write necessary code in your preferred folder, Add that topic in the parent folder's **.md** file (Example : If I've done code of Linear Search in Searching Folder, Add Linear Search under Searching Algorithm section in `Searching.md` file).
6. Always use [Coding Style](https://github.com/aaryahjolia/dsa_competitive-coding/blob/main/Contribution_Guidelines.md#coding-style) when writing a code.
7. Commit the code with a meaningful description.
8. [Push](https://help.github.com/en/articles/pushing-to-a-remote) the code to your cloned repository on your github account.
9. Submit a [Pull Request](https://help.github.com/en/articles/about-pull-requests) with your updated repository into our repository.
10. That's all! You've done your Open Source Contribution. Just wait for us to merge your code into main repository.


We are thankful to all the people showing interest in our repository.

---

# Coding style

Follow this coding Scheme throughout your contribution:

1. File naming:
    If you are demonstrating `linear search` in `searching`, name your file **`Linear_Search.md`** and save it in the `Searching` directory.
    Remember to name your file in Pascal Case (First letter capital) with `_` in between. Ex: `Merge_Sort.md`.

2. In every **.md** file, You need to have a Description, the code, and the time complexities.

3. Add Opening braces for loops, conditional statements,etc. on the same line.
```cpp
    int main()
    {
                            // ❌
    }

    int main(){
                            // ✔️.
    }
```

4. Indentation : 
    Use only one indenting format for the whole program.
    Use **1 Tab** or **4 Spaces**.

5. Add appropriate comments wherever necessary to explain the code.
> Programs wth NO Comments at all will not be merged.

6. Expression should be readable, Use 1 space between different tokens.
```cpp 
    a=a+b          // ❌
    a = a + b      // ✔️.
```

7. Always add braces in a for/while loop, even if it's a one-liner loop.
```cpp    
    for (int i = 0; i < 10 ; i++)
        cout << i << " ";               // ❌
    
    for (int i = 0; i < 10; i++){
        cout << i << " ";               // ✔️.
    }
```

8. You **MUST** use `using namespace std;` at beginning so that you don't have to write `std::` every time (Moreover some coders also don't know how to use `std::`, so it will be easy to understand).

9. **MUST** use `#include <bits/stdc++.h>` as competitive coders use that only (If you were unaware about it, This header file load all other header files so you don't have to include them seperately).

10. Don't include `.exe` files or any other files than `.cpp` (It's totally OK if you are going to contribute through Git as [.gitignore](.gitignore) file will ignore .exe files when pushing the code).
