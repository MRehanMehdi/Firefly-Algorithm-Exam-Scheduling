🔁 Pseudocode / Flowchart – Firefly Algorithm for Exam Scheduling
This file contains the structured pseudocode for solving the Exam Scheduling Problem using the Firefly Algorithm. Each firefly represents a possible exam schedule, and the algorithm iteratively improves solutions by simulating attraction and movement among fireflies.

📘 Algorithm: Firefly-Based Exam Scheduling

1. Set algorithm parameters:
   - Number of fireflies (n)
   - Base attractiveness (β₀)
   - Light absorption coefficient (γ)
   - Randomness factor (α)
   - Maximum number of generations (MaxGen)

2. Generate the initial population:
   - Each firefly represents a random exam schedule
   - Assign each exam to a timeslot randomly

3. For each firefly, calculate its fitness:
   - Fitness = negative of the number of exam conflicts
   - A conflict occurs when a student has overlapping exams

4. For each generation t = 1 to MaxGen:
   a. For each firefly i in the population:
      i. For each firefly j in the population:
         - If firefly_j has better (lower) conflicts than firefly_i:
           * Calculate the distance between i and j
           * Compute attractiveness using: β = β₀ × exp(−γ × distance²)
           * Move firefly_i towards firefly_j
             (adjust timeslots with randomness)

      ii. Recalculate the fitness of firefly_i

5. After all generations, return the firefly with the best fitness:
   - This firefly represents the exam schedule with the lowest conflicts
