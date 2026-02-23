## **SETUP**

I created 3 child processes with tickets counts of:
P1 = 1 ticket
P2 = 2 tickets
P3 = 7 tickets

So my ideal CPU share should be as follows:
P1 = 10%
P2 = 20%
P3 = 70%

I created a program lotteryratio.c to test my lottery scheduler, it creates a total of 3 child processes with a ticket allocation of {1, 2, 7}

## **RESULTS**

My program output:
Tickets = 1 Work = 192778 Share = 18%
Tickets = 2 Work = 380677 Share = 36%
Tickets = 7 Work = 481613 Share = 45%

Which indicates that my lottery scheduler runs properly (higher ticket number has higher share %), however its not an exact match with the ideal % due to randomness and a finite duration time.

Over longer durations or with larger number of lottery draws, it would be expected that these shares converge closer to the expected ratios. I could also scale ticket numbers to reduce rounding errors, or I could implement a kernel side counter for improvements in measurement accuracy.

