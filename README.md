# This is my followspot i've designed for [highway](https://highway.hackclub.com/)!

<img width="1252" height="1155" alt="image" src="https://github.com/user-attachments/assets/2e0c2ba4-c5c4-41d8-b474-27583e33a3b6" />

A **followspot** is a type of spotlight used in theatre which is manually controlled and pointed at an actor. They normally have brightness and zoom controls, which mine has!

It has:

- An over 100W white LED COB chip for over 17000 lumens of light output (Max. 150W, real max depends on how much heat the led dissipates as i'll have to limit it so it can't overheat and die)
- An upcycled camera lens no longer good enough for photography but perfect for a beam of light
- Motorised lens control with manual control if desired and zoom recall
- Digital constant current LED dimming (so no flickering from PWM)
- USB-C for computer control of brightness and zoom
- Fully open source everything
- 3 programmable buttons and a fader
- Automatic brightness reduction if the LED gets too hot
- An LED on the control panel to give feedback, like if the LED is too hot or the lens is being pushed too far

The body is 3D printed in PETG but it could be made out of a better material if you feel like it, and the legs are plywood, and of course the lens is glass.

Here's the onshape link! https://cad.onshape.com/documents/9e98bdcd2562c04de815ecc5/w/89c7868c82d5394c068b4491/e/8808e6d7c01ac629712aeab9?renderMode=0&uiState=6882b91ba27d1511c88b3310

## Why?

I wanted my GCSE Design and Technology project to be a spotlight, but my DT teacher said no and told me to downsize it to a desk lamp. It got me a good grade, but it's not what I wanted to make, so I'm taking the opportunity to make what I want to make, with an LED bright enough to blind my DT teacher! (/j....) I'm going to take inspiration from my project, as I do like the general hexagonal design of it (see below)

![PXL_20250429_132238411 MP](https://github.com/user-attachments/assets/a4d03a03-815c-40e6-a3f4-aa352178debc)

I have a passion for the technical parts of theatre, so making this was rather an obvious choice for me

## PCB

![PCB](PCB/PCB.png)

## Wiring Diagram

(Made in GIMP :))

![wiring_diagram](wiring_diagram.png)

## More pictures :)

<img width="1521" height="891" alt="image" src="https://github.com/user-attachments/assets/b6aa2b4b-9660-4e9b-a312-62ae864c1feb" />

<img width="1844" height="1171" alt="image" src="https://github.com/user-attachments/assets/abd6726a-9022-4b92-bd9f-f4975d2ffcc6" />

<img width="908" height="1090" alt="image" src="https://github.com/user-attachments/assets/74bd0cb7-8099-4499-b20b-4e23db17041d" />


# Bill of Materials

