# Hospital-Management-System

Overview
This project implements a Hospital Management System (HMS) in C++. It allows users to manage patient appointments, doctor details, and billing information.

Features
Patient Management: Capture patient details including name, age, gender, health issue, previous surgery, and treatment type.

Doctor Management: Record doctor details such as name, age, specialization, and experience.

Appointment Scheduling: Schedule appointments with specific dates and times.

Billing: Calculate and display bills including consultation fees, treatment costs, medication costs, and applicable taxes.

Classes
Person: Base class for both Patient and Doctor classes, containing common attributes like name and age.

Patient: Inherits from Person, includes additional attributes related to health issues and treatment details.

Doctor: Inherits from Person, includes specialization and experience attributes.

Billing: Manages billing details such as consultation fees, treatment costs, medication costs, and tax calculations.

Appointment: Combines Patient, Doctor, Billing, and appointment details into a single entity for scheduling.

Usage
Setup: Compile and run the program using a C++ compiler (e.g., g++).

Input: Follow the prompts to enter patient details, doctor details, appointment details, and billing information.

Output: View appointment details and calculated bills, including tax.

Error Handling
The program includes basic error handling for incorrect input types and logical checks (e.g., doctor's experience cannot exceed their age).

Dependencies
Standard C++ libraries only. No additional dependencies required.

How to Use
Clone the repository.

Compile the main.cpp file using a C++ compiler.

Run the executable file generated.

Follow the prompts to manage patient appointments.

Contributors
Tarun Goli 
