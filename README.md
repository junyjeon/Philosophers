
<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>
philosophers
</h1>
<h3 align="center">📍 Think, collaborate and connect with the philosophers on GitHub.</h3>
<h3 align="center">🚀 Developed with the software and tools below.</h3>
<p align="center">

<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=for-the-badge&logo=C&logoColor=black" alt="" />
</p>

</div>

---
## 📚 Table of Contents
- [📚 Table of Contents](#-table-of-contents)
- [📍Overview](#-introdcution)
- [🔮 Features](#-features)
- [⚙️ Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🏎💨 Getting Started](#-getting-started)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [🪪 License](#-license)
- [📫 Contact](#-contact)
- [🙏 Acknowledgments](#-acknowledgments)

---

## 📍Overview

Philosophers is an open-source project that uses natural language processing (NLP) to extract insights from philosophical texts. It includes tools for text analysis, ontology building, and visual

## 🔮 Feautres

> `[📌  INSERT-PROJECT-FEATURES]`

---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-github-open.svg" width="80" />

## ⚙️ Project Structure

```bash
repo
└── philo
    ├── Makefile
    ├── inc
    │   └── philosophers.h
    ├── philosophers
    └── src
        ├── init.c
        ├── main.c
        ├── monitor.c
        ├── philos_cycle.c
        ├── tempCodeRunnerFile.c
        ├── util_01.c
        └── util_02.c

3 directories, 10 files
```
---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-src-open.svg" width="80" />

## 💻 Modules
<details closed><summary>Inc</summary>

| File           | Summary                                                                                                                                                                                                                                                                                | Module                   |
|:---------------|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:-------------------------|
| philosophers.h | This code is a header file for a program that simulates the dining philosophers problem . It contains structs and functions for initializing the program , creating the philosophers , and monitoring their actions . It also includes utility functions for printing , sleeping , and | philo/inc/philosophers.h |

</details>

<details closed><summary>Philo</summary>

| File         | Summary                                                                                                            | Module             |
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:-------------------|
| philosophers | This code is an error message indicating that a file could not be decoded because it is not a text or UTF-8 file . | philo/philosophers |

</details>

<details closed><summary>Src</summary>

| File                 | Summary                                                                                                                                                                                                                                                        | Module                         |
|:---------------------|:---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:-------------------------------|
| util_02.c            | This code contains utility functions for a program , such as ft_perror for printing errors , ft_strlen for calculating the length of a string , ft_putstr_fd for writing a string to a file descriptor , and ft _                                              | philo/src/util_02.c            |
| util_01.c            | This code is a utility file for the Philosophers problem . It contains functions to get the current time , put the thread to sleep , and print messages with a mutex lock .                                                                                    | philo/src/util_01.c            |
| main.c               | This code is the main function of a program that simulates the dining philosophers problem . It initializes the program 's information , creates the philosophers , and then monitors their behavior . It also includes a function to check for memory leaks . | philo/src/main.c               |
| init.c               | This code initializes the information and mutexes needed for a program that simulates philosophers eating . It takes in command line arguments for the number of philosophers , time to die , time to eat , and time to sleep . It also takes in               | philo/src/init.c               |
| monitor.c            | This code is a monitor for a program that simulates philosophers eating . It checks for when all the philosophers have eaten , when one of them has died , and when the program should end . It also includes functions to free all the resources used by      | philo/src/monitor.c            |
| philos_cycle.c       | This code creates threads for each philosopher and runs a cycle of eating , sleeping , and thinking . It also checks if the philosopher has eaten the required number of times and updates the full_cnt accordingly .                                          | philo/src/philos_cycle.c       |
| tempCodeRunnerFile.c | init_info is a function that initializes a set of variables with default values . It takes in a list of variables and assigns each one a default value . This function is useful for quickly setting up a set of variables with predetermined values .         | philo/src/tempCodeRunnerFile.c |

</details>
<hr />

## 🚀 Getting Started

### ✅ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> `[📌  INSERT-PROJECT-PREREQUISITES]`

### 💻 Installation

1. Clone the philosophers repository:
```sh
git clone https://github.com/junyjeon/philosophers
```

2. Change to the project directory:
```sh
cd philosophers
```

3. Install the dependencies:
```sh
gcc -o myapp main.c
```

### 🤖 Using philosophers

```sh
./myapp
```

### 🧪 Running Tests
```sh
#run tests
```

<hr />

## 🛠 Future Development
- [X] [📌  COMPLETED-TASK]
- [ ] [📌  INSERT-TASK]
- [ ] [📌  INSERT-TASK]


---

## 🤝 Contributing
Contributions are always welcome! Please follow these steps:
1. Fork the project repository. This creates a copy of the project on your account that you can modify without affecting the original project.
2. Clone the forked repository to your local machine using a Git client like Git or GitHub Desktop.
3. Create a new branch with a descriptive name (e.g., `new-feature-branch` or `bugfix-issue-123`).
```sh
git checkout -b new-feature-branch
```
4. Make changes to the project's codebase.
5. Commit your changes to your local branch with a clear commit message that explains the changes you've made.
```sh
git commit -m 'Implemented new feature.'
```
6. Push your changes to your forked repository on GitHub using the following command
```sh
git push origin new-feature-branch
```
7. Create a pull request to the original repository.
Open a new pull request to the original project repository. In the pull request, describe the changes you've made and why they're necessary.
The project maintainers will review your changes and provide feedback or merge them into the main branch.

---

## 🪪 License

This project is licensed under the `[📌  INSERT-LICENSE-TYPE]` License. See the [LICENSE](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/adding-a-license-to-a-repository) file for additional info.

---

## 🙏 Acknowledgments

[📌  INSERT-DESCRIPTION]


---