| Vendor         | Name (link)                          | Description                                                                | Price (Digikey With VAT) | Price (Local)       | Price (LCSC)  | Price(Other)    | Notes                                                                                                         |
| -------------- | ------------------------------------ | -------------------------------------------------------------------------- | ------------------------ | ------------------- | ------------- | --------------- | ------------------------------------------------------------------------------------------------------------- |
| digikey        | ELG-150-54B                          | 150W 54V led driver                                                        | x 37.94                  |                     | x             |                 | BACKORDER NEEDS BUYING, LEAD TIME CURRENTLY 13/06/2025                                                        |
| digikey        | XLG-150-H-AB                         | 150W 27-56V led driver                                                     | £31.04                   |                     | x             |                 |                                                                                                               |
| LCSC           | IRM-10-5                             | 10W 5V psu                                                                 | x 6.38                   |                     | $4.32         |                 |                                                                                                               |
| digikey        | SMU02L-12                            | 2W 5v to 12v converter                                                     | x 3.54                   |                     | x?            |                 |                                                                                                               |
| digikey        | SPU03L-12                            | 3W 5v to 12v conerter                                                      | £4.51                    |                     |               |                 |                                                                                                               |
| digikey        | L2C5-40801825G3200                   | 51.7V ~116W LED                                                            | £34.15                   |                     | x             |                 |                                                                                                               |
| digikey        | Schurter OGN Fuse holder             | 5x20mm fuse holder                                                         | x 1.04                   |                     | x?            |                 |                                                                                                               |
| digikey        | K104K15X7RF5TL2                      | 0.1uF tht capacitor                                                        | £0.22                    |                     |               |                 |                                                                                                               |
| digikey        | "885012210006"                       | 10nF smt capacitor                                                         | £0.46                    |                     |               |                 |                                                                                                               |
| digikey        | PTA6043-2010CIB502                   | 5K slide potentiometer                                                     | £1.70                    |                     | x?            |                 |                                                                                                               |
| digikey        | 240-080                              | 1m K-type thermocouple bare wires                                          | x 8.86                   |                     | x             |                 |                                                                                                               |
| LCSC           | ETA-G-K-24-200cm                     | 2m K-type thermocouple bare wires                                          |                          |                     | $4.56         |                 |                                                                                                               |
| LCSC           | MAX31855KASA+T                       | MAX31855 thermocouple amplifier chip                                       | x 8.28                   |                     | $2.33         |                 |                                                                                                               |
| digikey        | Wuerth elektronik screw pin terminal | Screwy terminal block for 2 pins for thermocouple                          | £0.32                    |                     |               |                 |                                                                                                               |
| digikey        | xiao rp2040                          | xiao rp2040 microcontroller                                                | £4.15                    |                     | x             |                 |                                                                                                               |
| digikey        | PC817X2NSZ9F                         | pc817 optocoupler/optoisolator                                             | £0.24                    |                     | x $0.38=£0.28 |                 | (LCSC minimum order quantity is 5, for just one it would be $0.07 but alas)                                   |
|                |                                      | 40 ohm resistor for led                                                    | (I have already)         |                     |               | £0.05           | (estimate price)                                                                                              |
|                |                                      | Red led                                                                    | (I have already)         |                     |               | ~5p if you buy? |                                                                                                               |
|                |                                      | 80-100 ohm resistor for optocoupler                                        | (will get locally)       |                     |               | £0.05           | (estimate price)                                                                                              |
|                |                                      | 3x cherry style keyboard switches and keycaps                              | (I have already)         |                     |               | ~5p if you buy? |                                                                                                               |
|                |                                      | 2.5A fuse - possibly 5x20mm                                                | (will get locally)       |                     |               | £0.10           | (estimate price)                                                                                              |
|                |                                      | SG90 servo motor                                                           | (I have already)         |                     |               |                 |                                                                                                               |
| LCSC           | DAC-13F                              | iec panel mount input with fuse integrated                                 | x 1.45                   |                     | $1.46         |                 | LCSC one has a switch too!                                                                                    |
| digikey        | xiao pin headers                     | 7 pin headers for xiao rp2040, as well as for the servo                    | £0.22                    | (might get locally) |               |                 |                                                                                                               |
| digikey        | molex 47053-1000                     | 4 pin fan header                                                           | £0.43                    |                     | x             |                 |                                                                                                               |
| digikey        | ATS-HP-F9L200S70W-014                | 200mm long 10.5mm wide ~60W heat pipe - 3 OF THEM                          | £12.90                   |                     |               |                 |                                                                                                               |
| AMAZON         | 1kg Creality Black PETG filament     | 1kg black PETG creality filament, i need it for the better heat resistance |                          |                     |               | x 12.99         |                                                                                                               |
| amazon         | 1kg sunlu black petg filament        | 1kg black PETG sunlu filament, for more heat resistance                    |                          |                     |               | £8.75           | (i'm splitting the cost with a friend so i only get 1kg and pay £8.75 for it, normally it would be about £12) |
| fb marketplace | Cooler master hyper 212 evo          | heatsink with fan                                                          |                          |                     |               | £10.00          |                                                                                                               |
| amazon         | 10g Silicone EC360 Thermal Glue      | Thermally conductive adhesive for attaching heat pipes                     |                          |                     |               | £5.99           |                                                                                                               |
|                |                                      | 50x85mm 3mm mdf                                                            |                          |                     |               | free            |                                                                                                               |
|                |                                      | about 40 m4 bolts and nuts (12mm long mostly but some might be longer)     |                          |                     |               | £6              | (estimate price)                                                                                              |
|                |                                      | 2 m10 bolts and nuts                                                       |                          |                     |               | £6.00           |                                                                                                               |
|                |                                      | about 400x200mm of thick plywood                                           |                          |                     |               | free            |                                                                                                               |
| JLCPCB         |                                      | The pcb!!!                                                                 |                          |                     |               | £12.00          |                                                                                                               |
|                |                                      |                                                                            |                          |                     |               |                 |                                                                                                               |
|                |                                      |                                                                            |                          |                     |               |                 |                                                                                                               |
|                |                                      |                                                                            |                          |                     | $12.45        |                 | Just parts cost                                                                                               |
| shipping stuff |                                      |                                                                            |                          |                     | $10.40        |                 | Shipping cost                                                                                                 |
| Total          |                                      |                                                                            | £90.34                   |                     | $22.85=£16.73 | £48.94          | £156.01                                                                                                       |
|                |                                      |                                                                            |                          |                     | cheaper!      |                 |                                                                                                               |
| Total total    | (manual value input)                 |                                                                            |                          |                     |               |                 | $209.51                                                                                                       |

(I am willing to cover the amount i've gone over budget if i have to)
