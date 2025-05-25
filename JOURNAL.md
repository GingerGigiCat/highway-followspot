## Time so far: 3 + 1 + 2.5 + 1.5 + 1 + 3 + 1 + 4 + 2 =  19 hours

# Saturday 17 May 2025 - 19:00 - 3 hours

So I've been wanting to make a spotlight for a while. I had planned for my GCSE Design & Technology project to be a spotlight, so I did research including a questionnaire on what people look for in a spotlight, and I upcycled a camera lens which is unsuitable for a camera but it works great to put light through. However, my teacher decided no and told me to make a desk lamp in the style of a spotlight. No lens, no very bright LED, and nothing over 9V. And it got me a good grade, but it's underwhelming and it isn't what I wanted to make.

Therefore, I want to properly go through with designing and creating a real, bright, functioning spotlight, taking inspiration from my desk lamp (the desk lamp is below)

![PXL_20250429_132217899 MP](https://github.com/user-attachments/assets/f220c4f3-c412-4063-a57d-dff0d6522912)
![PXL_20250501_122556802 MP](https://github.com/user-attachments/assets/2281e163-336d-49d5-bc21-3409a2349f29)

I am also inspired by the [beacon](https://hackclub.slack.com/archives/C0266FRGV/p1723503357605259) that [ruckusmatter](https://hackclub.slack.com/team/U06TZK6EKU6) made during arcade, and i'd like it include a way for my spotlight to have a perfectly straight beam. For reference, the beacon is 17,000 lumens and its colour temperature is 5600k.
![image](https://github.com/user-attachments/assets/d08b8b45-19fc-4a85-a123-553740619cb2)


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
