## Time so far: 3 + 1 + 2.5 + 1.5 + 1 + 3 + 1 + 4 + 2 + 1 + 1.5 + 3 + 3.5 =  28 hours

# Saturday 17 May 2025 - 19:00 - 3 hours

So I've been wanting to make a spotlight for a while. I had planned for my GCSE Design & Technology project to be a spotlight, so I did research including a questionnaire on what people look for in a spotlight, and I upcycled a camera lens which is unsuitable for a camera but it works great to put light through. However, my teacher decided no and told me to make a desk lamp in the style of a spotlight. No lens, no very bright LED, and nothing over 9V. And it got me a good grade, but it's underwhelming and it isn't what I wanted to make.

Therefore, I want to properly go through with designing and creating a real, bright, functioning spotlight, taking inspiration from my desk lamp (the desk lamp is below)

![PXL_20250429_132217899 MP](https://github.com/user-attachments/assets/f220c4f3-c412-4063-a57d-dff0d6522912)
![PXL_20250501_122556802 MP](https://github.com/user-attachments/assets/2281e163-336d-49d5-bc21-3409a2349f29)

I am also inspired by the [beacon](https://hackclub.slack.com/archives/C0266FRGV/p1723503357605259) that [ruckusmatter](https://hackclub.slack.com/team/U06TZK6EKU6) made during arcade, and i'd like it include a way for my spotlight to have a perfectly straight beam. For reference, the beacon is 17,000 lumens and its colour temperature is 5600k.
![image](https://github.com/user-attachments/assets/d08b8b45-19fc-4a85-a123-553740619cb2)

Oh also, the 9/11 memorial [Tribute In Light](https://en.wikipedia.org/wiki/Tribute_in_Light) also inspired me

I've been researching LEDs and PSUs. I've been looking on mouser electronics, and I found 2 LEDs that particularly stand out to me.
[One of them](https://www.mouser.co.uk/ProductDetail/Cree-LED/CMB3090-R050-000Q0H0A40G?qs=T%252BzbugeAwjgZC0QsY%2FU%2F9w%3D%3D) is by CREE, a well-known and reliable LED manufacturer, so I should be able to rely on it. This one is 48V, which is nice as it is a rather common voltage, and it produces 12,488 lumens and has a colour temperature of 4000k, which is a more pleasant, warmer shade of white than the spotlight. However, I am unsure about this LED as not only is it less bright than the beacon, it also has some conflicting information as it says  it is 1.2A, but that it is 82W, which can not both be true with a voltage of 48V.

[This other LED](https://www.mouser.co.uk/ProductDetail/Lumileds/L2C5-40801825G3200?qs=T3oQrply3y8Ak6%2FCD8N%252BaQ%3D%3D), by Lumileds seems like it could be better. It is 51.7V at 2.25A and 116W, producing 17,075 lumens, with the same 4000k colour temperature. It should be very bright, however I don't know if it would be the same true light output as the beacon because of the potential for light loss, especially since the lens will have to be a distance away from the light in order to get a straight beam. However, the higher power requirements and weird voltage means finding a suitable power supply may be more difficult.

In terms of powering the LED, I was initially planning to just have a dc power supply of the needed voltage, then allow dimming the LED by using pwm with a MOSFET. I learned that using PWM might not be the best idea though with that much power. Instead a constant current dimmable LED power supply, like [this one](https://www.mouser.co.uk/ProductDetail/MEAN-WELL/ELG-100-48B?qs=n51ddIYULBkC86Em3tr4DQ%3D%3D) from the reputable power supply brand Mean Well. It's got 2 pins which are used for dimming, with 3 options for how to dim the LED. It can be done by: giving it a constant voltage from 0-10V, giving it PWM at 10V, and applying a resistance between the two pins. I'm not sure which of these is the best option, as I don't know of a microcontroller that can produce pwm at 10V, or give a constant variable voltage as high as 10V. This is something I will need to think about.

I would like to have motor controlled zooming of the lens, but I would also like to have the option to control it manually when I want to. For example, it would be great if I could just press a button and have the lens snap into place to give a perfectly straight beam, and be able to save a certain beam angle to repeat later. But also, when manually using it as a followspot, it can be much more convenient and intuitive to physically move a handle which moves the lens. Perhaps I could do this using the same kind of thing as how the extruder on my 3d printer is moved, I think using a belt. It can be moved freely by hand when it's off, but when it's on it is locked in place and I can't move it.



# Monday 19 May 13:00 - 1 hour

I was looking into how I would control the brightness. I was initially thinking I would need 3 power supplies in total, one for the microcontroller, one for the 10V PWM signal, and the LED driver. I thought I would have to use a MOSFET or transistor in order to control the PWM. However I then searched for how to dim a meanwell led driver in particular, and i found [this forum answer](https://electronics.stackexchange.com/a/563669) where they suggest using an optocoupler, which apparently works. An optocoupler is a small box for electrically isolating two circuits, containing an LED and a light dependent resistor. When the LED turns on, the LDR lets current 
 through on the other side. Therefore I can generate a PWM signal for the brightness, and it can go into the optocoupler and from the optocoupler into the dimming pins of the LED driver. I will need to look at the datasheet of the optocoupler I choose, to check the voltage and current needed so that I can choose the correct resistor value, as too much current will kill the LED inside.

I also thought a bit more about how I'm going to move the lens. I think I will house the lens in a tube inside the outer tube, and then move that tube in and out of the outer tube. I think this could be digitally controlled by using potentially a servo and a rack and pinion (image below) to convert the rotary movement of the servo into a linear movement of the tube. It would be good if the servo includes an encoder, so I can find what rotation the servo is at. Using that data I could then include code to compensate for how the brightness of the beam changes when the lens is moved, because as the lens is moved closer to the focal point, the beam gets brighter, which may not be wanted in some situations.

# Monday 19 May 16:00-17:30  18:00-18:30  19:00-19:30 - 2.5 hours

:( Edge decided my github tab is unimportant, so got rid of what i had typed here initially. I've been attempting to use kicad to start making, and it's not easy but i'm figuring it out. Oh also I realised that my school's solidworks licence runs out in like 4 days so I'm going to have to learn a completely different cad software :heavysob:. So I was at first trying to put an esp32-s2 on my pcb, but then things quickly got confusing because I realised I'd have to do power supply circuitry and clock timing and waaaaaaaaaaaaa so instead I thought I'd look at the hackpad tutorial, and i saw that it used the xiao-rp2040-dip, so I'm going to use it. It has all the pins i need, and it seems like it should be nice and simple to use. I am thinking about how to power the microcontroller, because I will have an AC input going to the LED driver, and I will need another power supply for the microcontroller. I found [this](https://www.hlktech.net/index.php?id=134) cute little AC to 5V DC converter, the part number is HLK-10M05. It will need a fuse, capacitor and resistor as well, but it should in theory do a lot of the work for me. I don't want to have two different cables plugged into my light, one for the microcontroller and one for the LED driver, so I believe this should work. I think I can just take two psus off of the same ac line? At this point I'm just getting a hold of kicad and working out the general idea of my schematic.

![image](https://github.com/user-attachments/assets/8704e644-471d-45cb-ad61-32971cc67d5b)


# Tuesday 20 May 17:30-18:00  19:00-19:30  21:15-21:45 - 1.5 hours
I asked [#electronics](https://hackclub.slack.com/archives/C056AMWSFKJ/p1747758821959079) in slack about how i'd power both the led driver, and after consulting with [Aiden](https://hackclub.slack.com/team/U06CHEJ7P6U) in [this](https://hackclub.slack.com/archives/C056AMWSFKJ/p1747758821959079) thread, and drawing the below, beautiful drawing, I came to the conclusion that it is safe to 
split the ac input to a 5v psu and the led driver. I'll use a standalone psu rather than making my own, perhaps I'll take apart some random cheap usb plug for it.
![image](https://github.com/user-attachments/assets/c418081b-234b-4d86-b918-1f718c68181b)

So, the more powerful LED ([this one](https://www.mouser.co.uk/ProductDetail/Lumileds/L2C5-40801825G3200?qs=T3oQrply3y8Ak6%2FCD8N%252BaQ%3D%3D)) is 51.7V. That's weird. But the minimum voltage is 48.8V and the maximum 56.3V, so that gives me some leeway to find a suitable driver for it. Unfortunately the minimum is a smidge higher than the voltage of the meanwell driver I had been looking at. I just found [this](https://www.mouser.co.uk/ProductDetail/MEAN-WELL/ELG-150-54B?qs=sGAEpiMZZMvV8Y9YugmIgqWA%2FF1iXuxj6wUSrTKyFL2ZK2vf%2FH1rsg%3D%3D) meanwell LED driver which looks great, it's 54V so should be within the suitable voltage range for the LED, and it's 150W to go with the 115W LED, so it won't always be running at 100%. And it's only £35 which is close to the old one! and of course it supports the same way of dimming.

Ok, after [@Parker Rupe](https://hackclub.slack.com/team/U08SPJPNKDZ)'s input, I'm not going to take apart some random usb plug, instead I'm going to use [this](https://www.mouser.co.uk/ProductDetail/MEAN-WELL/IRM-10-5?qs=WkdRfq4wf1Mbq1AdfDJBoQ%3D%3D) 5V 10W meanwell power supply, model IRM-10-5 [(datasheet)](https://www.meanwellusa.com/webapp/product/search.aspx?prod=IRM-10). I believe I can just slap it on and stick 240Vac into it, then it will give me 5V that can go into the xiao. Of course, I'm going to ask if someone who knows what they're doing (not me) can check over everything i design.
So now the ~~PCB~~ *schematic* looks like this (it looks like less than before...):

![image](https://github.com/user-attachments/assets/5eec0b46-98ed-4a7d-a137-6f0642e71501)


# Wednesday 21 May 10:15-10:45  18:30-19:00 - 1 hour
I've been getting the schematic good (I think) and i calculated what are apparently appropriate resistors, according to internet. Behold:

![image](https://github.com/user-attachments/assets/c13f182e-e134-4175-86ca-c8be39994cbd)

I haven't yet added a potentiometer and the motor for lens movement yet. I really don't know how I'm going to do the lens movement. I also don't know what I'm going to do with all the heat the led produces. I'll have to have a heatsink with a fan, maybe a proper cpu type cooler. I'll probably print the actual thing out of PETG, as it might be heat resistant.


# Thursday 22 May - 3 hours

I started learning onshape because my school's solidworks license expires soon!

I started modelling the lamp, as seen below, but then i decided it would be helpful to have a model (below below picture) of the lens (below below below) I'm using. I used my calipers :) the model of the lens needs a bit more work. I decided the hexagonal tube at the front should be 12cm wide, and then i will need a bigger box at the back of the light for power bits and stuff (the meanwell led driver is 22cm long...)

![image](https://github.com/user-attachments/assets/04eeb36f-90bf-45a0-815d-02f63ea4c312)

![image](https://github.com/user-attachments/assets/b991e05c-7b3f-4fe5-bca7-e58b3309a519)

![PXL_20250522_220821661 MP](https://github.com/user-attachments/assets/86298f42-259f-43f9-bbb5-934116c96c99)


# Friday 23 May - 1 hour

I finished modelling the lens thing! It was shockingly difficult to do the bit where it slopes into a triangle, especially with getting the triangles to line up with the other cylinders using constraints, it's hard to explain.

![image](https://github.com/user-attachments/assets/15b59ba0-bba2-46a4-af04-b0db65e234ac)


# Saturday 24 May - 4 hours

I've started modelling thge front part, the inner tube that's going to hold the lens, as is seen below.

![image](https://github.com/user-attachments/assets/23df8567-bc31-4833-a3ca-88a69adc18e5)

I decided to try 3d printing the bit that the lens should in theory thread into because i want sanity and to see if i need a better way of holding the lens in than hoping it threads into the plastic. I'll have to try it again once i have petg, but i don't yet so i'm just doing in pla to see if the dimension i chose is good. The circle the lens should thread into is 0.5mm smaller than the outer diameter of the threads on the lens, so hopefully that will be good and hopefully my printer's accurate enough.

![image](https://github.com/user-attachments/assets/21090947-3fa4-4458-a2a4-0e643194da3b)

Oooo look at it go
![PXL_20250524_175748476 MP](https://github.com/user-attachments/assets/a4df2fab-09a5-4b9d-a1c8-8e9d72725a9b)


![image](https://github.com/user-attachments/assets/7f3c9165-76e5-4f4f-b74b-91f3f7b951b9)


It doesn't fit :(
It almost goes on but not quite. I can almost stretch it on but it doesn't stretch. I'm thinking if i make the holder a many sided shape of some description (hexagon maybe?) and then i should have room for it to stretch (maybe??) while still holding it??? maybe???? but then I'm not sure how I'll hold the flexible bit holding the lens to the actual tube in a way that is rigid but also allows the lens holder to flex a bit...

I just thought that I could make something to clip into the weird cut out in the lens with the slanty edges, the one that took me ages to model. Still has the problem of making sure it's flexible though

Ok i think clipping into the slopey bit isn't going to be possible because it's too close to the front to have any flexibility

So uhhhh I cooked up this monstrosity :pf:
![image](https://github.com/user-attachments/assets/8589e0a8-5027-44fc-a314-21884361711c)

Here's how it _should_ go together with lens
![image](https://github.com/user-attachments/assets/90f1ab17-44e2-4018-8fbf-e5fae9cbdacc)

Maybe it will be too thin?

Maybe it won't be flexible enough?

Maybe it will just delaminate from the layer below?

Maybe it will collapse when it's being printed? Hopefully the archedness is good enough that it won't need supports...

I don't know, but lets find out

![PXL_20250524_223147108](https://github.com/user-attachments/assets/6bba273d-c451-4613-9132-98b5e48fc3e7)
![PXL_20250524_223842524 MP](https://github.com/user-attachments/assets/c75189f9-0a7a-4cb4-9ec0-71825fddb536)

That was such a scary print to watch but IT WORKS!!!!!!!!!!!!!!!!!!!!! I am so happy

goodnight github


# Sunday 25 May - 2 hours

I edited the holder a little so the clippy bits go a little further inwards, just to give a slightly tighter fit on the lens. I also made it a teeny bit less long, because otherwise i think the front of the tube would have stopped the lens from going all the way in properly.

Here are the dimensions of the LED, I don't know if I'll directly hold it with PETG or if I'll make a wooden bit to hold it...
![image](https://github.com/user-attachments/assets/ce651a46-9651-45ee-bd76-3ecea05867a8)

I really don't know how i'm going to mount the LED, it will get HOT and any normal filaments will just warp. I also don't know how I'm going to mount the cooler to it, and I also don't know how the temperature sensing is going to work. Oh and i'll probably need 12v power for the fan.... yay another power supply...

Over lunch I decided I'll probably use some 3mm mdf i have, and cut out a whole for the led and cooler to hold the led. If that makes any sense

So I pressed the button on the mouser website to get a free cad model of the led and it just worked! They did it very quickly too.

Here's a cross section of what I have now, I've started doing the outer tube and I have arms inside it to hold the wood(?) that the LED will be mounted to.
![image](https://github.com/user-attachments/assets/72878a55-87df-4601-8168-2927da849cef)


# Monday 26 May - 1 hour

So i was planning to attach the led to the mdf and the mdf to the 3d print using superglue, but uhhh apparently if superglue gets heated up it produces toxic fumes?? so maybe I'll use a 2 part epoxy of some kind of a some other sort of adhesive. from searching, apparently water based adhesives can be good for heat resistance.

I now have this platform (the grey bit) for the LED! The LED goes behind the wood because then it makes it very impossible that the LED will ever crash into the lens, which is good! And if somehow the lens does go to far back, it just hits the mdf which would be absolutely fine.

![image](https://github.com/user-attachments/assets/49973005-e5b3-4cb4-9d46-ed2efa31bf45)


# Tuesday 27 May - 1.5 hours?

I was thinking about my LED mounting and I realised that since the LED is so bright, there's the possibility it could reflect off of the sides of the MDF hole? I don't know if that would be a problem but it's something to think about.

I was also thinking about how I'm going to move the lens, and I've pretty much decided to use a servo I think. I watched [this](https://youtu.be/MDk4SfTNr8M) video which shows how to open up a servo to get a wire out of the internal potentiometer to get feedback on what the current rotation is. So therefore i can find what rotation the user has manually moved it to, and I can store that rotation and then recall it! For storing settings, I'm thinking I'll have a bank of buttons and a SET button, like how a pipe organ stores registrations for stops. 

Also, I discovered that noctua makes fans that can run on 5V, meaning i won't need another psu!

I think I will need heatpipes to draw heat away from the LED, down the tube, and to a cooler towards the back of the light, because there is really not much space inside the tube for a cooler and fan, there's a 7.4cm gap inside which is unlikely to be enough for a big enough heatsink+fan.

I found [this](https://uk.farnell.com/amec-thermasol/mhp-2040a200a/heat-pipe-flat-200mmx40mmx2mm/dp/3972210) heat pipe but £20 seems kind of really expensive...

[This one](https://www.digikey.co.uk/en/products/detail/advanced-thermal-solutions-inc/ATS-HP-F9L200S70W-014/5049697) is from digikey and it can transport 90W of heat, so I might want two of them.  One heat pipe is £3.67. But, it's from digikey which means shipping is £12 unless i spend more than £33. So unless i decide to buy something else also from digikey, that's not going to be that helpful. I could buy the filament on digikey, but that's still not going to take the cost over £33.

Hmmm I realise i may not need nearly as beefy a cooler as i think because uhhh LEDs are supposed to be efficient.=
~~The LED I'm using doesn't explicitly say the efficiency and the heat output in the datasheet, but it does say that the typical luminous efficacy is 147lm/W, and in a worst case the minimum luminous flux is 15368lm. 15368 divided by 147 is 104.5W, meaning in a worst case the wattage~~ I just realised that lm/W is how many lumens are output for how many watts input, not whatever i thought it was.

I am quite confused with how much of the power input to an led is emitted as heat

I found [this datasheet](https://otmm.lumileds.com/adaptivemedia/6b684cddbefe74c4e4a88ed494320dc871c47925) about the LED that gives some information about its thermals, but nothing specific, but it does give things like how to measure the temperature with a thermocouple and how to mount a heatsink to it which would probably be helpful, and it mentions that you need a heatsink of enough wattage but it doesn't say anything about how to find that heatness :(

[This example](https://www.arduinolearning.com/code/max6675-and-arduino-example.php) I found shows how to use a thermocouple module with an arduino, which should be comparable to using it with the rp2040 i think. I also found [this thermocouple module](https://www.amazon.co.uk/DollaTek-MAX6675-Interface-Thermocouple-Temperature/dp/B07DK8VG87/) on amazon for £4.99. I'll also need a thermocouple wire, and they seem to be cheapest on digikey (shipping >:( ) but mouser has rather pitiful offerings for thermal things it seems which is sad: [1m wire](https://www.digikey.co.uk/en/products/detail/labfacility-ltd/XE-3529-001/25806221)  [30cm wire](https://www.digikey.co.uk/en/products/detail/labfacility-ltd/XE-0428-001/25935742)  A thermocouple works by having two dissimilar metals and when a heat is applied it makes a small voltage apparently, I don't really understand how it works but i thought i'd say something so it sounds like i have some idea about what i'm doing.


# Wednesday 28 May - 3 hours
Ok! I found [this video](https://www.youtube.com/watch?v=Lqbyu5BGthc&t=118s) which shows how to calculate the heat power output of an LED! yippee!

Now all I have to do is mentally process this scary looking equation:
![image](https://github.com/user-attachments/assets/68ce762b-1df4-45d0-9c0a-b0b3f6b53002)

I could not find a value for K in the datasheet (K is the luminous efficacy of radiation, and you need to know the radiant flux to find that, which isn't in the datasheet) so I searched how to find the heat power output of an led and apparently LEDs generally output 80% of energy input as heat, so apparently you should generally design for all of the power input to be output as heat. hhhhhhhhhhhhhhhhhhhhhhh. well anyway that was some nice research and wikipediaing, and i got to see a video of a funny looking man talk to me about LEDs for 5 minutes, many times

(that was 30 minutes)

Ok! Mouser does in fact have heat pipes! After a lot of looking and figuring out datasheets, I quite like the [ATS-HP-F7L200S65W-018](https://www.mouser.co.uk/ProductDetail/Advanced-Thermal-Solutions/ATS-HP-F7L200S65W-018?qs=lc2O%252BfHJPVYfQgWmPy67UQ%3D%3D) heat pipe (catchy name, I know) [(datasheet)](https://www.mouser.co.uk/datasheet/2/596/Heat_Pipes-1480426.pdf) (The picture on mouser has multiple heat pipes with a heatsink attached but I believe it is actually just a heatpipe. It can transfer up to 61W of heat energy, so I will have 2 of them to remove up to 122W of heat which should be more than enough. Each heatpipe is 11.2mm wide and 3.5mm tall and 200mm long and costs only £3.96 yay. Two heatpipes will take up 22.4mm roughly and be £7.92. If I decide i need another heatpipe, I can get another one and it will still fit on the 38mm LED. Perhaps a 150mm long heat pipe will be enough? I'll keep designing my light and decide what length I need. For 150mm, the [ATS-HP-F5L150S40W-025](https://www.mouser.co.uk/ProductDetail/Advanced-Thermal-Solutions/ATS-HP-F5L150S40W-025?qs=lc2O%252BfHJPVbaquzC%2FXHGQg%3D%3D) looks good, it's 59W and £3.23, and 8mm wide.

(that was also probably 30 minutes)

[This towerpro sg90](https://www.mouser.co.uk/ProductDetail/Soldered/101246?qs=IKkN%2F947nfCky%252BicgAH2DA%3D%3D) servo motor looks good, it's on mouser meaning i can have my free shipping and it's £4.82. Apparently it needs 5V power but the logic can be run at 3v so I can use it with the rp2040 yay. The datasheet says it is both 9 grams and 14 grams though. I guess it's 14 grams including the wire? the datasheet is very little but it's common so sure. I feel like the electronics shop near me would have one?
Also totally unrelated but if you invert the phase of one channel of stereo music and then mix them down to mono, it very often filters out the voice which is nice so i can have songs i like without the singer, or often just with the backing vocals, and without actively looking for an instrumental version.

And that servo even has a 3d model already!

I found some servo I had lying around which is a knock-off SG90, so i decided I'd solder a sensor pin to it like in the video i linked
![PXL_20250528_144646962 MP~2](https://github.com/user-attachments/assets/93f65cf8-d6f5-4be7-9680-aa3d9309c177)

I've been trying out the servo with my arduino uno r4 wifi, and i spent ages confused at why it was moving in such big steps. I assumed it's because it's a cheap knockoff servo, but when trying to search for why this was happening i found someone else who has an uno r4 and their stepper motor was moving in large steps. Apparently, there was a problem with uno r4s which had something to do with the PWM duty cycle, so i did an update and now it's fine! That was weird, though. Using the arduino serial plotter, I found that there is a very linear correlation between the sense pin of the servo and the angle it's rotated to, which is nice because it means i can do some code to just find a scale and offset to convert from analogue input to an angle which can be stored and sent to the servo. Yes I'm doing this to procrastinate figuring out how I'm mounting the servo in the spotlight. Below is a section of the serial plotter where the blue line is the target angle and the green line is the analogue value (which i did some manual scaling of)

![image](https://github.com/user-attachments/assets/ef3d80b0-fcc9-45e4-9283-8ff3e43c955b)

I was initially trying to do a sweep of angles and then map each angle to an analogue input, but that was too complex as i think instead i can just get two points and figure it out.

Maths!
![image](https://github.com/user-attachments/assets/9487c5b0-52e1-42d8-b8e2-b6b972bbf3f1)
Revising for my maths GCSE next week well

I even commited the code i did to the github repo! I just added a feature that lets you set a range of motion and the servo will stop you from going further by activating when it's past the motion and moving back until it's within the range, then deactivating again.

ooo a video too

https://github.com/user-attachments/assets/37b45619-cd76-4aad-be02-627f6d1e754e

ok what why does github think it's just sound i promise it's a video if you try hard enough

I made it vaguely store position values, but it's a little sqwonky in that it keeps on thinking the pin is connected to + even when it's not, it's very odd. this means that when you press one and then press another, it will quickly flap between the two because for some time it thinks both are being pressed...

I attempted some onshaping today, but i just drew some lines so i don't think you really need to see that, it was for estimating the needed heatpipe length, and i drew the start of a sketch for mounting the servo (it's 3 lines so far)


# Thursday 29 May - 3.5 hours

Agggggh I wrote so much for today, i should really start copying out what i've written so edge can't discard the tab and get rid of everything. Normally it shows the prompt to restore what i had, but not this time i guess :(
Here's my attempt at vaguely recreating what i wrote, with trawling through my clipboard history for screenshots:

Woah look at my servo mount!

![image](https://github.com/user-attachments/assets/30a1618c-f39a-4a3b-83b5-ad2f013301f7)


I did some more maths to figure out a probably good diameter for the cog

![image](https://github.com/user-attachments/assets/9530c22d-9e97-40a4-9dee-8ab2f1e11ea7)


I watched [this somewhat vague video](https://www.youtube.com/watch?v=wLZq1ZXhPfE) to figure out how to make the pinion (straight cog thing).

I had this, first, but...

![Screenshot from 2025-05-29 16-42-44](https://github.com/user-attachments/assets/f4d95da0-52f8-4e9e-bd1b-d5c415ab0a64)

...i then realised that the pinion would really want to snap if it was printed with the rest of the inner tube, so i redesigned it to be glued onto the inner tube, meaning it can be printed flat, which will be much stronger due to the orientation of the layer lines.
And now i have this:

![image](https://github.com/user-attachments/assets/b525db83-f7b6-4c01-8003-78c38efa3701)


I may want to swap the SG90 servo for an MG90S, it's basically the same thing but with metal gears which are finer, meaning it should be quieter, stronger, and not go crunchy when you push it too much like mine does.

I also edited the code a bit to remove some weirdness with the rotation limiting, which included fixing a bug where occasionally the servo would decide to suddenly rotate all the way to the other side

Also, I shortened the length of the outer tube from whatever it was before (180 maybe?) to 155mm which is more fitting.

I just added a vent so it doesn't bake and melt itself!

![image](https://github.com/user-attachments/assets/5d959766-bbde-4013-83c0-7cd497dd1861)


From a quick search, [this cpu cooler](https://www.amazon.co.uk/Thermalright-AXP90-X53-Profile-TL-9015-Technology/dp/B0BJPWX8B5/) looks like it could be good

Oooooo how about an AIO cooler? It's got tubes so i won't have to worry about heat pipes, although i will need to get 12V... I think I might just stick to heat pipes and a heat sink in the back with a 5v fan...

AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA the led driver is out of stock 
Oh and I just realised: "Product available only to OEM/EMS and design business customers. Product is not shipped to consumers in the EU or the UK" D:
It's supposed to come back in stock on mouser on 14/08/2025, which would be much too late. It's also out of stock on digikey, but with the short date of 13/06/2025 to get it back in stock. hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
And the 5v psu is also business only WHY IS IT SO UNOBVIOUS???? is hack club a business? probably doesn't count...

Um so that's inconvenient


# Friday 30 May - 3 hours

Wow i really don't learn do i, i just did the same thing where i had written a bunch and then the tab got discarded...

lcsc had the 5v psu for cheaper, but with the handling cost and shipping it's not worth it so i'm just doing digikey.

[LED on digikey](https://www.digikey.co.uk/en/products/detail/lumileds/L2C5-40801825G3200/7344822) for £29.07+VAT

[LED Driver on digikey](https://www.digikey.co.uk/en/products/detail/mean-well-usa-inc/ELG-150-54B/7702975) for £37.98+VAT

[5V 10W PSU on digikey](https://www.digikey.co.uk/en/products/detail/mean-well-usa-inc/IRM-10-5/7704657) for £6.45+VAT

I found [this little 2W 5V to 12V converter](https://www.digikey.co.uk/en/products/detail/mean-well-usa-inc/SMU02L-12/7706871) for £3.89+VAT on digikey, which is much cheaper than buying a £20 noctua 5v fan, as i can just use the normal 12V fan that comes with whatever heatsink i get

I feel like i don't need to pwm the fan, it can just run at full speed. I considered not having a thermocouple, but i think it should so that it can know if it's destroying itself.

Helpfully, I found this schematic on [this datasheet](https://blog.embeddedexpert.io/?p=806) on how to use a max6675 thermocouple chip in a circuit, meaning i don't have to buy an overpriced thing, it can just integrate into my pcb!
![image](https://github.com/user-attachments/assets/ca26b6a0-b29d-4406-a404-f1fc146a89ad)

Hmm i might use [this MAX31855KASA-T](https://www.digikey.co.uk/en/products/detail/analog-devices-inc-maxim-integrated/MAX31855KASA-T/2591213) for £7.05+VAT instead, it's basically the same thing but actually in production and at 3v. ([Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/max31855.pdf))

I've (maybe?) finished my schematic! I used every GPIO pin, so hopefully i won't find i missed something and need another. If i do, i'll sacrifice a switch. I added a red LED to indicate stuff, like flashing when going past the movement limit, and lighting up when the led is too hot. I also included a circuit for the thermocouple, and i realised a switch would be good for the main power input.

![image](https://github.com/user-attachments/assets/f5922a38-4b57-407d-acf9-76320024962c)
