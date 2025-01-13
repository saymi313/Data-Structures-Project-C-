# Setup Guide for this C++ Project

This README provides instructions for setting up and running the C++ project in **Visual Studio IDE**(Purple one). The project includes `.cpp` and `.h` files along with a `.csv` file for data input.



## Prerequisites

- **Visual Studio IDE**: Install the **Desktop development with C++** workload.
- **Required Files**:
  - `.cpp` files: Implementation code.
  - `.h` files: Header declarations.
  - `.csv` file: Data to be read by the program.



## Steps to Set Up the Project

### 1. Create a New Project
1. Open **Visual Studio IDE**.
2. Click **Create a new project**.
3. Select **Console App (C++)** and click **Next**.
4. Provide a project name and choose a location. Click **Create**.

### 2. Add Source Files
1. In **Solution Explorer**, right-click the **Source Files** folder.
2. Select **Add** → **Existing Item...**.
3. Navigate to the `.cpp` files' location and add them to the project.

### 3. Add Header Files
1. In **Solution Explorer**, right-click the **Header Files** folder.
2. Select **Add** → **Existing Item...**.
3. Navigate to the `.h` files' location and add them to the project.

### 4. Add the CSV File
1. Copy the `.csv` file to the project directory.
2. In **Solution Explorer**, right-click the project name and select **Add** → **Existing Item...**.
3. Locate and add the `.csv` file.

### 5. Update File Paths (if needed)
- Ensure the file path for the `.csv` file in the code matches its location in the project.
- Use relative paths, such as `myData_CS2001.csv`, for easier access.



## Build and Run the Project

### Build the Solution
- Go to **Build** → **Build Solution** (Shortcut: `Ctrl+Shift+B`).
- Resolve any compilation errors if they occur.

### Run the Project
- Click on **Local Windows Debugger** or press `F5`.
- The program will execute and read data from the `.csv` file.



## Notes

- Ensure the `.csv` file is formatted correctly for parsing by the program.
- Verify that the `.csv` file's path in the code is correct and accessible.



## Troubleshooting

- **Error: File Not Found**
  - Check that the `.csv` file exists in the project directory.
  - Confirm the file path is accurate.

- **Build Errors**
  - Ensure all `.cpp` and `.h` files are correctly added to the project.
  - Verify no unresolved dependencies exist.


