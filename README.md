# Airline-Crew-Management
# ✈️ Airline Crew Management System (Graph - C)

---

## 📌 Project Title

**Airline Crew Management using Graph (Adjacency List) with CRUD Operations**

---

## 👥 Team Members

* Thirumala Reddy
* Jaydeep Ram

---

## ❗ Problem Statement

Airline crew management involves handling multiple crew members and their assignments efficiently.
Traditional methods are not effective for managing complex relationships.
This project uses a **graph data structure** to represent crew members and their connections, allowing efficient **CRUD operations** and assignment handling.

---

## 🧠 Data Structure Used

* Graph (Adjacency List Representation)
* Linked List
* Each Crew Member is a Node
* Each Assignment is an Edge

---

## ⚙️ Algorithm Explanation

1. **Create (Add Crew)**

   * Allocate memory using `malloc()`
   * Insert crew node into list

2. **Read (Display Graph)**

   * Traverse all nodes
   * Display adjacency list

3. **Update (Modify Crew)**

   * Search crew by ID
   * Update name

4. **Delete (Remove Crew)**

   * Find and remove node
   * Free memory using `free()`

5. **Search Crew**

   * Traverse list
   * Match ID and display result

6. **Add Assignment (Edge)**

   * Connect two crew nodes using adjacency list

---

## 💻 Compilation Instructions

### Compile

```bash
gcc crew.c -o crew
```

### Run

```bash
./crew
```

---

## 🧪 Sample Output

```
====================================
 ✈ AIRLINE CREW MANAGEMENT SYSTEM
====================================
1. Add Crew (Create)
2. Delete Crew
3. Update Crew
4. Search Crew
5. Display Graph
6. Add Assignment
7. Exit
====================================
Enter Choice: 1

Enter Crew ID   : 101
Enter Crew Name : Ravi
Crew Added Successfully!
```

---

## 🎥 Demo Video Link

🔗 Add your demo video link here (Google Drive / YouTube)

---
