WIP

### Server OS/VM Setup
Setting up our Windows VM in VirtualBox

Get a Windows 7 ISO

#### Install VirtualBox on your host OS, in my case Arch Linux
`sudo pacman -S virtualbox  virtualbox-guest-iso`

#### Install the extension pack either from VirtualBox website or if in Arch, from the AUR

With pacaur:
`pacaur -S virtualbox-ext-oracle`

Manual way:
```sudo pacman -S git
git clone https://aur.archlinux.org/virtualbox-ext-oracle.git
cd virtualbox-ext-oracle
makepkg -si
```

#### Create Windows 7 VM and install Windows 7 (I won't detail the steps)
#### Install the applications you want to use remotely (ie Microsoft Office)
#### Install appetizer from http://appetizer.cozic.net/download
#### Install seamlessrdp shell (you need to give them email to get a download link unfortunately) from here: https://www.cendio.com/thinlinc/download/registration

Configure registry to use seamlessrdp shell instead of explorer.exe:
WIP

Hint: use Control + Alt + Delete when manually logging in to the VM from now on and use task manager to launch apps

#### Shut down the VM and create a port forwarding rule to forward 3389 (RDP port) to the VM:
WIP

#### Install zerotier on your host OS, in my case Arch Linux
If on another distribution visit their website for instructions: https://www.zerotier.com/download.shtml

With pacaur:
`pacaur -S zerotier-one`

Manual way:
```git clone https://aur.archlinux.org/zerotier-one.git
cd zerotier-one
makepkg -si
```

#### Enable the ZeroTier systemd service:.

`sudo systemctl enable zerotier-one.service && sudo systemctl start zerotier-one.service`

Create a network on ZeroTier website:
WIP

#### Allow zerotier through your firewall

`sudo ufw allow 9993/udp`

#### Allow all traffic on the new zt0 adapter

`sudo ufw allow in on zt0`

#### Join network on host machine:

`sudo zerotier-one join #######`

#### Set up ssh server, install openssh if you don't have it, on Arch it's

`sudo pacman -S openssh`

#### Create your ssh keys

`ssh-keygen -t rsa -b 4096`

### Client setup
