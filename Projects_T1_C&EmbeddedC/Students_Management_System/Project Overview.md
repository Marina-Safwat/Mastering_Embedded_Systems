
# Student Management System Project

## Project Overview

**Project Title:** Student Database Management System

**Author:**  Marina Safwat

**My Profile**: [LearnInDepth]((https://www.learn-in-depth-store.com/account/blank-4))

## Introduction

The Student Management System is a software application designed to manage student information in an educational institution. The system allows users to perform various operations such as adding students manually, displaying student information, searching for students by ID, first name, or enrolled courses, and updating or deleting student records. The project utilizes a FIFO (First-In-First-Out) buffer to store student data, providing an efficient way to manage and retrieve information.

## Project Components

The project consists of three main components: FIFO (First-In-First-Out) buffer, student information structure, and the main control program.

### 1. FIFO (First-In-First-Out) Buffer

The FIFO buffer is implemented to store student information in a structured manner. It is designed as a circular buffer, allowing efficient storage and retrieval of student records. The buffer is initialized, and students are enqueued as they are added manually or read from an external file. The FIFO buffer ensures that student information is managed in the order it was added.

### 2. Student Information Structure

The `student` structure defines the attributes of a student, including first name, last name, ID, GPA, Number of course enrolled, and an array of course IDs. This structure is used to represent individual student records and is employed throughout the project for various operations.

### 3. Main Control Program

The main control program, implemented in the `main.c` file, serves as the user interface. It allows users to interact with the system through a menu-driven console interface. Users can choose from a range of options, such as adding students manually or by the text file, displaying all students, searching for students, updating student records, and more. The main control program leverages functions defined in `Students.c` and `FIFO.c` to perform these operations.

## Key Features

- **Add Students Manually or By file:** Users can input student information, including ID, first name, last name, GPA, and enrolled courses. The data is then added to the FIFO buffer and the file for storage.

- **Display All Students:** The system can display information for all students from the FIFO buffer.

- **Search by ID, First Name, or Courses:** Users can search for students by their unique ID, first name, or enrolled courses. The search functionality helps quickly locate specific student records.

- **Update and Delete Student Records:** The system allows users to update existing student records by selecting the attribute to modify. It also supports the deletion of student records by ID.

## External File Interaction

Student information is persisted in an external file (`StudentsDB.text`). The system can read student data from this file and enqueue it into the FIFO buffer. Additionally, new student records added manually are written to the file for future retrieval.

## Conclusion

The Student Management System provides a convenient and organized way to manage student information. The use of a FIFO buffer enhances data management efficiency, and the integration with an external file enables data persistence between sessions. The project demonstrates fundamental file handling, data structure, and user interface concepts in C programming.
