#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <set>
#include <iomanip>
#include <chrono> // for time measurement
using namespace std;
using namespace chrono;

// Problem parameters
const int NUM_EXAMS = 5;
const int NUM_TIMESLOTS = 3;
const int NUM_STUDENTS = 4;

// Firefly algorithm parameters
const int NUM_FIREFLIES = 10;
const int MAX_GEN = 50;
const double ALPHA = 0.3;
const double BETA0 = 1;
const double GAMMA = 1;

// Student exam registrations
vector<set<int>> studentExams = {
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 4}
};

// Structure to represent a firefly (solution)
struct Firefly {
    vector<int> schedule;
    double intensity;

    Firefly() : schedule(NUM_EXAMS), intensity(0) {}
};

// Count number of conflicts in a schedule
double calculateConflicts(const vector<int>& schedule) {
    int conflicts = 0;
    for (const auto& exams : studentExams) {
        vector<int> times;
        for (int exam : exams) {
            times.push_back(schedule[exam]);
        }
        for (size_t i = 0; i < times.size(); i++) {
            for (size_t j = i + 1; j < times.size(); j++) {
                if (times[i] == times[j]) {
                    conflicts++;
                }
            }
        }
    }
    return conflicts;
}

double objectiveFunction(const vector<int>& schedule) {
    return -calculateConflicts(schedule);
}

double distance(const vector<int>& a, const vector<int>& b) {
    int d = 0;
    for (int i = 0; i < NUM_EXAMS; i++) {
        if (a[i] != b[i])
            d++;
    }
    return d;
}

void randomizeSchedule(vector<int>& schedule) {
    for (int i = 0; i < NUM_EXAMS; i++) {
        schedule[i] = rand() % NUM_TIMESLOTS;
    }
}

void moveFirefly(Firefly& from, const Firefly& to) {
    for (int i = 0; i < NUM_EXAMS; i++) {
        if (rand() % 100 < 50) {
            from.schedule[i] = to.schedule[i];
        }
        else {
            from.schedule[i] = (from.schedule[i] + (rand() % NUM_TIMESLOTS)) % NUM_TIMESLOTS;
        }
    }
}

Firefly runFireflyOptimization(int runID) {
    vector<Firefly> fireflies(NUM_FIREFLIES);

    // Initialize
    for (int i = 0; i < NUM_FIREFLIES; i++) {
        randomizeSchedule(fireflies[i].schedule);
        fireflies[i].intensity = objectiveFunction(fireflies[i].schedule);
    }

    // Optimization
    for (int gen = 0; gen < MAX_GEN; gen++) {
        for (int i = 0; i < NUM_FIREFLIES; i++) {
            for (int j = 0; j < NUM_FIREFLIES; j++) {
                if (fireflies[j].intensity > fireflies[i].intensity) {
                    double r = distance(fireflies[i].schedule, fireflies[j].schedule);
                    double beta = BETA0 * exp(-GAMMA * r * r);
                    moveFirefly(fireflies[i], fireflies[j]);
                    fireflies[i].intensity = objectiveFunction(fireflies[i].schedule);
                }
            }
        }
    }

    // Best firefly
    Firefly best = fireflies[0];
    for (int i = 1; i < NUM_FIREFLIES; i++) {
        if (fireflies[i].intensity > best.intensity)
            best = fireflies[i];
    }

    return best;
}

int main() {
    srand(time(0));
    const int NUM_RUNS = 5;
    vector<int> finalConflicts;
    double totalTime = 0;

    cout << "===== Firefly Algorithm - Exam Scheduling =====" << endl;

    for (int run = 1; run <= NUM_RUNS; run++) {
        auto start = high_resolution_clock::now();
        Firefly best = runFireflyOptimization(run);
        auto end = high_resolution_clock::now();
        duration<double, milli> elapsed = end - start;
        totalTime += elapsed.count();

        int conflicts = -best.intensity;
        finalConflicts.push_back(conflicts);

        cout << "\nRun #" << run << ":\n";
        for (int i = 0; i < NUM_EXAMS; i++) {
            cout << "  Exam " << i << " → Timeslot " << best.schedule[i] << endl;
        }
        cout << "  Conflicts: " << conflicts << endl;
        cout << "  Time Taken: " << fixed << setprecision(2) << elapsed.count() << " ms\n";
    }

    // Average conflicts
    double sum = 0;
    for (int c : finalConflicts) sum += c;
    double avg = sum / NUM_RUNS;

    cout << "\n====== Empirical Performance Summary ======" << endl;
    cout << "Runs: " << NUM_RUNS << ", Avg. Conflicts: " << fixed << setprecision(2) << avg << endl;
    cout << "Total Time: " << fixed << setprecision(2) << totalTime << " ms\n";
    cout << "Average Time per Run: " << fixed << setprecision(2) << totalTime / NUM_RUNS << " ms\n";

    // Approximate space usage
    size_t sizeOfFirefly = sizeof(Firefly) + NUM_EXAMS * sizeof(int);
    size_t totalMemory = NUM_FIREFLIES * sizeOfFirefly;
    cout << "Approx. Memory Used (Fireflies Only): " << totalMemory << " bytes\n";

    return 0;
}
