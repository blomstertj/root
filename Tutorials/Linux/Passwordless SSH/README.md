# Description
If you own a Raspberry Pi or you want to remote connect to your Linux box then you can use SSH.  SSH requires a password for the user you are logging in as.  You can disable this behavior by using SSH keys instead.  This method is arguably more secure because you need the right key to get into the box instead of a password.

# Generate a key
On your client computer generate a SSH key with:
`ssh-keygen -b 4096 -t rsa`.
Do not use a password as you'll have to use that password to "unlock" the key.

# Send key to host/server you want to control

Use `ssh-copy-id username@ip_address` replacing `username` with the correct user and `ip_address` with the correct IP.

# Disable password authentication on host/server you want to control

Edit the sshd configuration file using `sudo nano /etc/ssh/sshd_config`

Find:
```
# To disable tunneled clear text passwords, change to no here!
PasswordAuthentication yes
#PermitEmptyPasswords no
```

and change `PasswordAuthentication yes` to `PasswordAuthentication no`

# Verification
To test run ssh as you normally would and see if you get prompted for a password.
