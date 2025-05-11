1. Set algorithm parameters (firefly count, β₀, γ, α, max generations)

2. Generate initial firefly population 
   (each firefly = one possible exam schedule)

3. For each firefly, calculate fitness = -number of student exam conflicts

4. For each generation (t = 1 to MaxGenerations):
   a. For each firefly i:
      i. For each firefly j:
         - If firefly_j has fewer conflicts than firefly_i:
           * Move firefly_i toward firefly_j 
             (adjust exam timeslots using attractiveness and randomness)
      ii. Recalculate fitness of firefly_i

5. Return the firefly with the lowest number of conflicts (best schedule)
