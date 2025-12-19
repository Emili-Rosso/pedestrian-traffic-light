# 🚦 Pedestrian Traffic Light System
  
This project implements a pedestrian traffic light system using an Arduino. The system allows pedestrians to safely cross the street by pressing a request button, which triggers a sequence of traffic light changes for vehicles and pedestrians. A 7-segment display shows the remaining crossing time, giving pedestrians clear feedback on how long they have to cross safely.

It demonstrates the use of digital input handling, non-blocking timing control, and state-based logic in Arduino programming. It is a practical example of how to combine sensors, outputs, and timing in embedded systems.

# 🛠️ Components 

  ▫️Arduino Uno (or compatible board);

  ▫️	3 LEDs for vehicle traffic lights (Red, Yellow, Green);

  ▫️	2 LEDs for pedestrian traffic lights (Red, Green);

  ▫️	7-segment display;

  ▫️	Push button (pedestrian request);

  ▫️	Resistors (for LEDs and button pull-down);

  ▫️	Breadboard and jumper wires.

# ⚙️ How It Works
  1.	Normal Operation:

  •	Vehicle traffic light remains green while no pedestrian request is made.

  • Pedestrian light remains red.

2.	Pedestrian Request:

  •	When the pedestrian presses the button, the system waits for a safe moment to interrupt the vehicle green light.

  •	Vehicle lights change to yellow and then red.

  •	Pedestrian light turns green, and the 7-segment display shows the remaining crossing time.

3.	Crossing Timer:

  •	The pedestrian has 10 seconds to cross.

  •	The 7-segment display shows a countdown from 9 to 0, indicating the remaining time to cross safely.

4.	Return to Normal:

  •	After the timer ends, pedestrian light turns red.    

  •	Vehicle light returns to green, resuming normal operation.
