## Time so far: 3+1 hours

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
