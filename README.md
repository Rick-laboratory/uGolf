#Author: Rick Armbruster
# uGolf
uGolf Development
![Image description](http://u.cubeupload.com/GreatBullet/Thumbnail.png)
# 25.02.2020 new Update in Sight. 
Pretaste http://u.cubeupload.com/GreatBullet/vorgeschmack.png
# 26.02.2020 Dependency Injection Concerns in Mind
Although it happened that i already used it somewhere in the past i got a serious hint about its usefullness on a great Interview today.
As my programming is a Target of Improovement, i appreciate it alot. <br>
Lets move on. <br>
The Approach i have in Mind will be the Constructor DI
# 02.03.2020 Update Time it needs to be Commited
Refactorisation of Code has been done, it should seem selfexplainatory now. <br>
# 03.03.2020 A noteworthy Article which explains some of my Ideas of allocating everything upfront in RealTimeCritical Enviroments
Some people even tried to accuse me i would be wrong when i talked about it, maybe some C# or Java Devs i guess.<br>
(No offense, just Rational because of the managed Aspects of those Languages).<br>
Its called RAM for a Reason was my answer to this, and allocating Memory within the logical Part of Software is not the way to go if you want a smooth Transition from Procedure to Procedure.<br>
https://www.embedded.com/how-to-make-c-more-real-time-friendly/ <br>
An Implementation will follow, because the Code of uGolf consists of alot of Allocations within the Logical Part.<br>
For the simple Reason of limited Time.
Translation for the UI will follow too but, its a Minor Concern.


# Furthermore Implementation Details, subject to change for an improoving experience.
Serial Communication over UART[B9600] Between the Pi and the M8P-2-11 Works like a charm and is implementet within the SerialManager Class.<br>
Basic Data management Functionality has been implemented within the DataManager Class.<br>
<br>
Current Implementation Design foresees the MainWindow Class as Bay for further Implementations.

# M8P-2-11 Configuration
[NMEA] High Precision <br>
[Port] UART 1 [ALL Possible NMEA Protocolls]<br>
Details about how to configure the Chip over u-Blox u-Center will follow in future   
