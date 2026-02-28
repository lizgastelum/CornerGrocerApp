# Corner Grocer Application

A C++ application for analyzing grocery purchase frequency data from a transaction log.

## Overview
The Corner Grocer Application processes a text file containing grocery store purchase records and computes the frequency of each item. It provides a menu-driven interface that allows users to:
* Search for the frequency of a specific item.
* Display all item frequencies.
* Generate a histogram-style output.
* Persist frequency data to a backup file.

This project demonstrates structured program design, file I/O handling, data normalization, and modular C++ development using CMake.

## Problem Statement
Small retail businesses benefit from understanding purchasing trends. However, raw transaction logs are difficult to interpret without aggregation. This program addresses that problem, by reading purchase data and computing item frequency counts, making it easier to identify high-demand products and support inventory decisions.

## Reflection
This project is organized using a modular design with clearly defined responsabilities:
* `ItemFrequency` manages frequency calculations and data storage.
* `Menu` handles user interaction and input validation.
* `FrequencyPrinter` formats output for display.
* `FrequencyBackupWriter` writes computed data to a file.

Separating concerns reduced complexity and improved readability. Input validation was implemented within the menu loop, and item names were normalized to ensure consistent lookups.

## Areas for Enhancement
Several improvements could strengthen the implementation:
* **Improve Error Handling:** More robust validation for file access and malformed input.
* **Automated Testing:** Unit tests would improve reliability and simplify regression detection.
* **Configuration Flexibility:** Allowing configurable input/output file paths rather than hardcoding values.
* **Scalability Consideration:** While sufficient for small datasets, algorithmic and data structure optimizations could be evaluated for larger inputs.

These improvements would make the program more robust, scalable, and production-ready.

## Most Challenging Components
The most challenging aspects of this project were:
* Designing consistent frequency insertion logic.
* Implementing string normalization for accurate lookup.
* Building a stable menu loop with validated user input.

These challenges were addressed through iterative testing, careful review of STL container behaviour, and refining the control flow until edge cases were handled correctly. Reviewing official C++ documentation and debugging step-by-step execution were particularly helpful.

## Transferable Skills
This project reinforced several skills applicable to future coursework and software development:
* File input and output operations.
* Use of STL containers for data aggregation.
* Modular class-based design.
* Input validation and defensive programming.
* Build configuration using CMake.
* Structured commit management in Git.

These fundamentals are transferable to backend systems, data processing tools, and larger object-oriented applications.

## Maintainability, Readability, and Adaptability
The program was structured for maintainability by:
* Separating functionality into discrete classes.
* Maintaining header and source file separation.
* Using consistent naming conventions.
* Avoiding unecessary global state.
* Structuring logic to minimize duplication.

This architecture allows additional features (such as new reporting formats or data sources) to be implemented without major restructuring.

## Build Instructions
This project uses CMake.
```bash
mkdir build
cd build
cmake ..
make
./CornerGrocerApp
```
## Project Status
This project was completed as part of a Computer Science course assignment and meets all final project requirements. The core functionality is complete and stable. Incremental refinements, including performance optimization and expanded testing, may be implemented over time.
