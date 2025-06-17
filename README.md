# 🚗 Greedy License Plate Validation

This project implements a **Greedy Algorithm** to validate and auto-correct Egyptian-style license plates in real time. Designed for security and registration systems, the algorithm ensures plates conform to strict format rules using fast, heuristic-based logic.

## 📄 Overview

In modern vehicle registration systems, it's critical to instantly verify and correct plate inputs while minimizing delay. This greedy-based validator offers an efficient solution that prioritizes speed and simplicity over exhaustive computation.

This is part of a comparative study against Dynamic Programming (used for secure password generation), highlighting the efficiency trade-offs in real-world systems.


## 🧠 Algorithm Description

### ✅ Valid License Plate Format
- 3 **uppercase letters** at the beginning  
  (excluding **I, O, Q** to avoid confusion)
- Followed by a **hyphen** `-`
- Then **4 digits** (0-9)

### 🛠️ Greedy Validation Logic
- Iterates over the string to find valid letters and digits
- Replaces missing or invalid letters with `"A"`
- Inserts hyphen `-` if missing
- Fills missing digits with `"0"`
- Validates format without backtracking or full re-evaluation

