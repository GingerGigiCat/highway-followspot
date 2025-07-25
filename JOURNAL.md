## Time so far: 3 + 1 + 2.5 + 1.5 + 1 + 3 + 1 + 4 + 2 + 1 + 1.5 + 3 + 3.5 + 0.5 + 0.25 + 1.25 + 4 + 0.5 + 1 + 1.5 + 1 + 1 + 0.5 + 2 + 4 + 1.5 + 2 + 2.5 + 4 + 1 + 2 = 60.5 hours

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


# Saturday 31 May - 0.5 hours

I looked around my house for some components to see what i already have and won't have to buy, and i found 2 suitable(?) resistors, and a red led! I also did a bit of assigning of symbols to footprints, which included having to make some footprints myself.


# Sunday 01 June - 0.25 hours

happy pride month

i did a little more footprint making for things, namely the led driver. i also found a good looking fuse holder, and i think a 2.5A 5x20mm fuse should be good.


# Wednesday 04 June - 1.25 hours

I realised i'm fairly sure i don't need a resistor between the led driver and the LED, as it is a constant current driver so will regulate the current itself (hopefully?).

I was also looking at the thermocouple chip datasheet for no specific reason and found that the max31855 (the newer one that i switched to) suggests **not** having the negative of the thermocouple connected to ground because of something about power supply noise. There was also a revision of the datasheet that quietly adds the suggestion of "a 10nF differential capacitor to the T+/T- pins", to help reduce noise in measurements. I guess i'll do that then, no idea what differential means though.

Also apparently the wattage of the LED isn't a set maximum??? The graph below (blue line) shows that it can be as high as 250W at just under 56V. Interesting. Perhaps I should allow for more heatpipes then

