# 🧮 Complexity Analysis – Firefly Algorithm for Exam Scheduling

This file explains the time and space complexity of the Firefly Algorithm used to generate optimal exam schedules with minimal student conflicts.

---

## 4.1 Time Complexity

1. **Initialization**  
   - Create `n` fireflies, each representing a schedule with `m` exams  
   - **Time Complexity**: `O(n × m)`

2. **Main Loop (Generational Optimization)**  
   - For each generation `G`, all fireflies interact and update their positions  
   - Each firefly compares with every other and processes all `m` exams  
   - **Time Complexity**: `O(n² × m × G)`

3. **Total Time Complexity**  
   - Initialization + optimization  
   - **Combined Complexity**: `O(n² × m × G)`

4. **Parameter Definitions**  
   - `n`: Number of fireflies  
   - `m`: Number of exams  
   - `G`: Number of generations  

---

## 4.2 Space Complexity

1. **Firefly Storage**  
   - Each firefly stores a vector of size `m` (for exam timeslot assignments)  
   - **Space Complexity**: `O(n × m)`

2. **Worst Case**  
   - Full nested iterations across all generations  
   - **Space Complexity**: `O(n² × m × G)`

3. **Best Case**  
   - Fast convergence with minimal comparisons  
   - **Space Complexity**: `Ω(n × m)`

4. **Average Case**  
   - Moderate improvement across generations  
   - **Space Complexity**: `Θ(n² × m × G)`

---

## ✅ Summary

- The algorithm’s complexity grows with the number of fireflies, exams, and generations.
- Most processing time is spent in comparing and moving fireflies.
- Proper tuning of parameters (`n`, `G`) is important to balance solution quality and efficiency.
