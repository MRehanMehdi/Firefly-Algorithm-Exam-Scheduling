# 🔥 Firefly Algorithm – Exam Scheduling Project

This project implements the **Firefly Algorithm** using **C++** to solve a real-world **Exam Scheduling Problem**. The goal is to assign exams to available time slots in a way that **minimizes conflicts** for students who have multiple exams. This project is developed as part of the **Analysis of Algorithm** course and is aligned with **Course Learning Outcomes (CLOs)** and **Seoul Accord attributes**.

---

## 📌 Project Overview

- **Algorithm Used**: Firefly Algorithm (Metaheuristic Optimization)
- **Language**: C++
- **Application**: Conflict-free Exam Scheduling
- **Goal**: Minimize overlapping exams for students by optimizing exam timeslots
- **Approach**: Nature-inspired swarm intelligence algorithm simulating firefly movement and brightness attraction

---

## ⚙️ How to Compile and Run

1. Clone or download the repository.
2. Open the terminal or command prompt in the project folder.
3. Compile the code using a C++ compiler:
   ```bash
   g++ firefly.cpp -o scheduler
   ./scheduler

   ## 📈 Key Features

- Firefly-based metaheuristic optimization  
- Each firefly represents one possible exam schedule  
- Objective function minimizes student exam conflicts  
- Fireflies move based on attraction and random exploration  
- Shows output per run with:
  - Best exam-to-timeslot assignments  
  - Total number of student conflicts  
  - Execution time in milliseconds  
  - Estimated memory usage  

---

## 📚 Included Documentation

- **Pseudocode (`steps.md`)**: Step-by-step logic of the algorithm  
- **Complexity Analysis (`complexity.md`)**: Theoretical and empirical time/space complexity  
- **Formal Report (`REPORT.pdf`)**: Detailed explanation of the project, CLO mapping, evaluation, and results  

---

## 🧠 Educational Impact

This project simulates a real-world scenario (**exam scheduling**) using modern optimization techniques. It demonstrates how nature-inspired algorithms like the **Firefly Algorithm** can be adapted to handle scheduling constraints effectively, while maintaining a balance between accuracy and efficiency.

