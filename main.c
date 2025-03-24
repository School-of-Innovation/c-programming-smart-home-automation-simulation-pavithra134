/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define MAX_ROOMS 20 // Define a maximum limit for rooms
 // Function prototypes
 void initializeSystem(int rooms, int lights[], float temperatures[], int motionSensors[], int securityLocks[]);
 void toggleLight(int rooms, int lights[]);
 void readTemperature(int rooms, float temperatures[]);
 void checkMotion(int rooms, int motionSensors[]);
 void securitySystem(int rooms, int securityLocks[]);
 void houseStatus(int rooms, int lights[], float temperatures[], int motionSensors[], int securityLocks[]);
 void simulateRandomEvents(int rooms, int lights[], float temperatures[], int motionSensors[], int securityLocks[]);
 
 int main() {
     int rooms;
     int choice;
     int lights[MAX_ROOMS];
     float temperatures[MAX_ROOMS];
     int motionSensors[MAX_ROOMS];
     int securityLocks[MAX_ROOMS];
     int inputCount = 0;
     // Seed random number generator
     srand(time(NULL));
     printf("Enter number of rooms (maximum %d): ", MAX_ROOMS);
     scanf("%d", &rooms);
     // Validate input
     if (rooms <= 0 || rooms > MAX_ROOMS) {
         printf("Invalid number of rooms. Setting to default (3).\n");
         rooms = 3;
     }
     // Initialize the system
     printf("Initializing system...\n");
     initializeSystem(rooms, lights, temperatures, motionSensors, securityLocks);
     do {
         // Randomly select a menu option occasionally to simulate automated events
         if (rand() % 10 == 0 && inputCount > 0) {
             choice = 1 + rand() % 5; // Random choice between 1 and 5
             printf("\n[AUTO EVENT] System selecting option %d automatically\n", choice);
         } else {
             printf("\n===== Smart Home Menu =====\n");
             printf("1. Toggle Light\n");
             printf("2. Read Temperature\n");
             printf("3. Check Motion Sensor\n");
             printf("4. Lock/Unlock Security System\n");
             printf("5. House Status Summary\n");
             printf("6. Exit\n");
             printf("Enter your choice: ");
             scanf("%d", &choice);
         }
         inputCount++;
         switch (choice) {
             case 1:
                 if (rand() % 10 == 0) {  // 10% chance to toggle a random light
                     int randomRoom = 1 + rand() % rooms;
                     printf("[AUTO] Selecting room %d for light toggle\n", randomRoom);
                     lights[randomRoom - 1] = !lights[randomRoom - 1];
                     printf("Light in Room %d is now %s.\n", randomRoom, (lights[randomRoom - 1] == 1) ? "ON" : "OFF");
                 } else {
                     toggleLight(rooms, lights);
                 }
                 break;
             case 2:
                 readTemperature(rooms, temperatures);
                 break;
             case 3:
                 checkMotion(rooms, motionSensors);
                 break;
             case 4:
                 securitySystem(rooms, securityLocks);
                 break;
             case 5:
                 houseStatus(rooms, lights, temperatures, motionSensors, securityLocks);
                 break;
             case 6:
                 printf("Exiting...\n");
                 break;
             default:
                 printf("Invalid choice! Please try again.\n");
         }
         // Randomly update sensors to simulate environmental changes
         simulateRandomEvents(rooms, lights, temperatures, motionSensors, securityLocks);
     } while (choice != 6);   
     return 0;
 }
 void initializeSystem(int rooms, int lights[], float temperatures[], int motionSensors[], int securityLocks[]) {
     for (int i = 0; i < rooms; i++) {
         // Randomize initial state for demonstration
         lights[i] = rand() % 2; // Randomly ON/OFF
         securityLocks[i] = rand() % 2 == 0 ? 1 : 0; // Mostly LOCKED (higher chance)
         motionSensors[i] = rand() % 5 == 0 ? 1 : 0; // Small chance of motion
         temperatures[i] = 20.0 + (rand() % 10) + ((float)(rand() % 10) / 10.0); // 20-30°C
     }
     printf("System initialized with %d rooms.\n", rooms);   
     // Print initial state
     printf("Initial state:\n");
     for (int i = 0; i < rooms; i++) {
         printf("Room %d: Light %s, Temp %.1f°C, %s, %s\n", 
                i + 1,
                (lights[i] == 1) ? "ON" : "OFF",
                temperatures[i],
                (motionSensors[i] == 1) ? "Motion Detected" : "No Motion",
                (securityLocks[i] == 1) ? "Locked" : "Unlocked");
     }
 }
 void toggleLight(int rooms, int lights[]) {
     int roomNumber;
     printf("Enter room number to toggle light (1-%d): ", rooms);
     scanf("%d", &roomNumber);
     if (roomNumber < 1 || roomNumber > rooms) {
         printf("Invalid room number!\n");
         return;
     }   
     lights[roomNumber - 1] = !lights[roomNumber - 1];
     printf("Light in Room %d is now %s.\n", roomNumber, (lights[roomNumber - 1] == 1) ? "ON" : "OFF");
 }
 void readTemperature(int rooms, float temperatures[]) {
     int roomNumber;
     printf("Enter room number to read temperature (1-%d): ", rooms);
     scanf("%d", &roomNumber);
     if (roomNumber < 1 || roomNumber > rooms) {
         printf("Invalid room number!\n");
         return;
     }
     printf("Temperature in Room %d is %.1f°C.\n", roomNumber, temperatures[roomNumber - 1]);   
     // Occasionally provide temperature trend
     if (rand() % 3 == 0) {
         if (temperatures[roomNumber - 1] > 25.0) {
             printf("The temperature appears to be rising in this room.\n");
         } else if (temperatures[roomNumber - 1] < 22.0) {
             printf("The temperature appears to be dropping in this room.\n");
         } else {
             printf("The temperature is stable in this room.\n");
         }
     }
 }
 void checkMotion(int rooms, int motionSensors[]) {
     int roomNumber;
     printf("Enter room number to check motion (1-%d): ", rooms);
     scanf("%d", &roomNumber);
     if (roomNumber < 1 || roomNumber > rooms) {
         printf("Invalid room number!\n");
         return;
     }
     printf("Motion in Room %d: %s.\n", roomNumber, (motionSensors[roomNumber - 1] == 1) ? "Detected" : "Not Detected");   
     // Occasionally provide extra information
     if (motionSensors[roomNumber - 1] == 1 && rand() % 3 == 0) {
         printf("Motion was first detected %d inputs ago.\n", 1 + rand() % 5);
     }
 }
 void securitySystem(int rooms, int securityLocks[]) {
     int roomNumber;
     printf("Enter room number to toggle lock (1-%d): ", rooms);
     scanf("%d", &roomNumber);
     if (roomNumber < 1 || roomNumber > rooms) {
         printf("Invalid room number!\n");
         return;
     }
     securityLocks[roomNumber - 1] = !securityLocks[roomNumber - 1];
     printf("Security lock for Room %d is now %s.\n", roomNumber, (securityLocks[roomNumber - 1] == 1) ? "LOCKED" : "UNLOCKED");
     // Sometimes trigger security check in other rooms
     if (rand() % 4 == 0) {
         int otherRoom = 1 + rand() % rooms;
         if (otherRoom != roomNumber) {
             printf("[SECURITY] Auto-checking Room %d: %s\n", 
                    otherRoom, 
                    (securityLocks[otherRoom - 1] == 1) ? "Locked" : "Unlocked");
         }
     }
 }
 void houseStatus(int rooms, int lights[], float temperatures[], int motionSensors[], int securityLocks[]) {
     printf("House Status:\n");
     int lightsOn = 0;
     int doorsUnlocked = 0;
     int motionDetected = 0;
     float avgTemp = 0;
     for (int i = 0; i < rooms; i++) {
         printf("Room %d: Light %s, Temp %.1f°C, %s, %s\n", 
                i + 1,
                (lights[i] == 1) ? "ON" : "OFF",
                temperatures[i],
                (motionSensors[i] == 1) ? "Motion Detected" : "No Motion",
                (securityLocks[i] == 1) ? "Locked" : "Unlocked");     
         if (lights[i] == 1) lightsOn++;
         if (securityLocks[i] == 0) doorsUnlocked++;
         if (motionSensors[i] == 1) motionDetected++;
         avgTemp += temperatures[i];
     }
     // Show some analytics occasionally
     if (rand() % 2 == 0) {
         printf("\nSummary Statistics:\n");
         printf("- Lights on: %d/%d rooms\n", lightsOn, rooms);
         printf("- Doors unlocked: %d/%d rooms\n", doorsUnlocked, rooms);
         printf("- Motion detected: %d/%d rooms\n", motionDetected, rooms);
         printf("- Average temperature: %.1f°C\n", avgTemp / rooms);
     }
 }
 void simulateRandomEvents(int rooms, int lights[], float temperatures[], int motionSensors[], int securityLocks[]) {
     // Only make changes occasionally to avoid too much randomness
     if (rand() % 3 == 0) {
         int randomRoom = rand() % rooms;
         // Temperature fluctuations (small natural changes)
         temperatures[randomRoom] += ((rand() % 20) - 10) / 10.0;
         // Random motion detection
         if (rand() % 5 == 0) {
             motionSensors[randomRoom] = !motionSensors[randomRoom];
             if (motionSensors[randomRoom] == 1) {
                 printf("[SENSOR] Motion detected in Room %d.\n", randomRoom + 1);
             }
         }
         // Simulate power flickering sometimes
         if (rand() % 20 == 0) {
             printf("[POWER] Brief power fluctuation detected.\n");
             for (int i = 0; i < rooms; i++) {
                 if (rand() % 3 == 0 && lights[i] == 1) {
                     lights[i] = 0;
                     printf("[POWER] Light in Room %d turned off due to power fluctuation.\n", i + 1);
                 }
             }
         }
         // Simulate weather effects on temperature
         if (rand() % 15 == 0) {
             int weatherEffect = rand() % 3;
             if (weatherEffect == 0) {
                 printf("[WEATHER] It's getting warmer outside.\n");
                 for (int i = 0; i < rooms; i++) {
                     temperatures[i] += 1.0 + (rand() % 10) / 10.0;
                 }
             } else if (weatherEffect == 1) {
                 printf("[WEATHER] It's getting colder outside.\n");
                 for (int i = 0; i < rooms; i++) {
                     temperatures[i] -= 1.0 + (rand() % 10) / 10.0;
                 }
             }
         }
     }
 }