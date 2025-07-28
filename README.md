#  To-Do List App (Qt C++)
A modern, fully-featured daily planner desktop app built using **C++ and the Qt Framework**. Designed with a custom pink-themed UI, this application helps users organize their day with features like  real-time date display, progress tracking, task categorization, and session persistence.

---

##  Features
*  **Task Management**: Quickly add, complete, or remove tasks with a click or `Enter`.
*  **Task Completion**: Double-click tasks to strike-through (toggle complete).
*  **Task Description**: Add and view detailed descriptions for each task.
*  **Task Categories**: Assign categories (e.g., *Work*, *Personal*) shown next to tasks.
*  **Progress Bar**: Auto-updates to reflect the number of completed tasks.
*  **Live Calendar Card**: Displays current day, date, and month dynamically.
*  **Session Persistence**: Unfinished tasks are restored using `QSettings`.
*  **Custom UI**:
  * Pink-themed modern design using Qt Style Sheets.
  * Hover effects, responsive layout.
*  **Strike-Through Toggle**: Visual completion marker with line-through styling.
*  **Task Reminders**: Schedule reminders for tasks.
*  **Search & Filter**: Quickly filter and locate tasks.
  
---

##  UI Components
| **Component**                                         | **Purpose / Use**                                     |
|-------------------------------------------------------|-------------------------------------------------------|
| `QSettings`                                           | Save/restore task list and state on close             |
| `QCloseEvent`                                         | Handle app closing for task cleanup                   | 
| `QTimer`, `QDateTime`                                 | Real-time clock updates and scheduling reminders      |
| `QInputDialog`, `QDialog`                             | For entering task descriptions and categories         |
| `QMessageBox`                                         | Alerts and confirmations                              |
| `QDebug`                                              | Development logging                                   |
| `QSystemTrayIcon`                                     | *(Upcoming)* Background reminders via system tray     |

---

##  Tech Stack
| Component      | Technology            |
| -------------- | --------------------- |
| **Language**   | C++                   |
| **Framework**  | Qt 5 / Qt 6 (Widgets) |
| **IDE**        | Qt Creator            |
| **Storage**    | QSettings             |
| **Versioning** | Git & GitHub          |

---

##  Getting Started
###  Prerequisites

* Install Qt (recommended via [Qt Installer](https://www.qt.io/download))
* Qt Creator IDE or compatible C++ IDE with Qt support

###  Clone the Repository

```bash
git clone https://github.com/Tanisha02806/To_Do_List.git
cd To_Do_List
```

###  Build & Run

1. Open the `.pro` file in **Qt Creator**
2. Build the project (`Ctrl + B`)
3. Run the app (`Ctrl + R`)

---

## 📁 Project Structure

```
├── main.cpp             # App entry point
├── mainwindow.h         # Main window class
├── mainwindow.cpp       # Core logic (task, voice, UI)
├── mainwindow.ui        # Layout design
└── README.md            # Documentation
```

---

##  Screenshots
<img width="1183" height="919" alt="image" src="https://github.com/user-attachments/assets/a8bdd73a-791b-44f3-9e41-9589fb458855" />

---

##  Author
**Tanisha Thakur**
🔗 [GitHub – @Tanisha02806](https://github.com/Tanisha02806)

---
