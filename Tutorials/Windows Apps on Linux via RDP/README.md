This tutorial assumes you have good prerequisite knowledge about Linux and Windows.  At the end of this tutorial, you will be able to display any application installed on your VM to any guest using RDP.  Applications that require high bandwidth and lots of graphics are a bad idea; but, applicaitons like Microsoft Word work great though.  Adapted from this guide: http://tech.poweredbyorphans.net/natively-run-windows-applications-on-linux-with-seamlessrdp-and-rdesktop/

## End Result
![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Windows%20Apps%20on%20Linux%20via%20RDP/final_result.png)

## Host/server setup

#### Install VirtualBox on your host OS, in my case Arch Linux
`sudo pacman -S virtualbox  virtualbox-guest-iso`

#### Install the extension pack either from VirtualBox website or if in Arch, from the AUR

With pacaur:
`pacaur -S virtualbox-ext-oracle`

Manual way:
```
sudo pacman -S git
git clone https://aur.archlinux.org/virtualbox-ext-oracle.git
cd virtualbox-ext-oracle
makepkg -si
```

#### Install zerotier on your host OS, in my case Arch Linux
If on another distribution visit their website for instructions: https://www.zerotier.com/download.shtml

With pacaur:
`pacaur -S zerotier-one`

Manual way:
```
git clone https://aur.archlinux.org/zerotier-one.git
cd zerotier-one
makepkg -si
```

#### Set up and configure ZeroTier on the web.  I recommend private network and a manually creating a subnet instead of IPv4 Auto-Assign.

Example: 
![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Windows%20Apps%20on%20Linux%20via%20RDP/ZT_Sample_network.png)

#### Enable the ZeroTier systemd service:

`sudo systemctl enable zerotier-one.service && sudo systemctl start zerotier-one.service`

#### Allow zerotier through your firewall, I'm using ufw

`sudo ufw allow 9993/udp`

#### Allow all traffic on the new zt0 adapter (you don't have to allow all but for this project we need at least SSH port and RDP ports allowed through)

`sudo ufw allow in on zt0`

#### Join network:

`sudo zerotier-one join #######`

Go to the ZeroTier Central and go in your network and allow the computer to join.  Verify it gets an IP address via the web GUI or use `ip addr | grep zt0`

#### Set up ssh server, install openssh if you don't have it, on Arch it's

`sudo pacman -S openssh`

#### Create your ssh keys

`ssh-keygen -t rsa -b 4096`

#### Enable and start the SSH daemon
`sudo systemctl enable sshd && sudo systemctl start sshd`


## Client setup

#### Install zerotier on your client OS, in my case Arch Linux
If on another distribution visit their website for instructions: https://www.zerotier.com/download.shtml

With pacaur:
`pacaur -S zerotier-one`

Manual way:
```
git clone https://aur.archlinux.org/zerotier-one.git
cd zerotier-one
makepkg -si
```

#### Enable the ZeroTier systemd service:

`sudo systemctl enable zerotier-one.service && sudo systemctl start zerotier-one.service`

#### Allow zerotier through your firewall, I'm using ufw

`sudo ufw allow 9993/udp`

#### Allow all traffic on the new zt0 adapter

`sudo ufw allow in on zt0`

#### Join network:

`sudo zerotier-one join #######`

Go to the ZeroTier Central and go in your network and allow the computer to join.  Verify it gets an IP address via the web GUI or use `ip addr | grep zt0`

#### Set up ssh server, install openssh if you don't have it, on Arch it's

`sudo pacman -S openssh`

#### Create your ssh keys

`ssh-keygen -t rsa -b 4096`

#### Copy the key to the server so you do not need to enter a password (this will help our script later and will be convenient for remote administration)
`ssh-copy-id username@zt-ipaddr`

Verify you can ssh to the server without a password

## Final Server setup
#### Disable plain-text password authentication -- this will only allow keys the server knows about to connect (turn this off to add new clients then turn it back on)

`sudo nano /etc/ssh/sshd_config`

Find this portion:
```
# To disable tunneled clear text password, change to no here!
#PasswordAuthentication yes
#PermitEmptyPasswords no
```

Change `#PasswordAuthentication yes` to `PasswordAuthentication no`

Restart the sshd service
`sudo systemctl restart sshd`


## VM Setup

#### Setting up our Windows VM in VirtualBox

Get a Windows 7 ISO

#### Create Windows 7 VM and install Windows 7 (I won't detail the steps)
#### Install the applications you want to use remotely (ie Microsoft Office)
#### Install appetizer from http://appetizer.cozic.net/download
#### Install seamlessrdp shell (you need to give them email to get a download link unfortunately) from here: https://www.cendio.com/thinlinc/download/registration

Install the shell by extracting the zip and running the install in `windows-tools` on the VM.

#### Configure Appetizer with the shortcuts you want.  I recommend creating a folder of all the shortcuts and importing it.

### Enable Remote Assistance
Navigate to Start > Right Click Computer > Properties > Advanced System Settings > Remote > Check "Allow Remote Assistance connections to this computer".  Then check "Allow connections from computers running any version of Remote Desktop (less secure)".  

Then open Local Policy Editor by holding Win + R then typing in gpedit.msc then navigating to Computer Configuration > Administrative Templates > Network > Network Connections > Windows Firewall > Standard Profile > Edit "Windows Firewall: Allow inbound Remote Desktop exceptions" to "Allow". 

#### Configure registry to use seamlessrdp shell instead of explorer.exe:
Open regedit and navigate to HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Winlogon.  Change Shell from “explorer.exe” to “C:\Program Files\ThinLinc\WTSTools\seamlessrdpshell.exe”

#### Configure registry to allow any program to be a remote app
Open regedit and navigate to HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows NT\Terminal Services and create a new DWORD value named !fAllowUnlistedRemotePrograms.  Set its value to 1.

Hint: use Control + Alt + Delete when manually logging in to the VM from now on and use task manager to launch apps

#### Shut down the VM and create a port forwarding rule to forward 3389 (RDP port) to the VM:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Windows%20Apps%20on%20Linux%20via%20RDP/virtualbox_win7_network.png)

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Windows%20Apps%20on%20Linux%20via%20RDP/virtualbox_win7_network_port_forward.png)

## Create script to start VM then start appetizer launcher to show on client via rdesktop

Sourced from: http://tech.poweredbyorphans.net/natively-run-windows-applications-on-linux-with-seamlessrdp-and-rdesktop/

```
#!/bin/bash
ssh user@linux-host vboxheadless -s 'vm-name' & disown
sleep 7
rdesktop \
  -A 'C:\Program Files\ThinLinc\WTSTools\seamlessrdpshell.exe' \
  -s 'C:\Program Files (x86)\Appetizer\Appetizer.exe' \
  -r disk:home=$HOME \
  -r clipboard:PRIMARYCLIPBOARD \
  -u <username> \
  -p '<password>' \
  -d <domain> \
  -N \
  -P \
  -x l \
  <hostname>
  ```
