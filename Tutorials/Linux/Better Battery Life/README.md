- OS: Debian, Debian based, Ubuntu, Ubuntu based
- Hardware: Must be laptop computer
- Difficulty: Easy to medium
- Last Tested: Ubuntu 16.04 LTS

Have you noticed that Linux battery life sucks? I love Linux but it seems to be lacking in this department.  Sure you can install XFCE, LXDE, or even Openbox to cut down the battery usage but that isn’t enough.  I’m going to showcase two programs that will really increase your battery level.  This is not a definitive guide but rather guidelines from personal experience and may or may not work on every laptop. For reference I'm using an HP EliteBook 840 G2. I went from 4 to 5 hours to 6-7.

TLP should work for all models of laptops and is easy. PowerTOP is one step further and requires more effort. 


## TLP Installation
Website: http://linrunner.de/en/tlp/tlp.html also http://www.webupd8.org/2013/04/improve-power-usage-battery-life-in.html .  
No one is really sure what TLP stands for but it’s a great program that manages your battery life with two modes, BAT and AC.  If you have a Thinkpad make sure to install the packages mentioned by webupd8. Let’s open the Terminal and start.

`sudo apt install tlp`

This will install TLP.  TLP works out of the box but configuration steps are located here: http://linrunner.de/en/tlp/docs/tlp-configuration.html or run `man tlp`

Next let’s start TLP with

`sudo tlp start`

TLP will start on it’s own and run without user interaction.  No testing should be necessary.  You can verify it's enabled after reboot using 

`sudo systemctl status tlp.service`


## PowerTOP Installation
PowerTOP is a program developed by Intel to save battery.  You can find the manual here: https://01.org/sites/default/files/page/powertop_users_guide_201412.pdf and a website talking about it here: http://www.makeuseof.com/tag/powertop-will-maximize-your-linux-laptops-battery-life/

To get it installed use

`sudo apt install powertop`

If you run

`sudo powertop`

You will see a lot of information about what’s going on with your system.  But we don’t need to look at this information.  So if you ran that command just use `Esc` key to exit.


### PowerTOP Configuration and First Time Setup

Let’s use the calibrate argument to get the best tweaks.  This will take a while to do and you screen with turn on and off but don’t worry it will be done within about 10 minutes.  Try not to do anything else on your laptop while this is happening.

`sudo powertop --calibrate`

After that is done then run

`sudo powertop --auto-tune`

If all is working after that command great, but check your USB devices, touchpad, keyboard.  For example, I ran this on my desktop to try and lower power consumption and my mouse turned off automatically really fast.  I've never had anything not work right on the laptops I ran it on. If something is unusable like your mouse just reboot. If you know auto tune breaks something you can set it back after using my Fixing section.

#### Note: `auto-tune` sets the VM Writeback Timeout higher which saves battery but can potentially cause data loss if your computer loses all power.  Since laptops run on AC AND battery, this isn't a big deal since you would need to lose both; but, if it's concerning to you you can manually turn that tweak to `off` which will set it to `Bad`.  Use the next section below to do that.


### Apply PowerTOP Tweaks Automatically at Startup
If all is working then we need to set PowerTOP to run at startup as root.  The easiest way to do that is to edit `/etc/rc.local` which by default does nothing and it will tell you that.  Run

`sudo nano /etc/rc.local`

Type in (you can navigate with the arrow keys)

`powertop --auto-tune`

Before the exit 0 like below:
```
#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.
powertop --auto-tune
exit 0
```
Then press `Control X` then `Y` then Enter to save

You can also edit this using GUI by using 

`sudo gedit /etc/rc.local`


## Fixing a bad tweak after running `sudo powertop --auto-tune`

#### If you didn’t have any issues from before you can continue to Verification.  If you did have issues after running auto tune then read this section.

If you have any issues with your hardware after running `sudo powertop --auto-tune`.  You can try to run

`sudo powertop`

Use the tab key to move to Tunables heading.  Use the arrow keys to scroll up and down and use the space bar to change the values.  If you have any issues with your USB devices just go down to the one you recognize as the problem like below

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Better%20Battery%20Life/fixing_tunables_1.png)

And change it from `Good` to `Bad`

![alt_text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Better%20Battery%20Life/fixing_tunables_2.png)

See the echo command at the top?  That’s what you just did.  So to make this change permanent copy that line up top by highlighting it and using `Control Shift C`

So, in this case, you’ll copy 
`echo 'on' > '/sys/bus/usb/devices/2-3/power/control'`

Remove the ; and the first two >> at the front to get what’s above.  Now go back to your rc.local file by using

`sudo nano /etc/rc.local`

Add that line you copied like so
```
#!/bin/sh -e
#
# rc.local
#
# This script is executed at the end of each multiuser runlevel.
# Make sure that the script will "exit 0" on success or any other
# value on error.
#
# In order to enable or disable this script just change the execution
# bits.
#
# By default this script does nothing.
powertop --auto-tune
echo 'on' > '/sys/bus/usb/devices/2-3/power/control'
exit 0
```

## Verification
Again, no testing should be necessary with TLP since it’s really straightforward.  With PowerTOP you will have to reboot after saving `/etc/rc.local` and then run

`sudo powertop`

When you are back into the Terminal.  Use tab to go to the Tunables section.  If almost everything you have is “Good” then it worked.  My VM Writeback Timeout is “Bad” but that is the only thing that isn’t tuned.  That’s probably being changed by something else for a reason.

If everything is still “Bad” you may have to enable your rc.local service by using

`sudo systemctl enable rc.local.service`

Then reboot.  If it still doesn’t work right try the Ubuntu forums or other help sites.
