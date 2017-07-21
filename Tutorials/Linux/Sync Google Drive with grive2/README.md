- OS: Ubuntu or Ubuntu based
- Hardware: Any
- Difficulty: Medium
- Last Tested: Ubuntu 16.04 LTS

## Description
If you have a Google Drive account, there are a few methods you can use to sync your Drive files with Linux.  My favorite method is using Grive2, a command line only tool that was forked from Grive that stopped development.  Grive2 project is located here: https://github.com/vitalif/grive2/blob/master/README.md Grive2 is pretty easy to set up and schedule.  I use a cron job to sync in the background at regular intervals.  I’m going to be following the configuration of this webpage: http://www.webupd8.org/2015/05/grive2-grive-fork-with-google-drive.html however I’m going to take another step to make it run automatically so you don’t have to manually do it.  Grive will only sync files that have changed so don’t worry about it syncing everything again.  Google Doc files are not supported, check out overGrive for that: https://www.thefanclub.co.za/overgrive 

Try to make a backup of your Google Drive files to a place that isn’t touched by Grive or any or other tools as best practice.  Remember that this is an unofficial tool for use with Google Drive.


## Adding the PPA
We’re going to need the PPA for Grive2.  Add the PPA with this terminal command:

`sudo add-apt-repository -y ppa:nilarimogard/webupd8`

Now we’re going to have to update the repositories with:

`sudo apt update`


## Installing Grive

To install grive we simply need to run:

`sudo apt install grive`


## Creating the Google Drive directory

Let’s continue using the terminal to make the directory to sync the Drive files but you can use your file manager if you want.  I just make a folder in my Home folder called Google Drive.  Let’s make sure we’re in the home directory using:

`cd`

Now let’s make the directory using (we need quotes for spaces):

`mkdir “Google Drive”`

To verify that you created the directory you can use:

`ls`

That should have an output like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/create_dir_1.png)

Now let’s go into that directory with the terminal by using:

`cd “Google Drive”`

Now your terminal line should look like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/create_dir_2.png)

## Running Grive for the First Time
Now let’s start Grive for the first time.  To do this run:

`grive -a`

You should get an output like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/grive_first_time_1.png)

Right click that link where my black box is and click Open Link.  In your web browser, it’ll bring you to your Google sign in page.  Sign in, review the permissions, and click Allow.  At the next screen right click the code (make sure to highlight it all) and click copy like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/grive_first_time_2.png)

Now go to your terminal and right click and click paste like so then press Enter like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/grive_first_time_3.png)

Then you should start seeing your files syncing like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/grive_first_time_4.png)

After it’s done syncing you can open your File Manager like Files then view the files in the Google Drive folder.  

## Scheduling Automatic Sync
You can sync grive manually from anywhere using `grive --path “/home/username/Google Drive”` so what we’re going to do is create a cron job to run this every 15 (you can change this interval to whatever you want) minutes. We are going to also make it check if Grive is already running before syncing to avoid data loss.  To accomplish this we can edit your crontab file which is an easy way to make cronjobs.  Run:

`crontab -e`

And you’ll receive this output (if never run before):

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/schedule_sync_1.png)

Select 2 because it’s the easiest.

You’ll be greeted by this block of text:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/schedule_sync_2.png)

Just use the down arrow key to go to the bottom like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/schedule_sync_3.png)

Now type in this (Don’t forget the # symbol and don’t forget to replace ‘username’ with your own username):
```
#Sync Google Drive Every 15 Minutes
*/15 * * * * pgrep grive >/dev/null || grive --path "/home/tanner/Google Drive" >/dev/null 2>&1
```
So it looks like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/schedule_sync_4.png)

So the first line is just a description of what the next line does for documentation purposes so later if you make your own cron jobs you can see what each is for.  The next line is the command to run, the first part determines when to run the following command.  `pgrep grive >/dev/null` will check if grive is already running, then `||` means OR and then `grive --path "/home/tanner/Google Drive" >/dev/null 2>&1` will run grive to sync to your folder.  Combined, this will check if grive is running and if it is, it will quit and not sync then wait until the next interval; but, if it's not running then it will start sync.  This gives us protection against very large files that are syncing or slow internet connections.

Now press `Control Key and X` then press `Y` then press `Enter` to save.  Then you’ll see this message: `“crontab: installing new crontab”` in your terminal.


## (Optional) Create an On Demand Sync Shortcut

You can create a file to sync immediately using a .desktop file.  We can create one by opening your text editor (gedit, mousepad, etc) normally.  Then we can put in (make sure to change the path to reflect your username so /home/joe/Google Drive for example) then save it as `Sync Drive Now.desktop`

Then save this to anywhere you want.  (I keep it right in my Google Drive folder).  Then right click the file in your file manager and click Properties like so:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/on_demand_sync_1.png)

Now click the Permissons tab and check `“Allow executing file as program”` and then click `Close`

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/on_demand_sync_2.png)
![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/on_demand_sync_3.png)

Now just double click on this with file and it’ll run in a terminal window then exit when done:

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Tutorials/Linux/Sync%20Google%20Drive%20with%20grive2/on_demand_sync_4.png)
