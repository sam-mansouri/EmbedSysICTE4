# EmbedSysICTE4
ICTE 4: Round-Robin Scheduler
Objective: Create a simple round-robin scheduler that runs three independent tasks on the ESP32-S3 using the Arduino IDE.
Tasks include:

    Task 1: Flash LED1 at a fixed interval

    Task 2: Flash LED2 at a different interval

    Task 3: Read an analog potentiometer value and print it to the Serial Monitor

What is not allowed:

    delay () 

What is allowed:

    millis()
    all arduino macros (including pinmode() and digitalwrite())

Bonus:

Avoid using pinmode(), millis(), digitalwrite() and use the GPIO registers


What to turn:

A single well-commented .ino file.
