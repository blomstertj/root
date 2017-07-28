# Description
If you dualboot between Windows and Linux and switch between them often you may want an easy reboot shortcut where it automatically selects the Windows GRUB entry.  This method basically makes GRUB select a specific entry instead of the default one so you don't have to use the arrow keys to select a different OS.  The beauty of this solution is once you reboot again in your other OS (like Windows) the selected GRUB entry is back to it's normal one.  This allows you to have some automation to make Windows run it's maintenance tasks once a week or something.


# Edit GRUB Default Config
Edit `/etc/default/grub/` with `sudo nano /etc/default/grub` and change `GRUB_DEFAULT=` to `GRUB_DEFAULT=saved`


# Script

Before creating this script you must understand how numbering works with GRUB.  When looking at your GRUB bootloader you may have:
- Ubuntu
- Ubuntu Advanced Options
- Windows 10

GRUB starts at 0 so if you want to have GRUB select `Windows 10` your number would be 2.  That being said we can create a very simple script using the `grub-reboot` command.

```
#!/bin/sh

gksu grub-reboot 2 && reboot
```

This will require the `gksu` package to be installed and your root password when this script is ran.  Save this script somewhere like `/home/username/bin/RebootWindows10`


# Create a desktop shortcut for this script

Open a text editor and put in the following:
```
[Desktop Entry]
Type=Application
Name=Reboot to Windows
Terminal=false
Exec=/home/tanner/bin/RebootWindows10
Hidden=false
Icon=/home/tanner/Pictures/Icons/Windows_logo_-_2012.svg.png
```

I recommend finding a png icon of the Windows logo like I have done above.  Save this file as `Reboot to Windows 10.desktop` or something similar but make sure `.desktop` is at the end.


# (Optional) Create a cron job to automatically reboot to Windows at night weekly

This is useful to make Windows come up to perform all it's maintenance tasks at night.  If you're running Windows 10, I recommend changing the "maintenance window" time to a few minutes after this cron job runs.  Make a task using Task Scheduler on Windows to automatically reboot maybe 2 hours after the cron job to load Linux back up.

## cron job

Since this will be ran as root, gksu is not required.  Create a new script like before but with this instead:
```
#!/bin/sh

grub-reboot 2 && reboot
```

Save this as `/home/username/bin/RebootWindows10Cron`

Edit the root crontab using `sudo crontab -e` or (for easy mode) use `sudo EDITOR=nano crontab -e`
```
#Reboot into to Windows 10 every Wednesday at 1AM
0 1 * * Wed /home/username/bin/RebootWindows10Cron
```
