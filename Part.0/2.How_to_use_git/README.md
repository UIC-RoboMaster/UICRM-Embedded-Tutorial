# How to use git

## 1. Git Introduction

### 1.1 What is Git

Git is a distributed version control system, which is used to manage the source code of software development. It is designed for the efficient and reliable management of very large projects, and is also suitable for small projects. It is currently the most popular version control system in the world.

### 1.2 Why use Git

Git is a distributed version control system, which is different from the centralized version control system such as SVN. It has the following advantages:

1. Distributed development, no need to rely on the network, you can work offline.
2. Git has a complete branch management system, which is very convenient for branch management and merging.
3. Git has a complete tagging system, which is very convenient for version management.
4. Git has a complete log system, which is very convenient for project management.
5. Git has a complete collaboration mechanism, which is very convenient for team collaboration.

### 1.3 Git Installation

#### 1.3.1 Windows

Run the following command in the terminal:

```cmd
winget install Git.Git
```

#### 1.3.2 Linux(Ubuntu)

Run the following command in the terminal:

```bash
sudo apt install git
```

#### 1.3.3 MacOS

In general, MacOS has installed Git by default. If not, you can [install brew](https://brew.sh) and run the following command in the terminal:

```bash
brew install git
```

### 1.4 Git Configuration

#### 1.4.1 User Information

Run the following command in the terminal:

```bash
git config --global user.name "Your Name"
git config --global user.email "Your Email"
```

#### 1.4.2 Editor

Run the following command in the terminal:

```bash
# For VSCode
git config --global core.editor "code --wait"
# For Vim
git config --global core.editor "vim"
```

### 1.5 Git Basic Operation

#### 1.5.1 Create a Repository

Run the following command in the terminal:

```bash
git init
```

#### 1.5.2 Add Files

Run the following command in the terminal:

```bash

# Add all files
git add .

# Add a specific file
git add <file name>
```

#### 1.5.3 Commit

Run the following command in the terminal:

```bash
git commit -m "Commit Message"
```

#### 1.5.4 Check Status

Run the following command in the terminal:

```bash
git status
```

#### 1.5.5 Check Commit Log

Run the following command in the terminal:

```bash
git log
```

#### 1.5.6 Check Difference

Run the following command in the terminal:

```bash
git diff
```

#### 1.5.7 Check Commit History

Run the following command in the terminal:

```bash
git reflog
```

#### 1.5.8 Branch

Run the following command in the terminal:

```bash
# Create a branch
git branch <branch name>

# Switch to a branch
git checkout <branch name>

# Create a branch and switch to it

git checkout -b <branch name>

# Delete a branch
git branch -d <branch name>
```

#### 1.5.8 Reset

Run the following command in the terminal:

```bash
# Reset to the last commit
git reset --hard HEAD^

# Reset to the specific commit
git reset --hard <commit id|branch name>

# Reset to the specific commit and keep the changes
git reset --soft <commit id|branch name>

# Reset to the specific commit and keep the changes in the staging area
git reset --mixed <commit id|branch name>

```

#### 1.5.9 Merge

Run the following command in the terminal:

```bash
# Merge a branch to the current branch
git merge <branch name>
# If there is a conflict, you need to manually modify the conflict file and then add and commit it.
```

#### 1.5.10 Add Remote Repository

run the following command in the terminal:

```bash
git remote add <remote name> <remote address>
```

## 2. GitHub

### 2.1 What is GitHub

GitHub is a Git repository hosting service, which provides a web-based graphical interface and desktop and mobile integration. It also provides access control and several collaboration features such as bug tracking, feature requests, task management, and wikis for every project.

### 2.2 Why use GitHub

GitHub is a Git repository hosting service, which is different from the centralized version control system such as SVN. It has the following advantages:

1. GitHub is a web-based graphical interface, which is very convenient for project management.
2. GitHub has a complete collaboration mechanism, which is very convenient for team collaboration.
3. GitHub has a complete issue system, which is very convenient for bug tracking and feature requests.
4. GitHub has a complete wiki system, which is very convenient for documentation.
5. GitHub has a complete pull request system, which is very convenient for code review.
6. GitHub has a complete action system, which is very convenient for CI/CD.

### 2.3 Create a Repository

1. Click the `+` button in the upper right corner of the GitHub homepage and select `New repository` in the drop-down menu.

   ![Create a Repository](./images/1.png)

2. Enter the repository name and click `Create repository`.

   ![Create a Repository](./images/2.png)

### 2.4 Set up SSH Key

1. Run the following command in the terminal:

    ```bash
    ssh-keygen -t ed25519
    ```

2. Then press `Enter` to use the default path and enter the password.

3. Run the following command in the terminal:

    ```bash
    cat ~/.ssh/id_ed25519.pub
    ```

    if you are using Windows, run the following command in the terminal:

    ```cmd
    type %USERPROFILE%\.ssh\id_ed25519.pub
    ```

4. Copy the output content.
5. Click the profile icon in the upper right corner of the GitHub homepage and select `Settings` in the drop-down menu.
6. Select `SSH and GPG keys` in the left menu.
7. Click `New SSH key`.
8. Enter the title and paste the content copied in step 4 into the `Key` field.
9. Click `Add SSH key`.
10. Then you can see the SSH key you just added.

    ![Set up SSH Key](./images/3.png)

### 2.4 Clone a Repository

1. Click the `Code` button in the upper right corner of the repository page and copy the repository address.
2. Run the following command in the terminal:

    ```bash
    git clone <repository address>
    ```

    >Note: If you are clone an private repository, you need to use SSH address, not HTTPS address. If you are clone an public repository, you can use HTTPS address.

### 2.5 Push

> Note: Before you push, you need to add the remote repository address.

Run the following command in the terminal:

```bash
git push <remote name> <branch name>
```

### 2.6 Pull

> Note: Before you pull, you need to add the remote repository address, and set up SSH Key.

Run the following command in the terminal:

```bash
git pull <remote name> <branch name>
```

## 3. Pull Request

### 3.1 What is Pull Request

Pull Request is a function provided by GitHub (and many others git remote provider), which is used to submit code to the repository. It is usually used for merge and code review.

### 3.2 How to use Pull Request

1. Click the `Pull requests` button in the upper right corner of the repository page and click `New pull request` in the drop-down menu.
2. Select the branch you want to merge and the branch you want to merge to.
3. Click `Create pull request`.
4. Enter the title and description of the pull request.
5. Click `Create pull request`.
6. Then you can see the pull request you just created.
7. If you want to merge the pull request, click `Merge pull request` and then click `Confirm merge`.

### 3.3 If there are conflicts in PR

1. If there are conflicts in PR, you need to manually modify the conflict file and then add and commit it.
