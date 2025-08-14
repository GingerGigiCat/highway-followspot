# HIGHLIGHT!

## Highlight is my followspot i've designed for hack club's [highway](https://highway.hackclub.com/) hardware event

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
- A light on the control panel to give feedback, like if the main LED is too hot or the lens is being pushed too far

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
| digikey        | [XLG-150-H-AB ](https://www.digikey.co.uk/en/products/detail/mean-well-usa-inc/XLG-150-H-AB/10222586)                        | 150W 27-56V led driver                                                     | £31.04                   |                     | x             |                 |                                                                                                               |
| LCSC           | [IRM-10-5](https://lcsc.com/product-detail/Power-Module-Power-Supply_MW-MEAN-WELL-Enterprises-IRM-10-5_C2857903.html?s_z=n_IRM-10-5)                             | 10W 5V psu                                                                 | x 6.38                   |                     | $4.32         |                 |                                                                                                               |
| digikey        | [SPU03L-12](https://www.digikey.co.uk/en/products/detail/mean-well-usa-inc/SPU03L-12/7707058)                            | 3W 5v to 12v conerter                                                      | £4.51                    |                     |               |                 |                                                                                                               |
| digikey        | [‎CXM-32-50-80-54-AC00-F2-5‎](https://www.digikey.co.uk/en/products/detail/luminus-devices-inc/CXM-32-50-80-54-AC00-F2-5/5811014)                | 50-56V up to 200W LED                                                       | £21.78                   |                     | x             |                 |                                                                                                               |
| digikey        | [K104K15X7RF5TL2](https://www.digikey.co.uk/en/products/detail/vishay-beyschlag-draloric-bc-components/K104K15X7RF5TL2/286538)                      | 0.1uF tht capacitor                                                        | £0.22                    |                     |               |                 |                                                                                                               |
| digikey        | ["885012210006"](https://www.digikey.co.uk/en/products/detail/w%C3%BCrth-elektronik/885012210006/5453247)                       | 10nF smt capacitor                                                         | £0.46                    |                     |               |                 |                                                                                                               |
| digikey        | [PTA6043-2010CIB502](https://www.digikey.co.uk/en/products/detail/bourns-inc/PTA6043-2010CIB502/3781226)                   | 5K slide potentiometer                                                     | £1.70                    |                     | x?            |                 |                                                                                                               |
| LCSC           | [ETA-G-K-24-200cm](https://lcsc.com/product-detail/Electronic-testing-accessories_ETA-ETA-G-K-24-200cm_C5144202.html?s_z=n_ETA-G-K-24)                    | 2m K-type thermocouple bare wires                                          |                          |                     | $4.56         |                 |                                                                                                               |
| LCSC           | [MAX31855KASA+T](https://lcsc.com/product-detail/ADCs-DACs-Special-Purpose_Analog-Devices-Inc-Maxim-Integrated-MAX31855KASA-T_C52028.html)                       | MAX31855 thermocouple amplifier chip                                       | x 8.28                   |                     | $2.33         |                 |                                                                                                               |
| digikey        | [Wuerth elektronik screw pin terminal](https://www.digikey.co.uk/en/products/detail/w%C3%BCrth-elektronik/691137710002/6644051) | Screwy terminal block for 2 pins for thermocouple                          | £0.32                    |                     |               |                 |                                                                                                               |
| digikey        | [xiao rp2040](https://www.digikey.co.uk/en/products/detail/seeed-technology-co-ltd/102010428/14672129)                          | xiao rp2040 microcontroller                                                | £4.15                    |                     | x             |                 |                                                                                                               |
| digikey        | [PC817X2NSZ9F](https://www.digikey.co.uk/en/products/detail/sharp-socle-technology/PC817X2NSZ9F/7942022)                         | pc817 optocoupler/optoisolator                                             | £0.24                    |                     | x $0.38=£0.28 |                 | (LCSC minimum order quantity is 5, for just one it would be $0.07 but alas)                                   |
|                |                                      | 40 ohm resistor for led                                                    | (I have already)         |                     |               | £0.05           | (estimate price)                                                                                              |
|                |                                      | Red led                                                                    | (I have already)         |                     |               | ~5p if you buy? |                                                                                                               |
|                |                                      | 80-100 ohm resistor for optocoupler                                        | (will get locally)       |                     |               | £0.05           | (estimate price)                                                                                              |
|                |                                      | 3x cherry style keyboard switches and keycaps                              | (I have already)         |                     |               | ~5p if you buy? |                                                                                                               |
|                |                                      | 2.5A fuse - possibly 5x20mm                                                | (will get locally)       |                     |               | £0.10           | (estimate price)                                                                                              |
|                |                                      | SG90 servo motor                                                           | (I have already)         |                     |               |                 |                                                                                                               |
| LCSC           | [Legion RT-C14B-H1+SS11-1BB](https://lcsc.com/product-detail/AC-Power-Connectors_Legion-RT-C14B-H1-SS11-1BB_C22379821.html?s_z=n_c14%2520input)           | iec panel mount input with fuse and switch integrated                                 | x 1.45                   |                     | $1.46         |                 | LCSC one has a switch too!                                                                                    |
| digikey        | [xiao pin headers](https://www.digikey.co.uk/en/products/detail/seeed-technology-co-ltd/102010490/19176770)                     | 7 pin headers for xiao rp2040, as well as for the servo                    | £0.22                    | (might get locally) |               |                 |                                                                                                               |
| digikey        | [molex 47053-1000](https://www.digikey.co.uk/en/products/detail/molex/0470531000/2421261?s=N4IgTCBcDaICwHYAMBWAzAWgIxNyAugDQgpSgAOUWx5lkOSAvo0A)                     | 4 pin fan header                                                           | £0.43                    |                     | x             |                 |                                                                                                               |
| digikey        | [ATS-HP-F9L200S70W-014](https://www.digikey.co.uk/en/products/detail/advanced-thermal-solutions-inc/ATS-HP-F9L200S70W-014/5049697?s=N4IgjCBcoOw1oDGUBmBDANgZwKYBoQB7KAbRACYYwA2SkAXQIAcAXKEAZRYCcBLAOwDmIAL4EwATgDMCEMkjps%2BIqQrkALBOoNmbSJx4DhIk0A)                | 200mm long 10.5mm wide ~60W heat pipe - 3 OF THEM                          | £12.90                   |                     |               |                 |                                                                                                               |
| amazon         | [1kg sunlu black petg filament](https://www.amazon.co.uk/SUNLU-Filament-Tangle-Free-Dimensional-Accuracy/dp/B0D1KC72YP)        | 1kg black PETG sunlu filament, for more heat resistance                    |                          |                     |               | £8.75           | (i'm splitting the cost with a friend so i only get 1kg and pay £8.75 for it, normally it would be about £12) |
| fb marketplace | Cooler master hyper 212 evo          | heatsink with fan                                                          |                          |                     |               | £10.00          |(no link so i don't doxx myself but i promise it's £10)                                                        |
| amazon         | [10g Silicone EC360 Thermal Glue](https://www.amazon.co.uk/EC360%C2%AE-Glue-Thermal-Adhesive-Liquid/dp/B00XQ9AZ8Y)      | Thermally conductive adhesive for attaching heat pipes                     |                          |                     |               | £5.99           |                                                                                                               |
|                |                                      | 50x85mm 3mm mdf                                                            |                          |                     |               | free            |                                                                                                               |
|                |                                      | about 40 m4 bolts and nuts (12mm long mostly but some might be longer)     |                          |                     |               | £6              | (estimate price)                                                                                              |
|                |                                      | 2 m10 bolts and nuts                                                       |                          |                     |               | £6.00           |                                                                                                               |
|                |                                      | about 400x200mm of thick plywood                                           |                          |                     |               | free            |                                                                                                               |
| JLCPCB         |                                      | The pcb!!!                                                                 |                          |                     |               | £12.00          |                                                                                                               |
|                |                                      |                                                                            |                          |                     |               |                 |                                                                                                               |
|                |                                      |                                                                            |                          |                     |               |                 |                                                                                                               |
|                |                                      |                                                                            |                          |                     | $12.45        |                 | Just parts cost                                                                                               |
| shipping stuff |                                      |                                                                            |                          |                     | $10.40        |                 | Shipping cost                                                                                                 |
| Total          |                                      |                                                                            | £78.18                   |                     | $22.85=£16.73 | £48.94          | £141.64                                                                                                       |
|                |                                      |                                                                            |                          |                     | cheaper!      |                 |                                                                                                               |
| Total total    | (manual value input)                 |                                                                            |                          |                     |               |                 | $190.49                                                                                                       |

(I am willing to cover the amount i've gone over budget if i have to)
