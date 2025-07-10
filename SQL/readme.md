# 📚 SQL Study Notes

## 🔍 What is SQL?
- SQL stands for Structured Query Language.
- It is used to communicate with databases.
- It helps me ask queries and give instructions to a database.

---

## 🗄️ Database
A database is a place where we store data in an organized way so that we can easily add, update, delete, or find the data whenever needed.

### 📊 Types of Databases

#### 1. Relational Databases (SQL):
- Stores data in tables like rows and columns, and we use SQL to manage the data.
- The structure is fixed
- Different tables can be connected using keys.
- **Examples:** MySQL, PostgreSQL, and Oracle

#### 2. Non-Relational Databases (NoSQL):
- Stores data in formats like JSON or key-value pairs
- They don't require a fixed structure and are good for handling large or flexible data.
- **Examples:** MongoDB, Redis

### Main Difference:
Relational databases are structured and use SQL. Non-relational databases are more flexible and are used when the data format can change or grow very large.

---

## 🔑 Key Concepts

### Primary Key
- A primary key is a column, or a group of columns, in a table that is used to uniquely identify each row.
- It cannot be null

### Foreign Key
- A foreign key links two tables by referring to the primary key in another table. 
- It helps maintain relationships between data in different tables.

---

## 🔄 Primary Key vs Unique Key

### What is the difference between a primary key and a unique key?
A primary key is used to uniquely identify each row in a table. It cannot have duplicate or NULL values, and there can be only one primary key in a table.

A unique key also ensures that values are unique, but it can allow NULLs, and we can have multiple unique keys in a table.

**Example:** In a students table, student_id can be the primary key, and email can be a unique key.

---

## 📐 Normalisation
Normalization is the process of organizing data in a database to reduce redundancy (duplicate data) and improve data consistency.

**In simple words:**
We break big, messy tables into smaller, clean tables — and link them using keys.

---

## 🔗 What is a join
A JOIN in SQL is used to combine data from two or more tables based on a related column.
The main types of joins are:

- **INNER JOIN**: returns only matching rows.

- **LEFT JOIN**: returns all rows from the left table and matches from the right.

- **RIGHT JOIN**: returns all rows from the right table and matches from the left.

- **FULL JOIN**: returns all rows from both tables.

---

## 🗑️ What is the difference between DELETE and TRUNCATE in SQL

**DELETE**:
- Used to remove specific rows from a table using a WHERE clause. 
- It can be rolled back (undone) if not committed.
- It doesn't reset auto-increment values.

**TRUNCATE**:
- Used to delete all rows at once — super fast!
- It cannot delete selected rows, usually cannot be rolled back.
- Resets auto-increment back to 1.

For example, DELETE FROM students WHERE name = 'Riya'; deletes only Riya's row, while TRUNCATE TABLE students; deletes all students at once.

---

## 🔄 What is the difference between UNION and UNION ALL

The difference between UNION and UNION ALL is that:

**UNION**:
- Combines the results of two SELECT queries and removes duplicate rows.
- Takes more time because it removes duplicates by sorting and comparing.

**UNION ALL**:
- Combines the results and includes duplicates.
- Faster as it just stacks the results without checking for duplicates.

---

## 🔍 What is the difference between the HAVING clause and the WHERE clause?

**WHERE clause**:
- Used to filter rows based on a condition before the data is grouped or aggregated.
- Operates on individual rows.

**HAVING clause**:
- Used to filter grouped rows based on a condition after the data is grouped or aggregated using the GROUP BY clause.
- Operates on grouped results.


**In one line:**
> 🧽 WHERE filters before data is grouped.
> 
> 🧼 HAVING filters after data is grouped.