![image](https://github.com/user-attachments/assets/0ad89a8e-4ccc-406d-8af5-938dfe313840)


I used a [funny calculator](https://www.digikey.co.uk/en/resources/conversion-calculators/conversion-calculator-pcb-trace-width?msockid=34b1ed09ca0362e112bdf8ebcbe36317) online to figure out that my AC traces should be about 2.5mm thick for the absolute maximum of 2.5A i'm having.

I've also been finding components like resistors and capacitors. I found 2 roughly 40 ohm resistors which should be perfect for the optocoupler and red led, and I found a red led. I put matching footprints for them into the footprint assignment. I also found a [0.1uF capacitor on digikey](https://www.digikey.co.uk/en/products/detail/vishay-beyschlag-draloric-bc-components/K104K15X7RF5TL2/286538) for £0.18, as well as [this fuse holder](https://www.schurter.com/en/datasheet/typ_OGN.pdf), which i both put footprints for.

I also realised that the pin header I selected for the servo to connect to was actually tiny, thanks to my friend wanting to look at the 3d model and me realising the servo pins were tiny compared to the fan header. So i replaced it for a 2.54mm type header.

Now all that's left to do in the footprint assignment is the buttons, the connector for the thermocouple, and the holes for the led driver.


# Tuesday 10 June - 4 hours

I've been doing my PCB, I started with the AC side, and then did the lower power side. It took me a while to route it and do good placements for the footprints, but it should be done now! yay!

![image](https://github.com/user-attachments/assets/393ccb40-11d4-4f31-9c3e-305c889db638)

I've also made a spreadsheet of all the components, although i did just realise it's missing the servo and pin headers, although i can hopefully get those from my local electronics shop. OH THE OPTOISOLATOR!
Here's what i've got so far:

![image](https://github.com/user-attachments/assets/a03767a5-ea10-483e-87e3-25bc4ee5a6ad)

can't write much sorry i need to sleep


# Wednesday 11 June - 0.5 hours

I found that I can get an IEC power input thing that has a spot for a fuse! https://www.digikey.co.uk/en/products/detail/dit/DAC-13F/18681314 Meaning I can remove my internal fuse and the fuse can be user replaceable! This is also safer as it means that it is fused the moment it enters the spotlight, so the fuse will stop anything bad that could happen in the free wiring to the switch and to the board!

![image](https://github.com/user-attachments/assets/18a04461-7e53-48b9-ae0b-be7cfa5eb288)

Oh yeah, yesterday I found it would be cheaper to buy the thermocouple amplifier and the 5v psu at lcsc, even with the added handling and shipping fees!

I just found that LCSC does iec power input things that not only have a spot for a fuse in them, but also have a switch in them! Even better!

I also added to the spreadsheet

![image](https://github.com/user-attachments/assets/95c2779f-a732-4a9b-bfea-2cc7f187d6e9)


# Saturday 14 June - 1 hour

I assigned 3d models to almost all the parts in my PCB, except the 5v to 12v converter which i unfortunately couldn't find online. Here's pictures! Oh yeah, i discovered kicad has an option to enable ray tracing which is entertaining to watch  my laptop struggle with

![image](https://github.com/user-attachments/assets/4b7081e6-78dd-4417-a6ef-4139a1d6e4a4)

![image](https://github.com/user-attachments/assets/5dbba933-6428-41af-94d7-db1db7742e56)

I also gave the board edge cuts, with rounded corners (yummy), as well as mounting holes, and a cut out to give room for the power plug.
I then imported it to onshape, although for some reason it decided to lose the colours of the components :/

![image](https://github.com/user-attachments/assets/65f9a6ad-cf7e-4bd0-ad6b-0f7aa82a8a32)


# Monday 23 June - 1.5 hours

After importing the pcb to onshape and positioning it, i realised it's a bit big, so i've been working on getting it smaller in kicad. I decided to remove the traces connecting the led driver to the led, instead it will just be freewired, it's literally just two wires.

![image](https://github.com/user-attachments/assets/733de100-ce07-4819-8af1-2b9bbd6369ac)

Size comparison, old in back new in front:
![image](https://github.com/user-attachments/assets/3fde698f-7376-4f2b-86fe-4eab7a70f1c3)


My LED driver still isn't back in stock, the website stock checker says shipment is due 13/06/2025 - We are actively pursuing delivery information with the supplier and will update our website as soon as possible. It's been like that for over a week so i'm emailing digikey support.

here's the email:


> Hello,
> 
> I've been waiting for the shipment of the Mean Well LED driver ELG-150-54B to arrive at digikey so I can order one for a somewhat time-sensitive project. The shipment was due on 13/06/2025 but 10 days later it is still not in stock.
> 
> Since it was due, the lead time checker on the website has said "We are actively pursuing delivery information with the supplier and will update our website as soon as possible."  so I was wondering if you have any updates on this shipment that you could share, or a good alternative? The HLG series seems to only dim to 10% and I'd rather not have to also use a relay as I am using all pins on my microcontroller already.
> 
> Thanks in advance,

They responded basically saying that the HLG-150-54B is the closest alternative. It's more expensive and doesn't dim to 0% so i won't be using it, and they probably didn't really read my email.


# Tuesday 24 June - 1 hour

I found a new LED driver!!!!!!!!
It's the [XLG-150-H-AB](https://www.digikey.co.uk/en/products/detail/mean-well-usa-inc/XLG-150-H-AB/10222586)!!! and it's cheaper! at £31.20 (incl. VAT) compared to the ELG one which is £37.94 (incl. VAT) so i save some money yippee

Apparently it should work, and it's smaller!!!

I realised the fan would be a smidge over 2W, which is the limit for my 5v-12v converter, so perhaps i will have to use a resistor

It does have an earth wire though so i will have to connect the earth to the plug input's earth, which is kind of nice because it felt a little weird having an earthed plug but no actual earthing in the light.

I have been considering how i'm going to have the heatsink. 
Here's a drawing (terrible, i know)

![image](https://github.com/user-attachments/assets/df2ca6f1-2799-4790-bd92-7accd37ee472)

Basically, I'll have a cutout below the heatsink so it can exhaust the hot air, without just exhausting all the heat from the led inside the light. The fan will also extract ambient heat from the electronics too!

That heatsink is £20 on facebook marketplace, hopefully it's still in stock by the time i actually buy it.

I realised it's kind of impossible to solder to a heat pipe because uhh it moves heat? so instead i'll have to use thermal epoxy WHY IS THERMAL EPOXY SO EXPENSIVE WHAT

ok i found ec360 thermal glue for £6 on amazon it's not that bad


# Friday 4 July - 1 hour

I moved the microcontroller so it's more central on the board and further contemplated by heatsink choice. After consulting my friend ([Max W](https://github.com/max-worboys)), he found the cooler master 212 evo on facebook marketplace for £10, which is half the price of the low profile cooler i was looking at before. Yes, it's not low profile, but i don't think that matters all that much if it gives me more cooling headroom, is cheaper, and is more easy for other people to find (it's around £15 on ebay and pretty common, so others will be able to reproduce my project).

![image](https://github.com/user-attachments/assets/8e8a02ce-75d3-4c45-8b5e-3fc13bcd9a90)

aaaand, as the fan on the hyper 212 evo is 2.26W (over the 2w rating of my 5v-12v boost converter), i have (with much pain) found the [SPU03L-12](https://www.digikey.co.uk/en/products/detail/mean-well-usa-inc/SPU03L-12/7707058?s=N4IgTCBcDaIM4AcCuAGAzAGQLQEYIF0BfIA) which is £4.51 on digikey and is not available on LCSC, so it's more than the £3.54 i was paying for the 2w converter but this one actually provides enough power so i think it's worth it, and the cheaper cooler offsets the cost.

i really need a good good proper think about how i'm mounting and orienting the cooler. Now that i've proerly decided on a specific cooler, i can start doing it without fear of it changing because that just is the cooler i'm getting no matter what. 

goodnight github


# Saturdat 5 July - 0.5 hours

I replaced the old voltage converter on the schematic and pcb, and i have found a 3d model of the heatsink and imported it to onshape!

ALSO, i managed to find a thermocouple on LCSC!!!! for $4.56 !!!!!!!!!!!!!!!!!!!! that's a lot less than the thermocouple i had before ($7.54 less!), although it doesn't have much data available about it. It is the [ETA-G-K-24-200cm](https://lcsc.com/product-detail/Electronic-testing-accessories_ETA-ETA-G-K-24-200cm_C5144202.html?s_z=n_ETA-G-K-24) which is 200cm but i can just coil it up inside [(manufacturer website)](https://en.tw-eta.com/index.php?c=show&id=320)


# Sunday 6 July - 2 hours

I positioned the parts how i think they will fit nicely, and i imported a model of the led driver. There was no model available for the power input part, so i modelled the important aspects in onshape which took way too long, and i made a raised bit that comes out of the light for the part to sit on so that the prongs aren't at risk of touching the heatsink (bad). and it's looking pretty good! oh also i think i have finalised my parts list. Also, I added a fan to the model.

![image](https://github.com/user-attachments/assets/93231a9c-7bf8-4114-afdd-57216663cf55)

(ignore the wires sticking out, those are from the led driver and i haven't done anything about them yet)

![image](https://github.com/user-attachments/assets/576e5c32-807c-4bb0-b832-f1b38fa85b28)

![image](https://github.com/user-attachments/assets/74cf4585-1735-4de4-a9ef-89199c190437)

(yes i realise that fan needs to be the other way around, that's a future me task)


# Friday 18 July - 4 hours

SO it's been a while but i've been working on it over the past few days and i've modelled the heatpipes and i researched bending tools for heat pipes. i found a few, but the best i found was [this one](https://www.reddit.com/r/functionalprint/comments/y1ksua/pipe_bender_for_heat_pipes/). It's simple, 3d printed, and doesn't kink the heat pipe. AND, the person gave an onshape link so i could see how they modelled it! 

Heat pipes:

<img width="1128" height="688" alt="image" src="https://github.com/user-attachments/assets/54dbc821-c081-4621-af59-da78c76f1021" />


I had to make 2 different benders because it wasn't possible to combine all the bends into one. And the first bender has to be in 2 separate pieces that go together, or else it would be impossible to take the heat pipe out once it has been bended :pf:

Bender 1 part 1 with complete heatpipe for reference
<img width="1467" height="965" alt="image" src="https://github.com/user-attachments/assets/578e0cc3-7e21-4c13-9504-e71b16c00c90" />

Bender 1 part 2
<img width="1195" height="632" alt="image" src="https://github.com/user-attachments/assets/deeeb2d3-2486-45d1-930d-052a4853d1c3" />

Bender 1 together with complete heatpipe for reference
<img width="1461" height="781" alt="image" src="https://github.com/user-attachments/assets/56c0bfba-8d5f-4249-8fe6-4d28e21c6716" />

Bender 2 with complete heatpipe
<img width="1340" height="1001" alt="image" src="https://github.com/user-attachments/assets/4bb70108-f90f-42e5-af0e-c72a221266c8" />

# Sundary 20 July - 1.5 hours

guten abend

I have made the top of the electronics box separate from the main thing, AND i decided how i'm going to be mounting things!

So i'm going to be using m4 screws with nuts, it's easier than threaded inserts and both the IEC power input and the led driver and now my PCB have 4.5mm holes for m4 screws.

I have made holes for:

- the led driver!
- the electronics box roof!
- the power input!

It looks like this:

<img width="1298" height="856" alt="image" src="https://github.com/user-attachments/assets/d1113317-9a9d-475b-8fbb-45ede80ab92a" />


# Monday 21 July - 2 hours

I have sort of hollowed out the back of the light tube, it used to look like the first picture but now looks like the second! I also added an extra bit that sticks out slightly to give some room for the LED driver wires, and i continued adding screw holes and nut holes around

Hollowing out the back was shockingly difficult, i tried offsetting the faces and thickning them as a cut, but it would just go wonky so i ended up having to manually make a plane in exactly the right place and draw a little triangle which i cut out of the body for each side :pf: it's hard to explain

I'm just about to add extra screw holes at the top where the front and back attach but i'm going to sleep

I'm feeling like it's close to finished, although i still do need to figure out a mount for the heatsink and make a back plate the pcb attaches to, but that shouldn't be too hard right? right?????

<img width="1242" height="877" alt="image" src="https://github.com/user-attachments/assets/3c7713dc-4a25-4c45-9349-3aeb8beddc35" />

<img width="1334" height="853" alt="image" src="https://github.com/user-attachments/assets/35395737-d9b7-4d36-90b0-5ba2a1e0be56" />


<img width="1208" height="571" alt="image" src="https://github.com/user-attachments/assets/a975a986-c55b-4814-98a9-ef16af8ac605" />


# Tuesday 22 July - 2.5 hours

I've done the top of the attachment between the front and back!

<img width="1218" height="489" alt="image" src="https://github.com/user-attachments/assets/62f1a4e1-41dd-4e92-99ce-7b1387fa2e1a" />

Next up: heatsink mounting

I've just been seeing how PLA handles being pushed against my cpu heatsink when i'm running a stress test (CPU at 150-180W) and it was absolutely fine, didn't go melty at all, so PETG should be great to hold the heatsink without needing a buffer material (MDF)

Snazzy hole:

<img width="1406" height="945" alt="image" src="https://github.com/user-attachments/assets/b12e9db0-2717-422f-bbb8-c6c238135a1b" />

I really really hope this model of the cooler is accurate

I just finished making 2 mounting brackets to (hopefully) hold the cooler in place, they should fit inbetween the fan and heatsink, maybe they'll be noisy but oh well. I also made the base of the box nicely fit to the heatsink!

<img width="812" height="508" alt="image" src="https://github.com/user-attachments/assets/7c897b33-edf0-4176-83eb-a424f054fc08" />

My dad just reminded me i need a mount for the light... I think i'll do that now. I'm thinking M10 bolts? (I'll need to check dimensions once i've bought the bolts and before printing)

Hey look it's a mount nub! I also put 2 little tabs on one of the sides that can be folded over the bolt because otherwise it could fall in

<img width="989" height="903" alt="image" src="https://github.com/user-attachments/assets/e4f87aba-ec28-4e7a-96b6-04f82194695c" />


# Wednesday 23 July - 4 hours

I've made a nice back panel, added a silkscreen warning symbol to the part of the PCB where AC is, made a cutout to plug in a usb c cable, changed the nubs for the legs slightly, and added more fan intake holes on the front tube.

<img width="1259" height="1099" alt="image" src="https://github.com/user-attachments/assets/ae09a6e8-241d-4e21-865c-2fe12c646192" />

I'm thinking i'll cut the legs out of plywood, i don't think 3d printed legs would be great to hold the whole lamp with.

I just made a handle to move the front tube. 
I suddenly thought i could use one of the buttons on the back, or a key combo, to switch the fader from changing the led brightness to moving the lens, i think that would be fun.

<img width="1108" height="865" alt="image" src="https://github.com/user-attachments/assets/2032b58c-28ae-4539-9d9d-5674c1a8f3c3" />

Oh did I mention that when i did my school desk lamp project it had a really not great way of mounting the bolts to the body, it was just a superglued on thing that went over the bolt to attach it to the body, very bad and i doubt it would hold for such a bigger scale version.

LEGS!

<img width="1233" height="937" alt="image" src="https://github.com/user-attachments/assets/30163222-e35b-4330-ac7c-19da33e9b640" />

KNOB!!

<img width="1298" height="952" alt="image" src="https://github.com/user-attachments/assets/b3404ada-30ad-427e-b2a5-75fa3c81b2d1" />

<img width="1191" height="923" alt="image" src="https://github.com/user-attachments/assets/42a17303-9555-4523-bae9-cd9c08f32792" />


wow very productive day


# Thursday 24 July - 1 hour

I've been getting my project towards ready for submission, and i also added two more screw holes for attaching the back plate.

I gimped a wiring diagram!

<img width="715" height="596" alt="image" src="https://github.com/user-attachments/assets/7d30c748-be72-403a-98ed-833857e947cc" />

I also did a better readme

Here's my ticklist so far!

<img width="1257" height="1034" alt="image" src="https://github.com/user-attachments/assets/6bab0443-28a7-45e6-a3d2-4777382f6227" />

I am going to do the code tomorrow, i have no doubt it won't be perfect but it should be enough to function

I have an excel spreadsheet of my BoM, but i'm too tired right now to add it to my repo as a csv and in my readme as a table so goodnight!

I am debating with myself whether or not this is a 6 or 10 point project, i guess i'll ask in one of the highway channels


# Friday 25 July - 2 hours

I did code, assigning pins to the right ones for the xiao, and i changed the pin input types from pulldown to pullup and it fixed so much quirkyness! Before i did that, touching some pins on the arduino with a finger made the servo freak out and the buttons were weird, now it's fine!! I also added the thermocouple library, but code is not yet finished. (see https://github.com/Zanduino/MAX31855/blob/master/examples/Demo/Demo.ino)

i also exported everything as step files, finalised the BoM, figured out i'm going to split the cost of filament with a friend so i can get 1kg for £8.75, and made production files.

oh and i added to the readme, asked acon if it's a 6 or 10 point project (they said 6 but maybe with extra points), and did some other things to get it good too.
