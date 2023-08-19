# Simple-ATM-machine
## Project Description:
This project aims to design and develop an Automated Teller Machine (ATM) system that simulates the main functionalities of a real-world ATM, including card insertion, PIN verification, transaction authorization, and balance update.<br />
The system consists of two microcontroller units (MCUs) - one for the ATM and the other for the card - that communicate with each other to execute the transaction process.<br />
### Hardware Components
Two ATmega32 Microcontrollers (one for the ATM machine and one for the Card).<br />
LCD <br />
EEPROM<br />
Keypad<br />
Serial Terminal<br />
Buzzer<br />
Button<br />
## Project sequence :
• The ATM MCU will handle the transaction main flows, including displaying welcome messages, requesting card insertion, entering PIN, and validating transactions.<br />
• The CARD MCU has two modes of operation - programming and user mode. In programming mode, the MCU will request the user to enter the card PAN and PIN and store them in the EEPROM. In user mode, the CARD MCU will send a trigger signal to the ATM MCU to initiate the transaction flow.<br />
• The project uses a hard-coded array of structures for accounts that contain the PAN, account state (blocked/running), and balance.<br />
• The maximum allowed limit for a transaction is hardcoded as $5000.00.<br />
• The system will perform several checks on the database before finalizing the transaction, including verifying the card PAN, checking if the card is blocked, checking if the amount required exceeds the maximum daily limit, and verifying the available balance.<br />
• If all checks pass, the system will display the remaining balance and eject the card. If any check fails, the system will display a declined message accordingly and initiate an alarm if necessary.<br />
